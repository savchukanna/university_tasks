#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>

#define AMOUNT 100

using namespace std;

int Rand(int num){
	return rand() % num + 1;
}

class BaseExeption{

protected:
	string text;

public:
	BaseExeption(){}
	virtual string what() = 0;
};

class ArithmeticExeption : public BaseExeption {

public:
	ArithmeticExeption(){}

	ArithmeticExeption(string text)	{
		this->text = text;
	}
	string what()	{
		return text;
	}
};

class WrongIndex :public BaseExeption{

public:
	WrongIndex(){}

	WrongIndex(string text)	{
		//text = "Error.Wrong Index";
		this->text = text;
	}

	string what() {
		return text;
	}
};

class Date {

public:
	int year;
	int month;
	int day;

	Date() {
		day = Rand(31);
		month = Rand(12);
		year = Rand(50) + 1980;
	}

	void show() {
		cout << endl << "Day: " << day;
		cout << endl << "Month: " << month;
		cout << endl << "Year: " << year;
	}

	int getDay() {
		return day;
	}

	int get_month() {
		return month;
	}

	int get_year() {
		return year;
	}

	Date(const Date& a)	{
		this->year = a.year;
		this->month = a.month;
		this->day = a.day;
	}

	Date& operator = (const Date& obj) {
		if (this != &obj) {
			this->year = obj.year;
			this->month = obj.month;
			this->day = obj.day;
		}
		return *this;
	}

	//virtual void show()	{}
};

class Person :public Date {

public:
	char first_name[15];
	char last_name[15];
	char first_name_1[15];

	Person() :Date() {

		for (int i = 0; i < 15; i++) {
			last_name[i] = '\0';
			first_name[i] = '\0';
			first_name_1[i] = '\0';
		}


		for (int i = 0; i < 14; i++) {
			last_name[i] = 'a' + rand() % 26;
		}

		for (int i = 0; i < 14; i++) {
			first_name[i] = 'a' + rand() % 26;
			first_name_1[i] = first_name[i];
		}
	}

	void show()	{
		cout << "\n\tSurname: " << last_name << endl;
		cout << "\tName:" << first_name << endl;
		cout << "Date: ";
		Date::show();
	}

	Person(const Person& a)	{
		strcpy(first_name, a.first_name);
		strcpy(last_name, a.last_name);
		strcpy(first_name_1, a.first_name_1);
	}

	Person& operator=(const Person& a) {
		if (this != &a)	{
			strcpy(this->first_name, a.first_name);
			strcpy(this->last_name, a.last_name);
			strcpy(this->first_name_1, a.first_name_1);
			Date::operator=(a);
		}
		return*this;
	}
};

class Author :public Person {

public:
	char position[15];

	Author() :Person()	{
		for (int i = 0; i < 15; i++) {
			position[i] = '\0';
		}
		for (int i = 0; i < 14; i++) {

			position[i] = 'a' + rand() % 26;
		}
	}

	void Show()	{
		Person::show();
		cout << "\nPosition: " << position << endl;
	}

	Author(const Author& a)	{
		strcpy(position, a.position);
		Person::operator=(a);
	}

	Author& operator=(const Author& a)	{
		if (this != &a)	{
			strcpy(position, a.position);
			Person::operator=(a);
		}
		return*this;
	}
};

class Teza : public Date {

public:
	Author leader;
	Author student;
	char title[20];
	int images;
	int links;
	float pages;

	int rand_num;
	string rand_string;

	Teza() :Date() {
		rand_num = rand() % 1000;

		rand_string = '\0';
		for (int i = 0; i < 20; i++) {
			title[i] = '\0';
		}
		for (int i = 0; i < 15; i++) {
			title[i] = 'a' + rand() % 26;
			rand_string += title[i];
		}

		images = Rand(56);
		links = Rand(12);
		pages = Rand(25);

		Author temp;
		leader = temp;
		Author temp_obj;
		student = temp_obj;
	}

	string& get_rand_string() {
		return rand_string;
	}

	int get_rand_num()	{
		return rand_num;
	}

	void show()	{
		cout << "_______________________" << endl;
		cout << endl << "Date: " << getDay() << "." << get_month() << "." << get_year();
		cout << endl << "Author(leader): ";
		leader.Show();
		cout << endl << "Author(student): ";
		student.Show();
		cout << endl << "Title: " << title;
		cout << endl << "AmountImages: " << images;
		cout << endl << "AmountLinks: " << links;
		cout << endl << "AmountImages: " << pages;
		cout << endl;
	}

	Teza(const Teza& a)	{
		strcpy(title, a.title);
		this->images = a.images;
		this->links = a.links;
		this->pages = a.pages;
		this->leader = a.leader;
		this->student = a.student;
		this->rand_string = a.rand_string;
		this->rand_num = a.rand_num;
		Date::operator=(a);
	}

	Teza& operator=(const Teza& a)	{
		if (this != &a)	{
			strcpy(this->title, a.title);
			this->images = a.images;
			this->links = a.links;
			this->pages = a.pages;
			this->leader = a.leader;
			this->student = a.student;
			this->rand_string = a.rand_string;
			this->rand_num = a.rand_num;
			Date::operator=(a);
		}
		return *this;
	}
};

class CollectionOfTezes :public Date {

private:
	int size;
public:
	
	vector<Teza> tezes;
	int total_pages;

	int get_size() {
		return size;
	}

	CollectionOfTezes() {}

	~CollectionOfTezes() {
		tezes.clear();
	}

	CollectionOfTezes(int num) :Date()	{
		size = num;
		total_pages = Rand(78);
		for (int i = 0; i < size; i++)
		{
			Teza value;
			tezes.push_back(value);
		}
	}

	Teza& operator[](int index)	{
		if (index < 0 || index >= size)
		{
			throw new WrongIndex("Error.Negative Index");
		}
		return tezes[index];
	}

	double char_sort()
	{
		cout << "Not sorted" << endl;
		time_t start = clock();

		for (int i = 0; i < 10; i++) {
			cout << tezes[i].leader.first_name << " - " << tezes[i].leader.first_name_1 << endl;
		}
		for (int i = 0; i < size; i++)	{
			for (int j = i + 1; j < size; j++)	{
				if (strcmp(tezes[i].leader.first_name, tezes[j].leader.first_name) > 0)	{
					Teza obj;
					obj = tezes[i];
					tezes[i] = tezes[j];
					tezes[j] = obj;
				}
			}
		}
		time_t end = clock();
		double speed_per_second = (double)(end - start) / CLOCKS_PER_SEC;
		cout << endl << "Char sort:" << setprecision(10) << speed_per_second << endl;

		for (int i = 0; i < 10; i++) {
			cout << tezes[i].leader.first_name << " - " << tezes[i].leader.first_name_1 << endl;
		}
		cout << endl;
		return speed_per_second;
	}

	double string_sort()
	{
		cout << "Not sorted" << endl;
		for (int i = 0; i < 10; i++) {
			cout << tezes[i].leader.first_name << " - " << tezes[i].leader.first_name_1 << endl;
		}
		time_t start = clock();
		for (int i = 0; i < size; i++)	{
			for (int j = i + 1; j < size; j++)	{
				if (tezes[i].leader.first_name_1 > tezes[j].leader.first_name_1) {
					Teza obj;
					obj = tezes[i];
					tezes[i] = tezes[j];
					tezes[j] = obj;
				}
			}
		}
		time_t end = clock();
		double speed_per_second = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "String sort: " << setprecision(10) << speed_per_second << endl;
		cout << endl;

		for (int i = 0; i < 10; i++) {
			cout << tezes[i].leader.first_name << " - " << tezes[i].leader.first_name_1 << endl;
		}
		cout << endl;
		return speed_per_second;
	}

	void show()	{
		cout << endl << "Total pages: " << total_pages << endl;
		for (int i = 0; i < size; i++)	{
			tezes[i].show();
			cout << endl;
		}
		Date::show();
	}

	CollectionOfTezes(const CollectionOfTezes& other)
	{
		this->size = other.size;
		this->total_pages = other.total_pages;
		Date::operator=(other);

		this->tezes.clear();
		for (int i = 0; i < size; i++)	{
			this->tezes.push_back(other.tezes[i]);
		}
	}

	CollectionOfTezes& operator=(const CollectionOfTezes& a) {
		if (this != &a) {
			this->size = a.size;
			this->total_pages = a.total_pages;
			this->tezes.clear();
			for (int i = 0; i < size; i++)	{
				this->tezes.push_back(a.tezes[i]);
			}
			Date::operator=(a);
		}
		return *this;
	}

	void show_title() {
		cout << endl << "Title: " << endl;
		if (size >= 20)	{
			for (int i = 0; i < 20; i++)  {
				cout << i + 1 << ". " << tezes[i].title << endl;
			}
		}
		else  {
			for (int i = 0; i < size; i++)	{
				cout << i + 1 << ". " << tezes[i].title << endl;
			}
		}
	}

	vector <Teza>& get_tesis_arr()
	{
		return tezes;
	}
};

template<typename T>
double calc_avarage_square(T count, Teza* array) {
	double sum = 0;
	for (int i = 0; i < count; i++) {
		sum += pow(array[i].links, 2);
	}
	return sqrt(sum / count);
}

template <class T>
class Test {

private:
	T obj;

public:

	T get_obj() {
		return obj;
	}

	void show(Date* date) {
		date->show();
	}
};


bool sort_num(Teza& obj1, Teza& obj2)  {
	return (obj1.get_rand_num() < obj2.get_rand_num());
}

bool sort_string(Teza& obj1, Teza& obj2)  {
	return (obj1.get_rand_string() < obj2.get_rand_string());
}

int main()
{
	Date base;
	Date** p = new Date * [4];
	p[0] = &base;
	//p->show();

	Person show0;
	p[1] = &show0;
	//p->show();

	Author show1;
	p[2] = &show1;
	//p->show();

	Teza show2;
	p[3] = &show2;
	//p->show();
	for (int i = 0; i < 3; i++) {
		p[i]->show();
		cout << endl << "----------------------------------------------" << endl;
	}

	CollectionOfTezes a(1000);

	try {
		a[-1];
	}
	catch (BaseExeption* exception) {
		cout << exception->what() << endl;
	}

	CollectionOfTezes c;
	c = a;
	CollectionOfTezes b;
	CollectionOfTezes d;
	d = a;
	b = a;

	cout << endl << endl << "After sorting string: " << endl << endl;
	c.string_sort();
	c.show_title();

	cout << endl << endl;

	double time_start;
	double time_end;

	cout << "Char sort" << endl;
	time_start = clock();
	sort(b.get_tesis_arr().begin(), b.get_tesis_arr().end(), sort_num);
	time_end = clock();
	cout << "Time of sorting = " << (time_end - time_start) / CLOCKS_PER_SEC << endl;
	cout << endl;
	cout << endl;

	cout << "String sort" << endl;
	time_start = clock();
	sort(d.get_tesis_arr().begin(), d.get_tesis_arr().end(), sort_string);
	time_end = clock();
	cout << "Time of sorting = " << (time_end - time_start) / CLOCKS_PER_SEC << endl;
	cout << endl;
	cout << endl;

	system("pause");
	return 0;
}
