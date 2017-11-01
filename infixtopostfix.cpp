//converting infix to postfix
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

using namespace std;

struct node
{
	char data;
	node*next;
};

class stack
{
	
	public:
		node*top;
		stack()
		{
			top='\0';
		}
		void push(char);
		char pop();
		char rettop();
		int isempty();
}s;

char stack::rettop()
{
 char r;
 r=top->data;
 return r;
}

int stack::isempty()
{
	if(top=='\0')
	  return 1;  
	else
	 return 0;  	
}

void stack::push(char val)
{
	node*temp=new node;
	temp->data=val;
	temp->next='\0';
	temp->next=top;
	top=temp;
}

char stack::pop()
{
	node*T=top;
	if(!isempty())
	{
		char v=T->data;
		if(top->next=='\0')
		  top='\0';
		else
		 top=top->next;
		delete T;
		return v;  
		  
	}
}

class infix
{
	public:
		char exp[100];
		char postfix[100];
		void input();
		void inf();
		int weight(char);
		bool prece(char,char);
		
};

void infix::input()
{
	cout<<"\n\nEnter expression ";
	gets(exp);
	
}

void infix::inf()
{	
	stack s;
	s.push('(');
	int l=strlen(exp);
	exp[l]=')';
	int j=0;
	int i;
	for(i=0;i<=l;i++)
	{
		if(isalpha(exp[i])||isdigit(exp[i]))
		 postfix[j++]=exp[i];
		 
		else if(exp[i]=='(')
		  s.push(exp[i]);
		  
		else if(exp[i]==')')
		{
			char m=s.pop();
			while(m!='(')
			{
				postfix[j++]=m;
				m=s.pop();
			}	
		}  
		
		else if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
		{
			while(prece(s.rettop(),exp[i]))
				postfix[j++]=s.pop();
			s.push(exp[i]);
		}
	}
	
	cout<<"\n\nPostfix expression is ";
	for(i=0;i<j;i++)
	cout<<postfix[i];
}

int infix::weight(char op)
{
	int weight; 
	switch(op)
	{
	case '(':
		weight=1;
		break;
	case '+':
	case '-':
		weight = 2;
		break;
	case '*':
	case '/':
		weight = 3;
		break;	
	}
	return weight;
}
  
bool infix::prece(char op1, char op2)
{
	int w1 = weight(op1);
	int w2 = weight(op2); 
	if(w1 >=w2)
	  return true;
	else
	  return false;  
}

int main()
{
	infix i;
	i.input();
	i.inf();
	getch();
	return 0;
}
