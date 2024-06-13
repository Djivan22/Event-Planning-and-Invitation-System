#ifndef EVENT_H
#define EVENT_H

#define MAX_EVENTS 100

typedef struct {
    int id;
    char name[50];
    char date[20];
    char location[100];
} Event;

extern Event events[MAX_EVENTS];
extern int eventCount;

void createEvent();
void viewEvents();

#endif