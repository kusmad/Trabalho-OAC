#include<iostream>
#include<list>
#include<iomanip>
#include<stdio.h>
#include<cstring>

using namespace std;

void listar_registros(list<dados>& l){

    dados mostra;
    if(l.empty()){
		cout<<"Lista esta vazia\n";
		return;
	}
	for(auto it=l.begin(); it!=l.end(); it++){
			cout<<"===========================================================\n"
            	<<"Id:\t\t"		<< it->id 		<<"\n"
				<< "Produto:\t" << it->produto 	<< "\n"
				<<"Preco: \t\tR$"<<fixed<<setprecision(2)<<it->preco<<"\n"
				<< "Genero:\t\t"	<< it->genero  	<< "\n"
				<< "Tamanho:\t" << it->tamanho 	<< "\n";

    }
    cout<<"===========================================================\n";
}

bool exibe(list<dados> l, string s1, int cod){
    for(auto it=l.begin(); it!=l.end(); it++){
            string s2;
            if(cod == 1) s2 = conv_str(it->tamanho);
            else if(cod  == 2) s2 = conv_str(it->genero);
            else if(cod  == 3) s2 = conv_str(it->produto);

            if(s1 == s2){
                    cout<<"===========================================================\n"
                    <<"Id:\t\t"		<< it->id 		<<"\n"
                    << "Produto:\t" << it->produto 	<< "\n"
                    <<"Preco: \t\tR$"<<fixed<<setprecision(2)<<it->preco<<"\n"
                    << "Genero:\t\t"	<< it->genero  	<< "\n"
                    << "Tamanho:\t" << it->tamanho 	<< "\n";
                    }
                cout<<"===========================================================\n";
            }
            return 0;
}

bool listar_registros_grupo(list<dados> l){
    if(l.empty()){
        cout << "lista vazia\n\n";
        return 0;
    }

    cout << "Filtrar por: \n\n";
    cout << "1- Tamanho\n";
    cout << "2- Genero\n";
    cout << "3- Produto\n";

    int op;

    cin >> op;

    switch(op){


        case 1:{
            char ftam[5];
            cout << "Digite o tamanho desejado ( PP, P, M, G, GG ): ";
            fflush(stdin);
            gets(ftam);
            maiusculo(ftam);
            string s1 = conv_str(ftam);
            exibe(l, s1, 1);
            break;
        }


        case 2:{
            char gen[5];
            cout << "Digite o nome do Genero (M = Masculino / F = Feminino)\n";
            fflush(stdin);
            gets(gen);
            maiusculo(gen);
            string s1 = conv_str(gen);
            exibe(l, s1, 2);
            break;
        }

        case 3:
            char nprod[40];
            cout << "Digite o nome do produto que deseja buscar: ";
            fflush(stdin);
            gets(nprod);
            maiusculo(nprod);
            string s1 = conv_str(nprod);
            exibe(l, s1, 3);
            break;
    }
}

bool excluir (list<dados> &l){
    if(l.empty()) {
        cout << "Lista vazia!\n\n";
        return 0;
    }

    bool flag =1;

        cout << "Digite o ID do produto que deseja excluir: ";
        int ident;
        cin >> ident;

        for(auto it=l.begin(); it!=l.end(); it++){
            if(it->id == ident){
                l.erase(it);
                flag =0;
                cout << "Item excluido\n\n";
                return 0;
                }
            }
        if(flag==1) cout << "Item nao encontrado\n\n";

        return 0;
}

void incluir(list<dados>&l){
    dados dado;
    consiste(l,dado,'i');
    consiste(l,dado,'n');
    consiste(l,dado,'g');
    consiste(l,dado,'t');
    consiste(l,dado,'p');
    l.push_back(dado);
    cout<<"\nInserido com sucesso.\n";
}
