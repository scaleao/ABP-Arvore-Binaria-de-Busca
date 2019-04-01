#ifndef ARVOREBINARIAPESQUISA_H_INCLUDED
#define ARVOREBINARIAPESQUISA_H_INCLUDED
#define true 1
#define false 0

typedef int bool;
typedef int TipoChave;

typedef struct aux {
    TipoChave chave;
    //dados aqui
    struct aux *esq, *dir;
} NO;

typedef NO* Pont; // cria o tipo de dado Pont, que possui a estrutura NO


#endif // ARVOREBINARIAPESQUISA_H_INCLUDED
