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
	for(i=0; i<arr.length; i++)
        cout<<i<<" "<<arr.A[i]<<"\n";
    
    cout<<"Array Length is: "<<arr.length<<"\n";
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
	
	if(index>=0 && index<arr->length)
	{
        x=arr->A[index];
		for(int i=index; i<arr->length-1; i++)
			arr->A[i]=arr->A[i+1];
		arr->length--;
		return x;
	}
	return -1;
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x=*y;
	*y=temp;
}

int LSearch(Array *arr, int key)
{
	for(int i=0; i<arr->length; i++)
	{
	if(arr->A[i]==key)
    {
        swap(&arr->A[i], &arr->A[i-1]);//Improving linear search by TRANSPOSITION
        //swap(&arr->A[i], &arr->A[0]); Improving linear search by MOVE TO HEAD
        return i;
    }
	}
	return -1;
}

int BinSearch(int a[], int l, int h, int key)
{
    int mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(a[mid]==key)
            return mid;
        else if(key < a[mid])
            h=mid-1;
        else    
            l=mid+1;
    }
    return -1;
}

int Get(Array arr, int index)
{
    if(index>=0 && index < arr.length)
        return arr.A[index];
    return -1;
}

int Set(Array *arr, int index, int x)
{
    if(index>=0 && index < arr->length)
        arr->A[index]=x;
    return -1;
}

int Max(Array arr)
{
    int max=arr.A[0];
    int i;
    for(i=0; i<arr.length; i++)
    {
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}

int Min(Array arr)
{
    int min=arr.A[0];
    int i;
    for(i=0; i<arr.length; i++)
    {
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
}

int Sum(Array arr)
{
    int sum=0;
    for(int i=0; i<arr.length-1; i++)
        sum += arr.A[i];
    return sum;
}

void Reverse(Array *arr)
{
    int *B;
    int i,j;
    B=new int[arr->length];
    for(i=arr->length-1, j=0; i>=0;i--,j++)
        B[j]=arr->A[i];
    for(i=0; i<arr->length; i++)
        arr->A[i]=B[i];
    delete []B;
}

void Reverse2(Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1; i<j; i++,j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

void InsertSort(Array *arr, int x)
{
    int i=arr->length-1;
    if(arr->length==arr->size)
        return;
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

int isSorted(Array arr)
{
    int i;
    for(i=0; i<arr.length-1; i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}

void Rearrange(Array *arr)
{
    int i,j;
    i=0;
    j=arr->length-1;

    while (i<j)
    {
        while(arr->A[i]<0)
            i++;
        while(arr->A[i]>=0)
            j--;
        if(i<j)swap(&arr->A[i], &arr->A[j]);
    }
    
}

int main()
{
    Array arr;
    int ch, x, index;
    cout<<"Enter size of array: ";
    cin>>arr.size;
    arr.A=new int[arr.size];
    arr.length=0;

    do
    {
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6.Exit\n");
        printf("enter you choice ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter an element and index");
                scanf("%d%d",&x,&index);
                Insert(&arr,index,x);
                break;
            case 2: printf("Enter index ");
                scanf("%d",&index);
                x=Delete(&arr,index);
                printf("Deleted Element is %d\n",x);
                break;
            case 3:printf("Enter element to search ");
                scanf("%d",&x);
                index=LSearch(&arr,x);
                printf("Element index %d",index);
                break;
            case 4:printf("Sum is %d\n",Sum(arr));
                break;
            case 5:Display(arr);
        }
    }while(ch<6);
    
/*  Display(arr);

    Append(&arr, 69);
    Display(arr);

    Insert(&arr, 1, 69);
	Display(arr);

    cout<<"The deleted element is: "<<Delete(&arr, 3)<<"\n";
    Display(arr);

    cout<<"The element is found at index: "<<LSearch(&arr, 8)<<"\n";
	Display(arr);

    cout<<"Index of element searched using BinSearch: "<<BinSearch(arr.A, 0, arr.length-1, 8)<<"\n";

    cout<<"Value at given index is "<<Get(arr, 3)<<"\n";

    Set(&arr, 4, 96);
    cout<<"After replacing the value:- "<<"\n";
    Display(arr);

    cout<<"The maximum element of an array is: "<<Max(arr)<<"\n";

    cout<<"The maximum element of an array is: "<<Min(arr)<<"\n";

    cout<<"Sum of elements is: "<<Sum(arr)<<"\n";

    cout<<"Average of elements in an array is: "<<(float)Sum(arr)/arr.length<<"\n";

    Reverse2(&arr);  //Reverse & Reverse 2 are two methods
    cout<<"The array is now reversed: \n";
    Display(arr);
    
    //InsertSort(&arr, 5);  //only works if array is sorted can use isSorted();
    //Rearrange()
*/
    
    delete []arr.A;
    
    return 0;
}