#ifndef PESSOA_H
#define PESSOA_H

#include "Perfil.h"

class Pessoa: public Perfil {
public:
    Pessoa(string nome);
    Pessoa(string nome, int id); // Persistencia
    virtual ~Pessoa();
    void imprimir();
};

#endif // PESSOA_H
