#ifndef CLASSEPUB_H
#define CLASSEPUB_H
#include <QObject>
#include <QTreeWidget>
#include <QDomDocument>
#include <QTextDocument>
class classepub
{
public:
    classepub();
int curentPage;
int pageCount;
QString infoBookTitle;
QString infoBookAutor;
QString infoBookBetaka;
public slots:

    bool ebubUnzip(QString fileName);
void chargeTreeIndex(QTreeWidget *view);
QString setPage(int page);
void setCurentPage(QString page);
private:

QStringList m_listId;
QStringList m_listEpub;
QStringList m_listContent;
QString m_tocPath;
private slots:

inline int findStringInQuotes (const QString& tag, int offset, QString& value, bool firstquote, bool decodeentities);
void getChild(QDomNode node,QTreeWidgetItem *item);
void ebubOpenContainer(QString fileName);

void ebubOpenContent(QString fileName,bool write);

QString ebubSetPage(QString fileName);
void epubOpenToc(QString fileName);
void epubGetChild(QDomNode item,int lvl);
void epubCreatIndex();
};

#endif // CLASSEPUB_H
