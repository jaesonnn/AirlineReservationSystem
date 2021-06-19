#ifndef RESERVATION_H
#define RESERVATION_H

const int arraySize = 10;   // array size

class Reservation
{
public:
    Reservation();
    int getSeats();
    int reserveSmoking(int seatLocation);
    int reserveRandomSmoking();
    int reserveNonSmoking(int seatLocation);
    int reserveRandomNonSmoking();
    bool availableNonSmoking();
    bool availableSmoking();

private:
    int plane[arraySize];
    int seats;
    void reduceAvailableSeats();
};

#endif // RESERVATION_H
