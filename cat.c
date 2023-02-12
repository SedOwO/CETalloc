/* snode: student node
cnode:clg node  
*/
#include<stdlib.h>
#include<stdio.h>
#define A1SEATS 8 //maximim number of seats 
#define B2SEATS 8 //for reservations in clgs
#define GMSEATS 9 //for different categories
typedef struct Student
{
	char name[20];
	int rank;
	char cat[2];
	char clg[10];
	int uid[5];
	struct Student *lptr, *rptr;
}snode;
typedef struct College
{
	char name[20];
	snode* pupils[25];//clg list will have student nodes assigned to them.
	struct College *lptr, *rptr;
}cnode;
int main()
{
    snode* studentlist; //to dynamically create and store students info.
    snode* A1, *B2, *GM;
    cnode *rv, *rns, *pes, *bms, *msr, *jss;
    
    
    
    int ch;
    int rank;
    for(;;)
    {
        printf("\n\n2023 CET CHOICE ENTRY\n");
        printf("1.Insert\n2.Display\n3.exit\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();break;
            case 2:display();break;
            case 3:exit (0);
            default:printf("Wrong choice\n");
        }
    }
}

