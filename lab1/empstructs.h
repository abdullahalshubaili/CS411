/*
 * empstructs.h
 *
 *  Created on: Jan 14, 2016
 *      Author: abdullahalshubaili
 */
#ifndef EMPSTRUCTS_H_
#define EMPSTRUCTS_H_


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_EMPLOYEES 100
#define MAX_NAME 25
#define EMP_SIZE 30
#define LINE 80
#define OPTIONS 9


#ifndef NULL
#define NULL   ((void *) 0)
#endif


#define FALSE 0;
#define TRUE 1;


typedef struct
{
   int id;
   char name[EMP_SIZE];
   double salary;
    struct EMPLOYEE* left;
	struct EMPLOYEE* right;
} EMPLOYEE;


typedef struct
{

   EMPLOYEE* root;
   EMPLOYEE* previous;
   int freeCount;
   int employeeIndex;
   int numEntries;
   int  freeList[MAX_EMPLOYEES];
   EMPLOYEE *employees[MAX_EMPLOYEES];

} EMPLOYEE_LIST;



/* Declared in Employee.c */
void destroyEmployee(EMPLOYEE*);
EMPLOYEE* createEmployee(char*, double, int);
char* employeeToString(EMPLOYEE* e);
void display(EMPLOYEE* e);


/* Declared in EmployeeList.c */
EMPLOYEE_LIST* initializeEmployeeList();
EMPLOYEE* insert(EMPLOYEE_LIST*, char*, double);
void sort(EMPLOYEE_LIST*);
int delete(EMPLOYEE_LIST*, int);
void deleteAll(EMPLOYEE_LIST*);
void initialize(EMPLOYEE_LIST*, int);
EMPLOYEE* find(EMPLOYEE_LIST*, int);
void traverse(EMPLOYEE_LIST* eL, EMPLOYEE* current, void func ( void (*f)));


#endif /* EMPSTRUCTS_H_ */
