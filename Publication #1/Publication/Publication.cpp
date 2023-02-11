#include <iostream>
#include <string>
#include <locale>

using namespace std;


class Publication {
private:
	string name;
	int year;
public:
	string getName() {
		return name;
	};
	void setName(string a) {
		if (a == "" or a == " ") {
			cout << "Invalid param";
		}
		else {
			name = a;
		}
	}
	int getYear() {
		cout << year << endl;
		return 0;
	};
	void setYear(int a) {
		if (a < 0 or a > 2023) {
			cout << "Invalid param";
		}
		else {
			year = a;
		}
	}
};

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
	void setISBN(string a) {
		if (a == "" or a == " ") {
			cout << "Invalid param";
		}
		else {
			ISBN = a;
		}
	}
	string getIzd() {
		return Izd;
	};
	void setIzd(string a) {
		Izd = a;
	}
	int getPubCount() {
		return PubCount;
	};
	void setPubCount(int a) {
		if (a < 0 or a > 100) {
			cout << "Invalid param";
		}
		else {
			PubCount = a;
		}
	}
	string getAuthor() {
		return Author;
	};
	void setAuthor(string a) {
		if (a == "" or a == " ") {
			cout << "Invalid param";
		}
		else {
			Author = a;
		}
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
	void setISBN(string a) {
		if (a == "" or a == " ") {
			cout << "Invalid param";
		}
		else {
			ISBN = a;
		}
	}
	string getIzd() {
		return Izd;
	};
	void setIzd(string a) {
		
		Izd = a;
	}
	int getPubCount() {
		return PubCount;
	};
	void setPubCount(int a) {
		if (a < 0 or a > 1000) {
			cout << "Invalid param";
		}
		else {
			PubCount = a;
		}
	}
	string getAuthor() {
		return Author;
	};
	void setAuthor(string b) {
		Author = b;
	}
	int getTom() {
		return Tom;
	};
	void setTom(int a) {
		if (a < 0 or a > 10) {
			cout << "Invalid param";
		}
		else {
			Tom = a;
		}
	}
	int getNumber() {
		return Number;
	};
	void setNumber(int a) {
		Number = a;
	}
	bool getScoups() {
		return Scoups;
	};
	void setScoups(bool a) {
		Scoups = a;
	}
	bool getWoS() {
		return WoS;
	};
	void setWoS(bool a) {
		WoS = a;
	}
	bool getRINC() {
		return RINC;
	};
	void setRINC(bool a) {
		RINC = a;
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
	void setAuthor(string a) {
		if (a == "" or a == " ") {
			cout << "Invalid param";
		}
		else {
			Author = a;
		}
	}
	int getPstart() {
		return Pstart;
	};
	void setPstart(int a) {
		Pstart = a;
	}
	int getPend() {
		return Pend;
	};
	void setPend(int a) {
		Pend = a;
	}
	bool getStatus() {
		return Status;
	};
	void setStatus(bool a) {
			Status = a;
	}
};


int main() {
	setlocale(LC_ALL, "Russian");

	Publication test;
	test.setName("Образование");
	cout << test.getName() << endl;

	Book testBook;
	testBook.setISBN("81687-63452");
	cout << testBook.getISBN() << endl;

	Magazine testMagazine;
	testMagazine.setRINC(1);
	cout << testMagazine.getRINC() << endl;

	Article testArticle;
	testArticle.setPstart(10);
	testArticle.setPend(15);
	cout << testArticle.getPstart() << "\t" << testArticle.getPend() << endl;

	testBook.setName("");
	cout << testBook.getName() << endl;
}