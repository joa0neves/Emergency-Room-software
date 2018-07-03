#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projeto.h"

List cria_lista(){
    List aux;
    Paciente a;
    aux=(List)malloc(sizeof(List_node));
    if(aux!=NULL){
        aux -> info=a;
        aux -> next=NULL;
    }
    return aux;
}

char* triagem(){
    char* t[10];
    int n,i=1;
    while (i!=0){
        printf("Que Prioridade pretende atribuir?(0=verde;1=amarela:2=vermelha)\n");
        scanf("%d",&n);
        if (n!=0 && n!=1 && n!=2) printf("Input nao reconhecido!\n");
        else break;
    }
    switch(n){
        case 2:strcpy(t,"vermelha");break;
        case 0:strcpy(t,"verde");break;
        case 1:strcpy(t,"amarela");break;
    }
    return t;
}

Paciente recolhe(){
    Paciente doente;
    int i=1;
    printf("Introduza o nome do paciente:\n");
    getchar();
    fgets(doente.nome,100,stdin);
    while (i==1){
        printf("Introduza o BI do paciente:\n");
        scanf("%d",&doente.bi);
        if (doente.bi<9999999 || doente.bi>100000000)
            printf("Todos os numeros de BI tem 8 digitos! Tente outra vez.\n");
        else break;
    }
    while (i==1){
        printf("Introduza a data de entrada(dd/mm/aaaa):\n");
        scanf("%d/%d/%d",&doente.entrada.dia,&doente.entrada.mes,&doente.entrada.ano);
        if (doente.entrada.dia>31 || doente.entrada.mes>12)
            printf("Data nao existente! Tente outra vez.\n");
        else break;
    }
    while (i==1){
        printf("Introduza a hora(hh:mm):\n");
        scanf("%d:%d",&doente.entrada.hora,&doente.entrada.minuto);
        if (doente.entrada.hora>24 || doente.entrada.minuto>59)
            printf("Hora nao existente! Tente outra vez.\n");
        else break;
    }
    return doente;
}
void insere_lista(List lista,Paciente it){
    List ptr=lista;
    List no;
    no=(List)malloc (sizeof(List_node));
    while(ptr->next != NULL)
        ptr=ptr->next;
    no->info=it;
    ptr->next=no;
    no->next=NULL;
}
void imprime_listap (List lista){
    List ptr;
    ptr=lista->next;
    while(ptr!=NULL){
        imprime_elementop(ptr->info);
        ptr=ptr->next;
    }
}
void imprime_elementop(Paciente it){
    printf("\n->Nome: %s",it.nome);
    printf("->Numero de Identificacao: %d\n",it.bi);
    if (it.entrada.minuto<10)
        printf("->Data de entrada: %d/%d/%d\n->Hora de entrada: %d:0%d\n\n",it.entrada.dia,it.entrada.mes,it.entrada.ano,it.entrada.hora,it.entrada.minuto);
    else printf("->Data de entrada: %d/%d/%d\n->Hora de entrada: %d:%d\n",it.entrada.dia,it.entrada.mes,it.entrada.ano,it.entrada.hora,it.entrada.minuto);
    printf("->Prioridade %s\n\n",it.prioridade);
}
void insere_lista_inicio(List lista,Paciente it){
    List ptr=lista->next;
    List no;
    no=(List)malloc(sizeof(List_node));
    no->info=it;
    lista->next=no;
    no->next=ptr;
}
Paciente procura_paciente(List lista,int b){
    List ptr=lista->next;
    while(ptr!=NULL){
        if (b ==(ptr->info).bi){
            return ptr->info;
            break;
        }
        else ptr=ptr->next;
    }

}
void imprime_elemento(Paciente it){
    printf("\n->Nome: %s",it.nome);
    printf("->Numero de Identificacao: %d\n",it.bi);
    if (it.entrada.minuto<10)
        printf("->Data de entrada: %d/%d/%d\n->Hora de entrada: %d:0%d\n\n",it.entrada.dia,it.entrada.mes,it.entrada.ano,it.entrada.hora,it.entrada.minuto);
    else printf("->Data de entrada: %d/%d/%d\n->Hora de entrada: %d:%d\n\n",it.entrada.dia,it.entrada.mes,it.entrada.ano,it.entrada.hora,it.entrada.minuto);
}
void imprime_lista (List lista){
    List ptr;
    ptr=lista->next;
    while(ptr!=NULL){
        imprime_elemento(ptr->info);
        ptr=ptr->next;
    }
}

int existe(List lista,int b){
    List ptr=lista->next;
    while (ptr!=NULL){
        if (ptr->info.bi==b)
            return 1;
        else ptr=ptr->next;
    }
    return 0;
}

void elimina_paciente(List lista, int bi){
    List ant=lista,atual=lista->next;
    while(atual!=NULL){
        if((atual->info).bi==bi){
            ant->next=atual->next;
            free(atual);
            break;
        }
        else{
            ant=atual;
            atual=atual->next;
        }
    }
}
Paciente primeiro_da_lista(List lista){
    List ptr=lista->next,ant=lista;
    Paciente doente=ptr->info;
    ant->next=ptr->next;
    free(ptr);
    return doente;
}
int lista_vazia(List lista){
    return (lista->next == NULL ? 1 : 0);
}
void chamada(List vermelho,List verde,List amarelo,List aux,int *conta_vermelho,int *conta_amarelo){
    Paciente doente;
    if (lista_vazia(vermelho)==1 && lista_vazia(amarelo)==1 && lista_vazia(verde)==1){
        printf("\nNao existe pacientes a espera de consulta.\n\n");
                }
    else if(*conta_vermelho<3){
        if(lista_vazia(vermelho)==0){
            doente=primeiro_da_lista(vermelho);
            elimina_paciente(aux,doente.bi);
            imprime_elemento(doente);
            *conta_vermelho++;
        }
        else if (lista_vazia(amarelo)==0){
            doente=primeiro_da_lista(amarelo);
            elimina_paciente(aux,doente.bi);
            imprime_elemento(doente);
            *conta_amarelo++;
            *conta_vermelho=0;
        }
        else if (lista_vazia(verde)==0){
            *conta_amarelo=0;
            *conta_vermelho=0;
            doente=primeiro_da_lista(verde);
            elimina_paciente(aux,doente.bi);
            imprime_elemento(doente);
        }

    }
    else if(lista_vazia(vermelho)==1){
        if(lista_vazia(amarelo)==0){
            doente=primeiro_da_lista(amarelo);
            elimina_paciente(aux,doente.bi);
            imprime_elemento(doente);
            *conta_amarelo++;
            *conta_vermelho=0;
            }
        else if (lista_vazia(verde)==0){
            *conta_amarelo=0;
            *conta_vermelho=0;
            doente=primeiro_da_lista(verde);
            elimina_paciente(aux,doente.bi);
            imprime_elemento(doente);
        }
        else if (lista_vazia(vermelho)==0){
            doente=primeiro_da_lista(vermelho);
            elimina_paciente(aux,doente.bi);
            imprime_elemento(doente);
            *conta_vermelho++;
            *conta_amarelo=0;
        }
    }
    else{
        if (lista_vazia(verde)!=1){
            *conta_amarelo=0;
            *conta_vermelho=0;
            doente=primeiro_da_lista(verde);
            elimina_paciente(aux,doente.bi);
            imprime_elemento(doente);
        }
        else if (lista_vazia(vermelho)==0){
            doente=primeiro_da_lista(vermelho);
            elimina_paciente(aux,doente.bi);
            imprime_elemento(doente);
            *conta_vermelho++;
            *conta_amarelo=0;
        }
        else if(lista_vazia(amarelo)==0){
            doente=primeiro_da_lista(amarelo);
            elimina_paciente(aux,doente.bi);
            imprime_elemento(doente);
            *conta_amarelo++;
            *conta_vermelho=0;
        }

    }
}
