#include <iostream>
#include <fstream>
#include "headers.h"
#include <string.h>

using namespace std;

void contaproducoes(quantidade_producoes **contador_producoes, docente **docentes, producoes **producoes){
    int i,j;


    for (i=1; i<16; i++){
            (*contador_producoes)[i].artigo_publicado= 0;
            (*contador_producoes)[i].trabalho_em_evento = 0;
            for (j = 1;j < 380;j++){
                    if (strcmp((*docentes)[i].id, (*producoes)[j].id_autor) == 0){
                            if (strcmp((*producoes)[j].tipo,"ARTIGO-PUBLICADO") == 0){
                                    (*contador_producoes)[i].artigo_publicado += 1;
                            }
                            if (strcmp((*producoes)[j].tipo,"ARTIGO-ACEITO-PARA-PUBLICACAO") == 0){
                                    (*contador_producoes)[i].artigo_publicado += 1;
                            }
                            if (strcmp((*producoes)[j].tipo,"TRABALHO_EM_EVENTO") == 0){
                                    (*contador_producoes)[i].trabalho_em_evento += 1;
                            }
                    }
            }
    }





}
