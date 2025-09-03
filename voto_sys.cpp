#include <iostream>

int main() {
    int voto = 0;
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

    while (true) {
        std::cin >> voto;

        if (voto == -1) {
            break;
        }

        totalEleitores++;

        switch (voto) {
            case 1:
                candidato1++;
                break;
            case 2:
                candidato2++;
                break;
            case 3:
                candidato3++;
                break;
            case 0:
                brancos++;
                break;
            case 4:
                nulos++;
                break;
            default:
                std::cout << "(Voto inválido, computado como nulo)\n";
                nulos++;
                break;
        }
    }

    std::cout << "\n--- Resultado da Votação ---\n";

    if (candidato1 > candidato2 && candidato1 > candidato3) {
        std::cout << "Candidato vencedor: 1\n";
    } else if (candidato2 > candidato1 && candidato2 > candidato3) {
        std::cout << "Candidato vencedor: 2\n";
    } else if (candidato3 > candidato1 && candidato3 > candidato2) {
        std::cout << "Candidato vencedor: 3\n";
    } else {
        std::cout << "Candidato vencedor: Houve um empate entre os candidatos mais votados.\n";
    }

    std::cout << "Número de votos em branco: " << brancos << "\n";
    std::cout << "Número de votos nulos: " << nulos << "\n";
    std::cout << "Número total de eleitores que votaram: " << totalEleitores << "\n";
    
    std::cout << "\n--- Votos por Candidato ---\n";
    std::cout << "Candidato 1: " << candidato1 << " votos\n";
    std::cout << "Candidato 2: " << candidato2 << " votos\n";
    std::cout << "Candidato 3: " << candidato3 << " votos\n";


    return 0;
}