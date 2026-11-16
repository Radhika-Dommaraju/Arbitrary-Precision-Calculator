#include<stddef.h>
#include "apc.h"
#include<stdlib.h>



int list_compare(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2)
{
    int count1 = 0;
    int count2 = 0;

    Dlist *temp1 = head1;
    Dlist *temp2 = head2;

    while (temp1 != NULL)
    {
        count1++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }

    if (count1 > count2)
        return 1;

    if (count1 < count2)
        return -1;

    /* Same number of digits */
    temp1 = head1;
    temp2 = head2;

    while (temp1 != NULL)
    {
        if (temp1->data > temp2->data)
            return 1;

        if (temp1->data < temp2->data)
            return -1;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return 0;   /* numbers are equal */
}