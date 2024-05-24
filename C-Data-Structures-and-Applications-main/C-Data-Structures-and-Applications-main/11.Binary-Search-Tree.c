#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

void inorder(struct node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}

void preorder(struct node* root){
    if(root==NULL) return;
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}

struct node* create(int value){
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data =value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* insert(struct node* node,int value){
    if(node ==NULL) return create(value);
   if(value<node->data)
   node->left=insert(node->left,value);
   else node->right=insert(node->right,value);
    return node;
}

int flag=0;
void search(struct node* root,int key){
    if(root->data==key){
        flag=1;
        return;
    }
    else{
    if(flag==0 && root->left!=NULL){
        search(root->left,key);
    }
    if(flag==0 && root->right!=NULL){
        search(root->right,key);
    }
    return;
    }
}

int main(){
    int i,n,k,m,ch;
    printf("Enter the No. of values:");
    scanf("%d",&n);
    struct node* root=NULL;
  while(1){
      printf("\nBinary Search Tree\n");
      printf("1.Create\n");
      printf("2.Traversal\n");
      printf("3.Search\n");
      printf("4.Exit\n");
      printf("Enter your choice:");
      scanf("%d",&ch);
      switch(ch){
          case 1:for(i=0;i<n;i++){
                printf("Enter node :");
                scanf("%d",&k);
                root=insert(root,k);}
                break;
          case 2:printf("\nInorder :");
                   inorder(root);
                printf("\nPreorder :");
                   preorder(root);
                printf("\nPostorder :");
                   postorder(root);
                break;
          case 3:printf("Enter the Element to search:");
                 scanf("%d",&m);
                 flag = 0; // resetting flag bit before each search
                 search(root,m);
                 if(flag==0) printf("Element %d not found",m);
                 else printf("Element %d found",m);
                 break;
          case 4:exit(0);
          default:printf("Invalid choice!!");
       }
   }
}
