#include "userRole.h"

int menu(int DECKSIZE)
{
	CardDeck * cardDeck = new cardDeck(DECKSIZE);
	CardGame * cardGame;
	cardDeck->fill_cardDeck();
	
	char option;
	
	while (option != '3')
	{
		cardDeck->shuffle();
		cout << "\nChoose any of the options:\n"
			<< "1. Display Cards\n"
			<< "2. Solitaire\n"
			<< "3. Close Menu \n"		
		    << "\nOptions: ";
		cin >> option;
		
		{
		case '1':
		{
			displayCards();
			break;
		}
		case '2':
		{
			Solitaire * solitaire = new Solitaire();
			cardGame = (&*solitaire);
			cardGame->play(cardDeck);	
			break;
		}
		case '3':
		{
			break;
		}
		default:
		{
			break;
		}
		};

	}
	return 0;
}

int displayCards()
{
	cout << "\n-------Cards-------\n"
		<< "\n\n-<>-----Suit-----<>-"
		<< "\nc = CLUBS\ts = SPADES\td = DIAMONDS\th = HEARTS\n\n";
		<< "\n-<>-----Color-----<>-"
		<< "\nr = RED  \tb = BLACK"

	return 0;
}
