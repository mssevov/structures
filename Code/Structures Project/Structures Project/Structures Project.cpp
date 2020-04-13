// Include, Using, Define
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// Structures, Enumerators
struct NAME {
    string first, middle, last;
};

struct BOARD_PASS {
    char flightNum[6];
    int takenSeats;
};

struct CLIENT {
    struct NAME name;
    int age;
    char id[10];
    char egn[11];
    struct BOARD_PASS bp;
};

struct PLANES {
    string manufacturer;
    string modelName;
    int maxSeats;
};

struct FLIGHT {
    char flightNum[6];
    string origin, destination;
    float distanceToDestination;
    struct PLANES plane;
};

// Functions
void mainMenu(bool& inMainLoop, FLIGHT flight[], int& flightCounter);

void registerFlight(FLIGHT flight[], int& flightCounter);

// Main
int main()
{

    struct CLIENT client[20];
    int flightCounter = 0;
    struct FLIGHT flight[20];
    bool inMainLoop = true;
    while (inMainLoop)
    {
        mainMenu(inMainLoop, flight, flightCounter);
    }
}

// Functions
void mainMenu(bool& inMainLoop, FLIGHT flight[], int& flightCounter)
{
    system("CLS");
    cout << "===========| Main Menu |===========\n";

    cout << "\n0. Quit application...\n";

    cout << "\n-----/ Planes \\-----\n";
    cout << "1. Register a new Plane...\n";
    cout << "2. See Plane information...\n";
    cout << "3. Remove a Plane...\n";

    cout << "\n-----/ Flight \\-----\n";
    cout << "4. Register a new Flight...\n";
    cout << "5. See Flight information...\n";
    cout << "6. Remove a Flight...\n";

    cout << "\n-----/ Client \\-----\n";
    cout << "7. Register a new Client...\n";
    cout << "8. See Client information...\n";
    cout << "9. Remove a Client...\n";


    switch (_getch())
    {
    case 48: //0 -> quit app
        inMainLoop = false;
        break;
    case 49: //1 -> register a new flight
        registerFlight(flight, flightCounter); //function
        break;
    case 50: //2 -> see flight information
        //function
        break;
    case 51: //3 -> remove a flight
        //function
        break;
    case 52: //4 -> register a new client
        //function
        break;
    case 53: //5 -> see client information
        //function
        break;
    case 54: //6 -> remove a client
        //function
        break;
    default:
        cout << "Error...";
        break;
    }

}

void registerFlight(FLIGHT flight[], int& flightCounter)
{
    system("CLS");

    cout << "Flight Number(6 symbols): "; cin >> flight[flightCounter].flightNum;
    cout << "Country/City of origin: "; cin >> flight[flightCounter].origin;
    cout << "Destination: "; cin >> flight[flightCounter].destination;
    cout << "Travel Distance(km): "; cin >> flight[flightCounter].distanceToDestination;
    cout << "Plane: ";
    cout << "\n----Manufacturer: "; cin >> flight[flightCounter].plane.manufacturer;
    cout << "----Model name: "; cin >> flight[flightCounter].plane.modelName;
    cout << "----Max seats: "; cin >> flight[flightCounter].plane.maxSeats;

    flightCounter++;
}
