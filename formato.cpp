#include<iostream>
#include<string.h>
#include<conio.h>
#include "formato.h"

using namespace std;

void printTable(char table[][6])
	{
		system("cls");
		for (int i = 0; i < 5; i++)
			{
				cout << "-------------------------------------" << endl;
				cout << "-     -     -     -     -     -     -" << endl;
				printf("-  %c  -  %c  -  %c  -  %c  -  %c  -  %c  -\n", table[i][0], table[i][1], table[i][2], table[i][3], table[i][4], table[i][5]);
				cout << "-     -     -     -     -     -     -" << endl;	
			}
		cout << "-------------------------------------" << endl;	
	}

void modTable(char table[][6])
	{
		int riga, colonna;
		char carattere;
		char salva;
		char* nomefile = new char[30];
		
		while(true)
			{
				cout << "Inserisci Riga: ";
				cin >> riga;
				cout << "Inserisci Colonna: ";
				cin >> colonna;
				table[riga-1][colonna-1] = '#';
				system("cls");
				printTable(table);
				cout << "Salvare il documento? y/n" << endl;
				cin >> salva;
				if (salva == 'y')
					{
						cout << "Inserisci Nome File da Salvare: ";
						cin >> nomefile;
						strcat(nomefile, ".formato");
						saveTable(table, nomefile);
						cout << "File Salvato con Nome " << nomefile << endl;
						break;
					}	
			}	
	}

void inizializateMatrix(char table[][6])
	{
		for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++)
					{
						table[i][j] = ' ';
					}	
			}
	}
	
void saveTable(char table[][6], char* nome)
	{
		FILE* fw = fopen(nome, "w");
		for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++)
					{
						fprintf(fw, "%c", table[i][j] + 1);	
					}
				fprintf(fw, "%c", '\n');
			}
		fclose(fw);	
	}
	
void openFile(char table[][6])
	{
		char scelta;
		char* nomefile = new char[30];
		char val;
		
		cout << "Aprire un Documento gia Esistente o Crearne uno Nuovo?" << endl << "c = Crea" << endl << "a = Apri" << endl << "Scelta: ";
		cin >> scelta;
		if (scelta == 'a')
			{
				cout << "Inserire Nome Documento da Aprire: ";
				cin >> nomefile;
				strcat(nomefile, ".formato");
				FILE* fr = fopen(nomefile, "r");
				if (fr == NULL)
					{
						cout << "File non trovato." << endl;
						getch();
						exit(1);
					}
				else
					{
						for (int i = 0; i < 6; i++)
							{
								for (int j = 0; j < 7; j++)
									{
										fscanf(fr, "%c", &val);
										if (val - 1 != '\n')
											{
												table[i][j] = val - 1;
											}								
									}
							}
						printTable(table);
						getch();
						exit(1);						
					}
			}
	}
