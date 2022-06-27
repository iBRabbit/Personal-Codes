#include "iostream"
#include "string"

using namespace std;

struct users{
    int id;
    bool isLogged;
}UserData[1001];

int N;
int event;
int arr[1001];
bool flag = false;

int main(int argc, char const *argv[])
{
    
    cin >> N;
    int counter =  0;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        flag = false;
        // if(UserData[i].id < 0) {
        //     UserData[i].id *= -1;
        //     UserData[i].isLogged = false;
        //     for(int j = 0; j < i; j++){
        //         if(UserData[j].id == UserData[i].id) continue;
        //         else counter++;
        //     }
        // } else UserData[i].isLogged = true;
        
        if(arr[i] < 0){
            // cout << "Iterasi i  " << i << endl ;
            for(int j = 0; j < i; j++){
                // cout << "Iterasi j :  " << j << " -> " << arr[j] << " " << arr[i] * -1 << endl;
                if(arr[j] == arr[i] * -1) 
                    flag = true;
                // cout << flag << endl;
            }
            // cout << " << " << flag << endl;
            if(flag == false) counter++;
        }
        
        
    }
    
    // cout << "Sol" << endl;
    cout << counter << endl;

    return 0;
}
