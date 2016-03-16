/*
 * empstructs.h
 *
 *  Created on: Feb 25, 2016
 *      Author: abdullahalshubaili
 */

#ifndef EMPSTRUCTS_H_
#define EMPSTRUCTS_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EMPLOYEES 1000000
#define EMP_SIZE 30
#define LINE 80
#define OPTIONS 11

#ifndef NULL
#define NULL   ((void *) 0)
#endif

#define FALSE 0
#define TRUE 1

typedef struct _EMPLOYEE {
	int id;
	char name[EMP_SIZE];
	double salary;
	int height;
	struct _EMPLOYEE *right;
	struct _EMPLOYEE *left;
} EMPLOYEE;

typedef struct {
	int freeCount;
	int employeeIndex;
	int numEntries;
	int freeList[MAX_EMPLOYEES];
	EMPLOYEE *root;
} EMPLOYEE_LIST;

/* Declared in Employee.c */
void destroyEmployee(EMPLOYEE**);
EMPLOYEE* createEmployee(char*, double, int);
char* employeeToString(EMPLOYEE* employee, char*);
//char* display(EMPLOYEE* employee, char*);

/* Declared in EmployeeList.c */
void initializeEmployeeList(EMPLOYEE_LIST*);
EMPLOYEE* insert(EMPLOYEE_LIST*, char*, double);
void sort(EMPLOYEE_LIST*);
int delete(EMPLOYEE_LIST*, int);
void deleteAll(EMPLOYEE_LIST*);
EMPLOYEE* find(EMPLOYEE_LIST*, int);
int traverse(EMPLOYEE_LIST*, void (*)(EMPLOYEE*, char*));

//binary
EMPLOYEE* insertb(EMPLOYEE*, EMPLOYEE*);
EMPLOYEE* binaryDelete(EMPLOYEE*, int);
EMPLOYEE* findminb(EMPLOYEE*);
EMPLOYEE* removeminb(EMPLOYEE*);
EMPLOYEE* binaryFind(EMPLOYEE*, int);
void binaryDeleteAll(EMPLOYEE*);
void displayBINARY(EMPLOYEE*, void (*)(EMPLOYEE*, char*));

//AVl
int height(EMPLOYEE *N);
int max(int a, int b);
int getBalance(EMPLOYEE *list);
EMPLOYEE* insertAVL(EMPLOYEE* current, EMPLOYEE* employee);
void displayAVL(EMPLOYEE* employee, void (*employeeToString) (EMPLOYEE*, char*));

//heap and quick sorting
void swap(int *, int, int);
void heapSort(int *, int);
void heap(int *, int, int);
int section(int *, int, int);
void quickSort(int *, int);

#endif /* EMPSTRUCTS_H_ */
