#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}Node;

Node * create(Node *root,int x)
{
	if(x==-1)
	{
		return NULL;
	}
	root = (Node *)malloc(sizeof(Node));
	root->left=NULL;
	root->right=NULL;
	root->data=x;
	printf("Enter the Data to insert in left sub tree of %d or enter -1 \n",x);
	int d;
	scanf("%d",&d);
	root->left=create(root,d);
	printf("Enter the Data to insert in right sub tree of %d or enter -1 \n",x);
	int c;
	scanf("%d",&c);
	root->right=create(root,c);
	return root;
}

void preorder(Node *root)
{
	if(root!=NULL)
	{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}

void postorder(Node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
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

int main()
{
	int ch,k,key;
	Node *root=NULL;
	do{
		printf("Operations of Binary tree : \n");
		printf("1.Create\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Exit\n");
		printf("Enter your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter the Root :");
			scanf("%d",&k);
			root=create(root,k);
			break;
			case 2:preorder(root);
			printf("\n");
			break;
			case 3:inorder(root);
			printf("\n");
			break;
			case 4:postorder(root);
			printf("\n");
			break;
			case 5:
			printf("Enter the number to be searched : ");
			scanf("%d",&key);
			flag = 0; // resetting flag bit before each search
			search(root,key);
			if(flag==1)
			{
				printf("Entered Element is Present\n");
			}
			else{
				printf("Entered Element is not Present \n");
			}
			break;
			case 6:ch=0;
			break;
            default:printf("Invalid choice\n");
        }
	}while(ch!=0);
	return 0;
}
