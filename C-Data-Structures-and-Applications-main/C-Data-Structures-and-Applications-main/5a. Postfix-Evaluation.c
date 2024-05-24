#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

float stack[20];
int top=-1;

int isEmpty(){
    if(top<0)
      return 1;
    else
      return 0;
}

void push(char symbol){
    stack[++top]=symbol;
    return;
}

int pop(){
    int temp=stack[top];
    --top;
    return temp;
}

float compute(char symbol,int op1,int op2)
{
    switch(symbol)
    {
        case '+':return op1+op2;
                 break;
        case '-':return op1-op2;
                 break;
        case '*':return op1*op2;
                 break;
        case '/':return op1/op2;
                 break;
        case '%':return op1%op2;
                 break;
        case '^':return pow(op1, op2);
                 break;
        default :return 0;
    }
}

int main(){
    float res,op1,op2;
    char postfix[20],symbol;

    printf("Enter Postfix expression:");
    scanf("%s",postfix);

    for(int i=0;i<strlen(postfix);i++)
    {
        symbol=postfix[i];
        if(isdigit(symbol))
        {
            push(symbol-'0');
        }
        else
        {
          op2=pop();
          op1=pop();
          res=compute(symbol,op1,op2);
          push(res);
        }
    }
      res=stack[top];
    printf("Evaluated Postfix Expression is :%f",res);
}
