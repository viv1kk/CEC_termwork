/*
MERGE SORT
TIME COMPLEXITY - O(NlogN) (FOR AVERAGE AND WORST) AND O(N) FOR BEST CASE
SPACE COMPLEXITY - O(N)
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

void Merge(vector<int>&a, int lb, int mid, int ub)
{
    int s1 = mid-lb+1;
    int s2 = ub-mid;
    vector<int>L(s1);
    vector<int>R(s2);

    for(int i = 0; i < s1; i++)
    {
        L[i] = a[lb+i];
    }
    for(int i = 0; i < s2; i++)
    {
        R[i] = a[mid+i+1];
    }
    L[s1] = R[s2] = INT_MAX;
    int i = 0, j = 0;
    for(int k = lb; k <= ub; k++)
    {
        if(L[i] <= R[j])
            a[k] = L[i++];
        else
            a[k] = R[j++];
    }
}

void mergeSort(vector<int>&a, int lb, int ub)
{
    if(lb >= ub)
        return;
    int mid = lb+(ub-lb)/2;
    mergeSort(a, lb, mid);
    mergeSort(a, mid+1, ub);
    Merge(a, lb, mid, ub);
}

void printArray(vector<int>&a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<", ";
    }
    cout<<endl;
}

int main()
{
    int n, x;
    cout<<"Enter the number of Elements : ";
    cin>>n;
    vector<int>a(n);
    getInput(a);
    mergeSort(a, 0, a.size()-1);
    cout<<"After Sorting :"<<endl;
    printArray(a);
    return 0;
}