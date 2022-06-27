#include "iostream"

using namespace std;

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int tambahArray(int arr[], int n){
    int result = 0;
    for(int i = 0; i < n; i++)
        result += arr[i];
    
    return result;
}

int main(int argc, char const *argv[])
{
    int n;
    int arr[1005];
    
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int i = 0; i < n; i++){
        int arr1[1005] = {0}, arr2[1005] = {0};
        int k = 0;

        for(int j = 0; j <= i; j++)
            arr1[j] = arr[j];
        
        for(int j = i + 1; j < n; j++){
            arr2[k] = arr[j]; 
            k++;
        }

        // cout << "=============" << endl;
        // printArr(arr, n);
        // printArr(arr1, n);
        // printArr(arr2, n);
        // cout << "=============" << endl;
        int result1 = tambahArray(arr1, n);
        int result2 = tambahArray(arr2, n);

        // cout << result1 << " " <<result2 << endl;

        if(result1 == result2){
            cout << result1 << endl;
            return 1;
        }
            
    }

    cout << "0" << endl;

    return 0;
}

