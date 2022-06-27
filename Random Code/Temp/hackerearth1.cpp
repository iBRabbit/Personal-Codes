#include "iostream"
#include "stdlib.h"

using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");    
    int testcase = 0, greenCost = 0, purpleCost = 0, num_of_participants = 0;
    cin >> testcase;
    
    for(int i = 1; i <= testcase; i++){
        int cost = 0;
        cin >> greenCost >> purpleCost;
        cin >> num_of_participants;
        
        for(int j = 0; j < num_of_participants; j++){
            int status1 = 0, status2 = 0;
            cin >> status1 >> status2;

            if(i % 2 != 0){
                if(status1 == 1) cost += greenCost;
                if(status2 == 1) cost += purpleCost;
            } else{
                if(status1 == 1) cost += purpleCost;
                if(status2 == 1) cost += greenCost;
            }

        } 
        cout << cost << endl;
    
    }

    return 0;
}
