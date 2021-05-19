#include<iostream>
using namespace std;
int length_of_string(char[]);
int compare_two_string(char[]);

int main()
{
    char str[100];
    //cout<<;
    cout<<"Enter a String to Count characters : ";
    cin>>str;
    compare_two_string(str);
    //cout<<"Length of String is " << length_of_string(str);

}

int length_of_string(char str[])
{
    int count = 0;
    while(str[count]!='\0')
    {
        count++;
    }
    return count;
}

int compare_two_string(char str1[])
{
    char str2[100];
    int count=0;
    fflush(stdin);
    cout<<"Enter another String : ";
    cin>>str2;

    while(str1[count] == str2[count])
    {
        count++;
        //cout<<"\nSame till Now "<<count;
    }
    //cout<<count;
    if(count < length_of_string(str1) && count < length_of_string(str2))
        cout<<"Not Same String";
    else
        cout<<"String are Same";
}
