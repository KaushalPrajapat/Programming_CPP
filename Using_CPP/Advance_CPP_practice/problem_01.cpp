// Kaushal Prajapat 14.05.2021

// Problem -- Replace smallest in array with 0 and largest with last_index
// eg    -- 12,15,48,2,154,96,9
// Index -  0  1  2  3  4  5  6
// Replace- 2  3  4  0  6  5  1

#include<iostream>
#include<vector>
#include<utility>
#include <bits/stdc++.h>
using namespace std;
int Array_method();

bool mycomp(pair<int, int> p1 ,pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    // Solution Seen from Video
    int arr[] = {10,16,7,14,5,3,12,9},arr1[8];
    vector<pair<int,int>> v1;
    for(int i = 0 ; i <(sizeof(arr)/sizeof(arr[0])) ; i++)
    {
        v1.push_back(make_pair(i,arr[i]));
    }
    for(auto it = v1.begin() ; it != v1.end() ; it++)
    {
        cout<<it->first<<"----"<<it->second<<endl;
    }

    sort(v1.begin(),v1.end(),mycomp);
    // cout<<"sorted"<<endl;
    // for(auto it = v1.begin() ; it != v1.end() ; it++)
    // {
    //     cout<<it->first<<"----"<<it->second<<endl;
    // }
    cout<<"Solution in Array -1 "<<endl;
    for(int i = 0 ; i < v1.size() ; i++)
    {
        arr[v1[i].first] = i;
    }
    for(int i = 0 ; i < v1.size() ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"My Solution in array - 2"<<endl;








    // My Solution
    vector<pair<int,int>> v = {{{0,10},{1,16},{2,7},{3,14},{4,5},{5,3},{6,12},{7,9}}};

    // cout<<"Before Sorting : "<<endl;
    // for(auto it = v.begin() ; it != v.end() ; it++)
    // {
    //     cout<<it->first<<"----"<<it->second<<endl;
    // }
    //    cout<<"After Sorting : "<<endl;
    sort(v.begin(),v.end(),mycomp);

    // for(auto it = v1.begin() ; it != v1.end() ; it++)
    // {
    //     cout<<it->first<<"----"<<it->second<<endl;
    // }

    // for(auto it = v1.begin() ; it != v1.end() ; it++)
    // {
    //     cout<<it->first<<" ";
    // }

    for(int i = 0 ; i < v.size() ; i++)
    {
        arr1[v[i].first] = i;
    }
    for(int i = 0 ; i < v.size() ; i++)
    {
        cout<<arr1[i]<<" ";
    }


    //Array_method();
}

// My solution using only arrays
int Array_method()
{
    int n = 7; //Number of element in array
    int arr[n] = {12,15,48,2,154,96,9}; // array which to placed Numbers
    int arrx[n],arrs[n],x=0; // arrx -- array to store result arrs -- array to store copy of real array
    int a;
    //Printing Unsorted array
    cout<<"Unsorted Array : "<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        arrs[i]=arr[i];
        cout<<arrs[i]<<" ";
    }
    cout<<endl;
    // Sorting algo for sorting
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            if(arr[i]>arr[j])
            {
                a=arr[i];
                arr[i]=arr[j];
                arr[j]=a;
            }
        }
    }
    //Printing Sorted aray
    cout<<"Printing Sorted Array : "<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //Replacing smallest with zero to increasing order
    int b = 0;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(arr[i] == arrs[j])
            {
                arrx[j]=b++;
                //cout<<arrs[i]<<arr[i]<<" ";
            }
        }
    }

    cout<<endl<<endl<<endl;
    //Printing Unsorted array
    cout<<"Unsorted Array : "<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arrs[i]<<" ";
    }
    cout<<endl<<endl<<endl;
    //Printing Replaced Numbers
    cout<<"Printing Replaced Numbers : "<<endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout<<arrx[i]<<" ";
    }
}
