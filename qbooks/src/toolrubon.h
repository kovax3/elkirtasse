#ifndef TOOLRUBON_H
#define TOOLRUBON_H
#include <QTabBar>
#include <QWidget>
#include <QToolBar>
#include <QTabWidget>
#include <QToolButton>
class tab : public QTabBar
{
    Q_OBJECT
public:

protected:

    void mouseDoubleClickEvent( QMouseEvent *  )
    {
        emit doubleClick(true);
        update();
    }
signals:

    void doubleClick(bool );


public slots:

private:
    bool m_checked;

};
class toolrubon : public QToolBar
{
    Q_OBJECT
public:
    explicit toolrubon(QWidget *parent = 0);
   void setRubonStyle();
    QToolBar *toolFile;
    QToolBar *toolEdit;
    QToolBar *tooTools;
    QToolBar *toolView;
    QToolBar *toolFind;
    QToolBar *toolHelp;
signals:
    
public slots:
    void setToolIconSize(int s,bool asTxt);
    void setStyleWhite();
private:
 QTabWidget *TabWidgetTool;
QToolButton *btnAddtab;

int m_toolHeight;
int m_tabHeight;
private slots:
    void  collapsTab(bool cheked);
    void tabWidget_currentChanged(int );
};

#endif // TOOLRUBON_H
