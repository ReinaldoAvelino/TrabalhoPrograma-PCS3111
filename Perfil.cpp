#include "Perfil.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <list>

using namespace std;

int Perfil::ultimoId = 0;

Perfil::Perfil(string nome) {
    this->nome = nome;
    this->id = ++Perfil::ultimoId;
    contatos = new vector<Perfil*>();
    postagens = new list<Postagem*>();
}

Perfil::Perfil(string nome, int id) { // Persistencia
    this->nome = nome;
    this->id = id;
    contatos = new vector<Perfil*>();
    postagens = new list<Postagem*>();
}

Perfil::~Perfil() {
    cout << "Destrutor de perfil: " << nome
         << " - Quantidade de postagens feitas: "
         << this->postagens->size() << endl;

    delete contatos;

    while (!postagens->empty()) {
        Postagem* p = postagens->front();
        postagens->pop_front(); // Tirando da lista
        delete p;
    }
    delete postagens;
    cout << "Perfil deletado" << endl;
}

string Perfil::getNome() {
    return this->nome;
}

vector<Perfil*>* Perfil::getContatos() {
    return this->contatos;
}

list<Postagem*>* Perfil::getPostagens() {
    return this->postagens;
}

void Perfil::adicionar(Perfil* contato) {
    if (this == contato) throw new invalid_argument("Perfil adicionando ele mesmo");
    for (unsigned int i = 0; i < this->contatos->size(); i++) {
        if(this->contatos->at(i) == contato) {
            throw new invalid_argument("Perfil ja adicionado");
        }
    }
    this->contatos->push_back(contato);
    contato->contatos->push_back(this);
}

void Perfil::adicionar(Postagem* p) {
    postagens->push_back(p);
}

list<Postagem*>* Perfil::getPostagensDosContatos(int data) {
    list<Postagem*>* postagensDosContatos = new list<Postagem*>();
    int dataRecente;
    list<Postagem*>::iterator it;

    for (unsigned int i = 0; i < this->contatos->size(); i++) {
        for (it = contatos->at(i)->postagens->begin(); it != contatos->at(i)->postagens->end(); it++) {
            dataRecente = data;
            while (dataRecente > 0 && dataRecente >= data-3) {
                if ((*it)->getData() == dataRecente) {
                    postagensDosContatos->push_back((*it));
                }
                dataRecente--;
            }
        }
    }
    return postagensDosContatos;
}

list<Postagem*>* Perfil::getPostagensDosContatos() {
    list<Postagem*>* postagensDosContatos = new list<Postagem*>();
    list<Postagem*>::iterator it;
    list<Postagem*>* lista;

    for (unsigned int i = 0; i < this->contatos->size(); i++) {
        it = postagensDosContatos->begin();
        lista = this->contatos->at(i)->getPostagens();
        postagensDosContatos->insert(it, lista->begin(), lista->end());
    }

    return postagensDosContatos;
}

int Perfil::getId() {
    return this->id;
}

int Perfil::getUltimoId() {
    return Perfil::ultimoId;
}

void Perfil::setUltimoId(int ultimoId) {
    Perfil::ultimoId = ultimoId;
}
