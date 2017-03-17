#include <stdlib.h>
#include <stdio.h>
#include <conio.h>



int SIZE = 5;


struct contact {
	char name[40];
	int tel_number;
} ;

void enter(), init_list(), show();
void update(), input(int i);
void find(), del();
int menu(), mystrcmp(char a[], char b[]);

contact * reference;


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

	printf("vvedite imya: ");
	scanf_s("%s", name, _countof(name));

	for (i = 0; i < SIZE; i++)
	if (mystrcmp(name, reference[i].name)) break;

	if (i == SIZE) {
		printf("kontakt ne naiden: ");
		return;
	}

*reference[i].name = '\0';
}

int menu()
{
	char ch;
	

	printf("\n");
	printf("(e)nter\n");
	printf("(s)how\n");
	printf("(d)elete\n");
	printf("(f)ind\n");
	printf("(u)pdte\n");
	printf("(q)uit\n\n");
	printf("vyberite komandu");
	ch = _getch();
	

	return ch;
}

void enter()
{
	int i;
	for (i = 0; i < SIZE; i++)
	if (!*reference[i].name) break;

	if (i == SIZE){
		SIZE++;
		reference = (contact *) realloc(reference, SIZE*sizeof(contact));
		*reference[i].name = '\0';
		
	}

	input(i);
	
}

void input(int i)
{
	printf("imya: ");
	scanf_s("%s", reference[i].name, _countof(reference[i].name));

	printf("nomer telefona: ");
	scanf_s("%d", &reference[i].tel_number, 5);

}

void update()
{
	int i;
	char name[80];

	printf("vvedite imya: ");
	scanf_s("%s", name, _countof(name));

	for (i = 0; i < SIZE; i++)
	if (mystrcmp(name, reference[i].name)) break;

	if (i == SIZE) {
		printf("kontakt ne naiden: ");
		return;
	}
	printf("vvedite novuy informaciy: \n");
	input(i);
}

void show()
{
	int t;

	for (t = 0; t < SIZE; t++) {
		if (*reference[t].name) {
			printf("%s %d",reference[t].name, reference[t].tel_number);	
			printf("\n");
		}
	}
}

void find()
{
	int t;
	char name[40];
	printf("vvedite imya: \n");
	scanf_s("%s", name, _countof(name));
	for (t = 0; t < SIZE; t++){
		if (mystrcmp(name, reference[t].name)){
			break;
		}
	}
	printf("%s %d", reference[t].name, reference[t].tel_number);
	printf("\n");
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
