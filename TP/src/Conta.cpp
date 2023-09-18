#include "../include/Conta.hpp"

Conta::Conta(){
    ID = 0;
    CaixaDeEmail *c = new CaixaDeEmail();
    caixa = c;
}

Conta::Conta(int id){
    ID = id;
    CaixaDeEmail *c = new CaixaDeEmail();
    caixa = c;
}

int Conta::GetID(){
    return ID;
}

void Conta::Imprime(){
    std::cout << ID << std::endl;
}

CaixaDeEmail* Conta::GetCaixa(){
    return caixa;
}
