#include "Postagem.h"

#include <iostream>
#include <string>

Postagem::Postagem(string texto, int data, Perfil* autor)
{
    //ctor
    this->texto = texto;
    this->data = data;
    this->autor = autor;
}

Postagem::~Postagem()
{
    //dtor
    cout << "Destrutor de postagem: " << texto << endl;
}

string Postagem::getTexto() {
    return this->texto;
}

int Postagem::getData() {
    return this->data;
}

Perfil* Postagem::getAutor() {
    return this->autor;
}

void Postagem::imprimir() {
    cout << "Texto: " << this->texto            << " - "
         << "Data: "  << this->data             << " - "
         << "Autor: " << this->autor->getNome() << endl;
}
