#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

struct node
{
	char data;
	node *next;
};

class stack
{
	public:
		node *top;
		stack()
		{
			top=NULL;
		}
		int isempty();
		void push(char);
		char pop();
};

int stack::isempty()
{
	if(top==NULL)
		return 1;
	else 
		return 0;
}

void stack::push(char val)
{
	node *temp=new node;
	temp->next='\0';
	temp->data=val;
	if(top=='\0')
		top=temp;
	else
	{
		temp->next=top;
		top=temp;
	}
}

char stack::pop()
{
	if(!isempty())
	{
		node *t=top;
		char r=t->data;
		if(top->next=='\0')
			top='\0';
		else
			top=top->next;
		delete t;
		return r;
	}
}

class post
{
	public:
		stack s;
		char expr[100];
		void input();
		void check();
};

void post::input()
{
	cout<<"\nEnter the expression:";
	gets(expr);
}

void post::check()
{
	char ch;
	int i;
	for(i=0;i<strlen(expr);i++)
	{
		if(expr[i]=='{' || expr[i]=='(' || expr[i]=='[')
			s.push(expr[i]);
		else if(expr[i]==')')
		{
			ch=s.pop();
			if(ch=='(')
				continue;
			else
			{
				if(ch=='[' || ch=='{')
				{
					cout<<"\nParantheses are not balanced...";
					s.push(ch);
					break;
				}
			}
		}
		else if(expr[i]=='}')
		{
			ch=s.pop();
			if(ch=='{')
				continue;
			else
			{
				if(ch=='(' || ch=='[')
				{
					cout<<"\nParantheses are not balanced...";
					s.push(ch);
					break;
				}
			}
		}
		else if(expr[i]==']')
		{
			ch=s.pop();
			if(ch=='[')
				continue;
			else
			{
				if(ch=='(' || ch=='{')
				{
					cout<<"\nParantheses are not balanced...";
					s.push(ch);
					break;
				}
			}
		}
	}
	if(expr[i]=='\0' && s.top!='\0')
		cout<<"\nParantheses are not balanced...";
	if(expr[i]=='\0' && s.top=='\0')
		cout<<"\nParantheses are balanced...";
}

int main()
{
	post p;
	p.input();
	p.check();
	getch();
	return 0;
}
