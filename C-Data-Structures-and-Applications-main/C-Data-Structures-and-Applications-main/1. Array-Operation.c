#include<stdio.h>
#include<stdlib.h>
int a[10], n,i;

void create() {
    printf("Enter the number of elements :");
    scanf("%d",&n);
    printf("Enter the element in the array :");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}

void display() {
     printf("Elements in the Array are :");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
         printf(" ");
   }
}

int elem ,pos;
void insert(){
    printf("Enter the position for new element : ");
    scanf("%d",&pos);
    printf("Enter the element to be inserted : ");
    scanf("%d",&elem);
    for (i=n-1;i>=pos-1;i--){
        a[i+1]=a[i];
    }
    a[pos-1]=elem;
    n=n+1;
}

void delete(){
    printf("Enter the position to delete :");
    scanf("%d",&pos);
    printf("Deleted element is %d", a[pos-1]);
    for(i=pos;i<=n-1;i++){
        a[i-1]=a[i];
    }
     n=n-1;
}

int main(){
    int ch;

while(1)
{
 printf("\n____ARRAY OPERATION____\n");
 printf("1.Create\n2.Display\n3.Insert\n4.Delete\n5.Exit\n");
 printf("Enter Your Choice:");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:create();break;
 case 2:display();break;
 case 3:insert();break;
 case 4:delete();break;
 case 5:exit(0);break;
 default :printf("INVALID CHOICE\n");
 }
}
return 0;
}
