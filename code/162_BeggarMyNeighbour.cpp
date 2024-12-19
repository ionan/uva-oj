/*
	“Beggar My Neighbour” (sometimes known as “Strip Jack Naked”) is a traditional card game, designed
	to help teach beginners something about cards and their values. A standard deck is shuffled and dealt
	face down to the two players, the first card to the non-dealer, the second to the dealer, and so on until
	each player has 26 cards. The dealer receives the last card. The non-dealer starts the game by playing
	the top card of her deck (the second last card dealt) face up on the table. The dealer then covers it by
	playing her top card face up. Play continues in this fashion until a “face” card (Ace, King, Queen or
	Jack) is played. The next player must then “cover” that card, by playing one card for a Jack, two for a
	Queen, three for a King and four for an Ace. If a face card is played at any stage during this sequence,
	play switches and the other player must cover that card. When this sequence has ended, the player
	who exposed the last face card takes the entire heap, placing it face down under her existing deck. She
	then starts the next round by playing one card face up as before, and play continues until one player
	cannot play when called upon to do so, because they have no more cards.
	
	Write a program that will simulate playing this game. Remember that a standard deck (or pack)
	of cards contains 52 cards. These are divided into 4 suits — Spades (♠), Hearts (♡), Diamonds (♢)
	and Clubs (♣). Within each suit there are 13 cards — Ace (A), 2–9, Ten (T), Jack (J), Queen (Q) and
	King (K).

	INPUT

	Input will consist of a series of decks of cards. Each deck will give the cards in order as they would
	be dealt (that is in the example deck below, the non-dealer would start the game by playing the ‘H2’).
	Decks will occupy 4 lines with 13 cards on each. The designation of each card will be the suit (S, H, D,
	C) followed by the rank (A, 2–9, T, J, Q, K). There will be exactly one space between cards. The file will
	be terminated by a line consisting of a single ‘#’.
	
	OUTPUT
	
	Output will consist of a series of lines, one for each deck in the input. Each line will consist of the
	number of the winning player (1 is the dealer, 2 is the first to play) and the number of cards in the
	winner’s hand (ignoring any on the stack), right justified in a field of width 3.
*/
#include <bits/stdc++.h>
using namespace std;

int nextPlay(deque<int>& deck, deque<int>& cards, bool lastHadPenalty){
printf("[DEBUG] 	Deck has %d cards, and user has %d cards\n", static_cast<int>(deck.size()), static_cast<int>(cards.size()));
	int penaltyCards = 0, i;
	if (cards.size() == 0){
		return -1;
	}
	if (deck.size() > 0){
		penaltyCards = deck.back();
	}
printf("[DEBUG] 	Penalty cards are %d\n", penaltyCards);
	if (penaltyCards == 0){
		if (lastHadPenalty){
printf("[DEBUG] 	User adds %d card to their deck due to the penalty imposed to the other user\n", static_cast<int>(deck.size()));
			while (deck.size() > 0){
				cards.push_front(deck.back());
				deck.pop_back();
			}
printf("[DEBUG] 	User has now %d cards on their deck\n", static_cast<int>(cards.size()));
		}
		deck.push_back(cards.back());
		cards.pop_back();
printf("[DEBUG] 	User adds card that gives a %d card penalty to next user\n", deck.back());
	} else {
		for (i = 0; i < penaltyCards; i++){
			if (cards.size() == 0){
				return -1;
			}
			deck.push_back(cards.back());
			cards.pop_back();
printf("[DEBUG] 	User adds card that gives a %d card penalty to next user\n", deck.back());
			if (deck.back() > 0){
				break;
			}
		}
	}
printf("[DEBUG] 	Deck has now %d cards, and user has %d cards\n", static_cast<int>(deck.size()), static_cast<int>(cards.size()));
	return penaltyCards;
}

int main() {
	int round, lastResult, penaltyCards;
	bool isDealerTurn;
    char card[3];
    deque<int> nonDealer, dealer, deck;
    nonDealer.clear();
    dealer.clear();
    deck.clear();
    isDealerTurn = false;
    lastResult = 0;
    while (scanf("%s", card) != EOF && card[0] != '#'){
    	penaltyCards = 0;
    	if (card[1] == 'J'){
			penaltyCards = 1;
		} else if (card[1] == 'Q'){
			penaltyCards = 2;
		} else if (card[1] == 'K'){
			penaltyCards = 3;    			
		} else if (card[1] == 'A'){
			penaltyCards = 4;
		}   		
    	if (!isDealerTurn){
    		nonDealer.push_back(penaltyCards);
printf("[DEBUG] %s adds %d penalty cards to non-dealer getting a total of %d cards on their deck\n", card, penaltyCards, static_cast<int>(nonDealer.size()));	    		
    	} else {
    		dealer.push_back(penaltyCards);
printf("[DEBUG] %s adds %d penalty cards to dealer getting a total of %d cards on their deck\n", card, penaltyCards, static_cast<int>(dealer.size()));	
    	}	
    	isDealerTurn = !isDealerTurn;
    	if (nonDealer.size() >= 26 && dealer.size() >= 26){
    		round = 1;
    		do {
isDealerTurn ? printf("[DEBUG] Round %d gives turn for the dealer\n", round) : printf("[DEBUG] Round %d gives turn for the non-dealer\n", round);
    			lastResult = nextPlay(deck, isDealerTurn ? dealer : nonDealer, lastResult > 0);
printf("[DEBUG] Last result is %d\n", lastResult);	
    			isDealerTurn = !isDealerTurn;
    			round++;
    		} while (lastResult >= 0);
    		printf("%d %d\n", isDealerTurn ? 1 : 2, static_cast<int>(isDealerTurn ? dealer.size() : nonDealer.size()));
    		nonDealer.clear();
		    dealer.clear();
		    deck.clear();
		    isDealerTurn = false;
		    lastResult = 0;
    	}
    }
    return 0;
}