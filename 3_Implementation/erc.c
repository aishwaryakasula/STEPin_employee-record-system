// C program for the Employee record system
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "header.h"
#include "addemployee.c"
#include "deleteemployee.c"
#include "displayemployee.c"
#include "modifyemployee.c"

// size of the structure
long int size = sizeof(e);

// In the start coordinates
// will be 0, 0
COORD cord = { 0, 0 };

// function to set the
// coordinates
void gotoxy(int x, int y)
{
	cord.X = x;
	cord.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		cord);
}

FILE *fp, *ft;


// Driver code
int main()
{
	int choice;

	// opening the file
	fp = fopen("data.txt", "rb+");

	// showing error if file is
	// unable to open.
	if (fp == NULL) {
		fp = fopen("data.txt", "wb+");
		if (fp == NULL) {
			printf("\nCannot open file...");
			exit(1);
		}
	}

	system("Color 3F");
	printf("\n\n\n\n\t\t\t\t============="
		"============================="
		"===========");
	printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~"
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
		"~~~~~");
	printf("\n\t\t\t\t==================="
		"============================="
		"=====");
	printf("\n\t\t\t\t[|:::>:::>:::>::> "
		"EMPLOYEE RECORD <::<:::<:::"
		"<:::|]\t");
	printf("\n\t\t\t\t==================="
		"============================="
		"=====");
	printf("\n\t\t\t\t~~~~~~~~~~~~~~~~~~~~"
		"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
		"~~~");
	printf("\n\t\t\t\t====================="
		"==============================\n");
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t"
		"Developer : k.sai aishwarya"
		"\n\n\t\t\t\t");

	system("pause");

	while (1) {
		// Clearing console and asking the
		// user for input
		system("cls");
		gotoxy(30, 10);
		printf("\n1. ADD RECORD\n");
		gotoxy(30, 12);
		printf("\n2. DELETE RECORD\n");
		gotoxy(30, 14);
		printf("\n3. DISPLAY RECORDS\n");
		gotoxy(30, 16);
		printf("\n4. MODIFY RECORD\n");
		gotoxy(30, 18);
		printf("\n5. EXIT\n");
		gotoxy(30, 20);
		printf("\nENTER YOUR CHOICE...\n");
		fflush(stdin);
		scanf("%d", &choice);

		// Switch Case
		switch (choice) {
		case 1:

			// Add the records
			addrecord(fp,size);
			break;

		case 2:

			// Delete the records
			deleterecord(fp,size,ft);
			break;

		case 3:

			// Display the records
			displayrecord(fp,size);
			break;

		case 4:

			// Modify the records
			modifyrecord(fp,size);
			break;

		case 5:
			fclose(fp);
			exit(0);
			break;

		default:
			printf("\nINVALID CHOICE...\n");
		}
	}

	return 0;
}
