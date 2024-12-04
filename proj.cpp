#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <string>


using namespace std;

typedef struct {
    int res;
    int lastIndex;
    int resLeft;
    int resRight;
} Bolinha;

int calc(int a, int b, int n, vector<vector<int> >& opTable) {
    if (a > n || b > n) {
        return -1;
    }
    return opTable[a-1][b-1];
}

string recursive(int i, int j, int res, int n, vector<vector<vector<Bolinha> > >& resTable){
    // Diagonal principal
    if (resTable[i][j][0].lastIndex == -1 && resTable[i][j][0].res == res){
        return to_string(resTable[i][j][0].res);
    }
    else {
        for (int k = 0; k < n; k++){
            if (resTable[i][j][k].res == res){
                //printf("res da bolinha = %d\n", resTable[i][j][k].res);
            int left_j = resTable[i][j][k].lastIndex;
            int right_i = left_j + 1;
            int left_res = resTable[i][j][k].resLeft;
            int right_res = resTable[i][j][k].resRight;
            string left = recursive(i,left_j,left_res,n,resTable);
            string right = recursive(right_i,j,right_res,n,resTable);
            return "(" + left + " " + right + ")";
            }
        }
        //printf("recursive 0\n");
        return "0";
        
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n, m;

    // Leitura de n e m
    cin >> n >> m;
    if (n < 1 || m < 1) {
        cout << "0\n";
        return 0;
    }

    // Leitura da tabela de operações (matriz n x n)
    vector<vector<int> > opTable(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> opTable[i][j];
        }
    }

    // Leitura da sequência de inteiros
    vector<vector<vector<Bolinha> > > resTable = vector<vector<vector<Bolinha> > >(m, vector<vector<Bolinha> >(m, vector<Bolinha>()));

    for (int i = 0; i < m; i++) {
        resTable[i][i].push_back(Bolinha());
        cin >> resTable[i][i][0].res;
        resTable[i][i][0].lastIndex = -1;
        resTable[i][i][0].resLeft = -1;
        resTable[i][i][0].resRight = -1;
        

    }

    int desiredResult;
    cin >> desiredResult;
    int counter = 1;
    while (counter < m)
    {
    for (int i = 0; i < m-1; i++) {  
            //for ( int j= counter; j < m; j++){
            int j = i+counter;
            if(j >= m)
                {break;}

                int n_sol = 0;
                // Vetor de resultados
                vector<bool> results = vector<bool>(n, false);

                for (int x = j-1; x >= i && n_sol != n; x--){
                    if (n_sol == n)
                    {
                        break;
                    }
                    
                    vector<Bolinha> left_solutions = resTable[i][x]; 
                   
                    for (int z = 0; z < (int) left_solutions.size() && n_sol != n; z++)
                    {
                        int lv = left_solutions[z].res; 
                        vector<Bolinha> right_solutions = resTable[x+1][j]; 
                              
                        for (int k = 0; k < (int) right_solutions.size() && n_sol != n; k++)
                        {
                            int rv = right_solutions[k].res;   
                            int v = calc(lv, rv, n, opTable);
            
                            if(!results[v]) {
                                results[v] = true;
                                Bolinha b = {v, x, lv, rv};
                                resTable[i][j].push_back(b);
                                n_sol++;
                            }
                        }
                    }
                }
           
        }
    
counter++;
}
    string output = recursive(0,m-1,desiredResult,n,resTable);
    if(output != "0")
        cout << "1\n";
    cout << output << '\n';
    

    //print resTable
    /* for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (j>=i){
                cout << "[";
            for (int z = 0; z < n; z++)
            {
                cout << resTable[i][j][z].res << ", ";
            }
            cout << "] ";}
            
        }
        cout << '\n';
    } */

    // Leitura do resultado desejado

    return 0;
}