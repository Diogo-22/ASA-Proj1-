#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
#include <sstream>

int calc(int a, int b, vector<vector<int> >& opTable) {
    return opTable[a-1][b-1];
}


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n, m;
    int result = 0;
    //cout << "Digite n e m: ";

    // Leitura de n e m
    cin >> n >> m;
    //cout << "n: " << n << ", m: " << m << '\n';


    // Leitura da tabela de operações (matriz n x n)
    vector<vector<int> > opTable(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> opTable[i][j];
        }
    }

     int desiredResult;
    cin >> desiredResult;
    int counter = 0;

    // Leitura da sequência de inteiros
    vector<vector<int> > resTable(m, vector<int>(m));
    for (int i = 0; i < m; ++i) {
       cin >> resTable[i][i];
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            //printf("i: %d, j: %d\n", i, j);
            if(j>i+1){
            resTable[i][j] = calc(resTable[i][j-1], resTable[i+2][j], opTable);
            //resTable[i][j] = calc(resTable[i][j-2], resTable[i+1][j], opTable);
            }
            else if (j == i+1){
                resTable[i][j] = calc(resTable[i][j-1], resTable[i+1][j], opTable);
            }
        }
    }

    //print resTable
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            //if(j>=i)
            cout << resTable[i][j] << " ";
        }
        cout << '\n';
    }
    

    // Leitura do resultado desejado
   
 

    return 0;
}