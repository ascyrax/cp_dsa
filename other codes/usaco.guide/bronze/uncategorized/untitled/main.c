#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int top=-1;
char stack[10];

void push(char a){
    top+=1;stack[top]=a;
}
char pop(){
    char a;a=stack[top--];
    return a;
}
void main()
{
int i=0;
char infix[100],t;
printf("Enter an infix operation ");
scanf("%s",&infix);
printf("The postfix version of the given infix operation is : ");
while(infix[i]!='\0')
{
t=infix[i];
if(isdigit(t))
{
printf("%c",infix[i]);
}
else
{
switch(t)
{
case '(':
{
push('(');
break;
}
case ')':
{
while(stack[top]!='(')
{
pop();
printf("%c",stack[top+1]);
}
pop();
break;
}
case '*':
{
push('*');
break;
}
case '/':
{
push('/');
break;
}
case '+':
{
if(stack[top]=='*' || stack[top]=='/')
{
while(stack[top]=='*' || stack[top]=='/')
{
pop();
printf("%c",stack[top+1]);
}
}
push('+');
break;
}
case '-':
{
if(stack[top]=='*' || stack[top]=='/')
{
while(stack[top]=='*' || stack[top]=='/')
{
pop();
printf("%c",stack[top+1]);
}
}
push('-');
break;
}
}
}
i=i+1;
}
while(top!=-1)
{
pop();
printf("%c",stack[top+1]);
}
}
