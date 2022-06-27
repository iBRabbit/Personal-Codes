#include "iostream"

using namespace std;

#define MAX_SIZE 999

int itemQuantity;
int heapSize;
int bagQuantity, bagQuantityInit;
int sumWeight = 0;
int maxValue = 0;
double weightRemainder;

struct items{
    char nama;
    double weight;
    double value;
    double profit;    
}itemsData[MAX_SIZE];

void heapify(int i){
    int max = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    if(left < heapSize && itemsData[left].profit > itemsData[max].profit) max = left; 
    if(right < heapSize && itemsData[right].profit > itemsData[max].profit) max = right; 

    if(max != i){
        swap(itemsData[i], itemsData[max]); 
        heapify(max);
    } 
}


void popRoot(){
    swap(itemsData[0], itemsData[heapSize - 1]);
    heapSize--;
    heapify(0);
}

void buildHeap(){
    int startIdx = (heapSize / 2) - 1; 
    for(int i = startIdx; i >= 0; i--)  
        heapify(i); 
}

void printHeap(){
    cout << "Isi Heap :" << endl;

    for(int i = 0; i < heapSize; i++)
        cout << "| Data " << itemsData[i].nama << " | Weight : " << itemsData[i].weight << " | Value : " << itemsData[i].value << " | Profit : " << itemsData[i].profit << " |" << endl;

}

int main(int argc, char const *argv[])
{

    cout << "Masukkan jumlah item : "; // time complexity = k
    cin >> itemQuantity; // time complexity = k

    cout << "Masukkan kuantitas bag : "; // time complexity = k
    cin >> bagQuantity; // time complexity = k

    bagQuantityInit = bagQuantity; // time complexity = k
    heapSize = itemQuantity; // time complexity = k
 
    for(int i = 0; i < itemQuantity; i++){ // time complexity = n + 1
        itemsData[i].nama = 'A' + i;  // time complexity = n
        cout << "Masukkan Weight item " << itemsData[i].nama << " : ";  // time complexity = n
        cin >> itemsData[i].weight;  // time complexity = n
        cout << "Masukkan Profit item " << itemsData[i].nama << " : ";  // time complexity = n
        cin >> itemsData[i].value;  // time complexity = n

        itemsData[i].profit = itemsData[i].value / itemsData[i].weight;
    }

    buildHeap(); 
    // Misal h adalh height dari tree dan n adalah banyak node
    // Pada buildHeap terdapat loop sebanyak n/2 - 1 yang masing2 memanggil fungsi heapify
    // artinya kompleksitas waktunya adalah h * banyak node di level tersebut
    // kompleksitas pada setiap level  adalah h * (n/2^h)
    // Sehingga total level dari n node adalah jumlah dari node pertama sampai log2 (n)
    // sehingga sigma h = 0 to log n (n/2^h) O(h) = O(n * sigma h = 0 to log (n) (h/2^h))
    // O(n sigma h = 0 to infinity (h/2^h))
    // Karena deret sigma h = 0 to infinity (h/2^h) konvergen maka bisa dikatakan jumlahnya adalah k
    // O(nk) = O(n)
    // Sehingga kompleksitas waktu buildHeap() adalah O(n)

    for(int i = 0; i < 10; i++)
        cout << endl;

    cout << "SOLUTION" << endl;

    do{
        
        if(bagQuantity - itemsData[0].weight <= 0){
            
            weightRemainder = bagQuantity / itemsData[0].weight;
        
            cout << "| Data " << itemsData[0].nama << " | Weight : " << weightRemainder * itemsData[0].weight << " | Value : " << itemsData[0].value * weightRemainder << " | Profit : " << itemsData[0].profit << " | Remainder : " << weightRemainder << endl;

            maxValue += itemsData[0].value * weightRemainder;
            sumWeight += weightRemainder * itemsData[0].weight;

            cout << endl;
            cout << "The maximum value is " << maxValue << " with total weight " << sumWeight << ((bagQuantityInit == sumWeight) ? " (Optimal)" : " (Not Optimal)");

            popRoot();
            break;
        }

        bagQuantity -= itemsData[0].weight;

        cout << "| Data " << itemsData[0].nama << " | Weight : " << itemsData[0].weight << " | Value : " << itemsData[0].value <<  " | Profit : " << itemsData[0].profit << " | " << endl;

        maxValue += itemsData[0].value;
        sumWeight += itemsData[0].weight;

        popRoot(); // 
        // Memanggil fungsi heapify  di mana heapify kompelkitasnya O(log2 n )
    } while(heapSize > 0); // time complexity O(n)

    // Sehingga total kompleksitasnya adalah
    // O(n) * O(log n) = O(n log n) untuk time complexity

    // Untuk space complexity adalah O(n) dikarenakan membutuhkan sebuah array berukuran n untuk menampung items.

    return 0;
}
