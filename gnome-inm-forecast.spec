# gnome-inm-forecast.spec
#
# Copyright (c) 2007 Gustavo I�iguez Goya ga@kutxa.homeunix.org
#
%define name gnome-inm-forecast
%define version 0.1.1
%define release 4
%define manifest %{_builddir}/%{name}-%{version}-%{release}.manifest

# required items
Name: %{name}
Version: %{version}
Release: %{release}
License: GPL
Group: Application/Misc

# optional items
#Vendor: Gustavo I�iguez Goya
#Distribution:
#Icon:
URL: http://kutxa.homeunix.org/trac/gnome-inm-forecast/
Packager: Gustavo I�iguez Goya ga@kutxa.homeunix.org

# source + patches
Source: %{name}-%{version}.tar.gz
#Source1:
#Patch:
#Patch1:

# RPM info
#Provides:
#Requires:
#Conflicts:
#Prereq:

#Prefix: /usr
BuildRoot: /var/tmp/%{name}-%{version}

Summary: Spanish weather forecast

%description
Spanish weather forecast applet for the gnome panel
gnome-inm-forecast.spec.  Generated from gnome-inm-forecast.spec.in by configure.

%prep
%setup -q
#%patch0 -p1

%build
%configure
make

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/usr/share/gnome-inm-forecast/pixmaps/inm/
mkdir -p $RPM_BUILD_ROOT/usr/libexec/
mkdir -p $RPM_BUILD_ROOT/usr/lib/bonobo/servers/
mkdir -p $RPM_BUILD_ROOT/usr/share/pixmaps/
install -m 644 GNOME_inm-forecast.server_rpm $RPM_BUILD_ROOT/usr/lib/bonobo/servers/GNOME_inm-forecast.server
install -m 644 gnome-inm-glade.glade $RPM_BUILD_ROOT/usr/share/gnome-inm-forecast/gnome-inm-glade.glade
install -m 644 GNOME_INM_menu.xml $RPM_BUILD_ROOT/usr/share/gnome-inm-forecast/
install -m 644 pixmaps/inm/* $RPM_BUILD_ROOT/usr/share/gnome-inm-forecast/pixmaps/inm/
install -m 644 pixmaps/espcan.jpg $RPM_BUILD_ROOT/usr/share/gnome-inm-forecast/pixmaps/
install -m 644 pixmaps/gnome-inm-forecast.png $RPM_BUILD_ROOT/usr/share/pixmaps/
install -m 655 src/gnome-inm-forecast $RPM_BUILD_ROOT/usr/libexec/
install -m 644 local_codes.txt $RPM_BUILD_ROOT/usr/share/gnome-inm-forecast/
install -m 644 stations_list_es.txt $RPM_BUILD_ROOT/usr/share/gnome-inm-forecast/
%makeinstall

# __os_install_post is implicitly expanded after the
# %install section... do it now, and then disable it,
# so all work is done before building manifest.

%{?__os_install_post}
%define __os_install_post %{nil}

# build the file list automagically into %{manifest}

cd $RPM_BUILD_ROOT
rm -f %{manifest}
find . -type d \
        | sed '1,2d;s,^\.,\%attr(-\,root\,root) \%dir ,' >> %{manifest}
find . -type f \
        | sed 's,^\.,\%attr(-\,root\,root) ,' >> %{manifest}
find . -type l \
        | sed 's,^\.,\%attr(-\,root\,root) ,' >> %{manifest}

#%pre
#%post
#%preun
#%postun

%clean
rm -f %{manifest}
rm -rf $RPM_BUILD_ROOT

%files -f %{manifest}
%defattr(-,root,root)
%doc README AUTHORS COPYING INSTALL
#%docdir
#%config

%changelog
