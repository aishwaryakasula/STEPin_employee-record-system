#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "header.h"

// Function to display the record
void displayrecord(FILE *fp, int size)
{
	system("cls");

	// sets pointer to start
	// of the file
	rewind(fp);

	printf("\n========================="
		"==========================="
		"======");
	printf("\nNAME\t\tAGE\t\tSALARY\t\t"
		"\tID\n",
		e.name, e.age,
		e.salary, e.id);
	printf("==========================="
		"==========================="
		"====\n");

	while (fread(&e, size, 1, fp) == 1)
		printf("\n%s\t\t%d\t\t%.2f\t%10d",
			e.name, e.age, e.salary, e.id);

	printf("\n\n\n\t");
	system("pause");
}
