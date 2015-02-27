#include "Deck.h"
#include "cards.h"
#include <fstream>
#include <string>


Deck::Deck(const char* &filename){

	int loadErr =
		load(filename);
	
	if (loadErr){
		throw loadErr;
	}
	
}

int Deck::load(const char* &filename){
	//Which Error to Return
	int toReturn = SUCCESS;
	std::string white_space_buffer; // used for skipping whitespace
	std::ifstream in(filename);
	std::string line;
	if (in.is_open()){
		in >> std::ws;

		int cardsAdded = 0;
		char rankChar, suitChar;

		while (in >> rankChar){

			if (in.fail()){
				in.clear();
				handleErrMessages(program_name, "Error durring File Handling. Will attempt to continue.");
				toReturn = ERRORDURINGFILEREADING;
			}

			in >> std::ws;
			in >> suitChar;
			if (suitChar == '0'){
				rankChar = '0';
				in >> std::ws;
				in >> suitChar;
			}
			if (suitChar == '/' || rankChar == '/'){// reach end or comment
				continue;
			}
			in >> std::ws;

				Card::RANK r;
				Card::SUIT s;
				int rankErr = getRankFromChar(rankChar, r);
				int suitErr = getSuitFromChar(suitChar, s);
				if (rankErr || suitErr){
					if (!toReturn){
						handleErrMessages(program_name, "Improper File Format");
					}
					continue;
				}
				Card c(s, r);

				this->cards.push_back(c);
				cardsAdded++;

			
		}
		in.close();
		return toReturn;
	}
	else{
		handleErrMessages(program_name, "Couldn't open the file");
		return CANTOPENFILE;
	}
}