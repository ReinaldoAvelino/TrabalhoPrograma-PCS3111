#ifndef PERFIL_H
#define PERFIL_H

#include "Postagem.h"

#include <string>
#include <list>
#include <vector>

class Postagem;

class Perfil { // Classe abstrata
public:
    Perfil(std::string nome);
    Perfil(std::string nome, int id); // Persistencia
	virtual ~Perfil();

	std::string getNome();

    virtual void adicionar(Perfil* contato);
	virtual void adicionar(Postagem* p);

	virtual std::list<Postagem*>* getPostagens();
    virtual std::list<Postagem*>* getPostagensDosContatos(int data);
    virtual std::list<Postagem*>* getPostagensDosContatos();
    virtual std::vector<Perfil*>* getContatos();

    virtual void imprimir() = 0; // Metodo abstrato

    int getId();
    static int getUltimoId();
    static void setUltimoId(int ultimoId); // Persistencia

protected:
	std::string nome;
	std::vector<Perfil*>* contatos;
	int quantidadeDeContatos = 0;
	std::list<Postagem*>* postagens;
	int quantidadeDePostagens = 0;
	int id = 0;
	static int ultimoId;
};

#endif // PERFIL_H
