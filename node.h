class Node{

	public:
		int coordinate[2];
        Node *next;
		Node *previous;
		Node();
		Node* getNext();
		void setNext(Node *p);
		Node* getPrevious();
		void setPrevious(Node *a);
		int getCoordinate();
		void setCoordinate(int x, int y);
};

Node::Node(){
	next = NULL;
	previous = NULL;
	coordinate[2] = NULL;
}

Node* Node::getNext(){
	return next;
}

void Node::setNext(Node *p){
	next = p;
}

Node* Node::getPrevious(){
	return previous;
}

void Node::setPrevious(Node *a){
	previous = a;
}

int Node::getCoordinate(){
	return coordinate[2];
}

void Node::setCoordinate(int x, int y){
	coordinate[0] = x;
	coordinate[1] = y;
}