// ONLY INSERTION PART IS DONE (PRIORITY SLL)

#include<stdlib.h>
#include<stdio.h>
struct cet
{
    char name[20];
    int rank;
    struct cet *next;
};
typedef struct cet node;
node *start=NULL;
node *getnode()
{
    node *new1;
    new1=(node*)malloc(sizeof(node));
    printf("ENTER YOUR NAME: ");
    scanf("%s",new1->name);
    printf("ENTER YOUR RANK:");
    scanf("%d",&new1->rank);
    new1->next=NULL;
    return new1;
}
void insert()
{
    node *new1,*temp=start;
    new1=getnode();
    if(start==NULL||new1->rank < start->rank) 	//WORK FOR BOTH CASES, 1.WHEN START
    {							//IS NULL & 2. WHEN PRIORITY OF NEW1 								// IS HIGHER THAN 1ST NODE. 
        new1->next=start;
        start=new1;
    }
    else
    {
        while(temp->next!=NULL && temp->next->rank<=new1->rank)	
            temp=temp->next;
        new1->next=temp->next;
        temp->next=new1;
    }
}
void display()
{
    node *temp=start;
    if(start==NULL)
    {
      printf("EMPTY\n");
    }
    else
    {
        printf("\n******CET ALLOTMENT LIST******\n");
        printf("RANK      NAME\n");
        while(temp!=NULL)
        {
            printf("%5d      %5s\n",temp->rank,temp->name);
            temp=temp->next;
        }
    }
}
int main()
{
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

