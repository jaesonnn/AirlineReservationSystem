#include <iostream>
using namespace std;

#include "reservation.h"

int main()
{
    Reservation flight;         // a Reservation object is created

    int seat;
    int option;
    int choice;
    int secondChoice;

    do {
        cout << " ---------- Airline Reservation System ----------\n"
                "|   Please Type 1 for Smoking Area               |\n"
                "|   Please Type 2 for Non-Smoking Area           |\n"
                "|   Please Type 3 to Exit                        |\n"
                " ------------------------------------------------\n";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nYou have chosen the Smoking Area\n"
                        "\tPress 1 to pick your seat\n"
                        "\tPress 2 for the system to randomly pick a seat for you\n";
                cin >> option;

                if(option == 1)
                {
                    if(flight.availableSmoking())
                    {
                        cout << ">> Please choose a seat from 0-4: ";
                        cin >> seat;
                        if(flight.reserveSmoking(seat) == -1) {
                            cout << ">> Sorry, that seat is already reserved.\n\n";
                        }
                        else {
                            cout << "     BOARDING PASS\n"
                                    "     SEAT LOCATION: " << seat << "\n"
                                    "     SECTION: SMOKING\n\n";
                        }
                    }
                    else if(flight.availableSmoking() == false)
                    {
                        cout << "Smoking section is full. Would you like to reserve a seat in the Non-smoking section?\n"
                                "\tIf YES, enter 1\n"
                                "\tIf NO, enter 2\n";
                        cin >> secondChoice;

                        switch(secondChoice)
                        {
                            case 1:
                                if(flight.availableNonSmoking() == true) {
                                    cout << "     BOARDING PASS\n"
                                            "     SEAT LOCATION: " << flight.reserveRandomNonSmoking() << "\n"
                                            "     SECTION: NON-SMOKING\n\n";
                                }
                                else if(flight.availableNonSmoking() == false) {
                                    cout << "No available seats remaining.\n"
                                            "Next flight leaves in 3 hours.\n\n";
                                }
                                break;
                            case 2: cout << "Next flight leaves in 3 hours.\n\n"; break;
                            default: cout << "Invalid option.\n\n"; break;
                        }
                    }   // end of else-if statement
                }
                else if(option == 2) {
                    cout << "     BOARDING PASS\n"
                            "     SEAT LOCATION: " << flight.reserveRandomSmoking() << "\n"
                            "     SECTION: NON-SMOKING\n\n";
                }
                break;
            case 2:
                cout << "\nYou have chosen the Non-Smoking Area\n"
                        "\tPress 1 to pick your seat\n"
                        "\tPress 2 for the system to randomly pick a seat for you\n";
                cin >> option;

                if(option == 1)
                {
                    if(flight.availableNonSmoking() == true)
                    {
                        cout << ">> Please choose a seat from 5-9: ";
                        cin >> seat;
                        if(flight.reserveNonSmoking(seat) == -1) {
                            cout << ">> Sorry, that seat is already reserved.\n\n";
                        }
                        else {
                            cout << "     BOARDING PASS\n"
                                    "     SEAT LOCATION: " << seat << "\n"
                                    "     SECTION: NON-SMOKING\n\n";
                        }
                    }
                    else if(flight.availableNonSmoking() == false)
                    {
                        cout << "Non-smoking section is full. Would you like to reserve another seat?\n"
                                "\tIf YES, enter 3\n"
                                "\tIf NO, enter 4\n";
                        cin >> secondChoice;

                        switch(secondChoice)
                        {
                            case 3:
                                if(flight.availableSmoking() == true) {
                                    cout << "     BOARDING PASS\n"
                                            "     SEAT LOCATION: " << flight.reserveRandomSmoking() << "\n"
                                            "     SECTION: SMOKING\n\n";
                                }
                                else if(flight.availableSmoking() == false) {
                                    cout << "No available seats remaining.\n"
                                            "Next flight leaves in 3 hours.\n\n";
                                }
                                break;
                            case 4: cout << "Next flight leaves in 3 hours.\n\n"; break;
                            default: cout << "Invalid option.\n\n"; break;
                        }
                    }   // end of else-if statement
                }
                else if(option == 2) {
                    cout << "     BOARDING PASS\n"
                            "     SEAT LOCATION: " << flight.reserveRandomNonSmoking() << "\n"
                            "     SECTION: NON-SMOKING\n\n";
                }
        }   // end of switch
    } while(choice != 3);

    return 0;
}
