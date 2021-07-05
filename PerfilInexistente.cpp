#include "PerfilInexistente.h"

#include <string>
#include <stdexcept>

using namespace std;

PerfilInexistente::PerfilInexistente():
logic_error("Perfil Inexistente") {
    // ctor
}

PerfilInexistente::~PerfilInexistente() {
    // dtor
}
