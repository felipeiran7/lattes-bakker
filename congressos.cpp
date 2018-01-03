#include <iostream>
#include <fstream>
#include "headers.h"
#include <string.h>

using namespace std;

congressos *guarda_congressos(){
    int i=0,tamanho=0,k=0;
    char *buffer, *reinicia_buffer, *result;//PONTEIROS DE RETORNO
    congressos *congressos_capes;

    congressos_capes= new congressos[1181];
    buffer= new char[400];
    reinicia_buffer= buffer;

    ifstream arquivo_congressos;

    arquivo_congressos.open("arquivos/qualis_capes_congressos.csv");
    if (arquivo_congressos.is_open())
        while (arquivo_congressos.good()){
            arquivo_congressos.getline(buffer,399);

            if (i<1179){

            if(i>0){
                result=strstr(buffer, " - ");
                *result=NULL;
                buffer=result+1;
            }

            buffer=buffer+2;
            result= strstr(buffer, "\",\"");
            *result=NULL;
            strcpy(congressos_capes[i].nome_congresso,buffer);
            buffer= result+1;

            result=strstr(buffer, "\",\"");
            *result=NULL;
            buffer=buffer+2;
            strcpy(congressos_capes[i].sigla_congresso,buffer);
            buffer= result+1;

            buffer=buffer+2;
            tamanho=strlen(buffer);
            buffer[tamanho-1]=NULL;
            strcpy(congressos_capes[i].estrato_qualis,buffer);

            i++;
            buffer= reinicia_buffer;
            }
    }

    return congressos_capes;
}
