// cse332_lab2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include "cards.h"

using namespace std;

const char* program_name;
enum lab2_cmd_args{pName, file_name, shuffle};
const int min_cmd_args = 2;
const int max_cmd_args = 3;

const int num_players = 9;
const int cards_per_hand = 5;

int main(int argc, char* argv[])
{
	const char* file_name;
	bool b_shuffle = cmdOptionExists(argv,argv+argc,"-shuffle");
	program_name = argv[lab2_cmd_args::pName];

	if (argc < min_cmd_args){
		
			handleErrMessages(program_name, NOCOMMANDLINEARGS);
			return NOCOMMANDLINEARGS;
	}
	if (argc == min_cmd_args){
		if (b_shuffle){
			handleErrMessages(program_name, NOTENOUGHARGUMENTS_SHUFFLE);
			return NOTENOUGHARGUMENTS_SHUFFLE;
		}

	}
	if (argc == max_cmd_args){
		if (!b_shuffle){
			handleErrMessages(program_name, WRONGCOMMANDLINEARGS);
			return WRONGCOMMANDLINEARGS;
		}
	}
	if (argc > max_cmd_args){
			handleErrMessages(program_name, TOOMANYARGUMENTS);
			return TOOMANYARGUMENTS;
	}

	//Program Logic here
	
	
		file_name = argv[lab2_cmd_args::file_name];
		string fName = file_name;
		string cmd = "-shuffle";
		if (fName == cmd){
			file_name = argv[lab2_cmd_args::shuffle];
		}
	Deck deck;
	int loadErr = deck.load(file_name);
	if (loadErr){
		handleErrMessages(program_name, loadErr);
		return loadErr;
	}

	if (b_shuffle)
		deck.shuffle();
	
	vector<Hand> players;
	for (int i = 0; i < num_players; i++){
		players.push_back(Hand());
	}
	int cards = num_players * cards_per_hand;
	while (cards != 0){
		players[cards%num_players] << deck;
		cards--;
	}
	//print players
	for (auto i = players.begin(); i != players.end(); i++){
		cout << *i << endl;
	}
	cout << endl;

	cout << deck;

	cout << endl;
	//normal sort
	sort(players.begin(), players.end());
	for (auto i = players.begin(); i != players.end(); i++){
		cout << *i << endl;
	}

	cout << endl;

	//poker sort
	sort(players.begin(), players.end(), poker_rank);
	for (auto i = players.begin(); i != players.end(); i++){
		cout << *i << endl;
	}

	return SUCCESS;
}

