/*
INSERTION SORT
TIME COMPLEXITY - O(N^2) (FOR AVERAGE AND WORST) AND O(N) FOR BEST CASE
SPACE COMPLEXITY - O(1)
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

void insertionSort(vector<int>&a)
{
    int key, j;
    for(int i = 0; i < a.size(); i++){
        key = a[i];
        j = i-1;
        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
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
    insertionSort(a);
    cout<<"After Sorting :"<<endl;
    printArray(a);
    return 0;
}