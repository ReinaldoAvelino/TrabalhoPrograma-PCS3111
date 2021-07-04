#include "Pagina.h"

#include <iostream>
#include <string>

Pagina::Pagina(string nome, PessoaVerificada* proprietario):
Perfil(nome), proprietario (proprietario) {
    this->adicionarContato(proprietario);
}

Pagina::~Pagina()
{
    //dtor
}

PessoaVerificada* Pagina::getProprietario()
{
    return this->proprietario;
}

void Pagina::imprimir() { // Redefinicao por substituicao
    cout << "Nome: " << getNome()
         << " - id: " << Perfil::getId()
         << " - Proprietario: " << proprietario->getNome()
         << endl;
}
