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

#include <iostream>
#include <string>
#include <vector>

class Perfil;

class RedeSocial {
public:
    RedeSocial ();
    virtual ~RedeSocial();

    std::vector<Perfil*>* getPerfis();
    Perfil* getPerfil(int id);
    void adicionar(Perfil* perfil);

    void imprimir();
    void imprimirEstatisticas();

private:
    std::vector<Perfil*>* perfis;
};

#endif // REDESOCIAL_H
