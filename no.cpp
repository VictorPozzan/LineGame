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