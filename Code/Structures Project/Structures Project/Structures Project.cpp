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

// Functions
void mainMenu(bool& inMainLoop, FLIGHT flight[], int& flightCounter, CLIENT client[], int& clientCounter, int& editIndex, int& fId); //mainMenu

void registerFlight(FLIGHT flight[], int& flightCounter); //register Flight

void informationFlight(FLIGHT flight[], int& flightCounter); //information Flight

int editFlight(FLIGHT flight[], int& flightCounter); //Edit Flight 

void removeFlight(FLIGHT flight[], int& flightCounter); //Remove Flight 

void registerClient(CLIENT client[], int& clientCounter); //register Client

void informationClient(CLIENT client[], int& clientCounter); //information Client

void removeClient(CLIENT client[], int& clientCounter); //Remove Client

int editClient(CLIENT client[], int& clientCounter); //Edit Client 

void checkMonth(FLIGHT flight[], int i); //Checks if the month is possible

void checkDay(FLIGHT flight[], int i); //Checks if the day is possible

void connectFlightClient(FLIGHT flight[], int flightCounter, CLIENT client[], int clientCounter); //Connects Flights and Clients and checks seats

void informationPassenger(FLIGHT flight[], int flightCounter, CLIENT client[], int clientCounter); //information passengers-clients

void checkFlightNum(FLIGHT flight[], int flightCounter); //checks for flight num duplicates

void checkFlightNumClient(CLIENT client[], int clientCounter); //checks for flight num len

void checkFlightNumFlight(FLIGHT flight[], int flightCounter); //checks for flight num len

void checkMarried(CLIENT client[], int clientCounter); //checks if client is married

void checkSeats(FLIGHT flight[], int flightCounter, CLIENT client[], int clientCounter, int& editIndex); //checks the client seats

void checkOverbooked(FLIGHT flight[], int flightCounter, int fId); //checks if flight is overbooked

void checkEmptySeatsAfterMaxChange(FLIGHT flight[], int fId); //updates empty seats after the max is changed

// Main
int main()
{
	int clientCounter = 0;
	struct CLIENT client[20];
	int flightCounter = 0;
	struct FLIGHT flight[20];
	int editIndex = 0;
	int fId = 0;
	bool inMainLoop = true;
	while (inMainLoop)
	{
		mainMenu(inMainLoop, flight, flightCounter, client, clientCounter, editIndex, fId);
	}
}

// Functions
void mainMenu(bool& inMainLoop, FLIGHT flight[], int& flightCounter, CLIENT client[], int& clientCounter, int& editIndex, int& fId)
{
	system("CLS");
	cout << "===========| Main Menu |===========\n";

	cout << "\nEsc. Quit application...\n";

	cout << "\n-----/ Flight \\-----\n";
	cout << "1. Register a new Flight...\n";
	cout << "2. See Flight information...\n";
	cout << "3. Remove a Flight...\n";

	cout << "\n-----/ Client \\-----\n";
	cout << "4. Register a new Client...\n";
	cout << "5. See Client information...\n";
	cout << "6. Remove a Client...\n";

	cout << "\n-----/ Edit \\-----\n";

	cout << "7. Edit client info...\n";
	cout << "8. Edit Flight info...\n";


	switch (_getch())
	{
	case 27: //Esc -> quit app
		inMainLoop = false;
		break;
	case '1': //1 -> register a new flight
		registerFlight(flight, flightCounter); //function
		connectFlightClient(flight, flightCounter, client, clientCounter);
		fId = flightCounter - 1;
		checkOverbooked(flight, flightCounter, fId);
		break;
	case 50: //2 -> see flight information
		informationFlight(flight, flightCounter);//function
		informationPassenger(flight, flightCounter, client, clientCounter);
		break;
	case 51: //3 -> remove a flight
		removeFlight(flight, flightCounter);//function
		break;
	case 52: //4 -> register a new client
		registerClient(client, clientCounter);//function
		connectFlightClient(flight, flightCounter, client, clientCounter);
		editIndex = clientCounter - 1;
		checkSeats(flight, flightCounter, client, clientCounter, editIndex);
		break;
	case 53: //5 -> see client information
		informationClient(client, clientCounter);//function
		break;
	case 54: //6 -> remove a client
		removeClient(client, clientCounter);//function
		break;
	case 55: //7 -> edit client
		editIndex = editClient(client, clientCounter);//function
		checkSeats(flight, flightCounter, client, clientCounter, editIndex);
		break;
	case 56: //8 -> edit Flight
		fId = editFlight(flight, flightCounter);//function
		checkEmptySeatsAfterMaxChange(flight, fId);
		checkOverbooked(flight, flightCounter, fId);
		break;
	default:
		cout << "Error...";
		break;
	}

}

void registerClient(CLIENT client[], int& clientCounter) //register client Function
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
	cout << "EGN: ";
	cin >> client[clientCounter].egn;
	cout << "Married or not(yes/no): ";
	cin >> client[clientCounter].married;
	checkMarried(client, clientCounter);
	cout << "Board pass\n";
	cout << "Flight Num(6 symbols): ";
	cin >> client[clientCounter].bp.flightNum;
	checkFlightNumClient(client, clientCounter);
	cout << "Taken Seats: ";
	client[clientCounter].bp.oldSeats = 0;
	cin >> client[clientCounter].bp.takenSeats;




	client[clientCounter].bp.ticketNum = clientCounter;

	clientCounter++;
}

void informationClient(CLIENT client[], int& clientCounter) //information Client Function
{
	system("CLS");
	if (clientCounter == 0)
	{
		cout << "No Clients present in the system...";
		_getch();
	}
	else
	{
		for (int i = 0; i < clientCounter; i++)
		{
			cout << "ID:" << i;
			cout << "\nName: " << client[i].name.first << " " << client[i].name.middle << " " << client[i].name.last;
			cout << "\nAge: " << client[i].age;
			cout << "\nEGN: " << client[i].egn;
			cout << "\nMarried: " << client[i].married;
			cout << "\nBoard pass\n";
			cout << "Flight Num: " << client[i].bp.flightNum;
			cout << "\nTaken Seats: " << client[i].bp.takenSeats;
			cout << "\n\n";

		}
		_getch();
	}
}

void removeClient(CLIENT client[], int& clientCounter) //Remove Client Function
{
	informationClient(client, clientCounter);
removeStart:
	system("CLS");
	int index;
	cout << "Choose id: ";
	cin >> index;
	if (index > clientCounter or index < 0) //checking index in range of client counter 
	{
		cout << "Error...\n";
		goto removeStart;
	}
	else
	{
		cout << "id:" << index;
		cout << "\nName: " << client[index].name.first << " " << client[index].name.middle << " " << client[index].name.last;
		cout << "\nAge: " << client[index].age;
		cout << "\nEGN: " << client[index].egn;
		cout << "\nMarried: " << client[index].married;
		cout << "\nBoard pass\n";
		cout << "Flight Num: " << client[index].bp.flightNum;
		cout << "\nTaken Seats: " << client[index].bp.takenSeats << "\n";
		cout << "\n";


		for (int i = index; i < clientCounter - 1; i++) //delete index register client
		{
			client[i] = client[i + 1];
		}
		clientCounter--;

	}
	_getch();
}

int editClient(CLIENT client[], int& clientCounter)
{
	system("CLS");
	if (clientCounter == 0)
	{
		cout << "No Clients present in the system...";
		_getch();
		return -1;
	}
	else
	{
	editClientStart:
		informationClient(client, clientCounter);
		int index = 0;
		cout << "\nChoose ID: ";
		cin >> index;
		if (index >= clientCounter or index < 0)
		{
			cout << "\nError...\n";
			_getch();
			goto editClientStart;
		}
		system("CLS");

		struct CLIENT temp;
		temp = client[index];

		cout << "===========| Edit Client Menu |===========\n";

		for (int i = 0; i < clientCounter; i++)
		{
			if (i == index)
			{
			cout << "\nID:" << index;
			cout << "\nName: " << client[i].name.first << " " << client[i].name.middle << " " << client[i].name.last;
			cout << "\nAge: " << client[i].age;
			cout << "\nEGN: " << client[i].egn;
			cout << "\nMarried: " << client[i].married;
			cout << "\nBoard pass\n";
			cout << "Flight Num: " << client[i].bp.flightNum;
			cout << "\nTaken Seats: " << client[i].bp.takenSeats;
			cout << "\n\n";
			}
		}

		cout << "\nEsc. Back to the Main Menu...\n";

		cout << "\n/--- Edit Personal Information ---\\\n";
		cout << "\n1.Edit Name...\n";
		cout << "2.Edit age...\n";
		cout << "3.Edit EGN...\n";
		cout << "4.Edit Married Status...\n";

		cout << "\n/--- Edit Board Pass ---\\\n";
		cout << "5.Edit flight num...\n";
		cout << "6.Edit taken seats...\n\n";


		switch (_getch()) //second menu
		{
		case 27: //Esc -> back to the Main Menu
			break;
		case 49: //1 -> edit name
			cout << "Old name: " << client[index].name.first << " " << client[index].name.middle << " " << client[index].name.last << "\n";
			cout << "New name: ";
			cin >> temp.name.first;
			cin >> temp.name.middle;
			cin >> temp.name.last;
			break;
		case 50: //2 -> edit age
			cout << "Old age: " << client[index].age << "\n";
			cout << "New age: ";
			cin >> temp.age;
			break;
		case 51: //3 -> edit EGN 
			cout << "Old EGN: " << client[index].egn << "\n";
			cout << "New EGN: ";
			cin >> temp.egn;
			break;
		case 52: //4 -> edit married
			cout << "Old Married: " << client[index].married << "\n";
			cout << "New Married: ";
			cin >> client[index].married;
			checkMarried(client, index);
			break;
		case 53: //5 -> edit flight num
			cout << "Old flight number: " << client[index].bp.flightNum << "\n";
			cout << "New flight number: ";
			cin >> client[index].bp.flightNum;
			checkFlightNumClient(client, clientCounter);
			break;
		case 54: //6 -> edit taken seats
			cout << "Old taken seats: " << client[index].bp.takenSeats << "\n";
			cout << "New taken seats: ";
			cin >> temp.bp.takenSeats;
			break;
		}

		cout << "\nDo you want to save the changes made?...\n";
		cout << "1.Save changes\n";
		cout << "2.Don't save changes\n";
		int dec;
		cin >> dec;
		switch (dec) // save or cancel the new name
		{
		case 1: //1 -> save new

			temp.bp.oldSeats = client[index].bp.takenSeats;
			temp.married = client[index].married;
			swap(temp.bp.flightNum, client[index].bp.flightNum);

			client[index] = temp;
			
			/*
			client[index].name.first = temp.name.first; //change old name with new name
			client[index].name.middle = temp.name.middle;
			client[index].name.last = temp.name.last;

			client[index].age = temp.age; //change old age with new age
			swap(client[index].egn, temp.egn); //change old EGN with new EGN
			swap(client[index].bp.flightNum, temp.bp.flightNum); //change old flight num with new flight num
			client[index].bp.takenSeats = temp.bp.takenSeats; //change old taken seats with new taken seats
			*/

			cout << "\nChanges have been saved.\n";
			_getch();
			break;
		case 2: //2 -> Cancel the new
			cout << "\nChanges are discarded.\n";
			client[index].married = temp.married;
			swap(temp.bp.flightNum, client[index].bp.flightNum);
			_getch();
			break;
		}

		cout << "\nClient Info:";
		cout << "\nid:" << index; //couting all information of client
		cout << "\nName: " << client[index].name.first << " " << client[index].name.middle << " " << client[index].name.last;
		cout << "\nAge: " << client[index].age;
		cout << "\nEGN: " << client[index].egn;
		cout << "\nMarried: " << client[index].married;
		cout << "\nBoard pass\n";
		cout << "Flight Num: " << client[index].bp.flightNum;
		cout << "\nTaken Seats: " << client[index].bp.takenSeats << "\n";
		cout << "\n";
		_getch();
		
		return index;
	}

}

void checkMonth(FLIGHT flight[], int i) //Checks if the month is possible
{
	if (flight[i].dateOfTakeOff.month < 0 or flight[i].dateOfTakeOff.month > 12)
	{
		cout << "\tMonth not possible... Enter a new Month: "; cin >> flight[i].dateOfTakeOff.month;
		checkMonth(flight, i);
	}
}

void checkDay(FLIGHT flight[], int i) //Checks if the day is possible
{
	int maxDays;
	switch (flight[i].dateOfTakeOff.month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		maxDays = 31;
		break;
	case 2:
		maxDays = 28;
	default:
		maxDays = 30;
		break;
	}

	if (flight[i].dateOfTakeOff.day < 0 or flight[i].dateOfTakeOff.day > maxDays)
	{
		cout << "\tDay not possible... Enter a new day: "; cin >> flight[i].dateOfTakeOff.day;
		checkDay(flight, i);
	}

}

void registerFlight(FLIGHT flight[], int& flightCounter)
{
	system("CLS");

	cout << "Flight Number(6 symbols): "; cin >> flight[flightCounter].flightNum;
	checkFlightNum(flight, flightCounter);
	cout << "Country/City of origin: "; cin >> flight[flightCounter].origin;
	cout << "Destination: "; cin >> flight[flightCounter].destination;
	cout << "Travel Distance(km): "; cin >> flight[flightCounter].distanceToDestination;
	cout << "Take off date(26 8): "; cin >> flight[flightCounter].dateOfTakeOff.day >> flight[flightCounter].dateOfTakeOff.month;
	checkMonth(flight, flightCounter);
	checkDay(flight, flightCounter);
	cout << "Plane: ";
	cout << "\n-  -Manufacturer: "; cin >> flight[flightCounter].plane.manufacturer;
	cout << "-  -Model name: "; cin >> flight[flightCounter].plane.modelName;
	cout << "-  -Max seats: "; cin >> flight[flightCounter].plane.maxSeats;
	flight[flightCounter].plane.oldMaxSeats = 0;
	flight[flightCounter].emptySeats = flight[flightCounter].plane.maxSeats;
	flightCounter++;
}

void informationFlight(FLIGHT flight[], int& flightCounter)
{
	system("CLS");
	if (flightCounter == 0)
	{
		cout << "No Flights present in the system...";
		_getch();
	}
	else {
		for (int i = 0; i < flightCounter; i++)
		{
			cout << "ID:" << i;
			cout << "\nFlight Number(6 symbols): " << flight[i].flightNum;
			cout << "\nCountry/City of origin: " << flight[i].origin;
			cout << "\nDestination: " << flight[i].destination;
			cout << "\nTravel Distance(km): " << flight[i].distanceToDestination;
			cout << "\nTake off date(day.month): ";
			if (flight[i].dateOfTakeOff.day < 10) cout << "0";
			cout << flight[i].dateOfTakeOff.day << "."; 
			if (flight[i].dateOfTakeOff.month < 10) cout << "0"; 
			cout << flight[i].dateOfTakeOff.month;
			cout << "\nPlane: ";
			cout << "\n-  -Manufacturer: " << flight[i].plane.manufacturer;
			cout << "\n-  -Model name: " << flight[i].plane.modelName;
			cout << "\n-  -Max seats: " << flight[i].plane.maxSeats;
			if (flight[i].overbooked) cout << "\nNo empty seats-\tOverbooked!";
			else cout << "\nEmpty seats: " << flight[i].emptySeats;
			cout << "\n\n";

		}
		_getch();
	}
}

void removeFlight(FLIGHT flight[], int& flightCounter) //Remove Flight Function
{
	informationFlight(flight, flightCounter);
removeStart:
	system("CLS");
	int index;
	cout << "Choose id: ";
	cin >> index;
	if (index > flightCounter or index < 0) //checking index in range of flight counter 
	{
		cout << "Error...\n";
		goto removeStart;
	}
	else
	{
		cout << "\nFlight Number: " << flight[index].flightNum;
		cout << "\nCity/Country of origin: " << flight[index].origin;
		cout << "\nDestination City/Country: " << flight[index].destination;
		cout << "\nDistance to destination: " << flight[index].distanceToDestination;
		cout << "\nTake off date(day.month): " << flight[index].dateOfTakeOff.day << "."; if (flight[index].dateOfTakeOff.month < 10) cout << "0"; cout << flight[index].dateOfTakeOff.month;
		cout << "\nPlane: ";
		cout << "\n-  -Manufacturer: " << flight[index].plane.manufacturer;
		cout << "\n-  -Model name: " << flight[index].plane.modelName;
		cout << "\n-  -Max Seats: " << flight[index].plane.maxSeats;
		if (flight[index].overbooked) cout << "\nNo empty seats-\tOverbooked!";
		else cout << "\nEmpty seats: " << flight[index].emptySeats;


		for (int i = index; i < flightCounter - 1; i++) //delete index register flight
		{
			flight[i] = flight[i + 1];
		}
		flightCounter--;

	}
	_getch();
}

int editFlight(FLIGHT flight[], int& flightCounter)
{
	system("CLS");
	if (flightCounter == 0)
	{
		cout << "No Flights present in the system...";
		_getch();
		return -1;
	}
	else
	{
	editFlightStart:
		informationFlight(flight, flightCounter);

		int index;
		cout << "\nChoose ID: ";
		cin >> index;
		system("CLS");
		if (index >= flightCounter or index < 0)
		{
			cout << "\nError...\n";
			_getch();
			goto editFlightStart;
		}

		struct FLIGHT temp;
		temp = flight[index];
		
		cout << "===========| Edit Flight Menu |===========\n";

		for (int i = 0; i < flightCounter; i++)
		{
			if (i == index)
			{
				cout << "\nID:" << index;
				cout << "\nFlight Number(6 symbols): " << flight[i].flightNum;
				cout << "\nCountry/City of origin: " << flight[i].origin;
				cout << "\nDestination: " << flight[i].destination;
				cout << "\nTravel Distance(km): " << flight[i].distanceToDestination;
				cout << "\nTake off date(day.month): ";
				if (flight[i].dateOfTakeOff.day < 10) cout << "0";
				cout << flight[i].dateOfTakeOff.day << ".";
				if (flight[i].dateOfTakeOff.month < 10) cout << "0";
				cout << flight[i].dateOfTakeOff.month;
				cout << "\nPlane: ";
				cout << "\n-  -Manufacturer: " << flight[i].plane.manufacturer;
				cout << "\n-  -Model name: " << flight[i].plane.modelName;
				cout << "\n-  -Max seats: " << flight[i].plane.maxSeats;
				if (flight[i].overbooked) cout << "\nNo empty seats-\tOverbooked!";
				else cout << "\nEmpty seats: " << flight[i].emptySeats;
				cout << "\n\n";
			}
		}

		cout << "\nEsc. Back to the Main Menu...\n";

		cout << "\n/--- Edit Flight ---\\\n";
		cout << "1.Edit flight number...\n";
		cout << "2.Edit origin...\n";
		cout << "3.Edit destination...\n";
		cout << "4.Edit distance to destination...\n";

		cout << "\n/--- Edit Plane ---\\\n";
		cout << "5.Edit manufacturer...\n";
		cout << "6.Edit model name...\n";
		cout << "7.Edit max seats...\n";

		cout << "\n/--- Edit Take Off Date ---\\\n";
		cout << "8.Edit date...\n";

		switch (_getch()) //second menu
		{
		case 27: //Esc -> back to the Main Menu
			break;
		case 49: //1 -> edit flight num
			cout << "Old flight number: " << flight[index].flightNum;
			cout << "\nNew flight number: ";
			cin >> flight[index].flightNum;
			checkFlightNum(flight, flightCounter);
			break;
		case 50: //2 -> edit origin
			cout << "Old origin: " << flight[index].origin;
			cout << "\nNew origin: ";
			cin >> temp.origin;
			break;
		case 51: //3 -> edit destination
			cout << "Old destination: " << flight[index].destination;
			cout << "\nNew destination: ";
			cin >> temp.destination;
			break;
		case 52: //4 -> edit distance
			cout << "Old distance: " << flight[index].distanceToDestination;
			cout << "\nNew distance: ";
			cin >> temp.distanceToDestination;
			break;
		case 53: //5 -> edit manufacturer
			cout << "Old manufacturer: " << flight[index].plane.manufacturer;
			cout << "\nNew manufacturer: ";
			cin >> temp.plane.manufacturer;
			break;
		case 54: //6 -> edit model name
			cout << "Old model name: " << flight[index].plane.modelName;
			cout << "\nNew model name: ";
			cin >> temp.plane.modelName;
			break;
		case 55: //7 -> edit max seats
			cout << "Old max seats: " << flight[index].plane.maxSeats;
			cout << "\nNew max seats: ";
			cin >> temp.plane.maxSeats;
			break;
		case 56: //8 -> edit date
			cout << "\nOld take off date(day.month): " << flight[index].dateOfTakeOff.day << "."; if (flight[index].dateOfTakeOff.month < 10) cout << "0"; cout << flight[index].dateOfTakeOff.month;
			cout << "New take off date(26 8): "; cin >> flight[index].dateOfTakeOff.day >> flight[index].dateOfTakeOff.month;
			checkMonth(flight, index);
			checkDay(flight, index);
			break;
		}

		cout << "\nDo you want to save the changes made?...\n";
		cout << "1.Save changes\n";
		cout << "2.Don't save changes\n";
		int dec;
		cin >> dec;
		switch (dec) // save or cancel the new
		{
		case 1: //1 -> save new


			cout << "\nChanges have been saved.\n";
			temp.plane.oldMaxSeats = flight[index].plane.maxSeats;
			flight[index] = temp;
			for (int i = 0; i < 6; i++)
			{
				temp.flightNum[i] = flight[index].flightNum[i];
			}
			temp.dateOfTakeOff.day = flight[index].dateOfTakeOff.day;
			temp.dateOfTakeOff.month = flight[index].dateOfTakeOff.month;
			_getch();
			break;
		case 2: //2 -> Cancel the new
			cout << "\nChanges are discarded.\n";
			for (int i = 0; i < 6; i++)
			{
				flight[index].flightNum[i] = temp.flightNum[i];
			}
			flight[index].dateOfTakeOff.day = temp.dateOfTakeOff.day;
			flight[index].dateOfTakeOff.month = temp.dateOfTakeOff.month;
			_getch();
			break;
		}

		if (temp.emptySeats < 0)
			temp.overbooked = true;
		else
			temp.overbooked = false;

		cout << "Flight Number(6 symbols): " << temp.flightNum;
		cout << "\nCountry/City of origin: " << temp.origin;
		cout << "\nDestination: " << temp.destination;
		cout << "\nTravel Distance(km): " << temp.distanceToDestination;
		cout << "\nTake off date(day.month): " << temp.dateOfTakeOff.day << "."; if (temp.dateOfTakeOff.month < 10) cout << "0"; cout << temp.dateOfTakeOff.month;
		cout << "\nPlane: ";
		cout << "\n-  -Manufacturer: " << temp.plane.manufacturer;
		cout << "\n-  -Model name: " << temp.plane.modelName;
		cout << "\n-  -Max seats: " << temp.plane.maxSeats;
		cout << "\nEmpty seats: " << temp.emptySeats;
		cout << "\n\n";
		_getch();
		return index;
	}
}

void connectFlightClient(FLIGHT flight[], int flightCounter, CLIENT client[], int clientCounter)
{
	for (int i = 0; i < flightCounter; i++)
	{
		for (int j = 0; j < clientCounter; j++)
		{
			if (client[j].bp.checkedIn == false)
			{
				bool check = true;
				for (int k = 0; k < 6; k++)
				{
					if (int(client[j].bp.flightNum[k]) != int(flight[i].flightNum[k]))
					{
						check = false;
					}
				}
				if (check == true)
				{
					flight[i].passengersTickets[flight[i].passengers] = client[j].bp.ticketNum;
					flight[i].passengers++;
					client[j].bp.checkedIn = true;
				}
			}
			else
			{
				continue;
			}
		}
	}
}

void informationPassenger(FLIGHT flight[], int flightCounter, CLIENT client[], int clientCounter)
{
	system("CLS");
	for (int i = 0; i < flightCounter; i++)
	{
		if (flight[i].passengers == 0)
		{
			continue;
		}
		cout << "ID:" << i;
		cout << "\nFlight Number(6 symbols): " << flight[i].flightNum;
		cout << "\nCountry/City of origin: " << flight[i].origin;
		cout << "\nDestination: " << flight[i].destination;
		cout << "\nTravel Distance(km): " << flight[i].distanceToDestination;
		cout << "\nTake off date(day.month): ";
		if (flight[i].dateOfTakeOff.day < 10) cout << "0";
		cout << flight[i].dateOfTakeOff.day << ".";
		if (flight[i].dateOfTakeOff.month < 10) cout << "0";
		cout << flight[i].dateOfTakeOff.month;
		cout << "\nPlane: ";
		cout << "\n-  -Manufacturer: " << flight[i].plane.manufacturer;
		cout << "\n-  -Model name: " << flight[i].plane.modelName;
		cout << "\n-  -Max seats: " << flight[i].plane.maxSeats;
		if (flight[i].emptySeats < 0) cout << "\nNo empty seats-\tOverbooked!";
		else cout << "\nEmpty seats: " << flight[i].emptySeats;
		cout << "\n\n";
		cout << "\nPassengers: ";

		for (int j = 0; j < clientCounter; j++)
		{
			for (int k = 0; k < flight[i].passengers; k++)
			{
				if (client[j].bp.ticketNum == flight[i].passengersTickets[k])
				{
					cout << "\nName: " << client[j].name.first << " " << client[j].name.middle << " " << client[j].name.last;
					cout << "\nAge: " << client[j].age;
					cout << "\nEGN: " << client[j].egn;
					cout << "\nMarried: " << client[i].married;
					cout << "\nBoard pass\n";
					cout << "Flight Num: " << client[j].bp.flightNum;
					cout << "\nTaken Seats: " << client[j].bp.takenSeats;
					cout << "\n\n";
				}
			}
		}
	}
	_getch();
}

void checkFlightNum(FLIGHT flight[], int flightCounter)
{
	checkFlightNumFlight(flight, flightCounter);

	for (int i = 0; i < flightCounter; i++)
	{

		bool check = true;
		for (int k = 0; k < 6; k++)
		{
			if (int(flight[flightCounter].flightNum[k]) != int(flight[i].flightNum[k]))
			{
				check = false;
			}
		}
		if (check == true)
		{
			cout << "\nFlight Number Taken...\tTry another number: ";
			cin >> flight[flightCounter].flightNum;
			cout << "\n";
			checkFlightNum(flight, flightCounter);
		}
		else
		{
			break;
		}

	}
}

void checkMarried(CLIENT client[], int clientCounter)
{
	if (client[clientCounter].married == "yes" or client[clientCounter].married == "Yes" or client[clientCounter].married == "no" or client[clientCounter].married == "No")
	{}
	else
	{
		cout << "\nInput not possible...\tMarried: ";
		cin >> client[clientCounter].married;
		checkMarried(client, clientCounter);
	}

}

void checkFlightNumFlight(FLIGHT flight[], int flightCounter)
{
	if (strlen(flight[flightCounter].flightNum) < 6 or strlen(flight[flightCounter].flightNum) > 6)
	{
		cout << "\nInput not possible...\tFlight Num(6-symbols): ";
		cin >> flight[flightCounter].flightNum;
		checkFlightNumFlight(flight, flightCounter);
	}
}

void checkFlightNumClient(CLIENT client[], int clientCounter)
{
	if (strlen(client[clientCounter].bp.flightNum) < 6 or strlen(client[clientCounter].bp.flightNum) > 6)
	{
		cout << "\nInput not possible...\tFlight Num(6-symbols): ";
		cin >> client[clientCounter].bp.flightNum;
		checkFlightNumClient(client, clientCounter);
	}
}

void checkSeats(FLIGHT flight[], int flightCounter, CLIENT client[], int clientCounter,int& editIndex)
{
	if (editIndex >= 0)
	{
		int fId = -1;
		for (int i = 0; i < flightCounter; i++)
		{
			if (flight[i].passengers == 0)
			{
				continue;
			}

			bool check = true;
			for (int j = 0; j < 6; j++)
			{
				if (int(client[editIndex].bp.flightNum[j]) != int(flight[i].flightNum[j]))
				{
					check = false;
				}
			}
			if (check == true)
			{
				fId = i;
				break;
			}
		}

		if (fId >= 0)
		{
			flight[fId].emptySeats += client[editIndex].bp.oldSeats;
			flight[fId].emptySeats -= client[editIndex].bp.takenSeats;
		}
		
		checkOverbooked(flight, flightCounter, fId);
	}
}

void checkOverbooked(FLIGHT flight[], int flightCounter, int fId)
{
	if (flight[fId].emptySeats < 0)
	{
		flight[fId].overbooked = true;
	}
	else
	{
		flight[fId].overbooked = false;
	}
}

void checkEmptySeatsAfterMaxChange(FLIGHT flight[], int fId)
{
	if (fId >= 0)
	{
		flight[fId].emptySeats += (flight[fId].plane.maxSeats - flight[fId].plane.oldMaxSeats);
	}
}
