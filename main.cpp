#include "Pagina.h"
#include "Perfil.h"
#include "PerfilInexistente.h"
#include "PersistenciaDaRede.h"
#include "Pessoa.h"
#include "PessoaVerificada.h"
#include "Postagem.h"
#include "RedeSocial.h"
#include "Story.h"

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <list>
#include <vector>

using namespace std;

void listarPerfis(RedeSocial* rede) {
    for (int i = 0; i < rede->getPerfis()->size(); i++) {
        cout << rede->getPerfis()->at(i)->getId() << ") "
             << rede->getPerfis()->at(i)->getNome();
        if (dynamic_cast<PessoaVerificada*>(rede->getPerfis()->at(i)) != NULL) {
            cout << " (Verificada)";
        }
        cout << endl;
    }
}

void interface() {

    string arquivo;
    cout << "Arquivo: ";
    getline(cin, arquivo);

    PersistenciaDaRede* persistencia = new PersistenciaDaRede(arquivo);

    RedeSocial* rede = persistencia->carregar();

    string opcao_string = "";
    int opcao = -1;
    while (opcao_string != "0") {
        cout << "Escolha uma opcao"   << endl
             << "1) Cadastrar Pessoa" << endl
             << "2) Cadastrar Pagina" << endl
             << "3) Logar"            << endl
             << "0) Terminar"         << endl;

        while (true) {
            getline(cin, opcao_string);

            // Convert from string to number safely
            stringstream myStream(opcao_string);
            if (myStream >> opcao) break;
            cout << "Numero invalido. Tente novamente." << endl;
        }

        switch (opcao) {
            case 1:
            {
                string nome;
                string verificada = "";
                cout << "Informe os dados da pessoa" << endl;
                cout << "Nome: ";
                getline(cin, nome);

                while (verificada != "s" && verificada != "n") {
                    cout << "Verificada (s/n)? ";
                    getline(cin, verificada);

                    if(verificada == "s") {

                        string email;
                        cout << "Email: ";
                        getline(cin, email);

                        rede->adicionar(new PessoaVerificada(nome, email));

                    }

                    else if(verificada == "n") {
                        rede->adicionar(new Pessoa(nome));
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
                getline(cin, nome);
                cout << "Proprietario:" << endl;
                listarPerfis(rede);

                string id_string = "";
                int id = -1;

                while (true) {
                    cout << "Digite o id ou 0 para cancelar: ";
                    getline(cin, id_string);

                    // Convert from string to number safely
                    stringstream myStream(id_string);
                    if (myStream >> id) break;
                }

                if (id != 0) {
                    if ( PessoaVerificada* pv =
                    dynamic_cast<PessoaVerificada*>(rede->getPerfil(id)) ) {
                        rede->adicionar( new Pagina(nome, pv) );
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
                listarPerfis(rede);

                string id_string = "";
                int id = -1;
                while (true) {
                    cout << "Digite o id ou 0 para cancelar: ";
                    getline(cin, id_string);

                    // Convert from string to number safely
                    stringstream myStream(id_string);
                    if (myStream >> id) break;
                }

                if (id != 0) {
                    cout << rede->getPerfil(id)->getNome();
                    if ( PessoaVerificada* pv =
                    dynamic_cast<PessoaVerificada*>(rede->getPerfil(id)) ) {
                        cout << " - " << pv->getEmail();
                    }
                    cout << endl;
                    if ( Pagina* pag = dynamic_cast<Pagina*>(rede->getPerfil(id)) ) {
                        cout << "Proprietario " << pag->getProprietario()->getNome() << endl;
                    }
                    cout << "Contatos: " << rede->getPerfil(id)->getContatos()->size() << endl;
                    cout << "---" << endl;

                    int acao = -1;
                    string acao_string = "";
                    while (acao != 0) {
                        cout << "Escolha uma opcao:" << endl
                             << "1) Fazer Postagem" << endl
                             << "2) Ver postagens dos contatos" << endl
                             << "3) Adicionar contato" << endl
                             << "0) Deslogar" << endl;
                        while (true) {

                            getline(cin, acao_string);

                            // Convert from string to number safely
                            stringstream myStream(acao_string);
                            if (myStream >> acao) break;
                            cout << "Tente novamente" << endl;
                        }

                        switch (acao) {
                            case 1:
                            {
                                cout << "Story (s/n): ";
                                string resposta;
                                getline(cin, resposta);

                                int data = -1;
                                string data_string = "";
                                while (true) {
                                    cout << "Data: ";
                                    getline(cin, data_string);

                                    // Convert from string to number safely
                                    stringstream myStream(data_string);
                                    if (myStream >> data) break;
                                }

                                int dataDeFim = -1;
                                string dataDeFim_string = "";
                                if (resposta == "s") {
                                    while (true) {
                                        cout << "Data de fim: ";
                                        getline(cin, dataDeFim_string);

                                        // Convert from string to number safely
                                        stringstream myStream(dataDeFim_string);
                                        if (myStream >> dataDeFim) break;
                                    }
                                }

                                string texto;
                                cout << "Texto: ";
                                getline(cin, texto);
                                if (resposta == "s") {
                                    rede->getPerfil(id)->adicionar(
                                    new Story(texto, data, dataDeFim, rede->getPerfil(id)));
                                }
                                else {
                                    rede->getPerfil(id)->adicionar(
                                    new Postagem(texto, data, rede->getPerfil(id)));
                                }
                                cout << endl;
                            }
                            break;

                            case 2:
                            {
                                int data = -1;
                                string data_string = "";
                                while (true) {
                                    cout << "Data: ";
                                    getline(cin, data_string);

                                    // Convert from string to number safely
                                    stringstream myStream(data_string);
                                    if (myStream >> data) break;
                                }

                                cout << "Postagens dos ultimos 3 dias:" << endl;
                                list<Postagem*>* postagensDosContatos = rede->getPerfil(id)->getPostagensDosContatos(data);
                                list<Postagem*>::iterator it;
                                for (it = postagensDosContatos->begin(); it != postagensDosContatos->end(); it++) {
                                    (*it)->imprimir();
                                }
                                cout << endl;
                            }
                            break;

                            case 3:
                            {
                                cout << "Perfil:" << endl;
                                listarPerfis(rede);

                                int idContato = -1;
                                string idContato_string = "";
                                while (true) {
                                    cout << "Digite o id ou 0 para cancelar: ";
                                    getline(cin, idContato_string);

                                    // Convert from string to number safely
                                    stringstream myStream(idContato_string);
                                    if (myStream >> idContato) break;
                                }

                                if (idContato != 0) {
                                    try {
                                        rede->getPerfil(id)->adicionar(rede->getPerfil(idContato));
                                    } catch (logic_error *e) {
                                        cout << "Erro: " << e->what() << endl;
                                        delete e;
                                    }

                                }
                                cout << endl;
                            }
                            break;
                        }
                    }
                }
                cout << endl;
            }
            break;

            case 0:
            {
                string resposta;
                cout << "Deseja salvar? (s/n) ";
                getline(cin, resposta);
                if (resposta == "s") {
                    persistencia->salvar(rede);
                }
                delete persistencia;
                delete rede;
            }
            break;
        }
    }
}

int main() {
    interface();
    return 0;
}
