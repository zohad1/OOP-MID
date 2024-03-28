#include <iostream>
#include <vector>
#include <map>
#include <string>

// Reservation class to store reservation details
class Reservation {
public:
    std::string customerName;
    int timeSlot; // Assuming military time for simplicity (e.g., 1800 for 6 PM)
    int partySize;

    Reservation(std::string name, int slot, int size) 
        : customerName(name), timeSlot(slot), partySize(size) {}
};

// Restaurant class to manage reservations and time slots
class Restaurant {
private:
    std::map<int, bool> timeSlots; // Tracks availability of time slots (true if available)
    std::vector<Reservation> reservations; // Stores all reservations

public:
    // Constructor initializes available time slots
    Restaurant() {
        // Assuming the restaurant operates from 6 PM to 10 PM (1800 to 2200 hours)
        for (int i = 18; i <= 22; ++i) {
            timeSlots[i] = true; // Mark all time slots as initially available
        }
    }

    // Display available time slots to the user
    void displayAvailableTimeSlots() {
        std::cout << "Available Time Slots:\n";
        for (const auto& slot : timeSlots) {
            if (slot.second) { // If slot is available
                std::cout << slot.first << "00 Hours\n";
            }
        }
    }

    // Accept a reservation from the user
    void makeReservation(const std::string& name, int time, int size) {
        if (timeSlots.find(time) != timeSlots.end() && timeSlots[time]) {
            reservations.emplace_back(name, time, size);
            timeSlots[time] = false; // Mark this time slot as booked
            std::cout << "Reservation confirmed for " << name << " at " << time << "00 Hours for " << size << " people.\n";
        } else {
            std::cout << "Sorry, that time slot is not available. Please choose a different time.\n";
        }
    }
};

int main() {
    Restaurant myRestaurant;
    int choice = 0;

    while (choice != 3) {
        std::cout << "\n*** Restaurant Reservation System ***\n";
        std::cout << "1. View Available Time Slots\n";
        std::cout << "2. Make a Reservation\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            myRestaurant.displayAvailableTimeSlots();
        } else if (choice == 2) {
            std::string name;
            int time, size;
            std::cout << "Enter your name: ";
            std::cin >> name;
            std::cout << "Enter preferred time slot (18 to 22): ";
            std::cin >> time;
            std::cout << "Enter party size: ";
            std::cin >> size;
            myRestaurant.makeReservation(name, time, size);
        } else if (choice == 3) {
            std::cout << "Exiting system. Thank you for using the Restaurant Reservation System.\n";
        } else {
            std::cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}

