#include<stdio.h>

void toh(int n,char source,char destination,char auxillary){
    if(n==1){
        printf("Move disk 1 from rod %c to rod %c",source,destination);
        return ;
    }
    toh(n-1,source ,auxillary,destination);
    printf("\nMove disk %d from rod %c to rod %c\n ",n,source,destination);
    toh(n-1,auxillary,destination,source);
}

int main(){
    int n;
    printf("Enter No. of disk :");
    scanf("%d",&n);
    toh(n,'A','B','C');
    return 0;
}
