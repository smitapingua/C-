//calculating power recursively
#include<iostream>
#include<conio.h>

using namespace std;

float powr(float x,int y)
{
    if(y==0)
        return 1.0;
    else
        return (x*powr(x,y-1));
}

int main()
{
    float b;
    int r;
    cout<<"Enter the required no.:";
    cin>>b;
    cout<<"\nEnter the power to be calculated:";
    cin>>r;
    float ans;
    if(r>=0)
    {
        ans=powr(b,r);
        cout<<"\nThe result of "<<b<<"^"<<r<<" is:"<<ans;
    }
    if(r<0)
    {
        ans=powr(b,-r);
        cout<<"\nThe result of "<<b<<"^"<<r<<" is:1/"<<ans;
    }
    getch();
    return 0;
}
