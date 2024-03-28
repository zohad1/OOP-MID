#pragma once
#include<map>
#include<string>

using namespace std;


class Restaurant {
private:
    map<int, bool> timeSlots; 
    vector<Reservation> reservations; 

public:
    Restaurant() {
        for (int i = 14; i <= 22; i++) {
            timeSlots[i] = true;
        }
    }

    void displayAvailableTimeSlots() {
        cout << "Available Time Slots:\n";
        for (const auto& slot : timeSlots) {
            if (slot.second) {
                cout << slot.first << ":00 PM\n";
            }
        }
    }

    void makeReservation(const string& name, int time, int size) {
        if (timeSlots.find(time) != timeSlots.end() && timeSlots[time]) {
            reservations.emplace_back(name, time, size);
            timeSlots[time] = false;
            cout << "|** Reservation confirmed for " << name << " at " << time << ":00 Hours for " << size << " people **|\n";
        }
        else {
            cout << "Sorry, that time slot is not available. Please choose a different time.\n";
        }
    }

    
    void displayReservations() {
        if (reservations.empty()) {
            cout << "No reservations have been made yet.\n";
            return;
        }
        cout << "\nAll Reservations:\n";
        for (const auto& reservation : reservations) {
            cout << "Name: " << reservation.customerName << ", Time Slot: " << reservation.timeSlot
                << ":00, Group Size: " << reservation.partySize <<endl;
        }
    }
};
