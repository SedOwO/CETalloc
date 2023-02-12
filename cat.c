// ONLY INSERTION PART IS DONE (PRIORITY SLL)

#include<stdlib.h>
#include<stdio.h>

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

