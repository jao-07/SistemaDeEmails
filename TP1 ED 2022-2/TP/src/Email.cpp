#include "../include/Email.hpp"

Email::Email(){
    conteudo = " ";
    prioridade = 0;
}

Email::Email(std::string c, int p){
    conteudo = c;
    prioridade = p;
}

void Email::Imprime(){
    std::cout << conteudo << std::endl;
}

int Email::GetPrioridade(){
    return prioridade;
}