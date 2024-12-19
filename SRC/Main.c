#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "Funcoes.c"


int main(){
    Aluno aluno;
    Cronograma cronograma;
    int op;
    do{
        Linha();
        printf("\tMenu de Opcoes:\n");
        printf("1.Cadastro do Aluno:\n");
        printf("2.Cronograma de Estudo:\n");
        printf("0.Sair do Programa:\n");
        Linha();
        scanf("%d", &op);
        system("cls");
        switch(op){
            case 1:{
                CadAluno(&aluno);
                break;
            }
            case 2:{
                CronogramaEstudo(&cronograma);
                break;
            }
            case 0:{
                printf("Saindo do Programa...\n");
                Sleep(1000);
                printf("Obrigado por usar o programa!Volte Sempre.\n");
                break;
            }
            default:
            printf("Opcao Invalida!!TENTE NOVAMENTE.\n");
        }
    }while(op != 0);
    return 0;
}