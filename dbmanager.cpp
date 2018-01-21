#include "dbmanager.h"
#include "dashboard.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QFileInfo>

DbManager::DbManager()
{
   const QString path = ("E:/polsl/PO/projekt/Train_O_Matic/polaczenie.db");

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);


   if(!db.open())
   {
        qDebug() << "Nie można połączyć z bazą danych";
    }

   else
       {
           qDebug() << "Database: connection ok";
       }

}

DbManager::~DbManager()
{
    if (db.isOpen())
    {
    db.close();
    }
}

QList<Connection> DbManager::getCurrentConnections()
{
    QList<Connection> connections;
    Connection connection;
    int trainId, destId, originId, platformId, trackId, arrivalId, departureId,costId;

    QSqlQuery query("SELECT * FROM Connections");

    trainId = query.record().indexOf("TrainNum");
    destId = query.record().indexOf("Destination");
    originId = query.record().indexOf("Origin");
    platformId = query.record().indexOf("Platform");
    trackId = query.record().indexOf("Track");
    arrivalId = query.record().indexOf("Arrival");
    departureId = query.record().indexOf("Departure");
    costId = query.record().indexOf("Cost");
    while(query.next()){

     connection.trainNum = query.value(trainId).toString();
     connection.destination = query.value(destId).toString();
     connection.origin = query.value(originId).toString();
     connection.platform = query.value(platformId).toChar();
     connection.track = query.value(trackId).toString();
     connection.arrival = query.value(arrivalId).toString();
     connection.departure = query.value(departureId).toString();
     connection.cost=query.value(costId).toString();
     connections.append(connection);
    }

    return connections;
}
void DbManager::saveTicket(TicketType* ticket)
{


    QSqlQuery queryAdd;

    QString name=QString::number(ticket->ticketNum);
    QString date=QTime::currentTime().toString("hh:mm:ss")+" "+QDate::currentDate().toString("dd-MM-yy");
    queryAdd.prepare("INSERT INTO sales (trainNum,destination,"
                     "origin,platform,track,arrival,departure,"
                     "ticketType,classType,seatType,ticketNum,salesDate) "
                  "VALUES ('"+ticket->trainNum+"','"+ticket->destination+"',"
                  "'"+ticket->origin+"','"+ticket->platform+"','"
                  ""+ticket->track+"','"+ticket->arrival+"','"+ticket->departure+"'"
                 ",'"+ticket->ticketType+"','"+ticket->classType+"',"
                  "'"+ticket->seatType+"','"+name+"','"+date+"')");

    if(queryAdd.exec())
    {
        qDebug()<<"Zapisano bilet";


    }
    else
    {
        qDebug()<<"Nie zapisano biletu"<<queryAdd.lastError();
    }

}

