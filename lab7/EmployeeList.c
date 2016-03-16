/*
 * EmployeeList.c
 *
 *  Created on: Feb 25, 2016
 *      Author: abdullah alshubaili
 */


#include "empstructs.h"

void initializeEmployeeList(EMPLOYEE_LIST* list) {
	int i = 0;

	list->freeCount = MAX_EMPLOYEES;
	list->numEntries = 0;
	list->employeeIndex = 0;
	list->root = NULL;

	for (i = 0; i < MAX_EMPLOYEES; i++) {
		list->freeList[i] = MAX_EMPLOYEES+1;//change
	}
}
//2-3-4


EMPLOYEE* splitter(EMPLOYEE* current,EMPLOYEE* employee) {
	//current = malloc(current->right* sizeof(int));
	current = malloc(sizeof(EMPLOYEE));
	current = current->right;
	EMPLOYEE* root;
	EMPLOYEE* father;

	if(father)
		current = employee->father;
	else
		root = malloc(sizeof(employee));
		//root = malloc(employee* sizeof(int));
		current = root->right;
		employee = root->left;

		return current;
}


//end

//int max(int a, int b);
int height(EMPLOYEE *current)
{ if(current == NULL)
	return 0;
	return current->height;
}
int max(int a, int b)
{return (a>b)? a:b;}

//for AVL rotate y
EMPLOYEE* rightrotate(EMPLOYEE* y)
{
EMPLOYEE *x = y->left;
EMPLOYEE *T2 = x->right;
//perform rotation
x->right = y;
y->left = T2;
//update
y->height = max(height(y->left), height(y->right))+1;
x->height = max(height(x->left), height(x->right))+1;
//return root
return x;
}
//rotate x
EMPLOYEE* leftrotate(EMPLOYEE* x)
{

	EMPLOYEE *y = x->right;
	EMPLOYEE *T2 = y->left;
	//perform rotation
	y->left = x;
	x->right = T2;
	//update
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;
	//return root
	return y;
}
//get balance factor of employee list
int getBalance(EMPLOYEE *list)
{
	if (list == NULL)
		return 0;
	return height (list->left) - height(list->right);
}

EMPLOYEE* insertAVL(EMPLOYEE* current, EMPLOYEE* employee )
{
	if(current == NULL)
	current = employee;
	if(employee->id < current->id)
	current->left = insertb(current->left, employee);
	if(employee->id > current->id)
	current->right = insertb(current->right, employee);
//update height
current->height = max(height(current->left), height(current->right))+1;
int balance = getBalance(current);
//if employee is unbalanced, there are 4 cases for this
//ll
if(balance > 1 && employee->id < current->left->id)
	return rightrotate(current);
//rr
if(balance < -1 && employee->id> current->right->id)
	return leftrotate(current);
//lr
if(balance > 1 && employee->id > current->left->id)
{
	current->left = leftrotate(current->left);
	return rightrotate(current);
}
//rl
if(balance < -1 && employee->id < current->right->id)
{
	current->right = rightrotate(current->right);
	return current;//rightrotate(current)
}
return current;//rightrotate(current)
}

void displayAVL(EMPLOYEE* current, void (*employeeToString) (EMPLOYEE*, char*))
{

	char string[LINE];

	if (current == NULL)
		return;
		displayAVL(current->left,(*employeeToString));
				employeeToString(current, string);
				printf("%s\n", string);
				fflush(stdout);
		displayAVL(current->right,(*employeeToString));

}


void displayBINARY(EMPLOYEE* current, void (*employeeToString)(EMPLOYEE*, char*)) {
	char string[LINE];
	if(current == NULL)
		return;
	displayBINARY(current->left, (*employeeToString));
	employeeToString(current, string);
	printf("%s\n", string);
	fflush(stdout);
	displayAVL(current->right, (*employeeToString));
}


int traverse(EMPLOYEE_LIST* list, void (*employeeToString)(EMPLOYEE*, char*)) {
	displayBINARY(list->root, (*employeeToString));//displayBINARY
	return TRUE;
}


EMPLOYEE* insert(EMPLOYEE_LIST* list, char* name, double salary) {
	EMPLOYEE *employee = NULL;

	int id = 0;
	if (list->numEntries >= MAX_EMPLOYEES) {//might change the >=
		splitter(list,employee);
		//return NULL;
	}
	id = list->freeList[rand() % MAX_EMPLOYEES];
	while (find(list, id) != NULL) {
		id = rand() % MAX_EMPLOYEES;
	}
	employee = createEmployee(name, salary, id);
	list->root = insertb(list->root, employee);
	list->numEntries++;

	return employee;
}


EMPLOYEE *insertb(EMPLOYEE* current, EMPLOYEE* employee) {
	if(current == NULL) {
		current = employee;
	} else if(employee->id < current->id) {
		current->left = insertb(current->left, employee);
	} else if(employee->id > current->id) {
		current->right = insertb(current->right, employee);
	}

	return current;
}


void sort(EMPLOYEE_LIST* list) {
	return;
}


EMPLOYEE* findminb(EMPLOYEE* current) {
	if(current != NULL)
		while(current->left != NULL)
			current = current->left;

	return current;
}


EMPLOYEE* removeminb(EMPLOYEE *current) {
	if(current == NULL)
		return current;

	if(current->left != NULL) {
		current->left = removeminb(current->left);
		return current;
	}
	return current->right;
}


EMPLOYEE* binaryDelete(EMPLOYEE* current, int id) {
	if(current == NULL)
		return current;

	if(id < current->id) {
		current->left = binaryDelete(current->left, id);
	} else if(id > current->id) {
		current->right = binaryDelete(current->right, id);
	} else if(current->left != NULL && current->right != NULL) {
		EMPLOYEE *minimumEmployee = findminb(current->right);
		current->id = minimumEmployee->id;
		current->salary = minimumEmployee->salary;
		strcpy(current->name, minimumEmployee->name);
		current->right = removeminb(current->right);
	} else {
		EMPLOYEE* replacer = (current->left != NULL) ? current->left : current->right;
		free(current);
		current = NULL;
		current = replacer;
	}

	return current;
}


int delete(EMPLOYEE_LIST* list, int id) {
	if(binaryFind(list->root, id) == NULL)
		return FALSE;

	list->root = binaryDelete(list->root, id);
	return TRUE;
}


void binaryDeleteAll(EMPLOYEE* current) {
	if(current == NULL)
		return;

	binaryDeleteAll(current->left);
	binaryDeleteAll(current->right);
	free(current);
	current = NULL;
}


void deleteAll(EMPLOYEE_LIST* list) {
	binaryDeleteAll(list->root);

	initializeEmployeeList(list);
}


EMPLOYEE* binaryFind(EMPLOYEE* current, int id) {
	if(current == NULL)
		return NULL;

	if(id < current->id)
		return binaryFind(current->left, id);
	else if(id > current->id)
		return binaryFind(current->right, id);

	return current;
}


EMPLOYEE* find(EMPLOYEE_LIST* list, int id) {
	return binaryFind(list->root, id);
}


// Used only for sorting, swap elements between I and J
void heap(int *elements, int parent, int lastnode) {
	int done = FALSE;
	int tmp = elements[parent];
	int rightchild = 0;
	int leftchild = 2 * parent + 1;
	int big = 0;

	while(!done && (leftchild <= lastnode)) {
		big = leftchild;
		rightchild = leftchild + 1;

		if ((rightchild <= lastnode) && (elements[rightchild] > elements[big])) {
			big = rightchild;
		}

		if (tmp < elements[big]) {
			elements[parent] = elements[big];
			parent = big;
			leftchild = 2 * parent + 1;
		} else {
			done = TRUE;
		}
	}

	elements[parent] = tmp;
}

void heapSort(int *elements, int numElements) {
	int size = numElements;
	int parent = 0;
	int lastnode = 0;

	for(parent = size / 2 - 1; parent >= 0; parent--)
		heap(elements, parent, size - 1);

	swap(elements, 0, size - 1);

	for(lastnode = size - 2; lastnode > 0; lastnode--) {
		heap(elements, 0, lastnode);
		swap(elements, 0, lastnode);
	}
}

void quickSort(int *elements, int numElements) {
	int low = 0;
	int high = numElements - 1;
	int *stack = malloc((high - low) * sizeof(int));
	int full = -1;
	stack[++full] = low;
	stack[++full] = high;

	while (full >= 0) {
		high = stack[full--];
		low = stack[full--];
		int pivot = section(elements, low, high);
		if (pivot - 1 > low) {
				stack[++full] = low;
				stack[++full] = pivot - 1;
				}
		if (pivot + 1 < high) {
			stack[++full] = pivot + 1;
			stack[++full] = high;
		}
	}

	free(stack);
	stack = NULL;

}
void swap(int *elements, int i, int j) {
	int temp = 0;

	temp = elements[i];
	elements[i] = elements[j];
	elements[j] = temp;
}

//heap sort on the list of elements
int section(int *elements, int low, int high) {
	int j = 0;
	int x = elements[high];
	int i = (low - 1);
	for (j = low; j <= high - 1; j++) {
		if (elements[j] <= x) {
			i++;
			swap(elements, i, j);
		}
	}

	swap(elements, i + 1, high);

	return i + 1;
}
