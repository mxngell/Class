#include <iostream>
#include <string>
#include <locale>
#include <regex>


#define DEBUG

using namespace std;


class Library {
private: 
	string name;
public:
	int SetName(string newName) {
		int error{ 0 };
		smatch n;
		if (regex_search(newName, n, regex("^[А-Я]{1}[а-я]{1,30}$"))) {
			name = newName;
			error = 0;
		}
		else {
			error = -1;
		}
		return error;
	}
	string getName() {
		return name;
	}
};

class Reader{
private:
	//string name;
	string surname;
	bool sex;
	//1 = male; 0 = female
public:
	int setSurname(string sName) {
		surname = sName;
		return 0;
	}
	string getSurname() {
		return surname;
	}
};

class ReaderCard {
private:
	string readerSurname;
	int duty;
public:
	int readerSurname(string readerSName) {
		readerSurname = readerSName;
		return 0;
	}
	string getSurname() {
		return readerSurname;
	}
};

int main() {
	Library test;
	cerr << test.SetName("Малик") << endl;
	cerr << test.getName() << endl;

	Reader test1;
	cerr << test1.setSurname("malik") << endl;
	cerr << test1.getSurname() << endl;
}