#include "../include/ListaContas.hpp"
#include "../include/Email.hpp"
#include "../include/CelulaEmail.hpp"
#include "../include/CaixaDeEmail.hpp"
#include <fstream>

int main(int argc, char *argv[]){

    ListaContas *Lista = new ListaContas();
    std::string linha, palavra, c = "";
    int cont, id, prior = 0;
    long unsigned int i;
    std::ifstream arquivo;
    arquivo.open(argv[1]);

    if(arquivo.is_open()){

        while(getline(arquivo, linha)){
            for(i = 0; linha[i] != ' '; i++){
                palavra = palavra + linha[i];
                cont++;
            }

            if(palavra == "CADASTRA"){
                palavra = "";
                for(i = cont; i < linha.length(); i++){
                    if(linha[i] != ' ')
                        palavra = palavra + linha[i];
                }
                
                id = std::stoi(palavra);
                Lista->InsereID(id);
                palavra = "";
                cont = 0;
            }
            else if(palavra == "REMOVE"){
                palavra = "";
                for(i = cont; i < linha.length(); i++){
                    if(linha[i] != ' ')
                        palavra = palavra + linha[i];
                }
                id = std::stoi(palavra);
                Lista->RemoveID(id);
                palavra = "";
                cont = 0;
            }
            else if(palavra == "CONSULTA"){
                palavra = "";
                for(i = cont; i < linha.length(); i++){
                    if(linha[i] != ' ')
                        palavra = palavra + linha[i];
                }
                id = std::stoi(palavra);
                Lista->LeEmailID(id);
                palavra = "";
                cont = 0;
            }
            else if(palavra == "ENTREGA"){
                palavra = "";
                for(i = cont+1; linha[i] != ' '; i++){
                    palavra = palavra + linha[i];
                    cont++;
                }
                id = std::stoi(palavra);
                palavra = "";
                cont++;

                for(i = cont+1; linha[i] != ' '; i++){
                    palavra = palavra + linha[i];
                    cont++;
                }
                prior = std::stoi(palavra);
                palavra = "";
                cont++;

                for(i = cont+1; i < linha.length(); i++){
                    palavra = palavra + linha[i];
                    if(linha[i+1] == 'F' && linha[i+2] == 'I' && linha[i+3] == 'M')
                        break;
                }
                Lista->RecebeEmailID(id, palavra, prior);
                palavra = "";
                cont = 0;
            }
        }
    }
    else
        std::cout << "ERRO NA ABERTURA DO ARQUIVO!" << std::endl;
}