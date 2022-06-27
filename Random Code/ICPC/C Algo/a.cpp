#include "iostream"
#include "stdlib.h"
#include "vector"

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
}itemsData[MAX_SIZE], solution[MAX_SIZE];

class items2{
    public: " <<"
}

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
                cout << "| Data " << itemsData[i].nama << " | Weight : " << itemsData[i].weight << " | Value : " << itemsData[i].value << " | Profit : " << itemsData[i].profit << " |" << endl;
            break;
        }
        case 1 : {
            int maxValue = 0;
            int sumWeight = 0;

            system("cls");
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
    vector <items> vItems;
    items temp;
    tem
    vItems.push_back()
    
    return 0;
}
