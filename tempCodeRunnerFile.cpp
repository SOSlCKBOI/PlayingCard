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
        void dealCard(int, int, Deck[]);
    private :
        int numberOfCard;
        Card deckCard[52];
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
    /*Deck testDeck, testDeck2;
    testDeck.testDeck();
    cout << "Test deck" << endl;
    testDeck.showDeck();
    cout << "Test deck after swap card number 1 and card number 4" << endl;
    testDeck.swapCard(1,4);
    testDeck.showDeck();
    cout << "Show card number 3 from test deck" << endl;
    testDeck.showSingleCard(3);
    cout << "Give the last card of testDeck to testDeck2" << endl;
    //testDeck2.testDeck();
    testDeck2.placeAfter(testDeck.sendCard(1));
    cout << "TestDeck after sendCard" << endl;
    testDeck.showDeck();
    cout << "TestDeck2 after placeCard" << endl;
    testDeck2.showDeck();*/
    Deck TestStack;
    Deck Player[2];
    TestStack.testDeck();
    TestStack.shuffleCards();
    cout << "Shuffled Full stack before deal card" << endl;
    TestStack.showDeck();
    cout << "Player 1 hand before deal card" << endl;
    Player[0].showDeck();
    cout << "Player 2 hand before deal card" << endl;
    Player[1].showDeck();
    TestStack.dealCard(2,2,Player);
    cout << "Full stack after deal card" << endl;
    TestStack.showDeck();
    cout << "Player 1 hand after deal card" << endl;
    Player[0].showDeck();
    cout << "Player 2 hand after deal card" << endl;
    Player[1].showDeck();
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
        cout << "There is no card on this deck" << endl;
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

Card Deck::sendCard(int index){
    Card tempCard = deckCard[index-1];
    for(int i = index-1; i < numberOfCard ;i++){
        deckCard[i] = deckCard[i+1];
    }
    numberOfCard--;
    return tempCard;
}

void Deck::dealCard(int amountDeal, int numberOfPlayer, Deck reciever[20]){
    cout << "Dealing cards........" << endl;
    for(int i = 0; i < amountDeal; i++){
        for(int j = 0; j < numberOfPlayer; j++){
            reciever[j].placeAfter(sendCard(numberOfCard));
        }
    }
}