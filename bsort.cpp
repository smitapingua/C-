#include<iostream>
#include<conio.h>

using namespace std;

template <class T>
struct node
{
	T data;
	node *next;
	node *previous;
};

template <class T>
class bsort
{
	node<T> *head;
	node<T> *tail;
    node<T> *temp;
    public:
        bsort()
        {
            head=NULL;
            tail=NULL;
            temp=NULL;
        }
        void insertend(int);
        void insertbeg(int);
        void sort();
        void swap(T &,T &) ;
        void display();
};

template <class T>
void bsort<T>::insertend(int value)
{
    temp=new node<T>;
    temp->data=value;
    temp->next=NULL;
    temp->previous=NULL;
    if(head=='\0')
    {
		head=temp;
		tail=temp;
	}
    else
    {
    	tail->next=temp;
    	temp->previous=tail;
    	tail=temp;
    }
    cout<<"\nThe element is inserted successfully.....";
    getch();
}

template <class T>
void bsort<T>::insertbeg(int value)
{
    temp=new node<T>;
    temp->data=value;
    temp->next=head;
    temp->previous=NULL;
    if(head=='\0')
    {
		head=temp;
		tail=temp;
	}
	else
	{
		temp->next=head;
        head->previous=temp;
        head=temp;
	}
    cout<<"\nThe element is inserted successfully.....";
    getch();
}

template <class T>
void bsort<T>::display()
{
    if(head=='\0')
    {
        cout<<"\nArray doesn't exist'...";
        getch();
        return;
    }
    node<T> *t=head;
    cout<<"\n";
    while(t!='\0')
    {
    	cout<<t->data<<'\t';
        t=t->next;
    }
}

template <class T>
void bsort<T>::sort()
{
	node<T> *t=head;
	node<T> *p=tail;
	node<T> *q=p->previous;
	while(t->next!='\0')
	{
		while(p->previous!=t)
		{
			if(p->data<q->data)
				swap(p->data,q->data);
			p=q;
			q=q->previous;
		}
		if(t->data>p->data)
			swap(t->data,p->data);
		cout<<"\nArray after each iteration:";
		display();
		t=t->next;
		p=tail;
		q=p->previous;
	}
}

template <class T>
void bsort<T>::swap(T &a,T &b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
	return;
}

int main()
{
	bsort<int> obj;
	int x,y;
	do
	{
		system("cls");
		cout<<"The menu is:"
			<<"\n1.Insert in end of array"
			<<"\n2.Insert in beginning of array"
			<<"\n3.Sort the array"
			<<"\n4.Display the array"
			<<"\n5.Exit";
		cout<<"\nEnter the choice:";
		cin>>x;
		switch(x)
		{
			case 1:cout<<"Enter the element:";
                     cin>>y;
                     obj.insertend(y);
                     break;
            case 2:cout<<"Enter the element:";
                     cin>>y;
                     obj.insertbeg(y);
                     break;
            case 3:obj.sort();
            		cout<<"\nThe sorted array is:"<<endl;
            		obj.display();
            		getch();
            		break;
            case 4:obj.display();
            		getch();
            		break;
            case 5:exit(0);
            default:cout<<"\nWrong choice is entered...";
            		getch();
            		break;
		}
	}while(x!=5);
	getch();
	return 0;
}
