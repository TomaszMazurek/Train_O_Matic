#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QString>
#include <QtSql>
#include <QMessageBox>
#include <QChar>

struct Connection
{
    QString trainNum;
    QString destination;
    QString origin;
    QChar platform;
    QString track;
    QString arrival;
    QString departure;

};

class DbManager
{
public:
    DbManager();
    ~DbManager();
    QList<Connection> getCurrentConnections();

private:
    QSqlDatabase db;
    QMessageBox mBox;
    QDir databasePath;
};

#endif // DBMANAGER_H
