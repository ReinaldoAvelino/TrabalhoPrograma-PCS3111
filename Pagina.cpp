#include "Pagina.h"

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
    cout << "Nome: " << getNome() << " - Proprietario: "
         << proprietario->getNome() << endl;
}
