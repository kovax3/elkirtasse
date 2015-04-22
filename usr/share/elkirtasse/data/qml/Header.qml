/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 1.0

Image {
    id: header

 property int count: webBrowser.countpage
    property bool urlChanged: false
 property int htmp: 0
 // property int count: 1000
    source: "pics/titlebar-bg.png"; fillMode: Image.TileHorizontally

    x: webView.contentX < 0 ? -webView.contentX : webView.contentX > webView.contentWidth-webView.width
       ? -webView.contentX+webView.contentWidth-webView.width : 0
    y: {
        if (webView.progress < 1.0)
            return 0;
        else {
            webView.contentY < 0 ? -webView.contentY : webView.contentY > height ? -height : -webView.contentY
        }
    }
    Column {
        id: column1
        width: parent.width



        Item {
            width: parent.width; height: 32

            Button {
                id: lastButton
              //  action: webView.back;
                image: "pics/last.png"
                anchors { left: parent.left; bottom: parent.bottom }
                onClicked: {

                        htmp=count
                    webView.url="../HTML/P"+htmp+".html"
                     webBrowser.focus = true
                }
            }
            Button {
                id: nextButton
              //  action: webView.back;
                image: "pics/next.png"
                anchors { left: lastButton.right; bottom: parent.bottom }
                onClicked: {
                       htmp=webView.title
                    htmp++
                    if(htmp>=count)
                        htmp=count
                    webView.url="../HTML/P"+htmp+".html"
                     webBrowser.focus = true
                }
            }
            Button {
                id: homeButton
                anchors.left: nextButton.right
               // action: webView.forward;
                image: "pics/home.png"
                onClicked: {
                    htmp=0
                    webView.url="../index.html"
                    webBrowser.focus = true
                }
            }

            Button {

                id: prevButton
                anchors.left: homeButton.right
               // action: webView.forward;
                image: "pics/prev.png"
                onClicked: {
                     htmp=webView.title
                       htmp--
                    if(htmp<=1)
                        htmp=1
                    webView.url="../HTML/P"+htmp+".html"
                  //  webBrowser.urlString ="../book/HTML/P"+htmp
                    webBrowser.focus = true
                }
            }
            Button {
                id:firstButton
                anchors.left: prevButton.right
               // action: webView.forward;
                image: "pics/first.png"
                onClicked: {


                        htmp=1
                    webView.url="../HTML/P"+htmp+".html"
                  //  webBrowser.urlString ="../book/HTML/P"+htmp
                    webBrowser.focus = true
                }
            }
/*
            UrlInput {
                id: urlInput
                x: 86
                y: 0
                anchors.rightMargin: -6
                anchors.leftMargin: 6
                anchors { left: firstButton.right; right: reloadButton.left }
                image: "pics/display.png"
                onUrlEntered: {
                    webBrowser.urlString = url
                    webBrowser.focus = true
                    header.urlChanged = false

                }
                onUrlChanged: header.urlChanged = true
            }


   

                Text {
                    id:title
                    x: 66
                    y: 12
                    anchors.rightMargin: -13
                    anchors.leftMargin: 13
                    anchors { left: firstButton.right; right: gonextButton.left }

                    anchors.centerIn: parent
                    text: webView.title;  font.pixelSize: 14; font.bold: true
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    color: "white"; styleColor: "black"; style: Text.Sunken
                }
*/




            Button {
                id:gonextButton
               // anchors.left: title.right
                 anchors.right: gobackButton.left
                action: webView.forward;
                image: "pics/go-previous-view.png"

            }

            Button {
                id:gobackButton
                // anchors.left: gonextButton.right
               anchors.right: parent.right
                action: webView.back;
                image: "pics/go-next-view.png"

            }
        }
    }
}
