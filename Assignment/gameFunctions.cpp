#include "gameFunctions.h"

node::node(){
	card = NULL;
	previous = NULL;
	next = NULL;
	
}

node::node(Card * add){
	
	card = add;

}

node::~node(){
	delete card;
	delete previous;
	delete next;
}

int node::setNext(node * newNext){
	next = new_next;
	return 0;
}

int node::setPrevious(node * newPrevious){
	previous = newPrevious;
	return 0;

}

node * node::getNext(){
	return next;
}

node * node::getPrevious (){
	return previous;
}


int node::displayCard(){
	card->displayCard();
	return 0;

}

char node::getCardColour(){
	return card->getColour();

}


int node::getCardNumber(){
	return card->getNumber();
}


int node::move(node * ending){
	previous->next = NULL;
	previous = ending;
	ending->next = this;
	next = NULL;
	return 0;

}


ArrayList::ArrayList(){
	face = NULL;
	tail = NULL;	
	head = NULL;
	
}


ArrayList::ArrayList(int layers){	
    face = new add * [layers];
    tail = new add * [layers];
    head = new add * [layers];
	
	
}


ArrayList::~ArrayList(){
	delete []face;
	delete []tail;
	delete []head;
}


int Array::insert(Card * add, int cardsInLayers)
{
	if(head[cardsInLayers] == NULL){
		insert_as_first(add, cardsInLayers);
	}
	else{
		add * temp = new add(to_add);
		temp->setPreviousrev(tail[cardsInLayers]);
		tail[cardsInLayers]->setNextext(temp);
		tail[cardsInLayers] = temp;
		face[cardsInLayers] = temp; 
	}
	return 0;
}

int ArrayList::insert_as_first(Card * add, int cardsInLayers){
	add * temp = new node(add);
	face[cardsInLayers] = temp;
	tail[cardsInLayers] = temp;
	head[cardsInLayers] = temp;
	
	return 0;

}


int ArrayList::move(int starting, int ending)
{
	if(tail[starting] == head[starting]) 
		face[starting]->move(tail[ending]);
		tail[ending] = face_up[starting];
		face[starting] = NULL;
		tail[starting] = NULL;
		head[starting] = NULL;
	}
	else{
		node * temp = face[starting]->getPreviousrev();
		face[starting]->move(tail[ending]);
		tail[ending] = face[starting];
		face[starting] = temp;
		tail[starting] = temp;
	}
		
	return 0;
}

int ArrayList::displayLayers(int layers){
	node * temp = head[layers];
	
	while(temp != NULL){
		if(temp == face[layers]){
			while(temp != NULL)
			{
				temp->dsiplayCard();
				temp = temp->getNext();
			}
			return 0;
		}
		else{
			cout << " <>\t";
			temp = temp->getNext();
		}	
	}
	return 0;
}


node * ArrayList::getTail(int position){
	return tail[position];
	
}


node * ArrayList::getFace(int position){
	return face[position];
}

