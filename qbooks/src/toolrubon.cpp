#include "toolrubon.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QStyle>
toolrubon::toolrubon(QWidget *parent) :
    QToolBar(parent)
{
    this->setObjectName("maintoolBar");
    this->setWindowTitle(trUtf8("ازرار قياسية"));

    this->setMovable(false);
    toolFile=new QToolBar;
    toolEdit=new QToolBar;
    tooTools=new QToolBar;
   toolView=new QToolBar;
    toolFind=new QToolBar;
    toolHelp=new QToolBar;
}
void  toolrubon::setRubonStyle()
{
    TabWidgetTool=new QTabWidget;
      TabWidgetTool->setFocusPolicy(Qt::ClickFocus);

//toolEdit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        //  connect(TabWidgetTool->tab., SIGNAL(), this, SLOT(collapsTab(bool)));
    QWidget *widgetFile=new  QWidget;
    QWidget *widgetEdit=new  QWidget;
    QWidget *widgetNavig=new  QWidget;
  QWidget *widgetView=new  QWidget;
    QWidget *widgetFind=new  QWidget;
    QWidget *widgetHelp=new  QWidget;

    QHBoxLayout *layoutFile=new QHBoxLayout(widgetFile);
    QHBoxLayout *layoutEdit=new QHBoxLayout(widgetEdit);
    QHBoxLayout *layoutNavig=new QHBoxLayout(widgetNavig);
  QHBoxLayout *layoutView=new QHBoxLayout(widgetView);
    QHBoxLayout *layoutFind=new QHBoxLayout(widgetFind);
    QHBoxLayout *layoutHelp=new QHBoxLayout(widgetHelp);

    layoutFile->setMargin(0);
    layoutEdit->setMargin(0);
    layoutNavig->setMargin(0);
   layoutView->setMargin(0);
    layoutFind->setMargin(0);
    layoutHelp->setMargin(0);

    TabWidgetTool->addTab(widgetFile,trUtf8("&ملف"));
    TabWidgetTool->addTab(widgetEdit,trUtf8("&تحرير"));
    TabWidgetTool->addTab(widgetFind,trUtf8("بحث&"));
    TabWidgetTool->addTab(widgetNavig,trUtf8("ادوات"));
       TabWidgetTool->addTab(widgetView,trUtf8("&عرض"));
    TabWidgetTool->addTab(widgetHelp,trUtf8("التع&ليمات"));

//    TabWidgetTool->addTab(trUtf8("&ملف"));
//    TabWidgetTool->addTab(trUtf8("&تحرير"));
//    TabWidgetTool->addTab(trUtf8("بحث&"));
//    TabWidgetTool->addTab(trUtf8("ادوات"));
//       TabWidgetTool->addTab(trUtf8("&عرض"));
//    TabWidgetTool->addTab(trUtf8("التع&ليمات"));

    layoutFile->addWidget(toolFile);
    layoutEdit->addWidget(toolEdit);
    layoutNavig->addWidget(tooTools);
  layoutView->addWidget(toolView);
    layoutFind->addWidget(toolFind);
    layoutHelp->addWidget(toolHelp);

    this->addWidget(TabWidgetTool);

    btnAddtab=new QToolButton(this);
    btnAddtab->setArrowType(Qt::UpArrow);
    btnAddtab->setStyleSheet(" QToolButton  {  border: 0px solid #8f8f91;}"
                             " QToolButton:hover  {  border: 1px solid #8f8f91; border-radius: 3px;}");
    btnAddtab->setCheckable(true);
    btnAddtab->setToolTip(trUtf8("غلق"));
  TabWidgetTool->setCornerWidget(btnAddtab,Qt::TopLeftCorner);
    connect(btnAddtab, SIGNAL(toggled(bool)), this, SLOT(collapsTab(bool)));
    connect(TabWidgetTool, SIGNAL(currentChanged(int)), this, SLOT(tabWidget_currentChanged(int)));
 setStyleWhite();

}

void  toolrubon::collapsTab(bool cheked)
{
    //int h=TabWidgetTool->height();
    //int ht=m_toolHeight;
    if(cheked){
        btnAddtab->setArrowType(Qt::DownArrow);
        TabWidgetTool->setMaximumHeight(m_tabHeight-4);
       TabWidgetTool->setMinimumHeight(m_tabHeight-4);
    }else{
        btnAddtab->setArrowType(Qt::UpArrow);
        TabWidgetTool->setMinimumHeight(m_tabHeight+m_toolHeight);
        TabWidgetTool->setMaximumHeight(m_tabHeight+m_toolHeight);
    }
    btnAddtab->setChecked(cheked);
}

void toolrubon::tabWidget_currentChanged(int )
{
   collapsTab(false);
}

void toolrubon::setToolIconSize(int s,bool asTxt)
{

  int sizeF=  this->fontInfo().pixelSize();
    toolFile->setIconSize(QSize(s,s));
    toolEdit->setIconSize(QSize(s,s));
    tooTools->setIconSize(QSize(s,s));
   toolView->setIconSize(QSize(s,s));
    toolFind->setIconSize(QSize(s,s));
    toolHelp->setIconSize(QSize(s,s));
    this->setIconSize(QSize(s,s));

    if(asTxt==true){
 toolFile->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
 toolEdit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
 tooTools->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

 toolFind->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  toolView->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
  toolHelp->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
   this->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    m_toolHeight=s+24+sizeF;
}else{
        toolFile->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolEdit->setToolButtonStyle(Qt::ToolButtonIconOnly);
        tooTools->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolFind->setToolButtonStyle(Qt::ToolButtonIconOnly);
         toolView->setToolButtonStyle(Qt::ToolButtonIconOnly);
         toolHelp->setToolButtonStyle(Qt::ToolButtonIconOnly);
              this->setToolButtonStyle(Qt::ToolButtonIconOnly);
           m_toolHeight=s+12;
    }
    m_tabHeight=sizeF*2;
 qDebug()<<"m_toolHeight : "<<m_toolHeight;
 qDebug()<<"m_tabHeight : "<<m_tabHeight;
 qDebug()<<"sizeF : "<<sizeF;
}

void toolrubon::setStyleWhite()
{
    int mred= this->palette().color(QPalette::Highlight).red();
    int mgreen= this->palette().color(QPalette::Highlight).green();
    int mblue= this->palette().color(QPalette::Highlight).blue();
    QString mystyle=QString(
                             "QDockWidget::title {"
                         "background-color: rgba(%1, %2, %3, 50);"
                       "}"
                      "QTabWidget::pane { /* The tab widget frame */"
                            "background-color: qlineargradient(spread:pad, x1:0.994318, y1:0.471, x2:1, y2:1, stop:0 rgba(%1, %2, %3, 50), stop:1 rgba(%1, %2, %3, 100));"
                             "margin-bottom: -2px;"
                            "border-top: 0px solid #C2C7CB;}"
                            "QDockWidget::QTabWidget::tab-bar {"
                            "left: 5px; /* move to the right by 5px */}"

                            "QTabBar::tab:left {"
                            "background-color: rgba(255, 255, 255, 0);"
                            "spacing: 5px;"
                            "min-width: 2ex;"
                            "padding: 5px;}"

                            "QTabBar::tab:top {"
                            "background-color: rgba(255, 255, 255, 0);"
                            "spacing: 8px;"
                            "min-width: 2ex;"
                            "padding: 5px;}"


                          " QTabBar::tab:top:hover {"
                            "border: 1px solid #C4C4C3;"
                            "border-color: #9B9B9B;"
                            "border-bottom-color: #C2C7CB; /* same as the pane color */"
                            "border-top-left-radius: 4px;"
                            "border-top-right-radius: 4px;"
                            "background-color: qlineargradient(spread:pad, x1:0.994318, y1:1.0, x2:1, y2:0, stop:0 rgba(255, 255, 255, 80), stop:1 rgba(%1, %2, %3, 160));"
                            "}"

                " QTabBar::tab:left:hover {"
                  "border: 1px solid #C4C4C3;"
                  "border-color: #9B9B9B;"
                    "border-top-right-radius: 4px;"
                  "border-bottom-right-radius: 4px;"
                  "background-color: qlineargradient(spread:pad, x1:0.1, y1:0.0113636, x2:1, y2:0, stop:0 rgba(255, 255, 255, 80), stop:1 rgba(%1, %2, %3, 160));"
                  "}"

                            "QTabBar::tab:left:selected {"
                            "border: 1px solid #C4C4C3;"
                            "border-color: #9B9B9B;"

                            "background-color: qlineargradient(spread:pad, x1:0.61, y1:0.0113636, x2:1, y2:0, stop:0 rgba(%1, %2, %3, 50), stop:1 rgba(255, 255, 255, 150));"
                            "border-top-right-radius: 4px;"
                            "border-bottom-right-radius: 4px;"
                            "border-right-color:rgba(%1, %2, %3, 80); /* same as pane color */ }"

                            "QTabBar::tab:top:selected {"
                            "border: 1px solid #C4C4C3;"
                            "border-color: rgba(%1, %2, %3, 100);"
                            "margin-bottom: -2px;"
                            "background-color: qlineargradient(spread:pad, x1:0.994318, y1:0.471, x2:1, y2:0, stop:0 rgba(%1, %2, %3, 50), stop:1 rgba(255, 255, 255, 150));"
                             "border-top-left-radius: 4px;"
                            "border-top-right-radius: 4px;"
                            "border-bottom-color:rgba(%1, %2, %3, 80); /* same as pane color */ }"



                            "QToolBar {"

                            "background-color: rgba(255, 255, 255, 0);"
                            "spacing: 3px;"
                            "border-width: 0px;}"


                            ).arg(QString::number(mred)).arg(QString::number(mgreen)).arg(QString::number(mblue)) ;

    this->setStyleSheet(mystyle);

}
