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
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

const int NUM_SYMBOLS1 = 38, NUM_SYMBOLS2 = 5;

const string TITLE = "HEX-DECIMAL-BINARY CONVERTER", 
             USER_PROMPT = "Enter your string to convert (q to quit): ",
             BINARY = "The binary conversion is: ",
             HEX = "The hexadecimal conversion is: ",
             DECIMAL = "The decimal conversion is: ";

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
  
  char base;
  string userChoice, newValue;

  printTitle (TITLE, SYMBOL);
  userChoice = getNumber (USER_PROMPT);

  while (userChoice != "q") {
    base = getBase (userChoice);
    if (base == 'd' || base == 'D') {
      newValue = decimalToBinary(userChoice);
      cout << BINARY << newValue << endl;
      newValue = decimalToHex (userChoice);
      cout << HEX << newValue << endl;
    } else if (base == 'b' || base == 'B') {
      newValue = binaryToDecimal(userChoice);
      cout << DECIMAL << newValue << endl;
      newValue = binaryToHex(userChoice);
      cout << HEX << newValue << endl;
    } else if (base == 'h' || base == 'H') {
      newValue = hexToDecimal(userChoice);
      cout << DECIMAL << newValue << endl;
      newValue = hexToBinary(userChoice);
      cout << BINARY << newValue << endl;
    }
    userChoice = getNumber (USER_PROMPT);
  }
  
  return EXIT_SUCCESS;
}

int hexChartoInt (char hexDigit) {
  const int A = 10, B = 11, C = 12, D = 13, E = 14, F = 15;
  int newVal;

  switch (hexDigit) {
      case 65: 
          newVal = A;
          break;
      case 66:
          newVal = B;
          break;
      case 67:
          newVal = C;
          break;
      case 68:
          newVal = D;
          break;
      case 69:
          newVal = E;
          break;
      case 70:
          newVal = F;
          break;
      default:
          newVal = hexDigit;
          break;
  }

  return newVal;
}

char getBase (const string& strNumber) {
  char userBase;

  if (strNumber[1] == 'b') {
    userBase = 'B';
  } else if (strNumber[1] == 'x') {
    userBase = 'H';
  } else {
    userBase = 'D';
  }

  return userBase;
}

string getNumber (const string& prompt) {
  string userNum;

  cout << prompt;
  cin >> userNum;

  return userNum;
}

void printTitle (const string& myTitle, char symbol) {
  cout << setfill (symbol) << setw (NUM_SYMBOLS1) << symbol << endl 
       << setfill (symbol) << setw (NUM_SYMBOLS2) << symbol << myTitle 
       << setfill (symbol) << setw (NUM_SYMBOLS2) << symbol << endl
       << setfill (symbol) << setw (NUM_SYMBOLS1) << symbol << endl;
}

string binaryToDecimal (const string& strNumber) {
  int sum = 0, base = 2, exponent = 0, counter = strNumber.length();
    while (counter >= 0) {
      if (strNumber[counter] == '1') {
        sum += pow(base, exponent);
      }
      exponent++;
      counter--;
    }
  return to_string(sum);
}

string decimalToBinary (const string& strNumber) {
  int newBinary = stoi(strNumber);
  string binaryValue;

  if (newBinary == 0) {
    binaryValue = "0";
  }
  while (newBinary > 0) {
    binaryValue += to_string(newBinary % 2);
    newBinary = newBinary / 2;
  }
  reverse (binaryValue.begin(), binaryValue.end());

  return "0b" + binaryValue;
}

string decimalToHex (const string& strNumber) {
  int hexValue = stoi(strNumber), change;
  string hexString;
  char hexChar;

  if (hexValue == 0) {
    hexString = "0";
  }

  while (hexValue > 0) {
    change = hexValue % 16;

    switch (change) {
      case 10:
        hexChar = 'A';
        hexString += hexChar;
        break;
      case 11:
        hexChar = 'B';
        hexString += hexChar;
        break;
      case 12:
        hexChar = 'C';
        hexString += hexChar;
        break;
      case 13:
        hexChar = 'D';
        hexString += hexChar;
        break;
      case 14:
        hexChar = 'E';
        hexString += hexChar;
        break;
      case 15:
        hexChar = 'F';
        hexString += hexChar;
        break;
      default: 
        hexString = to_string (change);
    }
    hexValue = hexValue / 16;
  }
  reverse (hexString.begin(),hexString.end());
  return "0x" + hexString;
} 

string hexToDecimal (const string& strNumber) {
  int dValue = 0, power = 0, counter = strNumber.size() - 1, newValue;
  while (counter >= 2) {
    newValue = hexChartoInt(strNumber[counter]);
    dValue += newValue * static_cast<int>(pow(16,power));
    power++;
    counter--;
  }

  return to_string (dValue);
}


string hexToBinary (const string& strNumber) {
  string newString;

  newString = hexToDecimal(strNumber);
  newString = decimalToBinary (newString);

  return newString;
}

string binaryToHex (const string& strNumber) {
  string newString;

  newString = binaryToDecimal (strNumber);
  newString = decimalToHex (newString);

  return newString;
}