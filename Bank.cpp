#include <iostream>
#include "Bank.h"
using namespace std;
Bank::Bank() {
	name = "";
	surname = "";
	balance = 0;
	PasNum = "";
}
Bank::Bank(string fname, string fsurname, unsigned int fbalance, string fpasnum) {
	name = fname;
	surname = fsurname;
	balance = fbalance;
	PasNum = fpasnum;
}
void Bank::ShowParametrs() {
	cout << "���: " << name << endl;
	cout << "�������: " << surname << endl;
	cout << "������������������ �����: " << PasNum << endl;
	cout << "������ :" << balance << "$" << endl;
}
float Bank::add_balance(float fbl) {
	balance += fbl;
	return balance;
}