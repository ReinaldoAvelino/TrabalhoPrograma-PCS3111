#include "PersistenciaDaRede.h"

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

PersistenciaDaRede::PersistenciaDaRede(string arquivo) {
    this->arquivo = arquivo;
}

PersistenciaDaRede::~PersistenciaDaRede()
{
    //dtor
}

void PersistenciaDaRede::salvar(RedeSocial* r) {
    ofstream output;
    output.open(this->arquivo);

    if(output.fail()) throw new logic_error("Erro ao salvar");

    // Se existem apenas PessoaVerificada na rede
    output << r->getQuantidadeDePerfis() << endl;

    for (int i = 0; i < r->getQuantidadeDePerfis(); i++) {
        PessoaVerificada* pv =
        dynamic_cast<PessoaVerificada*>(r->getPerfis()[i]);
        output << pv->getId() << " "
               << pv->getNome() << " "
               << pv->getEmail() << endl;
    }

    output << endl;
    output.close();
}

RedeSocial* PersistenciaDaRede::carregar()
{
    RedeSocial* rede = new RedeSocial();
    ifstream entrada; // input
    entrada.open(this->arquivo);

    if (entrada.fail()) {
        entrada.close();
        throw new logic_error("Arquivo nao encontrado");
    }

    int quantidadeDePerfis, id;
    string nome, email;
    int quantidade = 0;

    entrada >> quantidadeDePerfis;
    entrada >> id >> nome >> email;
    while (entrada) { // Enquanto nao for nem fail nem bad
        rede->adicionar(new PessoaVerificada(nome, email));
        quantidade++;
        entrada >> id;
        entrada >> nome;
        entrada >> email;
    }

    if (!entrada.eof()) { // Se nao chegou no fim do arquivo
        entrada.close();
        delete rede;
        throw new logic_error("Erro de leitura");
    }

    if (quantidade == 0) {
        entrada.close();
        delete rede;
        throw new logic_error("Arquivo vazio");
    }

    if (quantidade != quantidadeDePerfis) {
        entrada.close();
        delete rede;
        throw new logic_error("Quantidade de Perfis difere do informado.");
    }

    entrada.close();
    return rede;
}
