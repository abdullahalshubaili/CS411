/*
 * empstructs.h
 *
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
	struct EMPLOYEE* right;
} EMPLOYEE;


typedef struct
{

    EMPLOYEE* root;
    int freeCount;
    int freeList[MAX_EMPLOYEES];
    int numEntries;     // number of entries entered into link so far

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
int deleteEmployee(EMPLOYEE_LIST*, int);
void deleteAll(EMPLOYEE_LIST*);
void initialize(EMPLOYEE_LIST*, int);
EMPLOYEE* find(EMPLOYEE_LIST*, int);
void traverse(EMPLOYEE_LIST* eL, EMPLOYEE* current, void func ( void (*f)));

// Declared in SortAlgorithm.c
EMPLOYEE* SortedMerge(EMPLOYEE* subListA, EMPLOYEE* subListB);
void SplitList(EMPLOYEE* original, EMPLOYEE** frontRef, EMPLOYEE** backRef);
EMPLOYEE* MergeSort(EMPLOYEE** rootRef);


#endif /* EMPSTRUCTS_H_ */
