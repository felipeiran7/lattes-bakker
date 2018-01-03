#include <iostream>
#include <fstream>
#include "headers.h"
#include <string.h>


using namespace std;

void contaorientacoes(quantidade_orientacoes **contador_orientacoes, docente **docentes, orientacoes **orientacoes){
    int i=0,j=0;

    for (i=1; i<16; i++){
        (*contador_orientacoes)[i].dissertacao_mestrado=0;
        (*contador_orientacoes)[i].iniciacao_cientifica=0;
        (*contador_orientacoes)[i].monografia_aperf_especializacao=0;
        (*contador_orientacoes)[i].tese_doutorado=0;
        (*contador_orientacoes)[i].trabalho_conclusao_curso=0;

        for (j=1; j<667; j++){
            if(strcmp((*docentes)[i].id,(*orientacoes)[j].id_docente)==0){
                if(strcmp((*orientacoes)[j].tipo_orientacao,"Dissertação de mestrado")==0){
                    (*contador_orientacoes)[i].dissertacao_mestrado+=1;
                }

                else if(strcmp((*orientacoes)[j].tipo_orientacao,"INICIACAO_CIENTIFICA")==0){
                        (*contador_orientacoes)[i].iniciacao_cientifica+=1;
                }
                else if(strcmp((*orientacoes)[j].tipo_orientacao,"TRABALHO_DE_CONCLUSAO_DE_CURSO_GRADUACAO")==0){
                        (*contador_orientacoes)[i].trabalho_conclusao_curso+=1;
                }
                else if (strcmp((*orientacoes)[j].tipo_orientacao,"Tese de doutorado")==0){
                        (*contador_orientacoes)[i].tese_doutorado+=1;
                }
                else if (strcmp((*orientacoes)[j].tipo_orientacao,"MONOGRAFIA_DE_CONCLUSAO_DE_CURSO_APERFEICOAMENTO_E_ESPECIALIZACAO")==0){
                        (*contador_orientacoes)[i].monografia_aperf_especializacao+=1;
                 }
            }
        }
    }

 }
