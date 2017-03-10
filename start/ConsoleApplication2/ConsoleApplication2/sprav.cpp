#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

const int SIZE = 100;

struct contact {
	char name[40];
	int tel_number;
} ;

void enter(), init_list(), show();
void update(), input(int i);
void find(), del();
int menu(), mystrcmp(char a[], char b[]);

contact *reference;


int main()
{
	reference = (contact *)malloc(SIZE*sizeof(contact));
	
	char choice;

	init_list();

	for (;;){
		choice = menu();
		switch (choice){
		case 'e': enter();
			break;
		case 's': show();
			break;
		case 'f': find();
			break;
		case 'd': del();
			break;
		case 'u': update();
			break;
		case 'q': free(reference);
			return 0;
		}
	}
}

void init_list()
{
	int t;

	for (t = 0; t < SIZE; t++) *reference[t].name = '\0';
}

void del()
{
	int i;
	char name[80];

	cout << "vvedite imya: ";
	cin >> name;

	for (i = 0; i < SIZE; i++)
	if (mystrcmp(name, reference[i].name)) break;

	if (i == SIZE) {
		cout << "kontakt ne naiden: ";
		return;
	}

*reference[i].name = '\0';
}

int menu()
{
	char ch;
	

	cout << '\n';
	cout << "(e)nter\n";
	cout << "(s)how\n";
	cout << "(d)elete\n";
	cout << "(f)ind\n";
	cout << "(u)pdte\n";
	cout << "(q)uit\n\n";
	cout << "vyberite komandu";
	cin >> ch;


	return ch;
}

void enter()
{
	int i;
	for (i = 0; i < SIZE; i++)
	if (!*reference[i].name) break;

	if (i == SIZE){
		cout << "spisok polon.\n";
		return;
	}

	input(i);
}

void input(int i)
{
	cout << "imya: ";
	cin >> reference[i].name;	

	cout << "nomer telefona: ";
	cin >> reference[i].tel_number;

}

void update()
{
	int i;
	char name[80];

	cout << "vvedite imya: ";
	cin >> name;

	for (i = 0; i < SIZE; i++)
	if (mystrcmp(name, reference[i].name)) break;

	if (i == SIZE) {
		cout << "kontakt ne naiden: ";
		return;
	}
	cout << "vvedite novuy informaciy: \n";
	input(i);
}

void show()
{
	int t;

	for (t = 0; t < SIZE; t++) {
		if (*reference[t].name) {
			cout << reference[t].name << " " << reference[t].tel_number << "\n";	
		}
	}
}

void find()
{
	int t;
	char name[40];
	cout << "vvedite imya: \n";
	cin >> name;
	for (t = 0; t < SIZE; t++){
		if (mystrcmp(name, reference[t].name)){
			break;
		}
	}
	cout << reference[t].name << reference[t].tel_number << "\n";
}

int mystrcmp(char a[], char b[])
{
	int r = 1;
	int i;
	for (i = 0; a[i] != '\0'; i++){
		if (a[i] != b[i]){
			r = 0;
			break;
		}
		
	}
	return r;
}