#pragma once

#include "Email.hpp"

class CelulaEmail {

    public:
        CelulaEmail();
        void Imprime();
    private:
        Email e;
        CelulaEmail *prox;

    friend class CaixaDeEmail;
};