#include "Story.h"
#include <iostream>
#include <string>
using namespace std;

Story::Story(string texto, int data, int dataDeFim, Perfil* autor): Postagem(texto, data, autor)
{
    //ctor
    this->dataDeFim = dataDeFim;
}

Story::~Story()
{
    //dtor
}

int Story::getDataDeFim() {
    return this->dataDeFim;
}

void Story::imprimir() {
    cout << "Texto: " << this->texto << " - "
         << "Data: " << this->data << " - "
         << "Data De Fim: " << this->dataDeFim << " - "
         << "Autor: " << this->autor->getNome() << endl;
}
