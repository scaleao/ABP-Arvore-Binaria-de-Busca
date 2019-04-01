#include "arvoreBinariaPesquisa.h"
#include <stdio.h>

// fun��o INICIALIZA
Pont inicializa() {
    return(NULL);
}

//fun��o CRIA NOVO N�
Pont criaNovoNo(TipoChave ch) {
    Pont novoNo = (Pont)malloc(sizeof(NO));
    novoNo->chave = ch;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return(novoNo);
}

// fun��o ADICIONA
Pont adiciona(Pont raiz, Pont no){
    if (raiz == NULL)
        return(no);

    if (no->chave < raiz->chave)
        raiz->esq = adiciona(raiz->esq, no);
    else
        raiz->dir = adiciona(raiz->dir, no);
    // ignoro chave igual
    return(raiz);
}

// Arvore bin�ria de pesquisa - ABP
//fun��o PESQUISA
Pont contem(TipoChave ch, Pont raiz) {
    if (raiz == NULL)
        return(NULL);

    if (raiz->chave == ch)
        return(raiz);

    if (raiz->chave > ch)
        return(contem(ch, raiz->esq));
    else
        return(contem(ch, raiz->dir));
}

//------- FUN��ES DE LEITURA ---------
// Leitura EM ORDEM - esq, raiz, dir - ordenada
void leituraEmOrdem(Pont raiz){
    if ( raiz != NULL){
        leituraEmOrdem(raiz->esq);
        printf("%i ", raiz->chave);
        leituraEmOrdem(raiz->dir);
    }
}

// Leitura PR� ORDEM - raiz, esq, dir
void leituraPreOrdem(Pont raiz){
    if (raiz != NULL) {
        printf("%i ", raiz->chave);
        leituraPreOrdem(raiz->esq);
        leituraPreOrdem(raiz->dir);
    }
}

//Leitura P�S ORDEM - esq, dir, raiz
void leituraPosOrdem(Pont raiz) {
    if (raiz != NULL) {
        leituraPreOrdem(raiz->esq);
        leituraPreOrdem(raiz->dir);
        printf("%i ", raiz->chave);
    }
}

//FUN��O DE CONTAGEM DE N�S
int conta(Pont raiz){
    if (raiz != NULL)
        return (conta(raiz->esq) + 1 + conta(raiz->dir));
    else return 0;
}

//-----FUN��ES PARA REMO��O------
/* Retorna o endere�o do n� a ser removido
   Abastece o ponteiro *pai com o endere�o do pai do n� a ser removido */
Pont buscaNo(Pont raiz, TipoChave ch, Pont *pai) {
    Pont atual = raiz;
    *pai = NULL;
    while (atual) {
        if (atual->chave == ch) //Encontrou o n�??
            return(atual);

        *pai = atual;

        if (ch < atual->chave)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return(NULL);
}

/* Descri��o da fun��o removeNo:
   Quando o n� a ser removido possui 2 sub�rvores, o mesmo ser�
   substitu�do pelo n� mais � direita da sub�rvore da esquerda*/
Pont removeNo(Pont raiz, TipoChave ch) {
    Pont pai, no, p, q;
    //p vai ser o pai do substituto
    //q vai marcar o n� substituto
    no = buscaNo(raiz, ch, &pai);
    if (no == NULL)
        return(raiz); // se o n� n�o foi encontrado, retorna null
    if (!no->esq || !no->dir) { //se foi encontrado, ver quantas sub�rvores ele tem
        if (!no->esq)           //se tiver uma s�, verifica qual �
            q = no->dir;
        else
            q = no->esq;
    }
    else { //se tiver os dois
        p = no;
        q = no->esq;

        while (q->dir) { //enquanto tiver filho � direita
            p = q;
            q = q->dir;
        }
        if (p != no) {   // o pai do n� substituto � o n� a ser removido??
            p->dir = q->esq;
            q->esq = no->esq;
        }
        q->dir = no->dir;
    }
    if (!pai) { //n� a ser removido � a raiz? Se for a ra�z, o pai vai ser nulo
        free(no);
        return(q);
    }
    if (ch < pai->chave)
        pai->esq = q;
    else
        pai->dir = q;
    free(no);
    return(raiz);
}

/* Descri��o da fun��o removeNoDir:
   Quando o n� a ser removido possui 2 sub�rvores, o mesmo ser�
   substitu�do pelo n� mais � esquerda da sub�rvore da direita.

   As linhas onde a dire��o dos ponteiros foi invertida est�o
   marcadas com "**" */
Pont removeNoDir(Pont raiz, TipoChave ch) {
    Pont pai, no, p, q;
    //p vai marcar a sub�rvore da direita
    //q vai marcar o n� substituto
    no = buscaNo(raiz, ch, &pai);

    if (no == NULL)
        return(raiz); // se o n� n�o foi encontrado, retorna null

    if (!no->esq || !no->dir) { //se foi encontrado, ver quantos descendentes ele tem
        if (!no->esq)           //se tiver um s�, verificar qual �
            q = no->dir;
        else
            q = no->esq;
    }
    else { //se tiver os dois
        p = no;
        q = no->dir; //**//

        while (q->esq) { //**enquanto tiver filho � esquerda
            p = q;
            q = q->esq; //**//
        }

        if (p != no) { // o pai do n� substituto � o n� a ser removido??
            p->esq = q->dir; //**//
            q->dir = no->dir; //**//
        }
        q->esq = no->esq; //**//
    }

    if (!pai) { //n� removido � a raiz?
        free(no);
        return(q);
    }

    //se o n� a ser removido n�o for a raiz
    if (ch < pai->chave)
        pai->esq = q;
    else
        pai->dir = q;

    free(no);
    return(raiz);
}
