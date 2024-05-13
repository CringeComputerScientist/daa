#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {

            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int(n);
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr,0,n-1);
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
}
