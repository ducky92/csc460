#include <iostream>
#include <string>

using namespace std;

class Card
{
	public:
                Card()
		{

		}
                ~Card()
                {

                }
		Card(string cFace, string cSuit)
		{
			face = cFace;
			suit = cSuit;
		}
		string print() const
		{
			return(face + " of " + suit);
		}
		string getFace() const
		{
			return face;	
		}
		string getSuit() const
		{
			return suit;
		}

	private:
		string face;
		string suit;
};
