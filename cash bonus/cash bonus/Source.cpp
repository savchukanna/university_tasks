//Банк. Организовать ввод данных о клиентах с возможностью продолжения ввода или прекращения.

#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <limits>
#include <fstream>
using namespace std;

class CashBonus {
	string last_name;
	string first_name;
	string position;
	int day_of_appointment;
	int month_of_appointment;
	int year_of_appointment;
	double amount_of_cash_bonus;

public:
	string get_last_name() { return last_name; }
	void set_last_name(string surname) { last_name = surname; }
	string get_first_name() { return first_name; }
	void set_first_name(string name) { first_name = name; }
	string get_position() { return position; }
	void set_position(string pos) { position = pos; }
	int get_day() { return day_of_appointment; }
	void set_day(int day) { day_of_appointment = day; }
	int get_month() { return month_of_appointment; }
	void set_month(int month) { month_of_appointment = month; }
	int get_year() { return year_of_appointment; }
	void set_year(int year) { year_of_appointment = year; }
	double get_cash_bonus() { return amount_of_cash_bonus; }
	void set_cash_bonus(double amount) { amount_of_cash_bonus = amount; }
};

void show_main_menu(CashBonus* obj, int count);
void input_data(CashBonus* obj);
void output_data(CashBonus* obj, int count);
int check_day(int month, int year);
int check_month();
int check_year();
string check_text();
double check_number();
bool is_name_correct(string name);
CashBonus* employers(CashBonus* obj, const int count);

CashBonus* employers(CashBonus* obj, const int count)
{
	if (count == 0)  {
		obj = new CashBonus[count + 1];
	}
	else  {
		CashBonus* employers = new CashBonus[count + 1];
		for (int i = 0; i < count; i++)	{
			employers[i] = obj[i];
		}
		delete[] obj;
		obj = employers;
	}
	return obj;
}


bool is_name_correct(string name) {
	if (name.length() <= 0) {
		return false;
	}
	for (int i = 0; i < name.length(); i++) {
		if (!isalpha(name[i]) && !isspace(name[i])) {
			return false;
		}
	}
	return true;
}

string check_text() {
	string text;
	//cin.clear();
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, text);
	return text;
}

double check_number() {
	string input;
	do	{
		cin >> input;
		double value = atof(input.c_str());
		if (value > 0.0)
			return value;
		cout << "You input wrong data. Try again" << endl;
	} while (true);
}

int check_day(int month, int year) {
	int day;
	cin >> day;
	int max_day = 31;
	while (true) {
		if (year % 4 == 0 && month == 2)
		{
			max_day = 29;
		}
		if (year % 4 != 0 && month == 2)
		{
			max_day = 28;
		}
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			max_day = 30;
		}
		if (!cin || day < 1 || day > max_day)
		{
			cout << "You should enter a number(1-" << max_day << ")" << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin >> day;
		}
		else break;
	}
	return day;
}

int check_month() {
	int month;
	cin >> month;
	while (true) {
		if (!cin || month < 1 || month > 12)
		{
			cout << "Not correct, must be a number(1-12)" << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin >> month;
		}
		else break;
	}
	return month;
}

int check_year() {
	int year;
	cin >> year;
	while (true) {
		if (!cin || year < 1 || year > 2019)
		{
			cout << "Not correct, must be a number(1-2019)" << endl;
			cin.clear();
			while (cin.get() != '\n');
			cin >> year;
		}
		else break;
	}
	return year;
}

void show_main_menu(CashBonus* obj, int count) {
	short int ind;
	cout << "Main menu" << endl << endl;
	cout << "0 - Exit" << endl;
	cout << "1 - Enter employee data" << endl;
	cout << "2 - Output data" << endl;

	cout << "Your choice: ";
	cin >> ind;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Invalid format! Try again!" << endl;
	}
	switch (ind) {
	case 0:
		exit(0);
	case 1:
		system("cls");
		input_data(&obj[count]);
		count++;
		break;
	case 2:
		system("cls");
		output_data(obj, count);
		system("pause");
		break;
	default:
		cout << "Incorrect button. Try again." << endl;
		system("pause");
		break;
	}
	system("cls");
}

void input_data(CashBonus* obj) {
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());

	cout << "Enter the surname of employee: ";
	obj->set_last_name(check_text());

	cout << "Enter the name of employee: ";
	obj->set_first_name(check_text());

	cout << "Enter year of appointment: ";
	obj->set_year(check_year());

	cout << "Month of appointment: ";
	obj->set_month(check_month());

	cout << "Day of appointment: ";
	obj->set_day(check_day(obj->get_year(), obj->get_month()));
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	cout << "Enter the position of employee: ";
	obj->set_position(check_text());

	cout << "Enter amount of cash bonus: ";
	obj->set_cash_bonus(check_number());
}

void output_data(CashBonus* obj, int count) {
	if (obj == NULL)
	{
		return;
	}
	for (int i = 1; i <= 74; i++)
	{
		cout << "-";
	}
	cout << endl;
	cout << "|    Surname   | Employee name |    Position   | Cash bonus  |   data    |";
	cout << endl;
	for (int i = 1; i <= 74; i++)
	{
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < count; i++)
	{
		cout << "|" << setfill(' ') << setw(14) << (obj + i)->get_last_name();
		cout << "|" << setfill(' ') << setw(15) << (obj + i)->get_first_name();
		cout << "|" << setfill(' ') << setw(15) << (obj + i)->get_position();
		cout << "|" << setfill(' ') << setw(13) << fixed << setprecision(3) << (obj + i)->get_cash_bonus();
		cout << "|" << setfill('0') << setw(2) << (obj + i)->get_day() << "." << setfill('0') << setw(2);
		cout << (obj + i)->get_month() << "." << setfill('0') << setw(5) << (obj + i)->get_year();
		cout << "|" << endl;
		for (int i = 1; i <= 74; i++)
		{
			cout << "-";
		}
		cout << endl;
	}
}

int main() {
	const int n = 100;
	CashBonus* obj = new CashBonus[n];
	int count = 0;
	int ind;
	while (true) {
		obj = employers(obj, count);
		show_main_menu(obj, count);
		count++;
		cout << endl << "Open the menu again? (0/1)" << endl;

		cout << "Your choice: ";
		cin >> ind;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Invalid format! Try again!" << endl;
		}
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

	};
	//delete[] obj;
	system("pause");
	return 0;
}