#include <stdio.h>  

#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_PARTICIPANTS 100
/*структура за направата на събития
integer дефиниращ ID което е hard code-нато до 100  */
typedef struct {   
    int id;
    char name[50];
    char date[20];
    char location[100];
} Event;

typedef struct {
    int id;
    char name[50];
    char email[50];
    int eventId;
} Participant;

Event events[MAX_EVENTS];
Participant participants[MAX_PARTICIPANTS];
int eventCount = 0;
int participantCount = 0;

// main structure for the whole code (creating event, sending invitations and registering participants ) 
void createEvent();
void registerParticipant();
void sendInvitations();
// view events and participants
void viewEvents();
void viewParticipants();
// save and load data 
void saveData();
void loadData();

int main() {
    int choice;

    loadData();
// докато е вярно принтира f-овете и след това минава в switchcase според user choice 
    while (1) {
        printf("\nEvent Planning and Invitation System\n");
        printf("1. Създаване на събитие\n");
        printf("2. Регистриране на участник\n");
        printf("3. Изпращане на покана\n");
        printf("4. Списък със събитията\n");
        printf("5. Списък с участници\n");
        printf("6. Изход\n");
        printf("Моля въведете вашият избор: ");
        scanf("%d", &choice);

        switch (choice) {
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
void createEvent() {
    if (eventCount >= MAX_EVENTS) {
        printf("Event limit reached!\n");
        return;
    }
    Event newEvent;
    newEvent.id = eventCount + 1;
    printf("Enter event name: ");
    scanf(" %[^\n]", newEvent.name);
    printf("Enter event date (YYYY-MM-DD): ");
    scanf("%s", newEvent.date);
    printf("Enter event location: ");
    scanf(" %[^\n]", newEvent.location);

    events[eventCount++] = newEvent;
    printf("Event created successfully!\n");
}

void registerParticipant() {
    if (participantCount >= MAX_PARTICIPANTS) {
        printf("Participant limit reached!\n");
        return;
    }
    Participant newParticipant;
    newParticipant.id = participantCount + 1;
    printf("Enter participant name: ");
    scanf(" %[^\n]", newParticipant.name);
    printf("Enter participant email: ");
    scanf("%s", newParticipant.email);
    printf("Enter event ID to register for: ");
    scanf("%d", &newParticipant.eventId);

    participants[participantCount++] = newParticipant;
    printf("Participant registered successfully!\n");
}

void sendInvitations() {
    int eventId;
    printf("Enter event ID to send invitations for: ");
    scanf("%d", &eventId);

    printf("Sending invitations for Event ID: %d\n", eventId);
    for (int i = 0; i < participantCount; i++) {
        if (participants[i].eventId == eventId) {
            printf("Invitation sent to %s (%s)\n", participants[i].name, participants[i].email);
        }
    }
}

void viewEvents() {
    printf("\nEvents:\n");
    for (int i = 0; i < eventCount; i++) {
        printf("ID: %d, Name: %s, Date: %s, Location: %s\n", events[i].id, events[i].name, events[i].date, events[i].location);
    }
}

void viewParticipants() {
    printf("\nParticipants:\n");
    for (int i = 0; i < participantCount; i++) {
        printf("ID: %d, Name: %s, Email: %s, Event ID: %d\n", participants[i].id, participants[i].name, participants[i].email, participants[i].eventId);
    }
}
void saveData() {
    FILE *file = fopen("events.dat", "wb");
    if (file != NULL) {
        fwrite(&eventCount, sizeof(int), 1, file);
        fwrite(events, sizeof(Event), eventCount, file);
        fclose(file);
    }

    file = fopen("participants.dat", "wb");
    if (file != NULL) {
        fwrite(&participantCount, sizeof(int), 1, file);
        fwrite(participants, sizeof(Participant), participantCount, file);
        fclose(file);
    }
}

void loadData() {
    FILE *file = fopen("events.dat", "rb");
    if (file != NULL) {
        fread(&eventCount, sizeof(int), 1, file);
        fread(events, sizeof(Event), eventCount, file);
        fclose(file);
    }

    file = fopen("participants.dat", "rb");
    if (file != NULL) {
        fread(&participantCount, sizeof(int), 1, file);
        fread(participants, sizeof(Participant), participantCount, file);
        fclose(file);
    }
}