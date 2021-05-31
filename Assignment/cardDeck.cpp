#include "deck.h"

Card::Card()
{

}

Card::~Card()
{

}


Card::Card(char in_color, char in_suit, int in_num)
{
	color = in_color;
	suit = in_suit;
	num = in_num;
}


Card::Card(const Card *& to_copy)
{
	color = to_copy->color;
	suit = to_copy->suit;
	num = to_copy->num;
}


int Card::print_card()
{
	cout 	<<" -"
		<< color
		<< suit
	 	<< num
		<< "- ";
	return 0;
}


int Card::print_card_face_down()
{
	cout	<<" -"
		<<"?"
		<<"?"
		<<"??"
		<<"- ";
	return 0;
}


int Card::set_card(char in_color, char in_suit, int in_num)
{
	color = in_color;
	suit = in_suit;
	num = in_num;

}


Card* Card::get_card()
{

	return this;
}


{
	color = to_copy.color;
	suit = to_copy.suit;
	num = to_copy.num;
	return 0;
}

int Card::copy_card(Card *to_copy)
{
	color = to_copy->color;
	suit = to_copy->suit;
	num = to_copy->num;
	return 0;
}


int Card::get_num()
{
	return num;
}

char Card::get_color()
{
	return color;

}


Deck::Deck()
{
	deck = NULL;
}

Deck::~Deck()
{
	delete []deck;
}


Deck::Deck(int in_DECK_SIZE)
{
	DECKSIZE = in_DECKSIZE;
	cardDeck = new Card[DECKSIZE];	
}


int Deck::fill_deck()
{
	ifstream infile;
	infile.open("cards.txt");
	for (int i = 0; i < DECK_SIZE; i++)
	{
		char colour;
		char suit;
		int number;
		infile >> colour >> suit >> number;
		infile.ignore(DECKSIZE, '\n');
		cardDeck[i].setCard(colour, suit, number);
	}
	infile.close();	
	return 0;
}


int CardDeck::displayDeck() const
{
	displayDeck(0);
	return 0;	d
}


int CardDeck::displayDeck(int position) const
{
	if(position == DECK_SIZE)
		return 0;
	else
	{
		deck[position].displayCard();
		position++;
		return displayDeck(position);
	}
	return 0;
}


int CardDeck::swap(int x, int y)
{
	Card * temp = new Card;
	temp->copy_card(cardDeck[x]);
	cardDeck[a].addCard(cardDeck[y]);
	cardDeck[b].addCard(temp);
	return 0;
}


int CardDeck::shuffle(){
	srand(time(NULL));
	for (int i = (DECKSIZE - 1); i > 0; i--)
	{
		int j = rand() % (i + 1);
		swap(j, i);
				
	}
	return 0;
}


Card* CardDeck::getCard(int deckPosition){
	Card * temp = cardDeck[deckPosition].getCard();
	return temp;

}