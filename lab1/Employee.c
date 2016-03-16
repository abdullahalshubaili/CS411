/*
 * Employee.c
 *
 *  Created on: Jan 14, 2016
 *      Author: abdullahalshubaili
 */
#include "empstructs.h"

void destroyEmployee(EMPLOYEE *emp)
{
	//free up allocated memory
	free(emp);
	emp = NULL;
}

EMPLOYEE* createEmployee(char* name, double salary, int ID){
	EMPLOYEE* emp = malloc(sizeof(EMPLOYEE));

	//Assign Id and Salary
	emp->id = ID;
	emp->salary = salary;

	int i =0;

	for (i = 0; i < MAX_NAME; i++) {
		 emp->name[i] = *name;
		 name++;
		}
	emp->left = NULL;
	emp->right = NULL;

	return emp;

}

void display(EMPLOYEE* e){
	printf("Employee ID: %-3i Name: %-20s Salary: $%.2f\n", e->id, e->name, e->salary);
	fflush(stdout);
}

