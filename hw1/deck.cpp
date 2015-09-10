#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "card.cpp"

using namespace std;

const int DECK_SIZE = 52;
class Deck
{
	public:
		void printDeck() const
		{
			cout << left;
			for(int i = 0; i < DECK_SIZE; ++i)
			{
				cout << setw(19) << deck[i].print();
				if((i + 1) % 4 == 0)
					cout << endl;
			}
		}

		Deck()
		{
			string FACES[] = { "A", "K", "Q", "J",
					   "10", "9", "8", "7",
					   "6", "5", "4", "3",
					   "2"};
			string SUITS[] = {" Clubs  ", " Spades ",
					  "Diamonds", " Hearts "};
			deck = new Card[DECK_SIZE];
			currCard = 0;
			for(int i = 0; i < DECK_SIZE; ++i)
				deck[i] = Card(FACES[i % 13], SUITS[i / 13]);
		}
		~Deck()
		{




		}
		void shuffle()
		{
			currCard = 0;
			for(int i = 0; i < DECK_SIZE; ++i)
			{
				int second = (rand() + time(0)) % DECK_SIZE;
				Card temp = deck[i];
				deck[i] = deck[second];
				deck[second] = temp;
			}
		}

		Card dealCard()
		{
			if(currCard > DECK_SIZE)
				shuffle();
			if(currCard < DECK_SIZE)
				return deck[currCard++];
			return deck[0];
		}
	private:
		Card *deck;
		int currCard;	
};
