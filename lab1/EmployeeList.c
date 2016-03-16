/*
 * EmployeeList.c
 *
 *  Created on: Jan 14, 2016
 *      Author: abdullahalshubaili
 */
#include "empstructs.h"

void removeNode(EMPLOYEE_LIST* eL, EMPLOYEE* node, EMPLOYEE* nodeParent);
void freeID(EMPLOYEE_LIST* eL, int ID);

EMPLOYEE_LIST* initializeEmployeeList()
{
	EMPLOYEE_LIST *el= malloc(sizeof(EMPLOYEE_LIST));
	srand((int)time(NULL));
	int i = 0;

	for(i = 0; i < MAX_EMPLOYEES; i++)
	{
		el->freeList[i] = (i + 1);
	}

	el->numEntries = 0;
	el->freeCount = MAX_EMPLOYEES;
	el->root = NULL;
	return el;
}

void add(EMPLOYEE_LIST* el, char* name, double salary)
{
	if (el->employeeIndex == MAX_EMPLOYEES)
	{
		puts("MAXIMUM number of employees reached");
		fflush(stdout);
	}
	else
	{
		int randIndex = rand() % el->freeCount;
		int ID = el->freeList[randIndex];
		el->freeCount--;
		el->freeList[randIndex] = el->freeList[el->freeCount];

		EMPLOYEE* e = createEmployee(name, salary,ID);
		if (el->numEntries < 1)
		{
			el->root = e;

		}
		else
		{
			EMPLOYEE* current = el->root;
			while(1)
			{

				 //left
				if (e->id < current->id)
				{
					if (current->left != NULL)
					{
						current = current->left;
					}
					else
					{
						current->left = e;
						break;
					}
				}
				//right
				if (e->id > current->id)
				{
					if (current->right != NULL)
					{
						current = current->right;
					}
					else
					{
						current->right = e;
						break;
					}
				}
			}
		}
		el->numEntries = (el->numEntries + 1);
		//printf("%d",el->numEntries);
	}
}


EMPLOYEE* find(EMPLOYEE_LIST* el, int id)
{
	EMPLOYEE* current = el->root;
		while (1)
		{
			if (current == NULL)
			{
				break;
			}
			if(current->id == id)
			{
				return current;
			}
			if (id < current->id)
			{
				el->previous = current;
				current = current->left;
			}
			else if (id > current->id)
			{
				el->previous = current;
				current = current->right;
			}
		}
		return NULL;
}

void displayAll(EMPLOYEE_LIST* eL){
	traverse(eL, eL->root, display);
}

void traverse(EMPLOYEE_LIST* eL, EMPLOYEE* current, void func ( void (*f))) {

	if (current == NULL) {
		return;
	}
	traverse(eL, current->left, func);
	func(current);
	traverse(eL, current->right, func);
}

int delete(EMPLOYEE_LIST* eL, int ID)
{
	eL->previous = NULL;
	EMPLOYEE* current = find(eL, ID);
	if (current == NULL)
	{
		return 0;
	}
	else
	{//no children
		if (current->left == NULL && current->right == NULL)
		{
			removeNode(eL, current, eL->previous);

		}
		else
		{ //one child
			if (current->left == NULL || current->right == NULL)
			{
				removeNode(eL, current, eL->previous);
			}
			else
			{ //two children
				//find predecessor
				EMPLOYEE* pred = current->left;
				EMPLOYEE* parentPred = current;
				while (1)
				{
					if (pred->right == NULL)
					{
						break;
					}
					parentPred = pred;
					pred = pred->right;
				}
				int id = pred->id;
				char name[30];
				strncpy( name, pred->name,30);
				//memcpy(current->name, pred->name,30);
				removeNode(eL, pred, parentPred);

				strncpy( current->name,name,30);
				current->id = id;

			}
		}
	}
	return 1;
}

void removeNode(EMPLOYEE_LIST* eL, EMPLOYEE* node, EMPLOYEE* nodeParent)
{
	if (node->left == NULL && node->right == NULL)
	{//no children
		if (nodeParent == NULL)
		{
			eL->root = NULL;
		}
		else {
			if (node->id < nodeParent->id)
			{
				nodeParent->left = NULL;
			}
			else {
				nodeParent->right = NULL;
			}
		}
		freeID(eL, node->id);
		destroyEmployee(node);
	}
	else
	{
		if (node->left == NULL || node->right == NULL)
		{//one child
			if (nodeParent == NULL)
			{
				if(node->right == NULL)
				{
					eL->root = node->left;
				}
				else
				{
					eL->root = node->right;
				}
			}
			else {
				if (node->id < nodeParent->id)
				{
					if(node->right == NULL) {
						nodeParent->left = node->left;
					}
					else {
						nodeParent->left = node->right;
					}
				}
				else {
					if(node->right == NULL) {
						nodeParent->right = node->left;
					}
					else {
						nodeParent->right = node->right;
					}
				}
			}
			freeID(eL, node->id);
			destroyEmployee(node);
		}
	}
	eL->numEntries--;
}


void freeID(EMPLOYEE_LIST* eL, int ID)
{
	eL->freeList[eL->freeCount] = ID;
	eL->freeCount++;
}

void deleteAll(EMPLOYEE_LIST* eL)
{
	int i;
	for (i = 1; i < 101; i++)
	{
		delete(eL, i);
	}
}


void initialize(EMPLOYEE_LIST* eL, int num)
{
	char* names[5] = {"John", "Harry", "Tom", "Dick", "Bruce"};
	double salary;
	int i;
	for (i = 0; i < num; i++) {
		salary = ((double)(rand()%2500) + 1000 );
		add(eL, names[(rand() % 5)], salary);
	}
}
