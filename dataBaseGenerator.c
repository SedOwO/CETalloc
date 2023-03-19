#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student
{
        int uid;
        char name[20];
        char cat[2];  // changed
        int rank;     // order
        char clg[10]; // omfg hahaha
        struct Student *lptr, *rptr;
} node;

void createFile()
{
        int n = 150;
        node new1; //not a pointer, but a structure variable. 
        FILE *fp;
	fp = fopen("data.bin", "wb");
        printf("Number of students = 150\n");
        printf("\nEnter Student Details:\n UID   NAME   RANK   CATEGORY:\n");
        while (n--)
        {
                scanf("%d%s%d%s", &new1.uid, new1.name, &new1.rank, new1.cat);
               	fwrite(&new1, sizeof(node), 1, fp);
        }
        fclose(fp);
        printf("\n\nGenerated Binary file of 150 student record...\n\n");
}

/*
node* input(node *studentList){
        int n;
        FILE *fp;
	fp = fopen("data.bin", "rb");
        node tempStudent;
        printf("Number of students to import?:(<=150):\n");
        scanf("%d",&n);
        printf("\nImporting %d student data from database...\n\n",n);
        
        while(n--){
                node* new1=malloc(sizeof(node));
                new1->lptr=new1->rptr=NULL;
                
                fread(&tempStudent, sizeof(node), 1, fp);
                new1->uid = tempStudent.uid;
                strcpy(new1->name, tempStudent.name);
                new1->rank = tempStudent.rank;
                strcpy(new1->cat, tempStudent.cat);
                
                node* temp;
                if(!studentList)
                        studentList=new1;
                else{
                        studentList->lptr=new1;
                        new1->rptr=studentList;
                        studentList=new1;
                }
        }
        return studentList;
}

void displayAll(node *newStudentList){
    	    node* temp=newStudentList;
            printf("\n\nTestDisplay:\n");
            printf("%5s%20s%20s%20s%20s\n\n","UID","NAME","RANK","CATEGORY","COLLEGE");
            while(temp!=NULL){
                printf("%5d%20s%20d%20s%20s\n",temp->uid,temp->name,temp->rank,temp->cat,temp->clg);
                temp=temp->rptr;
            }
}
*/

void main()
{
	createFile();
/*	
	node* studentList=NULL;
	studentList = input(studentList);
	displayAll(studentList);
*/
}



