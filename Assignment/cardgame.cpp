#include "game.h"


Solitaire::Solitaire()
{
	solitaireBoard = NULL;
}

Solitaire::~Solitaire()
{
	delete solitaireBoard;

}


int Solitaire::dealCards(CardDeck * cardDeck, int deckPosition)
{
	int layers = 7; 
	char selection;
	solitaireBoard = new Array(layers);
	deck->shuffle();	
	
	for(int i = 0; i < layers; i++)
	{
		for(int j = i; j < layers; j++)
		{
			solitaireBoard->insert(deck->getCard(deckPosition), i);
			deckPosition++; 
		}
	}

	displayBoard(deck, deckPosition);
	cin.ignore();	
	cout 	<< "1. Turn Card Around\n"
		<< "2. Move Card\n"
		<< "3. Close\n"
		<< "Option: ";
	cin >> option; 
	
	while(option != 3)
	{	
	switch (option)
	{
	case '1':{
		int starting;
		int ending;
		cout << "Enter layer to move(0 = DECK): ";
		cin >> starting;
		cout << "Enter destination row: ";
		cin >> ending;
		if ( starting == 0) 
		{
			ending--; 
			move_from_deck(deck->get_card(deckPosition), ending);
			deckPosition++;
		}
		else 
		{
			starting--;
			ending--;
			move_card(starting, ending);
		}
		displayBoard(cardDeck, deckPosition);
		cout << "1. Turn Card Around\n"
		<< "2. Move Card\n"
		<< "3. Close\n"
		<< "Option: ";
		cin >> selection;
		break;
	}
	
	case '2': {
		deckPosition++;
		displayBoard(cardDeck, deckPosition);
		cout << "1. Turn Card Around\n"
		<< "2. Move Card\n"
		<< "3. Close\n"
		<< "Option: ";
		cin >> selection;
		break;
		
	}
	case '3': {
		return 0;
	}
	default:
		cout << "Wrong Choice!!!" << endl;
		cout << "Option: ";
		cin >> option;
		break;
		
	};
	}

	return 0;
}


int Solitaire::moveDeck(CardDeck * starting, int ending){
	if(starting->getColour() == getTailColour(ending)){ 
		cout << "\nWrong Colour Palette.\n Colours Should Be Different.\n";
		return 0;
	}
	if(starting->getNumber() != getTailNumber(ending) - 1){
		cout << "\nWrong Numbering!\n The Initial Card Should Be Less Than.\n";
		return 0;
	}

	nodeA * temp = solitaireBoard->getFace(ending);
	solitaireBoard->insert(starting, ending);
	solitaireBoard->setFace(ending, temp); 
	return 0;

}


int Solitaire::moveCard(int starting, int ending){
	if(getFaceColour(starting) == getTailColour(ending)){
		cout << "\nWrong Colour Palette.\n Colours Should Be Different.\n";
		return 0; 
	}
	if(getFaceNumber(starting) != getTailNumber(ending) - 1) {
		cout << "\nWrong Numbering!\n The Initial Card Should Be Less Than.\n";
		return 0;
	}else
	{
		solitaireBoard->move(starting, ending); 
	}
	return 0;

}


int Solitaire::getFaceNumber(int position){
	return solitaireBoard->getFace(position)->getCardNumber();

}


char Solitaire::getFaceColour(int position){
	return solitaireBoard->getFace(position)->getCardColour();

}



char Solitaire::getTailColour(int position){
	return solitaireBoard->get_tail(position)->getTailColour();

}


int Solitaire::getTailNumber(int position){
	return solitaireBoard->getTail(position)->getTailNumber();

}


int Solitaire::displayBoard(CardDeck * cardDeck, int deckPosition){
	cout 	<< "cardDeck: ";
		cardDeck->getCard(deckPosition)->displayCard();
	cout << endl;	
	int layers = 7;  
	for (int i = 0; i < layers; i++)
	{
		cout	<< "Layers " << i + 1 << ": ";
		solitaireBoard->displayLayers(i);
		cout << endl;
	}
	return 0;

}



int Solitaire::displayInitialBoard(){
	cout 	<< "carddDeck: \n";
	int layers = 7;
	
	for(int i = 0; i < layers; i++)
	{
		cout << "Layers " << i + 1 << ":\t";
		for(int j = i; j < layers; j++)
		{
			cout << "<>\t";
		}
		cout << endl;
	}

	return 0;
}



int Solitaire::startGame(CardDeck * cardDeck){
	char option;
	int deckPosition = 0;
	displayInitialBoard();
	cout << "1. Deal Cards\n"
		<<  "2. Close menu\n"
		<<  "option: ";
	cin >> option;
	
	
	if(option == '1'){
		dealCards(cardDeck, deckPosition);
	}
	else if(option == '2'){
		return 0;
	}
	return 0;
}

