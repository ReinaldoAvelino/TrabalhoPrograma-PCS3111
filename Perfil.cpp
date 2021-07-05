#include "Perfil.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <list>

using namespace std;

int Perfil::ultimoId = 0;

Perfil::Perfil(string nome) {
    this->nome = nome;
    contatos = new vector<Perfil*>();
    postagens = new list<Postagem*>();
    this->id = ++Perfil::ultimoId;
}

Perfil::~Perfil() {
    cout << "Destrutor de perfil: " << nome
         << " - Quantidade de postagens feitas: "
         << quantidadeDePostagens << endl;

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
    for (int i = 0; i < this->quantidadeDeContatos; i++) {
        if(this->contatos[i] == contato) {
            throw new invalid_argument("Perfil ja adicionado");
        }
    }
    this->contatos[this->quantidadeDeContatos++] = contato;
    contato->contatos[contato->quantidadeDeContatos++] = this;
}

void Perfil::adicionar(Postagem* p) {
    postagens->push_back(p);
    quantidadeDePostagens++;
}

list<Postagem*>* Perfil::getPostagensDosContatos(int data) {
    list<Postagem*>* postagensDosContatos = new list<Postagem*>();
    int dataRecente;
    list<Postagem*>::iterator it;

    for (int i = 0; i < this->quantidadeDeContatos; i++) {
        for (it = contatos[i]->postagens->begin(); it != contatos[i]->postagens->end(); it++) {
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
    list<Postagem*>* L;

    for (int i = 0; i < this->quantidadeDeContatos; i++) {
        it = postagensDosContatos->begin();
        L = this->contatos[i]->getPostagens();
        postagensDosContatos->insert(it, L->begin(), L->end());
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
