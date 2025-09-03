#include <iostream>

void apurarVotos(int* ptrC1, int* ptrC2, int* ptrC3, int* ptrBrancos, int* ptrNulos, int* ptrTotal);
void imprimirResultados(int c1, int c2, int c3, int brancos, int nulos, int total);

int main() {
    int candidato1 = 0;
    int candidato2 = 0;
    int candidato3 = 0;
    int brancos = 0;
    int nulos = 0;
    int totalEleitores = 0;

    std::cout << "--- Urna Eletrônica ---\n";
    std::cout << "1: Candidato 1\n";
    std::cout << "2: Candidato 2\n";
    std::cout << "3: Candidato 3\n";
    std::cout << "0: Voto em Branco\n";
    std::cout << "4: Voto Nulo\n";
    std::cout << "-1: Encerrar votação\n";
    std::cout << "-----------------------\n";
    std::cout << "Digite os votos um por um:\n";

    apurarVotos(&candidato1, &candidato2, &candidato3, &brancos, &nulos, &totalEleitores);

    imprimirResultados(candidato1, candidato2, candidato3, brancos, nulos, totalEleitores);

    return 0;
}


void apurarVotos(int* ptrC1, int* ptrC2, int* ptrC3, int* ptrBrancos, int* ptrNulos, int* ptrTotal) {
    int voto;

    while (true) {
        std::cin >> voto;

        if (voto == -1) {
            break; 
        }

        (*ptrTotal)++; 

        switch (voto) {
            case 1:
                (*ptrC1)++; 
                break;
            case 2:
                (*ptrC2)++;
                break;
            case 3:
                (*ptrC3)++; 
                break;
            case 0:
                (*ptrBrancos)++; 
                break;
            case 4:
                (*ptrNulos)++; 
                break;
            default:
                std::cout << "(Voto inválido, computado como nulo)\n";
                (*ptrNulos)++;
                break;
        }
    }
}

void imprimirResultados(int c1, int c2, int c3, int brancos, int nulos, int total) {
    std::cout << "\n--- Resultado da Votação ---\n";

    if (c1 > c2 && c1 > c3) {
        std::cout << "Candidato vencedor: 1\n";
    } else if (c2 > c1 && c2 > c3) {
        std::cout << "Candidato vencedor: 2\n";
    } else if (c3 > c1 && c3 > c2) {
        std::cout << "Candidato vencedor: 3\n";
    } else {
        std::cout << "Candidato vencedor: Houve um empate entre os candidatos mais votados.\n";
    }

    std::cout << "Número de votos em branco: " << brancos << "\n";
    std::cout << "Número de votos nulos: " << nulos << "\n";
    std::cout << "Número total de eleitores que votaram: " << total << "\n";
    
    std::cout << "\n--- Votos por Candidato ---\n";
    std::cout << "Candidato 1: " << c1 << " votos\n";
    std::cout << "Candidato 2: " << c2 << " votos\n";
    std::cout << "Candidato 3: " << c3 << " votos\n";
}
