#include<stddef.h>
#include<stdlib.h>
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    int borrow = 0;
    int data;

    while(temp1 != NULL)
    {
        if(temp2 != NULL)
        {
            if(temp1->data - borrow < temp2->data)
            {
                data = temp1->data + 10 - borrow - temp2->data;
                borrow = 1;
            }
            else
            {
                data = temp1->data - borrow - temp2->data;
                borrow = 0;
            }

            temp2 = temp2->prev;
        }
        else
        {
            data = temp1->data - borrow;

            if(data < 0)
            {
                data = data + 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }
        }

        insert_first(headR, tailR, data);

        temp1 = temp1->prev;
    }

    while(*headR != NULL &&
          (*headR)->data == 0 &&
          *headR != *tailR)
    {
        Dlist *temp = *headR;

        *headR = (*headR)->next;
        (*headR)->prev = NULL;

        free(temp);
    }

    return SUCCESS;

}