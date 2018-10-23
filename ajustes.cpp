#include <iostream>
#include <list>
#include <cctype>
#include <algorithm>
#include <iomanip>
#include <string.h>

using namespace std;
struct dados{
    int id;
    char produto[40], genero[5],tamanho[5];
    bool status=true;
    float preco;
};

void maiusculo(char s[]){
    for(int i=0;i<strlen(s);i++){
        s[i]=toupper(s[i]);
    }

}

string conv_str(char s[]){
    string str=" ";
    for(int i=0;i<=strlen(s);i++)
        str[i]=s[i];
    return s;
}

void consiste(list<dados> l,dados &aux,char op){
    char genr;
    string str;
    bool existe;
    switch(op){
    case 'g':
        do{
            cout << "Digite o genero (Masculino (M) / Feminino (F)): ";
            fflush(stdin);
            gets(aux.genero);
            aux.genero[0]=toupper(aux.genero[0]);
            }while(!(aux.genero[0]=='M'^aux.genero[0]=='F'));
    break;

    case 't':
        do{
            cout << "Tamanho(Apenas os tamanhos PP, P, M, G, GG serao aceitos): ";
            fflush(stdin);
            gets(aux.tamanho);
            maiusculo(aux.tamanho);
            str=conv_str(aux.tamanho);
        }while(!(str=="PP"^str=="P"^str=="M"^str=="G"^str=="GG"));
    break;

    case 'i':
        do{
            existe=false;
            cout <<"Digite a ID do produto: ";
            cin>> aux.id;
            if(aux.id<0){
                cout<<"\nApenas valores positivos sao validos\n\n";
            }
            for(auto it=l.begin();it!=l.end();it++){
                if(it->id==aux.id){
                    existe=true;
                    cout<<"ID ja cadastrado!\n";
                    break;
                }
            }
        }while(existe||aux.id<0);
        break;
    case 'n':
        cout << "Digite o nome do produto: ";
        fflush(stdin);
        gets(aux.produto);
        maiusculo(aux.produto);
        break;
    case 'p':
        do{
            cout<<"Digite o preco: R$";
            cin>>aux.preco;
        }while(aux.preco<0);
        break;
    }
}

void altera_valores(list<dados>l,dados &item){
    int op;

    cout <<"Nome: "<<item.produto<<endl
         <<"Genero: "<<item.genero<<endl
         <<"Tamanho: "<<item.tamanho<<endl
         <<"Preco: R$"<<fixed<<setprecision(2)<<item.preco<<"\n\n"
         << "Qual valor desseja alterar ?\n"
         << "1 - Nome do produto\n"
         << "2 - Genero\n"
         << "3 - Tamanho\n"
         << "4 - Preco\n";
    cin>>op;
    switch(op){
    case 1:
        consiste(l,item,'n');
        break;
    case 2:
        consiste(l,item,'g');
        break;
    case 3:
        consiste(l,item,'t');
        break;
    case 4:
        consiste(l,item,'p');
    }
    cout<<"Alterado com sucesso\n\n";
    }
