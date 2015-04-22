#ifndef DIALOGIMPORTDVD_H
#define DIALOGIMPORTDVD_H

#include <QDialog>
#include <QTreeWidgetItem>
#include <QAbstractButton>
#include <QProcess>

namespace Ui {
    class DialogImportDvd;
}

class DialogImportDvd : public QDialog
{
    Q_OBJECT

public:
    explicit DialogImportDvd(QWidget *parent = 0);
    ~DialogImportDvd();
    void setBooksPath(QString path);
<<<<<<< HEAD
    void setAppPath(QString path);
=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
    QString getBooksPath();


private slots:
    void on_buttonBox_accepted();

    void on_toolButton_clicked();
<<<<<<< HEAD
    void on_toolButtonBooksPath_clicked();
=======
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
void treeChargeGroupe( );
void on_treeWidget_itemChanged(QTreeWidgetItem *item, int );
bool unzipFile(QString fileGz,QString file);
void readstdout();
void readsteror();
void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::DialogImportDvd *ui;
  QString  m_booksPath;
  QString m_groupPath;
<<<<<<< HEAD
  QProcess *process;
  QString m_pathApp;
=======
      QProcess *process;
>>>>>>> 782789df57a2a7d2f3b28c5cde42eee89c50d76e
};

#endif // DIALOGIMPORTDVD_H
