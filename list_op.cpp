#include<iostream>
#include<list>
#include<iomanip>
void listar_registros(list<dados> lista){

    dados mostra;
    if(lista.empty()){
		cout<<"Lista esta vazia\n";
		return;
	}
	for(auto it=lista.begin(); it!=lista.end(); it++){
        if(it->status==true){
			cout<<"===========================================================\n"
            	<<"Id:\t\t"		<< it->id 		<<"\n"
				<< "Produto:\t" << it->produto 	<< "\n"
				<<"Preco: \t\tR$"<<fixed<<setprecision(2)<<it->preco<<"\n"
				<< "Genero:\t\t"	<< it->genero  	<< "\n"
				<< "Tamanho:\t" << it->tamanho 	<< "\n";
        }

    }
    cout<<"===========================================================\n";
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
