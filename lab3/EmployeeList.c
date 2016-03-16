/*
 * EmployeeList.c
 *
 *      Author: abdullahalshubaili
 */
#include "empstructs.h"

void removeNode(EMPLOYEE_LIST* eL, EMPLOYEE* node, EMPLOYEE* nodeParent);
void freeID(EMPLOYEE_LIST* eL, int ID);

EMPLOYEE_LIST* initializeEmployeeList()
{
    EMPLOYEE_LIST *el = malloc(sizeof(EMPLOYEE_LIST));

    el->root = NULL;
    //el->head = NULL;
    el->numEntries = 0;
    return el;
}

void add(EMPLOYEE_LIST* el, char* name, double salary)
{

    if (el->numEntries == MAX_EMPLOYEES)        // maximum number of employees reached
    {
        puts("MAXIMUM number of employees reached");
        fflush(stdout);
        return;
    }

    else
    {

        EMPLOYEE* newEmployee = createEmployee(name, salary, (el->numEntries + 1));

        if (el->numEntries < 1)                 // If this is the first entry into the list
        {
            el->root = newEmployee;
        }
        else
        {
            newEmployee->right = el->root;       // make new entry reference back to previous last entry


            el->root = newEmployee;             // make new entry the head of the list
        }
        el->numEntries = (el->numEntries + 1);  // increment count of entries already made into list

    }
}


EMPLOYEE* find(EMPLOYEE_LIST* el, int id)
{
    EMPLOYEE* current = el->root;
    while (1)
    {
        if (current == NULL)
        {
            return NULL;
        }
        if (current->id == id)
        {
            return current;
        }
        current = current->right;
    }
    return NULL;
}


void displayAll(EMPLOYEE_LIST* eL){
	traverse(eL, eL->root, display);
}

void traverse(EMPLOYEE_LIST* eL, EMPLOYEE* current, void func ( void (*f))) {

	if (current == NULL || eL->numEntries == 0) {
		return;
	}
	traverse(eL, current->right, func);
	func(current);
}

int deleteEmployee(EMPLOYEE_LIST* el, int ID)
{
    EMPLOYEE* buffer = el->root;
    EMPLOYEE* buffer2;
    int i;
    if ((buffer != NULL && buffer->id == ID)) {
            el->root = (el->root)->right;
                destroyEmployee(buffer);
                (el->numEntries)--;             // reduce number of employees by one after deletion
                return 1;
            }
            else {
                for (i = 0; i < el->numEntries; i++) {
                    // look for ID in saved entries
                    buffer2 = buffer->right;
                    if (buffer2 != NULL && buffer2->id == ID) {
                        buffer->right = buffer2->right;
                        destroyEmployee(buffer2);
                        (el->numEntries)--;
                        return 1;
                    }
                }
            }
            return 0;
        }

        void deleteAll(EMPLOYEE_LIST* el)
        {
            int i;
            EMPLOYEE* employee;
            for (i = 0; i < el->numEntries; i++)
            {
                employee = el->root;
                deleteEmployee(el, employee->id);
            }
            el->numEntries = 0;
        }


        void initialize(EMPLOYEE_LIST* eL, int num)
        {
            char* names[5] = {"John", "Harry", "Tom", "Dick", "Bruce"};
            double salary;
            int i;
            for (i = 0; i < num; i++) {
                salary = ((double)(rand() % 2500) + 1000 );
                add(eL, names[(rand() % 5)], salary);
            }
        }

