/*
COUNTING SORT
TIME COMPLEXITY - O(N + K) (FOR AVERAGE, WORST AND BEST CASE)
SPACE COMPLEXITY - O(K) - K IS THE LARGEST ELEMENT
*/

#include <bits/stdc++.h>
using namespace std;

void getInput(vector<int>&a)
{
    for(int i = 0; i < a.size(); i++) cin>>a[i];
}

void printArray(vector<int>&a)
{
    for(int i = 0; i < a.size(); i++) cout<<a[i]<<", ";
    cout<<endl;
}

void countingSort(vector<int>&freq, vector<int>&a)
{
    int n = a.size();
    vector<int>ans(n);
    for(int i = 0; i < n; i++) freq[a[i]]++;
    for(int i = 1; i <= freq.size(); i++) freq[i] += freq[i-1];
    for(int i = n-1; i >= 0; i--)
    {
        ans[freq[a[i]]-1] = a[i];
        freq[a[i]]--;
    }
    for(int i = 0; i < n; i++) a[i] = ans[i];
}

int main()
{
    int n, x;
    cout<<"Enter the number of Elements : ";
    cin>>n;
    vector<int>a(n);
    getInput(a);
    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    vector<int>arr(mx, 0);
    countingSort(arr, a);
    cout<<"After Sorting :"<<endl;
    printArray(a);
    return 0;
}