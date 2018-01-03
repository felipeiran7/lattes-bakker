#include <iostream>
#include <fstream>
#include "headers.h"
#include <string.h>

using namespace std;

void contadorperiodicos(quantidade_estratos_periodicos **contador_estratos_periodicos, docente **docentes, producoes **producoes, periodicos **periodicos ){
    int i,j,k;

    for (i = 1;i < 16;i++){
    (*contador_estratos_periodicos)[i].estrato_A1 = 0;
    (*contador_estratos_periodicos)[i].estrato_A2 = 0;
    (*contador_estratos_periodicos)[i].estrato_B1 = 0;
    (*contador_estratos_periodicos)[i].estrato_B2 = 0;
    (*contador_estratos_periodicos)[i].estrato_B3 = 0;
    (*contador_estratos_periodicos)[i].estrato_B4 = 0;
    (*contador_estratos_periodicos)[i].estrato_B5 = 0;
    (*contador_estratos_periodicos)[i].estrato_C = 0;
    (*contador_estratos_periodicos)[i].sem_estrato = 0;
    for (j = 1;j < 381;j++){
      if ((strcmp((*docentes)[i].id, (*producoes)[j].id_autor) == 0) && (strcmp((*producoes)[j].tipo,"ARTIGO-PUBLICADO") == 0)){
        for (k = 1;k < 177061;k++){
          if ((strcmp((*producoes)[j].issn, (*periodicos)[k].issn) == 0) && (strcmp((*periodicos)[k].area_avaliacao,"CIÊNCIA DA COMPUTAÇÃO")== 0)){
            if (strcmp((*periodicos)[k].estrato_qualis, "A1") == 0){
              (*contador_estratos_periodicos)[i].estrato_A1 += 1;
            }
            else if (strcmp((*periodicos)[k].estrato_qualis, "A2") == 0){
              (*contador_estratos_periodicos)[i].estrato_A2 += 1;
            }
            else if (strcmp((*periodicos)[k].estrato_qualis, "B1") == 0){
              (*contador_estratos_periodicos)[i].estrato_B1 += 1;
            }
            else if (strcmp((*periodicos)[k].estrato_qualis, "B2") == 0){
              (*contador_estratos_periodicos)[i].estrato_B2 += 1;
            }
            else if (strcmp((*periodicos)[k].estrato_qualis, "B3") == 0){
              (*contador_estratos_periodicos)[i].estrato_B3 += 1;
            }
            else if (strcmp((*periodicos)[k].estrato_qualis, "B4") == 0){
              (*contador_estratos_periodicos)[i].estrato_B4 += 1;
            }
            else if (strcmp((*periodicos)[k].estrato_qualis, "B5") == 0){
              (*contador_estratos_periodicos)[i].estrato_B5 += 1;
            }
            else if (strcmp((*periodicos)[k].estrato_qualis, "C") == 0){
              (*contador_estratos_periodicos)[i].estrato_C += 1;
            }
            }
            else if (strcmp((*producoes)[j].issn, (*periodicos)[k].issn) == 0){
            (*contador_estratos_periodicos)[i].sem_estrato+= 1;
          }
        }
      }
    }
  }






}
