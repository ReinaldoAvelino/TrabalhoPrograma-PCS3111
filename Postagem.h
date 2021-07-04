#ifndef POSTAGEM_H
#define POSTAGEM_H

#include "Perfil.h"
#include <string>
using namespace std;

class Perfil;

class Postagem {
protected:
    string texto;
    int data;
    Perfil* autor;
public:
    string getTexto();
    int getData();
    Perfil* getAutor();
    Postagem(string texto, int data, Perfil* autor);
    virtual ~Postagem();
    virtual void imprimir();
};

#endif // POSTAGEM_H
