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
void mainMenu(bool& inMainLoop, FLIGHT flight[], int& flightCounter, CLIENT client[], int& clientCounter); //mainMenu

void registerFlight(FLIGHT flight[], int& flightCounter);

void registrationClient(CLIENT client[], int& clientCounter); //registration CLIENT

void informationClient(CLIENT client[], int& clientCounter); //information Client

// Main
int main()
{
    int clientCounter = 0;
    struct CLIENT client[20];
    int flightCounter = 0;
    struct FLIGHT flight[20];
    bool inMainLoop = true;
    while (inMainLoop)
    {
        mainMenu(inMainLoop, flight, flightCounter, client, clientCounter);
    }
}

// Functions
void mainMenu(bool& inMainLoop, FLIGHT flight[], int& flightCounter, CLIENT client[], int& clientCounter)
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
        registrationClient(client, clientCounter);//function
        break;
    case 53: //5 -> see client information
        informationClient(client, clientCounter);//function
        break;
    case 54: //6 -> remove a client
        //function
        break;
    default:
        cout << "Error...";
        break;
    }
}

void registrationClient(CLIENT client[], int& clientCounter) //registration client Functions
{
    system("CLS");
    cout << "First name: ";
    cin >> client[clientCounter].name.first;
    cout << "Middle name: ";
    cin >> client[clientCounter].name.middle;
    cout << "Last name: ";
    cin >> client[clientCounter].name.last;
    cout << "Age: ";
    cin >> client[clientCounter].age;
    cout << "ID: ";
    cin >> client[clientCounter].id; //bug!!! replace twice
    cout << "EGN: ";
    cin >> client[clientCounter].egn;
    cout << "Board pass\n";
    cout << "Flight Num: ";
    cin >> client[clientCounter].bp.flightNum;
    cout << "Taken Seats: ";
    cin >> client[clientCounter].bp.takenSeats;

    clientCounter++;
}

void informationClient(CLIENT client[], int& clientCounter) //information Client Functions
{
    system("CLS");
    for (int i = 0; i < clientCounter; i++)
    {
        cout << "Name: "<< client[i].name.first<<" "<< client[i].name.middle<<" "<< client[i].name.last;
        cout << "\nAge: " << client[i].age;
        cout << "\nID: " << client[i].id; //bug!!! replace twice
        cout << "\nEGN: " << client[i].egn;
        cout << "\nBoard pass\n";
        cout << "Flight Num: " << client[i].bp.flightNum;
        cout << "\nTaken Seats: " << client[i].bp.takenSeats << "\n";
        cout << "\n";

    }
    system("PAUSE");
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
