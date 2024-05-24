#include<stdio.h>
#include<string.h>

void selection_sort(char s[]){
    char temp;
    int l,i,j,min;
    l=strlen(s);
    for(i=0;i<l-1;i++){
        min=i;
        for(j=i+1;j<l;j++){
            if(s[j]<s[min]){
                min=j;
            }
        }
    temp=s[min];
    s[min]=s[i];
    s[i]=temp;
}
printf("\nThe Sorted Array is(Selection Sort) : %s",s);
}

void insertion_sort(char s[]){
    int i,j,l;
    char temp;
    l=strlen(s);
    for(i=1;i<l;i++){
         temp=s[i];
         j=i-1;
      while(j>=0&&s[j]>temp){
            s[j+1]=s[j];
             j--;
      }
        s[j+1]=temp;
    }
    printf("The Sorted Array is(Insertion sort) : %s",s);
}

int main(){
    char s[200];
    printf("Enter the Character array :");
    scanf("%s",s);
    insertion_sort(s);
    selection_sort(s);
}
