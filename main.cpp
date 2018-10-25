#include<iostream>
#include<list>
#include "ajustes.cpp"
#include "list_op.cpp"
#include "arq_op.cpp"
using namespace std;

int menu(){
    int op;
    cout<< "1- Incluir novo registro\n"
        << "2- Alterar registro existente\n"
        << "3- Excluir registro\n"
        << "4- Listar todos os registros\n"
        << "5- Listar os dados por grupo\n"
        << "6- Salvar e Sair\n";
    cin >> op;
    return op;

}

int main(){
    list<dados> l;
    int id,op;
    list<dados>::iterator it;

    abrir_arquivo(l);
do{
    op=menu();
    switch(op){
    case 1:
        incluir(l);
        break;

    case 2:
        cout<<"Qual o id do produto que deseja alterar?\n";
        cin>>id;
        for(auto it=l.begin();it!=l.end();it++)
            if(it->id==id)
                altera_valores(l,*it);
        break;
case 3:
    excluir(l);
    break;
case 4:
    listar_registros(l);
    break;
case 5:
    listar_registros_grupo(l);
    break;
case 6:
    salvar_sair(l);
    break;
default:
    cout<<"Opcao invalida";
    break;
    }
}while(op!=6);
}
