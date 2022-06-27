#include "iostream"

using namespace std;

long long int k = 0, s = 0, n = 0;

int main(int argc, char const *argv[])
{
    bool isSolution = true;
    cin >> k >> s >> n; 

    if(n < k) isSolution = false;

    // win kalo misalnya selisih p1p2 > 2
    // menang sesuai k

    if(s == 1)
        if(n % 2 > 0 && (2 * k - 1) <= n) 
            isSolution = false;

    if(s > 1){
        n -= (s - 1) * k;
        if(n < k) isSolution = false;
        if(n % 2 > 0 && (2 * k - 1) <= n && k == 2)
            isSolution = false;
    }

    if(isSolution) cout << "YES" << endl;
    else cout << "NO" << endl;

    // k = 7 n = 13
    // 13  
    // 7 - 6 false

    // misal 3 set n = 10 k =  2
    // 7 - 1
    // 7 - 1
    // -> sisa 13 7 -  5
    // -> sisa 13 7 -  4

    // misal 3 set n = 11 k = 2
    // 2 - 1
    // 2 - 1
    // sisa 7 ->  

    return 0;
}
