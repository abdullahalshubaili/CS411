/*
 * Employee.c
 *
 *      Author: abdullahalshubaili
 */
#include <stdio.h>
#include "empstructs.h"

void getString(char *prompt, char *ouput) {

	char input[LINE];
	printf("%s:", prompt);
	fgets(input, 255, stdin);
	input[strlen(input) - 1] = '\0';
	strcpy(ouput, input);
}
double getDouble(char *prompt) {
	char input[LINE];
	double value = 0;

	while (TRUE)
	{
		input[0] = '\0';
		getString(prompt, input);
		if (sscanf(input, "%lf", &value) == 1) {
			return value;
		}
	}
	return value;
}
int getInt(char *prompt) {

	char input[LINE];
	int value = 0;

	while (TRUE)
	{
		input[0] = '\0';
		getString(prompt, input);
		if (sscanf(input, "%d", &value) == 1)
		{
			return value;
		}
		printf("ERROR: accept only numbers between 1-9 .\n");
	}
	return value;
}


int main() {

	int options = 8;
	int i = 0;
	int id = 0;
	int numElements = 0;

	double salary = 0;
	char name[EMP_SIZE];
	char string[LINE];
	char *names[] = { "fahad", "mner", "salim", "mhmod", "ramya" ,"abdullah", "yara", "zahra", "rakan", "mohemed", "grgosh", "fatma" };
	EMPLOYEE_LIST el;
	EMPLOYEE *emp = NULL;

	initializeEmployeeList(&el);

	while (options)
	{
		if (options == 1)
		{
				getString("Enter Employee Name", name);
				salary = getDouble("Enter Employee Salary");
				emp = insert(&el, name, salary);
				if (emp != NULL)
				{
					employeeToString(emp, string);
					printf("%s\n", string);
				} else
				{
					printf("Inventory Is Full.\n");
				}
		}
		else if (options == 2)
		{
			id = getInt("Enter Employee ID");
			if (delete(&el, id)) {
				printf("Employee Removed.");
			}
			else
			{
				printf("ERROR: ID does not exist.");
			}
		}
		else if (options == 3)
		{
			id = getInt("Enter Employee ID");
			emp = find(&el, id);
			if (emp != NULL)
			{
				employeeToString(emp, string);
				printf("%s\n", string);
			}
			else
			{
				printf("ERROR: ID does not exist");
			}
		}
		else if (options == 4)
		{
			traverse(&el, employeeToString);
		}
		else if (options == 5)
		{
			deleteAll(&el);
			printf("List is clean");
		}
		else if (options == 6)
		{
			printf("Generate 20 Random Employees");
			for (i = 0; i < 20; i++)
			{
				emp = insert(&el, names[rand() % 10], rand() % 5000 + 5000);
				employeeToString(emp, string);
			}
		}
		else if (options == 7)
		{
			printf("Already Sorted!!");
			sort(&el);
		}
		else if (options == 8)
		{
			printf("1) Add Employee\n");
			printf("2) Remove Employee\n");
			printf("3) Display Employee\n");
			printf("4) Display Employee List\n");
			printf("5) Reset List\n");
			printf("6) Create Initial List\n");
			printf("7) Sort\n");
			printf("8) Help\n");
			printf("9) Quit\n");
		}
		else if (options == 9)
		{
			printf("Goodbye!!!");
			deleteAll(&el);
				return 0;
		}
		else if (options > 9 || options <= 1)
		{
			printf("Input Must be between 1-9");
		}

	printf("\n");
	options = getInt("Please Select ");
	}
	deleteAll(&el);
	return 0;
}

