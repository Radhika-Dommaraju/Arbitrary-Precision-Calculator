#ifndef APC_H
#define APC_H


#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

/*store the operands into the list */
void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[], int *sign1, int *sign2);

//insert last
void insert_last(Dlist **head, Dlist **tail, int res);

//insert_first
int insert_first(Dlist **head, Dlist **tail, int data);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

//to compare operands for substraction
int list_compare(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2);

/*subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*Multiplication*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

 void print_list(Dlist *head1, Dlist *tail1);

 int delete_list(Dlist **head, Dlist **tail);

 
int delete_first(Dlist **head, Dlist **tail);

/*Division */
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

#endif
