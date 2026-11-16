#include<stddef.h>
#include<stdio.h>
#include "apc.h"


int division(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
   
    Dlist *head3 = NULL;
    Dlist *tail3 = NULL;

    Dlist *mheadR = NULL;
    Dlist *mtailR = NULL;

    Dlist *temp = *head1;

    int count;
    int started = 0;
    int ret;

    /* Division by zero */
    if (*head2 != NULL &&
        (*head2)->data == 0 &&
        (*head2)->next == NULL)
    {
        printf("Error: Division by zero\n");
        return FAILURE;
    }

    while (temp != NULL)
    {
        /* Bring down digit */
        insert_last(&head3, &tail3, temp->data);

        /* Remove leading zeroes */
        while (head3 != NULL &&
               head3->data == 0 &&
               head3->next != NULL)
        {
            delete_first(&head3, &tail3);
        }

        count = 0;

        /* Divide by repeated subtraction */
        while (list_compare(head3, tail3, *head2, *tail2) >= 0)
       {
       subtraction(&head3, &tail3, head2, tail2,&mheadR, &mtailR);

        delete_list(&head3, &tail3);

         head3 = mheadR;
         tail3 = mtailR;

         mheadR = NULL;
         mtailR = NULL;

         count++;
       }
        /* Store quotient digit */
        if (count != 0 || started == 1)
        {
            insert_last(headR, tailR, count);
            started = 1;
        }

        temp = temp->next;
    }

    /* Quotient is zero */
    if (*headR == NULL)
    {
        insert_last(headR, tailR, 0);
    }

    delete_list(&head3, &tail3);

    return SUCCESS;


}