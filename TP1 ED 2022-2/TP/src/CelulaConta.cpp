#include "../include/CelulaConta.hpp"
#include <stddef.h>

CelulaConta::CelulaConta(){
    Conta a;
    c = a;
    prox = NULL;
}

void CelulaConta::Imprime(){
    c.Imprime();
}

Conta CelulaConta::GetConta(){
    return c;
}