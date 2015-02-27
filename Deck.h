#ifndef DECK_H
#define DECK_H

#include "card.h"
#include "cards.h"
#include <vector>
#include <iostream>

class Deck{
public:

	Deck(const char* &filename);
	int load(const char* &filename);
	void shuffle();
	const int size();

private:
	std::vector<Card> cards;
};

std::ostream& operator<<(std::ostream& out, Deck& deck);


#endif