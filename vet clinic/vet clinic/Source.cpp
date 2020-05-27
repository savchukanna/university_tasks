//Организовать процесс работы и хранения данных в ветеринарной клинике.
//У хозяина может быть несколько котов.На каждого кота заведена карточка.
//Ветеринар может добавить информация о приеме и результаты анализов за определенную дату.
//Организовать ввод, вывод данных для определенного кота и всех котов конкретного хозяина.

#include <string>
#include <iostream> 
#include <iomanip> 

#define DEFAULT_CLIENT_COUNT 2

using namespace std;

struct MedicalCardRecord {
	string date;
	string reception_information;
	string results_of_analysis;
};

struct MedicalCard {
	int id;
	int count_records;
	MedicalCardRecord* records;
};

struct Cat {
	int id;
	string name;
	string color;
	string breed;
	int age;
	MedicalCard card;
};

struct Client {
	int id;
	string name;
	string phone;
	int count_cat;
	Cat* cats;
};

struct ClientAndCat {
	int client_id;
	int cat_id;
};

int convert_char_to_int(char);
void show_clients(Client*);
void show_cats(Client*);
void show_cat_by_id(Client*, int);
void show_cat_by_client_id(Client*, int);
void show_medical_card(MedicalCard);
int search_client(Client*, int, int);
ClientAndCat search_cat(Client*, int, int);
void fill_health_information(Client*, int);
void fill_health_information_by_client_id(Client*, int);

void show_menu()
{
	cout << "M E N U" << endl;
	cout << "1 - Show all clients" << endl;
	cout << "2 - Show all cats" << endl;
	cout << "3 - Show cat by ID" << endl;
	cout << "4 - Show all cats of client" << endl;
	cout << "5 - Add cat health information" << endl;
	cout << "6 - Add cats health information of client" << endl;
	cout << "0 - Exit Program" << endl;
	cout << "Enter Menu Option   ";
}

int convert_char_to_int(char symbol)
{
	return (int)symbol - 48;
}

void show_clients(Client* clients)
{

	cout << endl;
	cout << setw(15) << "ID" << '|' << setw(15) << "Name" << '|' << setw(15);
	cout << "Phone" << '|' << endl;

	for (int i = 0; i < DEFAULT_CLIENT_COUNT; i++) {

		cout << setw(15) << clients[i].id << '|' << setw(15) << clients[i].name;
		cout << '|' << setw(15) << clients[i].phone << '|' << endl;
	}

	cout << endl;
}

void show_cats(Client* clients)
{
	cout << endl;
	cout << setw(15) << "ID" << '|' << setw(15) << "Name" << '|' << setw(15);
	cout << "Color" << '|' << setw(15) << "Breed" << '|' << setw(15) << "Age";
	cout << '|' << setw(15) << "Client ID" << '|' << setw(15) << "Client Name";
	cout << '|' << endl;

	for (int i = 0; i < DEFAULT_CLIENT_COUNT; i++) {

		for (int j = 0; j < clients[i].count_cat; j++) {

			cout << setw(15) << clients[i].cats[j].id << '|' << setw(15);
			cout << clients[i].cats[j].name << '|' << setw(15);
			cout << clients[i].cats[j].color << '|';
			cout << setw(15) << clients[i].cats[j].breed << '|' << setw(15);
			cout << clients[i].cats[j].age << '|' << setw(15) << clients[i].id;
			cout << '|' << setw(15) << clients[i].name << '|' << endl;
		}
	}

	cout << endl;
}

void show_cat_by_id(Client* clients, int cat_id)
{

	cout << endl;

	ClientAndCat cat = search_cat(clients, cat_id, DEFAULT_CLIENT_COUNT);

	if (cat.cat_id == -1) {

		cout << "Data not found" << endl;
	}
	else {

		cout << setw(15) << "ID" << '|' << setw(15) << "Name" << '|' << setw(15);
		cout << "Color" << '|' << setw(15) << "Breed" << '|' << setw(15) << "Age";
		cout << '|' << setw(15) << "Client ID" << '|' << setw(15) << "Client Name";
		cout << '|' << endl;

		cout << setw(15) << clients[cat.client_id].cats[cat.cat_id].id << '|' << setw(15);
		cout << clients[cat.client_id].cats[cat.cat_id].name << '|' << setw(15);
		cout << clients[cat.client_id].cats[cat.cat_id].color << '|';
		cout << setw(15) << clients[cat.client_id].cats[cat.cat_id].breed << '|' << setw(15);
		cout << clients[cat.client_id].cats[cat.cat_id].age << '|' << setw(15) << clients[cat.client_id].id;
		cout << '|' << setw(15) << clients[cat.client_id].name << '|' << endl;

		show_medical_card(clients[cat.client_id].cats[cat.cat_id].card);
	}

	cout << endl;
}

void show_medical_card(MedicalCard card)
{

	if (card.count_records > 0) {

		cout << endl;
		cout << setw(30) << "Date" << '|' << setw(30);
		cout << "Reception Information" << '|' << setw(30);
		cout << "Results of analysis" << '|' << endl;
		for (int n = 0; n < card.count_records; n++) {
			cout << setw(30) << card.records[n].date << '|' << setw(30);
			cout << card.records[n].reception_information << '|' << setw(30);
			cout << card.records[n].results_of_analysis << '|' << endl;
		}
		cout << endl;
	}
}

ClientAndCat search_cat(Client clients[], int cat_id, int size)
{

	ClientAndCat result;
	result.client_id = -1;
	result.cat_id = -1;

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < clients[i].count_cat; j++) {

			if (clients[i].cats[j].id == cat_id) {

				result.client_id = i;
				result.cat_id = j;
			}
		}
	}

	return result;
}

int search_client(Client clients[], int client_id, int size)
{

	int result = -1;

	for (int i = 0; i < size; i++)
		if (clients[i].id == client_id)
			result = i;

	return result;
}

void show_cat_by_client_id(Client* clients, int client_id)
{

	cout << endl;

	int record_index = search_client(clients, client_id, DEFAULT_CLIENT_COUNT);

	if (record_index == -1) {

		cout << "Data not found" << endl;
	}
	else {

		cout << setw(15) << "ID" << '|' << setw(15) << "Name" << '|' << setw(15);
		cout << "Color" << '|' << setw(15) << "Breed" << '|' << setw(15) << "Age";
		cout << '|' << setw(15) << "Client ID" << '|' << setw(15) << "Client Name";
		cout << '|' << endl;

		for (int j = 0; j < clients[record_index].count_cat; j++) {

			cout << setw(15) << clients[record_index].cats[j].id << '|' << setw(15);
			cout << clients[record_index].cats[j].name << '|' << setw(15);
			cout << clients[record_index].cats[j].color << '|';
			cout << setw(15) << clients[record_index].cats[j].breed << '|' << setw(15);
			cout << clients[record_index].cats[j].age << '|' << setw(15) << clients[record_index].id;
			cout << '|' << setw(15) << clients[record_index].name << '|' << endl;

			show_medical_card(clients[record_index].cats[j].card);
		}
	}

	cout << endl;
}

void fill_health_information(Client* clients, int cat_id)
{

	ClientAndCat cat = search_cat(clients, cat_id, DEFAULT_CLIENT_COUNT);

	if (cat.cat_id == -1) {

		cout << "Data not found" << endl;
	}
	else {

		int size = clients[cat.client_id].cats[cat.cat_id].card.count_records;

		MedicalCardRecord* new_arr = new MedicalCardRecord[size + 1];

		for (int index = 0; index < size; index++) {
			new_arr[index] = clients[cat.client_id].cats[cat.cat_id].card.records[index];
		}

		cin.ignore();

		cout << "Enter Date: " << endl;
		getline(cin, new_arr[size].date);

		cout << "Enter Reception Information: " << endl;
		getline(cin, new_arr[size].reception_information);

		cout << "Enter Results of analysis: " << endl;
		getline(cin, new_arr[size].results_of_analysis);

		clients[cat.client_id].cats[cat.cat_id].card.records = new_arr;
		clients[cat.client_id].cats[cat.cat_id].card.count_records++;
	}

	cout << endl;
}

void fill_health_information_by_client_id(Client* clients, int client_id)
{

	int record_index = search_client(clients, client_id, DEFAULT_CLIENT_COUNT);

	if (record_index == -1) {

		cout << "Data not found" << endl;
	}
	else {

		for (int j = 0; j < clients[record_index].count_cat; j++) {

			fill_health_information(clients, clients[record_index].cats[j].id);
		}
	}

	cout << endl;
}

int main()
{

	char menu_choice;
	//default data
	Client clients[DEFAULT_CLIENT_COUNT];

	clients[0].id = 1;
	clients[0].name = "Bob Jones";
	clients[0].phone = "8123456789";
	clients[0].count_cat = 2;
	clients[0].cats = new Cat[clients[0].count_cat];

	clients[0].cats[0].id = 1;
	clients[0].cats[0].name = "Moris";
	clients[0].cats[0].color = "white";
	clients[0].cats[0].breed = "Maine Coon";
	clients[0].cats[0].age = 2;

	clients[0].cats[0].card.id = 1;
	clients[0].cats[0].card.count_records = 0;

	clients[0].cats[1].id = 2;
	clients[0].cats[1].name = "Boris";
	clients[0].cats[1].color = "grey";
	clients[0].cats[1].breed = "Scottish Fold";
	clients[0].cats[1].age = 3;

	clients[0].cats[1].card.id = 2;
	clients[0].cats[1].card.count_records = 0;

	clients[1].id = 2;
	clients[1].name = "Jim Smith";
	clients[1].phone = "8123456781";
	clients[1].count_cat = 1;
	clients[1].cats = new Cat[clients[1].count_cat];

	clients[1].cats[0].id = 3;
	clients[1].cats[0].name = "Doris";
	clients[1].cats[0].color = "grey";
	clients[1].cats[0].breed = "Chartreux";
	clients[1].cats[0].age = 2;

	clients[1].cats[0].card.id = 3;
	clients[1].cats[0].card.count_records = 0;

	do {
		show_menu();

		cin >> menu_choice;

		switch (menu_choice) {
		case '1':
			show_clients(clients);
			break;
		case '2':
			show_cats(clients);
			break;
		case '3':
			cout << "Enter Cat ID: ";
			cin >> menu_choice;
			show_cat_by_id(clients, convert_char_to_int(menu_choice));
			break;
		case '4':
			cout << "Enter Client ID: ";
			cin >> menu_choice;

			show_cat_by_client_id(clients, convert_char_to_int(menu_choice));
			break;
		case '5':
			cout << "Enter Cat ID: ";
			cin >> menu_choice;
			fill_health_information(clients, convert_char_to_int(menu_choice));
			break;
		case '6':
			cout << "Enter Client ID: ";
			cin >> menu_choice;
			fill_health_information_by_client_id(clients, convert_char_to_int(menu_choice));
			break;
		case '0':
			break;
		default:
			cout << "Wrong choice. Please enter again" << endl;
		}

	} while (menu_choice != '0');

	return 0;
}