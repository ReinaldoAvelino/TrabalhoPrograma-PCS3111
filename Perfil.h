#ifndef PERFIL_H
#define PERFIL_H

#include <string>

#define MAXIMO_POSTAGENS 20
#define MAXIMO_CONTATOS 20

using namespace std;

#include "Postagem.h"

class Postagem;

class Perfil {
public:
    Perfil(string nome);
	virtual ~Perfil();
    virtual bool adicionarContato(Perfil* contato);
	virtual bool adicionarPostagem(Postagem* p);
	virtual void imprimir();
	string getNome();
	virtual int getQuantidadeDeContatos();
	virtual int getQuantidadeDePostagens();
	virtual Perfil** getContatos();
	virtual Postagem** getPostagens();
protected:
	string nome;
	Perfil** contatos;
	int quantidadeDeContatos = 0;
	Postagem** postagens;
	int quantidadeDePostagens = 0;
};

#endif // PERFIL_H
