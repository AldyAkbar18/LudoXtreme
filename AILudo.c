#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<windows.h>

struct Bidak {
	char ID[5];
	char ID_Pemilik[5];
	int Lokasi;
	char Status[10];
};


struct User {
	char ID[7];
	char Nama[50];
	char Warna[10];
	unsigned int Score;
	struct Bidak BidakUser[4];
};

struct Com {
	char ID[7];
	char Nama[50];
	char Warna[10];
	char Personality[10];
	struct Bidak BidakCom[4];
};

char sa[10], sb[10], sc[10], sd[10];
int a=10, b=0, c=0, d=0;
int ua=0, ub = 20, uc= 3, ud = 7;
int finish = 73;
void data(struct User pemain, struct Com Com1, struct Com Com2, struct Com Com3, int urutan);
void userChoice(struct User *pemain, struct Com *Com1, struct Com *Com2, struct Com *Com3, int langkah, int urutan);
void gotoxy(int x, int y);
void userOutPawn(struct User *pemain, int langkah);
void userMovePawn(struct User *pemain, int langkah);
void showCom1Data(struct Com Com1);
void showCom3Data(struct Com Com2);
void maju(struct User *pemain, struct Com *Com1, struct Com *Com2, struct Com *Com3, int langkah, int urutan);
void cekPosisi(int a, char *b);
int max4Value(int value1, int value2, int value3, int value4);

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
	struct Com Com1, Com2, Com3;
	struct User pemain;
	struct Bidak BidakUser[4], BidakCom1[4], BidakCom2[4], BidakCom3[4];
	int urutan = 1;
	
	strcpy(pemain.ID, "USR18");
	strcpy(pemain.Nama, "Afdal");
	pemain.Score = 0;
	strcpy(pemain.Warna, "Merah");
	
	strcpy(Com1.ID, "COM1");
	strcpy(Com1.Nama, "Bidjie");
	strcpy(Com1.Personality, "GGPRO");
	strcpy(Com1.Warna, "Kuning");
	
	strcpy(Com2.ID, "COM2");
	strcpy(Com2.Nama, "Jek");
	strcpy(Com2.Personality, "Lumayan");
	strcpy(Com2.Warna, "Hijau");
	
	strcpy(Com3.ID, "COM3");
	strcpy(Com3.Nama, "Kvda");
	strcpy(Com3.Personality, "NOOBZ");
	strcpy(Com3.Warna, "Biru");
	
	strcpy(pemain.BidakUser[0].ID, "BU01");
	strcpy(pemain.BidakUser[0].ID_Pemilik, "USR18");
	strcpy(pemain.BidakUser[0].Status, "HOME");
	pemain.BidakUser[0].Lokasi = 0;
	strcpy(pemain.BidakUser[1].ID, "BU02");
	strcpy(pemain.BidakUser[1].ID_Pemilik, "USR18");
	strcpy(pemain.BidakUser[1].Status, "HOME");
	pemain.BidakUser[1].Lokasi = 0;
	strcpy(pemain.BidakUser[2].ID, "BU03");
	strcpy(pemain.BidakUser[2].ID_Pemilik, "USR18");
	strcpy(pemain.BidakUser[2].Status, "HOME");
	pemain.BidakUser[2].Lokasi = 0;
	strcpy(pemain.BidakUser[3].ID, "BU04");
	strcpy(pemain.BidakUser[3].ID_Pemilik, "USR18");
	strcpy(pemain.BidakUser[3].Status, "HOME");
	pemain.BidakUser[3].Lokasi = 0;
	
	strcpy(Com1.BidakCom[0].ID, "C101");
	strcpy(Com1.BidakCom[0].ID_Pemilik, "COM01");
	strcpy(Com1.BidakCom[0].Status, "HOME");
	Com1.BidakCom[0].Lokasi = 0;
	strcpy(Com1.BidakCom[1].ID, "C102");
	strcpy(Com1.BidakCom[1].ID_Pemilik, "COM01");
	strcpy(Com1.BidakCom[1].Status, "HOME");
	Com1.BidakCom[1].Lokasi = 0;
	strcpy(Com1.BidakCom[2].ID, "C103");
	strcpy(Com1.BidakCom[2].ID_Pemilik, "COM01");
	strcpy(Com1.BidakCom[2].Status, "HOME");
	Com1.BidakCom[2].Lokasi = 0;
	strcpy(Com1.BidakCom[3].ID, "C104");
	strcpy(Com1.BidakCom[3].ID_Pemilik, "COM01");
	strcpy(Com1.BidakCom[3].Status, "HOME");
	Com1.BidakCom[3].Lokasi = 0;
	
	strcpy(Com2.BidakCom[0].ID, "C201");
	strcpy(Com2.BidakCom[0].ID_Pemilik, "COM02");
	strcpy(Com2.BidakCom[0].Status, "HOME");
	Com2.BidakCom[0].Lokasi = 0;
	strcpy(Com2.BidakCom[1].ID, "C202");
	strcpy(Com2.BidakCom[1].ID_Pemilik, "COM02");
	strcpy(Com2.BidakCom[1].Status, "HOME");
	Com2.BidakCom[1].Lokasi = 0;
	strcpy(Com2.BidakCom[2].ID, "C203");
	strcpy(Com2.BidakCom[2].ID_Pemilik, "COM02");
	strcpy(Com2.BidakCom[2].Status, "HOME");
	Com2.BidakCom[2].Lokasi = 0;
	strcpy(Com2.BidakCom[3].ID, "C204");
	strcpy(Com2.BidakCom[3].ID_Pemilik, "COM02");
	strcpy(Com2.BidakCom[3].Status, "HOME");
	Com2.BidakCom[3].Lokasi = 0;
	
	strcpy(Com3.BidakCom[0].ID, "C301");
	strcpy(Com3.BidakCom[0].ID_Pemilik, "COM02");
	strcpy(Com3.BidakCom[0].Status, "HOME");
	Com3.BidakCom[0].Lokasi = 0;
	strcpy(Com3.BidakCom[1].ID, "C302");
	strcpy(Com3.BidakCom[1].ID_Pemilik, "COM02");
	strcpy(Com3.BidakCom[1].Status, "HOME");
	Com3.BidakCom[1].Lokasi = 0;
	strcpy(Com3.BidakCom[2].ID, "C303");
	strcpy(Com3.BidakCom[2].ID_Pemilik, "COM02");
	strcpy(Com3.BidakCom[2].Status, "HOME");
	Com3.BidakCom[2].Lokasi = 0;
	strcpy(Com3.BidakCom[3].ID, "C304");
	strcpy(Com3.BidakCom[3].ID_Pemilik, "COM01");
	strcpy(Com3.BidakCom[3].Status, "HOME");
	Com3.BidakCom[3].Lokasi = 0;
	
	data(pemain, Com1, Com2, Com3, urutan);
	
	return 0;
}

void data(struct User pemain, struct Com Com1, struct Com Com2, struct Com Com3, int urutan)
{
	int langkah, i;
	
	system("cls");
	
	if( urutan==1 )
	{
		gotoxy(32,1);
	} else if( urutan==2 )
	{
		gotoxy(75,1);
	} else if( urutan==3 )
	{
		gotoxy(32,9);
	} else
	{
		gotoxy(75,9);
	}
	printf("%s", "PLAYING");
	gotoxy(0,0);
	printf("%c", 218);
	for( i=0; i<82; i++)
	{
		if(i==39)
		{
			printf("%c", 194);
		} else
		{
			printf("%c", 196);
		}
	}
	printf("%c", 191);
	printf("\n");
	printf("%c USER\n", 179);
	printf("%c Nama    : %s\n", 179, pemain.Nama);
	printf("%c Posisi Bidak\n", 179);
	printf("%c Bidak 1 : %d\n", 179, pemain.BidakUser[0].Lokasi);
	printf("%c Bidak 2 : %d\n", 179, pemain.BidakUser[1].Lokasi);
	printf("%c Bidak 3 : %d\n", 179, pemain.BidakUser[2].Lokasi);
	printf("%c Bidak 4 : %d\n", 179, pemain.BidakUser[3].Lokasi);
	printf("%c", 195);
	for( i=0; i<82; i++)
	{
		printf("%c", 196);
	}
	printf("%c\n", 180);
	printf("%c COM 2\n", 179);
	printf("%c Nama    : %s\n", 179, Com2.Nama);
	printf("%c Posisi Bidak\n", 179);
	printf("%c Bidak 1 : %d\n", 179, Com2.BidakCom[0].Lokasi);
	printf("%c Bidak 2 : %d\n", 179, Com2.BidakCom[1].Lokasi);
	printf("%c Bidak 3 : %d\n", 179, Com2.BidakCom[2].Lokasi);
	printf("%c Bidak 4 : %d\n", 179, Com2.BidakCom[3].Lokasi);
	printf("%c", 192);
	for( i=0; i<82; i++)
	{
		if(i==39)
		{
			printf("%c", 193);
		} else
		{
			printf("%c", 196);
		}
	}
	printf("%c\n", 217);
	for( i=0; i<15; i++)
	{
		gotoxy(40,i+1);
		if(i==7)
		{
			printf("%c\n", 197);
		} else
		{
			printf("%c\n", 179);
		}
	}
	for( i=0; i<15; i++)
	{
		gotoxy(83,i+1);
		if(i==7)
		{
			printf("%c\n", 180);
		} else
		{
			printf("%c\n", 179);
		}
		
	}
	showCom1Data(Com1);
	showCom3Data(Com3);
	gotoxy(0,17);
	printf("Masukkan jumlah langkah yang ingin dilakukan : ");scanf("%d", &langkah);
	if( urutan==1 )
	{
		userChoice(&pemain, &Com1, &Com2, &Com3, langkah, urutan);
	} else
	{
		maju(&pemain, &Com1, &Com2, &Com3, langkah, urutan);
	}
}

void showCom1Data(struct Com Com1)
{
	gotoxy(42,1);
	printf("COM 1");
	gotoxy(42,2);
	printf("Nama    : %s", Com1.Nama);
	gotoxy(42,3);
	printf("Posisi Bidak");
	gotoxy(42,4);
	printf("Bidak 1 : %d", Com1.BidakCom[0].Lokasi);
	gotoxy(42,5);
	printf("Bidak 2 : %d", Com1.BidakCom[1].Lokasi);
	gotoxy(42,6);
	printf("Bidak 3 : %d", Com1.BidakCom[2].Lokasi);
	gotoxy(42,7);
	printf("Bidak 4 : %d", Com1.BidakCom[3].Lokasi);
}

void showCom3Data(struct Com Com3)
{
	gotoxy(42,9);
	printf("COM 3");
	gotoxy(42,10);
	printf("Nama    : %s", Com3.Nama);
	gotoxy(42,11);
	printf("Posisi Bidak");
	gotoxy(42,12);
	printf("Bidak 1 : %d", Com3.BidakCom[0].Lokasi);
	gotoxy(42,13);
	printf("Bidak 2 : %d", Com3.BidakCom[1].Lokasi);
	gotoxy(42,14);
	printf("Bidak 3 : %d", Com3.BidakCom[2].Lokasi);
	gotoxy(42,15);
	printf("Bidak 4 : %d", Com3.BidakCom[3].Lokasi);
}

void userChoice(struct User *pemain, struct Com *Com1, struct Com *Com2, struct Com *Com3,int langkah, int urutan)
{
	int pilihBidak;
	if(langkah == 6)
	{
		if( (*pemain).BidakUser[0].Lokasi==0 && (*pemain).BidakUser[1].Lokasi==0 && (*pemain).BidakUser[2].Lokasi==0 && (*pemain).BidakUser[3].Lokasi==0 )
		{
			userOutPawn(pemain, langkah);
		} else if( (*pemain).BidakUser[0].Lokasi!=0 && (*pemain).BidakUser[1].Lokasi!=0 && (*pemain).BidakUser[2].Lokasi!=0 && (*pemain).BidakUser[3].Lokasi!=0 )
		{
			userMovePawn(pemain, langkah);
		} else
		{
			printf("1. Keluarkan bidak dari dalam homebase\n");
			printf("2. Gerakkan bidak yang berada di lintasan\n");
			printf("Tindakan apa yang ingin anda lakukan? : ");scanf("%d", &pilihBidak);
			if(pilihBidak == 1)
			{
				userOutPawn(pemain, langkah);
			} else
			{
				userMovePawn(pemain, langkah);
			}
		}
	} else
	{
		if( strcmp((*pemain).BidakUser[0].Status, "JALAN")==0 || strcmp((*pemain).BidakUser[1].Status, "JALAN")==0 || strcmp((*pemain).BidakUser[2].Status, "JALAN")==0 || strcmp((*pemain).BidakUser[3].Status, "JALAN")==0 )
		{
			userMovePawn(pemain, langkah);
		} else
		{
			printf("Seluruh bidak masih berada di dalam Homebase");
			getch();
		}
	}
	
	urutan+=1;
	
	data(*pemain, *Com1, *Com2, *Com3, urutan);
	
}

void userOutPawn(struct User *pemain, int langkah)
{
	int pilihBidak;
	char status[20];
	printf("Inputkan no bidak yang ingin anda keluarkan : ");scanf("%d", &pilihBidak);
	if( pilihBidak==1 )
	{
		if( (*pemain).BidakUser[0].Lokasi!=0 )
		{
			printf("Bidak sudah berada di luar homebase\n");
			system("pause");
			userOutPawn(pemain, langkah);
		} else
		{
			(*pemain).BidakUser[0].Lokasi = 1;
			cekPosisi((*pemain).BidakUser[0].Lokasi, status);
			strcpy((*pemain).BidakUser[0].Status, status);
		}
	} else if( pilihBidak==2 )
	{
		if( (*pemain).BidakUser[1].Lokasi!=0 )
		{
			printf("Bidak sudah berada di luar homebase\n");
			system("pause");
			userOutPawn(pemain, langkah);
		} else
		{
			(*pemain).BidakUser[1].Lokasi = 1;
			cekPosisi((*pemain).BidakUser[1].Lokasi, status);
			strcpy((*pemain).BidakUser[1].Status, status);
		}
	} else if( pilihBidak==3 )
	{
		if( (*pemain).BidakUser[2].Lokasi!=0 )
		{
			printf("Bidak sudah berada di luar homebase\n");
			system("pause");
			userOutPawn(pemain, langkah);
		} else
		{
			(*pemain).BidakUser[2].Lokasi = 1;
			cekPosisi((*pemain).BidakUser[2].Lokasi, status);
			strcpy((*pemain).BidakUser[2].Status, status);
		}
	} else if( pilihBidak==4 )
	{
		if( (*pemain).BidakUser[3].Lokasi!=0 )
		{
			printf("Bidak sudah berada di luar homebase\n");
			system("pause");
			userOutPawn(pemain, langkah);
		} else
		{
			(*pemain).BidakUser[3].Lokasi = 1;
			cekPosisi((*pemain).BidakUser[3].Lokasi, status);
			strcpy((*pemain).BidakUser[3].Status, status);
		}
	}
}

void userMovePawn(struct User *pemain, int langkah)
{
	int pilihBidak;
	char status[20];
	printf("Inputkan no bidak yang ingin anda majukan (1-4) : ");scanf("%d", &pilihBidak);
	if( pilihBidak==1 )
	{
		if( (*pemain).BidakUser[0].Lokasi==0 )
		{
			printf("Bidak tidak dapat dikeluarkan karena masih berada di dalam homebase\n");
			getch();
			userMovePawn(pemain, langkah);
		} else
		{
			if( (*pemain).BidakUser[0].Lokasi+langkah>73 )
			{
				(*pemain).BidakUser[0].Lokasi = 73;
				strcpy((*pemain).BidakUser[0].Status, "FINISH");
			} else
			{
				(*pemain).BidakUser[0].Lokasi += langkah;
				cekPosisi((*pemain).BidakUser[0].Lokasi, status);
				strcpy((*pemain).BidakUser[0].Status, status);
			}
		}
	} else if( pilihBidak==2 )
	{
		if( (*pemain).BidakUser[1].Lokasi==0 )
		{
			printf("Bidak tidak dapat dikeluarkan karena masih berada di dalam homebase\n");
			getch();
			userMovePawn(pemain, langkah);
		} else
		{
			if( (*pemain).BidakUser[1].Lokasi+langkah>73 )
			{
				(*pemain).BidakUser[1].Lokasi = 73;
				strcpy((*pemain).BidakUser[1].Status, "FINISH");
			} else
			{
				(*pemain).BidakUser[1].Lokasi += langkah;
				cekPosisi((*pemain).BidakUser[1].Lokasi, status);
				strcpy((*pemain).BidakUser[1].Status, status);
			}
		}
	} else if( pilihBidak==3 )
	{
		if( (*pemain).BidakUser[2].Lokasi==0 )
		{
			printf("Bidak tidak dapat dikeluarkan karena masih berada di dalam homebase\n");
			getch();
			userMovePawn(pemain, langkah);
		} else
		{
			if( (*pemain).BidakUser[2].Lokasi+langkah>73 )
			{
				(*pemain).BidakUser[2].Lokasi = 73;
				strcpy((*pemain).BidakUser[2].Status, "FINISH");
			} else
			{
				(*pemain).BidakUser[2].Lokasi += langkah;
				cekPosisi((*pemain).BidakUser[2].Lokasi, status);
				strcpy((*pemain).BidakUser[1].Status, status);
			}
		}
	} else if( pilihBidak==4 )
	{
		if( (*pemain).BidakUser[3].Lokasi==0 )
		{
			printf("Bidak tidak dapat dikeluarkan karena masih berada di dalam homebase\n");
			getch();
			userMovePawn(pemain, langkah);
		} else
		{
			if( (*pemain).BidakUser[3].Lokasi+langkah>73 )
			{
				(*pemain).BidakUser[3].Lokasi = 73;
				strcpy((*pemain).BidakUser[3].Status, "FINISH");
			} else
			{
				(*pemain).BidakUser[3].Lokasi += langkah;
				cekPosisi((*pemain).BidakUser[3].Lokasi, status);
				strcpy((*pemain).BidakUser[1].Status, status);
			}
		}
	}
}

void maju(struct User *pemain, struct Com *Com1, struct Com *Com2, struct Com *Com3, int langkah, int urutan)
{
	if( urutan==2 )
	{
		if( langkah==6 )
		{
			if( (*Com1).BidakCom[0].Lokasi==0 )
			{
				(*Com1).BidakCom[0].Lokasi = 1;
				cekPosisi((*Com1).BidakCom[0].Lokasi, sa);
				strcpy((*Com1).BidakCom[0].Status, sa);
				
			} else if( ((*Com1).BidakCom[1].Lokasi==0) && ((*Com1).BidakCom[0].Lokasi==finish) )
			{
				(*Com1).BidakCom[1].Lokasi = 1;
				cekPosisi((*Com1).BidakCom[1].Lokasi, sb);
				strcpy((*Com1).BidakCom[1].Status, sb);
			}
			else if( ((*Com1).BidakCom[2].Lokasi==0) && ((*Com1).BidakCom[1].Lokasi==finish) && ((*Com1).BidakCom[0].Lokasi==finish) )
			{
				(*Com1).BidakCom[2].Lokasi = 1;
				cekPosisi((*Com1).BidakCom[2].Lokasi, sc);
				strcpy((*Com1).BidakCom[2].Status, sc);
			}
			else if( ((*Com1).BidakCom[3].Lokasi==0) && ((*Com1).BidakCom[2].Lokasi==finish) && ((*Com1).BidakCom[1].Lokasi==finish) && ((*Com1).BidakCom[0].Lokasi==finish) )
			{
				(*Com1).BidakCom[3].Lokasi = 1;
				cekPosisi((*Com1).BidakCom[3].Lokasi, sd);
				strcpy((*Com1).BidakCom[3].Status, sd);
			} else if ( (((*Com1).BidakCom[0].Lokasi!=0) || ((*Com1).BidakCom[0].Lokasi!= finish)) && strcmp((*Com1).BidakCom[0].Status, "FINISH") != 0 )
			{
				if((*Com1).BidakCom[0].Lokasi+langkah >=73)
				{
					(*Com1).BidakCom[0].Lokasi = 73;
				} else
				{
					(*Com1).BidakCom[0].Lokasi += langkah;
				}
				cekPosisi((*Com1).BidakCom[0].Lokasi, sa);
				strcpy((*Com1).BidakCom[0].Status, sa);
			} else if ( (((*Com1).BidakCom[1].Lokasi!=0) || ((*Com1).BidakCom[1].Lokasi!= finish)) && strcmp((*Com1).BidakCom[1].Status, "FINISH") != 0 )
			{
				if((*Com1).BidakCom[1].Lokasi+langkah >=73)
				{
					(*Com1).BidakCom[1].Lokasi = 73;
				} else
				{
					(*Com1).BidakCom[1].Lokasi += langkah;
				}
				cekPosisi((*Com1).BidakCom[1].Lokasi, sb);
				strcpy((*Com1).BidakCom[1].Status, sb);
			} else if ( (((*Com1).BidakCom[2].Lokasi!=0) || ((*Com1).BidakCom[2].Lokasi!= finish)) && strcmp((*Com1).BidakCom[2].Status, "FINISH") != 0 )
			{
				if((*Com1).BidakCom[2].Lokasi+langkah >=73)
				{
					(*Com1).BidakCom[2].Lokasi = 73;
				} else
				{
					(*Com1).BidakCom[2].Lokasi += langkah;
				}
				cekPosisi((*Com1).BidakCom[2].Lokasi, sc);
				strcpy((*Com1).BidakCom[2].Status, sc);
			} else if ( (((*Com1).BidakCom[3].Lokasi!=0) || ((*Com1).BidakCom[3].Lokasi!= finish)) && strcmp((*Com1).BidakCom[3].Status, "FINISH") != 0 )
			{
				if((*Com1).BidakCom[3].Lokasi+langkah >=73)
				{
					(*Com1).BidakCom[3].Lokasi = 73;
				} else
				{
					(*Com1).BidakCom[3].Lokasi += langkah;
				}
				cekPosisi((*Com1).BidakCom[3].Lokasi, sd);
				strcpy((*Com1).BidakCom[3].Status, sd);
			}
		} else if( (((*Com1).BidakCom[0].Lokasi!=0) && strcmp((*Com1).BidakCom[0].Status, "FINISH") != 0) || (((*Com1).BidakCom[1].Lokasi!=0) && strcmp((*Com1).BidakCom[1].Status, "FINISH") != 0) || (((*Com1).BidakCom[2].Lokasi!=0) && strcmp((*Com1).BidakCom[2].Status, "FINISH") != 0) || (((*Com1).BidakCom[3].Lokasi!=0) && strcmp((*Com1).BidakCom[3].Status, "FINISH") != 0) )
		{
			if ( (((*Com1).BidakCom[0].Lokasi!=0) || ((*Com1).BidakCom[0].Lokasi!= finish)) && strcmp((*Com1).BidakCom[0].Status, "FINISH") != 0 )
			{
				if((*Com1).BidakCom[0].Lokasi+langkah >=73)
				{
					(*Com1).BidakCom[0].Lokasi = 73;
				} else
				{
					(*Com1).BidakCom[0].Lokasi += langkah;
				}
				cekPosisi((*Com1).BidakCom[0].Lokasi, sa);
				strcpy((*Com1).BidakCom[0].Status, sa);
			} else if ( (((*Com1).BidakCom[1].Lokasi!=0) || ((*Com1).BidakCom[1].Lokasi!= finish)) && strcmp((*Com1).BidakCom[1].Status, "FINISH") != 0 )
			{
				if((*Com1).BidakCom[1].Lokasi+langkah >=73)
				{
					(*Com1).BidakCom[1].Lokasi = 73;
				} else
				{
					(*Com1).BidakCom[1].Lokasi += langkah;
				}
				cekPosisi((*Com1).BidakCom[1].Lokasi, sb);
				strcpy((*Com1).BidakCom[1].Status, sb);
			} else if ( (((*Com1).BidakCom[2].Lokasi!=0) || ((*Com1).BidakCom[2].Lokasi!= finish)) && strcmp((*Com1).BidakCom[2].Status, "FINISH") != 0 )
			{
				if((*Com1).BidakCom[2].Lokasi+langkah >=73)
				{
					(*Com1).BidakCom[2].Lokasi = 73;
				} else
				{
					(*Com1).BidakCom[2].Lokasi += langkah;
				}
				cekPosisi((*Com1).BidakCom[2].Lokasi, sc);
				strcpy((*Com1).BidakCom[2].Status, sc);
			} else if ( (((*Com1).BidakCom[3].Lokasi!=0) || ((*Com1).BidakCom[3].Lokasi!= finish)) && strcmp((*Com1).BidakCom[3].Status, "FINISH") != 0 )
			{
				if((*Com1).BidakCom[3].Lokasi+langkah >=73)
				{
					(*Com1).BidakCom[3].Lokasi = 73;
				} else
				{
					(*Com1).BidakCom[3].Lokasi += langkah;
				}
				cekPosisi((*Com1).BidakCom[3].Lokasi, sd);
				strcpy((*Com1).BidakCom[3].Status, sd);
			}
		}
	} else if(urutan == 3)
	{
		int max, jarak1, jarak2, jarak3, jarak4;
		if( langkah==6 )
		{
			if( a==0 )
			{
				a = 1;
				cekPosisi(a, sa);
			} else if( a!=0 && b==0 )
			{
				b = 1;
				cekPosisi(b, sb);
			} else if( a!=0 && b!=0 && c==0 )
			{
				c = 1;
				cekPosisi(c, sc);
			} else if( a!=0 && b!=0 && c!=0 && d==0 )
			{
				d = 1;
				cekPosisi(d, sd);
			} else 
			{
				if(strcmp(sa, "HOME") == 0)
				{
					jarak1 = -1;
				} else
				{
					jarak1 = finish-a;
				}
				if(strcmp(sb, "HOME") == 0)
				{
					jarak2 = -1;
				} else
				{
					jarak2 = finish-b;
				}
				if(strcmp(sc, "HOME") == 0)
				{
					jarak3 = -1;
				} else
				{
					jarak3 = finish-c;
				}
				if(strcmp(sd, "HOME") == 0)
				{
					jarak4 = -1;
				} else
				{
					jarak4 = finish-d;
				}
				max = max4Value(jarak1, jarak2, jarak3, jarak4);
				if ( (max==jarak1) && strcmp(sa, "JALAN") == 0 )
				{
					if(a+langkah >=73)
					{
						a = 73;
					} else
					{
						a += langkah;
					}
					cekPosisi(a, sa);
				} else if ( (max==jarak2) && strcmp(sb, "JALAN") == 0 )
				{
					if(b+langkah >=73)
					{
						b = 73;
					} else
					{
						b += langkah;
					}
					cekPosisi(b, sb);
				} else if ( (max==jarak3) && strcmp(sc, "JALAN") == 0 )
				{
					if(c+langkah >=73)
					{
						c = 73;
					} else
					{
						c += langkah;
					}
					cekPosisi(c, sc);
				} else if ( (max==jarak4) && strcmp(sd, "JALAN") == 0 )
				{
					if(d+langkah >=73)
					{
						d = 73;
					} else
					{
						d += langkah;
					}
					cekPosisi(d, sd);
				}
			}
		} else
		{
			if(strcmp(sa, "HOME") == 0)
			{
				jarak1 = -1;
			} else
			{
				jarak1 = finish-a;
			}
			if(strcmp(sb, "HOME") == 0)
			{
				jarak2 = -1;
			} else
			{
				jarak2 = finish-b;
			}
			if(strcmp(sc, "HOME") == 0)
			{
				jarak3 = -1;
			} else
			{
				jarak3 = finish-c;
			}
			if(strcmp(sd, "HOME") == 0)
			{
				jarak4 = -1;
			} else
			{
				jarak4 = finish-d;
			}
			max = max4Value(jarak1, jarak2, jarak3, jarak4);
			if ( (max==jarak1) && strcmp(sa, "JALAN") == 0 )
			{
				if(a+langkah >=73)
				{
					a = 73;
				} else
				{
					a += langkah;
				}
				cekPosisi(a, sa);
			} else if ( (max==jarak2) && strcmp(sb, "JALAN") == 0 )
			{
				if(b+langkah >=73)
				{
					b = 73;
				} else
				{
					b += langkah;
				}
				cekPosisi(b, sb);
			} else if ( (max==jarak3) && strcmp(sc, "JALAN") == 0 )
			{
				if(c+langkah >=73)
				{
					c = 73;
				} else
				{
					c += langkah;
				}
				cekPosisi(c, sc);
			} else if ( (max==jarak4) && strcmp(sd, "JALAN") == 0 )
			{
				if(d+langkah >=73)
				{
					d = 73;
				} else
				{
					d += langkah;
				}
				cekPosisi(d, sd);
			}
		}
	} else if(urutan==4 )
	{
		if( langkah==6 )
		{
			if( a==0 )
			{
				a = 1;
				cekPosisi(a, sa);
			} else if( a!=0 && b==0 )
			{
				b = 1;
				cekPosisi(b, sb);
			} else if( a!=0 && b!=0 && c==0 )
			{
				c = 1;
				cekPosisi(c, sc);
			} else if( a!=0 && b!=0 && c!=0 && d==0 )
			{
				d = 1;
				cekPosisi(d, sd);
			} else 
			{
				int min;
				int jarakua_a, jarakub_a, jarakuc_a, jarakud_a;
				int jarakua_b, jarakub_b, jarakuc_b, jarakud_b;
				int jarakua_c, jarakub_c, jarakuc_c, jarakud_c;
				int jarakua_d, jarakub_d, jarakuc_d, jarakud_d;
				
				if( (ua-a<0 || ua-a<langkah) || strcmp(sa, "HOME") == 0  )
				{
					jarakua_a = 100;
				} else
				{
					jarakua_a = ua-a;
				}
				if( (ub-a<0 || ub-a<langkah) || strcmp(sa, "HOME") == 0  )
				{
					jarakub_a = 100;
				} else
				{
					jarakub_a = ub-a;
				}
				if( (uc-a<0 || uc-a<langkah) || strcmp(sa, "HOME") == 0  )
				{
					jarakuc_a = 100;
				} else
				{
					jarakuc_a = uc-a;
				}
				if( (ud-a<0 || ud-a<langkah) || strcmp(sa, "HOME") == 0  )
				{
					jarakud_a = 100;
				} else
				{
					jarakud_a = ud-a;
				}
				if( (ua-b<0 || ua-b<langkah) || strcmp(sb, "HOME") == 0  )
				{
					jarakua_b = 100;
				} else
				{
					jarakua_b = ua-b;
				}
				if( (ub-b<0 || ub-b<langkah) || strcmp(sb, "HOME") == 0  )
				{
					jarakub_b = 100;
				} else
				{
					jarakub_b = ub-b;
				}
				if( (uc-b<0 || uc-b<langkah) || strcmp(sb, "HOME") == 0  )
				{
					jarakuc_b = 100;
				} else
				{
					jarakuc_b = uc-b;
				}
				if( (ud-b<0 || ud-b<langkah) || strcmp(sb, "HOME") == 0  )
				{
					jarakud_b = 100;
				} else
				{
					jarakud_b = ud-b;
				}
				if( (ua-c<0 || ua-c<langkah) || strcmp(sc, "HOME") == 0  )
				{
					jarakua_c = 100;
				} else
				{
					jarakua_c = ua-c;
				}
				if( (ub-c<0 || ub-c<langkah) || strcmp(sc, "HOME") == 0  )
				{
					jarakub_c = 100;
				} else
				{
					jarakub_c = ub-c;
				}
				if( (uc-c<0 || uc-c<langkah) || strcmp(sc, "HOME") == 0  )
				{
					jarakuc_c = 100;
				} else
				{
					jarakuc_c = uc-c;
				}
				if( (ud-c<0 || ud-c<langkah) || strcmp(sc, "HOME") == 0  )
				{
					jarakud_c = 100;
				} else
				{
					jarakud_c = ud-c;
				}
				if( (ua-d<0 || ua-d<langkah) || strcmp(sd, "HOME") == 0  )
				{
					jarakua_d = 100;
				} else
				{
					jarakua_d = ua-d;
				}
				if( (ub-d<0 || ub-d<langkah) || strcmp(sd, "HOME") == 0  )
				{
					jarakub_d = 100;
				} else
				{
					jarakub_d = ub-d;
				}
				if( (uc-d<0 || uc-d<langkah) || strcmp(sd, "HOME") == 0  )
				{
					jarakuc_d = 100;
				} else
				{
					jarakuc_d = uc-d;
				}
				if( (ud-d<0 || ud-d<langkah) || strcmp(sd, "HOME") == 0  )
				{
					jarakud_d = 100;
				} else
				{
					jarakud_d = ud-d;
				}
				
				min = min4Value(min4Value(jarakua_a, jarakub_a, jarakuc_a, jarakud_a), min4Value(jarakua_b, jarakub_b, jarakuc_b, jarakud_b), min4Value(jarakua_c, jarakub_c, jarakuc_c, jarakud_c), min4Value(jarakua_d, jarakub_d, jarakuc_d, jarakud_d));
				
				if ( (min==jarakua_a || min==jarakub_a || min==jarakuc_a || min==jarakud_a) && strcmp(sa, "JALAN") == 0 )
				{
					if(a+langkah >=73)
					{
						a = 73;
					} else
					{
						a += langkah;
					}
					cekPosisi(a, sa);
				} else if ( (min==jarakua_b || min==jarakub_b || min==jarakuc_b || min==jarakud_b) && strcmp(sa, "JALAN") == 0 )
				{
					if(b+langkah >=73)
					{
						b = 73;
					} else
					{
						b += langkah;
					}
					cekPosisi(b, sb);
				} else if ( (min==jarakua_c || min==jarakub_c || min==jarakuc_c || min==jarakud_c) && strcmp(sc, "JALAN") == 0 )
				{
					if(c+langkah >=73)
					{
						c = 73;
					} else
					{
						c += langkah;
					}
					cekPosisi(c, sc);
				} else if ( (min==jarakua_d || min==jarakub_d || min==jarakuc_d || min==jarakud_d) && strcmp(sd, "JALAN") == 0 )
				{
					if(d+langkah >=73)
					{
						d = 73;
					} else
					{
						d += langkah;
					}
					cekPosisi(d, sd);
				}
			}
		} else
		{
			int min;
			int jarakua_a, jarakub_a, jarakuc_a, jarakud_a;
			int jarakua_b, jarakub_b, jarakuc_b, jarakud_b;
			int jarakua_c, jarakub_c, jarakuc_c, jarakud_c;
			int jarakua_d, jarakub_d, jarakuc_d, jarakud_d;
			
			if( (ua-a<0 || ua-a<langkah) || strcmp(sa, "HOME") == 0  )
			{
				jarakua_a = 100;
			} else
			{
				jarakua_a = ua-a;
			}
			if( (ub-a<0 || ub-a<langkah) || strcmp(sa, "HOME") == 0  )
			{
				jarakub_a = 100;
			} else
			{
				jarakub_a = ub-a;
			}
			if( (uc-a<0 || uc-a<langkah) || strcmp(sa, "HOME") == 0  )
			{
				jarakuc_a = 100;
			} else
			{
				jarakuc_a = uc-a;
			}
			if( (ud-a<0 || ud-a<langkah) || strcmp(sa, "HOME") == 0  )
			{
				jarakud_a = 100;
			} else
			{
				jarakud_a = ud-a;
			}
			if( (ua-b<0 || ua-b<langkah) || strcmp(sb, "HOME") == 0  )
			{
				jarakua_b = 100;
			} else
			{
				jarakua_b = ua-b;
			}
			if( (ub-b<0 || ub-b<langkah) || strcmp(sb, "HOME") == 0  )
			{
				jarakub_b = 100;
			} else
			{
				jarakub_b = ub-b;
			}
			if( (uc-b<0 || uc-b<langkah) || strcmp(sb, "HOME") == 0  )
			{
				jarakuc_b = 100;
			} else
			{
				jarakuc_b = uc-b;
			}
			if( (ud-b<0 || ud-b<langkah) || strcmp(sb, "HOME") == 0  )
			{
				jarakud_b = 100;
			} else
			{
				jarakud_b = ud-b;
			}
			if( (ua-c<0 || ua-c<langkah) || strcmp(sc, "HOME") == 0  )
			{
				jarakua_c = 100;
			} else
			{
				jarakua_c = ua-c;
			}
			if( (ub-c<0 || ub-c<langkah) || strcmp(sc, "HOME") == 0  )
			{
				jarakub_c = 100;
			} else
			{
				jarakub_c = ub-c;
			}
			if( (uc-c<0 || uc-c<langkah) || strcmp(sc, "HOME") == 0  )
			{
				jarakuc_c = 100;
			} else
			{
				jarakuc_c = uc-c;
			}
			if( (ud-c<0 || ud-c<langkah) || strcmp(sc, "HOME") == 0  )
			{
				jarakud_c = 100;
			} else
			{
				jarakud_c = ud-c;
			}
			if( (ua-d<0 || ua-d<langkah) || strcmp(sd, "HOME") == 0  )
			{
				jarakua_d = 100;
			} else
			{
				jarakua_d = ua-d;
			}
			if( (ub-d<0 || ub-d<langkah) || strcmp(sd, "HOME") == 0  )
			{
				jarakub_d = 100;
			} else
			{
				jarakub_d = ub-d;
			}
			if( (uc-d<0 || uc-d<langkah) || strcmp(sd, "HOME") == 0  )
			{
				jarakuc_d = 100;
			} else
			{
				jarakuc_d = uc-d;
			}
			if( (ud-d<0 || ud-d<langkah) || strcmp(sd, "HOME") == 0  )
			{
				jarakud_d = 100;
			} else
			{
				jarakud_d = ud-d;
			}
			
			min = min4Value(min4Value(jarakua_a, jarakub_a, jarakuc_a, jarakud_a), min4Value(jarakua_b, jarakub_b, jarakuc_b, jarakud_b), min4Value(jarakua_c, jarakub_c, jarakuc_c, jarakud_c), min4Value(jarakua_d, jarakub_d, jarakuc_d, jarakud_d));
			
			if ( (min==jarakua_a || min==jarakub_a || min==jarakuc_a || min==jarakud_a) && strcmp(sa, "JALAN") == 0 )
			{
				if(a+langkah >=73)
				{
					a = 73;
				} else
				{
					a += langkah;
				}
				cekPosisi(a, sa);
			} else if ( (min==jarakua_b || min==jarakub_b || min==jarakuc_b || min==jarakud_b) && strcmp(sa, "JALAN") == 0 )
			{
				if(b+langkah >=73)
				{
					b = 73;
				} else
				{
					b += langkah;
				}
				cekPosisi(b, sb);
			} else if ( (min==jarakua_c || min==jarakub_c || min==jarakuc_c || min==jarakud_c) && strcmp(sc, "JALAN") == 0 )
			{
				if(c+langkah >=73)
				{
					c = 73;
				} else
				{
					c += langkah;
				}
				cekPosisi(c, sc);
			} else if ( (min==jarakua_d || min==jarakub_d || min==jarakuc_d || min==jarakud_d) && strcmp(sd, "JALAN") == 0 )
			{
				if(d+langkah >=73)
				{
					d = 73;
				} else
				{
					d += langkah;
				}
				cekPosisi(d, sd);
			}
		}
	}
	
	if( urutan==2 )
	{
		urutan = 1;
	} else
	{
		urutan+=1;
	}
	
	data(*pemain, *Com1, *Com2, *Com3, urutan);
}

int max4Value(int value1, int value2, int value3, int value4)
{
	int maximum, temp_max1, temp_max2;
	
	if( value1>value2 )
	{
		temp_max1 = value1;
	} else
	{
		temp_max1 = value2;
	}
	if( value3>value4 )
	{
		temp_max2 = value3;
	} else
	{
		temp_max2 = value4;
	}
	if( temp_max1>temp_max2 )
	{
		maximum = temp_max1;
	} else
	{
		maximum = temp_max2;
	}
	
	return maximum;
}

int min4Value(int value1, int value2, int value3, int value4)
{
	int minimum, temp_min1, temp_min2;
	
	if( value1<value2 )
	{
		temp_min1 = value1;
	} else
	{
		temp_min1 = value2;
	}
	if( value3<value4 )
	{
		temp_min2 = value3;
	} else
	{
		temp_min2 = value4;
	}
	if( temp_min1<temp_min2 )
	{
		minimum = temp_min1;
	} else
	{
		minimum = temp_min2;
	}
	
	return minimum;
}

void cekPosisi(int posisi, char *status)
{
	if(posisi == 73)
	{
		strcpy(status, "FINISH");
	} else if ( posisi>0 && posisi<73 )
	{
		strcpy(status, "JALAN");
	}
}
