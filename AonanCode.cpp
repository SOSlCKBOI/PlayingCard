#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>

using namespace std;

class Card
{
    public :
        void assignCardFace(char cardFace) {face = cardFace;}
        void assignCardNumber(int cardNumber) {number = cardNumber;}
        char getCardFace() {return face;}
        int getCardNumber() {return number;}
    private :
        char face; //หน้าไพ่
        int number; //เลขไพ่
};

class Deck
{
    public :
        Deck() : numberOfCard(0) {} //constructor deck
        void starterDeck(); //ฟังก์ชั่นกำหนดค่าให้ไพ่ทั้งสำรับ
        void shuffleCards(); //ฟังก์ชั่นสับไพ่
        void showDeck(); //ฟังก์ชั่นแสดงผลไพ่ทั้งกองที่ console
        void swapCard(int,int); //สลับที่ไพ่ในกอง
        void showCard(int); //ฟังก์ชั่นแสดงไพ่ที่ console (ไว้ใช้กะ showDeck)
        void showSingleCard(int i) {showCard(i-1);} //ฟังก์ชั่นแสดงไพ่ 1 ใบที่ console
        void testDeck(); //การ์ดกองทดสอบ (มี 5 ใบ)
	    void placeAfter(Card);
        void placeBefore(Card);
        Card sendCard(int);
        void dealCard(int,int); //(Number of players, Number of deal)
        void showHand(); //show card on player hands
    private :
        int numberOfCard;
        int numOnHand;
        int rows,cols;
        Card deckCard[52];
        Card players[20][20];  // assume players max 20 , ถือไพ่สูงสุดในมือ 20  ใบ
        Card LeftCard[52];

};

//main
int main(){
    //driver program
    /*Deck FirstDeck;
    FirstDeck.starterDeck();
    cout << "Deck before shuffle" << endl << endl;
    FirstDeck.showDeck();
    FirstDeck.shuffleCards();
    cout << "Deck after shuffle" << endl << endl;
    FirstDeck.showDeck();*/
    Deck testDeck, testDeck2;
    testDeck.testDeck();
    cout << "Test deck" << endl;
    testDeck.showDeck();
    cout << "Test deck after swap card number 1 and card number 4" << endl;
    testDeck.swapCard(1,4);
    testDeck.showDeck();
    cout << "After the cards have been dealt: " << endl;
    testDeck.dealCard(2,2); //(NumofPlayers,NumofDeal)
    testDeck.showHand(); //Show card on player hands
    testDeck.showDeck(); //

    /*cout << "Show card number 3 from test deck" << endl;
    testDeck.showSingleCard(3);
    cout << "Give the third card of testDeck to testDeck2" << endl;
    testDeck2.placeBefore(testDeck.sendCard(3));
    cout << "TestDeck after sendCard" << endl;
    testDeck.showDeck();
    cout << "TestDeck2 after placeCard" << endl;
    testDeck2.showDeck();*/

}

//ฟังก์ชั่นกำหนดค่าให้ไพ่ทั้งสำรับ
void Deck::starterDeck(){
    for(int i=0;i<52;i++){
        if(i<=12){
            deckCard[i].assignCardFace('C');
            deckCard[i].assignCardNumber(i+1);
        }
        else if(i<=25){
            deckCard[i].assignCardFace('D');
            deckCard[i].assignCardNumber(i-12);
        }
        else if(i<=38){
            deckCard[i].assignCardFace('H');
            deckCard[i].assignCardNumber(i-25);
        }
        else{
            deckCard[i].assignCardFace('S');
            deckCard[i].assignCardNumber(i-38);
        }
        numberOfCard++;
    }
}

//ฟังก์ชั่นแสดงผลไพ่ทั้งกองที่ console
void Deck::showDeck(){
    if(numberOfCard == 0)
        cout << "There is no card on this deck";
    else{
        for(int i=0;i<numberOfCard;i++)
            showCard(i);
    }
    cout << endl;
}

//ฟังก์ชั่นสับไพ่
void Deck::shuffleCards(){
    int randomIndex;
    Card tempCard;
    srand(time(NULL));
    for(int i=0;i<numberOfCard;i++){
        randomIndex = rand()%numberOfCard;
        tempCard = deckCard[randomIndex];
        deckCard[randomIndex] = deckCard[i];
        deckCard[i] = tempCard;
    }
}

//ฟังก์ชั่นสลับไพ่ ตำแหน่ง a กะตำแหน่ง b
void Deck::swapCard(int a, int b){
    Card tempCard;
    tempCard = deckCard[a-1];
    deckCard[a-1] = deckCard[b-1];
    deckCard[b-1] = tempCard;
}

//ฟังก์ชั่นแสดงผลการ์ด
void Deck::showCard(int i){
    if(deckCard[i].getCardNumber() == 1)
        cout << "[" << deckCard[i].getCardFace() << "-" << "A" << "]" << endl;
    else if(deckCard[i].getCardNumber() <= 10)
        cout << "[" << deckCard[i].getCardFace() << "-" << deckCard[i].getCardNumber() << "]" << endl;
    else if(deckCard[i].getCardNumber() == 11)
        cout << "[" << deckCard[i].getCardFace() << "-" << "J" << "]" << endl;
    else if(deckCard[i].getCardNumber() == 12)
        cout << "[" << deckCard[i].getCardFace() << "-" << "Q" << "]" << endl;
    else if(deckCard[i].getCardNumber() == 13)
        cout << "[" << deckCard[i].getCardFace() << "-" << "K" << "]" << endl;
}

void Deck::testDeck(){
    numberOfCard = 5;
    deckCard[0].assignCardFace('C');
    deckCard[0].assignCardNumber(1);
    deckCard[1].assignCardFace('C');
    deckCard[1].assignCardNumber(5);
    deckCard[2].assignCardFace('H');
    deckCard[2].assignCardNumber(3);
    deckCard[3].assignCardFace('S');
    deckCard[3].assignCardNumber(2);
    deckCard[4].assignCardFace('D');
    deckCard[4].assignCardNumber(12);
}

void Deck::placeAfter(Card a)
{
    deckCard[numberOfCard] = a; //กำหนด Index เป็น numberofCard ซึ่งเป็นค่าขยะให้มันเท่ากับ parameter ของฟังก์ชั่นนี้
    numberOfCard++;
}

void Deck::placeBefore(Card a)
{
    int i;
    for(i = numberOfCard; i > 0; i--)
    {
        deckCard[i] = deckCard[i-1];//ทำจากหลังมาหน้า ตรงกันข้ามกับฟังก์ชั่น placeAfter
    }
    deckCard[0] = a;
    numberOfCard++;
}

Card Deck::sendCard(int index)
{
    Card tempCard = deckCard[index-1];
    for(int i = index-1; i < numberOfCard ;i++)
    {
        deckCard[i] = deckCard[i+1];
    }
    numberOfCard--;
    return tempCard;
}

void Deck::dealCard(int row, int col) // row = NumOfPlayers, col = NumOfDealCards
{
    int countCard = numberOfCard;
    rows = row, cols = col;

    for (int j = 0; j < col; ++j) //คนละกี่ใบ
    {
        for (int i = 0; i < row ; ++i) //กี่คน
        {
            players[i][j] = deckCard[countCard-1];
            countCard--;
        }
    }

}

void Deck::showHand()
{
    int numOnHand=0;
    for (int i = 0; i < rows ; i++)
    {
        //showCard(0);
        cout << "Player " << i+1 << ":" <<endl;
        for (int j = 0; j < cols ; j++)
        {
            cout << ' ';
            deckCard[numOnHand] = players[i][j];
            showCard(numOnHand);
            numOnHand++;
        }
        cout << endl;
    }
    numberOfCard = rows*cols;
}


