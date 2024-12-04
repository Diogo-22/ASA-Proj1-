#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
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

int calc(int a, int b, vector<vector<int> >& opTable) {
    return opTable[a-1][b-1];
}

string recursive(int i, int j, int res, int n, vector<vector<vector<Bolinha> > >& resTable){
    // Diagonal principal
    if (resTable[i][j][0].lastIndex == -1){
        return to_string(resTable[i][j][0].res);
    }
    else {
        for (int k = 0; k < n; k++){
            if (resTable[i][j][k].res == res){
                int left_j = resTable[i][j][k].lastIndex;
                int right_i = left_j + 1;
                int left_res = resTable[i][j][k].resLeft;
                int right_res = resTable[i][j][k].resRight;
                string left = recursive(i,left_j,left_res,n,resTable);
                string right = recursive(right_i,j,right_res,n,resTable);
                return "(" + left + " " + right + ")";
            }
        }
        return "0";
        
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int n, m;

    // Leitura de n e m
    cin >> n >> m;

    // Matriz de HashTables
    vector<vector<unordered_map<int, int> > > resultHash(m, vector<unordered_map<int, int> >(m));
    hash<int> intHash;
    
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
    vector<vector<vector<Bolinha> > > resTable(m, vector<vector<Bolinha> >(m));

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
    //int nºsol = 0; 
    int placeholder = 0;
    while (counter < m)
    {
    for (int i = 0; i < m-1; i++) {  
            //for ( int j= counter; j < m; j++){
            int j = i+counter;
            if(j >= m)
                {break;}
                for (int x = j-1; x >= i; x--){
                    for (int z = 0; z < n; z++)
                    {
                         //printf("i: %d, j: %d, x: %d, z: %d\n", i, j, x, z);
                        if (resTable[i][x][z].res == 0)
                        {
                            break;
                        }
                        for (int k = 0; k < n; k++)
                        {
                            // printf("i: %d, j: %d, x: %d, z: %d, k: %d\n", i, j, x, z, k);
                            if (resTable[x+1][j][k].res == 0)
                        {
                            break;
                        }
                            //printf("reach\n");
                           
                            placeholder = calc(resTable[i][x][z].res, resTable[x+1][j][k].res, opTable);
                            //printf("placeholder: %d\n", placeholder);
                        //if(resTable[i][j][z] does not contains placeholder)
                        if(resultHash[i][j][intHash(placeholder)] == 0)
                            {
                                //printf("reach2\n");
                                resultHash[i][j][intHash(placeholder)] = 1;
                                //printf("reach3\n");
                            Bolinha b = {placeholder, x, resTable[i][x][z].res, resTable[x+1][j][k].res};
                            //printf("reach4\n");
                            resTable[i][j].push_back(b);
                            //printf("reach5\n");
                            //printf("resTable[%d][%d][%d]: %d\n", i, j, z, resTable[i][j][z].res);
                            }
                        //printf("reach6\n");
                        }
                    
                    }
                }
           // }
           
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