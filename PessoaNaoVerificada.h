#ifndef PESSOANAOVERIFICADA_H
#define PESSOANAOVERIFICADA_H

#include "Perfil.h"

class PessoaNaoVerificada: public Perfil {
public:
    PessoaNaoVerificada(string nome);
    virtual ~PessoaNaoVerificada();
};

#endif // PESSOANAOVERIFICADA_H
