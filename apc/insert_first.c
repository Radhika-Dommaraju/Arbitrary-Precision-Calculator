#include<stdlib.h>
#include "apc.h"

int insert_first(Dlist **head, Dlist **tail, int data)
{
	 
    Dlist *new;
    new = malloc(sizeof(Dlist));
    
    if(new == NULL)
    return FAILURE;
    
    new->prev = NULL;
    new->data = data;
    new->next = *head;
    
    //if list is empty
    if((*head) == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    
    //if not empty
    else
    {
        (*head)->prev = new;
        *head = new;
        return SUCCESS;
        
    }

}