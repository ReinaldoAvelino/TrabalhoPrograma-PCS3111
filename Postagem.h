#ifndef POSTAGEM_H
#define POSTAGEM_H

#include "Perfil.h"

#include <string>

using namespace std;

class Perfil;

class Postagem {
public:
    Postagem(string texto, int data, Perfil* autor);
    virtual ~Postagem();
    
    string getTexto();
    int getData();
    Perfil* getAutor();
    
    virtual void imprimir();
protected:
    string texto;
    int data;
    Perfil* autor;
};

#endif // POSTAGEM_H
