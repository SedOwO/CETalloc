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

node* generatePQueue(node* catlist,node* studentList,char ch){
	while(studentList){
		if((studentList->cat)[0]==ch){
			node* new1=malloc(sizeof(node));
			new1->lptr=new1->rptr=NULL;
			strcpy((new1->name),(studentList->name));
			new1->rank=studentList->rank;
			strcpy((new1->cat),(studentList->cat));
			new1->uid=studentList->uid;
			
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
TRAVERSE:	studentList=studentList->rptr;
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

node* aiopq(college a[]){
        node *start=NULL;
        for(int i=0;i<6;i++){
                for(int j=0;j<25;j++){
                        node* nNode=malloc(sizeof(node));
                        nNode->lptr=nNode->rptr=NULL;
                        (a[i].(pupils[j]))->uid= nNode->uid;
                        (a[i].(pupils[j]))->rank= nNode->rank;
                        strcpy(nNode->name,(a[i].(pupils[j]))->name);
                        strcpy(nNode->cat,(a[i].(pupils[j]))->cat);
                        strcpy(nNode->clg,(a[i].(pupils[j]))->clg);
                        
                        node* temp=start;
                        if(start==NULL||nNode->uid < start->uid) {
                                nNode->rptr=start;
                                start=nNode;
                        }
                        else{
                                while(temp->rptr!=NULL && temp->rptr->uid<=nNode->uid){
                                        temp=temp->rptr;
                                }
                                nNode->rptr=temp->rptr;
                                temp->rptr=nNode;
                        }
                }
        }
        
}

node *generateBST(node *root, node* studentList){
        while(studentList){
                node* new1=malloc(sizeof(node));
                new1->uid=studentList->uid;
                new1->rank=studentList->rank;
                strcpy(new1->name,studentList->name);
                strcpy(new1->cat,studentList->cat);
                strcpy(new1->clg, studentList->clg);
                
                if (!root)
                        root=new1;
		else{
                node *pathFinder = root, *temp;
                while (pathFinder){
                        temp = pathFinder;
                        if (new1->uid >= pathFinder->uid)
                                pathFinder = pathFinder->rptr;
                        else
                                pathFinder = pathFinder->lptr;
                }

                if (new1->uid >= temp->uid)
                        temp->rptr = new1;
                else
                        temp->lptr = new1;
                }
		studentList=studentList->rptr;
        }
         return root;
}

void displayALL(node *newStudentList){
    	    temp=newStudentList;
            printf("\n******CET ALLOTMENT LIST******\n");
            printf("%20s%20s%20s%20s%20s","UID","NAME","RANK","CATEGORY","COLLEGE");
            while(temp!=NULL){
                printf("20%d20%s20%d20%s20%s",temp->uid,temp->name,temp->rank,temp->cat,temp->clg);
                temp=temp->lptr;
            }
}

node* deleteStudents(node* newStudentList){
	printf("Enter number of students withdrawing from KEA College allocation:\n");
	int n,uid, foundFlag;
	node* temp;
	scanf("%d", &n);
	printf("Enter the UIDs of %d students:\n", n);
	
	while(n--){
		scanf("%d",&uid);
		temp= newStudentList; foundFlag=0;
		while(temp!=NULL){ //to access every node
			if(temp->uid==uid){
				foundFlag=1;
				printf("Removing student %d and freeing seat in %s\n", temp->uid, temp->clg); 
				if(temp==newStudentList){//first node nuking
					newStudentList=newStudentList->rptr;
					free(newStudentList->lptr);
					newStudentList->lptr=NULL;
					temp=newStudentList;
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
	return newStudentList;	
}

void nukeTree(node* root){
	if(root){
		nukeTree(root->lptr);
		nukeTree(root->rptr);
		free(root);
	}
}
void  nukeQueue(node* q){
	node* nuker;
	while(q){
		nuker=q;
		q=q->rptr;
		free(nuker);
	}
}

void displayStudent(root){
	int keyid;
	printf("\nIndividual student result\n");
	printf("Enter your UID:  ");
	scanf("%d", keyid);
	while(root){
		if(keyid==root->uid)
			break;
		if(keyid>root->uid)
			root=root->rptr;
		else 
			root=root->lptr;	
	}
	//now root points to key node
	if(!root){
		printf("Student %d not found\n", uid);
		return;
	}
	printf("\nUID: %d\nName: %s\nRank: %d\n\nAllocated College: %s\n",root->uid, root->name,root->rank, root->clg);
}

void displayCollege(int a[]){
	int clg, i;
	printf("Which college?:\n1.RVCE 2.MSRIT 3.BMSCE 4.RNSIT 5.JSSATE\n");
	scanf("%d",&clg);
	clg--;//cuz array index starts from 0
	printf("Student list of %s\n",a[clg]->name);
	printf("%20s%20s\n","UID","NAME");
	for(int i=0;i<25;i++)
		printf("%20d%20s\n",a[clg].pupils[i]->uid,a[clg].pupils[i]->name);
}

int main(){
	int i,ch;
	node* studentList;
	studentList = input(studentList);
	node* A1, *B2, *GM;//prioity queues
	A1=generatePQueue(A1,studentList, 'A');
	B2=generatePQueue(B2,studentList, 'B');
	GM=generatePQueue(GM,studentList, 'G');
		
	//initializing array of colleges
	college a[6]; 
	strcpy(a[0].name,"RVCE");
	strcpy(a[1].name,"PESU");
	strcpy(a[2].name,"MSRIT");
	strcpy(a[3].name,"BMSCE");
	strcpy(a[4].name,"RNSIT");
	strcpy(a[5].name,"JSSATE");
	
	//college allocation round 1
	for(i=0; i<6;i++)
		a[i]=collegeAllocator(a[i],&A1,&B2,&GM);
		
	//making newStudentList
	node* newStudentList = aiopq(a);
	//BST for round 1
	node* root=NULL; 
	root = generateBST(root, newStudentList);
	
	//display menue for first round
	//result for round 1 
	while(1){
		printf("\nRound one Results:\n1.All Student List  2.Individial result  3. College wise  4.Proceede to round 2\n");
		scanf("%d",&ch);
		switch(ch){
		case 1: displayAll(newStudentList); break;
		case 2: displayStudent(root); break;
		case 3: displayCollege(a); break;
		default: goto EOR1;
		}
	}
EOR1:	//phenoix section aka garbage collection.
	newStudentList = deleteStudents(newStudentList);
	nukeTree(root);
	nukeQueue(A1); A1=NULL;
	nukeQueue(B2); B2=NULL;
	nukeQueue(GM); GM=NULL;
	
	A1=generatePQueue(A1,newStudentList, 'A');
	B2=generatePQueue(B2,newStudentList, 'B');
	GM=generatePQueue(GM,newStudentList, 'G');
	//college allocation round 2
	for(i=0; i<6;i++)
		a[i]=collegeAllocator(a[i],&A1,&B2,&GM);
	//remaking newStudentList
	node* newStudentList = aiopq(a);
	//to remake tree for round 2
	root=NULL; 
	root = generateBST(root, newStudentList);
	
	//display menue for second round
	//result for round 2 
	while(1){
		printf("\nRound two Results:\n1.All Student List  2.Individial result  3. College wise\n");
		scanf("%d",&ch);
		switch(ch){
		case 1: displayAll(newStudentList); break;
		case 2: displayStudent(root); break;
		case 3: displayCollege(a); break;
		default: return 0;
		}
	}
	
	
}
