#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QString>
#include <QtSql>
#include <QMessageBox>
#include <QChar>
#include "ticket.h"
#include <QSqlDatabase>


struct Connection
{
    QString trainNum;
    QString destination;
    QString origin;
    QChar platform;
    QString track;
    QString arrival;
    QString departure;
    QString cost;
};


class DbManager
{
public:
    DbManager();
    ~DbManager();
    QList<Connection> getCurrentConnections();
    void saveTicket(TicketType* ticket);

private:
    QSqlDatabase db;
    QMessageBox mBox;
    QDir databasePath;
};

#endif // DBMANAGER_H
