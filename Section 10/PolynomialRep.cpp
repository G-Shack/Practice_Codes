#include<iostream>
using namespace std;

class Term
{
    public:
        int coeff;
        int exp;
};

class Poly
{
    private:
        int n;
        Term *t;
    public:
        Poly(int n)
        {
            this->n=n;
            t = new Term[n];
        }
        ~Poly()
        {
            delete []t;
        }

        Poly operator+(Poly p);
        friend istream & operator>>(istream &is, Poly &p1);
        friend ostream & operator<<(ostream &os, Poly &p1);

};

Poly Poly::operator+(Poly p)
{
    Poly *sum=new Poly(n+p.n);
    int i,j,k;
    i=j=k=0;
    while(i<n && j<p.n)
    {
        if(t[i].exp>p.t[j].exp)
            sum->t[k++]=t[i++];
        else if(p.t[j].coeff>t[i].coeff)
            sum->t[k++]=p.t[j++];
        else
        {
            sum->t[k]=t[i++];
            sum->t[k++].coeff += p.t[j++].coeff;
        }
    }
    for(;i<n;i++)sum->t[k++]=t[i];
    for(;j<p.n;j++)sum->t[k++]=p.t[j];
    sum->n=k;
    return *sum;
}

istream & operator >>(istream &is, Poly &p1)
{
    cout<<"Enter Polynomial Coefficient & Power: \n";
    for(int i=0; i<p1.n; i++)
        cin>>p1.t[i].coeff>>p1.t[i].exp;
    return is;
}

ostream & operator << (ostream &os, Poly &p1)
{
    for(int i=0; i<p1.n; i++)
        cout<<p1.t[i].coeff<<"x"<<p1.t[i].exp<<"+";
    cout<<endl;
    return os;
}

int main()
{
    Poly p1(3);
    cin>>p1;
    Poly p2(3);
    cin>>p2;
    cout<<"First Polynomial is: "<<p1<<endl;
    cout<<"Second Polynomial is: "<<p2<<endl;
    cout<<"Sum of the 2 Poly is: "<<endl;
    Poly p3 = p1+p2;
    cout<<p3<<endl;

    return 0;

}