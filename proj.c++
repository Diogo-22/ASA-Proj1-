#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, m;

    // Leitura de n e m
    cin >> n >> m;

    // Leitura da tabela de operações (matriz n x n)
    vector<std::vector<int>> opTable(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> opTable[i][j];
        }
    }

    // Leitura da sequência de inteiros
    std::vector<int> sequence(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> sequence[i];
    }

    // Leitura do resultado desejado
    int desiredResult;
    std::cin >> desiredResult;

    // Apenas para verificar a leitura (debug)
    std::cout << "n: " << n << ", m: " << m << '\n';
    std::cout << "Tabela de Operações:\n";
    for (const auto& row : opTable) {
        for (int val : row) {
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "Sequência: ";
    for (int val : sequence) {
        std::cout << val << ' ';
    }
    std::cout << "\nResultado Desejado: " << desiredResult << '\n';

    return 0;
}