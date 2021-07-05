#ifndef PERFILINEXISTENTE_H
#define PERFILINEXISTENTE_H

#include <stdexcept>

class PerfilInexistente: public std::logic_error {
public:
    PerfilInexistente();
    virtual ~PerfilInexistente();
};

#endif // PERFILINEXISTENTE_H
