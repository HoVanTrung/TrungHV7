// TrungHV7_Assignment_Day4_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
using namespace std;

int strlenght(char *str){
	int length = 0, i;
	for (i = 0; str[i] != '\0'; ++i) {
		length++;
	}
	return length;
}

class String
{
public:
	String();
	~String();
	friend String operator + (const String& strOne, const String& strTwo);
	friend ostream& operator << (ostream&, String&);
	friend istream& operator >> (istream&, String&);
public:
	char* str;
	int iLenght;
};

String::String()
{
}

String::~String()
{
	iLenght = 0;
	if(strlenght(str)==NULL)
		delete[] str;
}
String operator + (const String& strOne, const String& strTwo) {

	String sStringConcat = strOne;
	int index, iIndexConcat = strlenght(sStringConcat.str);
	for (index = 0; strTwo.str[index] != '\0'; ++index) {
		sStringConcat.str[iIndexConcat] =  strTwo.str[index];
		iIndexConcat++;
	}
	return sStringConcat;
}


ostream& operator << (ostream& os, String& str) {
	os << str.str;
	return os;
}

istream& operator >> (istream& is, String& str) {
	cout << "\nEnter Length string is: ";
	is >> str.iLenght;
//	fflush(stdin);
	str.str = new char[str.iLenght + 1];
	do {
		cout << "\nEnter character string: ";
		is >> str.str;
	} while (strlenght(str.str) >= str.iLenght);

////	/*is.ignore();
//	is.getline(str.str, str.iLenght + 1);*/

	return is;
}
int main()
{
	String sSringOne, sStringTwo, sStringConcat;
	cout << "\n=== String One ===";
	cin >> sSringOne;
	cout << "\n=== String Two ===";
	cin >> sStringTwo;
	sStringConcat = sSringOne + sStringTwo;
	cout << "\n=== String Concat ===" << "\nCharacter string after: " << sStringConcat;
	return 0;

}

