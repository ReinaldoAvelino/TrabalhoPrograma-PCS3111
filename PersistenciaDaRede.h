#ifndef PERSISTENCIADAREDE_H
#define PERSISTENCIADAREDE_H

#include "RedeSocial.h"

#include <string>

class RedeSocial;

class PersistenciaDaRede {
public:
    PersistenciaDaRede(string arquivo);
    virtual ~PersistenciaDaRede();

    void salvar(RedeSocial* r);
    RedeSocial* carregar();

protected:
    string arquivo;
};

#endif // PERSISTENCIADAREDE_H
