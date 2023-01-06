/*
	This program is currently set up to convert a currency amount in USD to its corresponding amount in a target currency the user chooses.
*/
#include <iostream>	//for standard I/O
#include <fstream>	//for file I/O
#include <iomanip>	//for output format left, fixed, setprecision, setw
using namespace std;

int main() {
  double us_dollars;
  string target_currency;
  
  cout << "How much US Dollars would you like to exchange? ";
  cin >> us_dollars;
  
  cout << "What is the ABBREVIATION of the currency of your choice?\n";
  cout << "For example\n";
  cout << "\tBRL\t\tBrazilian Real\n";
  cout << "\tEUR\t\tEuro\n";
  cout << "\tMXN\t\tMexican Peso\n";
  cout << "Use ALL UPPERCASE:\t";
  cin >> target_currency;

	ifstream input("rates.txt");	//to process file input
  if (!input.is_open()) {
    cout << "Can't open the rates.txt file" << endl;
    return 1; //exit the program when the file is not ready for access
  }

  string currency_type;	//read from the input file
  double exchange_rate;	//read from the input file

  /*
    The following shows a common programming pattern to search for something in a file. Note the condition for the while loop is for the loop to continue. That is, repeat the loop body while the end of file has not been reached AND a match has not been found.
  */
  bool matched = false;	//no match is found before looking into the file
  while (!input.eof() && !matched) {
        input >> currency_type >> exchange_rate; 
    if (currency_type == target_currency) 
      matched = true;
  }	//end of while

  if (matched) {
    /*
      This named constant helps explain purpose of a number. It also reduces places to be changed if we like 20 instead of 15 as the width.
    */
    const int WIDTH = 15;
    cout << left << fixed << setprecision(2);
    cout << setw(WIDTH) << "US Dollars" << target_currency << endl;
    cout << setw(WIDTH) << us_dollars << us_dollars * exchange_rate << endl;

	} else
		cout << "Sorry, no matching currency is found." << endl;

	input.close();	//close the input stream

	return 0;	//signal normal exit of the program
}