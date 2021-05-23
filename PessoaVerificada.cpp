#include "PessoaVerificada.h"

PessoaVerificada::PessoaVerificada(string nome, string email) : Perfil(nome)
{
    this->nome = nome;
    this->email = email;
}

PessoaVerificada::PessoaVerificada(string nome): Perfil(nome) {
    this->nome = nome;
    this->email = "email.padrao@usp.br";
}

PessoaVerificada::~PessoaVerificada()
{
    //dtor
}

string PessoaVerificada::getEmail()
{
    return this->email;
}

void PessoaVerificada::imprimir() { // Redefinicao por refinamento
    cout << this->email << endl;
    Perfil::imprimir();
}
