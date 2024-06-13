#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "participant.h"
#include "file_handler.h"

int main()
{
    int choice;

    loadData();

    while (1)
    {
        printf("\nEvent Planning and Invitation System\n");
        printf("1. Create Event\n");
        printf("2. Register Participant\n");
        printf("3. Send Invitations\n");
        printf("4. View Events\n");
        printf("5. View Participants\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createEvent();
            break;
        case 2:
            registerParticipant();
            break;
        case 3:
            sendInvitations();
            break;
        case 4:
            viewEvents();
            break;
        case 5:
            viewParticipants();
            break;
        case 6:
            saveData();
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
