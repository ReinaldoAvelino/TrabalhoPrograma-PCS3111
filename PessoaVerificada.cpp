#include "PessoaVerificada.h"

#include <iostream>
#include <string>

using namespace std;

PessoaVerificada::PessoaVerificada(string nome, string email) : Pessoa(nome) {
    this->email = email;
}

PessoaVerificada::PessoaVerificada(string nome): Pessoa(nome) {
    this->email = "email.padrao@usp.br";
}

PessoaVerificada::PessoaVerificada(string nome, string email, int id): Pessoa(nome, id) {
    this->email = email;
}

PessoaVerificada::~PessoaVerificada() {
}

string PessoaVerificada::getEmail() {
    return this->email;
}

void PessoaVerificada::imprimir() { // Redefinicao por refinamento
    cout << this->email << endl;
    Pessoa::imprimir();
}
