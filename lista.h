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
    Node *head, *end;
	public:
		Lista();
        void createList(int x, int y);
        void insertListByHead(int x, int y);
        void insertListByEnd(int x, int y);
        void print_list();
		bool getValue(int i, int j);
        void removeOccupantList();
        bool verifyLineIsComplete();
        bool verifyPositionNearHead(int x, int y);
		bool verifyPositionNearEnd(int x, int y);//verif3 se a posição sugerida é perto da segunda posição
};

Lista::Lista(){
	head = NULL;
	end = NULL;
}

void Lista::createList(int x, int y){
    Node *s;
    Node *tmp;
    tmp = new Node;
    tmp->coordinate[0] = x;
    tmp->coordinate[1] = y;
    tmp->next = NULL;
    if (head == NULL){
        tmp->previous = NULL;
        head = tmp;
    }
    else{
        s = head;
        while (s->next != NULL)
        s = s->next;
        s->next = tmp;
        tmp->previous = s;
    }
}

void Lista::insertListByHead(int x, int y){
    Node *s;
    Node *tmp;
    Node *penultimo;

	tmp = new Node;
    tmp->coordinate[0] = x;
    tmp->coordinate[1] = y;

	s = head;//s é o primeiro elemento
	penultimo = head;
	int pulaprimeiro=0;
	while (s->next != NULL){ // ate achar  ultimo elemento
           if(pulaprimeiro > 0){
			   penultimo = penultimo->next;//sempre vai estar apontando o elemento anterior ao ultimo
		   }
		   s = s->next;
		   pulaprimeiro++;
	}

    tmp->next = s;
	tmp->previous = penultimo;
	s->previous = tmp;
	penultimo->next = tmp;

}

void Lista::insertListByEnd(int x, int y){
    Node *s;
    Node *tmp;
    Node *segundo;

	tmp = new Node;
    tmp->coordinate[0] = x;
    tmp->coordinate[1] = y;

	s = head;//s é o primeiro elemento
	segundo = head;
    segundo = segundo->next;//achei o segundo elemento da lista

	tmp->next = segundo;
    //tmp->proximo = s;
	tmp->previous = s;
	//tmp->anterior = penultimo;
	s->next = tmp;
	//s->anterior = tmp;
	segundo->previous = tmp;
	//penultimo->proximo = tmp;

}

void Lista::print_list(){
    Node *q;
    if (head == NULL){
        cout<<"Lista vazia"<<endl;
        return;
    }
    q = head;
    cout<<"Valores da lista: "<<endl;
    while (q != NULL){
        cout<<q->coordinate[0]<<","<<q->coordinate[1]<<" <-> ";
        q = q->next;
    }
}

bool Lista::getValue(int i, int j){
	Node *q;
    q = head;
    int x=0;
    int y=0;
    bool find = false;
	while (q != NULL){
        x = q->coordinate[0];
        y = q->coordinate[1];
		if(x==i && y==j){
			find = true;
			return find;
			break;
		}
        q = q->next;
    }
	return find;
}

void Lista::removeOccupantList(){
	Node *s;
    Node *tmp;
    Node *ultimo;

	s = head;//s é o primeiro elemento
	tmp = s->next;
    ultimo = tmp->next;
	int pulaprimeiro=0;
	while (ultimo->next != NULL){ // ate achar  ultimo elemento
           if(ultimo->next != NULL && pulaprimeiro == 1){
				tmp = ultimo;
				ultimo = ultimo->next;
   	   	   }
		   tmp->next = NULL;
  	   	   tmp->previous = NULL;
		   s->next = ultimo;
  	   	   ultimo->previous = s;
  	   	   free(tmp);
  	   	   pulaprimeiro = 1;
	}

}

bool Lista::verifyLineIsComplete(){
	bool resposta = true;
    Node *s;
	Node *s1;
	s = head;
	s1 = s->next;

	while(s->next != NULL){
	  if((s->coordinate[0] == s1->coordinate[0] && s->coordinate[1] == s1->coordinate[1]+1)||
	    (s->coordinate[0] == s1->coordinate[0] && s->coordinate[1] == s1->coordinate[1]-1)||
  	    (s->coordinate[0] == s1->coordinate[0]+1 && s->coordinate[1] == s1->coordinate[1])||
		(s->coordinate[0] == s1->coordinate[0]-1 && s->coordinate[1] == s1->coordinate[1])){
		  s = s->next;
		  if(s1->next != NULL){
			  s1 = s1->next;
		  }
	  }else{
		  resposta = false;
		  break;
	  }
	}

	return resposta;
}

bool Lista::verifyPositionNearHead(int x, int y){
	bool resposta = false;
	Node *s;
    Node *penultimo;

	s = head;//s é o primeiro elemento
	penultimo = head;
	int pulaprimeiro=0;
	while (s->next != NULL){ // ate achar  ultimo elemento
           if(pulaprimeiro > 0){
			   penultimo = penultimo->next;//sempre vai estar apontando o elemento anterior ao ultimo
		   }
		   s = s->next;
		   pulaprimeiro++;
	}

     if((penultimo->coordinate[0] == x && penultimo->coordinate[1] == y+1)||
	    (penultimo->coordinate[0] == x && penultimo->coordinate[1] == y-1)||
  	    (penultimo->coordinate[0] == x+1 && penultimo->coordinate[1] == y)||
		(penultimo->coordinate[0] == x-1 && penultimo->coordinate[1] == y)){
			resposta = true;
		}

	return resposta;
}

bool Lista::verifyPositionNearEnd(int x, int y){
	bool resposta = false;
	Node *s;
    Node *segundo;

	s = head;//é preciso verificar o segundo elemento da linha sempre
	segundo = s->next;

     if((segundo -> coordinate[0] == x && segundo->coordinate[1] == y+1)||
	    (segundo -> coordinate[0] == x && segundo->coordinate[1] == y-1)||
  	    (segundo -> coordinate[0] == x+1 && segundo->coordinate[1] == y)||
		(segundo -> coordinate[0] == x-1 && segundo->coordinate[1] == y)){
			resposta = true;
		}

	return resposta;
}