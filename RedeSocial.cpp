#include "RedeSocial.h"

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

RedeSocial::RedeSocial() {
    perfis = new vector<Perfil*>();
}

RedeSocial::~RedeSocial() {
  cout << "Destrutor de RedeSocial: " << quantidadeDePerfis << " perfis" << endl;
  for (int i = 0; i < quantidadeDePerfis; i++) {
    delete perfis[i];
  }
  delete[] perfis;
  cout << "RedeSocial deletada " << endl;
}

Perfil** RedeSocial::getPerfis() {
    return this->perfis;
}

bool RedeSocial::adicionar(Perfil* perfil) {
    if (this->quantidadeDePerfis < capacidade) {
        this->perfis[this->quantidadeDePerfis] = perfil;
        this->quantidadeDePerfis++;
        return true;
    }
    return false;
}

int RedeSocial::getQuantidadeDePerfis() {
    return this->quantidadeDePerfis;
}

void RedeSocial::imprimir() {
  cout << "==================================" << endl;
  cout << "Rede Social: " << quantidadeDePerfis << " perfis" << endl;
  cout << "==================================" << endl;
  if (quantidadeDePerfis == 0){
        cout << "Sem perfis" << endl;
        cout << "==================================" << endl;
  } else {
      for (int i = 0; i < quantidadeDePerfis; i++) {
          perfis[i]->imprimir();
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
    for(int i = 0; i < this->quantidadeDePerfis; i++) {
        if(dynamic_cast<PessoaVerificada*>(this->perfis[i]) != NULL) {
            numPessoaVerificada++;
        }
        else if(dynamic_cast<Pessoa*>(this->perfis[i]) != NULL) {
            numPessoa++;
        }
        else if(dynamic_cast<Pagina*>(this->perfis[i]) != NULL) {
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
    for (int i = 0; i < this->quantidadeDePerfis; i++) {
        if (this->perfis[i]->getId() == id) return this->perfis[i];
    }
    throw new PerfilInexistente();
}

