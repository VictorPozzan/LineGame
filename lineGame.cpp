#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <cstdlib>
#include <windows.h>
using namespace std;

class No{

	public:
		int valor[2]; //posição 0 = x e 1 = y
        No *proximo;
		No *anterior;
		No();
		No* GetProximo();
		void SetProximo(No *p);
		No* GetAnterior();
		void SetAnterior(No *a);
		int GetValor();
		void SetValor(int x, int y);
};
No::No(){
	proximo = NULL;
	anterior = NULL;
	valor[2] = NULL;
}
No* No::GetProximo(){
	return proximo;
}
void No::SetProximo(No *p){
	proximo = p;
}
No* No::GetAnterior(){
	return anterior;
}
void No::SetAnterior(No *a){
	anterior = a;
}
int No::GetValor(){
	return valor[2];
}
void No::SetValor(int x, int y){
	valor[0] = x;
	valor[1] = y;
}

class lista{
    No *head, *fim;
	public:
		lista();
        void criar_lista(int x, int y);
        void add_head(int novo);
        void add_entre(int novo, int posicao);
        void deletar_elemento(int novo);
        void procurar_elemento(int novo);
        void print_lista();
        void insere_lista_inicial(int x, int y);
        void insere_lista_final(int x, int y);
        bool getValor(int i, int j);
        void removeListaOcupante();
        bool percorreLinha();
        bool posicaoPertoComeco(int x, int y);//verif3 se a posição sugerida é perto da ultima posição
		bool posicaoPertoFinal(int x, int y);//verif3 se a posição sugerida é perto da segunda posição
};

lista::lista(){
	head = NULL;
	fim = NULL;
}

void lista::criar_lista(int x, int y){
    No *s;
    No *tmp;
    tmp = new No;
    tmp->valor[0] = x;
    tmp->valor[1] = y;
    tmp->proximo = NULL;
    if (head == NULL){
        tmp->anterior = NULL;
        head = tmp;
    }
    else{
        s = head;
        while (s->proximo != NULL)
        s = s->proximo;
        s->proximo = tmp;
        tmp->anterior = s;
    }
}
void lista::insere_lista_final(int x, int y){
    No *s;
    No *tmp;
    No *segundo;

	tmp = new No;
    tmp->valor[0] = x;
    tmp->valor[1] = y;

	s = head;//s é o primeiro elemento
	segundo = head;
    segundo = segundo->proximo;//achei o segundo elemento da lista

	tmp->proximo = segundo;
    //tmp->proximo = s;
	tmp->anterior = s;
	//tmp->anterior = penultimo;
	s->proximo = tmp;
	//s->anterior = tmp;
	segundo->anterior = tmp;
	//penultimo->proximo = tmp;

}

void lista::insere_lista_inicial(int x, int y){
    No *s;
    No *tmp;
    No *penultimo;

	tmp = new No;
    tmp->valor[0] = x;
    tmp->valor[1] = y;

	s = head;//s é o primeiro elemento
	penultimo = head;
	int pulaprimeiro=0;
	while (s->proximo != NULL){ // ate achar  ultimo elemento
           if(pulaprimeiro > 0){
			   penultimo = penultimo->proximo;//sempre vai estar apontando o elemento anterior ao ultimo
		   }
		   s = s->proximo;
		   pulaprimeiro++;
	}

    tmp->proximo = s;
	tmp->anterior = penultimo;
	s->anterior = tmp;
	penultimo->proximo = tmp;

}
void lista::print_lista(){
    No *q;
    if (head == NULL){
        cout<<"Lista vazia"<<endl;
        return;
    }
    q = head;
    cout<<"A lista eh: "<<endl;
    while (q != NULL){
        cout<<q->valor[0]<<","<<q->valor[1]<<" <-> ";
        q = q->proximo;
    }
    cout<<"NULL"<<endl;
}

bool lista::getValor(int i, int j){
	No *q;
    q = head;
    int x=0;
    int y=0;
    bool find = false;
	while (q != NULL){
        x = q->valor[0];
        y = q->valor[1];
		if(x==i && y==j){
			find = true;
			return find;
			break;
		}
        q = q->proximo;
    }
	return find;
}

void lista::removeListaOcupante(){
	No *s;
    No *tmp;
    No *ultimo;

	s = head;//s é o primeiro elemento
	tmp = s->proximo;
    ultimo = tmp->proximo;
	int pulaprimeiro=0;
	while (ultimo->proximo != NULL){ // ate achar  ultimo elemento
           if(ultimo->proximo != NULL && pulaprimeiro == 1){
				tmp = ultimo;
				ultimo = ultimo->proximo;
   	   	   }
		   tmp->proximo = NULL;
  	   	   tmp->anterior = NULL;
		   s->proximo = ultimo;
  	   	   ultimo->anterior = s;
  	   	   free(tmp);
  	   	   pulaprimeiro = 1;
	}

}

bool lista::percorreLinha(){
	bool resposta = true;
    No *s;
	No *s1;
	s = head;
	s1 = s->proximo;

	while(s->proximo != NULL){
	  if((s->valor[0] == s1->valor[0] && s->valor[1] == s1->valor[1]+1)||
	    (s->valor[0] == s1->valor[0] && s->valor[1] == s1->valor[1]-1)||
  	    (s->valor[0] == s1->valor[0]+1 && s->valor[1] == s1->valor[1])||
		(s->valor[0] == s1->valor[0]-1 && s->valor[1] == s1->valor[1])){
		  s = s->proximo;
		  if(s1->proximo != NULL){
			  s1 = s1->proximo;
		  }
	  }else{
		  resposta = false;
		  break;
	  }
	}

	return resposta;
}

bool lista::posicaoPertoComeco(int x, int y){
	bool resposta = false;
	No *s;
    No *penultimo;

	s = head;//s é o primeiro elemento
	penultimo = head;
	int pulaprimeiro=0;
	while (s->proximo != NULL){ // ate achar  ultimo elemento
           if(pulaprimeiro > 0){
			   penultimo = penultimo->proximo;//sempre vai estar apontando o elemento anterior ao ultimo
		   }
		   s = s->proximo;
		   pulaprimeiro++;
	}

     if((penultimo->valor[0] == x && penultimo->valor[1] == y+1)||
	    (penultimo->valor[0] == x && penultimo->valor[1] == y-1)||
  	    (penultimo->valor[0] == x+1 && penultimo->valor[1] == y)||
		(penultimo->valor[0] == x-1 && penultimo->valor[1] == y)){
			resposta = true;
		}

	return resposta;
}

bool lista::posicaoPertoFinal(int x, int y){
	bool resposta = false;
	No *s;
    No *segundo;

	s = head;//é preciso verificar o segundo elemento da linha sempre
	segundo = s->proximo;

     if((segundo->valor[0] == x && segundo->valor[1] == y+1)||
	    (segundo->valor[0] == x && segundo->valor[1] == y-1)||
  	    (segundo->valor[0] == x+1 && segundo->valor[1] == y)||
		(segundo->valor[0] == x-1 && segundo->valor[1] == y)){
			resposta = true;
		}

	return resposta;
}

int pontos(int l, int c){
	int numPares;
	while(true){
		cout<<"Informe o numero de pares:"<<endl;
		cin>>numPares;
    	if((numPares<(c*l)/2) && (numPares>=1)){
			return numPares;
		}
		else{
			cout<<"numero de pares inválido"<<endl;
		}
	}
}

void printMatriz(int l, int c, int tamLista, lista dl[]){
	bool vdd = false;
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
			for(int k=0; k<tamLista; k++){
            //cout<<"verificando lista "<<k<<endl;
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
		cout<<" "<<endl;
	}
}
int  **constroiMatriz(int l, int c){
	cout<<"Matriz de tamanho: "<<l<<" x "<<c<<endl;
	//alocação dinâmica
	int **p, i;//p um ponteiro para a matriz
    p = (int **) calloc (l, sizeof(int *));//aloca as linhas da matriz

	for (i = 0; i < l; i++){ //aloca as colunas
        p[i] = (int*) calloc (c, sizeof(int));
    }
    cout<<"Matriz construida com sucesso"<<endl;
    for(int i=0; i<l; i++){
	    for(int j=0; j<c; j++){
			p[i][j] = -1;
		}
	}
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

int main(){
	 setlocale(LC_ALL, "Portuguese");
    int n=0, l=0, c=0, **matriz;
	cout<<"LINE GAME"<<endl;
	cout<<"Digite o tamanho da Matriz"<<endl;
	cout<<"Linhas: ";
	cin>>l;
	cout<<"Colunas: ";
	cin>>c;
	matriz = constroiMatriz(l, c);
	cout<<"Press Enter to continue"<<endl;
	system("pause");
	system("cls"); 
	n = pontos(l, c);

	int elementoX, elementoY;
	bool verif1=false, verif2=false, verif3=false;
	lista dl[n]; //cria vetor de objetos

	cout<<"(X,Y)----->"<<endl;
	cout<<" |"<<endl;
	cout<<" |"<<endl;
	cout<<" |"<<endl;
	cout<<" v"<<endl;
	for(int i=0; i<n; i++){
		verif1=false;
		verif2=false;

		while(verif1==false || verif2==false){
	   		cout<<"Digite PX"<<i<<" inicial: ";
			cin>>elementoX;
			cout<<"Digite PY"<<i<<" inicial: ";
			cin>>elementoY;
			//verificar se a posição esta dentro da matriz
			if((elementoX >= 0 || elementoX < l) && (elementoY >= 0 || elementoX < c)){
				verif1 = true;
			}else{
				verif1 = false;
				cout<<"Esta posicao esta fora da matriz, digite outra posicao!"<<endl;
			}
			//verificar posição ja esta ocupada
			if(matriz[elementoX][elementoY] == -1){
				verif2 = true;
			}
			else{
				verif2 = false;
				cout<<"Esta posicao ja esta ocupada, digite outra posicao!"<<endl;
			}
		}

		matriz = InserMatriz(elementoX, elementoY, matriz, 'c');//insere Matriz Começo
		verif1=false;
		verif2=false;
		dl[i].criar_lista(elementoX, elementoY);

		while(verif1==false || verif2==false){
			cout<<"Digite PX"<<i<<" final: ";
			cin>>elementoX;
			cout<<"Digite PY"<<i<<" final: ";
			cin>>elementoY;
			if((elementoX >= 0 || elementoX < l) && (elementoY >= 0 || elementoX < c)){
				verif1 = true;
			}
			else{
				verif1 = false;
				cout<<"Esta posicao esta fora da matriz, digite outra posicao!"<<endl;
			}
			//verificar posição ja esta ocupada
			if(matriz[elementoX][elementoY] == -1){
				verif2 = true;
			}
			else{
				verif2 = false;
				cout<<"Esta posicao ja esta ocupada, digite outra posicao!"<<endl;
			}
		}

		matriz = InserMatriz(elementoX, elementoY, matriz, 'f');
		dl[i].criar_lista(elementoX, elementoY);
	}

	bool GameRun = true;
	int indexLista;
	char CF;
	while(GameRun){
        system("cls");//limpar a tela do jogo

		printMatriz(l, c, n, dl);
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
        cin>>CF;
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
			if((elementoX >= 0 || elementoX < l) && (elementoY >= 0 || elementoX < c)){
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
					matriz = removePos(pos,l,c, matriz);
					dl[pos].removeListaOcupante();
				   	verif2 = true;
	  	        }
	 	 	 }


			//verificar se o usuario começou pela posição inicial
			if(CF=='C' || CF=='c'){
				//verificar se a posição é perto da posição anterior
				verif3 = dl[indexLista].posicaoPertoComeco(elementoX, elementoY);

				if(verif1 == true && verif2 == true && verif3 == true){
					dl[indexLista].insere_lista_inicial(elementoX, elementoY);//sempre insere na penultima posicao da lista
					matriz[elementoX][elementoY] =  indexLista; //recebe o index da lista
				}
			}else if(CF=='F' || CF=='f'){
				//verificar se a posição é perto da posição anterior
				verif3 = dl[indexLista].posicaoPertoFinal(elementoX, elementoY);

				if(verif1 == true && verif2 == true && verif3 == true){
					dl[indexLista].insere_lista_final(elementoX,elementoY);//sempre insere na segunda posicao da lista
					matriz[elementoX][elementoY] =  indexLista; //recebe o index da lista
				}
            }else{
				cout<<"Esta opcao "<<CF<<" não existe"<<endl;
			}

			//verificar se toda a lista foi percorrida, caso sim pode-se escolher outra lista
			linhaCompleta = dl[indexLista].percorreLinha();


			printMatriz(l, c, n, dl);
			dl[indexLista].print_lista();
			//verificar se a linha esta completa;
		}
	   GameRun = finalGame(l, c, matriz);
	}
    matriz = destroiMatriz(l, c, matriz);
	return 0;
}


