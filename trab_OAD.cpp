#include<iostream>
#include<list>
#include<fstream>

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

void incluir(list<dados> &lista){
    // Deixar incluir maiúsculo e minúsculo (mostrar sempre maiúsculo) Tamanho e gênero

    dados aux;
    cout << "Digite o nome do produto: ";
	cin.ignore();
    getline(cin,aux.produto);
    cout << "Digite o genero (Masculino (M) / Feminino (F)): ";
    cin >> aux.genero;
    cout << "Digite o tamanho da peca (PP, P, M, G, GG): ";
    cin >> aux.tamanho;
<<<<<<< HEAD

    aux.id=lista.size()+1;

=======

    aux.id=lista.size()+1;

>>>>>>> a8b120bae1fbb593dbf977b06dfa551c328df81d
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

<<<<<<< HEAD
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

=======
        // remoção lógica (bolar teste para saber se a lista está toda "excluída")
    }
}

>>>>>>> a8b120bae1fbb593dbf977b06dfa551c328df81d
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
				cout<<"Digite um valor entre 0 e 5 de acordo com as opcoes informadas.\n\n";
				break;
<<<<<<< HEAD
            case 6:
                salvar_sair(lista);
                break;
=======
>>>>>>> a8b120bae1fbb593dbf977b06dfa551c328df81d

        }
    }while(op!=0);



    return 0;
}
