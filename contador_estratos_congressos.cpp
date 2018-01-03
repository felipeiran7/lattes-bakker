#include <iostream>
#include <fstream>
#include "headers.h"
#include <string.h>


using namespace std;

void contadorcongressos(quantidade_estratos_congressos **contador_estratos_congressos, docente **docentes, producoes **producoes, congressos **congressos){
    int i,j,k;

    for (i = 1;i <16 ;i++){
    (*contador_estratos_congressos)[i].estrato_A1 = 0;
    (*contador_estratos_congressos)[i].estrato_A2 = 0;
    (*contador_estratos_congressos)[i].estrato_B1 = 0;
    (*contador_estratos_congressos)[i].estrato_B2 = 0;
    (*contador_estratos_congressos)[i].estrato_B3 = 0;
    (*contador_estratos_congressos)[i].estrato_B4 = 0;
    (*contador_estratos_congressos)[i].estrato_B5 = 0;
    (*contador_estratos_congressos)[i].estrato_C = 0;
    (*contador_estratos_congressos)[i].sem_estrato = 0;
    for (j = 1;j < 381;j++){
      if ((strcmp((*docentes)[i].id,(*producoes)[j].id_autor) == 0) && (strcmp((*producoes)[j].tipo,"TRABALHO_EM_EVENTO")==0 )){
        for (k = 1;k < 1180;k++){
          if (strstr((*producoes)[j].local,(*congressos)[k].nome_congresso)!= NULL){
            if (strcmp((*congressos)[k].estrato_qualis, "A1") == 0){
              (*contador_estratos_congressos)[i].estrato_A1 += 1;
            } else if (strcmp((*congressos)[k].estrato_qualis, "A2") == 0){
              (*contador_estratos_congressos)[i].estrato_A2 += 1;
            } else if (strcmp((*congressos)[k].estrato_qualis, "B1") == 0){
              (*contador_estratos_congressos)[i].estrato_B1 += 1;
            } else if (strcmp((*congressos)[k].estrato_qualis, "B2") == 0){
              (*contador_estratos_congressos)[i].estrato_B2 += 1;
            } else if (strcmp((*congressos)[k].estrato_qualis, "B3") == 0){
              (*contador_estratos_congressos)[i].estrato_B3 += 1;
            } else if (strcmp((*congressos)[k].estrato_qualis, "B4") == 0){
              (*contador_estratos_congressos)[i].estrato_B4 += 1;
            } else if (strcmp((*congressos)[k].estrato_qualis, "B5") == 0){
              (*contador_estratos_congressos)[i].estrato_B5 += 1;
            }  else if (strcmp((*congressos)[k].estrato_qualis, "C") == 0){
              (*contador_estratos_congressos)[i].estrato_C += 1;
            }
            else{
                (*contador_estratos_congressos)[i].sem_estrato+=1;
            }
            k=1181;
          }
        }
      }
    }
  }


}
