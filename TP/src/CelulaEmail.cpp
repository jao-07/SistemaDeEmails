#include "../include/CelulaEmail.hpp"
#include <stddef.h>

CelulaEmail::CelulaEmail() {

    Email a;
    e = a;
    prox = NULL;
}

void CelulaEmail::Imprime(){
    e.Imprime();
}