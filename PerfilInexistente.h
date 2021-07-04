#ifndef PERFILINEXISTENTE_H
#define PERFILINEXISTENTE_H

#include <stdexcept>
#include <string>

using namespace std;

class PerfilInexistente: public logic_error {
public:
    PerfilInexistente();
    virtual ~PerfilInexistente();
};

#endif // PERFILINEXISTENTE_H
