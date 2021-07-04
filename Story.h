#ifndef STORY_H
#define STORY_H

#include "Postagem.h"
#include <string>

class Story: public Postagem {
    public:
        Story(string texto, int data, int dataDeFim, Perfil* autor);
        virtual ~Story();
        int getDataDeFim();
        void imprimir();
    private:
        int dataDeFim;
};

#endif // STORY_H
