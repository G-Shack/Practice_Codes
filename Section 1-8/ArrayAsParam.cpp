#include<iostream>
using namespace std;

void fun(int *A, int n)
{
	for(int i=0; i<n; i++)
	cout<<A[i]<<" ";
}

int * fun2(int size)
{
	int *p;
	p=new int[size];
	for(int i=0; i<size; i++)
	p[i]=i+1;
	return p;
}
int main()
{
	int *ptr;
	int sz;
	
	int A[]={2,4,6,8,10};
	fun(A,5);
	
	cout<<"Enter size of an Array: ";
	cin>>sz;
	
	ptr=fun2(sz);
	
	for(int i=0; i<sz; i++)
		cout<<ptr[i]<<" ";
	return 0;	
}
