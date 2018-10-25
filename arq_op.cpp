#include<iostream>
#include<list>
#include<fstream>

using namespace std;

void abrir_arquivo(list<dados>&lista){
    ifstream Finp;
    Finp.open("Data.bin",ios::in|ios::binary);

    Finp.seekg(0,ios_base::beg);
    dados dado;
    while (Finp.read((char*)&dado,sizeof(dados)))
        lista.push_back(dado);
    Finp.close();
}

void salvar_sair(list<dados>& lista){
    ofstream Fout;
    Fout.open("Data.bin",ios::out|ios::binary);
    if(!Fout){cout<<"\nAlgum erro ocorreu ao abrir o arquivo\n";return;}

    for(auto dado:lista){
        Fout.write((char *) &dado,sizeof(dados));
    }
    cout<<"Dados foram salvos com sucesso.\n";
    Fout.close();
}
