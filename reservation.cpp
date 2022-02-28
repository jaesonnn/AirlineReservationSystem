/* Author:      Floyd Ack
 * Date:        Saturday, 19 June 2020
 * Github:      https://github.com/jaesonnn
 * Twitter:     https://twitter.com/WellFloyd
 * Facebook:    https://www.facebook.com/jason.ack/
 * Instagram:   https://www.instagram.com/wellfloyd_/
*/

#include "reservation.h"

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

Reservation::Reservation()
{
    // initializes the array to 0
    for(int i=0; i<seats; i++) {
        plane[i] = 0;
    }

    seats = 10;
}

// returns the current number of availabe seats
int Reservation::getSeats()
{
    return seats;
}

// reserves a seat in the smoking section
int Reservation::reserveSmoking(int seatLocation)
{
    if(seatLocation > 4 || seatLocation < 0)
        return -1;
    else if(plane[seatLocation] == 0)
    {
        plane[seatLocation]++;
        reduceAvailableSeats();
        return seatLocation;
    }
    return -1;
//    if(plane[seatLocation] == 0)
//    {
//        plane[seatLocation]++;
//        reduceAvailableSeats();
//        return seatLocation;
//    }
//    else if(seatLocation > 4 || seatLocation < 0) {
//        return -1;
//    }

//    return -1;
}

// randomly reserves a seat in the smoking section
int Reservation::reserveRandomSmoking()
{
    srand(time(0));

    int randSmokingSeat = rand() % 5;      // generates a random number between 0 and 5

    for(randSmokingSeat=0; randSmokingSeat<5; randSmokingSeat++)
    {
        if(plane[randSmokingSeat] == 0)
        {
            plane[randSmokingSeat]++;
            reduceAvailableSeats();
            return randSmokingSeat;
        }
    }
    return 0;
}

// reserves a seat in the smoking section 
int Reservation::reserveNonSmoking(int seatLocation)
{
    if(seatLocation > 9 || seatLocation < 5) {
        cout << "Sorry. There isn't any seats.\n";
        return -1;
    }
    else if(plane[seatLocation] == 0)
    {
        plane[seatLocation]++;
        reduceAvailableSeats();
        return seatLocation;
    }
    return -1;
}

int Reservation::reserveRandomNonSmoking()
{
    srand(time(0));

    int randNonSmokingSeat = rand() % 5 + 5;      // generates a random number between 6 and 10

    for(randNonSmokingSeat=5; randNonSmokingSeat<5; randNonSmokingSeat++)
    {
        if(plane[randNonSmokingSeat] == 0)
        {
            plane[randNonSmokingSeat]++;
            reduceAvailableSeats();
        }
    }
    return randNonSmokingSeat;
}

// checks if there are available seats in the non-smoking section
bool Reservation::availableNonSmoking()
{
    for(int i=6; i<10; i++)
    {
        if(plane[i] == 0)
            return true;
    }
    return false;
}

// checks if there are available seats in the smoking section
bool Reservation::availableSmoking()
{
    for(int i=0; i<5; i++)
    {
        if(plane[i] == 0)
            return true;
    }
    return false;
}

// called every time a reservation is successfully made in either sections decrementing the number of available seats
void Reservation::reduceAvailableSeats()
{
    seats--;
}
