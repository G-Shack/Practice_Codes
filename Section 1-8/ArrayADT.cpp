#include<iostream>
using namespace std;

struct Array
{
	int *A;
	int size;
	int length;
};

void Display(Array arr)
{
	int i;
	cout<<"Elements are: ";
	for(i=0;i<arr.length;i++)
		cout<<" "<<arr.A[i];
}

void Append(Array *arr, int x)
{
	if(arr->length<arr->size)
	{
		arr->A[arr->length]=x;
		arr->length++;
	}
}

void Insert(Array *arr, int index, int x)
{
	if(index>=0 && index <=arr->length)
	{
		for(int i=arr->length; i>index; i--)
			arr->A[i]=arr->A[i-1];
		arr->A[index]=x;
		arr->length++;
	}
}

int Delete(Array *arr, int index)
{
	int x=0;
	x=arr->A[index];
	
	if(index>=0 && index<arr->length)
	{
		for(int i=index; i=arr->length-1; i++)
			arr->A[i]=arr->A[i+1];
		arr->length--;
		return x;
	}
	return 0;
}

void swap(int *x, int *y)
{
	int *temp;
	*temp = *x;
	*x=*y;
	*y=*temp;
}

int LSearch(Array *arr, int key)
{
	for(int i=0; i<arr->length; i++)
	{
	if(arr->A[i]=key)
		return i;
	}
	return -1;
}

int main()
{
	Array arr;
	int n,i;
	cout<<"Enter size of an array: ";
	cin>>arr.size;
	arr.A=new int[arr.size];
	arr.length=0;
	
	cout<<"Enter number of numbers: ";
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cout<<"Enter element "<<i<<" :";
		cin>>arr.A[i];
	}
		
	arr.length=n;
	
	Append(&arr, 69);
	Display(arr);
	
	Insert(&arr, 1, 69);
	Display(arr);
	
	cout<<"The deleted element is: "<<Delete(&arr, 3);
	Display(arr);
	
	cout<<"The element is found at index: "<<LSearch(&arr, 8);
	Display(arr);
	
	delete []arr.A;
	return 0;
}
