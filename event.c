#include <stdio.h>
#include <string.h>
#include "event.h"

Event events[MAX_EVENTS];
int eventCount = 0;

void createEvent()
{
    if (eventCount >= MAX_EVENTS)
    {
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

void viewEvents()
{
    printf("\nEvents:\n");
    for (int i = 0; i < eventCount; i++)
    {
        printf("ID: %d, Name: %s, Date: %s, Location: %s\n", events[i].id, events[i].name, events[i].date, events[i].location);
    }
}