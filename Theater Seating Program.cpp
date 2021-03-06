// Theater Seating Program.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

class TheaterSeats {

private:
	string seats[10][10];
	int rowPrices[10];
	int numOfSeatsLeft = 100;
	int numOfSeatsSold = 0;

public:
	TheaterSeats();
	~TheaterSeats();

	void AssignSeats();
	void CancelSeats();
	void DisplayAllSeats();
	void DisplayRowPrices();

	void setSeatsLeft(int x);
	int getSeatsLeft();
	void setSeatsSold(int x);
	int getSeatsSold();


};

int main()
{
	TheaterSeats TheaterSeats;
	int number; //create a number to hold the number from the keybord
	int again = 1;

	TheaterSeats.DisplayAllSeats();
	cout << endl;

Tryagain:

	//Get information from the user to perform task
	//First display the options to choose from or the menu.
	std::cout << "Please, choose the option that you want to perform: " << endl;
	std::cout << "1- See the prices of the seats per row." << endl;
	std::cout << "2- Purchase seats." << endl;
	std::cout << "3- View all the seats." << endl;
	std::cout << "4- Cancel an order already placed." << endl;
	std::cout << "5- View the seats that are unavailable." << endl;
	std::cout << "6- View the seats that are still available." << endl;
	std::cout << "7- Exit" << endl;

	std::cin >> number;     //Getting the choice of the user via keybord.

	switch (number)   //Setting up a switch statement according to the menu.
	{
	case 1:
		TheaterSeats.DisplayRowPrices();  //The first case just displays the row prices
		break;

	case 2:                //This case has to set seats and update the system
		
			TheaterSeats.AssignSeats(); //Assigning the seat if it is only one.
			
		break;
	case 3:
		TheaterSeats.DisplayAllSeats(); //This case just displays all the seats; including the sold and the left
		break;
	case 4:             //This case cancels seats, and updates the system accordingly.
		
			TheaterSeats.CancelSeats(); //Cancelling a seat when it is only one.
			
		break;

	case 5:
		cout << "There have been " << TheaterSeats.getSeatsSold() << " sold" << endl;   //This case just displays the seats that are unavailable
		break;

	case 6:
		cout << "There are " << TheaterSeats.getSeatsLeft() << " available" << endl;   //This case just displays the seats that are available.
		break;
	case 7:
		again = 0;
		break;
	default:
		std::cout << "That option is out of range." << endl; //In case the entry is not within the range
		goto Tryagain;      //we send the user back to the menu.
	}

	if (again) {
		goto Tryagain;
	}
	

	return 0;
}

TheaterSeats::TheaterSeats() {

	//Set all row pricing 
	rowPrices[0] = 100;
	rowPrices[1] = 100;
	rowPrices[2] = 100;
	rowPrices[3] = 75;
	rowPrices[4] = 75;
	rowPrices[5] = 75;
	rowPrices[6] = 50;
	rowPrices[7] = 50;
	rowPrices[8] = 25;
	rowPrices[9] = 25;

	//Set all seats to available denoted with "#"
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			seats[i][j] = "#";
		}
	}

}

TheaterSeats::~TheaterSeats() {

}

void TheaterSeats::AssignSeats() {

	int row, column;
	int again = 0;
	int answ = 0;
	int x, y;

	while (true) {
		if (again) {
			cout << "Would you like to purchase another seat? (1 = YES, 2 = NO): ";
			cin >> answ;

			if (answ == 2) {
				break;
			}
		}
		cout << "Please Enter Row: ";
		cin >> row;
		row -= 1;
		cout << "Please Enter Column: ";
		cin >> column;
		column -= 1;
		while (true) {
			if (seats[row][column].compare("#") == 0) {
				seats[row][column] = "*";
				cout << "Seat has been purchased\n";
				x = getSeatsLeft() - 1;
				setSeatsLeft(x);
				y = getSeatsSold() + 1;
				setSeatsSold(y);
				break;
			}
			else {
				cout << "A ticket for this seat already exist,\nPlease enter a different row: ";
				cin >> row;
				row -= 1;
				cout << "Please Enter Column: ";
				cin >> column;
				column -= 1;
			}
		}
		

		again = 1;

	}

}

void TheaterSeats::CancelSeats() {

	int row, column; 
	int again = 0;
	int answ = 0;
	int x, y;

	while (true) {
		if (again) {
			cout << "Would you like to cancel another seat? (1 = YES, 2 = NO): ";
			cin >> answ;

			if (answ == 2) {
				break;
			}
		}

		cout << "Please Enter Row: ";
		cin >> row;
		row -= 1;
		cout << "Please Enter Column: ";
		cin >> column;
		column -= 1;

		while (true) {
			//if seat is taken
			if (seats[row][column].compare("*") == 0) {
				seats[row][column] = "#";
				cout << "Seat has been canceled\n";
				x = getSeatsLeft() + 1;
				setSeatsLeft(x);
				y = getSeatsSold() - 1;
				setSeatsSold(y);
				break;
			}
			else {
				cout << "A ticket for this seat does not exist,\nPlease enter a different row: ";
				cin >> row;
				row -= 1;
				cout << "Please Enter Column: ";
				cin >> column;
				column -= 1;
			}
		}
		

		again = 1;

	} 

}

void TheaterSeats::DisplayAllSeats() {

	//Display column numbers 
	cout << "     1    2    3    4    5    6    7    8    9   10";

	for (int i = 0; i < 10; i++) {

		//display row number
		if (i != 9) {
			cout << endl << " " << i + 1;
		}
		else {
			cout << endl << i + 1;
		}

		for (int j = 0; j < 10; j++) {

			cout << "  |" << seats[i][j] << "|";

		}
	}

	cout << endl;
}

void TheaterSeats::DisplayRowPrices() {

	cout << endl << "Row prices from front to back: ";

	for (int i = 0; i < 10; i++)
	{
		cout << endl << "Row " << i + 1 << ": " << rowPrices[i];
	}
	cout << endl;
}

int TheaterSeats::getSeatsLeft()
{
	return numOfSeatsLeft;
}

int TheaterSeats::getSeatsSold()
{
	return numOfSeatsSold;
}

//Setter for number of seats left.
void TheaterSeats::setSeatsLeft(int x) {

	numOfSeatsLeft = x;

}

//Setter for the number of seats sold.
void TheaterSeats::setSeatsSold(int x) {

	numOfSeatsSold = x;

}

