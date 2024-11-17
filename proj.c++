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
    int n, m;

    cout << "Digite n e m: ";

    // Leitura de n e m
    cin >> n >> m;
    cout << "n: " << n << ", m: " << m << '\n';


    // Leitura da tabela de operações (matriz n x n)
    vector<vector<int> > opTable(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> opTable[i][j];
        }
    }

    // Leitura da sequência de inteiros
    vector<int> sequence(m);
    for (int i = 0; i < m; ++i) {
        cin >> sequence[i];
    }

    // Leitura do resultado desejado
    int desiredResult;
    cin >> desiredResult;
    vector<int> sequence2 = sequence;
    int counter = 0;
    do{
    sequence2 = sequence;
    if (counter > 0) {
            sequence2[1+counter] = calc(sequence2[1+counter], sequence2[2+counter], opTable);
   
    }
    
    for (int i = 1; i < m; i++) {
        if (counter == 0) {
            sequence2[i] = calc(sequence2[i-1], sequence2[i], opTable);
        }   
        else if(2 + counter != i)
            sequence2[i] = calc(sequence2[i-1], sequence2[i], opTable);
        else {
            sequence2[i] = sequence2[i-1];
        }
    }

   
    if( sequence2.back() == desiredResult ) {
        cout << "YES\n";
         string s = "";
    for (int i = 0; i < n+1; i++) {
        s += "(";
    }
    s += to_string(sequence[0]) + " " + to_string(sequence[1]) + ")";

    for (int i = 2; i < m; i++) {
        if (i == 1 + counter) {
            s += " (" + to_string(sequence[i]) +" "+ to_string(sequence[i+1]) + "))";
        }
        else if (i == 2 + counter && counter > 0) {
            continue;
        }
        else {
            s += " " + to_string(sequence[i]) + ")";
        }
        
    }
    cout << s << '\n';
    } else {
        cout << "NO\n";
    }
    counter++;
    } while (sequence2.back() != desiredResult || counter > m);

    // Apenas para verificar a leitura (debug)
    /* cout << "n: " << n << ", m: " << m << '\n';
    cout << "Tabela de Operações:\n";
    for (const auto& row : opTable) {
        for (int val : row) {
            cout << val << ' ';
        }
        cout << '\n';
    }
    cout << "Sequência: ";
    for (int val : sequence) {
        cout << val << ' ';
    }
    cout << "\nResultado Desejado: " << desiredResult << '\n'; */

    return 0;
}