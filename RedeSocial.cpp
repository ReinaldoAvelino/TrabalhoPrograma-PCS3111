#include "RedeSocial.h"
#include "Perfil.h"
#include "PessoaVerificada.h"
#include "PessoaNaoVerificada.h"
#include "Pagina.h"

RedeSocial::RedeSocial()
{
    //ctor
    perfis = new Perfil*[capacidade];
}

RedeSocial::~RedeSocial() {
  cout << "Destrutor de RedeSocial: " << quantidadeDePerfis << " perfis" << endl;
  // COMPLETE
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
    for (int i = 0; i < quantidadeDePerfis; i++){
      perfis[i]->imprimir();
      cout << "==================================" << endl;
    }
  }
  cout << endl;
}

void RedeSocial::imprimirEstatisticas() {
    int numPessoaVerificada = 0;
    int numPessoaNaoVerificada = 0;
    int numPagina = 0;
    int numPerfil = 0;
    for(int i = 0; i < this->quantidadeDePerfis; i++) {
        if(dynamic_cast<PessoaVerificada*>(this->perfis[i]) != NULL) {
            numPessoaVerificada++;
        }
        else if(dynamic_cast<PessoaNaoVerificada*>(this->perfis[i]) != NULL) {
            numPessoaNaoVerificada++;
        }
        else if(dynamic_cast<Pagina*>(this->perfis[i]) != NULL) {
            numPagina++;
        }
        else numPerfil++;
    }
    cout << "PessoaVerificada: " << numPessoaVerificada << endl
         << "PessoaNaoVerificada: " << numPessoaNaoVerificada << endl
         << "Pagina: " << numPagina << endl
         << "Perfil: " << numPerfil << endl;
    cout << endl;
}
