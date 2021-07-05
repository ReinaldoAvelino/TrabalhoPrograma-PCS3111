#ifndef POSTAGEM_H
#define POSTAGEM_H

#include "Perfil.h"

#include <string>

class Perfil;

class Postagem {
public:
    Postagem(std::string texto, int data, Perfil* autor);
    virtual ~Postagem();

    std::string getTexto();
    int getData();
    Perfil* getAutor();

    virtual void imprimir();
protected:
    std::string texto;
    int data;
    Perfil* autor;
};

#endif // POSTAGEM_H
