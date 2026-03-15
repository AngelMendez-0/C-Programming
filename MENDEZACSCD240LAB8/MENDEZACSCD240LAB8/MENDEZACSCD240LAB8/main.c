#include <stdio.h>
#include "ticket_system.h"

int main() {

    TicketSystem* system = createSystem();

    addTicket(system, 1001, "Cannot connect to VPN", 2, 1.5f);

    addTicket(system, 1002, "crash on login", 1, 2.0f);

    addTicket(system, 1003, "Email sync delay", 3, 0.5f);

    displayTickets(system);
    freeSystem(system);

    return 0;
} // end of main
