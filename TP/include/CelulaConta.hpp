#pragma once

#include "Conta.hpp"

class CelulaConta {

    public:
        CelulaConta();
        void Imprime();
        Conta GetConta();
        
    private:
        Conta c;
        CelulaConta *prox;

    friend class ListaContas;
};