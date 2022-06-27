#include "iostream"
#include "stdlib.h"

#define MAX_SIZE 9999
using namespace std;

int itemQuantity;
int bagQuantity, bagQuantityInit;
int bagLeft;

struct items{
    char nama;
    double weight;
    double value;
    double profit;    
    int maxCarry;
}itemsData[MAX_SIZE], solution[MAX_SIZE];

void swap(int a, int b){
    items temp = itemsData[a];
    itemsData[a] = itemsData[b];
    itemsData[b] = temp;
}

void quickSort(int left, int right){
    if(left < right){
        int pv = left;
        int l = left;
        int r = right + 1;
        do{
            do l++; while(itemsData[l].profit > itemsData[pv].profit);
            do r--; while(itemsData[r].profit < itemsData[pv].profit);
            if(l < r) swap(l, r);
        } while(l < r);
        swap(pv, r);
        quickSort(left, r - 1);
        quickSort(r + 1, right);
    }
}

void printData(items arr[], int size, int type = 0){
    switch(type){
        case 0 : {
            for(int i = 0; i < size; i++)
                cout << "| Data " << itemsData[i].nama << " | Weight : " << itemsData[i].weight << " | Value : " << itemsData[i].value << " | Profit : " << itemsData[i].profit << " |" << "Max Carry :  "  << itemsData[i].maxCarry << endl;
            break;
        }
        case 1 : {
            int maxValue = 0;
            int sumWeight = 0;

            // system("cls");
            cout << "SOLUTION" << endl;

            for(int i = 0; i < size; i++){
                cout << "| Data " << solution[i].nama << " | Weight : " << solution[i].weight << " | Value : " << solution[i].value << "\t| " << endl;
                maxValue += solution[i].value;
                sumWeight += solution[i].weight;
            }
            cout << endl;
            cout << "The maximum value is " << maxValue << " with total weight " << sumWeight << ((bagQuantityInit == sumWeight) ? " (Optimal)" : " (Not Optimal)");
            break;
        }
    }

    return;
}

int main(int argc, char const *argv[])
{

    cout << "Masukkan jumlah item : ";
    cin >> itemQuantity;

    cout << "Masukkan kuantitas bag : ";
    cin >> bagQuantity;

    bagQuantityInit = bagQuantity;

    for(int i = 0; i < itemQuantity; i++){
        itemsData[i].nama = 'A' + i;

        cout << "Masukkan Weight item " << itemsData[i].nama << " : ";
        cin >> itemsData[i].weight;
        cout << "Masukkan Profit item " << itemsData[i].nama << " : ";
        cin >> itemsData[i].value;
        cout << "Masukkan maksimal berat untuk membawa barang " << itemsData[i].nama << " : ";
        cin >> itemsData[i].maxCarry; 

        // 1. Calculate the value per kg //
        itemsData[i].profit = itemsData[i].value / itemsData[i].weight;
    }

    quickSort(0, itemQuantity - 1);
    printData(itemsData, itemQuantity);

    double weightRemainder = 0;

    int k = 0, l = 0;
    do{
        while(itemsData[k].maxCarry > 0){
            itemsData[k].maxCarry--;

            if(bagQuantity - itemsData[k].weight <= 0){
                cout << "Masuk" << endl;
                weightRemainder = bagQuantity / itemsData[k].weight;
                bagQuantity = 0;
                
                solution[l].nama = itemsData[k].nama;
                solution[l].weight = weightRemainder * itemsData[k].weight;
                solution[l].value = itemsData[k].value * weightRemainder;
                break;
            } 

            bagQuantity -= itemsData[k].weight;

            solution[l].nama = itemsData[k].nama;
            solution[l].value = itemsData[k].value;
            solution[l].weight = itemsData[k].weight;
            cout << solution[l].nama << endl;
            l++;
            
            if(itemsData[k].maxCarry == 0)
                break;
        }
        k++;
        
        if(k > bagQuantity)
            break;

    } while (bagQuantity > 0);

    printData(solution, ++l, 1);

    return 0;
}
