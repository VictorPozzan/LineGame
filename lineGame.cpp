#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <cstdlib>
#include <windows.h>
#include "no.h"
#include "lista.h"

using namespace std;


int setNumberPairs(int row, int col){
	int numberPairs;
	while(true){
		cout<<"Informe o numero de pares:"<<endl;
		cin>>numberPairs;
    	if((numberPairs<(col*row)/2) && (numberPairs>=1)){
			return numberPairs;
		}
		else{
			cout<<"Numero de pares inválido"<<endl;
		}
	}
}

void printMatriz(int l, int c, int tamLista, Lista dl[]){
	for(int i=0; i<c+7+(c*2); i++){
		cout<<"-";	
	}
	cout<<endl;
	cout<<" #    ";
	for(int i=0; i<c; i++){
		cout<<" "<<i<<" ";	
	}
	cout<<"|"<<endl;
	for(int i=0; i<c+7+(c*2); i++){
		cout<<"-";	
	}
	cout<<endl;
	bool vdd = false;
	for(int i=0; i<l; i++){
		cout<<" "<<i <<" | ";
		for(int j=0; j<c; j++){
			for(int k=0; k<tamLista; k++){
		 	vdd = dl[k].getValor(i, j);
				if(vdd){
					cout<<"  "<<k;
					k = tamLista;
				}
			}
			if(vdd == false){
			   cout<<"  "<<char(164);//164
            }
		}
		cout<<" |"<<endl;
	}
	for(int i=0; i<c+7+(c*2); i++){
		cout<<"-";	
	}
	cout<<endl;
	cout<<"Press Enter to continue"<<endl;
	system("pause");
}

int  **constroiMatriz(int l, int c){
	cout<<"Matriz de tamanho: "<<l<<" x "<<c<<endl;
	//alocação dinâmica
	int **p, i;//p um ponteiro para a matriz
    p = (int **) calloc (l, sizeof(int *));//aloca as linhas da matriz

	for (i = 0; i < l; i++){ //aloca as colunas
        p[i] = (int*) calloc (c, sizeof(int));
    }
    for(int i=0; i<l; i++){
	    for(int j=0; j<c; j++){
			p[i][j] = -1;
		}
	}
	cout<<"Matriz construida com sucesso\n"<<endl;
    return (p);
}

int **removePos(int pos, int l, int c, int **matriz){
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
			if(matriz[i][j] == pos){
				matriz[i][j] = -1;
			}
		}
	}
	return(matriz);
}

int **InserMatriz(int posX, int posY, int **matriz, char cf){
	if(cf=='c'){
		matriz[posX][posY] = -2;//-2 significa começo da linha
	}
	else{
        matriz[posX][posY] = -3;//2 significa começo da linha
	}

	return (matriz);
}

int **destroiMatriz(int l, int c, int **matriz){
	int  i;// variavel auxiliar
	for (i=0; i<l; i++) free (matriz[i]);//libera as linhas da matriz
	free (matriz);// libera a matriz
	cout<<"Matriz destruida com sucesso"<<endl;
	return (NULL);//retorna um ponteiro nulo
}

bool  finalGame(int l, int c, int **matriz){

	for(int i=0; i<l; i++){
		for(int j=0; j<l; j++){
			if(matriz[i][j]==-1){//significa que ainda há alguma posição vazia na matriz
				return true;//se for true continua o jogo
			}
		}
	}
	return false;//se for false retorna o fim do jogo
}

void setupPointsInMatriz(int n, int l, int c,  int **matriz,  Lista dl[]){
	int elementoX, elementoY;
	bool verif1=false, verif2=false, verif3=false;

	for(int i=0; i<n; i++){
		verif1=false;
		verif2=false;

		while(verif1==false || verif2==false){
	   		cout<<"Digite PX"<<i<<" inicial: ";
			cin>>elementoX;
			cout<<"Digite PY"<<i<<" inicial: ";
			cin>>elementoY;
			//verificar se a posição esta dentro da matriz
			if((elementoX >= 0 && elementoX < l) && (elementoY >= 0 && elementoY < c)){
				verif1 = true;
				//verificar posição ja esta ocupada
				if(matriz[elementoX][elementoY] == -1){
					verif2 = true;
				}
				else{
					verif2 = false;
					cout<<"Esta posicao ja esta ocupada, digite outra posicao!"<<endl;
				}
			}else{
				verif1 = false;
				cout<<"Esta posicao esta fora da matriz, digite outra posicao!"<<endl;
			}
		}

		matriz = InserMatriz(elementoX, elementoY, matriz, 'c');//insere Matriz Começo
		verif1=false;
		verif2=false;
		dl[i].criar_lista(elementoX, elementoY);
		printMatriz(l, c, n, dl);
		while(verif1==false || verif2==false){
			cout<<"Digite PX"<<i<<" final: ";
			cin>>elementoX;
			cout<<"Digite PY"<<i<<" final: ";
			cin>>elementoY;
			if((elementoX >= 0 && elementoX < l) && (elementoY >= 0 && elementoX < c)){
				verif1 = true;
				//verificar posição ja esta ocupada
				if(matriz[elementoX][elementoY] == -1){
					verif2 = true;
				}
				else{
					verif2 = false;
					cout<<"Esta posicao ja esta ocupada, digite outra posicao!"<<endl;
				}
			}
			else{
				verif1 = false;
				cout<<"Esta posicao esta fora da matriz, digite outra posicao!"<<endl;
			}
		}
		
		matriz = InserMatriz(elementoX, elementoY, matriz, 'f');
		dl[i].criar_lista(elementoX, elementoY);
		printMatriz(l, c, n, dl);
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
    int n=0, row=0, col=0, **matriz;
	cout<<"LINE GAME"<<endl;
	cout<<"Digite o tamanho da Matriz"<<endl;
	cout<<"Linhas: ";
	cin>>row;
	cout<<"Colunas: ";
	cin>>col;
	matriz = constroiMatriz(row, col);
	cout<<"Press Enter to continue"<<endl;
	system("pause");
	system("cls"); 
	n = setNumberPairs(row, col);
	Lista dl[n]; //cria vetor de objetos
	setupPointsInMatriz(n, row, col, matriz, dl);
	
	bool GameRun = true;
	int indexLista;
	char startByBeginOrEndList;
	bool verif1=false, verif2=false, verif3=false;
	int elementoX, elementoY;
	while(GameRun){
        system("cls");//limpar a tela do jogo

		printMatriz(row, col, n, dl);
		cout<<"Escolha a Linha pela qual deseja comecar a jogar"<<endl;
		for(int i=0; i<n; i++){
			cout<<"Linha "<<i<<":"<<endl;
			dl[i].print_lista();
		}
		cout<<"Indice Linha: ";
		cin>>indexLista;

		cout<<"Precione C ou F"<<endl;
		cout<<"C - Comecar pelo ponto inicial"<<endl;
		cout<<"F - Comecar pelo ponto final"<<endl;
        cin>>startByBeginOrEndList;
        bool linhaCompleta = false;

		while(linhaCompleta == false || verif1==false || verif2==false || verif3==false){
        	system("cls");//limpar a tela do jogo
			cout<<"(X,Y)----->"<<endl;
			cout<<" |"<<endl;
			cout<<" |"<<endl;
			cout<<" |"<<endl;
			cout<<" v"<<endl;

			cout<<"Digite PX: ";
			cin>>elementoX;
			cout<<"Digite PY: ";
			cin>>elementoY;

			//verificar se a posição esta dentro da matriz
			if((elementoX >= 0 || elementoX < row) && (elementoY >= 0 || elementoX < col)){
				verif1 = true;
			}else{
				verif1 = false;
				cout<<"Esta posicao esta fora da matriz, digite outra posicao!"<<endl;
			}

            //verificar posição se esta vazia na matriz
			if(matriz[elementoX][elementoY] == -1){
				verif2 = true;
			}
			else{//verificar se -2 ou -3 ou a propria lista não pode inserir
				if(matriz[elementoX][elementoY] == -2 || matriz[elementoX][elementoY] == -3 || matriz[elementoX][elementoY] == indexLista){
					verif2 = false;
					cout<<"Esta posicao ja esta ocupada, digite outra posicao!"<<endl;
			}
				else{//remover a lista ocupante dessa possição
					int pos = matriz[elementoX][elementoY];
					matriz = removePos(pos, row, col, matriz);
					dl[pos].removeListaOcupante();
				   	verif2 = true;
	  	        }
	 	 	 }


			//verificar se o usuario começou pela posição inicial
			if(startByBeginOrEndList=='C' || startByBeginOrEndList=='c'){
				//verificar se a posição é perto da posição anterior
				verif3 = dl[indexLista].posicaoPertoComeco(elementoX, elementoY);

				if(verif1 == true && verif2 == true && verif3 == true){
					dl[indexLista].insere_lista_inicial(elementoX, elementoY);//sempre insere na penultima posicao da lista
					matriz[elementoX][elementoY] =  indexLista; //recebe o index da lista
				}
			}else if(startByBeginOrEndList=='F' || startByBeginOrEndList=='f'){
				//verificar se a posição é perto da posição anterior
				verif3 = dl[indexLista].posicaoPertoFinal(elementoX, elementoY);

				if(verif1 == true && verif2 == true && verif3 == true){
					dl[indexLista].insere_lista_final(elementoX,elementoY);//sempre insere na segunda posicao da lista
					matriz[elementoX][elementoY] =  indexLista; //recebe o index da lista
				}
            }else{
				cout<<"Esta opcao "<<startByBeginOrEndList<<" não existe"<<endl;
			}

			//verificar se toda a lista foi percorrida, caso sim pode-se escolher outra lista
			linhaCompleta = dl[indexLista].percorreLinha();


			printMatriz(row, col, n, dl);
			dl[indexLista].print_lista();
			//verificar se a linha esta completa;
		}
	   GameRun = finalGame(row, col, matriz);
	}
    matriz = destroiMatriz(row, col, matriz);
	return 0;
}


