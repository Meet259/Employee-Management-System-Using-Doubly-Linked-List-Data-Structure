#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count = 0;

struct node{
	int ssn;
	char name[50];
	char dept[20];
	float sal;
	long long int phno;
	struct node *next;
	struct node *prev;
}*head,*last;

void createEmployeeList(int n);
void insertAtBeginning();
void insertAtLast();
void deleteAtBeginning();
void deleteAtEnd();
void displayEmployeeList();

void main(){
	int choice;
	printf("-------------Menu------------\n");
	printf("1.Create Employee List\n2.Display Employee List\n3.Insert Employee Data At Beginning\n4.Insert Employee Data At End\n");
	printf("5.Delete Employee Data From Beginning\n6.Delete Employee Data From End\n");
	printf("7.To Show DLL as Deque\n8.Exit\n");
	printf("-----------------------------\n");
	while(1){
		printf("\nEnter Choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				int n;
				printf("\nEnter no of employee data you want to insert : ");
				scanf("%d",&n);
				createEmployeeList(n);
				break;
			}
			case 2:
				displayEmployeeList();
				break;
			case 3:
				insertAtBeginning();
				break;
			case 4:
				insertAtLast();
				break;
			case 5:
				deleteAtBeginning();
				break;
			case 6:
				deleteAtEnd();
				break;
			case 7:{
				printf("To show DLL as deque\n");
				printf("1.Perform insert and deletion operation by calling insertAtBeginning() and deleteAtEnd() respectively\n");
				printf("OR\n");
				printf("2.Perform insert and deletion operation by calling insertAtLast() and deleteAtBeginning() respectively\n");
				break;
			}
			case 8:
				exit(0);
				break;
			default:
				printf("Wrong Choice\n");
				break;
		}
	}
}

void createEmployeeList(int n){
	int i;
	struct node *newNode;
	if(n>=1){
		head=(struct node *)malloc(sizeof(struct node));
		if(head==NULL){
			printf("Unable to allocate memory\n");
		}
		else{
			printf("\nEnter SSN of Employee 1 : ");
			scanf("%d",&head->ssn);
			printf("Enter Name of Employee 1 : ");
			scanf("%s",&head->name);
			printf("Enter Department of Employee 1 : ");
			scanf("%s",&head->dept);
			printf("Enter Salary of Employee 1 : ");
			scanf("%f",&head->sal);
			printf("Enter Phone Number of Employee 1 : ");
			scanf("%lld",&head->phno);
			
			head->next=NULL;
			head->prev=NULL;
			last=head;
			count++;
			
			for(i=2;i<=n;i++){
				newNode=(struct node *)malloc(sizeof(struct node));
				if(newNode==NULL){
					printf("Unable to allocate memory\n");
				}
				else{
					printf("\nEnter SSN of Employee %d : ",i);
					scanf("%d",&newNode->ssn);
					printf("Enter Name of Employee %d : ",i);
					scanf("%s",&newNode->name);
					printf("Enter Department of Employee %d : ",i);
					scanf("%s",&newNode->dept);
					printf("Enter Salary of Employee %d : ",i);
					scanf("%f",&newNode->sal);
					printf("Enter Phone Number of Employee %d : ",i);
					scanf("%lld",&newNode->phno);
					
			
					newNode->next=NULL;
					newNode->prev=last;
					last->next=newNode;
					last=newNode;
					count++;
				}
			}
		}
	}
}

void insertAtBeginning(){
	struct node *newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	if(newNode==NULL){
		printf("Unable to allocate memory\n");
	}
	else{
		printf("\nEnter SSN of Employee : ");
		scanf("%d",&newNode->ssn);
		printf("Enter Name of Employee : ");
		scanf("%s",&newNode->name);
		printf("Enter Department of Employee : ");
		scanf("%s",&newNode->dept);
		printf("Enter Salary of Employee : ");
		scanf("%f",&newNode->sal);
		printf("Enter Phone Number of Employee : ");
		scanf("%lld",&newNode->phno);
		
		newNode->prev=NULL;
		if(head==NULL){
			newNode->next=NULL;
			head=newNode;
			last=head;
			count++;
		}
		else{
			newNode->next=head;
			head->prev=newNode;
			head=newNode;
			count++;
		}
	}
}

void insertAtLast(){
	struct node *newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	if(newNode==NULL){
		printf("Unable to allocate memory\n");
	}
	else{
		printf("\nEnter SSN of Employee : ");
		scanf("%d",&newNode->ssn);
		printf("Enter Name of Employee : ");
		scanf("%s",&newNode->name);
		printf("Enter Department of Employee : ");
		scanf("%s",&newNode->dept);
		printf("Enter Salary of Employee : ");
		scanf("%f",&newNode->sal);
		printf("Enter Phone Number of Employee : ");
		scanf("%lld",&newNode->phno);
		
		newNode->next=NULL;	
		if(head==NULL){
			newNode->prev=NULL;
			head=newNode;
			last=head;
			count++;
		}
		else{
			last->next=newNode;
			newNode->prev=last;
			last=newNode;
			count++;
		}
	}
}

void deleteAtBeginning(){
	struct node *temp;
	if(head==NULL){
		printf("List is Empty\n");
	}
	else{
		temp=head;
		if(temp->prev==temp->next){
			printf("\nDeleted Employee Data From Beginning\n");
			printf("%d\t\t  %s\t\t  %s\t\t  %f\t\t  %lld\t\t\n",temp->ssn,temp->name,temp->dept,temp->sal,temp->phno);
			head=NULL;
			last=NULL;
			free(temp);
			count--;
		}
		else{
			printf("\nDeleted Employee Data From Beginning\n");
			printf("%d\t\t  %s\t\t  %s\t\t  %f\t\t  %lld\t\t\n",temp->ssn,temp->name,temp->dept,temp->sal,temp->phno);
			head=head->next;
			head->prev=NULL;
			count--;
		}
	}
}

void deleteAtEnd(){
	struct node *temp;
	if(head==NULL){
		printf("List is Empty\n");
	}
	else{
		temp=last;
		if(temp->prev==temp->next){
			printf("\nDeleted Employee Data From End\n");
			printf("%d\t\t  %s\t\t  %s\t\t  %f\t\t  %lld\t\t\n",temp->ssn,temp->name,temp->dept,temp->sal,temp->phno);
			head=NULL;
			last=NULL;
			free(temp);
			count--;
		}
		else{
			printf("\nDeleted Employee Data From End\n");
			printf("%d\t\t  %s\t\t  %s\t\t  %f\t\t  %lld\t\t\n",temp->ssn,temp->name,temp->dept,temp->sal,temp->phno);
			last=last->prev;
			last->next=NULL;
			free(temp);
			count--;
		}
	}
}

void displayEmployeeList(){
	struct node *temp;
	temp=head;
	if(head==NULL){
		printf("List is Empty\n");
	}
	else{
		printf("\nEmployee list is\n");
		while(temp!=NULL){
			printf("%d\t\t  %s\t\t  %s\t\t  %f\t\t  %lld\t\t\n",temp->ssn,temp->name,temp->dept,temp->sal,temp->phno);
			temp=temp->next;
		}
		printf("\nNumber of Employees is %d\n",count);
	}
}
