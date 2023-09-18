#include "../include/ListaContas.hpp"

ListaContas::ListaContas(){
    primeiro = new CelulaConta();
    ultimo = primeiro;
    tamanho = 0;
}

bool ListaContas::Verifica(int id){
    CelulaConta* p;
    p = primeiro;
    while(p->prox != NULL){
        if(p->prox->GetConta().GetID() == id)
            return true;
        p = p->prox;
    }
    return false;
}

void ListaContas::InsereID(int id){

    if(!Verifica(id)){
        CelulaConta *nova;
        nova = new CelulaConta();
        Conta acc(id);
        nova->c = acc;
        nova->prox = primeiro->prox;
        primeiro->prox = nova;
        tamanho++;
        std::cout << "OK: CONTA " << id << " CADASTRADA" << std::endl;

        if(nova->prox == NULL)
            ultimo = nova;

        
    }
    else{
        std::cout << "ERRO: CONTA " << id << " JA EXISTENTE" << std::endl;
    }
}

void ListaContas::RemoveID(int id){
    CelulaConta *p, *q;
    p = primeiro;

    if(tamanho > 0 && Verifica(id)){
        while(p->prox != NULL){
            if(p->prox->GetConta().GetID() == id){
                break;
            }
            p = p->prox;
        }
        q = p->prox;
        p->prox = q->prox;
        tamanho--;
        delete q;
        if(p->prox == NULL)
            ultimo = p;

        std::cout << "OK: CONTA " << id << " REMOVIDA" << std::endl;
    }
    else{
        std::cout << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
    }
}

void ListaContas::Limpa(){
    CelulaConta *p;
    p = primeiro->prox;
    while (p!=NULL) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
}

ListaContas::~ListaContas(){
    Limpa();
    delete primeiro;
}

void ListaContas::RecebeEmailID(int id, std::string conteudo, int prioridade){
    CelulaConta *p;
    p = primeiro->prox;

    if(Verifica(id)){
        while(p != NULL){
            if(p->GetConta().GetID() == id)
                break;
            p = p->prox;
        }
        Email e(conteudo, prioridade);
        p->c.GetCaixa()->RecebeEmail(e);

        std::cout << "OK: MENSAGEM PARA " << id << " ENTREGUE" << std::endl;
    }
    else{
        std::cout << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
    }
}

void ListaContas::LeEmailID(int id){
    CelulaConta *p;
    p = primeiro->prox;

    if(Verifica(id)){
        while(p != NULL){
            if(p->GetConta().GetID() == id)
                break;
            p = p->prox;
        }
        if(p->c.GetCaixa()->GetTamanho() > 0){
            std::cout << "CONSULTA " << id << ": ";
            p->c.GetCaixa()->LeEmail();
        }
        else{
            std::cout << "CONSULTA " << id << ": CAIXA DE ENTRADA VAZIA" << std::endl;
        }
    }
    else
        std::cout << "ERRO: CONTA " << id << " NAO EXISTE" << std::endl;
}

int ListaContas::GetTamanho(){
    return tamanho;
}



