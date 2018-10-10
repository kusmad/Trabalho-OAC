#include<iostream>
#include<list>

using namespace std;

void menu(){
    cout << "1- Incluir novo registro\n";
    cout << "2- Alterar registro existente\n";
    cout << "3- Excluir registro\n";
    cout << "4- Listar todos os registros\n";
    cout << "5- Listar os dados por grupo\n";
    cout << "0- Sair\n";

}

struct dados{
    int id=0;
    string produto;
    char genero;
    char tamanho;
    bool status;

};

void incluir(list<dados> &lista){
    // Deixar incluir maiúsculo e minúsculo (mostrar sempre maiúsculo) Tamanho e gênero

    dados aux;
    cout << "Digite o nome do produto: ";
    cin >> aux.produto;
    cin.ignore();
    cout << "Digite o genero (Masculino (M) / Feminino (F)): ";
    cin >> aux.genero;
    cin.ignore();
    cout << "Digite o tamanho da peca (PP, P, M, G, GG): ";
    cin >> aux.tamanho;
    cin.ignore();

    aux.status = true;

    aux.id ++;

    cout << "Dados cadastrados com Sucesso!\n";
    cout << endl;

    lista.push_back(aux);
}

void listar_registros_grupo(list<dados> lista){
    cout << "Digite o Grupo desejado (M - F - PP - P - M - G - GG):";
    char categoria;
    cin >> categoria;
}

void excluir_registro(list<dados> &lista){
    cout << "Digite o nome do item a ser excluido: ";
    string nome;
    cin >> nome;

    for(dados it : lista){
        if(it.produto == nome){
            cout << it.produto << endl;
            cout << "Deseja realmente excluir o item? (S / N): ";
            char opcao;
            cin >> opcao;
            if(opcao == 'S') {
                it.status = false;
                cout << "Item excluido!\n";
            }

            else
                cout << "A remoção foi cancelada\n";
        }
    }
}

void listar_registros(list<dados> lista){
    // Fazer uma tabela para mostrar os dados;
    dados mostra;
    for(auto it=lista.begin(); it!=lista.end(); it++){
        if(mostra.status==true){
            cout << mostra.id << " " << mostra.produto << " " << mostra.genero << " " << mostra.tamanho << endl;
        }
        else if(lista.size()==0) cout << "Lista vazia\n";
        // remoção lógica (bolar teste para saber se a lista está toda "excluída")
    }
}
int main(){

    list<dados> lista;

    int op;

    do{
        menu();
        cin >> op;
        switch(op){
            case 1:
                incluir(lista);
                break;
            case 3:
                excluir_registro(lista);
                break;
            case 4:
                listar_registros(lista);
                break;

        }
    }while(op!=0);



    return 0;
}
