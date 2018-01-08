#include "ticket.h"

Ticket::Ticket()
{

}

TicketType* Ticket::createTicket()
{
    ticketsCount++;

    TicketType *ticket = new TicketType();
    ticket->origin = "";
    ticket->destination = "";
    ticket->departure = "";
    ticket->arrival = "";
    ticket->platform = 'A';
    ticket->track = 99;
    ticket->ticketType = "";
    ticket->classType = "";
    ticket->seatType = "";
    ticket->ticketNum = ticketsCount;

    return ticket;
}

int Ticket::ticketsCount = 0;
