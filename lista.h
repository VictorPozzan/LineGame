#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <cstdlib>
#include <windows.h>


using namespace std;

class Lista{
    No *head, *fim;
	public:
		Lista();
        void createList(int x, int y);
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

Lista::Lista(){
	head = NULL;
	fim = NULL;
}

void Lista::createList(int x, int y){
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

void Lista::insere_lista_final(int x, int y){
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

void Lista::insere_lista_inicial(int x, int y){
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

void Lista::print_lista(){
    No *q;
    if (head == NULL){
        cout<<"Lista vazia"<<endl;
        return;
    }
    q = head;
    cout<<"Valores da lista: "<<endl;
    while (q != NULL){
        cout<<q->valor[0]<<","<<q->valor[1]<<" <-> ";
        q = q->proximo;
    }
 	cout<<"Press Enter to continue"<<endl;
	system("pause");
}

bool Lista::getValor(int i, int j){
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

void Lista::removeListaOcupante(){
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

bool Lista::percorreLinha(){
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

bool Lista::posicaoPertoComeco(int x, int y){
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

bool Lista::posicaoPertoFinal(int x, int y){
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