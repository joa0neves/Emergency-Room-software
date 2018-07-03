#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projeto.h"

int main(){
    List espera=cria_lista();
    List aux=cria_lista();
    List verde=cria_lista();
    List amarelo=cria_lista();
    List vermelho=cria_lista();
    int in,b,conta_amarelo=0,conta_vermelho=0;
    Paciente doente;
    do{
        printf("1}Adicionar paciente a lista de espera.\n2}Imprime lista de espera.\n3}Atribuir Triagem.\n4}Eliminar um paciente das listas\n5}Imprimir Pacientes com prioridade Verde\n6}Imprimir Pacientes com prioridade Amarela\n7}Imprimir Pacientes com prioridade Vermelha\n8}Mostrar Lista com os pacientes (mais recente->mais antigo)\n9}Proximo Paciente para consulta\n0} Sair\n");
        printf("Introduza comando:\n");
        scanf("%d",&in);
        switch(in){
            case 1:{
                doente=recolhe();
                insere_lista(espera,doente);
                break;
            }
            case 2:imprime_lista(espera);break;
            case 3:{
                printf("Introduza o BI do paciente:\n");
                scanf("%d",&b);
                if (existe(espera,b)==0){
                    printf("Nao existe um paciente com esse bi(nao se esqueca que o bi tem 8 digitos!)");
                    break;
                }
                doente=procura_paciente(espera,b);
                strcpy(doente.prioridade,triagem());
                insere_lista_inicio(aux,doente);
                elimina_paciente(espera,b);
                if (strcmp(doente.prioridade,"vermelha")==0)
                    insere_lista(vermelho,doente);
                else if (strcmp(doente.prioridade,"verde")==0)
                    insere_lista(verde,doente);
                else if (strcmp(doente.prioridade,"amarela")==0)
                    insere_lista(amarelo,doente);
                break;
            }
            case 4:{
                printf("Introduza o BI do paciente:\n");
                scanf("%d",&b);
                if (existe(espera,b)==1)
                    elimina_paciente(espera,b);
                else if (existe(verde,b)==1){
                    elimina_paciente(verde,b);
                    elimina_paciente(aux,b);
                }
                else if (existe(amarelo,b)==1){
                    elimina_paciente(amarelo,b);
                    elimina_paciente(aux,b);
                }
                else if (existe(vermelho,b)==1){
                    elimina_paciente(vermelho,b);
                    elimina_paciente(aux,b);
                }
            }
            case 5: {imprime_listap(verde);break;}
            case 6: {imprime_listap(amarelo);break;}
            case 7: {imprime_listap(vermelho);break;}
            case 8: {imprime_listap(aux);break;}
            case 9:{
                chamada(vermelho,amarelo,verde,aux,&conta_vermelho,&conta_amarelo);
                break;
            }
            case 0:break;
            default: printf("Input nao reconhecido!\n");
        }
    }while(in!=0);
    return 0;
}

