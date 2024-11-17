#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

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
    if (counter > 0) {
        for (int l = m; l > l-counter; l--) {
            sequence2[l-1] = calc(sequence2[l-1], sequence2[l], opTable);

        }
    }
    vector<int> sequence2 = sequence;
    for (int i = 1; i < m-counter; ++i) {
        sequence2[i] = calc(sequence2[i-1], sequence2[i], opTable);
    }
    if( sequence2.back() == desiredResult ) {
        cout << "YES\n";
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