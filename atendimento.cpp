#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> senhasGeradas;
    queue<int> senhasAtendidas;
    int opcao = -1;
    int senhaAtual = 1;

    while (opcao != 0 || !senhasGeradas.empty()) {
        cout << "\nSelecione uma opção:\n";
        cout << "0. Sair\n";
        cout << "1. Gerar senha\n";
        cout << "2. Realizar atendimento\n";

        cout << "Senhas aguardando atendimento: " << senhasGeradas.size() << endl;

        cin >> opcao;

        switch (opcao) {
            case 0:
                if (senhasGeradas.empty()) {
                    cout << "Não há mais senhas para atender. Encerrando o programa.\n";
                } else {
                    cout << "Ainda há senhas aguardando atendimento. Não é possível encerrar.\n";
                }
                break;
            case 1:
                senhasGeradas.push(senhaAtual);
                cout << "Senha gerada: " << senhaAtual << endl;
                senhaAtual++;
                break;
            case 2:
                if (!senhasGeradas.empty()) {
                    int senha = senhasGeradas.front();
                    senhasGeradas.pop();
                    senhasAtendidas.push(senha);
                    cout << "Senha atendida: " << senha << endl;
                } else {
                    cout << "Não há mais senhas para atender.\n";
                }
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
                break;
        }
    }

    cout << "\nTotal de senhas atendidas: " << senhasAtendidas.size() << endl;

    return 0;
}