#include "apc.h"
#include<stdlib.h>
#include<stdio.h>

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1, *temp2;
	temp1 = *tail1;
	temp2 = *tail2;

	int carry = 0,data;


	while(temp1 || temp2)
	{

		if(temp1  && temp2)
		{
			data = temp1->data + temp2->data + carry;
			carry = 0;
			if(data > 9)
			{
				data = data %10;
				if (insert_first(headR,tailR,data) == FAILURE)
				{
					printf("insert failes at case1\n");
					return FAILURE;
				}
				carry = 1;
			}
			else
			{
				if (insert_first(headR,tailR,data) == FAILURE)
				{
					printf("Insert failed at else of case1\n");
					return FAILURE;

				}
			}
			temp1 = temp1->prev;
			temp2 = temp2->prev;

		}

		else if (temp1 != NULL && temp2 == NULL)
		{
			data = temp1->data + carry;
			carry = 0;
			if(data > 9)
			{
				data = data % 10;
				if (insert_first(headR,tailR,data) == FAILURE)
				{
					printf("insert failes at case2\n");
					return FAILURE;
				}
				carry = 1;
			}
			else
			{
			if (insert_first(headR,tailR,data) == FAILURE)
				{
					printf("Insert failed at else of case2\n");
					return FAILURE;

				}
			}
			temp1= temp1->prev;
		}

		else if (temp1 == NULL && temp2 != NULL)
		{
			data = temp2->data + carry;
			carry = 0;
			if(data > 9)
			{
				data = data % 10;
				if (insert_first(headR,tailR,data) == FAILURE)
				{
					printf("Insert failed at case3\n");
					return FAILURE;

				}
				carry = 1;
			}
			else
			{
				if (insert_first(headR,tailR,data) == FAILURE)
				{
					printf("Insert failed at else of case3\n");
					return FAILURE;

				}
			}
			temp2 = temp2->prev;
		}

	}
	if(carry == 1)
	{
		if (insert_first(headR, tailR, carry) == FAILURE)
		{
			printf("Insert first failed at last step\n");
			return FAILURE;
		}
		carry = 0;
	}

	return SUCCESS;
}
