/*
 * Employee.c
 *
 *      Author: abdullahalshubaili
 */

#include "empstructs.h"

void initializeEmployeeList(EMPLOYEE_LIST* el) {

	int i = 0;
	for (i = 0; i < MAX_EMPLOYEES; i++)
	{
			el->freeList[i] = i + 1;
	}
	el->root = NULL;
	el->freeCount = MAX_EMPLOYEES;
	el->numEntries = 0;
	el->employeeIndex = 0;
}
//already sorted
void sort(EMPLOYEE_LIST* el) {

	return;

}

EMPLOYEE* insert(EMPLOYEE_LIST* el, char* name, double salary) {

	EMPLOYEE *emp = NULL;
	int id = 0;
	if (el->numEntries >= MAX_EMPLOYEES) {
		return NULL;
	}
	id = el->freeList[rand() % MAX_EMPLOYEES];
	while (find(el, id) != NULL)
	{
		id = rand() % 5000;
	}
//create emlpoyee
	emp = createEmployee(name, salary, id);
	el->root = insertb(el->root, emp);
	el->numEntries++;

	return emp;
}

EMPLOYEE *insertb(EMPLOYEE* current, EMPLOYEE* emp) {

	if(current == NULL)
	{
		current = emp;
	}
	else if(emp->id < current->id)
	{
		current->left = insertb(current->left, emp);

	}
	else if(emp->id > current->id)
	{
		current->right = insertb(current->right, emp);
	}
	return current;
}



EMPLOYEE* find(EMPLOYEE_LIST* el, int id) {
	return findb(el->root, id);

}

EMPLOYEE* findm(EMPLOYEE* current) {
	if(current != NULL)
		while(current->left != NULL)
			current = current->left;

	return current;
}

EMPLOYEE* findb(EMPLOYEE* current, int id) {

	if(current == NULL)
		return NULL;
	if(id < current->id)
		return findb(current->left, id);
	else if(id > current->id)
		return findb(current->right, id);

	return current;
}



EMPLOYEE* eraseb(EMPLOYEE* current, int id) {

	if(current == NULL)

		return current;

	if(id < current->id)
	{
		current->left = eraseb(current->left, id);
	}
	else if(id > current->id)
	{

		current->right = eraseb(current->right, id);
	}
	else if(current->left != NULL && current->right != NULL)
	{

		EMPLOYEE *minimumEmployee = findm(current->right);
		current->id = minimumEmployee->id;
		current->salary = minimumEmployee->salary;
		strcpy(current->name, minimumEmployee->name);
		current->right = removeb(current->right);

	}
	else
	{
		EMPLOYEE* sub = (current->left != NULL) ? current->left : current->right;
		free(current);
		current = sub;
		current = NULL;
	}
	return current;
}

int delete(EMPLOYEE_LIST* el, int id) {

	if(findb(el->root, id) == NULL)
		return FALSE;
	el->root = eraseb(el->root, id);
	return TRUE;
}

void deleteb(EMPLOYEE* current) {

	if(current == NULL)
		return;

	deleteb(current->left);
	deleteb(current->right);
	free(current);
	current = NULL;

}

int traverse(EMPLOYEE_LIST* el, void (*employeeToString)(EMPLOYEE*, char*)) {

	traverseb(el->root, (*employeeToString));
	return TRUE;
}
EMPLOYEE* removeb(EMPLOYEE *current) {

	if(current == NULL)
		return current;

	if(current->left != NULL)
	{
		current->left = removeb(current->left);
		return current;
	}
	return current->right;

}

void deleteAll(EMPLOYEE_LIST* el) {

	deleteb(el->root);
	/* Reset to default */
	initializeEmployeeList(el);
}



void traverseb(EMPLOYEE* current, void (*employeeToString)(EMPLOYEE*, char*)) {

	char string[LINE];
	if(current == NULL)
		return;
	traverseb(current->left, (*employeeToString));
	employeeToString(current, string);
	printf("%s\n", string);
	traverseb(current->right, (*employeeToString));

}



void swap(int *original, int i, int j) {

	int temp = 0;
	temp = original[i];
	original[i] = original[j];
	original[j] = temp;
}
void Sortedheap(int *original, int numElements) {

	int size = numElements;
	int parent = 0;
	int leaf = 0;

	for(parent = size / 2 - 1; parent >= 0; parent--)
	heap(original, parent, size - 1);
	swap(original, 0, size - 1);

	for(leaf = size - 2; leaf > 0; leaf--)
	{
		heap(original, 0, leaf);
		swap(original, 0, leaf);
	}
}
// This will re-arrange the original by heap rules

void heap(int *original, int parent, int leaf) {

	int checking = FALSE;
	int harlem = original[parent];
	int leafleft = 2 * parent + 1;
	int midway = 0;
	int leafhigh = 0;

	while(!checking && (leafleft <= leaf))
	{
		midway = leafleft;
		leafhigh = leafleft + 1;

		if ((leafhigh <= leaf) && (original[leafhigh] > original[midway]))
		{
			midway = leafhigh;
		}
		if (harlem < original[midway])
		{
			original[parent] = original[midway];
			parent = midway;
			leafleft = 2 * parent + 1;
		}
		else
		{
			checking = TRUE;
		}
	}
	original[parent] = harlem;
}

// Create a SplitList and return the next pivot element

int SplitList(int *original, int slow, int fast) {

	int j = 0;
	int x = original[fast];
	int i = (slow - 1);

	for (j = slow; j <= fast - 1; j++)
	{
		if (original[j] <= x) {
			i++;
			swap(original, i, j);
		}
	}

	swap(original, i + 1, fast);

	return i + 1;

}



// Perform a quick sort

void Sortedquick(int *original, int numElements) {

	int slow = 0;
	int fast = numElements - 1;
	int *stack = malloc((fast - slow) * sizeof(int));
	int count = -1;
	stack[++count] = slow;
	stack[++count] = fast;

	while (count >= 0)
	{
		fast = stack[count--];
		slow = stack[count--];

		int pivot = SplitList(original, slow, fast);

		if (pivot - 1 > slow)
		{
			stack[++count] = slow;
			stack[++count] = pivot - 1;
		}
		if (pivot + 1 < fast)
		{
			stack[++count] = pivot + 1;
			stack[++count] = fast;

		}
	}
	free(stack);
	stack = NULL;
}



