#include <iostream>
#include <fstream>
#include "headers.h"
#include <string.h>


using namespace std;

periodicos *guarda_periodicos()
{
    int i=0,tamanho=0;
    char *buffer, *reinicia_buffer, *result;//PONTEIROS DE RETORNO

    periodicos *lista_periodicos;

    lista_periodicos= new periodicos[177061];
    buffer= new char[300];
    reinicia_buffer= buffer;

    ifstream arquivo_periodicos;
    arquivo_periodicos.open("arquivos/qualis_capes_periodicos.csv");


    if (arquivo_periodicos.is_open()){
        while(arquivo_periodicos.good()){
            arquivo_periodicos.getline(buffer,300);

            if(i<177059){
            result= strstr(buffer,  "\",\"");
            *result=NULL;
            buffer=buffer+1;
            strcpy(lista_periodicos[i].issn,buffer);
            buffer= result+1;


            result= strstr(buffer,  "\",\"");
            *result=NULL;
            buffer=buffer+2;
            strcpy(lista_periodicos[i].nome_periodico,buffer);
            buffer= result+1;

            result= strstr(buffer, "\",\"");
            *result=NULL;
            buffer=buffer+2;
            strcpy(lista_periodicos[i].area_avaliacao,buffer);
            buffer= result+1;


            buffer=buffer+2;
            tamanho= strlen(buffer);
            buffer[tamanho-1]=NULL;
            strcpy(lista_periodicos[i].estrato_qualis,buffer);

            i++;
            buffer=reinicia_buffer;

            }
        }
    }
    return lista_periodicos;
}
