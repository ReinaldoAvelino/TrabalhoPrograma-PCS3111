#include "Perfil.h"
#include "PessoaNaoVerificada.h"
#include "PessoaVerificada.h"
#include "Pagina.h"
#include "Postagem.h"
#include "RedeSocial.h"

#include <iostream>

using namespace std;

bool EhVerificado(Perfil* p) {
    if( dynamic_cast<PessoaVerificada*>(p) != NULL ) return true;
    return false;
}

void listarPerfis(RedeSocial* R) {
    for(int i = 0; i < R->getQuantidadeDePerfis(); i++) {
        cout << i+1 << ") " << R->getPerfis()[i]->getNome();
        if ( EhVerificado( R->getPerfis()[i] ) ) {
            cout << " (Verificada)";
        }
        cout << endl;
    }
}

int main() {

    RedeSocial* PoliBook = new RedeSocial();

    
    int opcao = -1;
    while (opcao != 0) {
        cout << "Escolha uma opcao"   << endl
             << "1) Cadastrar Pessoa" << endl
             << "2) Cadastrar Pagina" << endl
             << "3) Logar"            << endl
             << "0) Terminar"         << endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
            {
                string nome = "nada", verificada = "nada";
                cout << "Informe os dados da pessoa" << endl;
                cout << "Nome: ";
                cin >> nome;

                while (verificada != "s" && verificada != "n") {
                    cout << "Verificada (s/n)? ";
                    cin >> verificada;

                    if(verificada == "s") {

                        string email;
                        cout << "Email: ";
                        cin >> email;

                        PoliBook->adicionar(new PessoaVerificada(nome, email));

                    }

                    else if(verificada == "n") {
                        PoliBook->adicionar(new PessoaNaoVerificada(nome));
                    }
                }
                cout << endl;
            }    
            break;

            case 2:
            {
                string nome;
                cout << "Informe os dados da pagina" << endl;
                cout << "Nome: ";
                cin >> nome;
                cout << "Proprietario:" << endl;
                listarPerfis(PoliBook);
                int numero;
                cout << "Digite o numero ou 0 para cancelar: ";
                cin >> numero;
                if (numero != 0) {
                    if ( EhVerificado( PoliBook->getPerfis()[numero-1] ) ) {

                        PoliBook->adicionar( new Pagina(nome, dynamic_cast<PessoaVerificada*>(PoliBook->getPerfis()[numero-1]) ) );
                    }
                    else {
                        cout << "Somente pessoas verificadas podem ser proprietarias" << endl;
                    }
                }
                cout << endl;
            }
            break;

            case 3:
            {
                cout << "Escolha um perfil:" << endl;
                listarPerfis(PoliBook);
                int numero;
                cout << "Digite o numero ou 0 para cancelar: ";
                cin >> numero;
                if (numero != 0) {
                    cout << PoliBook->getPerfis()[numero-1]->getNome << endl;
                }
            }
            break;

            case 0:
                delete PoliBook;
            break;
        }
    }
    return 0;
}
