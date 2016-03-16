/*
 * SortAlgorithm.c
 *
 *      Author: abdullahalshubaili
 */

#include "empstructs.h"

EMPLOYEE* SortedMerge(EMPLOYEE* subListA, EMPLOYEE* subListB);
void SplitList(EMPLOYEE* original, EMPLOYEE** frontRef, EMPLOYEE** backRef);

EMPLOYEE* MergeSort(EMPLOYEE** rootRef) {

    EMPLOYEE* root = *rootRef;
    EMPLOYEE* subListA;
    EMPLOYEE* subListB;


    if((root == NULL) || (root->right == NULL))
    {
        return NULL;
    }

    SplitList(root, &subListA, &subListB);

    MergeSort(&subListA);
    MergeSort(&subListB);

    *rootRef = SortedMerge(subListA, subListB);
    return(*rootRef);
}


EMPLOYEE* SortedMerge(EMPLOYEE* subListA, EMPLOYEE* subListB) {
    EMPLOYEE* result = NULL;
    // base case
    if(subListA == NULL)
        return(subListB);
    else if(subListB == NULL)
        return(subListA);

    if(subListA->salary >= subListB->salary)
    {
        result = subListA;
        result->right = SortedMerge(subListA->right, subListB);
    }
    else
    {
        result = subListB;
        result->right = SortedMerge(subListB->right, subListA);
    }
    return(result);
}

void SplitList(EMPLOYEE* original, EMPLOYEE** frontRef, EMPLOYEE** backRef) {
    EMPLOYEE* fast;
    EMPLOYEE* slow;

    if(original == NULL || original->right == NULL) {
        *frontRef = original;
        *backRef = NULL;
    }

    else
    {
        slow = original;
        fast = original->right;

        while(fast != NULL) {
            fast = fast->right;
            if(fast != NULL) {
                slow = slow->right;
                fast = fast->right;
            }
        }

        *frontRef = original;
        *backRef = slow->right;
        slow->right = NULL;
    }
}
