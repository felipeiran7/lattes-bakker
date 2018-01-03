#include <iostream>
#include "headers.h"
#include <fstream>
#include <string.h>

using namespace std;


producoes *guarda_producoes(){
    int i=0,tamanho=0;
    char *buffer, *reinicia_buffer, *result;//PONTEIROS DE RETORNO
    producoes *producao;//VETOR DE PRODUÇÃO

    producao= new producoes[381];//ALOCANDO O VETOR DE PRODUÇÃO DE ACORDO COM A QUANTIDADE

    buffer= new char[401];//ALOCA BUFFER
    reinicia_buffer=buffer;// UM PONTEIRO QUE GUARDA O ESTADO INICIAL DO BUFFER

    ifstream arquivo_producoes;//CRIA A VARIAVEL ARQUIVO PRODUÇÃO

    arquivo_producoes.open("arquivos/producao_V2.csv");//ABRE O ARQUIVO
    if(arquivo_producoes.is_open()){                   //VERIFICA O ESTADO  DO ARQUIVO
        while(!arquivo_producoes.eof()){              //PERCORRE ATÉ O FIM DO ARQUIVO
            arquivo_producoes.getline(buffer,400);

            if (i<379){
            result= strstr(buffer, ",");//ENCONTRA A VIRGULA NA STRING
            *result=NULL;// JOGA NULL NA VIRGULA (STRING SÓ LER ATÉ O \0)
            buffer=buffer+1;//FAZ BUFFER ANDAR UMA POSIÇÃO PARA RETIRAR ASPAS
            tamanho= strlen(buffer);
            buffer[tamanho-1]=NULL;// RETIRA ASPAS DO FINAL DO BUFFER
            strcpy(producao[i].id_autor,buffer);//COPIA O BUFFER PRA POSIÇÃO DE ID DO AUTOR NA STRUCT
            buffer= result+1;


            result= strstr(buffer,  ",\"");//REPETE O PROCESSO DO INICIO ANTERIOR
            *result=NULL;//REPETE O MESMO PROCESSO ANTERIOR
            strcpy(producao[i].id_producao,buffer);
            buffer= result+1;


            result= strstr(buffer, ",");
            *result=NULL;
            buffer=buffer+1;
            tamanho= strlen(buffer);
            buffer[tamanho-1]=NULL;
            tamanho= strlen(buffer);//PEGA O TAMANHO TOTAL DO BUFFER
            strcpy(producao[i].tipo,buffer);//COPIA
            buffer= result+1;//ANDA


            result= strstr(buffer, ",");
            *result=NULL;
            buffer=buffer+1;
            tamanho= strlen(buffer);
            buffer[tamanho-1]=NULL;
            strcpy(producao[i].issn,buffer);
            buffer= result+1;


            result= strstr(buffer, ",\"");
            *result=NULL;
            strcpy(producao[i].titulo,buffer);
            buffer= result+1;


            result= strstr(buffer, "\",");
            *result=NULL;
            buffer=buffer+1;
            strcpy(producao[i].local,buffer);
            buffer= result+1;


            buffer=buffer+1;
            strcpy(producao[i].ano,buffer);
            }

            buffer= reinicia_buffer;//AQUI REINICIA O BUFFER, POIS QUANDO MUDAMOS O ENDEREÇO DE MÉMORIA, SEU TAMANHO ESTOURA.
            i++;

        }
    }

    return producao;
}
