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

void exibe(dados item){
    cout <<"\nNome: "<<item.produto<<endl
         <<"Genero: "<<item.genero<<endl
         <<"Tamanho: "<<item.tamanho<<endl
         <<"Preco: R$"<<fixed<<setprecision(2)<<item.preco<<"\n\n";
}

bool comp_preco_dec(dados a,dados b){return a.preco>b.preco; }

bool comp_preco_cres(dados a,dados b){return a.preco<b.preco; }

bool comp_nome_dec(dados a,dados b){return (strcmp(a.produto,b.produto)>0);}

bool comp_nome_cres(dados a,dados b){return (strcmp(a.produto,b.produto)<0);}

bool listar_registros_grupo(list<dados> l){
    if(l.empty()){
        cout << "lista vazia\n\n";
        return 0;
    }
    int op;
    bool mostrou=false;
    dados dado;
    cout << "Filtrar por: \n\n"
         << "1- Tamanho\n"
         << "2- Genero\n"
         << "3- Produto ordem Crescente\n"
         << "4- Produto ordem Decrescente\n"
         << "5- Preco ordem Crescente\n"
         << "6- Preco ordem Decrescente\n\n";
        do{
        cin>>op;
        switch(op){
        case 1:
            consiste(l,dado,'t');
            for(auto item:l)
            if(strcmp(dado.tamanho, item.tamanho) == 0){
                mostrou = true;
                exibe(item);
            }
            break;

        case 2:
            consiste(l,dado,'g');
            for(auto item:l)
                if(strcmp(dado.genero,item.genero)==0){
                    mostrou=true;
                    exibe(item);
                }
            break;

        case 3:
            l.sort(comp_nome_cres);
            break;

        case 4:
            l.sort(comp_nome_dec);
            break;

        case 5:
            l.sort(comp_preco_cres);
            break;

        case 6:
            l.sort(comp_preco_dec);
            break;

        default:
            cout<<"\nOpcao invalida.\n";
        }
        }while(op<1 || op >6);

        if(op!=1&&op!=2)
            for(auto item:l){
                mostrou=true;
                exibe(item);
        }
        if(!mostrou){
            cout<<"\nNao foram encontrados valores no filtro desejado\n\n";
        }

}

void excluir(list<dados> &l){
    dados dado;
    int id,op;
    cout<<"Qual a id do produto que deseja remover?\n";
    cin>> id;
    for(auto it=l.begin();it!=l.end();it++)
            if(it->id==id){
                cout<< "\nProduto:\t"  << it->produto 	<< "\n"
                    <<"Preco: \t\tR$"<<fixed<<setprecision(2)<<it->preco<<"\n"
                    << "Genero:\t\t" << it->genero  	<< "\n"
                    << "Tamanho:\t"  << it->tamanho 	<< "\n\n"
                    << "\nDeseja realmente remover?(1- Sim | 0- Nao): ";
            cin>>op;
            if(op==1){
                l.erase(it);
                cout<<"Excluido com sucesso.\n";
            }
            if(op==0)
                cout<<"Exclusao cancelada.\n";
            break;
            }
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
