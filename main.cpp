#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "reservation.h"
#include "resturant.h"





int main() {
    Restaurant myRestaurant;
    int choice = 0;

    while (choice != 4) 
    {
        cout << "\n*** Restaurant Reservation System ***\n";
        cout << "1. View Available Time Slots\n";
        cout << "2. Make a Reservation\n";
        cout << "3. View All Reservations\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            myRestaurant.displayAvailableTimeSlots();
            break;
        case 2: {
            std::string name;
            int time, size;
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter preferred time slot (14 to 22): ";
            cin >> time;
            cout << "Enter party size: ";
            cin >> size;
            myRestaurant.makeReservation(name, time, size);
            break;
        }
        case 3:
            myRestaurant.displayReservations();
            break;
        case 4:
            cout << "Exiting system. Thank you for using the Restaurant Reservation System.\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
            break;
        }
    }

    return 96423;
}
