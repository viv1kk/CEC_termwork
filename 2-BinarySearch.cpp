/*
LINEAR SEARCH 
TIME COMPLEXITY - 0(log N) (FOR AVERAGE AND WORST) AND O(1) FOR BEST CASE
SPACE COMPLEXITY - 0(1)
*/


#include <bits/stdc++.h>
using namespace std;

void getInput(vector<pair<int, int>>&a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cin>>a[i].first;
        a[i].second = i;
    }
}

int binarySearch(vector<pair<int,int>>a, int x)
{
    int s = 0, e = a.size()-1;

    while(s <= e)
    {
        int mid = s+(e-s)/2;
        if(a[mid].first == x) return mid;
        else if(a[mid].first < x) s = mid+1;
        else e = mid-1;
    }
    return -1;
}

int main()
{
    int n, x;
    cout<<"Enter the number of Elements : ";
    cin>>n;
    vector<pair<int, int>>a(n);
    getInput(a);
    cout<<"Enter the element to be searched : ";
    cin>>x;
    sort(a.begin(), a.end());
    int ind = binarySearch(a, x);
    if(ind != -1)
        cout<<"Element Found at Index "<<a[ind].second<<endl;
    else
        cout<<"Element not Found!";
    return 0;
}