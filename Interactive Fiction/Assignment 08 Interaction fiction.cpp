// Interactive Fiction.cpp : Defines the entry point for the console application.
//Brant Wagner
//Create a new console project.
//Add a function called GetTextFromUser that takes a string as the prompt you wish to display to the user and returns a string.
//Add a function named GetNumbersFromUser that takes a string as the prompt you wish to display to the user and returns an integer.
//Add any more functions that you may need.
//Your main function should control all the other functions.
//Comment your source code file(.CPP) well.
//Once the program is working have tested it a few times, create a new repository in your GitHub account for your program.
//Add your solution and files to your new Repository on GitHub.
//Take a screenshot of this project in GitHub.
//Take a screenshot of the program working.


#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <time.h>
//Namespace
using namespace std;
string GetTextFromUser(string prompt);
int GetNumbersFromUser(string prompt);
void OutputStory(string name, string food, string weapon, string limb, int luckyNumber, int randomNumber);
bool CheckVictory(int luckyNumber, int randomNumber);
//main function

void main()
{
	cout << "\tAHOY  MATEY!!\n";
	srand(static_cast<unsigned int>(time(0))); // seeds random number 
	int randomNumber = rand() % 100 + 1; //random number between 1 and 100 into variable
	string name = GetTextFromUser("Ahoy Laddy, what be ye name? \n"); // GetTextFromUser into a varia
	string weapon = GetTextFromUser("Do ye prefer a hand cannon or a cutlass? \n"); // Stores the return of GetTextFromUser into a variable
	string limb = GetTextFromUser("Which of ye legs have a peg \n"); // Stores the return of GetTextFromUser into a variable
	string food = GetTextFromUser("What is ya favorite fruit? \n"); // GetTextFromUser into a variable
	int luckyNumber = GetNumbersFromUser("What is the number of ships ye have been on? \n"); // Stores the return of GetNumbersFromUser into a variable
	OutputStory(name, food, weapon, limb, luckyNumber, randomNumber); // Calls the OutputStory function and sends all your variables into it as parameters
	system("pause"); // pause system when program finishes all tasks
}

string GetTextFromUser(string prompt) //  GetTextFromUser function
{
	string text; //  store the user input
	cout << prompt; // output prompt
	cin >> text; // get input from user 
	return text; // Return the variable
}

int GetNumbersFromUser(string prompt) 
{
	int num;
	cout << prompt;
	cin >> num;
	return num; // Return the variable
}
void OutputStory(string name, string food, string weapon, string limb, int luckyNumber, int randomNumber) // This is the body of OutputStory, it takes all the main function variables as parameters
{
	// =story
	cout << "Your out on the high seas\n";
	cout << "Out in the distance, a British ship approaches\n";
	cout << "OY " << name << " Man your station, we goin to have to fight off the British\n";
	cout << "You go to your station, load the cannon and prepare to fight.\n";
	cout << "You ready your " << weapon << " while the British ship gets closer.\n";
	cout << "The British ship fires its cannons at you!\n";
	

	if (CheckVictory(luckyNumber, randomNumber) == true) // Canon miss
	{
		//Story below
		cout << "The cannon balls fall short, but the impact makes you drop your " << weapon;
		cout << "Your ship fires their cannons, blowing massive holes in the british ship.\n";
		cout << "You see people on the British boat abondoning ship as it goes under. \n Victory is yours! Congradulations!\n";
		cout << "Captain: Good job ye scallywags, but it isnt over ye. Grab you some " << food << "and we continue on.";
	}
	else // if the checkvictory return was anything but true do the below
	{
		//Story below
		cout << "The cannon balls hit your ship directly, holes explode all around you\nYou are hit with chunks of debris...\n\n Your peg leg on your " << limb <<" is missing";
		cout << "You hear the word for abandon ship as water fills up around you...\n";
		cout << "\tGAME OVER...\n";
	}
}

bool CheckVictory(int luckyNumber, int randomNumber) 
{
	if (luckyNumber >= randomNumber) 
	{
		return true;
	}
	else
	{
		return false;
	}
}
