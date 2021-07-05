#ifndef PESSOAVERIFICADA_H
#define PESSOAVERIFICADA_H

#include "Pessoa.h"

#include <string>

class PessoaVerificada: public Pessoa {
public:
    PessoaVerificada(std::string nome, std::string email);
    PessoaVerificada(std::string nome);
    PessoaVerificada(std::string nome, std::string email, int id); // Persistencia
    virtual ~PessoaVerificada();

    std::string getEmail();
    void imprimir();
private:
    std::string email;
};

#endif // PESSOAVERIFICADA_H

