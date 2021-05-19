//Programmed by KAUSHAL on 05.04.2021
//If key K = 3 shift cipher is called caesar cipher

#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int shift_cypher_encryption(int val = 3)
{
    fflush(stdin);
    char mes[50];
    cout<<"Enter Message to Encrypt : ";
    gets(mes);
    for(int i = 0 ; i < strlen(mes) ; i++)
    {
        if(mes[i] >= 'a' && mes[i] <='z')
        {
            mes[i] = ((mes[i] - 97 + val ) % 26 ) + 97;
        }
        else if(mes[i] >= '0' && mes[i] <= '9')
        {
            mes[i] = ((mes[i] - 48 + val ) % 10 ) + 48;
        }
        else if(mes[i] >= 'A' && mes[i] <= 'Z')
        {
            mes[i] = ((mes[i] - 65 + val ) % 26 ) + 65;
        }
        else
        {
            mes[i] = mes[i];
        }
    }
    cout<<"Encrypted Message : " <<mes<<endl;
}

int shift_cypher_decryption(int val = 3)
{
    fflush(stdin);
    char mes[50];
    cout<<"Enter Message to Decryption : ";
    gets(mes);
    for(int i = 0 ; i < strlen(mes) ; i++)
    {
        if(mes[i] >= 'a' && mes[i] <='z')
        {
            mes[i] = (((mes[i] - 97 - val ) + 26) % 26 ) + 97;
        }
        else if(mes[i] >= '0' && mes[i] <= '9')
        {
            mes[i] = ((mes[i] - 48 - val + 10) % 10 ) + 48;
        }
        else if(mes[i] >= 'A' && mes[i] <= 'Z')
        {
            mes[i] = ((mes[i] - 65 - val + 26) % 26 ) + 65;
        }
        else
        {
            mes[i] = mes[i];
        }
    }
    cout<<"Decrypted Message : "<<mes<<endl;
}

int main()
{
    //This is Shift Cypher
    int shift_val;
    cout<<"Enter Shift Value : ";
    cin>>shift_val;
    shift_cypher_encryption(shift_val);
    cout<<"Enter Shift Value : ";
    cin>>shift_val;
    shift_cypher_decryption(shift_val);
}
