#include <iostream>
#include <fstream>
#include <string.h>
#include "headers.h"
#include <windows.h>

using namespace std;

int main(){
    SetConsoleOutputCP(65001);

    int i;
    char *result=NULL, *result2, *result3, buffer[100];
    orientacoes *orientacoes;
    docente *docentes;
    producoes *producoes;
    periodicos *periodicos;
    congressos *congressos;


    orientacoes= guarda_orientacoes();
    docentes= guarda_docentes();
    producoes= guarda_producoes();
    periodicos= guarda_periodicos();
    congressos= guarda_congressos();

    quantidade_orientacoes *contador_orientacoes;
    quantidade_producoes *contador_producoes;
    quantidade_estratos_periodicos *contador_estratos_periodicos;
    quantidade_estratos_congressos *contador_estratos_congressos;

    contador_orientacoes= new quantidade_orientacoes[17];
    contador_producoes= new quantidade_producoes[17];
    contador_estratos_periodicos= new quantidade_estratos_periodicos[17];
    contador_estratos_congressos= new quantidade_estratos_congressos[17];


    contaorientacoes(&contador_orientacoes,&docentes,&orientacoes);
    contaproducoes(&contador_producoes, &docentes,&producoes);
    contadorperiodicos(&contador_estratos_periodicos, &docentes, &producoes, &periodicos);
    contadorcongressos(&contador_estratos_congressos, &docentes, &producoes, &congressos);




        for (i = 1;i < 16;i++){
            cout << "Docente: " << docentes[i].nome << "| id: "<< docentes[i].id <<endl;
            cout << "Dissertacoes de mestrado: " << contador_orientacoes[i].dissertacao_mestrado<< endl;
            cout << "Teses de doutorado: " << contador_orientacoes[i].tese_doutorado << endl;
            cout << "artigos publicados:"<< contador_producoes[i].artigo_publicado<<endl;
            cout << "Trabalho de conclusao de curso: " << contador_orientacoes[i].trabalho_conclusao_curso<< endl;
            cout << "Iniciacao cientifica: " << contador_orientacoes[i].iniciacao_cientifica << endl;
            cout<< "trabalho em eventos:"<< contador_producoes[i].trabalho_em_evento<<endl;
            cout<<"\n";
            cout<<"ESTRATOS DE PERIODICOS CAPES: \n";
            cout << "Estrato A1: " << contador_estratos_periodicos[i].estrato_A1 << endl;
            cout << "Estrato A2: " << contador_estratos_periodicos[i].estrato_A2 << endl;
            cout << "Estrato B1: " << contador_estratos_periodicos[i].estrato_B1 << endl;
            cout << "Estrato B2: " << contador_estratos_periodicos[i].estrato_B2 << endl;
            cout << "Estrato B3: " << contador_estratos_periodicos[i].estrato_B3 << endl;
            cout << "Estrato B4: " << contador_estratos_periodicos[i].estrato_B4 << endl;
            cout << "Estrato B5: " << contador_estratos_periodicos[i].estrato_B5 << endl;
            cout << "Estrato C: " << contador_estratos_periodicos[i].estrato_C << endl;
            cout << "Sem Estrato: " << contador_estratos_periodicos[i].sem_estrato << endl;
            cout<<"\n";
            cout<<"ESTRATOS DE CONGRESSOS CAPES: \n";
            cout << "Estrato A1: " << contador_estratos_congressos[i].estrato_A1 << endl;
            cout << "Estrato A2: " << contador_estratos_congressos[i].estrato_A2 << endl;
            cout << "Estrato B1: " << contador_estratos_congressos[i].estrato_B1 << endl;
            cout << "Estrato B2: " << contador_estratos_congressos[i].estrato_B2 << endl;
            cout << "Estrato B3: " << contador_estratos_congressos[i].estrato_B3 << endl;
            cout << "Estrato B4: " << contador_estratos_congressos[i].estrato_B4 << endl;
            cout << "Estrato B5: " << contador_estratos_congressos[i].estrato_B5 << endl;
            cout << "Estrato C: " << contador_estratos_congressos[i].estrato_C << endl;
            cout << "Sem Estrato: " << contador_estratos_congressos[i].sem_estrato << endl;
            cout << endl;
            cout<<"==========================================================================================\n";
        }

}
