#include <stdio.h>

struct Candidato {
    int numero;
    char nome[50];
    int votos;
}; 

// Função para votar
int votar(struct Candidato candidatos[], int totalCandidatos) {
    int voto;
    printf("Digite o número do candidato (1 a 99): ");
    scanf("%d", &voto);
    int encontrado = 0; 
    for (int i = 0; i < totalCandidatos; i++) {
        if (candidatos[i].numero == voto) {
            candidatos[i].votos++;
            encontrado = 1; 
            printf("Voto computado para %s!\n", candidatos[i].nome);
            return 1;
        }
    }
    if (!encontrado) {  // Corrigido aqui: a mensagem só aparece se não encontrar o candidato
        printf("Número de candidato inválido!\n");
    }
    return 0;
}

// Função para apurar votos
void apurarVotos(struct Candidato candidatos[], int totalCandidatos) {
    printf("\nResultado da apuração de votos:\n");
    for (int i = 0; i < totalCandidatos; i++) {  // Corrigido o índice, começando de 0
        printf("%s (Número %d): %d votos\n", candidatos[i].nome, candidatos[i].numero, candidatos[i].votos);
    }
}

// Função para mostrar o percentual de votos
void percentualVotos(struct Candidato candidatos[], int totalCandidatos, int totalVotos) {
    if (totalVotos == 0) {
         printf("Nenhum voto computado ainda.\n");
         return;
    }
    printf("\nPercentual de votos:\n");
    for (int i = 0; i < totalCandidatos; i++) {
        float percentual = (float)candidatos[i].votos / totalVotos * 100;  // Corrigido o cálculo do percentual
        printf("%s: %.2f%% dos votos\n", candidatos[i].nome, percentual);
    }
}

int main() {
    struct Candidato candidatos[3] = {{10, "João da Padaria", 0}, {20, "Maria da Farmácia", 0}, {30, "Zé do Gás", 0}};
    int opcao;
    int totalVotos = 0;
    int totalCandidatos = 3;
    
    do {
        printf("\nMenu de opções:\n");
        printf("1. Votar\n");
        printf("2. Apurar Votos\n");
        printf("3. Emitir percentual de votos\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                totalVotos += votar(candidatos, totalCandidatos);
                break;  // Corrigido: Adicionado 'break' aqui para evitar execução de outros cases
            case 2: 
                apurarVotos(candidatos, totalCandidatos);
                break;  // Corrigido: Adicionado 'break' aqui
            case 3: 
                percentualVotos(candidatos, totalCandidatos, totalVotos);
                break;  // Corrigido: Adicionado 'break' aqui
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 4); // Corrigido: A opção 4 não existe, logo o programa irá sair ao digitar '4'
    
    return 0;
}
