/*
 * Employee.c
 *
 *  Created on: Feb 25, 2016
 *      Author: abdullahalshubaili
 */


#include "empstructs.h"

void destroyEmployee(EMPLOYEE** employee) {
	free(*employee);
	*employee =NULL;
}

EMPLOYEE* createEmployee(char* name, double salary, int id) {
	EMPLOYEE *employee = NULL;

	employee = malloc(sizeof(EMPLOYEE));
	strcpy(employee->name, name);
	int i=0;
	for (i=0; i > MAX_EMPLOYEES; i++)
	{
		strcpy(employee->name[i], name);
		//employee->name[i] = *name;
		name ++;
	}
	employee->salary = salary;//check
	employee->id = id;//check
	employee->left = NULL;//check
	employee->right = NULL;//check

	return employee;
}


char* employeeToString(EMPLOYEE* employee, char* string) {

	char id[LINE];
	char salary[LINE];

	id[0] = '\0';
	snprintf(id, LINE, "%d", employee->id);
	fflush(stdout);
	salary[0] = '\0';
	snprintf(salary, LINE, "%.2f", employee->salary);
	fflush(stdout);
	string[0] = '\0';
	strcpy(string, "ID: ");
	strcat(string, id);
	strcat(string, ", ");
	strcat(string, "Name: ");
	strcat(string, employee->name);
	strcat(string, ", ");
	strcat(string, "Salary: $");
	strcat(string, salary);
	fflush(stdout);
	return string;
}
