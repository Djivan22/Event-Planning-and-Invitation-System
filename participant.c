#include <stdio.h>
#include <string.h>
#include "participant.h"

Participant participants[MAX_PARTICIPANTS];
int participantCount = 0;

void registerParticipant()
{
    if (participantCount >= MAX_PARTICIPANTS)
    {
        printf("Participant limit reached!\n");
        return;
    }
    Participant newParticipant;
    newParticipant.id = participantCount + 1;
    printf("Enter participant name: ");
    scanf(" %s[^\n]", newParticipant.name);
    printf("Enter participant email: ");
    scanf("%s", newParticipant.email);
    printf("Enter event ID to register for: ");
    scanf("%d", &newParticipant.eventId);

    participants[participantCount++] = newParticipant;
    printf("Participant registered successfully!\n");
}

void viewParticipants()
{
    printf("\nParticipants:\n");
    for (int i = 0; i < participantCount; i++)
    {
        printf("ID: %d, Name: %s, Email: %s, Event ID: %d\n", participants[i].id, participants[i].name, participants[i].email, participants[i].eventId);
    }
}

void sendInvitations()
{
    int eventId;
    printf("Enter event ID to send invitations for: ");
    scanf("%d", &eventId);

    printf("Sending invitations for Event ID: %d\n", eventId);
    for (int i = 0; i < participantCount; i++)
    {
        if (participants[i].eventId == eventId)
        {
            printf("Invitation sent to %s (%s)\n", participants[i].name, participants[i].email);
        }
    }
}