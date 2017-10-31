#include<iostream>
#include<conio.h>

using namespace std;

class queue
{
    int q[50];
    int size,front,rear;
    public:
        queue()
        {
            front=-1;
            rear=-1;
            size=0;
            for(int i=0;i<size;i++)
                q[i]=0;
        }
        void enter();
        void enqueue(int);
        void dequeue();
        int isfull();
        int isempty();
        void display();
};

void queue::enter()
{
    cout<<"Enter the size of queue:";
    cin>>size;
}

int queue::isfull()
{
    if(front==(rear+1)%size)
        return 1;
    else
        return 0;
}

int queue::isempty()
{
    if(rear==(front+1)%size)
        return 1;
    else
        return 0;
}

void queue::display()
{
    if(front==-1 && rear==-1)
    {
        cout<<"\nQueue is empty...";
        return;
    }
    else
    {
        cout<<"\nThe queue is:"<<endl;
        for(int i=front;i<=rear;i++)
            cout<<q[i]<<'\t';
    }
}

void queue::enqueue(int ele)
{
    if(isfull())
        {
            cout<<"\nQueue is full";
            return;
        }
    else
    {
        if(front==-1 && rear==-1)
            front=rear=0;
        else
            rear++;
        q[rear]=ele;
        cout<<"\nElement inserted successfully...";
    }
}

void queue::dequeue()
{
    if(front==-1 && rear==-1)
        {
            cout<<"\nQueue is empty";
            return;
        }
    else
        {
            if(front==rear)
            {
                cout<<"\n"<<q[front]<<" deleted succesfully...";
                front=rear=-1;
            }
            else
            {
                cout<<"\n"<<q[front]<<" deleted succesfully...";
                front++;
            }
        }
}

int main()
{
    queue obj;
    int e;
    char ch;
    obj.enter();
    do
    {
        cout<<"The operations are:"
            <<"\n1.Insert in queue"
            <<"\n2.Delete from queue"
            <<"\n3.Display the queue"
            <<"\n4.Exit";
        cout<<"\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
            case '1':cout<<"Enter the element to be inserted:";
                     cin>>e;
                     obj.enqueue(e);
                     break;
            case '2':obj.dequeue();
                     break;
            case '3':obj.display();
                     break;
            case '4':exit(0);
                     break;
            default:cout<<"Wrong choice is entered...";
                    break;
            
        }
        cout<<"\nDo you want more?";
        cin>>ch;
        system("cls");
    }while(ch=='y' || ch=='Y');
    getch();
    return 0;
}
                

    
