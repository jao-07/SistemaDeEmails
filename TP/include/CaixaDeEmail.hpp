#pragma once

#include "CelulaEmail.hpp"

class CaixaDeEmail {

    public:
        CaixaDeEmail();
        void RecebeEmail(Email e);
        void LeEmail();
        void Limpa();
        ~CaixaDeEmail();
        int GetTamanho();
        CelulaEmail* GetUltimo();

    private:
        CelulaEmail* primeiro;
        CelulaEmail* ultimo;
        int tamanho;
};