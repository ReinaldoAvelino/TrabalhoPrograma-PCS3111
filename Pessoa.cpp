#include "Pessoa.h"

#include <string>
#include <iostream>

using namespace std;

Pessoa::Pessoa(string nome) : Perfil(nome) {
}

Pessoa::Pessoa(string nome, int id): Perfil(nome, id) {
}

Pessoa::~Pessoa() {
}

void Pessoa::imprimir() {
    cout << endl << "Nome: " << nome
         << " - id: " << Perfil::getId() << endl;
    cout << "Numero de postagens feitas: "
         << postagens->size() << endl;

    list<Postagem*>::iterator i = postagens->begin();
    while (i != postagens->end()) {
        cout << "Postagens na data " << (*i)->getData()
             << " - Texto: " << (*i)->getTexto() << endl;
        i++;
    }

    if (contatos->size() == 0)
        cout << "Sem contatos " << endl;
    else {
        for (int i = 0; i < contatos->size(); i++) {
            list<Postagem*>::iterator j =
            contatos->at(i)->getPostagens()->begin();
            while (j != contatos->at(i)->getPostagens()->end()) {
                cout << "Postagens na data "
                     << (*j)->getData()
                     << " do contato "
                     << contatos->at(i)->getNome()
                     << " - Texto: " << (*j)->getTexto()
                     << endl;
                j++;
            }
        }
    }
}
