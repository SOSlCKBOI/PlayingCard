#include <iostream>
#include <cstring>

using namespace std;

class card{
    public :
        void assignCardFace(char cardFace[]);
        void assignCardNumber(int cardNumber);
        char* getCardFace();
        int getCardNumber();
    private :
        char face[10];
        int number;
};

class deck{
    public :
        void starterDeck();
        void shuffleCards();
        void showDeck();
    private : 
        card deckCard[52];
        int numberOfCard;
};

int main(){
    deck FirstDeck;
    FirstDeck.starterDeck();
    FirstDeck.showDeck();
}

void card::assignCardFace(char cardFace[]){
    strcpy(face,cardFace);
}

void card::assignCardNumber(int cardNumber){
    number = cardNumber;
}

char* card::getCardFace(){
    return face;
}

int card::getCardNumber(){
    return number;
}

void deck::starterDeck(){
    char clubs[] = "club", diamonds[] = "diamonds", hearts[] = "hearts", spades[] = "spades";
    numberOfCard = 52;
    for(int i=0;i<52;i++){
        if(i<=12){
            deckCard[i].assignCardFace(clubs);
            deckCard[i].assignCardNumber(i+1);
        }
        else if(i<=25){
            deckCard[i].assignCardFace(diamonds);
            deckCard[i].assignCardNumber(i-12);
        }
        else if(i<=38){
            deckCard[i].assignCardFace(hearts);
            deckCard[i].assignCardNumber(i-24);
        }
        else{
            deckCard[i].assignCardFace(spades);
            deckCard[i].assignCardNumber(i-38);
        }
    }
}

void deck::showDeck(){
    for(int i=0;i<numberOfCard;i++){
        if(deckCard[i].getCardNumber() == 1)
            cout << "[" << deckCard[i].getCardFace() << "-" << "ACE" << "]" << endl;
        else if(deckCard[i].getCardNumber() <= 10)
            cout << "[" << deckCard[i].getCardFace() << "-" << deckCard[i].getCardNumber() << "]" << endl;
        else if(deckCard[i].getCardNumber() == 11)
            cout << "[" << deckCard[i].getCardFace() << "-" << "JACK" << "]" << endl;
        else if(deckCard[i].getCardNumber() == 12)
            cout << "[" << deckCard[i].getCardFace() << "-" << "QUEEN" << "]" << endl;
        else if(deckCard[i].getCardNumber() == 13)
            cout << "[" << deckCard[i].getCardFace() << "-" << "KING" << "]" << endl;
        
    }
}