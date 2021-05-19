#include<iostream>
#include<string.h>

using namespace std;
char message[100];

void encryption()
{
    cout<<"Enter Message to Encryption : ";
    cin>>message;

    for(int i = 0 ; i < strlen(message) ; i++)
    {
        if('a' <= message[i] <= 'z')
        {
            message[i] = ((message[i] - 97 + 3) % 26) + 97;
        }
        else if(65 <= message[i] <= 'Z')
        {
            message[i]=((message[i]-65+2)%26)+65;
            //message[i] = ((message[i] - 65 + 3) % 26) + 65;
        }
        else if(48 <= message[i] <= 57)
        {
            message[i] = ((message[i] - 48 + 3) % 10) + 48;
        }
        else
        {
            message[i] = (message[i] - 1 + 3) % 26 + 1;
        }
    }
    cout<<message;
}

void decryption()
{
    cout<<"Enter Message to Encryption : ";
    cin>>message;

    for(int i = 0 ; i < strlen(message) ; i++)
    {
        message[i] = (message[i] - 97 - 3) % 26 + 97;
    }
    cout<<message;
}
int main()
{
    //decryption();
    encryption();
}
