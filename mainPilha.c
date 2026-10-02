#include "pilha.h"

int main () {
    Tpilha teste;
    
    inicializarPilha(&teste);

    if (estaCheia(&teste)) {
        printf("A pilha esta cheia\n");
    }
    else {
        printf("A pilha nao esta cheia\n");
    }
    
    char esc = 's';
    while (esc == 's') {
        limpa
        printf("Digite um numero Decimal\n> ");
        int num;        // numero a ser convertido
        scanf("%d", &num);

        limpa
        printf("Escolha o tipo de convercao\n");
        printf("\n2 - Binario\n8 - Octal\n16 - Hexadecimal\n\n> ");
        int tipo;
        scanf("%d", &tipo);

        if (tipo == 2) { // entao converter para binario
            converterValor(&teste, num, tipo);
            limpa
            printf("Aqui esta seu Decimal convertido para " C_AZ "binario:\n" RESE_C);
            printf(" pilhaBi = {");
            while (!estaVazia(&teste)) {
                printf("%d", acessar(&teste));
                desempilhar(&teste);
            }
            printf("}\n\n");
        }

        if (tipo == 8) { // entao eh octal
            converterValor(&teste, num, tipo);
            limpa
            printf("Aqui esta seu Decimal convertido para " C_AZ "Octal:\n" RESE_C);
            printf(" pilhaOc = {");
            while (!estaVazia(&teste)) {
                printf("%d", acessar(&teste));
                desempilhar(&teste);
            }
            printf("}\n\n");
        }

        if (tipo == 16) { // entao converter para hexadecimal 
            converterHexadecimal(&teste, num);
            limpa
            printf("Aqui esta seu decimal convertido para " C_AZ "Hexadecimal:\n" RESE_C);
            printf("PilhaHexa = {");
            while (!estaVazia(&teste)) {
                int val = acessar(&teste);
                if (val < 10) {
                    printf("%d", val);
                }
                else {
                    printf("%c", 'A' + (val - 10)); // Converte 10 em 'A' ate 'F'
                }
                desempilhar(&teste);
            }
            printf("}\n\n");
        }

        printf("Deseja continuar (s/n)\n> ");
        scanf(" %c", &esc);
    }
    limpa
    liberarPilha(&teste);
    return 0;
}