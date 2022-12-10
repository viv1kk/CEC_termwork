/*
LINEAR SEARCH 
TIME COMPLEXITY - 0(N) (FOR AVERAGE AND WORST) AND O(1) FOR BEST CASE
SPACE COMPLEXITY - 0(1)
*/


#include <bits/stdc++.h>
using namespace std;


void getInput(vector<int>&a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cin>>a[i];
    }
}

int linearSearch(vector<int>&a, int x)
{
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == x)
            return i;
    }
    return -1;
}

int main()
{
    int n, x;
    cout<<"Enter the number of Elements : ";
    cin>>n;
    vector<int>a(n);
    getInput(a);
    cout<<"Enter the element to be searched : ";
    cin>>x;
    int ind = linearSearch(a, x);

    if(ind != -1)
        cout<<"Element Found at Index "<<ind<<endl;
    else
        cout<<"Element not Found!";
    return 0;
}