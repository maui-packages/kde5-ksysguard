# 
# Do NOT Edit the Auto-generated Part!
# Generated by: spectacle version 0.27
# 

Name:       ksysguard

# >> macros
# << macros

Summary:    KDE Process Management application
Version:    5.1.0
Release:    1
Group:      System/Base
License:    GPLv2+
URL:        http://www.kde.org
Source0:    %{name}-%{version}.tar.xz
Source100:  ksysguard.yaml
Source101:  ksysguard-rpmlintrc
Requires:   kf5-filesystem
BuildRequires:  pkgconfig(Qt5Core)
BuildRequires:  pkgconfig(Qt5DBus)
BuildRequires:  pkgconfig(Qt5Xml)
BuildRequires:  pkgconfig(Qt5Network)
BuildRequires:  pkgconfig(Qt5Gui)
BuildRequires:  pkgconfig(Qt5Widgets)
BuildRequires:  pkgconfig(Qt5Concurrent)
BuildRequires:  pkgconfig(Qt5Test)
BuildRequires:  pkgconfig(Qt5Script)
BuildRequires:  pkgconfig(Qt5PrintSupport)
BuildRequires:  kf5-rpm-macros
BuildRequires:  extra-cmake-modules
BuildRequires:  qt5-tools
BuildRequires:  kcoreaddons-devel
BuildRequires:  ki18n-devel
BuildRequires:  kitemviews-devel
BuildRequires:  knewstuff-devel
BuildRequires:  kconfig-devel
BuildRequires:  kiconthemes-devel
BuildRequires:  kdelibs4support-devel
BuildRequires:  libksysguard-devel

%description
KDE Process Management application.


%package doc
Summary:    Documentation and user manuals for %{name}
Group:      Documentation
Requires:   %{name} = %{version}-%{release}

%description doc
Documentation and user manuals for %{name}


%prep
%setup -q -n %{name}-%{version}

# >> setup
# << setup

%build
# >> build pre
%kf5_make
# << build pre



# >> build post
# << build post

%install
rm -rf %{buildroot}
# >> install pre
%kf5_make_install
# << install pre

# >> install post
# << install post

%files
%defattr(-,root,root,-)
%doc COPYING COPYING.DOC README
%{_kf5_bindir}/ksysguard
%{_kf5_bindir}/ksysguardd
%{_kf5_libdir}/libkdeinit5_ksysguard.so
%{_kf5_sharedir}/ksysguard
%{_kf5_configdir}/ksysguard.knsrc
%{_kf5_sysconfdir}/ksysguarddrc
%{_kf5_iconsdir}/*
%{_kf5_applicationsdir}/ksysguard.desktop
%{_kf5_sharedir}/knotifications5/ksysguard.notifyrc
%{_kf5_sharedir}/kxmlgui5/*
# >> files
# << files

%files doc
%defattr(-,root,root,-)
%{_kf5_htmldir}/en/ksysguard
# >> files doc
# << files doc
