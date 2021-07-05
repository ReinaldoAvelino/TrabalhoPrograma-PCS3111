#ifndef PERSISTENCIADAREDE_H
#define PERSISTENCIADAREDE_H

#include "RedeSocial.h"

#include <string>

class RedeSocial;

class PersistenciaDaRede {
public:
    PersistenciaDaRede(std::string arquivo);
    virtual ~PersistenciaDaRede();

    void salvar(RedeSocial* r);
    RedeSocial* carregar();

protected:
    std::string arquivo;
};

#endif // PERSISTENCIADAREDE_H
