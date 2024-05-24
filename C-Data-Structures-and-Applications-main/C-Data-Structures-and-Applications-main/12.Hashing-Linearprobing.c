#include <stdio.h>
#define N 10

struct employee {
	int id;
       char name[15];	
};
typedef struct employee EMP;

EMP emp[N]; 
int HT[N]; 
int ht_size = 0;

void LinearProbing(int key) {
	int flag = 0, i = key % N; 
   if (HT[i] == -1) {
		flag=1;
		ht_size++;
	 }
    else{
	  printf("Collision detected\n");
	  i++;
      while(i != key && flag == 0 && ht_size < N){
			if(HT[i] == -1) {
				flag = 1;
				ht_size++;
				break;
			}
			i = (++i) % N; 
		}
       printf("Collision Avoided Successfully Using Linear probing\n");
	} 
	if (flag == 0)
		printf("Hash Table is Full\n");
	else {
		printf("Enter Employee ID: ");
		scanf("%d", &emp[i].id);
		printf("Enter Employee Name: ");
		scanf("%s",emp[i].name);
		HT[i] = i;
	}
}

void Display() {
	int i;
	int ch;
	printf("Would you like to hide empty values? (1/0) : ");
	scanf("%d",&ch);
	printf("HT Key \tEmp ID \tEmp Name\n");
	for(i=0;i<N;i++){
		if(ch == 1 && HT[i] == -1)
			continue;
		else
		 printf("%d \t %d \t%s \n",i, emp[i].id, emp[i].name);
	}
}

void main(){
	int key,i;
	int ch;
	for(i=0;i<N;i++) HT[i]=-1;
	do {
		printf("Enter Key(4 digit): ");
		scanf("%d", &key);
		LinearProbing(key);
		printf("Do you wish to continue (1/0): ");
		scanf("%d",&ch);
	} while(ch==1);
	Display();
}
