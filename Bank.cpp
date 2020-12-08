#include <iostream>
#include "Bank.h"
#include <fstream>
using namespace std;
Bank::Bank() {
	name = "";
	surname = "";
	balanceBYN = 0;
	balanceUSD = 0;
	PasNum = "";
}
Bank::Bank(string fname, string fsurname, float fbalanceBYN,float fbalanceUSD, string fpasnum) {
	name = fname;
	surname = fsurname;
	balanceBYN = fbalanceBYN;
	balanceUSD = fbalanceUSD;
	PasNum = fpasnum;
}
void Bank::ShowParametrs() {
	cout << "���: " << name << endl;
	cout << "�������: " << surname << endl;
	cout << "������������������ �����: " << PasNum << endl;
	cout << "������ ������: " << balanceBYN << "R" << endl;
	cout << "������ ��������: " << balanceUSD <<"$"<< endl;
}
void Bank::add_balance(float fbl) {
	balanceBYN += fbl;
	cout << endl;
	cout << "�������� ��: " << fbl << "R" << endl;
	cout << "������ BYN:" << balanceBYN << "R" << endl;
}
void Bank::put_balance(float pb) {
	balanceBYN -= pb;
	cout << endl;
	cout << "����� BYN: " << pb << "R" << endl;
	cout << "������ BYN: " << balanceBYN << "R" << endl;
}
void Bank::add_balanceUSD(float fbl) {
	balanceUSD += fbl;
	cout << endl;
	cout << "��������� �� USD: " << fbl << "$" << endl;
	cout << "������: " << balanceUSD << "$" << endl;
}
void Bank::put_balanceUSD(float pb) {
	balanceUSD -= pb;
	cout << endl;
	cout << "����� USD: " << pb << "$" << endl;
	cout << "������: " << balanceUSD << "$" << endl;
}
void Bank::buyUSD_payBYN(float USD) {
	ifstream InKurs;
	string str;
	InKurs.open("kurs.txt");
	if (InKurs.is_open()) {
		InKurs >> str;
		float usdToBYN = stoi(str);
		float sumToPutOfBYN = USD * usdToBYN;
		if (sumToPutOfBYN < balanceBYN) {
			Bank::put_balance(sumToPutOfBYN);
			cout << "����� �������� ������.";
			cout << endl << "������ BYN:" << endl;
			Bank::add_balanceUSD(USD);
		}
		else cout << "�� �������� ������!";
	}
	else cout << "��������!!!!";
}