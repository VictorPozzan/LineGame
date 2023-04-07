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

void printMatriz(int row, int col, int tamLista, Lista line[]){
	for(int i=0; i<col+7+(col*2); i++){
		cout<<"-";	
	}
	cout<<endl;
	cout<<" #    ";
	for(int i=0; i<col; i++){
		cout<<" "<<i<<" ";	
	}
	cout<<"|"<<endl;
	for(int i=0; i<col+7+(col*2); i++){
		cout<<"-";	
	}
	cout<<endl;
	bool vdd = false;
	for(int i=0; i<row; i++){
		cout<<" "<<i <<" | ";
		for(int j=0; j<col; j++){
			for(int k=0; k<tamLista; k++){
		 	vdd = line[k].getValue(i, j);
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
	for(int i=0; i<col+7+(col*2); i++){
		cout<<"-";	
	}
	cout<<endl;
	cout<<"Press Enter to continue"<<endl;
	system("pause");
}

int  **buildMatrix(int row, int col){
	cout<<"Matriz de tamanho: "<<row<<" x "<<col<<endl;
	//alocação dinâmica
	int **pointer, i, j;//p um ponteiro para a matriz
    pointer = (int **) calloc (row, sizeof(int *));//aloca as linhas da matriz

	for (i = 0; i < row; i++){ //aloca as colunas
        pointer[i] = (int*) calloc (col, sizeof(int));
    }
    for(i=0; i<row; i++){
	    for(j=0; j<col; j++){
			pointer[i][j] = -1;
		}
	}
	cout<<"Matriz construida com sucesso\n"<<endl;
    return (pointer);
}

int **removePos(int pos, int row, int col, int **matriz){
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
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

int **destroiMatriz(int row, int col, int **matriz){
	int  i;// variavel auxiliar
	for (i=0; i<row; i++) free (matriz[i]);//libera as linhas da matriz
	free (matriz);// libera a matriz
	cout<<"Matriz destruida com sucesso"<<endl;
	return (NULL);//retorna um ponteiro nulo
}

bool  finalGame(int row, int col, int **matriz){

	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			if(matriz[i][j]==-1){//significa que ainda há alguma posição vazia na matriz
				return true;//se for true continua o jogo
			}
		}
	}
	return false;//se for false retorna o fim do jogo
}

void setupPointsInMatriz(int n, int row, int col, int** matriz, Lista line[]) {
    for (int i = 0; i < n; i++) {
        int elementoX, elementoY;
        bool validPosition = false;

        while (!validPosition) {
            cout << "Digite PX" << i << " inicial: ";
            cin >> elementoX;
            cout << "Digite PY" << i << " inicial: ";
            cin >> elementoY;

            if (elementoX >= 0 && elementoX < row && elementoY >= 0 && elementoY < col && matriz[elementoX][elementoY] == -1) {
                validPosition = true;
                matriz = InserMatriz(elementoX, elementoY, matriz, 'c');
                line[i].createList(elementoX, elementoY);
                printMatriz(row, col, n, line);
            }
            else {
                cout << "Posição inválida ou já ocupada, digite outra posição!" << endl;
            }
        }

        validPosition = false;

        while (!validPosition) {
            cout << "Digite PX" << i << " final: ";
            cin >> elementoX;
            cout << "Digite PY" << i << " final: ";
            cin >> elementoY;

            if (elementoX >= 0 && elementoX < row && elementoY >= 0 && elementoY < col && matriz[elementoX][elementoY] == -1) {
                validPosition = true;
                matriz = InserMatriz(elementoX, elementoY, matriz, 'f');
                line[i].createList(elementoX, elementoY);
                printMatriz(row, col, n, line);
            }
            else {
                cout << "Posição inválida ou já ocupada, digite outra posição!" << endl;
            }
        }
    }
}


void printDirectionCoordinates(){
	cout<<"(X,Y)----->"<<endl;
	cout<<" |"<<endl;
	cout<<" |"<<endl;
	cout<<" |"<<endl;
	cout<<" v"<<endl;
}

boolean positionInsideMatriz(int elementoX, int elementoY, int row, int col){
	if((elementoX >= 0 || elementoX < row) && (elementoY >= 0 || elementoX < col)){
		return true;
	}else{
		cout<<"Esta posicao esta fora da matriz, digite outra posicao!"<<endl;
		return false;
	}
}

boolean positionEmpty(int **matriz, int elementoX, int elementoY, int indexLista, int row, int col, Lista line[]){//verificar posição se esta vazia na matriz
	if(matriz[elementoX][elementoY] == -1){
		return true;
	}
	else{//verificar se -2 ou -3 ou a propria lista não pode inserir
		if(matriz[elementoX][elementoY] == -2 || matriz[elementoX][elementoY] == -3 || matriz[elementoX][elementoY] == indexLista){
			cout<<"Esta posicao ja esta ocupada, digite outra posicao!"<<endl;
			return false;
		}
		else{//remover a lista ocupante dessa possição
			int pos = matriz[elementoX][elementoY];
			matriz = removePos(pos, row, col, matriz);
			line[pos].removeListaOcupante();
		   	return true;
		}
	}
}

int chooseLine(int numberOfPairs, Lista line[]){
	int indexLista;
    cout<<"Escolha a Linha pela qual deseja comecar a jogar"<<endl;
	for(int i=0; i<numberOfPairs; i++){
		cout<<"Linha "<<i<<":"<<endl;
		line[i].print_list();
		cout<<"\n"<<endl;
	}
	cout<<"Indice Linha: ";
	cin>>indexLista;
	
	return indexLista;
}


int main(){
	setlocale(LC_ALL, "Portuguese");
    int numberOfPairs=0, row=0, col=0, **matriz;
	cout<<"LINE GAME"<<endl;
	cout<<"Digite o tamanho da Matriz"<<endl;
	cout<<"Linhas: ";
	cin>>row;
	cout<<"Colunas: ";
	cin>>col;
	matriz = buildMatrix(row, col);
	cout<<"Press Enter to continue"<<endl;
	system("pause");
	system("cls"); 
	numberOfPairs = setNumberPairs(row, col);
	Lista line[numberOfPairs]; 
	setupPointsInMatriz(numberOfPairs, row, col, matriz, line);
	
	bool gameRun = true;
	int indexLista;
	char startByBeginOrEndList;
	bool posInsideMatriz = false, posEmpty = false, posNear = false;
	int elementoX, elementoY;
	while(gameRun){
        system("cls");
		printDirectionCoordinates();
		
		printMatriz(row, col, numberOfPairs, line);
		indexLista = chooseLine(numberOfPairs, line);

		cout<<"Pressione C ou F"<<endl;
		cout<<"C - Comecar pelo ponto inicial"<<endl;
		cout<<"F - Comecar pelo ponto final"<<endl;
        cin>>startByBeginOrEndList;
        bool linhaCompleta = false;

		while(true){
        	system("cls");

			cout<<"Digite PX: ";
			cin>>elementoX;
			cout<<"Digite PY: ";
			cin>>elementoY;

			posInsideMatriz = positionInsideMatriz(elementoX, elementoY, row, col);
			posEmpty  = positionEmpty(matriz, elementoX, elementoY, indexLista, row, col, line);
			
	    	if(!posInsideMatriz || !posEmpty){
        		continue;
    		}
			
			posNear = false;
			
			if(startByBeginOrEndList=='C' || startByBeginOrEndList=='c'){
				posNear = line[indexLista].posicaoPertoComeco(elementoX, elementoY);
			}else if(startByBeginOrEndList=='F' || startByBeginOrEndList=='f'){				
				posNear = line[indexLista].posicaoPertoFinal(elementoX, elementoY);
            }else{
				cout<<"Esta opcao "<<startByBeginOrEndList<<" não existe"<<endl;
				continue;
			}
			
	    	if(!posNear){
        		continue;
    		}
			
	    	if(startByBeginOrEndList=='C' || startByBeginOrEndList=='c'){
        		line[indexLista].insertListByHead(elementoX, elementoY);
    		}else{
        		line[indexLista].insertListByEnd(elementoX,elementoY);
    		}
			
			matriz[elementoX][elementoY] =  indexLista;
    		printMatriz(row, col, numberOfPairs, line);
    		line[indexLista].print_list();

		    if(line[indexLista].percorreLinha()){
        		break;
    		}
			
		}
	   gameRun = finalGame(row, col, matriz);
	}
    matriz = destroiMatriz(row, col, matriz);
	return 0;
}