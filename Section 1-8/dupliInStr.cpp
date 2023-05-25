#include<iostream>
using namespace std;

int main()
{
    char str[]="aple";
    int H[26]={0};
    for(int i=0; str[i]!='\0'; i++)
    {
        H[str[i]-97]++;
    }
    for(int i=0; i<26; i++)
    {
        if(H[i]>1)
        {
            cout<<"Characters are repeated."<<endl;
            return 0;
        }
    }
    cout<<"Charaters are unique."<<endl;
    return 1;

}