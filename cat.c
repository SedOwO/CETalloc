#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define A1SEATS 8 //maximim number of seats 
#define B2SEATS 8 //for reservations in clgs
#define GMSEATS 9 //for different categories
typedef struct Student{
	int uid;
	char name[20];
	int rank;
	char cat[2];
	char clg[10];
	struct Student *lptr, *rptr;
}node;
typedef struct College{
	char name[20];
	node* pupils[25];
}college;

node* input(node *studentList){
        int n;
        printf("Number of students(<=150):\n");
        scanf("%d",&n);
        printf("\nEnter Student Details:\n UID   NAME   RANK   CATEGORY:\n");
        while(n--){
                node* new1=malloc(sizeof(node));
                scanf("%d%s%d%s", &new1->uid, new1->name, &new1->rank, new1->cat);
                new1->lptr=new1->rptr=NULL;
                
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

node* generatePQueue(node* catlist,node* studentlist,char ch){
	while(studentlist){
		if((studentlist->cat)[0]==ch){
			node* new1=malloc(sizeof(node));
			new1->lptr=new1->rptr=NULL;
			strcpy((new1->name),(studentlist->name));
			new1->rank=studentlist->rank;
			strcpy((new1->cat),(studentlist->cat));
			new1->uid=studentlist->uid;
			
			if(!catlist){	
				catlist=new1;
				goto TRAVERSE;
			}
			//first node edge case
			if(catlist->rank > new1->rank){ //insert front	
				catlist->lptr=new1;
				new1->rptr=catlist;
				catlist=new1;
				goto TRAVERSE;
			}
			node *temp=catlist;
			//finding ascending priority spot
			while(temp->rptr && ((temp->rptr)->rank)<new1->rank)
				temp=temp->rptr; 
			//appending
			new1->rptr=temp->rptr;
			if(temp->rptr) //to avoid segufault
				(temp->rtpr)->lptr=new1;
			temp->rptr=new1;
			new1->lptr=temp;
		}
TRAVERSE:	studentlist=studentlist->rptr;
	}
	return catlist;
}

college collegeAllocator(college c, node** A1, node** B2, node** GM){
	int count=0;
	node* dQed;
	while(count<A1SEATS){
		dQed=malloc(sizeof(node));
		dQed->uid=(*A1)->uid;
		strcpy(dQed->name,(*A1)->name);
		dQed->rank=(*A1)->rank;
		strcpy(dQed->cat,(*A1)->cat);
		strcpy(dQed->clg,c.name);
		(c.pupils)[count]=dQed;
		
		if(!(*A1)->rptr)
			free(*A1);
		else{
			(*A1)=(*A1)->rptr;
			free((*A1)->lptr));
		}
		count++;
	}
	while(count<B2SEATS+A1SEATS){
		dQed=malloc(sizeof(node));
		dQed->uid=(*B2)->uid;
		strcpy(dQed->name,(*B2)->name);
		dQed->rank=(*B2)->rank;
		strcpy(dQed->cat,(*B2)->cat);
		strcpy(dQed->clg,c.name);
		
		if(!(*B2)->rptr)
			free(*B2);
		else{
			(*B2)=(*B2)->rptr;
			free((*B2)->lptr));
		}
		(c.pupils)[count]=dQed;
		count++;
	}
	while(count<A1SEATS+B2SEATS+GMSEATS){
		dQed=malloc(sizeof(node));
		dQed->uid=(*GM)->uid;
		strcpy(dQed->name,(*GM)->name);
		dQed->rank=(*GM)->rank;
		strcpy(dQed->cat,(*GM)->cat);
		strcpy(dQed->clg,c.name);
		
		if(!(*GM)->rptr)
			free(*GM);
		else{
			(*GM)=(*GM)->rptr;
			free((*GM)->lptr));
		}
		(c.pupils)[count]=dQed;
		count++;
	}
	return c;
}

node* deleteStudents(node* studentList){
	printf("Enter number of students withdrawing from KEA College allocation:\n");
	int n,uid, foundFlag;
	node* temp;
	scanf("%d", &n);
	printf("Enter the UIDs of %d students:\n", n);
	
	while(n--){
		scanf("%d",&uid);
		temp= studentList; foundFlag=0;
		while(temp!=NULL){ //to access every node
			if(temp->uid==uid){
				foundFlag=1;
				printf("Removing student %d and freeing seat in %s\n", temp->uid, temp->clg); 
				if(temp==studentList){//first node nuking
					studentList=studentList->rptr;
					free(studentList->lptr);
					studentList->lptr=NULL;
					temp=studentList;
					continue;
				}
				(temp->lptr)->rptr=temp->rptr; 
				if(temp->rptr) //if temp is NOT last node
					(temp->rptr)->lptr=temp->lptr; 
				free(temp);
			}
			temp=temp->rptr; //traversal wen miss
		}
		if(foundFlag==0)
			printf("Student %d not found\n", uid);
	}//end of one student nuking while
	return studentList;	
}

void nukeTree(node* root){
	if(root){
		nukeTree(root->lptr);
		nukeTree(root->rptr);
		free(root);
	}
}

void main(){
	node* studentlist;
	node* A1, *B2, *GM;//prioity queues
	A1=generatePQueue(A1,studentlist, 'A');
	B2=generatePQueue(B2,studentlist, 'B');
	GM=generatePQueue(GM,studentlist, 'G');
		
	//initializing array of colleges
	college a[6]; 
	strcpy(a[0].name,"RVCE");
	strcpy(a[1].name,"PESU");
	strcpy(a[2].name,"MSRIT");
	strcpy(a[3].name,"BMSCE");
	strcpy(a[4].name,"RNSIT");
	strcpy(a[5].name,"JSSATE");
	
	//college allocation round 1
	for(int i=0; i<6;i++)
		a[i]=collegeAllocator(a[i],&A1,&B2,&GM);
	
	//to remake tree for round 2
	nukeTree(root);
	root=NULL;
	
	
}
