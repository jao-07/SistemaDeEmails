#include "../include/CaixaDeEmail.hpp"

CaixaDeEmail::CaixaDeEmail() {
    primeiro = new CelulaEmail();
    ultimo = primeiro;
    tamanho = 0;
}



void CaixaDeEmail::RecebeEmail(Email email){
    CelulaEmail *nova;
    CelulaEmail *p;
    nova = new CelulaEmail();
    nova->e = email;

    if(tamanho == 0){
        
        primeiro->prox = nova;
        ultimo = nova;
        tamanho++;
    }
    else{
        p = primeiro;
        while(p->prox != NULL){
            if(p->prox->e.GetPrioridade() <= email.GetPrioridade()){
                p = p->prox;
            } 
            else {
                break;
            }
            
        }
        if(p == ultimo)
            ultimo = nova;

        nova->prox = p->prox;
        p->prox = nova;
        tamanho++;
    }

    if(p == ultimo)
        ultimo = nova;
}

void CaixaDeEmail::LeEmail(){
    if (tamanho > 0){
        int n = ultimo->e.GetPrioridade();
        CelulaEmail *p = primeiro;
        CelulaEmail *aux;
    
        while(p->prox != NULL){
            if(p->prox->e.GetPrioridade() < n){
                p = p->prox;
            }
            else{
                break;
            }
        }
        p->prox->Imprime();

        if(p->prox == ultimo){
            p->prox = NULL;
            tamanho--;
            delete ultimo;
            ultimo = p;
        }
        else {
            aux = p->prox;
            p->prox = p->prox->prox;
            delete aux;
            tamanho--;
        }
    }
}

void CaixaDeEmail::Limpa(){
    CelulaEmail *p;

    p = primeiro->prox;
    while (p!=NULL) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
}

CaixaDeEmail::~CaixaDeEmail() {
    Limpa();
    delete primeiro;
}

int CaixaDeEmail::GetTamanho(){
    return tamanho;
}

CelulaEmail* CaixaDeEmail::GetUltimo(){
    return ultimo;
}