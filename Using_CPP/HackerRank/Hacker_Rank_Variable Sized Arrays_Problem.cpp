//Consider an n-element array, a, where each index i in the array
//contains a reference to an array of (K)i integers (where the value of
//varies from array to array). See the Explanation section below for
//a diagram.
//Given a, you must answer q queries. Each query is in the format i j,
//where i denotes an index in array a and j denotes an index in the array
//located at a[i]. For each query, find and print the value of element j in
//the array at location a[i] on a new line.


//Input Format

//The first line contains two space-separated integers denoting the
//respective values of n (the number of variable-length arrays) and q
//(the number of queries).
//Each line i of the n subsequent lines contains a space-separated
//sequence in the format k a[i]0 a[i]1 ? a[i]k-1 describing the
//k-element array located at a[i].
//Each of the q subsequent lines contains two space-separated integers
//describing the respective values of i (an index in array a) and j
//(an index in the array referenced by a[i]) for a query.

//Input Sample
//2 2
//3 1 5 4
//5 1 2 8 9 3
//0 1
//1 3

//Sample Output
//5
//9

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q,num,k;
    vector<vector<int>> v;
    cin>>n>>q;
    for(int i = 0 ; i < n ; i++)
    {
        vector<int> v1;
        cin>>k;
        for(int j = 0 ; j < k  ; j++)
        {
            cin>>num;
            v1.push_back(num);
        }
        v.push_back(v1);
    }
    // for(int i = 0 ; i < n ; i++)
    // {
    //     for(auto it = v[i].begin() ; it != v[i].end() ; it++)
    //     {
    //         cout<<*it<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<int> v2;
    vector<int > v3;
    int num1;
    for(int i = 0 ; i < q ; i++)
    {
        cin>> num>>num1;
        v2.push_back(num1);
        v3.push_back(num);
    }

    // for(int i = 0 ; i < q ; i++)
    // {
    //     cout<<v3[i]<<" "<<v2[i]<<" "<<endl;
    // }

    for(int i = 0 ; i < q ; i++)
    {
        cout<<v[v3[i]].at(v2[i])<<endl;
    }



    return 0;
}
