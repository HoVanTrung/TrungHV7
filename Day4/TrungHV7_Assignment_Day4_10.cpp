// TrungHV7_Assignment_Day4_10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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
	delete[] str;
}
String operator + (const String& strOne, const String& strTwo) {

	int index, jndex;
	String sStringConcat = strOne;

	for (jndex = 0; strOne.str[jndex] != '\0'; ++jndex) {
		for (index = 0; strOne.str[jndex] != '\0'; ++index, ++jndex) {
			*(sStringConcat.str + jndex) = *(strTwo.str + index);
			cout << "\nStringConcat: " << sStringConcat.str;

		}
		sStringConcat.str[jndex] = '\0';
	}

	return sStringConcat;
}


ostream& operator << (ostream& os, String& str) {
	os << str.str;
	return os;
}

istream& operator >> (istream& is, String& str) {
	//cout << "\nEnter Length string is: ";
	//is >> str.iLenght;
//	fflush(stdin);
	str.str = new char[100];
//	str.str = new char[str.iLenght + 1];
//	do {
		cout << "\nEnter character string: ";
		is >> str.str;
//	} while (strlenght(str.str) >= str.iLenght);

//	/*is.ignore();
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
	cout << "\n=== String Concat ===" << sStringConcat;
	return 0;

}

