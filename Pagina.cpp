#include "Pagina.h"

#include <iostream>
#include <string>

using namespace std;

Pagina::Pagina(string nome, PessoaVerificada* proprietario):
Perfil(nome) {
    this->proprietario = proprietario;
    this->adicionar(proprietario);
}

Pagina::Pagina(string nome, PessoaVerificada* proprietario, int id):
Perfil(nome, id) {
    this->proprietario = proprietario;
    this->adicionar(proprietario);
}

Pagina::~Pagina() {
}

PessoaVerificada* Pagina::getProprietario() {
    return this->proprietario;
}

void Pagina::imprimir() { // Redefinicao por substituicao
    cout << "Nome: " << getNome()
         << " - id: " << Perfil::getId()
         << " - Proprietario: " << proprietario->getNome()
         << endl;
}
