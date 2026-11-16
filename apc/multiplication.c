#include<stddef.h>
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1, *temp2, *headR1, *headR2, *tailR1, *tailR2;
	headR1 = NULL;
	tailR1 = NULL;
	headR2 = NULL, tailR2 = NULL;

	temp1 = *tail1, temp2 = *tail2;
	int count = 0, i, data, carry = 0;


	while(temp2)
	{
		temp1  = *tail1;
		carry = 0;

		headR2= NULL;
		tailR2 = NULL;

		for(i = 0; i < count; i++)
		{
			insert_last(&headR2,&tailR2,0);
		}
	
		

		while(temp1)
		{
			data = temp1->data * temp2->data + carry;

            carry = data / 10;
			data = data % 10;

			insert_first(&headR2,&tailR2, data);

			temp1 = temp1->prev;
		}

		if(carry != 0)
		{
			insert_first(&headR2,&tailR2,carry);
		}
	
	if(count == 0)
        {
            headR1 = headR2;
            tailR1 = tailR2;

            headR2 = NULL;
            tailR2 = NULL;
        }
        else
        {
            addition(&headR1, &tailR1,&headR2, &tailR2, headR, tailR);

            delete_list(&headR1,&tailR1);
            delete_list(&headR2,&tailR2);

            headR1 = *headR;
            tailR1 = *tailR;

            *headR = NULL;
            *tailR = NULL;

            headR2 = NULL;
            tailR2 = NULL;
        }

        count++;
        temp2 = temp2->prev;
    }

*headR = headR1;
*tailR = tailR1;

return SUCCESS;
}
