#pragma once

#include <iostream>
#include "CaixaDeEmail.hpp"

class Conta {

    public:
        Conta();
        Conta(int ID);
        int GetID();
        CaixaDeEmail* GetCaixa();
        void Imprime();

    private:
        int ID;
        CaixaDeEmail *caixa;

};