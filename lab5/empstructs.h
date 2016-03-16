/*
 * Employee.c
 *
 *      Author: abdullahalshubaili
 */
#ifndef EMPSTRUCTS_H_
#define EMPSTRUCTS_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 10000
#define EMP_SIZE 30
#define LINE 80
#define OPTIONS 9

#ifndef NULL
#define NULL   ((void *) 0)
#endif

#define FALSE 0
#define TRUE 1

typedef struct _EMPLOYEE {
	int id;
	char name[EMP_SIZE];
	double salary;
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
char* employeeToString(EMPLOYEE* , char*);

/* Declared in EmployeeList.c */
void initializeEmployeeList(EMPLOYEE_LIST*);
EMPLOYEE* insert(EMPLOYEE_LIST*, char*, double);
void sort(EMPLOYEE_LIST*);
int delete(EMPLOYEE_LIST*, int);
void deleteAll(EMPLOYEE_LIST*);
void deleteb(EMPLOYEE*);
void traverseb(EMPLOYEE*, void (*)(EMPLOYEE*, char*));
int traverse(EMPLOYEE_LIST*, void (*)(EMPLOYEE*, char*));

EMPLOYEE* find(EMPLOYEE_LIST*, int);
EMPLOYEE* findm(EMPLOYEE*);
EMPLOYEE* findb(EMPLOYEE*, int);

EMPLOYEE* eraseb(EMPLOYEE*, int);
EMPLOYEE* removeb(EMPLOYEE*);
EMPLOYEE* insertb(EMPLOYEE*, EMPLOYEE*);


int SplitList(int *, int, int);
void Sortedheap(int *, int);
void Sortedquick(int *, int);
void heap(int *, int, int);
void swap(int *, int, int);


#endif /* EMPSTRUCTS_H_ */
