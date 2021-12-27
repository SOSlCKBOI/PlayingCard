#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>

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
        deck(); 
        void starterDeck();
        void shuffleCards();
        void showDeck();
        void sortNumber();
        void swapCard(card*,card*);
    private : 
        int numberOfCard;
        card deckCard[52];
};

//main is here

int main(){
    deck FirstDeck;
    FirstDeck.starterDeck();
    cout << "Deck before shuffle" << endl << endl;
    FirstDeck.showDeck();
    FirstDeck.shuffleCards();
    cout << "Deck after shuffle" << endl << endl;
    FirstDeck.showDeck();
    cout << "Deck after sort by number" << endl << endl;
    FirstDeck.sortNumber();
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
    char clubs[] = "clubs", diamonds[] = "diamonds", hearts[] = "hearts", spades[] = "spades";
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
    if(numberOfCard == 0)
        cout << "There is no card on this deck";
    else{
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
    cout << endl;
}

void deck::shuffleCards(){
    int randomIndex;
    card tempCard;
    srand(time(NULL));
    for(int i=0;i<numberOfCard;i++){
        randomIndex = rand()%numberOfCard;
        tempCard = deckCard[randomIndex];
        deckCard[randomIndex] = deckCard[i];
        deckCard[i] = tempCard;
    }
}

deck::deck() : numberOfCard(0){}

void deck::swapCard(card *a, card *b){
    card tempCard = *a;
    *a = *b;
    *b = tempCard;
}

void deck::sortNumber(){
    int minIndex;
    card tempCard;
    for(int i=0;i<numberOfCard;i++){
        minIndex = i;
        for(int j=i+1;j<numberOfCard;j++){
            if(deckCard[j].getCardNumber() < deckCard[minIndex].getCardNumber())
                minIndex = j;
        }
        swapCard(&deckCard[minIndex],&deckCard[i]);
    }
}