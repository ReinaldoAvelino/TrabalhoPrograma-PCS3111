#ifndef REDESOCIAL_H
#define REDESOCIAL_H

#include "Perfil.h"

class Perfil;

class RedeSocial {
public:
    RedeSocial ();
    virtual ~RedeSocial();
    Perfil** getPerfis();
    int getQuantidadeDePerfis();
    bool adicionar(Perfil* perfil);
    void imprimir();
    void imprimirEstatisticas();

private:
    Perfil** perfis;
    const int capacidade = 100;
    int quantidadeDePerfis = 0;
};

#endif // REDESOCIAL_H
