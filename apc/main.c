#include "apc.h"
#include<stdio.h>
#include<stdlib.h>


int flag = 0;
int sign1 = 1;
int sign2 = 1;


int main(int argc, char* argv[])
{
	/* Declare the pointers */
      
	Dlist *head1=NULL, *tail1=NULL;
        Dlist *head2=NULL, *tail2=NULL; 
        Dlist *headR=NULL,*tailR=NULL;
		if(argc != 4)
		{
			printf("use : ./a.out operand1 operator operand2");
			return FAILURE;
		}


	char operator=argv[2][0];
	digit_to_list(&head1,&tail1,&head2,&tail2,argv, &sign1, &sign2);

		switch (operator)
		{
			case '+':
            {
              int ret;
            int result_sign;

        if (sign1 == sign2)
        {
              //Same signs 

            if (addition(&head1, &tail1, &head2, &tail2,&headR, &tailR) == FAILURE)
            {
              printf("addition failed\n");
            }
           else
           {
            result_sign = sign1;

            printf("result: ");

            if (result_sign == -1)
                printf("-");

            print_list(headR, tailR);
            }
        }
        else
        {
        //Different signs

        ret = list_compare(head1, tail1, head2, tail2);

           if (ret == 1)
           {
            //op1 > op2

            subtraction(&head1, &tail1,&head2, &tail2,&headR, &tailR);

            result_sign = sign1;

            printf("result: ");

            if (result_sign == -1)
                printf("-");

            print_list(headR, tailR);
           }
          else if (ret == -1)
          {
           // op1 > op2
            subtraction(&head2, &tail2,&head1, &tail1,&headR, &tailR);

            result_sign = sign2;

            printf("result: ");

            if (result_sign == -1)
                printf("-");

            print_list(headR, tailR);
           }
          else
          {
            //if equal

            printf("result: 0\n");
          }
        }

    break;
    }

		
				
		case '-':
       {
         int ret;
         int result_sign;

           //changing the sign of second operator
           sign2 = -sign2;

          if (sign1 == sign2)
          {
            // same signs addition

            if (addition(&head1, &tail1,&head2, &tail2,&headR, &tailR) == FAILURE)
            {
            printf("addition failed\n");
            }
            else
            {
            result_sign = sign1;

            printf("result: ");

            if (result_sign == -1)
                printf("-");

            print_list(headR, tailR);
            }
        }
        else
        {
        // different signs substraction

        ret = list_compare(head1, tail1, head2, tail2);

        if (ret == 1)
        {
            //op1 > op2

            subtraction(&head1, &tail1,
                        &head2, &tail2,
                        &headR, &tailR);

            result_sign = sign1;

            printf("result: ");

            if (result_sign == -1)
                printf("-");

            print_list(headR, tailR);
        }
        else if (ret == -1)
        {
            //op2 > op1

            subtraction(&head2, &tail2,
                        &head1, &tail1,
                        &headR, &tailR);

            result_sign = sign2;

            printf("result: ");

            if (result_sign == -1)
                printf("-");

            print_list(headR, tailR);
        }
        else
        {
            printf("result: 0\n");
        }
        }

    break;
    }

			case 'x':	
			int result_sign;
			result_sign = sign1 * sign2;
				/* call the function to perform the multiplication operation */
				 if (multiplication(&head1,&tail1,&head2,&tail2, &headR, &tailR) == FAILURE)
				 {
					printf("multiplication failed\n");
				 }
				 else
				 {
					printf("Multiplication succesfull\n");
					printf("Result : ");

					if(result_sign == -1)
					printf("-");

					print_list(headR, tailR);
				 }
				break;
			case '/':
		
			     result_sign = sign1 * sign2;	
				/* call the function to perform the division operation */
				if(division(&head1,&tail1,&head2,&tail2,&headR,&tailR) == FAILURE)
				{
					printf("Division failed\n");
				}
				else
				{
					
                  printf("Division successful\n");

                  printf("result: ");

                   /* Don't print -0 */
                   if (result_sign == -1 &&!(headR->data == 0 && headR == tailR))
                    {
                      printf("-");
                    }

                   print_list(headR, tailR);
				}
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}

	return 0;

}
