#ifndef PESSOA_H
#define PESSOA_H

#include "Perfil.h"

#include <string>

class Pessoa: public Perfil {
public:
    Pessoa(std::string nome);
    Pessoa(std::string nome, int id); // Persistencia
    virtual ~Pessoa();
    void imprimir();
};

#endif // PESSOA_H
