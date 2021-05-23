#ifndef PAGINA_H
#define PAGINA_H

#include "Perfil.h"
#include "PessoaVerificada.h"

class PessoaVerificada;

class Pagina: public Perfil {
    public:
        Pagina(string nome, PessoaVerificada* proprietario);
        virtual ~Pagina();
        PessoaVerificada* getProprietario();
        void imprimir();

    protected:
        PessoaVerificada* proprietario;
};

#endif // PAGINA_H
