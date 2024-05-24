#include<stdio.h>
#include<string.h>

char infix[20],postfix[20],stack[20];
int top=-1;

int isEmpty(){
    if(top<0)
      return 1;
    else
      return 0;
}

void push(char symbol){
    ++top;
    stack[top]=symbol;
    return;
}

int pop(){
    int temp=stack[top];
    --top;
    return temp;
}

int precedence(char symbol)
{
  switch(symbol)
    { 
     case '+':        
     case '-':
          return 1;
     case '*':
     case '/':
     case '%':
          return 2;
     case '^':
          return 3;
     default: return 0;
        break;
    }
}

void infix_postfix(char*infix,char*postfix){
    int i,j=0;
    char symbol,next;

    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
    
       switch(symbol)
        {
            case '(':push(symbol);
                    break;
            case ')':while((next=pop())!='(')
                    postfix[j++]=next;
                    break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':while(!isEmpty()&&precedence(stack[top])>=precedence(symbol))
                    postfix[j++]=pop();
                    push(symbol);
                    break;
            default:postfix[j++]=symbol;
                    break;
    }
}
while(!isEmpty()){
    postfix[j++]=pop();
}
postfix[j]='\0';
}

int main(){
    printf("Enter a valid infix expression:");
    scanf("%s",infix);

    infix_postfix(infix,postfix);

    printf("The Infix expression is:%s\n",infix);
    printf("The Postfix expression is:%s",postfix);

    return 0;
}
