#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ticket_system.h"

TicketSystem* createSystem() {

    TicketSystem* system = (TicketSystem*)malloc(sizeof(TicketSystem));

    if (system == NULL) {
        fprintf(stderr, "Memory allocation failed for TicketSystem.\n");
        exit(1);

    } // end of if

    system->tickets = NULL;
    system->count = 0;

    return system;
} // end of ticket system

void addTicket(TicketSystem* system, int id, const char* desc, int priority, float hours) {

    system->tickets = (Ticket*)realloc(system->tickets, (system->count + 1) * sizeof(Ticket));

    if (system->tickets == NULL) {
        fprintf(stderr, "Memory reallocation failed for tickets.\n");
        exit(1);

    } // end of if

    Ticket* newTicket = &system->tickets[system->count];
    newTicket->ticketID = id;
    strncpy(newTicket->description, desc, 99);

    newTicket->description[99] = '\0';
    newTicket->priority = priority;
    newTicket->estimatedHours = hours;

    system->count++;
}

void displayTickets(TicketSystem* system) {

    printf("Current Support Tickets (%d):\n", system->count);

    for (int i = 0; i < system->count; i++) {
        Ticket t = system->tickets[i];
        printf("Ticket #%d\n", t.ticketID);
        printf("Description: %s\n", t.description);
        printf("Priority: %d\n", t.priority);
        printf("Estimated Resolution Time: %.1f hours\n", t.estimatedHours);
        printf("---------------------------\n");
        printf("\n");
    } // end of fpor

} // end of displayTickets

void freeSystem(TicketSystem* system) {
    free(system->tickets);
    free(system);

} // end of free
