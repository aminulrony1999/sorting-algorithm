#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int leftPointer = low;
    int rightPointer = mid + 1;
    while (leftPointer <= mid && rightPointer <= high)
    {
        if (arr[leftPointer] <= arr[rightPointer])
        {
            temp.push_back(arr[leftPointer]);
            leftPointer++;
        }
        else
        {
            temp.push_back(arr[rightPointer]);
            rightPointer++;
        }
    }
    while (leftPointer <= mid)
    {
        temp.push_back(arr[leftPointer]);
        leftPointer++;
    }
    while (rightPointer <= high)
    {
        temp.push_back(arr[rightPointer]);
        rightPointer++;
    }
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}
void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    for(int i = 0; i < n; ++i)
    cout<<arr[i]<<" ";
    return 0;
}