// Include, Using, Define
#include <iostream>
#include <string>
using namespace std;

// Structures, Enumerators
struct CLIENT {
    NAME name;
    int age;
    char id[10];
    char egn[11];
    BOARD_PASS bp;
};

struct NAME {
    string first, middle, last;
};

struct BOARD_PASS {
    char flightNum[6];
    int takenSeats;
};

struct FLIGHT {
    char flightNum[6];
    string origin, destination;
    int distanceToDestination;
    TAKE_OFF_TIME date;
    PLANES plane;
};

enum MONTHS {
    January = 1,
    February = 2,
    March = 3,
    April = 4,
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12
};

struct TAKE_OFF_TIME {
    int year;
    enum MONTHS month;
    int hour;
    int minutes;
};

struct PLANES {
    string manufacturer;
    string modelName;
    int maxSeats;
};


// Functions
void mainMenu();

// Main
int main()
{
    struct CLIENT client[20];
    struct FLIGHT flight[20];
    while (true)
    {
        mainMenu();
    }
}

// Functions
void mainMenu()
{

}