#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinariaPesquisa.h"

int main(){
    Pont r = inicializa();
    Pont no = criaNovoNo(17);

    r = adiciona(r, no);

    no = criaNovoNo(12);
    r = adiciona(r, no);

    no = criaNovoNo(15);
    r = adiciona(r, no);

    no = criaNovoNo(25);
    r = adiciona(r, no);

    no = criaNovoNo(8);
    r = adiciona(r, no);

    no = criaNovoNo(20);
    r = adiciona(r, no);

    no = criaNovoNo(30);
    r = adiciona(r, no);

    //Pont p = contem(12,r);
    //printf("%d", p->chave);

    //printf("%d", conta(r));
    //r = removeNo(r, 17);

    r = removeNoDir(r, 17);

    leituraPreOrdem(r);
    return 0;
}
