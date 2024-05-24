#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev, *next;
    char name[25],des[10],dept[10],ssn[10];
    int sal,ph_no;
} *newnode, *head = NULL, *temp, *tail,*cur;

void create() {
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter Name:");
    scanf("%s", newnode->name);
    printf("Enter SSN:");
    scanf("%s",newnode->ssn);
    printf("Enter Department:");
	scanf("%s",newnode->dept);
	printf("Enter Designation:");
	scanf("%s",newnode->des);
    printf("Enter Salary:");
    scanf("%d",&newnode->sal);
    printf("Enter Phone Number:");
    scanf("%d", &newnode->ph_no);
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL){ 
        temp = tail = head = newnode;
    }
    else{
        temp->next = newnode;
        newnode->prev = temp;
        temp = temp->next;
    }
}

void insertfront(){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->next = NULL;
    printf("\nEnter Name:");
    scanf("%s", newnode->name);
    printf("Enter SSN:");
    scanf("%s",newnode->ssn);
    printf("Enter Department:");
	scanf("%s",newnode->dept);
	printf("Enter Designation:");
	scanf("%s",newnode->des);
    printf("Enter Salary:");
    scanf("%d",&newnode->sal);
    printf("Enter Phone Number:");
    scanf("%d", &newnode->ph_no);
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void delfront(){
    temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}

void insertend(){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->next = NULL;
    printf("\nEnter Name:");
    scanf("%s", newnode->name);
    printf("Enter SSN:");
    scanf("%s",newnode->ssn);
    printf("Enter Department:");
	scanf("%s",newnode->dept);
	printf("Enter Designation:");
	scanf("%s",newnode->des);
    printf("Enter Salary:");
    scanf("%d",&newnode->sal);
    printf("Enter Phone Number:");
    scanf("%d", &newnode->ph_no);
    tail=head;
while(tail->next!=NULL){
    tail = tail->next;
 }
    tail->next=newnode;
    newnode->prev=tail;
    newnode->next=NULL;
}

void delend(){
    temp = head;
while (temp->next != NULL){
        cur = temp;
        temp = temp->next;
}
   cur->next=NULL;
   free(temp);
}

void display(){
    temp = head;
    int count = 1;
   while (temp!= NULL){
       printf("\nDetails of Employee %d",count++);
       printf("\nName:%s\nSSN:%s\nDepartment:%s\nDesignation:%s\nSalary:%d\nPhone Number:%d",temp->name,temp->ssn,temp->dept,temp->des,temp->sal,temp->ph_no);
          temp = temp->next;
    }
}

void dequeue(){   
    int choice;
    while (1){
        printf("\nDLL as Double Ended Queue\n");
        printf("\n1.InsertQueueFront\n2.DeleteQueueFront\n3.InsertQueueRear\n4.DeleteQueueRear\n5.DisplayStatus\n6.Exit \n");
        scanf("%d", &choice);
    switch (choice)
    {
        case 1:insertfront();break;
        case 2:delfront();break;
        case 3:insertend();break;
        case 4:delend();break;
        case 5:display();break;
        case 6:exit(0);break;
        default:printf("\nInvalid Choice!");break;
     }
  }
}

int main(){
    struct node n;
    int i, m, ch;
 while (1){
    printf("\nDouble linkedlist for Employee details\n\n1.Create\n2.Insert at front\n3.Delete at front\n4.Insert at end\n5.Delete at end\n6.DLL as Double ended queue\n7.Display\n8.Exit\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch){
        case 1 :printf("\nEnter No. of Employee.:");
                scanf("%d", &m);
                for (i = 0; i < m; i++){
                  create();}
                 break;
        case 2:insertfront();break;
        case 3:delfront();break;
        case 4:insertend();break;
        case 5:delend();break;
        case 6:dequeue();break;
        case 7:display();break;
        case 8:exit(1);
        default: printf("\ninvalid choice\n");break;
        }
    }
}
