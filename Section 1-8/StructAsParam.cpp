#include<iostream>
using namespace std;

struct Rectangle
{
	int length;
	int breadth;
};

void area(Rectangle p)
{
	cout<<(p.length)*(p.breadth)<<endl;
}

void cngLength(Rectangle *p, int l)
{
	p->length=l;
}


int main()
{
	Rectangle r1{10,20};
	area(r1);
	cngLength(&r1,21);
	area(r1);	
	return 0;
}
