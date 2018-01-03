#include <iostream>
#include <fstream>
#include "headers.h"
#include <string.h>


using namespace std;


docente *guarda_docentes(){
    int i=0,tamanho_nome=0;
    char *buffer, *reinicia_buffer, *result;

    docente *lista_docentes;
    lista_docentes = new docente[17];

    buffer= new char[300];

    reinicia_buffer= buffer;

    ifstream arquivo_docentes;
    arquivo_docentes.open("arquivos/docentes.csv");
    if (arquivo_docentes.is_open()){
            while(arquivo_docentes.good()){
                            arquivo_docentes.getline(buffer,300);
                            if (i<16){
                                result= strstr(buffer,",");
                                *result= NULL;
                                buffer=buffer+1;
                                tamanho_nome= strlen(buffer);
                                buffer[tamanho_nome-1]=NULL;
                                strcpy(lista_docentes[i].id,buffer);
                                buffer= result+1;

//*===========================RETIRANDO ASPAS DA STRING=======================================================================
                                buffer=buffer+1;
                                tamanho_nome=strlen(buffer);
                                buffer[tamanho_nome-1]=NULL;
//*===========================================================================================================================

                                strcpy(lista_docentes[i].nome,buffer);

                                  buffer= reinicia_buffer;
                                  i++;
                            }
                    }

        arquivo_docentes.close();
    }

    return lista_docentes;

}

