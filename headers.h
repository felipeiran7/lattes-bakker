#ifndef DOCENTES_H_INCLUDED
#define DOCENTES_H_INCLUDED


//=================================== STRUCT DE DOCENTES==========================================================
typedef struct _docentes_{
    char id[30];
    char nome[250];
}docente;
//=================================================================================================================




//============================STRUCT PRODUCOES========================================================================
typedef struct _producoes_{
    char id_autor[60];
    char id_producao[60];
    char tipo[60];
    char issn[60];
    char titulo[450];
    char local[450];
    char ano[8];
}producoes;

//===============================================================================================================



//=================================STRUCT DE ORIENTACOES==========================================================
typedef struct _orientacoes_{
    char id_docente[100];
    char id_orientacao[100];
    char tipo_orientacao[200];
    char titulo[500];
    char nome_orientando[200];
    char ano[60];
}orientacoes;
//===========================================================================================================================





//*========================================STRUCT DE CONGRESSOS DA CAPES=====================================================
typedef struct _congressos_capes_{
    char nome_congresso[200];
    char sigla_congresso[40];
    char estrato_qualis[20];
}congressos;
//============================================================================================================================


//=======================================STRUCT PERIODICOS CAPES============================================================

typedef struct _periodicos_capes_{
    char issn[100];
    char nome_periodico[300];
    char area_avaliacao[100];
    char estrato_qualis[20];

}periodicos;

//===============================================================================================================================



//==========================STRUCT QUANTIDADE DE ORIENTACOES DOCENTES===========================================================
typedef struct _contador_orientacoes_{
    int dissertacao_mestrado;
    int iniciacao_cientifica;
    int trabalho_conclusao_curso;
    int tese_doutorado;
    int monografia_aperf_especializacao;

}quantidade_orientacoes;
//==============================================================================================================================

//=====================================STRUCT QUANTIDADE DE PRODUCAO POR DOCENTES================================================
typedef struct _contador_producoes_{
    int trabalho_em_evento;
    int artigo_publicado;
}quantidade_producoes;

//===============================================================================================================================


//=========================================STRUCT PERIODICOS CAPES======================================
typedef struct _contador_periodicos_{
        int estrato_A1;
        int estrato_A2;
        int estrato_B1;
        int estrato_B2;
        int estrato_B3;
        int estrato_B4;
        int estrato_B5;
        int estrato_C;
        int sem_estrato;
}quantidade_estratos_periodicos;
//=======================================================================================================


//=========================================STRUCT CONGRESSOS CAPES======================================
typedef struct _contador_congressos_{
        int estrato_A1=0;
        int estrato_A2=0;
        int estrato_B1=0;
        int estrato_B2=0;
        int estrato_B3=0;
        int estrato_B4=0;
        int estrato_B5=0;
        int estrato_C=0;
        int sem_estrato=0;
}quantidade_estratos_congressos;
//=======================================================================================================


docente *guarda_docentes();//FUNCAO QUE GUARDA E RETORNA DOCENTES

producoes *guarda_producoes();//FUNCAO QUE GUARDA E RETORNA PRODUÇÕES

orientacoes *guarda_orientacoes();//FUNCAO QUE GUARDA E RETORNA ORIENTAÇÕES

congressos *guarda_congressos();// FUNCAO QUE GUARDA E RETORNA CONGRESSOS

periodicos *guarda_periodicos();// FUNCAO QUE GUARDA E RETORNA PERIODICOS

void contaorientacoes(quantidade_orientacoes **contador_orientacoes, docente **docentes, orientacoes **orientacoes);//FUNCAO QUE CONTA QUANTIDADE DE ORIENTACAO POR DOCENTES

void contaproducoes(quantidade_producoes **contador_producoes, docente **docentes, producoes **producoes);

void contadorperiodicos(quantidade_estratos_periodicos **contador_estratos_periodicos, docente **docentes, producoes **producoes, periodicos **periodicos );

void contadorcongressos(quantidade_estratos_congressos **contador_estratos_congressos, docente **docentes, producoes **producoes, congressos **congressos);


#endif // DOCENTES_H_INCLUDED
