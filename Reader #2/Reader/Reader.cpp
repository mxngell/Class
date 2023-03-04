#include <iostream>
#include <string>
#include <locale>
#include <regex>


#define TESTINGFUNC

using namespace std;

class Human {
private:
	string name;
	bool sex;
	int bookCount;
public:
	int setName(string newName) {
		smatch n;
		int error{ 0 };
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

	int setSex(bool curSex) {
		sex = curSex;
		return 0;
	}
	bool getSex() {
		return sex;
	}

	int setBookCount(int curCount) {
		int error{ 0 };
		if (curCount < 1) {
			error = -1;
		} else {
			bookCount = curCount;
		}
		return error;
	}

	int getBookCount() {
		return bookCount;
	}
};

class Imaginatiom {
private:
	string obraz;
public:
	int setObraz(string) {

	}
	string getObraz() {
		return obraz;
	}
};


class Book {
private:
	string name;
	string author;
	string ISBN;
	int prCount;
public:
	int setName(string newName) {
		int error{ 0 };
		smatch m;
		if (regex_search(newName, m, regex("^[А-Я]{1}[а-я]{1,30}$"))) {
			error = 0;
			name = newName;
		}
		else {
			error = -1;
		}
		return error;
	}

	string getName() {
		return name;
	};

	string getISBN() {
		return ISBN;
	};

	int setISBN(string isbn) {
		int error{ 0 };
		smatch n;
		if (regex_search(isbn, n, regex("^[0-9]{3}-[0-9]{1}-[0-9]{2,7}-[0-9]{2}-[0-9]{1}$"))) {
			error = 0;
			ISBN = isbn;
		}
		else {
			error = -1;
		}
		return error;
	}


	int setAuthor(string auth) {
		int error{ 0 };
		smatch n;
		if (regex_search(auth, n, regex("^[А-Я]{1}[а-я]{1,} [А-Я]{1}. [А-Я]{1}.$"))){
			error = 0;
		}
		else {
			author = auth;
			error = -1;
		}
		return error;
	}

	string getAuthor() {
		return author;
	}

	int setPrCount(int curCount) {
		int error{ 0 };
		if (curCount < 1 and curCount > 10) {
			error = -1;
		}
		else {
			prCount = prCount;
		}
		return error;
	}

	int getPrCount() {
		return prCount;
	}
};

class Proizvedenie {
private:
	string name;
public:
	int setName(string newName) {
		int error{ 0 };
		smatch m;
		if (regex_search(newName, m, regex("^[А-Я]{1}[а-я]{1,30}$"))) {
			error = 0;
			name = newName;
		}
		else {
			error = -1;
		}
		return error;
	}

	string getName() {
		return name;
	};

};


class Story {
private:

public:

};


class Character {
private:
	string name;
	bool antagonist;
	bool protagonist;
public:
	int setName(string newName) {
		int error{ 0 };
		smatch m;
		if (regex_search(newName, m, regex("^[А-Я]{1}[а-я]{1,30}$"))) {
			error = 0;
			name = newName;
		}
		else {
			error = -1;
		}
		return error;
	}

	string getName() {
		return name;
	};

	int setAntagonist(bool curStatus) {
		int error{ 0 };
		if (curStatus == 0 or curStatus == 1) {
			antagonist = curStatus;
		}
		else {
			error = -1;
		}
		return error;
	}
	
	bool getAntagonist(){
		return antagonist;
	}
};

//TESTING METHOD


int main() {
	setlocale(LC_ALL, "Russian");
	
	Book test;

	return 0;
}