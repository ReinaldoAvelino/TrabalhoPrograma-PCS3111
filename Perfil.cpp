#include "Perfil.h"

Perfil::Perfil(string nome)
{
    this->nome = nome;
    contatos = new Perfil*[MAXIMO_CONTATOS];
    postagens = new Postagem*[MAXIMO_POSTAGENS];
}


Perfil::~Perfil()
{
    cout << "Destrutor de perfil: " << nome << " - Quantidade de postagens feitas: "
         << quantidadeDePostagens << endl;
    for (int i = 0; i < quantidadeDePostagens; i++) {
        delete postagens[i];
    }
    delete[] postagens;
    delete[] contatos;
    cout << "Perfil deletado" << endl;
}

int Perfil::getQuantidadeDeContatos() {
    return this->quantidadeDeContatos;
}

string Perfil::getNome() {
    return this->nome;
}

int Perfil::getQuantidadeDePostagens() {
    return this->quantidadeDePostagens;
}

Perfil** Perfil::getContatos() {
    return this->contatos;
}

Postagem** Perfil::getPostagens() {
    return this->postagens;
}

bool Perfil::adicionarContato(Perfil* contato) {

    if(this->quantidadeDeContatos == MAXIMO_CONTATOS ||
       contato->quantidadeDeContatos == MAXIMO_CONTATOS) {
       return false;
    }
    for (int i = 0; i < this->quantidadeDeContatos; i++) {
        if(this->contatos[i] == contato) {
            return false;
        }
    }
    this->contatos[this->quantidadeDeContatos] = contato;
    this->quantidadeDeContatos++;
    contato->contatos[contato->quantidadeDeContatos] = this;
    contato->quantidadeDeContatos++;
    return true;
}

bool Perfil::adicionarPostagem(Postagem* p) {
    if (this->quantidadeDePostagens == MAXIMO_POSTAGENS) return false;
    else {
        this->postagens[this->quantidadeDePostagens] = p;
        this->quantidadeDePostagens++;
        return true;
    }
    return false;
}

void Perfil::imprimir() {
    cout << endl << "Nome: " << nome << endl;
    cout << "Numero de postagens feitas: " << quantidadeDePostagens << endl;
    for (int i = 0; i < quantidadeDePostagens; i++)
        cout << "Postagens na data " << postagens[i]->getData() << " - Texto: "
             << postagens[i]->getTexto() << endl;

    if (quantidadeDeContatos == 0)
        cout << "Sem contatos " << endl;
    else {
        for (int i = 0; i < quantidadeDeContatos; i++) {
            for (int j = 0; j < contatos[i]->getQuantidadeDePostagens(); j++)
                cout << "Postagens na data "
                     << contatos[i]->getPostagens()[j]->getData()
                     << " do contato " << contatos[i]->getNome()
                     << " - Texto: " << contatos[i]->getPostagens()[j]->getTexto()
                     << endl;
        }
    }
}
