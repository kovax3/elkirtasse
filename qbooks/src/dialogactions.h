#ifndef DIALOGACTIONS_H
#define DIALOGACTIONS_H

#include <QDialog>
#include <QTreeWidgetItem>
namespace Ui {
    class DialogActions;
}

class DialogActions : public QDialog
{
    Q_OBJECT

public:
    explicit DialogActions(QWidget *parent = 0);
    ~DialogActions();
QList<QVariant >listActToAdd;
private:
    Ui::DialogActions *ui;




public slots:

     void setListActions(   QList<QAction *>*listActions,QList<QVariant >listToAdd);
private slots:

    void on_toolButtonAdd_clicked();
    void on_toolButtonRemove_clicked();
    void on_buttonBox_accepted();
    void on_treeWidgetDest_itemSelectionChanged();
    void on_treeWidgetOrig_itemSelectionChanged();
    void on_toolButtonUp_clicked();
    void on_toolButtonDown_clicked();
};

#endif // DIALOGACTIONS_H
