#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#define MAX_PARTICIPANTS 100

typedef struct {
    int id;
    char name[50];
    char email[50];
    int eventId;
} Participant;

extern Participant participants[MAX_PARTICIPANTS];
extern int participantCount;

void registerParticipant();
void viewParticipants();
void sendInvitations();

#endif