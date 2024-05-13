#include <iostream>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int *arr=new int(n);
    int i, key, j;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
}
