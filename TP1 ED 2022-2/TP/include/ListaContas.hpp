#pragma once

#include "CaixaDeEmail.hpp"
#include "CelulaConta.hpp"

class ListaContas {

    public:
        ListaContas();
        ~ListaContas();
        void InsereID(int ID);
        void RemoveID(int ID);
        bool Verifica(int ID);
        void Limpa();
        void RecebeEmailID(int ID, std::string cont, int prior);
        void LeEmailID(int ID);
        int GetTamanho();

    private:
        CelulaConta* primeiro;
        CelulaConta* ultimo;
        int tamanho = 0;
};