#include <iostream>
#include <string>
#include <locale>
#include <regex>

#define TESTINGFUNC

using namespace std;


class Publication {
private:
	string name;
	int year;
public:
	int setName(string newName) {
		int error{ 0 };
		smatch m;
		if (regex_search(newName, m, regex("^[А-Я]{1}[а-я]{1,30}$"))){
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


	int getYear() {
		return year;
	};


	int setYear(int curYear) {
		int error{ 0 };
		if (curYear < 1 || curYear > 2023 ) {
			error = -1;
		}
		else {
			year = curYear;
		}
		return error;
	}
};

//METHODTEST
void testPublicationSetYear(Publication obj) {
	//0 1 2024 -1 2021
	int curYear{ 1 };
	if (obj.setYear(curYear) == 0) {
		cerr << "Test " << curYear << " success!" << endl;
	}
	else {
		cerr << "Test " << curYear << " failed!" << endl;
	}

	curYear = 0;
	if (obj.setYear(curYear) == -1) {
		cerr << "Test " << curYear << " success!" << endl;
	}
	else {
		cerr << "Test " << curYear << " failed!" << endl;
	}

	curYear = 2024;
	if (obj.setYear(curYear) == 0) {
		cerr << "Test " << curYear << " success!" << endl;
	}
	else {
		cerr << "Test " << curYear << " failed!" << endl;
	}

	curYear = -1;
	if (obj.setYear(curYear) == -1) {
		cerr << "Test " << curYear << " success!" << endl;
	}
	else {
		cerr << "Test " << curYear << " failed!" << endl;
	}

	curYear = 2021;
	if (obj.setYear(curYear) == 0) {
		cerr << "Test " << curYear << " success!" << endl;
	}
	else {
		cerr << "Test " << curYear << " failed!" << endl;
	}
}

class Book : public Publication {
private:
	string ISBN;
	string Izd;
	int PubCount;
	string Author;
public:
	string getISBN() {
		return ISBN;
	};
	int setISBN(string isbn) {
		int error{ 0 };
		if (isbn == "" or isbn == " ") {
			error = -1;
		}
		else {
			ISBN = isbn;
		}
		return error;
	}
	string getIzd() {
		return Izd;
	};
	int setIzd(string izd) {
		Izd = izd;
		return 0;
	}
	int getPubCount() {
		return PubCount;
	};
	int setPubCount(int pCount) {
		int error{ 0 };
		if (pCount < 0 or pCount > 100) {
			error = -1;
		}
		else {
			PubCount = pCount;
		}
		return error;
	}
	string getAuthor() {
		return Author;
	};
	int setAuthor(string auth) {
		int error{ 0 };
		if (auth == "" or auth == " ") {
			error = -1;
		}
		else {
			Author = auth;
		}
		return error;
	}
};


class Magazine : public Publication {
private:
	string ISBN;
	string Izd;
	int PubCount;
	string Author;
	int Tom;
	int Number;
	bool Scoups;
	bool WoS;
	bool RINC;
public:
	string getISBN() {
		return ISBN;
	};
	int setISBN(string isbn) {
		int error{ 0 };
		if (isbn == "" or isbn == " ") {
			error = -1;
		}
		else {
			ISBN = isbn;
		}
		return error;
	}
	string getIzd() {
		return Izd;
	};
	int setIzd(string izd) {
		Izd = izd;
		return 0;
	}
	int getPubCount() {
		return PubCount;
	};
	void setPubCount(int pCount) {
		if (pCount < 0 or pCount > 1000) {
			cout << "Invalid param";
		}
		else {
			PubCount = pCount;
		}
	}
	string getAuthor() {
		return Author;
	};
	int setAuthor(string auth) {
		Author = auth;
		return 0;
	}
	int getTom() {
		return Tom;
	};
	int setTom(int tom) {
		int error{ 0 };
		if (tom < 0 or tom > 10) {
			error = -1;
		}
		else {
			Tom = tom;
		}
		return error;
	}
	int getNumber() {
		return Number;
	};
	int setNumber(int num) {
		Number = num;
		return 0;
	}
	bool getScoups() {
		return Scoups;
	};
	int setScoups(bool scoups) {
		Scoups = scoups;
		return 0;
	}
	bool getWoS() {
		return WoS;
	};
	int setWoS(bool wos) {
		WoS = wos;
		return 0;
	}
	bool getRINC() {
		return RINC;
	};
	int setRINC(bool rinc) {
		RINC = rinc;
		return 0;
	}
};

class Article : public Magazine {
private:
	string Author;
	int Pstart;
	int Pend;
	bool Status;
public:
	string getAuthor() {
		return Author;
	};
	int setAuthor(string auth) {
		int error{ 0 };
		if (auth == "" or auth == " ") {
			error = -1;
		}
		else {
			Author = auth;
		}
		return error;
	}
	int getPstart() {
		return Pstart;
	};
	int setPstart(int pStart) {
		Pstart = pStart;
		return 0;
	}
	int getPend() {
		return Pend;
	};
	int setPend(int pEnd) {
		Pend = pEnd;
		return 0;
	}
	bool getStatus() {
		return Status;
	};
	int setStatus(bool status) {
			Status = status;
			return 0;
	}
};


int main() {
	setlocale(LC_ALL, "Russian");
	Publication test;
#ifdef TESTINGFUNC
	testPublicationSetYear(test);
#endif

}