#include "Perfil.h"
#include "PessoaNaoVerificada.h"
#include "PessoaVerificada.h"
#include "Pagina.h"
#include "Postagem.h"
#include "RedeSocial.h"

#include <iostream>

using namespace std;

int main() {

    RedeSocial* PoliBook = new RedeSocial();

    int opcao;
    cout << "Escolha uma opcao"   << endl
         << "1) Cadastrar Pessoa" << endl
         << "2) Cadastrar Pagina" << endl
         << "3) Logar"            << endl
         << "0) Terminar"         << endl;
    cin >> opcao;

    switch (opcao) {
        case 1:
            string nome = "nada", verificada = "nada";
            cout << "Informe os dados da pessoa" << endl;
            cout << "Nome: ";
            cin << nome;
            cout << endl;

            while (verificada != "s" && verificada != "n") {
                cout << "Verificada (s/n)? ";
                cin << verificada;
                cout << endl;

                if(verificada == "s") {

                    string email;
                    cout << "Email: ";
                    cin << email;
                    cout << endl;

                    PoliBook->adicionar(new PessoaVerificada(nome, email));

                }

                else if(verificada == "n") {
                    PoliBook->adicionar(new PessoaNaoVerificada(nome));
                }
            }
        break;

        case 2:
            string nome;
            cout << "Informe os dados da pagina" << endl;
            cout << "Nome: ";
            cin >> nome;
            cout << endl;
            cout << "Proprietario:" << endl;
            for(int i = 0; i < )
        break;

        case 3:
            cout << "Escolha um perfil:"   << endl
                 << "1) Ana (Verificada)"  << endl
                 << "2) Jose"              << endl
                 << "3) PCS3111"           << endl
                 << "4) Maria (Verificada" << endl
                 << "Digite o numero ou 0 para cancelar: "
        break;

        case 0:
            delete PoliBook;
        break;
    }

    return 0;
}
