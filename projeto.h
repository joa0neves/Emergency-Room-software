#ifndef PROJETO_H_INCLUDED
#define PROJETO_H_INCLUDED

typedef struct data{
    int dia,mes,ano,hora,minuto;
}Data;

typedef struct paciente{
    char nome[100];
    int bi;
    Data entrada;
    char prioridade[10];
}Paciente;

typedef struct lnode *List;
typedef struct lnode{
    Paciente info;
    List next;
 }List_node;

List cria_lista(void);
Paciente recolhe();
char* triagem();
void insere_lista(List lista,Paciente it);
void imprime_elemento(Paciente it);
void imprime_lista(List lista);
void insere_lista_inicio(List lista,Paciente it);
Paciente procura_paciente(List lista,int b);
void imprime_elementop(Paciente it);
int existe(List lista,int b);
void elimina_paciente(List lista, int bi);
Paciente primeiro_da_lista(List lista);
int lista_vazia(List lista);
void chamada(List vermelho,List verde,List amarelo,List aux,int *conta_vermelho,int *conta_amarelo);
#endif // PROJETO_H_INCLUDED
