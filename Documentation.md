# Documentation for structures school project :octocat:

1. Who we are
2. What the is project about
3. How we made the project
4. How the code works

## 1. Who we are

We are students from an IT school in Bulgaria.
* Martin Sevov(9V) - Developer, Team Manager
* Boris Kanev(9A) - Developer
* Hristo Hristov(9B) - Quality Control

## 2. What the project is about

This is a school project. We had to use structures and functions to make a program that can control data.

## 3. How we made the project

We used Visual Studio 2019 and Github to make and work on the project. It was made in C++ and is ~1000 lines long. It took us ~1.5 weeks to go from start to finish.

## 4. How the code works

We used only 2 libraries and 1 header file
```c++
#include <iostream>
#include <string>
#include <conio.h>
```
---

We have 2 main structures: Clients and Flights. And 4 substructures.

```
├── Flights
|	├── Planes
|	└── Take Off Date
|
└── Clients
	├── Name
	└── Board Pass
```

```C++
struct NAME {
	string first, middle, last;
};

struct BOARD_PASS {
	char flightNum[6];
	int takenSeats;
	int oldSeats;
	float ticketPrice = 0.00;
	int ticketNum;
	bool checkedIn = false;
};

struct CLIENT {
	struct NAME name;
	int age;
	char egn[11];
	string married;
	struct BOARD_PASS bp;
};

struct PLANES {
	string manufacturer;
	string modelName;
	int maxSeats;
	int oldMaxSeats = 0;
};

struct TAKE_OFF_DATE {
	int month;
	int day;
};

struct FLIGHT {
	char flightNum[6];
	string origin, destination;
	float distanceToDestination;
	struct PLANES plane;
	TAKE_OFF_DATE dateOfTakeOff;
	int emptySeats;
	bool overbooked = false;
	int passengers = 0;
	int passengersTickets[30];
};
```
---

We have 20 functions
```
int main
	└── mainMenu
		|
		├── registerFlight
		|	|	├── checkFlightNum
		|	|	|		└──checkFlightNumFlight
		|	|	├── checkMonth
		|	|	└──  checkDay
		|	|
		|	├── connectFlightClient
		|	|
		|	└── checkOverbooked
		|
		├── informationFlight
		|	|
		|	└── informationPassenger
		|
		├── removeFlight
		|		└── informationFlight
		|
		├── registerClient
		|	|	├── checkMarried
		|	|	└──  checkFlightNumClient
		|	|
		|	├── connectFlightClient
		|	|
		|	└── checkSeats
		|			└── checkOverbooked
		|
		├── informationClient
		|
		├── removeClient
		|		└── informationClient
		|
		├── editClient
		|	|	├── informationClient 
		|	|	├── checkMarried
		|	|	└──  checkFlightNumClient
		|	|
		|	└── checkSeats
		|			└── checkOverbooked
		|
		└── editFlight
			|	└── informationFlight
			|	├── checkFlightNum
			|	|	└──checkFlightNumFlight
			|	├── checkMonth
			|	└──  checkDay
			|
			├── checkEmptySeatsAfterMaxChange
			|
			└── checkOverbooked
```
---

Boris worked on the Client functions and the deleting functions

Martin worked on the Flight functions and the checking functions

---

