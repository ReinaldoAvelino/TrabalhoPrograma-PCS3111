#ifndef PESSOAVERIFICADA_H
#define PESSOAVERIFICADA_H

#include "Perfil.h"

class PessoaVerificada: public Perfil {
    public:
        PessoaVerificada(string nome, string email);
        PessoaVerificada(string nome);
        virtual ~PessoaVerificada();
        string getEmail();
        void imprimir();

    protected:

    private:
        string email;
};

#endif // PESSOAVERIFICADA_H

