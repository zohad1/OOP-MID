#pragma once
#include<string>
using namespace std;
class Reservation {
public:
    string customerName;
    int timeSlot; 
    int partySize;

    Reservation(string name, int slot, int size)
        : customerName(name), timeSlot(slot), partySize(size) {}
};
