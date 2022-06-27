#include "iostream"
#include "cstdlib"
#include "ctime"
#include "algorithm"
#include "string"

using namespace std;

#define MAX_SIZE 999

int arr[105][105];
int N;

void printArr(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    system("cls");
    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> arr[i][j];
    }

    // printArr();
    int max1 = 0, max2 = 0, counter1 = -1, counter2 = 0;
    int arr1[100], arr2[100];

    for(int i = 0; i < N; i++){

        max1 = 0;
        max2 = 0;
        for(int j = 0; j < N; j++){
            if(arr[j][i] >= max1) max1 = arr[j][i];
            if(arr[i][j] >= max2) max2 = arr[i][j];
        }
        // cout << max1 << " " <<  max2 << endl;
    }

    int k = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(arr[j][i] <= max1) 
                counter1++;
            if(arr[i][j] <= max2)
                counter2++;
        }
        arr1[k] = counter1;
        arr2[k] = counter2;
    }
  
    for(int i = 0; i < k; i++)
        cout << arr1[i] << " ";

    cout << endl;
    for(int i = 0; i < k; i++){
        cout << arr2[i] << endl;
    }

    return 0;
}

