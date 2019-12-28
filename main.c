#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
#include<time.h>
#include<MMsystem.h>

struct User {
	char ID[7];
	char Nama[50];
	char Warna[10];
	unsigned int Score;
	char Urutan;
};

struct Com {
	char ID[7];
	char Nama[50];
	char Warna[10];
	char Urutan;
	char Personality[10];
};

struct Bidak {
	char ID[5];
	char ID_Pemilik[5];
	char Lokasi;
	char Status[10];
};

void gotoxy(int x, int y);
void setcolor(unsigned short color);
void mainMenu();
void inputUserData();
void generateUserData(char a[50], char b, struct User *c);
void generateComData(struct Com a, struct Com b, struct Com c, struct User e, char d);
void resetComData(struct Com *Com1, struct Com *Com2, struct Com *Com3);
void generateCom1(struct Com *Com1, struct User pemain);
void generateCom2(struct Com *Com2, struct Com Com1, struct User pemain);
void generateCom3(struct Com *Com3, struct Com Com2, struct User pemain);
void printData(struct User pemain, struct Com Com1, struct Com Com2, struct Com Com3);


void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setcolor(unsigned short color)
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

void mainMenu()
{
	char tampungInput;
	do
	{
		system("cls");
		printf("1. Main gan");
		printf("\n2. Credit");
		printf("\n3. Exit");
		printf("\nPilih: ");
		tampungInput = getche();	
	}while(!(tampungInput == '1' || tampungInput == '2' || tampungInput == '3'));
	
	switch(tampungInput)
	{
		case '1':
			inputUserData();
			break;
		case '2':
			break;
		case '3':
			break;
		default :
			break;
	}
}

void inputUserData()
{
	struct User pemain;
	struct Com Com1, Com2, Com3;
	char Nama[50], pilihWarna, jmlCom;
	
	resetComData(&Com1, &Com2, &Com3);
	system("cls");
	printf("Masukkan nama anda (tanpa spasi) : ");gets(Nama);
	system("cls");
	printf("1. Merah");
	printf("\n2. Kuning");
	printf("\n3. Hijau");
	printf("\n4. Biru");
	printf("\nInputkan nomor warna yang anda inginkan : ");scanf("%c", &pilihWarna);
	system("cls");
	printf("Inputkan berapa banyak com yang akan anda lawan (1-3) : ");
	jmlCom = getche();
	generateUserData(Nama, pilihWarna, &pemain);
	generateComData(Com1, Com2, Com3, pemain, jmlCom);
}

void resetComData(struct Com *Com1, struct Com *Com2, struct Com *Com3)
{
	strcpy((*Com1).Nama, "NONE");
	strcpy((*Com2).Nama, "NONE");
	strcpy((*Com3).Nama, "NONE");
}

void generateUserData(char Nama[50], char pilihWarna, struct User *pemain)
{
	strcpy((*pemain).ID, "USR18");
	strcpy((*pemain).Nama, Nama);
	switch(pilihWarna)
	{
		case '1':
			strcpy((*pemain).Warna, "Merah");
			break;
		case '2':
			strcpy((*pemain).Warna, "Kuning");
			break;
		case '3':;
			strcpy((*pemain).Warna, "Hijau");
			break;
		case '4':
			strcpy((*pemain).Warna, "Biru");
			break;
	}
	(*pemain).Score = 0;
}

void generateComData(struct Com Com1, struct Com Com2, struct Com Com3, struct User pemain, char jmlCom)
{
	switch(jmlCom)
	{
		case '1':
			generateCom1(&Com1, pemain);
			break;
		case '2':
			generateCom1(&Com1, pemain);
			generateCom2(&Com2, Com1, pemain);
			break;
		case '3':
			generateCom1(&Com1, pemain);
			generateCom2(&Com2, Com1, pemain);
			generateCom3(&Com3, Com2, pemain);
			break;
	}
	printData(pemain, Com1, Com2, Com3);
}

void generateCom1(struct Com *Com1, struct User pemain)
{
	strcpy((*Com1).ID, "COM01");
	strcpy((*Com1).Nama, "Bidjie");
	strcpy((*Com1).Personality, "NOOBZ");
	if(strcmp(pemain.Warna, "Merah") == 0)
	{
		strcpy((*Com1).Warna, "Kuning");
	} else
	{
		strcpy((*Com1).Warna, "Merah");
	}
}

void generateCom2(struct Com *Com2, struct Com Com1, struct User pemain)
{
	strcpy((*Com2).ID, "COM02");
	strcpy((*Com2).Nama, "Kvda");
	strcpy((*Com2).Personality, "Lumayan");
	if((strcmp(pemain.Warna, "Kuning") == 0) || (strcmp(Com1.Warna, "Kuning") == 0))
	{
		strcpy((*Com2).Warna, "Hijau");
	} else
	{
		strcpy((*Com2).Warna, "Kuning");
	}
}

void generateCom3(struct Com *Com3, struct Com Com2, struct User pemain)
{
	strcpy((*Com3).ID, "COM03");
	strcpy((*Com3).Nama, "Zeki");
	strcpy((*Com3).Personality, "GGPRO");
	if((strcmp(pemain.Warna, "Hijau") == 0) || (strcmp(Com2.Warna, "Hijau") == 0))
	{
		strcpy((*Com3).Warna, "Biru");
	} else
	{
		strcpy((*Com3).Warna, "Hijau");
	}
}

void printData(struct User pemain, struct Com Com1, struct Com Com2, struct Com Com3)
{
	printf("\n%s si %s vs %s si %s vs %s si %s vs %s si %s ", pemain.Nama, pemain.Warna, Com1.Nama, Com1.Warna, Com2.Nama, Com2.Warna, Com3.Nama, Com3.Warna);
}

void randomUrutan()
{
	
}

int main() {
	mainMenu();
	return 0;
	
}
