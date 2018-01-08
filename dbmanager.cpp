#include "dbmanager.h"
#include "dashboard.h"
#include <QDebug>

DbManager::DbManager()
{
    QString path = "polaczenie.db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
    if(!db.open()){
        qDebug() << "Nie można połączyć z bazą danych";
    }
}

DbManager::~DbManager()
{
    db.close();
}

QList<Connection> DbManager::getCurrentConnections()
{
    QList<Connection> connections;
    Connection connection;
    int trainId, destId, originId, platformId, trackId, arrivalId, departureId;

    QSqlQuery query("SELECT * FROM Connections");

    trainId = query.record().indexOf("TrainNum");
    destId = query.record().indexOf("Destination");
    originId = query.record().indexOf("Origin");
    platformId = query.record().indexOf("Platform");
    trackId = query.record().indexOf("Track");
    arrivalId = query.record().indexOf("Arrival");
    departureId = query.record().indexOf("Departure");

    while(query.next()){

     connection.trainNum = query.value(trainId).toString();
     connection.destination = query.value(destId).toString();
     connection.origin = query.value(originId).toString();
     connection.platform = query.value(platformId).toChar();
     connection.track = query.value(trackId).toString();
     connection.arrival = query.value(arrivalId).toString();
     connection.departure = query.value(departureId).toString();
     connections.append(connection);
    }

    return connections;
}


