#include "apc.h"

void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[], int *sign1, int *sign2)
{
	char * str = argv[1];

	int i = 0,res;

	//first operand
	if(argv[1][0] == '-')
	{
		*sign1 = -1;
		i = 1;
	}
	else
	{
		*sign1 = 1;
		i = 0;
	}


	while(str[i] != '\0')
	{
		res = str[i] - '0';
		insert_last(head1,tail1,res);
		i++;
	}

	str = argv[3];

	if(argv[3][0] == '-')
	{
		*sign2 = -1;
		i = 1;
	}
	else
	{
		*sign2 = 1;
		i = 0;

	}
	while(str[i] != '\0')
	{
		res = str[i] - '0';
		insert_last(head2,tail2,res);
		i++;
	}
	//print_list(*head1,*tail1);
	//print_list(*head2,*tail2);
	return ;
}