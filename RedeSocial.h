#ifndef REDESOCIAL_H
#define REDESOCIAL_H

#include "Perfil.h"
#include "Pagina.h"
#include "PessoaVerificada.h"
#include "Postagem.h"
#include "Story.h"
#include "Pessoa.h"
#include "PerfilInexistente.h"
#include "PersistenciaDaRede.h"

class Perfil;

class RedeSocial {
public:
    RedeSocial ();
    virtual ~RedeSocial();
    virtual Perfil** getPerfis();
    virtual int getQuantidadeDePerfis();
    virtual bool adicionar(Perfil* perfil);
    virtual void imprimir();
    virtual void imprimirEstatisticas();
    Perfil* getPerfil(int id);

private:
    Perfil** perfis;
    const int capacidade = 100;
    int quantidadeDePerfis = 0;
};

#endif // REDESOCIAL_H
