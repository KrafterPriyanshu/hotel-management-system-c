#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100

// Structure to represent a room
typedef struct {
    int roomNumber;
    char guestName[50];
    int occupied;
} Room;

// Function prototypes
void initializeRooms(Room rooms[], int numRooms);
void displayMenu();
void displayRooms(Room rooms[], int numRooms);
void checkIn(Room rooms[], int numRooms);
void checkOut(Room rooms[], int numRooms);
void displayGuests(Room rooms[], int numRooms);

int main() {
    Room rooms[MAX_ROOMS];
    int numRooms = 10; // Change this based on your hotel size

    initializeRooms(rooms, numRooms);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRooms(rooms, numRooms);
                break;
            case 2:
                checkIn(rooms, numRooms);
                break;
            case 3:
                checkOut(rooms, numRooms);
                break;
            case 4:
                displayGuests(rooms, numRooms);
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

void initializeRooms(Room rooms[], int numRooms) {
    for (int i = 0; i < numRooms; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].occupied = 0; // 0 indicates the room is vacant
        strcpy(rooms[i].guestName, "");
    }
}

void displayMenu() {
    printf("\n=== Hotel Management System ===\n");
    printf("1. Display Rooms\n");
    printf("2. Check-In\n");
    printf("3. Check-Out\n");
    printf("4. Display Guests\n");
    printf("0. Exit\n");
}

void displayRooms(Room rooms[], int numRooms) {
    printf("\n=== List of Rooms ===\n");
    for (int i = 0; i < numRooms; i++) {
        printf("Room %d: %s\n", rooms[i].roomNumber, rooms[i].occupied ? rooms[i].guestName : "Vacant");
    }
}

void checkIn(Room rooms[], int numRooms) {
    int roomNumber;
    printf("Enter room number for check-in: ");
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > numRooms) {
        printf("Invalid room number. Please try again.\n");
        return;
    }

    if (rooms[roomNumber - 1].occupied) {
        printf("Room %d is already occupied.\n", roomNumber);
    } else {
        printf("Enter guest name for Room %d: ", roomNumber);
        scanf("%s", rooms[roomNumber - 1].guestName);
        rooms[roomNumber - 1].occupied = 1;
        printf("Check-in successful for Room %d.\n", roomNumber);
    }
}

void checkOut(Room rooms[], int numRooms) {
    int roomNumber;
    printf("Enter room number for check-out: ");
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > numRooms) {
        printf("Invalid room number. Please try again.\n");
        return;
    }

    if (rooms[roomNumber - 1].occupied) {
        printf("Checking out %s from Room %d.\n", rooms[roomNumber - 1].guestName, roomNumber);
        strcpy(rooms[roomNumber - 1].guestName, "");
        rooms[roomNumber - 1].occupied = 0;
    } else {
        printf("Room %d is already vacant.\n", roomNumber);
    }
}

void displayGuests(Room rooms[], int numRooms) {
    printf("\n=== List of Guests ===\n");
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].occupied) {
            printf("Room %d: %s\n", rooms[i].roomNumber, rooms[i].guestName);
        }
    }
}
