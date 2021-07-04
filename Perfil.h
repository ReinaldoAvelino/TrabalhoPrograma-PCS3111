#ifndef PERFIL_H
#define PERFIL_H

#include "Postagem.h"

#include <string>
#include <list>
#include <vector>

using namespace std;

class Postagem;

class Perfil { // Classe abstrata
public:
    Perfil(string nome);
    Perfil(string nome, int id); // Persistencia
	virtual ~Perfil();

	string getNome();

    virtual void adicionar(Perfil* contato);
	virtual void adicionar(Postagem* p);

	virtual list<Postagem*>* getPostagens();
    virtual list<Postagem*>* getPostagensDosContatos(int data);
    virtual list<Postagem*>* getPostagensDosContatos();
    virtual vector<Perfil*>* getContatos();

    virtual void imprimir() = 0; // Metodo abstrato

    int getId();
    static int getUltimoId();
    static void setUltimoId(int ultimoId); // Persistencia

protected:
	string nome;
	vector<Perfil*>* contatos;
	int quantidadeDeContatos = 0;
	list<Postagem*>* postagens;
	int quantidadeDePostagens = 0;
	int id = 0;
	static int ultimoId;
};

#endif // PERFIL_H
