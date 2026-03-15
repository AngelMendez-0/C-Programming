#ifndef TICKET_SYSTEM_H
#define TICKET_SYSTEM_H

typedef struct {
    int ticketID;
    char description[100];
    int priority;
    float estimatedHours;

} Ticket; // end of ticket

typedef struct {
    Ticket* tickets;
    int count;

} TicketSystem; // end of struct type

TicketSystem* createSystem();

void addTicket(TicketSystem* system, int id, const char* desc, int priority, float hours);

void displayTickets(TicketSystem* system);

void freeSystem(TicketSystem* system);

#endif
