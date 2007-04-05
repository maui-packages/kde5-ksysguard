/*
    KSysGuard, the KDE System Guard

	Copyright (c) 1999 - 2001 Chris Schlaeger <cs@kde.org>
	Copyright (c) 2006 John Tapsell <john.tapsell@kdemail.net>

    This program is free software; you can redistribute it and/or
    modify it under the terms version 2 of of the GNU General Public
    License as published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/

#include <QTimer>

#include <QDomElement>
#include <QVBoxLayout>
#include <QList>
#include <QHBoxLayout>
#include <QResizeEvent>
#include <QSortFilterProxyModel>
#include <QHeaderView>
#include <QAction>
#include <QMenu>
#include <QTime>
#include <QSet>


#include <kapplication.h>
#include <kdebug.h>
#include <klocale.h>
#include <kmessagebox.h>
#include <kdialog.h>
#include <kicon.h>

#include <ksgrd/SensorManager.h>

#include "ProcessController.moc"
#include "ProcessController.h"
#include "ReniceDlg.h"
#include "SignalIDs.h"

#include <QCheckBox>
#include <QComboBox>
#include <QLayout>
#include <QItemDelegate>
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QProgressBar>

#include <kapplication.h>
//#define DO_MODELCHECK
#ifdef DO_MODELCHECK
#include "modeltest.h"
#endif
ProcessController::ProcessController(QWidget* parent, const QString &title, SharedSettings *workSheetSettings)
	: KSGRD::SensorDisplay(parent, title, workSheetSettings)
{
	mUi.setupUi(this);

	setPlotterWidget(this);
	setMinimumSize(sizeHint());
}
void ProcessController::resizeEvent(QResizeEvent* ev)
{
	QWidget::resizeEvent(ev);
}

void
ProcessController::sensorError(int, bool err)
{
	if (err == sensors().at(0)->isOk())
	{
		if (!err)
		{
		} else {
			kDebug() << "SensorError called with an error" << endl;
		}
		/* This happens only when the sensorOk status needs to be changed. */
		sensors().at(0)->setIsOk( !err );
	}
	setSensorOk(sensors().at(0)->isOk());
}

bool
ProcessController::restoreSettings(QDomElement& element)
{
	bool result = addSensor(element.attribute("hostName"),
				element.attribute("sensorName"),
				(element.attribute("sensorType").isEmpty() ? "table" : element.attribute("sensorType")),
				QString());
//	mUi.chkTreeView->setChecked(element.attribute("tree").toInt());
//	setTreeView(element.attribute("tree").toInt());

//	uint filter = element.attribute("filter", "0").toUInt();
//	mUi.cmbFilter->setCurrentIndex(filter);

/*	uint col = element.attribute("sortColumn", "1").toUInt(); //Default to sorting the user column
	bool inc = element.attribute("incrOrder", "0").toUInt();  //Default to descending order
	mUi.treeView->sortByColumn(mInitialSortCol, (mInitialSortInc)?Qt::AscendingOrder:Qt::DescendingOrder);
	mFilterModel.sort(col,(inc)?Qt::AscendingOrder:Qt::DescendingOrder);
	//The above sort command won't work if we have no columns (most likely).  So we save
	//the column to sort by until we have added the columns (from PS_INFO_COMMAND)
	mInitialSortCol = col;
	mInitialSortInc = inc;
	kDebug() << "Settings mInitialSortCol to " << mInitialSortCol << endl;

	bool showTotals = element.attribute("showTotals", "1").toUInt();
	mUi.chkShowTotals->setCheckState( (showTotals)?Qt::Checked:Qt::Unchecked );
*/	
	SensorDisplay::restoreSettings(element);
	return (result);
}

bool
ProcessController::saveSettings(QDomDocument& doc, QDomElement& element)
{
	element.setAttribute("hostName", sensors().at(0)->hostName());
	element.setAttribute("sensorName", sensors().at(0)->name());
	element.setAttribute("sensorType", sensors().at(0)->type());
	SensorDisplay::saveSettings(doc, element);

	return (true);
}

