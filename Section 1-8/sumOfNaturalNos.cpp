#include<stdio.h>

int sum(int n)
{
	if(n==0)
		return 0;
	else
		return sum(n-1)+n;
}

int fact(int n)
{
	if(n==0)
		return 1;
	else
		return fact(n-1)*n;
}

int main()
{
	int r,p;
	r=sum(5);
	printf("%d\n",r);
	p=fact(5);
	printf("%d\n",p);
	
	return 0;	
}
