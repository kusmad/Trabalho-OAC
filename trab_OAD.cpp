#include<iostream>
#include<list>
#include<fstream>
#include<cctype>
#include <algorithm>

using namespace std;

int menu(){
    int op;
    cout << "1- Incluir novo registro\n";
    cout << "2- Alterar registro existente\n";
    cout << "3- Excluir registro\n";
    cout << "4- Listar todos os registros\n";
    cout << "5- Listar os dados por grupo\n";
    cout << "6- Salvar e Sair\n";

    cin >> op;
    return op;

}


struct dados{
    int id;
    string produto;
    char genero;
    string tamanho;
    bool status=true;

};

string maiusculo(string s){
    for(int i=0;i<s.size();i++)
        s[i]=toupper(s[i]);
    return s;
}

void incluir(list<dados> &lista){
    string tamanhos[]={"PP","P","M","G","GG"};

    // Deixar incluir maiúsculo e minúsculo (mostrar sempre maiúsculo) Tamanho e gênero
    bool existe;
    dados aux;

    cout << "Digite o nome do produto: ";
	cin.ignore();
    getline(cin,aux.produto);
    aux.produto=maiusculo(aux.produto);

    do{
    cout << "Digite o genero (Masculino (M) / Feminino (F)): ";
    cin >> aux.genero;
    aux.genero=toupper(aux.genero);
    }while(!(aux.genero=='M'^aux.genero=='F'));

    do{
    cout << "Digite o tamanho da peca (PP, P, M, G, GG): ";
    cin >> aux.tamanho;
    aux.tamanho=maiusculo(aux.tamanho);
    }while(!any_of(begin(tamanhos), end(tamanhos), [&](string i) { return aux.tamanho == i; }));

    do{
        existe=false;
        cout <<"Digite a ID do produto: ";
        cin>> aux.id;
        for(auto it=lista.begin(); it!=lista.end(); it++){
            if(it->id==aux.id){
                existe=true;
                cout<<"ID ja cadastrado!\n";
                break;
            }
        }
    }while(existe);


    cout << "Dados cadastrados com Sucesso!\n\n";

    lista.push_back(aux);
}

void alterar_registro(list<dados>& lista){
    cin.ignore();
    cout << "Digite o nome do item que deseja alterar: ";
    string nome_item;
    getline(cin, nome_item);


        cout << "O que voce desseja alterar ?\n";
        cout << "1 - Nome do produto\n";
        cout << "2 - Genero\n";
        cout << "3 - Tamanho\n";


        int escolha;
        cin >> escolha;
        if(escolha == 1){
            for(auto it=lista.begin(); it!=lista.end(); it++){
                if(it->produto == nome_item){
                    cout << "Digite o novo nome do produto: ";
                    string novo;
                    getline(cin, novo);
                    cin.ignore();
                    it->produto = novo;
                    cout << "Alteracao realizada\n";
                    cout << endl;
                    cin.ignore();

                }
            }
        }
        else if(escolha == 2){
            for(auto it=lista.begin(); it!=lista.end(); it++){
                if(it->produto == nome_item){
                    cin >> it->genero;
                    cout << "Alteracao realizada\n";
                }
            }
        }
        else if(escolha == 3){
            for(auto it=lista.begin(); it!=lista.end(); it++){
                if(it->produto == nome_item){
                    cin >> it->genero;
                    cout << "Alteracao realizada\n";
                }
            }
        }
    }


void listar_registros_grupo(list<dados> lista){
    cout << "Digite o Grupo desejado (M - F - PP - P - M - G - GG):";
    string categoria;
    cin >> categoria;
}

void excluir_registro(list<dados> &lista){
    cin.ignore();
    cout << "Digite o nome do item a ser excluido: ";
    string nome;
    getline(cin, nome);

    for(auto it=lista.begin(); it!=lista.end(); it++){
        if(it->produto == nome){
            cout << it->produto << endl;
            cout << "Deseja realmente excluir o item desejado? (S / N): ";
            char opcao;
            cin >> opcao;
            if(opcao == 'S'){
                it->status = false;
                cout << "Item excluido.\n";
                cout << endl;
            }
            else{
                cout << "Exclusao cancelada!\n";
                cout << endl;
            }
        }
    }
}

void listar_registros(list<dados> lista){
    // Fazer uma tabela para mostrar os dados;
    dados mostra;
    if(lista.empty()){
		cout<<"Lista está vazia";
		return;
	}
	for(auto it=lista.begin(); it!=lista.end(); it++){
        if(it->status==true){
			cout<<"===========================================================\n"
            	<<"Id:\t\t"		<< it->id 		<<"\n"
				<< "Produto:\t" << it->produto 	<< "\n"
				<< "Genero:\t\t"	<< it->genero  	<< "\n"
				<< "Tamanho:\t" << it->tamanho 	<< "\n";
        }
		cout<<"===========================================================\n";

    }
}

bool salvar_sair(list<dados> lista){

    ofstream arquivo;

    arquivo.open("Produtos.txt");

    if(!arquivo){
        cout << "              " << "Erro ao abrir o arquivo!\n";
        return 0;
    }
    for(auto it=lista.begin(); it!=lista.end(); it++){
        arquivo << it->id << endl;
        arquivo << it->produto << endl;
        arquivo << it->genero << endl;
        arquivo << it->tamanho << endl;
        arquivo << "\n";
    }
    cout << "              " << "Arquivo gerado com sucesso!\n";
    arquivo.close();
    return 1;
}

void abrir_arquivo(list<dados>& lista){

    dados linha;

    ifstream entrada;

    entrada.open("Produtos.txt");

    if(!entrada){
        cout << "Erro ao abrir o arquivo!\n";
    }

    while(!entrada.eof()){
        entrada >> linha.id;
        entrada >> linha.produto;
        entrada >> linha.genero;
        entrada >> linha.tamanho;
        lista.push_back(linha);
        break;
    }

    entrada.close();
}

        // remoção lógica (bolar teste para saber se a lista está toda "excluída")

int main(){

    list<dados> lista;

    int op;

    abrir_arquivo(lista);

    do{
        op=menu();

        switch(op){
            case 1:
                incluir(lista);
                break;
            case 2:
                alterar_registro(lista);
                break;
            case 3:
                excluir_registro(lista);
                break;
            case 4:
                listar_registros(lista);
                break;
			default:
				cout<<"Digite um valor entre 1 e 6 de acordo com as opcoes informadas.\n\n";
				break;
            case 6:
                salvar_sair(lista);
                break;

        }
    }while(op!=6);



    return 0;
}
