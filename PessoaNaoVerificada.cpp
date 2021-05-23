#include "PessoaNaoVerificada.h"
#include <string>

PessoaNaoVerificada::PessoaNaoVerificada(string nome): Perfil(nome) {
    this->nome = nome;
}

PessoaNaoVerificada::~PessoaNaoVerificada() {
    //dtor
}
