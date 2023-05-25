#include<iostream>
using namespace std;

int checkPal(char *string)
{
    int i,j;
    for(j=0; string[j]!='\0';j++)
    {}
    j=j-1;
    for(i=0;i<j;i++,j--)
    {
        if(string[i]!=string[j])
        {
            return 0;
            break;
        }
    }
    return 1;

}

int main()
{
    char str[]="nitin";
    if(checkPal(str))
        cout<<"String is Palindrome!";
    else
        cout<<"String is not Palindrome!";

    return 0;
}