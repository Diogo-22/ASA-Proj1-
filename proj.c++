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

    // Leitura de n e m
    cin >> n >> m;

    // Leitura da tabela de operações (matriz n x n)
    vector<vector<int> > opTable(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> opTable[i][j];
        }
    }

    // Leitura da sequência de inteiros
    vector<vector<vector<int> > > resTable(m, vector<vector<int> >(2*m, vector<int>(1)));
    for (int i = 0; i < m; i++) {
       cin >> resTable[i][i][0];
    }

     int desiredResult;
    cin >> desiredResult;
    int counter = 1;
    int placeholder = m-1;
    int nºsol = 0; 
    while (counter <= m-1)
    { for (int i = 0; i < placeholder; i++) {  
        printf("i: %d, counter: %d\n", i, counter);       
                
                if (counter == m-1){
                    for (int x = 0; x < m; x++)
                    {
                        if(resTable[i][i+counter-1][x] != 0)
                        {
                            nºsol++;
                        }        
                   }
                   printf("nºsol: %d\n", nºsol);

                    for (int j = 0; j < nºsol ; j++)
                    {
                    resTable[i][i+counter][j] = calc(resTable[i][i-1+counter][j], resTable[i+counter][i+counter][0], opTable);
                    resTable[i][i+counter][j+1+nºsol] = calc(resTable[0][0][0], resTable[i+1][i+counter][j], opTable);
                
                    }
                    resTable[i][i+counter][nºsol] = calc(resTable[i][i+counter-2][0], resTable[i+2][i+counter][0], opTable);
                   }
                else if(counter > 1){
                
                resTable[i][i+counter][0] = calc(resTable[i][i-1+counter][0], resTable[i+2][i+counter][0], opTable);
                
                resTable[i][i+counter][1] = calc(resTable[i][i-2+counter][0], resTable[i+1][i+counter][0], opTable);
                printf("reached here2\n");
                }
                else if (counter == 1){
                    
                    resTable[i][i+counter][0] = calc(resTable[i][i-1+counter][0], resTable[i+1][i+counter][0], opTable);
                    printf("reached here\n");
                }
        }
         counter++;
        placeholder--;
    }
    

    //print resTable
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << "[";
            for (int z = 0; z < 2*m; z++)
            {
                cout << resTable[i][j][z] << ", ";
            }
            cout << "] ";
        }
        cout << '\n';
    }

    // Leitura do resultado desejado

    return 0;
}