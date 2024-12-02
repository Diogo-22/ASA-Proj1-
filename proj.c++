#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cstring>


using namespace std;

typedef struct {
    int res;
    int lastIndex;
    int resLeft;
    int resRight;
} Bolinha;

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

    // Matriz de HashTables
    vector<vector<unordered_map<int, int> > > resultHash(m, vector<unordered_map<int, int> >(m));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
            resultHash[i][j][k] = 0; // Initialize each entry with 0
            }
        }
    }

    // Leitura da tabela de operações (matriz n x n)
    vector<vector<int> > opTable(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> opTable[i][j];
        }
    }

    // Leitura da sequência de inteiros
    vector<vector<vector<int> > > resTable(m, vector<vector<int> >(n, vector<int>(1)));
    for (int i = 0; i < m; i++) {
       cin >> resTable[i][i][0];
    }

     int desiredResult;
    cin >> desiredResult;
    int counter = 0;
    int nºsol = 0; 
    int placeholder = 0;
    for (int i = 0; i < m; i++) {  
            //for ( int j= counter; j < m; j++){
            int j = i+counter;
                for (int x = j-1; x >= i, x++){
                    for (int z = 0; z < n; z++)
                    {
                        for (int k = 0; k < n; k++)
                        {
                            placeholder = calc(resTable[i][x][z], resTable[x+1][j][k], opTable);
                        if(resTable[i][j][z] does not contains placeholder)
                            {resTable[i][j][z] = placeholder;
                            new Bolinha = {resTable[i][j][z], j, resTable[i][j-1][z], resTable[j][j][0]};
                            
                            }
                        }
                    
                    }
                }
           // }
           counter++;
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






/* 
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
    } */