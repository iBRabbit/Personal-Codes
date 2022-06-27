#include "iostream"

#define MAX_SIZE 105
using namespace std;

int itemQuantity;
int bagQuantity, bagQuantityInit;
int maxValue = 0;
int sumWeight = 0;

double weightRemainder = 0;

struct items{
    char nama;
    double weight;
    double value;
    double profit;    
}itemsData[MAX_SIZE];

void quickSort(int left, int right){
    if(left < right){
        int pv = left;
        int l = left;
        int r = right + 1;
        do{
            do l++; while(itemsData[l].profit > itemsData[pv].profit);
            do r--; while(itemsData[r].profit < itemsData[pv].profit);
            if(l < r) swap(itemsData[l], itemsData[r]);
        } while(l < r);
        swap(itemsData[pv], itemsData[r]);
        quickSort(left, r - 1);
        quickSort(r + 1, right);
    }
}

void printData(items arr[], int size){
    for(int i = 0; i < size; i++)
         cout << "| Data " << itemsData[i].nama << " | Weight : " << itemsData[i].weight << " | Value : " << itemsData[i].value << " | Profit : " << itemsData[i].profit << " |" << endl;
    return;
}

int main(int argc, char const *argv[])
{

    cout << "Masukkan jumlah item : "; // O(k)
    cin >> itemQuantity; // O(k)

    cout << "Masukkan kuantitas bag : "; // O(k)
    cin >> bagQuantity; // O(k)

    bagQuantityInit = bagQuantity;  

    for(int i = 0; i < itemQuantity; i++){  // O(n + 1)
        itemsData[i].nama = 'A' + i; // O(n)
        cout << "Masukkan Weight item " << itemsData[i].nama << " : ";
        cin >> itemsData[i].weight;
        cout << "Masukkan Profit item " << itemsData[i].nama << " : ";
        cin >> itemsData[i].value;

        // 1. Calculate the value per kg //
        itemsData[i].profit = itemsData[i].value / itemsData[i].weight;
    }

    quickSort(0, itemQuantity - 1); // O(n lg n) in avg -> O(n^2) in worst
    int k = 0; 

    for(int i = 0; i < 10; i++)
        cout << endl;

    cout << "SOLUTION" << endl;

    do{

        if(bagQuantity - itemsData[k].weight <= 0){
            // cout << "Masuk " << endl;
            weightRemainder = bagQuantity / itemsData[k].weight;
            bagQuantity = 0;
            // cout << k << endl;

            cout << "| Data " << itemsData[k].nama << " | Weight : " << weightRemainder * itemsData[k].weight << " | Value : " << itemsData[k].value * weightRemainder << " | Profit : " << itemsData[k].profit << " | Remainder : " << weightRemainder << endl;

            maxValue += itemsData[k].value * weightRemainder;
            sumWeight += weightRemainder * itemsData[k].weight;

            cout << endl;
            cout << "The maximum value is " << maxValue << " with total weight " << sumWeight << ((bagQuantityInit == sumWeight) ? " (Optimal)" : " (Not Optimal)");

            break;
        }

        bagQuantity -= itemsData[k].weight;

        cout << "| Data " << itemsData[k].nama << " | Weight : " << itemsData[k].weight << " | Value : " << itemsData[k].value <<  " | Profit : " << itemsData[k].profit << " | " << endl;

        maxValue += itemsData[k].value;
        sumWeight += itemsData[k].weight;
        k++; 

        if(k > itemQuantity)
            break;


    } while(bagQuantity > 0); // O(n)
    
    // Sehingga time complexity dari bounded knapsack menggunakan quicksort adalah
    // O(n^2) jika pivot quicksort dalam worst case
    // O(n lg n) jika pivot dalam quicksort dalam average case

    // Untuk space complexity adalah O(n) dikarenakan membutuhkan sebuah array berukuran n untuk menampung items.

    return 0;
}
