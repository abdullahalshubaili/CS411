/*
 * lab.c
 *
 *  Created on: Feb 25, 2016
 *      Author: abdullahalshubaili
 */


#include <stdio.h>
#include "empstructs.h"


void getString(char *prompt, char *out_string) {
	char input[LINE];

	printf("%s: ", prompt);
	fflush(stdout);
	fgets(input, 255, stdin);
	input[strlen(input) - 1] = '\0';
	strcpy(out_string, input);
	//fflush(stdout);
}

int getInt(char *prompt) {

	char input[LINE];
	int value = 0;

	while (TRUE)
	{
		input[0] = '\0';
		getString(prompt, input);
		//fflush(stdout);
		if (sscanf(input, "%d", &value) == 1) {
			return value;
		}
		printf("only numeric value is accepted.\n");
		fflush(stdout);
	}
	return value;
}

double readDouble(char *prompt) {
	char input[LINE];
	double value = 0;

	while (TRUE) {
		input[0] = '\0';
		getString(prompt, input);

		if (sscanf(input, "%lf", &value) == 1) {
			//fflush(stdout);
			return value;
		}

		printf("only numeric value is accepted \n");
		fflush(stdout);
	}

	return value;
}

int main() {
	int option = 8;
	int i = 0;
	int id = 0;
	int *elem1 = NULL;
	int *elem2 = NULL;
	int numElements = 0;

	double salary = 0;

	char name[EMP_SIZE];
	char string[LINE];
	char *names[] = { "ali", "mohsen", "jasim", "samy", "lama", "tyseer", "aljasm", "mostafa", "ranya", "khdooj" };

	EMPLOYEE_LIST list;
	EMPLOYEE *employee = NULL;

	clock_t start;
	clock_t end;

	srand((unsigned int) time(NULL));

	initializeEmployeeList(&list);

	while (option != 9) {
			if (option == 1) {

			getString("Enter employee name", name);
			fflush(stdout);
			salary = readDouble("Enter a salary");
			fflush(stdout);
			employee = insert(&list, name, salary);

			if (employee != NULL)
			{
				employeeToString(employee, string);

				printf("Employee has been added to the list.\n");
				printf("%s\n", string);
				fflush(stdout);
			} else {
				printf("Inventory is full.\n");
				fflush(stdout);
			}
		} else if (option == 2) {

			id = getInt("Enter employee ID");
			fflush(stdout);

			if (delete(&list, id)) {
				printf("Employee has been deleted.\n");
				fflush(stdout);
			} else {
				printf("ERROR: No employee exits with this ID# %d",id);
				fflush(stdout);
			}
		} else if (option == 3) {

			id = getInt("Enter employee ID");
			employee = find(&list, id);

			if (employee != NULL) {
				employeeToString(employee, string);
				printf("%s\n", string);
				fflush(stdout);
			} else {
				printf("ERROR: No employee exits with this ID# %d",id);
				fflush(stdout);
			}
		} else if (option == 4) {

			sort(&list);
			traverse(&list, employeeToString);
			fflush(stdout);
		} else if (option == 5) {

			deleteAll(&list);
			printf("The list is cleaned");
			fflush(stdout);
		} else if (option == 6) {

			printf("Inserting 20 employees\n");
			fflush(stdout);

			for (i = 0; i < 20; i++) {
				employee = insert(&list, names[rand() % 5], rand() % 1000 + 1);
				employeeToString(employee, string);
				printf("%s\n", string);
				fflush(stdout);
			}
		} else if (option == 7) {

			sort(&list);
		} else if (option == 8) {

			printf("Employee Maintenance\n");
			printf("1) Add Employee\n");
			printf("2) Remove Employee\n");
			printf("3) Display Employee\n");
			printf("4) Display Employee List\n");
			printf("5) Reset List\n");
			printf("6) Create Initial List\n");
			printf("7) Sort\n");
			printf("8) Help\n");
			printf("9) Quit\n");
			printf("10) Test merge sort, bubble sort and quick sort\n");
			printf("11) Test the performance of insertion, sorting, and removing of employees\n");
			fflush(stdout);


		} else if(option == 10) {

			numElements = getInt("Enter a number of employee to test");
			fflush(stdout);
			elem1 = malloc(numElements * sizeof(int));
			elem2 = malloc(numElements * sizeof(int));

			printf("Generating employee list for testing.\n");
			fflush(stdout);

			for(i = 0; i < numElements; i++) {
				elem1[i] = rand() % numElements;
				elem2[i] = elem1[i];
			}
			printf("Merge sorting \n");
			fflush(stdout);

			start = clock();
			mergeSort(numElements);
			end = clock();

			for(i = 0; i < numElements; i++) {

			}
			printf("%lf millisecond to perform Merge sort.\n", (1.0 * (end - start) / CLOCKS_PER_SEC));


			printf("bubble sorting\n");
			fflush(stdout);
			start = clock();
			BubbleSort(elem2, numElements);
			end = clock();


			printf("%lf millisecond to perform bubble sort.\n", (1.0 * (end - start) / CLOCKS_PER_SEC));
			fflush(stdout);

			printf("Quick sorting\n");
			fflush(stdout);
			start = clock();
			quickSort(elem1, numElements);
			end = clock();


			printf("%lf millisecond to perform quick sort.\n", (1.0 * (end - start) / CLOCKS_PER_SEC));
			fflush(stdout);
			free(elem1);
			elem1 = NULL;
			free(elem2);
			elem2 = NULL;
			deleteAll(&list);


		}


		else if (option == 11) {
						int m=0;
						deleteAll(&list);
						m = getInt("Insert a number employees for testing");
						fflush(stdout);
						start = clock();
						for(i = 0; i < m; i++) {
							employee = insert(&list, names[rand() % 10], rand() % m + 1);
							employeeToString(employee, string);
							fflush(stdout);

						}

						end = clock();

						printf("%lf milliseconds to perform insertion.\n", (1.0 * (end - start) / CLOCKS_PER_SEC));

						printf("Sorting the employee for testing\n");
						fflush(stdout);
						start = clock();

						sort(&list);

						end = clock();

						printf("%lf milliseconds to perform sorting.\n", (1.0 * (end - start) / CLOCKS_PER_SEC));

						printf("Deleting the employees from the list\n");
						fflush(stdout);
						start = clock();

						deleteAll(&list);

						end = clock();
						printf("%lf milliseconds to perform deleting.\n", (1.0 * (end - start) / CLOCKS_PER_SEC));
						fflush(stdout);
		}

		printf("\n");
		option = getInt("Please Select");
		printf("\n");
		fflush(stdout);
	}

	printf("Goodbye :D");
	fflush(stdout);
	deleteAll(&list);
	return EXIT_SUCCESS;
	//list = NULL;

	return 0;
}
