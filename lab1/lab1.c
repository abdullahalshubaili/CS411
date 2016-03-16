/*
 * lab1.c
 *
 *  Created on: Jan 14, 2016
 *      Author: abdullahalshubaili
 */
#include <stdio.h>
#include <stdlib.h>
#include "empstructs.h"

//Helper Method to read input and Validate.
int getInt(char*, int, int);
double getDouble(char*, double, double);
char* getStr(char* prompt, int size);

void displayMenu();

int main(void) {


	int selection = 0,ID =0;

	//Display Menu
	displayMenu();

			EMPLOYEE_LIST *el = initializeEmployeeList();
	while(selection != 9)
	{


		selection = getInt("Please Select: ", 1, 9);


		switch(selection)
		{

			case 1:
							fflush(stdout);

							char* name = getStr("Enter Name: ", MAX_NAME);
							double salary = getDouble("Enter Salary: ", 0.0, 10000000.0);
							add(el, name, salary);
							free(name);
							name = NULL;
							puts("Created employee");
							fflush(stdout);
				break;
			case 2:
							fflush(stdout);
							 ID = getInt("Enter ID:  ",1,MAX_EMPLOYEES);
							 if (delete(el, ID) == 0)
							 {
							 				puts("ERROR: ID does not exist");
							 				fflush(stdout);
							 }
							break;
			case 3:
				        fflush(stdout);
					     ID = getInt("Enter ID:  ",1,MAX_EMPLOYEES);
					    EMPLOYEE* current = find(el, ID);

					    if (current == NULL) {
					    		//puts("ERROR: ID does not exist");
					    		fflush(stdout);
					    	}
					    	else {
					    		display(current);
					    	}

							break;
			case 4:
							displayAll(el);
							break;
			case 5:
				            deleteAll(el);
							puts("All Employees Removed");
							fflush(stdout);
							break;
			case 6:
						    initialize(el, 5);
							puts("5 New Employees Created");
							fflush(stdout);
							break;
			case 7:
				fflush(stdout);
				puts("List is SORTED");
				fflush(stdout);
							break;
			case 8:
							displayMenu();
							break;
			case 9:
				puts("Goodbye!!!");
				fflush(stdout);
				deleteAll(el);
				free(el);
							break;
		}


	}


	return EXIT_SUCCESS;
}

void displayMenu()
{
	puts("Employee Maintenance");
				puts("1) Add Employee");
				puts("2) Remove Employee");
				puts("3) Display Employee");
				puts("4) Display Employee List");
				puts("5) Reset List");
				puts("6) Create Initial List");
				puts("7) Sort");
				puts("8) Help");
				puts("9) Quit");
				fflush(stdout);
}

int getInt(char* prompt, int min, int max) {
	int in;
	while (1) {
		printf("%s", prompt);
		fflush(stdout);
		if (scanf("%i", &in)!=1) {
			puts("Error: Please enter numeric input");
			fflush(stdout);
			scanf("%*s");
		}
		else if (in < min || in > max) {
			printf("Error: Please enter value between %i and %i \n", min, max);
			fflush(stdout);

		}
		else {
			fflush(stdin);
			return in;
		}
	}
	fflush(stdin);
	return in;
}

double getDouble(char* prompt, double min, double max) {
	double in;
	while (1) {
		printf("%s", prompt);
		fflush(stdout);
		if (scanf("%lf", &in)!=1) {
			puts("Error: Please enter numeric input");
			fflush(stdout);
			scanf("%*s");
		}
		else if (in < min || in > max) {
			printf("Error: Please enter value between %.2f and %.2f \n", min, max);
			fflush(stdout);
		}
		else {
			fflush(stdin);
			return in;
		}
	}
	fflush(stdin);
	return in;
}

char* getStr(char* prompt, int size) {
	printf("%s", prompt);
	fflush(stdout);
	char* s = malloc(MAX_NAME + 1);
	scanf(" %20[^\n]s", s);
	fflush(stdout);
	fflush(stdin);
	return s;
}
