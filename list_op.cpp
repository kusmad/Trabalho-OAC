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
    if(l.empty()||l.back().id<dado.id)
        l.push_back(dado);
    else
        if(l.front().id>dado.id)
            l.push_front(dado);
        else
            for(auto it=l.begin();it!=l.end();it++)
                if(it->id>dado.id)
                    l.insert(it,dado);
    cout<<"\nInserido com sucesso.\n";
}

void exclui(list<dados> &l){
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
