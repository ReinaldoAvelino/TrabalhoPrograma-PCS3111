#ifndef PESSOAVERIFICADA_H
#define PESSOAVERIFICADA_H

#include "Pessoa.h"

class PessoaVerificada: public Pessoa {
    public:
        PessoaVerificada(string nome, string email);
        PessoaVerificada(string nome);
        virtual ~PessoaVerificada();
        string getEmail();
        void imprimir();
    private:
        string email;
};

#endif // PESSOAVERIFICADA_H

