#pragma once

#include <iostream>
#include <string>

class Email {

    public:
        Email();
        Email(std::string c, int p);
        void Imprime();
        int GetPrioridade();

    private:
        std::string conteudo = " ";
        int prioridade = 0;
};