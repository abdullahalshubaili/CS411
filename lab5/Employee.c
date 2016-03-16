/*
 * Employee.c
 *
 *      Author: abdullahalshubaili
 */


#include "empstructs.h"

void destroyEmployee(EMPLOYEE** emp) {
	//free up allocated memory
	free(*emp);
	emp = NULL;
}

EMPLOYEE* createEmployee(char* name, double salary, int id) {
	EMPLOYEE *emp = NULL;
	emp = malloc(sizeof(EMPLOYEE));
	strcpy(emp->name, name);

	//Assign Id and Salary
	emp->salary = salary;
	emp->id = id;
	/*
	int i = 0;
	for (i = 0; i < MAX_EMPLOYEES; i++) {
			 emp->name[i] = *name;
			 name++;
			}
			*/

	emp->left = NULL;
	emp->right = NULL;

	return emp;
}

char* employeeToString(EMPLOYEE* emp, char* string) {
	char id[LINE];
	char salary[LINE];

	id[0] = '\0';
	snprintf(id, LINE, "%d", emp->id);
	salary[0] = '\0';
	snprintf(salary, LINE, "%.2f", emp->salary);
	string[0] = '\0';
	strcat(string, "Name: ");
	strcat(string, emp->name);
	strcat(string, " ID: ");
	strcat(string, id);
	strcat(string, " Salary: $ ");
	//string[0] = '\0';
	strcat(string, salary);
	return string;
}
