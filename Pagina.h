#ifndef PAGINA_H
#define PAGINA_H

#include "Perfil.h"
#include "PessoaVerificada.h"

class Pagina: public Perfil {
    public:
        Pagina(string nome, PessoaVerificada* proprietario);
        virtual ~Pagina();
        PessoaVerificada* getProprietario();
        void imprimir();

    private:
        PessoaVerificada* proprietario;
};

#endif // PAGINA_H
