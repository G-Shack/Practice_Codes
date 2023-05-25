#include<iostream>
using namespace std;

class Diagonal
{
    private:
        int n;
        int *A;
    public:
    Diagonal()
    {
        this->n=2;
        A = new int[2];
    }
    Diagonal(int n)
    {
        this->n=n;
        A = new int[n];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    ~Diagonal(){delete []A;};
};

void Diagonal::Set(int i, int j, int x)
{
    if(i==j)
        A[i-1]=x;
}

int Diagonal::Get(int i,int j)
{
    if(i==j)
        return A[i-1];
    else    
        return 0;
}

void Diagonal::Display()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j)
                cout<<A[i]<<" ";
            else    
                cout<<"0 ";
        }
        cout<<"\n";
    }
}

int main()
{
    Diagonal obj(4);
    obj.Set(1,1,1);obj.Set(2,2,2);obj.Set(3,3,3);obj.Set(4,4,4);
    obj.Display();
}