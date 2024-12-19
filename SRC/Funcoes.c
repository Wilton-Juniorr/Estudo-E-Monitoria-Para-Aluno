#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct{
char Nome[60];
char Matricula[12];
char Curso[40];
int Periodo;
int QuantDisciplina;
char Disciplina[10][50];
char Email[50];
} Aluno;

typedef struct{
int QuantDisciplina;
char Disciplina[10][50];
int TempoEstudo;
} Cronograma;

typedef struct{
char Materia [50];
char Enuciado [300];
char Alternativas [5][800];
int Resposta;
int QuantQuest;
} Questoes;

typedef struct{    
char NomeMonitor[50];
char EmailMonitor[50]; //pode ser o email secundario
int Horario;
char Telefone[11];
} Monitor;

void Linha(){
    printf("_______________________________\n");
}


void CadAluno(Aluno *aluno){
int contstring;

do{
printf("Digite seu Nome:\n");
getchar();
fgets(aluno ->Nome, 60, stdin);
contstring = strlen(aluno ->Nome);
if(contstring <= 1){
    printf("Invalido!!DIGITE SEU NOME.\n");
}
aluno ->Nome [strcspn(aluno ->Nome, "\n")] = '\0';
}while(contstring <= 1);
Sleep(750);
system("cls");

do{
printf("Digite seua Matricula:\n");
getchar();
fgets(aluno ->Matricula, 12, stdin);
contstring = strlen(aluno ->Matricula);
if(contstring !=10){
    printf("Matricula Invalida!!A Matricula tem 10 Numeros:\n");
}
aluno ->Matricula[strcspn(aluno ->Matricula, "\n")] = '\0';
}while(contstring != 10);
Sleep(750);
system("cls");

do{
printf("Digite o seu Curso:\n");
getchar();
fgets(aluno ->Curso, 40, stdin);
contstring = strlen(aluno ->Curso);
if(contstring <=2){
printf("Invalido!!Tem que ter no minomo dois caracteres.\n");
}
aluno ->Curso[strcspn(aluno ->Curso, "\n")] = '\0';
}while(contstring <=2);
Sleep(750);
system("cls");

do{
printf("Digite o seu Periodo:\n");
scanf("%d", &aluno ->Periodo);
if(aluno ->Periodo < 1 ||aluno ->Periodo > 12){
printf("Invalido!!Max de periodo 12\n");
}
}while(aluno ->Periodo < 1 || aluno ->Periodo > 12);
Sleep(750);
system("cls");

do{
printf("Digite a Quantidade de disciplinas:\n");
scanf("%d", &aluno ->QuantDisciplina);
if(aluno ->QuantDisciplina < 1 || aluno ->QuantDisciplina > 10){
printf("Quantidade MAX de DISCIPLINAS E 10.\n");
}
}while(aluno ->QuantDisciplina < 1 || aluno ->QuantDisciplina > 10);
Sleep(750);
system("cls");

for(int i = 0; i < aluno ->QuantDisciplina; i++){
do{
printf("Digite as Disciplinas:\n");
getchar();
fgets(aluno ->Disciplina[i], 50, stdin);
contstring = strlen(aluno ->Disciplina[i]);
if(contstring <= 3){
printf("Caracteres Insulficientes!!TENTE NOVAMENTE.\n");
}
aluno ->Disciplina[i][strcspn(aluno ->Disciplina[i], "\n")] = '\0';
}while(contstring <= 3);
}
Sleep(750);
system("cls");

do{
printf("Digite seu Email:\n");
getchar();
fgets(aluno ->Email, 50, stdin);
if(contstring <= 3){
printf("Caracteres Insulficientes!!TENTE NOVAMENTE.\n");
}
aluno ->Email[strcspn(aluno ->Email, "\n")] = '\0';
}while(contstring <= 3);

printf("Cadastrando Aluno...\n");
Sleep(2000);
printf("Cadastrado com Sucesso.\n");
Sleep(1500);

FILE *Alunotxt = fopen(aluno ->Matricula, 'M');

fprintf(Alunotxt, "Nome: %s\n", aluno ->Nome);
fprintf(Alunotxt, "Matricula: %s\n", aluno ->Matricula);
fprintf(Alunotxt, "Curso: %s\n", aluno ->Curso);
fprintf(Alunotxt, "Periodo: %d\n", aluno ->Periodo);
fprintf(Alunotxt, "Quantidade de Disciplina: %d\n", aluno ->QuantDisciplina);
for(int i = 0; i < aluno ->QuantDisciplina; i++){
fprintf(Alunotxt, "Disciplina: %s\n", i + 1, aluno ->Disciplina[i]);
}
fprintf(Alunotxt, "Email: %s\n", aluno ->Email);

fclose(Alunotxt);

 
    FILE *NomeAlunotxt = fopen("CadastroAluno.txt","a"); 

    fprintf(NomeAlunotxt, "Nome: %s\n", aluno ->Nome);
    fprintf(NomeAlunotxt, "Matricula: %s\n", aluno ->Matricula);
    fprintf(NomeAlunotxt, "Curso: %s\n", aluno ->Curso);
    fprintf(NomeAlunotxt, "Periodo: %d\n", aluno ->Periodo);
    fprintf(NomeAlunotxt, "Quantidade de Disciplina: %d\n", aluno ->QuantDisciplina);
    for(int i=0; i < aluno ->QuantDisciplina; i++){
    fprintf(NomeAlunotxt, "Disciplina: %s\n", aluno ->Disciplina);
    fprintf(NomeAlunotxt, "Email: %s\n", aluno ->Email);

    }
    fclose(NomeAlunotxt);
}


void CronogramaEstudo(Cronograma *cronograma){
    int contstring;
    do{
        printf("Digite as Disciplinas:\n");
        scanf("%d", &cronograma ->QuantDisciplina);
        if(cronograma ->QuantDisciplina < 1 || cronograma ->QuantDisciplina > 10){
            printf("Quantidade MAX 10.\n");
        }
    }while(cronograma ->QuantDisciplina < 1 || cronograma ->QuantDisciplina > 10);
for(int i= 0; i < cronograma ->QuantDisciplina; i++){
    do{
        printf("Digite as Disciplinas:\n");
        getchar();
        fgets(cronograma ->Disciplina[i], 50, stdin);
        contstring = strlen(cronograma ->Disciplina[i]);
        if(contstring <= 3){
            printf("Quantidade Minima de caracteres insulficientes!TENTE NOVAMENTE\n");
        }
        cronograma ->Disciplina[i][strcspn(cronograma ->Disciplina[i], "\n")] = '\0';
    }while(contstring <= 3);
    }
    Sleep(750);
    system("cls");

}