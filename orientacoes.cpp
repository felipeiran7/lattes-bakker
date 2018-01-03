#include <iostream>
#include <fstream>
#include "headers.h"
#include <string.h>


using namespace std;

orientacoes *guarda_orientacoes(){
    int i=0,tamanho_nome=0;
    char *buffer, *reinicia_buffer, *result;

    orientacoes *qt_orientacoes;
    qt_orientacoes= new orientacoes[668];

    buffer= new char[800];
    reinicia_buffer= buffer;

    ifstream arquivo_orient;
    arquivo_orient.open("arquivos/orientacao.csv");

    if(arquivo_orient.is_open()){
        while(arquivo_orient.good()){
            arquivo_orient.getline(buffer,801);

            if (i<667){
                result= strstr(buffer,",");
                *result=NULL;

                buffer=buffer+1;
                tamanho_nome= strlen(buffer);
                buffer[tamanho_nome-1]=NULL;
                strcpy(qt_orientacoes[i].id_docente, buffer);
                buffer= result+1;

                result= strstr(buffer,",");
                *result=NULL;
                strcpy(qt_orientacoes[i].id_orientacao,buffer);
                buffer= result+1;

                result= strstr(buffer,"\",\"");
                *result=NULL;
                buffer=buffer+1;
                strcpy(qt_orientacoes[i].tipo_orientacao,buffer);
                buffer= result+1;

                result= strstr(buffer,"\",");
                *result=NULL;
                buffer=buffer+2;
                strcpy(qt_orientacoes[i].titulo,buffer);
                buffer= result+1;

                result= strstr(buffer,"\",");
                *result=NULL;
                buffer=buffer+2;
                strcpy(qt_orientacoes[i].nome_orientando,buffer);
                buffer= result+1;

                buffer=buffer+1;
                strcpy(qt_orientacoes[i].ano,buffer);


                buffer=reinicia_buffer;
                i++;
            }
        }
    }
    return qt_orientacoes;

}
