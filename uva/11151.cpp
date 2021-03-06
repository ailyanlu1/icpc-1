//11151
//Longest Palindrome
//Dynamic Programming;Longest Common Subsequence  
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#define MAX 1005
using namespace std;

int T[MAX][MAX];
string P, Q;

int main() {
    int p, q, t;
    cin >> t;
    getline(cin, P);
    while(t--) {
        getline(cin, P);
        Q = string(P.rbegin(), P.rend());
        int p = P.size(), q = Q.size();
        
        for(int i=0; i<=p; i++) { T[i][0] = 0;  }
        for(int i=0; i<=q; i++) { T[0][i] = 0;  }

        for(int i=1; i<=p; i++) {
            for(int j=1; j<=q; j++) {
                if (P[i-1] == Q[j-1]) {
                    T[i][j] = T[i-1][j-1] + 1;
                }
                else {
                    T[i][j] = max(T[i-1][j], T[i][j-1]);
                }
            }
        }
        
        cout << T[p][q] << endl;
    }
    
    return 0;
}
