#ifndef TICKET_H
#define TICKET_H
#include <QString>

struct TicketType{

    QString trainNum;
    QString destination;
    QString origin;
    QString platform;
    QString track;
    QString arrival;
    QString departure;
    QString ticketType;
    QString classType;
    QString seatType;
    QString cost;
    int ticketNum;
};

class Ticket
{
public:
    Ticket();
    static TicketType* createTicket();

    static int ticketsCount;

};

#endif // TICKET_H
