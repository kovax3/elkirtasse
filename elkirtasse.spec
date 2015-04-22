# norootforbuild

%if 0%{?suse_version}
     %define qmake /usr/bin/qmake
BuildRequires:	libqt4-devel >= 4.6
BuildRequires: update-desktop-files
BuildRequires: pkg-config
Requires: libqt4-x11 >= 4.6.2
%endif

%if 0%{?fedora_version} || 0%{?rhel_version} || 0%{?centos_version}
   %define qmake /usr/bin/qmake-qt4
BuildRequires:	qt-devel
<<<<<<< HEAD
BuildRequires:  libqt4-devel >= 4.6
=======
BuildRequires:  qt4-devel
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e

%endif

%if 0%{?mandriva_version}  || 0%{?mdkversion}
    %define qmake /usr/lib/qt4/bin/qmake
BuildRequires:	libqt4-devel >= 4.6

%endif

Name:		elkirtasse
<<<<<<< HEAD
Version:	3.6.6
Release:	1
=======
Version:	3.6
Release:	76.1
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e

License:	GPL3
Group:		libriry/office
Summary:	Elkirtasse librery for system x11
<<<<<<< HEAD
URL:		http://elkirtasse.sourceforge.net
=======
URL:		http://www.elkirtasse.co.cc
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e

Source0:        %{name}-%{version}.tar.gz

BuildRoot:      %{_tmppath}/%{name}-%{version}-build

 
BuildRequires: 	gcc-c++




%description
  Library elkietasse free program is open source foe all operating systems running Linux or Windows or Mac lets you view and edit books and you can add news books 
         http://sites.google.com/site/kirtase.
<<<<<<< HEAD
,http://elkirtasse.sourceforge.net,
=======
,http://www.elkirtasse.co.cc,http://www.elkirtasse.22web.net,
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e

%prep
%setup -q -n %{name}-%{version}

%build
%{qmake}
<<<<<<< HEAD
make
=======

make

>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
%install
# Create desktop file
%__cat > %{name}.desktop << EOF
[Desktop Entry]
Name=elkirtasse
Name[ar]= 
Comment[ar]=    
Type=Application
Exec=elkirtasse
Icon=elkirtasse
Categories=Office;
EOF
# End of desktop file
# binary
<<<<<<< HEAD
#%{makeinstall} INSTALL_ROOT=$RPM_BUILD_ROOT
install -D -m 644 -T usr/share/applications/%{name}.desktop $RPM_BUILD_ROOT%{_datadir}/applications/%{name}.desktop
%if 0%{?suse_version}

%suse_update_desktop_file -c %{name} "elkirtasse" "elkirtasse app" %{name} "%{name}.png" Office Dictionary


	  mkdir -p $RPM_BUILD_ROOT%{_bindir}
	  mkdir -p $RPM_BUILD_ROOT%_libdir/%{name}/plugins
	  mkdir -p $RPM_BUILD_ROOT%{_datadir}/elkirtasse
	  mkdir -p $RPM_BUILD_ROOT%{_datadir}/icons
	  mkdir -p $RPM_BUILD_ROOT%_libdir/%{name}/plugins/
	  
	  cp -R usr/share/elkirtasse/data $RPM_BUILD_ROOT%{_datadir}/elkirtasse
	  cp -R usr/share/elkirtasse/translat $RPM_BUILD_ROOT%{_datadir}/elkirtasse
	  cp -R usr/share/icons $RPM_BUILD_ROOT%{_datadir}
	  cp -R usr/bin/%{name} $RPM_BUILD_ROOT%{_bindir}
      
	  cp -f usr/share/elkirtasse/plugins/libkirtassecdrom.so $RPM_BUILD_ROOT%_libdir/%{name}/plugins/libkirtassecdrom.so
	  cp -f usr/share/elkirtasse/plugins/libkirtassenet.so $RPM_BUILD_ROOT%_libdir/%{name}/plugins/libkirtassenet.so
	  cp -f usr/share/elkirtasse/plugins/libkirtasserowat.so $RPM_BUILD_ROOT%_libdir/%{name}/plugins/libkirtasserowat.so
	
%else
	  mkdir -p $RPM_BUILD_ROOT%{_bindir}
	  mkdir -p $RPM_BUILD_ROOT%{_datadir}/%{name}/plugins
	  mkdir -p $RPM_BUILD_ROOT%{_datadir}/elkirtasse
	  mkdir -p $RPM_BUILD_ROOT%{_datadir}/icons
 

        
	cp -R usr/share/elkirtasse/data $RPM_BUILD_ROOT%{_datadir}/elkirtasse
	cp -R usr/share/elkirtasse/translat $RPM_BUILD_ROOT%{_datadir}/elkirtasse
=======
#%{makeinstall} INSTALL_ROOT=%{buildroot}
install -D -m 644 -T %{name}.desktop $RPM_BUILD_ROOT%{_datadir}/applications/%{name}.desktop
%if 0%{?suse_version}
%suse_update_desktop_file -c %{name} "elkirtasse" "elkirtasse app" %{name} "%{name}.png" Office Dictionary


    mkdir -p $RPM_BUILD_ROOT%{_bindir}
    mkdir -p $RPM_BUILD_ROOT%_libdir/%{name}/plugins
    mkdir -p $RPM_BUILD_ROOT%{_datadir}/elkirtasse
    mkdir -p $RPM_BUILD_ROOT%{_datadir}/icons
 

	
        %__install -d -m 755 $RPM_BUILD_ROOT%{_datadir}/%{name}
	%__install -m 755 elkirtasse $RPM_BUILD_ROOT%{_datadir}/%{name}/elkirtasse
        
        cp -R data $RPM_BUILD_ROOT%{_datadir}/elkirtasse/
	
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
	cp -R usr/share/icons $RPM_BUILD_ROOT%{_datadir}
	cp -R usr/bin/%{name} $RPM_BUILD_ROOT%{_bindir}
        
        
<<<<<<< HEAD
	cp -f usr/share/elkirtasse/plugins/libkirtassecdrom.so $RPM_BUILD_ROOT%{_datadir}/%{name}/plugins/libkirtassecdrom.so
	cp -f usr/share/elkirtasse/plugins/libkirtassenet.so $RPM_BUILD_ROOT%{_datadir}/%{name}/plugins/libkirtassenet.so
	cp -f usr/share/elkirtasse/plugins/libkirtasserowat.so $RPM_BUILD_ROOT%{_datadir}/%{name}/plugins/libkirtasserowat.so
%endif

=======
	cp -f plugins/libkirtassecdrom.so $RPM_BUILD_ROOT%_libdir/%{name}/plugins/libkirtassecdrom.so
	cp -f plugins/libkirtassenet.so $RPM_BUILD_ROOT%_libdir/%{name}/plugins/libkirtassenet.so
	cp -f plugins/libkirtasserowat.so $RPM_BUILD_ROOT%_libdir/%{name}/plugins/libkirtasserowat.so
       
 %endif
     


        
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
%clean
%{__rm} -rf %{buildroot}


%files
%defattr(-,root,root,-)
<<<<<<< HEAD


=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
%{_bindir}
%{_bindir}/%{name}
%{_datadir}
%{_datadir}/applications
%{_datadir}/applications/%{name}.desktop
%{_datadir}/%{name}
%{_datadir}/%{name}/data
%{_datadir}/%{name}/data/ajzaa.xml
<<<<<<< HEAD
%{_datadir}/%{name}/data/bookslist.xml
%{_datadir}/%{name}/data/curan.xml
%{_datadir}/%{name}/data/font
%{_datadir}/%{name}/data/font/SimplifiedNaskh.ttf
=======
%{_datadir}/%{name}/data/curan.xml
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
%{_datadir}/%{name}/data/group.xml
%{_datadir}/%{name}/data/help.html
%{_datadir}/%{name}/data/images
%{_datadir}/%{name}/data/images/arabesque
%{_datadir}/%{name}/data/images/arabesque/bot.png
%{_datadir}/%{name}/data/images/arabesque/bot_left.png
%{_datadir}/%{name}/data/images/arabesque/bot_right.png
%{_datadir}/%{name}/data/images/arabesque/left.png
%{_datadir}/%{name}/data/images/arabesque/preview.png
%{_datadir}/%{name}/data/images/arabesque/right.png
%{_datadir}/%{name}/data/images/arabesque/top.png
%{_datadir}/%{name}/data/images/arabesque/top_left.png
%{_datadir}/%{name}/data/images/arabesque/top_right.png
%{_datadir}/%{name}/data/images/default
%{_datadir}/%{name}/data/images/default/bot.png
%{_datadir}/%{name}/data/images/default/bot_left.png
%{_datadir}/%{name}/data/images/default/bot_right.png
%{_datadir}/%{name}/data/images/default/left.png
%{_datadir}/%{name}/data/images/default/preview.png
%{_datadir}/%{name}/data/images/default/right.png
%{_datadir}/%{name}/data/images/default/top.png
%{_datadir}/%{name}/data/images/default/top_left.png
%{_datadir}/%{name}/data/images/default/top_right.png
%{_datadir}/%{name}/data/images/mashaf
%{_datadir}/%{name}/data/images/mashaf/bot.png
%{_datadir}/%{name}/data/images/mashaf/bot_left.png
%{_datadir}/%{name}/data/images/mashaf/bot_right.png
%{_datadir}/%{name}/data/images/mashaf/left.png
%{_datadir}/%{name}/data/images/mashaf/preview.png
%{_datadir}/%{name}/data/images/mashaf/right.png
%{_datadir}/%{name}/data/images/mashaf/top.png
%{_datadir}/%{name}/data/images/mashaf/top_left.png
%{_datadir}/%{name}/data/images/mashaf/top_right.png
%{_datadir}/%{name}/data/images/mashaf2
%{_datadir}/%{name}/data/images/mashaf2/bot.png
%{_datadir}/%{name}/data/images/mashaf2/bot_left.png
%{_datadir}/%{name}/data/images/mashaf2/bot_right.png
%{_datadir}/%{name}/data/images/mashaf2/left.png
%{_datadir}/%{name}/data/images/mashaf2/preview.png
%{_datadir}/%{name}/data/images/mashaf2/right.png
%{_datadir}/%{name}/data/images/mashaf2/top.png
%{_datadir}/%{name}/data/images/mashaf2/top_left.png
%{_datadir}/%{name}/data/images/mashaf2/top_right.png
%{_datadir}/%{name}/data/images/zakhrafa
<<<<<<< HEAD
%{_datadir}/%{name}/data/images/zakhrafa/bot.png
%{_datadir}/%{name}/data/images/zakhrafa/bot_left.png
%{_datadir}/%{name}/data/images/zakhrafa/bot_right.png
%{_datadir}/%{name}/data/images/zakhrafa/left.png
%{_datadir}/%{name}/data/images/zakhrafa/preview.png
%{_datadir}/%{name}/data/images/zakhrafa/right.png
%{_datadir}/%{name}/data/images/zakhrafa/top.png
%{_datadir}/%{name}/data/images/zakhrafa/top_left.png
%{_datadir}/%{name}/data/images/zakhrafa/top_right.png
=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
%{_datadir}/%{name}/data/images/zakhrafa2
%{_datadir}/%{name}/data/images/zakhrafa2/bot.png
%{_datadir}/%{name}/data/images/zakhrafa2/bot_left.png
%{_datadir}/%{name}/data/images/zakhrafa2/bot_right.png
%{_datadir}/%{name}/data/images/zakhrafa2/left.png
%{_datadir}/%{name}/data/images/zakhrafa2/preview.png
%{_datadir}/%{name}/data/images/zakhrafa2/right.png
%{_datadir}/%{name}/data/images/zakhrafa2/top.png
%{_datadir}/%{name}/data/images/zakhrafa2/top_left.png
%{_datadir}/%{name}/data/images/zakhrafa2/top_right.png
<<<<<<< HEAD
%{_datadir}/%{name}/data/qml
%{_datadir}/%{name}/data/qml/Button.qml
%{_datadir}/%{name}/data/qml/FlickableWebView.qml
%{_datadir}/%{name}/data/qml/Header.qml
%{_datadir}/%{name}/data/qml/ScrollBar.qml
%{_datadir}/%{name}/data/qml/pics
%{_datadir}/%{name}/data/qml/pics/titlebar-bg.png
%{_datadir}/%{name}/data/rowaInfo.xml
=======
%{_datadir}/%{name}/data/images/zakhrafa/bot.png
%{_datadir}/%{name}/data/images/zakhrafa/bot_left.png
%{_datadir}/%{name}/data/images/zakhrafa/bot_right.png
%{_datadir}/%{name}/data/images/zakhrafa/left.png
%{_datadir}/%{name}/data/images/zakhrafa/preview.png
%{_datadir}/%{name}/data/images/zakhrafa/right.png
%{_datadir}/%{name}/data/images/zakhrafa/top.png
%{_datadir}/%{name}/data/images/zakhrafa/top_left.png
%{_datadir}/%{name}/data/images/zakhrafa/top_right.png
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e

%if 0%{?suse_version}
%_libdir 
%_libdir/%{name}
%_libdir/%{name}/plugins
%_libdir/%{name}/plugins/libkirtassecdrom.so
%_libdir/%{name}/plugins/libkirtassenet.so
%_libdir/%{name}/plugins/libkirtasserowat.so
<<<<<<< HEAD
%else
%{_datadir}/%{name}/plugins
%{_datadir}/%{name}/plugins/libkirtassecdrom.so
%{_datadir}/%{name}/plugins/libkirtassenet.so
%{_datadir}/%{name}/plugins/libkirtasserowat.so
%endif
%{_datadir}/%{name}/translat
%{_datadir}/%{name}/translat/kirtasse_en.qm
%{_datadir}/%{name}/translat/kirtasse_en.ts
%{_datadir}/%{name}/translat/kirtasse_fr.qm
%{_datadir}/%{name}/translat/kirtasse_fr.ts
%{_datadir}/%{name}/translat/kirtasse_pk.qm
%{_datadir}/%{name}/translat/kirtasse_pk.ts
%{_datadir}/icons
%{_datadir}/icons/hicolor
%{_datadir}/icons/hicolor/22x22
%{_datadir}/icons/hicolor/22x22/apps
%{_datadir}/icons/hicolor/22x22/apps/%{name}.png
%{_datadir}/icons/hicolor/32x32
%{_datadir}/icons/hicolor/32x32/apps
%{_datadir}/icons/hicolor/32x32/apps/%{name}.png
%{_datadir}/icons/hicolor/48x48
%{_datadir}/icons/hicolor/48x48/apps
%{_datadir}/icons/hicolor/48x48/apps/%{name}.png
%{_datadir}/icons/hicolor/64x64
%{_datadir}/icons/hicolor/64x64/apps
%{_datadir}/icons/hicolor/64x64/apps/%{name}.png
%{_datadir}/icons/hicolor/96x96
%{_datadir}/icons/hicolor/96x96/apps
%{_datadir}/icons/hicolor/96x96/apps/%{name}.png
%{_datadir}/icons/hicolor/scalable
%{_datadir}/icons/hicolor/scalable/apps
%{_datadir}/icons/hicolor/scalable/apps/%{name}.svg
=======
%endif

%{_datadir}/icons
%{_datadir}/icons/hicolor
%{_datadir}/icons/hicolor/48x48
%{_datadir}/icons/hicolor/48x48/apps
%{_datadir}/icons/hicolor/48x48/apps/%{name}.png
%{_datadir}/icons/hicolor/scalable
%{_datadir}/icons/hicolor/scalable/apps
%{_datadir}/icons/hicolor/scalable/apps/%{name}.png
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
