#include <stdio.h>
#include "event.h"
#include "participant.h"

void saveData()
{
    FILE *file = fopen("events.dat", "wb");
    if (file != NULL)
    {
        fwrite(&eventCount, sizeof(int), 1, file);
        fwrite(events, sizeof(Event), eventCount, file);
        fclose(file);
    }

    file = fopen("participants.dat", "wb");
    if (file != NULL)
    {
        fwrite(&participantCount, sizeof(int), 1, file);
        fwrite(participants, sizeof(Participant), participantCount, file);
        fclose(file);
    }
}

void loadData()
{
    FILE *file = fopen("events.dat", "rb");
    if (file != NULL)
    {
        fread(&eventCount, sizeof(int), 1, file);
        fread(events, sizeof(Event), eventCount, file);
        fclose(file);
    }

    file = fopen("participants.dat", "rb");
    if (file != NULL)
    {
        fread(&participantCount, sizeof(int), 1, file);
        fread(participants, sizeof(Participant), participantCount, file);
        fclose(file);
    }
}