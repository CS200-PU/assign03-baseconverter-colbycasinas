//******************************************************************************
// File name:   main.cpp
// Author:      Colby Casinas
// Date:        09/13/2024
// Class:       CS200
// Assignment:  BaseConverter
// Purpose:     Create a program that automatically converts a number in a 
//              specified base to equivalent numbers in the other two bases
// Hours:       2.00
//******************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;
const int NUM_SYMBOLS1 = 38, NUM_SYMBOLS2 = 5;
const string TITLE = "HEX-DECIMAL-BINARY CONVERTER";
const char SYMBOL = '*';

int hexChartoInt (char hexDigit);
char getBase (const string& strNumber);
string getNumber (const string& prompt);
void printTitle (const string& myTitle, char symbol);
string binaryToDecimal (const string& strNumber);
string decimalToBinary (const string& strNumber);
string decimalToHex (const string& strNumber);
string hexToDecimal (const string& strNumber);
string hexToBinary (const string& strNumber);
string binaryToHex (const string& strNumber);

int main () {

  printTitle (TITLE, SYMBOL);
  
  return EXIT_SUCCESS;
}

int hexChartoInt (char hexDigit) {

}

char getBase (const string& strNumber) {

}

string getNumber (const string& prompt) {

}

void printTitle (const string& myTitle, char symbol) {
  cout << setfill (symbol) << setw (NUM_SYMBOLS1) << symbol << endl 
       << setfill (symbol) << setw (NUM_SYMBOLS2) << symbol << myTitle 
       << setfill (symbol) << setw (NUM_SYMBOLS2) << symbol << endl
       << setfill (symbol) << setw (NUM_SYMBOLS1) << symbol << endl;
}

string binaryToDecimal (const string& strNumber) {

}

string decimalToBinary (const string& strNumber) {

}

string decimalToHex (const string& strNumber) {

} 

string hexToDecimal (const string& strNumber) {

}

string hexToBinary (const string& strNumber) {

}

string binaryToHex (const string& strNumber) {

}