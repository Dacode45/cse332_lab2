//Initializing mapping
#include "card.h"

const char* Card::suitMap[4] = { "C", "D", "H", "S" };
const char* Card::rankMap[14] = { " ", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };


bool operator<(const Card& k, const Card& c){
	if (k.rank < c.rank){
		return true;
	}
	else if (k.rank == c.rank)
		return (k.suit < c.suit);
	else
		return false;
}



int getRankFromChar(char rChar, Card::RANK &rank){
	int toReturn;
	switch (rChar){
	case '2':
		rank = Card::RANK::two;
		toReturn = SUCCESS;
		break;

	case '3':
		rank = Card::RANK::three;
		toReturn = SUCCESS;
		break;

	case '4':
		rank = Card::RANK::four;
		toReturn = SUCCESS;
		break;

	case '5':
		rank = Card::RANK::five;
		toReturn = SUCCESS;
		break;

	case '6':
		rank = Card::RANK::six;
		toReturn = SUCCESS;
		break;

	case '7':
		rank = Card::RANK::seven;
		toReturn = SUCCESS;
		break;

	case '8':
		rank = Card::RANK::eight;
		toReturn = SUCCESS;
		break;

	case '9':
		rank = Card::RANK::nine;
		toReturn = SUCCESS;
		break;

	case '0':
		rank = Card::RANK::ten;
		toReturn = SUCCESS;
		break;

	case 'J':
	case 'j':
		rank = Card::RANK::jack;
		toReturn = SUCCESS;
		break;

	case 'Q':
	case 'q':
		rank = Card::RANK::queen;
		toReturn = SUCCESS;
		break;

	case 'K':
	case 'k':
		rank = Card::RANK::king;
		toReturn = SUCCESS;
		break;

	case 'A':
	case 'a':
		rank = Card::RANK::ace;
		toReturn = SUCCESS;
		break;

	default:
		toReturn = IMPROPERFILEFORMAT;
		break;

	}

	return toReturn;
}

int getSuitFromChar(const char sChar, Card::SUIT &suit){
	switch (sChar)
	{
	case 'c':
	case 'C':
		suit = Card::SUIT::clubs;
		return SUCCESS;
		break;

	case 'd':
	case 'D':
		suit = Card::SUIT::diamonds;
		return SUCCESS;
		break;

	case 'h':
	case 'H':
		suit = Card::SUIT::hearts;
		return SUCCESS;
		break;

	case 's':
	case 'S':
		suit = Card::SUIT::spades;
		return SUCCESS;
		break;


	default:
		return IMPROPERFILEFORMAT;
		break;
	}

	return IMPROPERFILEFORMAT;
}
