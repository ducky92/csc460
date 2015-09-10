#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "deck.cpp"

using namespace std;


int faceToNum (string a)
{
	if (a == "A")
	{
		return 14;
	}
	else if (a == "K")
	{
		return 13;
	}
	else if (a == "Q")
	{
		return 12;
	}
	else if (a == "J")
	{
		return 11;
	}
	else if (a == "10")
	{
		return 10;
	}
	else
	{
	  return atoi(a.c_str());
	}
}
void displayCard(Card p1, Card p2)
{
	// title of game
        cout << setw(15) << ' ' << setfill('=') << setw(25) << ' ' << setfill(' ') <<  endl;
	cout << setw(15) << ' ' << "= The card game: \"WAR\" =" << setfill(' ') << endl;
	cout << setw(15) << ' ' << setfill('=') << setw(25) << ' ' << endl;
	
	// p1 and p2 cards
	cout << setfill(' ') << setw(14) << "Your Card";
	cout << setfill(' ') << setw(35) << "Opponent's Card" << endl;
	cout << setfill('-') << setw(21) << ' ';
	cout << setfill(' ') <<  setw(12) << ' ' << setfill('-') << setw(21) << ' ' << endl;

	cout << setfill(' ');
	cout << '|' << left << setw(2) << p1.getFace() << right << setfill(' ') << setw(17) << '|';
	cout << setw(14) << '|' << left << setw(2) <<  p2.getFace() << right << setfill(' ') << setw(17) << '|' << endl;

	cout << '|' << setw(19) << '|' << setw(14) << '|' << setw(19) << '|' << endl;
	cout << '|' << setw(19) << '|' << setw(14) << '|' << setw(19) << '|' << endl;
	cout << '|' << setw(19) << '|' << setw(14) << '|' << setw(19) << '|' << endl;
	cout << '|' << setw(19) << '|' << setw(14) << '|' << setw(19) << '|' << endl;

	cout << '|' << setw(4) << ' ' <<  p1.getSuit() << setw(7) << '|';
	cout << setw(14) << '|' << setw(4) << ' ' << p2.getSuit() << setw(7) << '|' << endl;

	cout << '|' << setw(19) << '|' << setw(14) << '|' << setw(19) << '|' << endl;
	cout << '|' << setw(19) << '|' << setw(14) << '|' << setw(19) << '|' << endl;
	cout << '|' << setw(19) << '|' << setw(14) << '|' << setw(19) << '|' << endl;
	cout << '|' << setw(19) << '|' << setw(14) << '|' << setw(19) << '|' << endl;

	cout << '|' << setw(18) << p1.getFace() << '|';
	cout << setw(14) << '|' << setfill(' ') << setw(18) << p2.getFace() << '|' << endl;

	cout << setfill('-') << setw(21) << ' ';
	cout << setfill(' ') <<  setw(12) << ' ' << setfill('-') << setw(21) << ' ' << endl;
}
void dealCards(Deck &d, vector<Card> &a, vector<Card> &b)
{
  d.shuffle();
  Card currCard;
  for(int i = 0; i < DECK_SIZE; ++i)
    {
      currCard = d.dealCard();
      if(i % 2 == 0)
	a.push_back(currCard);
      else
	b.push_back(currCard);
    }
}
int main()
{
	Deck deck;
	Card currCard;
	vector<Card> p1, p2;
	int p1Score = 0;
	int ties = 0;
	int numBattles = 0;
	bool playGame = true;
	bool inputLoop = true;

	dealCards(deck, p1, p2);
	
	while(playGame == true)
	{
		playGame = false;

		if (p1.size() == 0)
		{
			dealCards(deck, p1, p2);
		}
		displayCard(p1.back(), p2.back());
		int p1Face = faceToNum(p1.back().getFace());
		int p2Face = faceToNum(p2.back().getFace());

		if(p1Face == p2Face) 	
		{
			// war
			ties++;
			numBattles++;
			cout << "There was a tie" << endl << endl;
			
		}
		else if (p1Face < p2Face)
		{
			// p2 wins
			numBattles++;
			cout << "You lost" << endl << endl;

		}
		else
		{
			// p1 wins
			p1Score++;
			numBattles++;
			cout << "You Won" << endl << endl;
		}
		// game stats
		cout << setfill(' ') << setw(15) << "Total Battles: "<< setw(9);
		cout << numBattles << endl;
		cout << "You Won: " << setw(15) << p1Score;
		cout << fixed << setprecision(2) << " (" << setw(6);
		cout << ((float) p1Score / numBattles) * 100 << "%)"<< endl;
		cout << "Opponent won: " << setw(10) << numBattles - p1Score - ties;
		cout << " (" << setw(6);
		cout << ((float) (numBattles - p1Score - ties) / numBattles) * 100;
		cout << "%)" << endl;
		cout << "Ties: " << setw(18) << ties;
		cout << " (" << setw(6) << ((float) ties / numBattles) * 100 << "%)"<< endl;

		p1.pop_back();
		p2.pop_back();

		// request new game
		inputLoop = true;
		  while (inputLoop == true)
		    {
		      cout << "Do you want to play another game? (y,n) " << endl;
		      string temp;
		      getline(cin, temp);
		      //cin >> temp;
		      //cout << temp << endl << endl << endl;
		      if (temp.length() == 1 && temp[0] == 'y' || temp[0] == 'Y')
			{
			  playGame = true;
			  inputLoop = false;
			}
		      else if (temp.length() == 1 && temp[0] == 'n' || temp[0] == 'N')
			{
			  playGame = false;
			  inputLoop = false;
			}
		      else
			{
			  cout << "Invalid input: ";
			  inputLoop = true;
			}
		    }
	}

	return 0;
}
