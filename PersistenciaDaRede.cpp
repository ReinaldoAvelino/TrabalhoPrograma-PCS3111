#include "PersistenciaDaRede.h"

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

PersistenciaDaRede::PersistenciaDaRede(string arquivo) {
    this->arquivo = arquivo;
}

PersistenciaDaRede::~PersistenciaDaRede()
{
    //dtor
}

void PersistenciaDaRede::salvar(RedeSocial* r) {
    ofstream output;
    output.open(this->arquivo);

    if(output.fail()) throw new logic_error("Erro ao salvar");

    output << Perfil::getUltimoId() << endl;

    int quantidadePessoas = 0;
    int quantidadePessoasVerificadas = 0;
    int quantidadePaginas = 0;
    vector<Perfil*>::iterator it;

    for (it = r->getPerfis()->begin(); it != r->getPerfis()->end(); it++) {
        if (dynamic_cast<PessoaVerificada*>(*it) != NULL)
            quantidadePessoasVerificadas++;
        else if (dynamic_cast<Pagina*>(*it) != NULL)
            quantidadePaginas++;
        else quantidadePessoas++;
    }

    // Pessoas
    output << quantidadePessoas << endl;
    for (it = r->getPerfis()->begin(); it != r->getPerfis()->end(); it++) {
        if (dynamic_cast<PessoaVerificada*>(*it) == NULL &&
        dynamic_cast<Pagina*>(*it) == NULL) {
            Pessoa* pessoa = dynamic_cast<Pessoa*>(*it);
            output << pessoa->getId() << " "
                   << pessoa->getNome() << endl;
        }
    }

    // PessoasVerificadas
    output << quantidadePessoasVerificadas << endl;
    for (it = r->getPerfis()->begin(); it != r->getPerfis()->end(); it++) {
        if (PessoaVerificada* pv = dynamic_cast<PessoaVerificada*>(*it)) {
            output << pv->getId() << " "
                   << pv->getNome() << " "
                   << pv->getEmail() << endl;
        }
    }

    // Paginas
    output << quantidadePaginas << endl;
    for (it = r->getPerfis()->begin(); it != r->getPerfis()->end(); it++) {
        if (Pagina* pag = dynamic_cast<Pagina*>(*it)) {
            output << pag->getId() << " "
                   << pag->getNome() << " "
                   << pag->getProprietario()->getId() << endl;
        }
    }

    // Contatos dos perfis
    vector<Perfil*>::iterator i, j;
    for (i = r->getPerfis()->begin(); i != r->getPerfis()->end(); i++) {
        for (j = (*i)->getContatos()->begin(); j != (*i)->getContatos()->end(); j++) {
            output << (*i)->getId() << " " << (*j)->getId() << endl;
        }
    }

    output << endl;
    output.close();
}

RedeSocial* PersistenciaDaRede::carregar()
{
    RedeSocial* rede = new RedeSocial();
    ifstream entrada; // input
    entrada.open(this->arquivo);

    if (entrada.fail()) { // Arquivo nao encontrado
        entrada.close();
        return rede; // Rede vazia
    }

    int ultimoId, id, idProprietario, idContato;
    string nome, email;

    entrada >> ultimoId;
    Perfil::setUltimoId(ultimoId);

    // Pessoas
    int quantidadePessoas;
    entrada >> quantidadePessoas;
    for (int i = 0; i < quantidadePessoas; i++) {
        entrada >> id >> nome;
        if (entrada) {
            rede->adicionar(new Pessoa(nome, id));
        }
        else {
            entrada.close();
            delete rede;
            throw logic_error("Erro de leitura");
        }
    }

    // PessoasVerificadas
    int quantidadePessoasVerificadas;
    entrada >> quantidadePessoasVerificadas;
    for (int i = 0; i < quantidadePessoasVerificadas; i++) {
        entrada >> id >> nome >> email;
        if (entrada) {
            rede->adicionar(new PessoaVerificada(nome, email, id));
        }
        else {
            entrada.close();
            delete rede;
            throw logic_error("Erro de leitura");
        }
    }

    // Paginas
    int quantidadePaginas;
    entrada >> quantidadePaginas;
    for (int i = 0; i < quantidadePaginas; i++) {
        entrada >> id >> nome >> idProprietario;
        if (entrada) { // if (!entrada.bad() && !entrada.fail())
            PessoaVerificada* proprietario =
            dynamic_cast<PessoaVerificada*>(rede->getPerfil(idProprietario));
            rede->adicionar(new Pagina(nome, proprietario, id));
        }
        else {
            entrada.close();
            delete rede;
            throw logic_error("Erro de leitura");
        }
    }

    // Contatos dos Perfis
    entrada >> id >> idContato;
    while (entrada) { // While not fail and not bad
        try {
            rede->getPerfil(id)->adicionar(rede->getPerfil(idContato));
        } catch (invalid_argument *e) {
            delete e; // Ignora repeticoes no adicionar
        }
        entrada >> id >> idContato;
    }

    if (!entrada.eof()) { // Se nao chegou no fim do arquivo
        entrada.close();
        delete rede;
        throw new logic_error("Erro de leitura");
    }

    entrada.close();
    return rede;
}
