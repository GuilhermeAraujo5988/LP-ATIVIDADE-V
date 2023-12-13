#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void agencia()
{
    printf("BANCO BRADESCO");
};

struct contaa
{
    float saldo;
};

void limpaTela()
{
    system("cls || clear");
}

float saldoAtual(float saldoAntigo, float deposito, float saque)
{
    return saldoAntigo += deposito - saque;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct contaa conta;
    int op;
    float deposito = 0;
    float soma = 0;
    float subtracao = 0;
    float saque = 0;
    char dinheiro = 0;

    printf("Na sua conta possui saldo? \n\n");
    printf("Digite S para Sim ou N para Não: ");
    scanf("%s", &dinheiro);
    limpaTela();

    if (dinheiro != 'S')
    {
        conta.saldo = 0;
    }
    else
    {
        printf("Digite o valor atual na conta: R$");
        scanf("%f", &conta.saldo);
        limpaTela();
    }

    limpaTela();

    do
    {

        printf("1 - Deposito  \n");
        printf("2 - Saque  \n");
        printf("3 - Consultar nome agência \n");
        printf("4 - Saldo da conta\n\n");

        printf("Digite a opção que deseja prosseguir: ");
        scanf("%d", &op);

        switch (op)
        {

        case 1:

            printf("Digite a quantidade para deposito: R$");
            scanf("%f", &deposito);
            soma += deposito;
            limpaTela();
            break;

        case 2:
            printf("Digite a quantidade do saque: R$");
            scanf("%f", &saque);

            subtracao += saque;
            limpaTela();
            break;

        case 3:
            agencia();
            sleep(3);
            limpaTela();

            break;

        default:
            printf("Opção invalida");

            limpaTela();
            break;
        }
    } while (op != 4);

    agencia();
    printf("\n\n");
    printf("Saldo Anterior: R$%.2f\n", conta.saldo);
    printf("Deposito: R$%.2f\n", soma);
    printf("Saque: R$%.2f\n\n", subtracao);
    printf("Saldo atual: R$%.2f\n", saldoAtual(conta.saldo, soma, subtracao));

    return 0;
}