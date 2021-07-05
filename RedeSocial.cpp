#include "RedeSocial.h"

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

RedeSocial::RedeSocial() {
    perfis = new vector<Perfil*>();
}

RedeSocial::~RedeSocial() {
  cout << "Destrutor de RedeSocial: " << perfis->size() << " perfis" << endl;
  for (int i = 0; i < perfis->size(); i++) {
    delete perfis->at(i);
  }
  delete perfis;
  cout << "RedeSocial deletada " << endl;
}

vector<Perfil*>* RedeSocial::getPerfis() {
    return this->perfis;
}

void RedeSocial::adicionar(Perfil* perfil) {
    vector<Perfil*>::iterator it;
    it = find(perfis->begin(), perfis->end(), perfil);
    if (it != perfis->end())
        throw new invalid_argument("Perfil ja existe.");
    else
        perfis->push_back(perfil);
}

void RedeSocial::imprimir() {
  cout << "==================================" << endl;
  cout << "Rede Social: " << perfis->size() << " perfis" << endl;
  cout << "==================================" << endl;
  if (perfis->size() == 0){
        cout << "Sem perfis" << endl;
        cout << "==================================" << endl;
  } else {
      for (int i = 0; i < perfis->size(); i++) {
          perfis->at(i)->imprimir();
          cout << "==================================" << endl;
      }
  }
  cout << endl;
}

void RedeSocial::imprimirEstatisticas() {
    int numPessoaVerificada = 0;
    int numPessoa = 0;
    int numPagina = 0;
    int numPerfil = 0;
    for(int i = 0; i < perfis->size(); i++) {
        if(dynamic_cast<PessoaVerificada*>(perfis->at(i)) != NULL) {
            numPessoaVerificada++;
        }
        else if(dynamic_cast<Pessoa*>(perfis->at(i)) != NULL) {
            numPessoa++;
        }
        else if(dynamic_cast<Pagina*>(perfis->at(i)) != NULL) {
            numPagina++;
        }
        else numPerfil++;
    }
    cout << "PessoaVerificada: " << numPessoaVerificada << endl
         << "Pessoa: " << numPessoa << endl
         << "Pagina: " << numPagina << endl
         << "Perfil: " << numPerfil << endl;
    cout << endl;
}

Perfil* RedeSocial::getPerfil(int id)
{
    for (int i = 0; i < perfis->size(); i++) {
        if (perfis->at(i)->getId() == id) return perfis->at(i);
    }
    throw new PerfilInexistente();
}

