#ifndef POSTAGEM_H
#define POSTAGEM_H

#include "Perfil.h"

class Perfil;

class Postagem {

private:
    // Atributos
    string texto;
    int data;
    Perfil* autor;

public:
    // Getters
    string getTexto();
    int getData();
    Perfil* getAutor();
    // Setters
    // Construtor
    Postagem(string texto, int data, Perfil* autor);
    // Destrutor
    virtual ~Postagem();
    void imprimir();
};

#endif // POSTAGEM_H
