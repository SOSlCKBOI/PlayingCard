#include <iostream>
#include <cstring>
#include <cstdlib>
#include <time.h>

using namespace std;

class Card
{
    public :
        void assignCardFace(char cardFace); //mutator ของ private member face
        void assignCardNumber(int cardNumber); //mutator ของ private member number
        char getCardFace(); //accessor ของ private member face
        int getCardNumber(); //accessor ของ private member number
    private :
        char face; //หน้าไพ่
        int number; //เลขไพ่
};

class Deck
{
    public :
        Deck(); //constructor deck
        void starterDeck(); //ฟังก์ชั่นกำหนดค่าให้ไพ่ทั้งสำรับ
        void shuffleCards(); //ฟังก์ชั่นสับไพ่
        void showDeck(); //ฟังก์ชั่นแสดงผลไพ่ทั้งกองที่ console
    private :
        int numberOfCard;
        Card deckCard[52];
};

//main
int main(){
    //driver program
    Deck FirstDeck;
    FirstDeck.starterDeck();
    cout << "Deck before shuffle" << endl << endl;
    FirstDeck.showDeck();
    FirstDeck.shuffleCards();
    cout << "Deck after shuffle" << endl << endl;
    FirstDeck.showDeck();
}

//mutator ของ private member face
void Card::assignCardFace(char cardFace)
{
    face = cardFace;
}

//mutator ของ private member number
void Card::assignCardNumber(int cardNumber){
    number = cardNumber;
}

//accessor ของ private member face
char Card::getCardFace(){
    return face;
}

//accessor ของ private member number
int Card::getCardNumber(){
    return number;
}

//ฟังก์ชั่นกำหนดค่าให้ไพ่ทั้งสำรับ
void Deck::starterDeck(){
    //เก็บหน้าไพ่ไว้ใน array char เพราะติด warning
    numberOfCard = 52; //
    for(int i=0;i<52;i++){
        if(i<=12){ //ไพ่ใบที่ 0 - 12
            deckCard[i].assignCardFace('C'); //ให้หน้าเป็นดอกจิก
            deckCard[i].assignCardNumber(i+1); //ให้เลขเป็น i + 1 ไพ่ดอกจิกใบแรกมี index เป็น 0 ให้เลขการ์ดเป็นเลข 1
        }
        else if(i<=25){ //ไพ่ใบที่ 13 - 25
            deckCard[i].assignCardFace('D'); //ให้หน้าเป็นหลามตัด
            deckCard[i].assignCardNumber(i-12); //ให้เลขเป็น i - 12 ไพ่หลามตัดใบแรกมี index เป็น 13 ให้เลขเป็น 13-12 = 1
        }
        else if(i<=38){ //ไพ่ใบที่ 26 - 38
            deckCard[i].assignCardFace('H'); //โพแดง
            deckCard[i].assignCardNumber(i-25);
        }
        else{ //ไพ่ใบที่ 39 - 52
            deckCard[i].assignCardFace('S'); //โพดำ
            deckCard[i].assignCardNumber(i-38);
        }
    }
}

//ฟังก์ชั่นแสดงผลไพ่ทั้งกองที่ console
void Deck::showDeck(){
    if(numberOfCard == 0)
        cout << "There is no card on this deck"; //ถ้าในกองไม่มีไพ่แสดงผล "There is no card on this deck"
    else{
        for(int i=0;i<numberOfCard;i++){ //แสดงผลไพ่ใบแรก (0) ถึงใบสุดท้าย (numberOfCard-1)
            if(deckCard[i].getCardNumber() == 1)
                cout << "[" << deckCard[i].getCardFace() << "-" << "A" << "]" << endl; //แสดงหน้าและเลขไพ่ที่ i ถ้าเลขเป็น 1 ให้แสดงผลเป็น ACE
            else if(deckCard[i].getCardNumber() <= 10)
                cout << "[" << deckCard[i].getCardFace() << "-" << deckCard[i].getCardNumber() << "]" << endl; //แสดงหน้าและเลขการ์ดที่ i
            else if(deckCard[i].getCardNumber() == 11)
                cout << "[" << deckCard[i].getCardFace() << "-" << "J" << "]" << endl; //แสดงหน้าและเลขไพ่ที่ i ถ้าเลขเป็น 11 ให้แสดงผลเป็น JACK
            else if(deckCard[i].getCardNumber() == 12)
                cout << "[" << deckCard[i].getCardFace() << "-" << "Q" << "]" << endl; //แสดงหน้าและเลขไพ่ที่ i ถ้าเลขเป็น 12 ให้แสดงผลเป็น Queen
            else if(deckCard[i].getCardNumber() == 13)
                cout << "[" << deckCard[i].getCardFace() << "-" << "K" << "]" << endl; //แสดงหน้าและเลขไพ่ที่ i ถ้าเลขเป็น 13 ให้แสดงผลเป็น KING
        }
    }
    cout << endl;
}

//ฟังก์ชั่นสับไพ่
void Deck::shuffleCards(){
    int randomIndex; //ตัวแปรไว้เก็บเลขที่ได้จากการสุ่ม
    Card tempCard; //ตัวแปรไพ่ชั่วคราว
    srand(time(NULL)); //seed
    for(int i=0;i<numberOfCard;i++){ //สุ่มตำแหน่งใหม่ให้ไพ่ทีละใบจนถึงใบสุดท้าย
        randomIndex = rand()%numberOfCard; //สุ่ม index ในช่วง 0 - จำนวนไพ่ที่มี
        tempCard = deckCard[randomIndex]; //ให้ไพ่ชั่วคราว = ไพ่ใบที่อยู่ในตำแหน่งเลขที่สุ่มได้                                       
        deckCard[randomIndex] = deckCard[i]; //ให้ไพ่ในตำแหน่งเลขที่สุ่มได้ = ไพ่ในตำแหน่งที่ลูปทำงานถึง                   
        deckCard[i] = tempCard; //ให้ไพ่ใบที่ลูปทำงานถึง = ไพ่ชั่วคราว ซึ่งไพ่ชั่วคราวมีค่า = ไพ่ใบที่อยู่ในตำแหน่งเลขที่สุ่มได้             
    }
}

Deck::Deck() : numberOfCard(0){}
