/*
HEAP SORT
TIME COMPLEXITY - O(NlogN) (FOR AVERAGE, WORST AND BEST CASE)
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

void printArray(vector<int>&a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<", ";
    }
    cout<<endl;
}

void heapify(vector<int>&a, int i, int n)
{
    int l = (2 * i)+1;
    int r = (2 * i)+2;

    int largest = i;

    if(l < n && a[l] > a[largest]) largest = l;
    if(r < n && a[r] > a[largest]) largest = r;
    if(largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, largest, n);
    }
}

void createHeap(vector<int>&a, int n)
{
    for(int i = floor(n/2)-1; i >= 0; i--)
    {
        heapify(a, i, n);
    }
}

void heapSort(vector<int>&a, int n)
{
    for(int i = n-1; i > 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
}

int main()
{
    int n, x;
    cout<<"Enter the number of Elements : ";
    cin>>n;
    vector<int>a(n);
    getInput(a);
    createHeap(a, n);
    heapSort(a, n);
    cout<<"After Sorting :"<<endl;
    printArray(a);
    return 0;
}