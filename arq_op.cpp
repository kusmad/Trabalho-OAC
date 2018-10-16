#include<iostream>
#include<list>
#include<fstream>

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
        arquivo << it->tamanho << "\n\n";
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
