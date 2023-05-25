#include<iostream>
using namespace std;
int main()
{
    char str1[]="painter";
    char str2[]="painting";
    int i,j;
    for(i=0,j=0;str1[i]!='\0'||str2[j]!='\0';i++,j++)
    {
        if(str1[i]!=str2[j])
        {
            cout<<"Strings are not equal."<<endl;
            return 0;
        }   
    }
    cout<<"Strings are equal"<<endl;
    return 1;

}