#include<iostream>
using namespace std;

class lowerTriM
{
    private:
        int n;
        int *A;
    public:
        lowerTriM()
        {
            this->n=2;
            A =new int[6];
        }
        lowerTriM(int n)
        {
            this->n=n;
            A=new int[(n*(n+1))/2];
        }
        void Set(int i, int j, int x);
        int Get(int i, int j);
        void Display();
        ~lowerTriM(){delete []A;}
};

void lowerTriM::Set(int i, int j, int x)
{
    if(i>=j)
        A[((i*(i-1))/2)+(j-1)]=x;
}

int lowerTriM::Get(int i, int j)
{
    if(i>=j)
        return A[((i*(i-1))/2)+(j-1)];
    return 0;
}

void lowerTriM::Display()
{
    for(int i=1; i<=n;i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i>=j)
                cout<<A[((i*(i-1))/2)+(j-1)]<<" ";
            else    
                cout<<"0 ";
        }
        cout<<"\n";
    }
}
int main()
{
    int d;
    cout<<"Enter Dimensions: ";
    cin>>d;
    lowerTriM lm(d);

    int x;
    cout<<"Enter all elements";
    for(int i=1; i<=d; i++)
    {
        for(int j=1; j<=d; j++)
        {
            cin>>x;
            lm.Set(i,j,x);
        }
    }
    lm.Display();
    return 0;
}