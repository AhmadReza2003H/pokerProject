#include <iostream>
#include <string.h>
#include "hands.h"
using namespace std;

int main(){
    int ranks[5];
    char suits[5];
    int suitCounter = 0;
    int rankCounter = 0;
    string hand;
    cin >> hand;

    // convert hand to array of suits and ranks

    for(int i = 0 ; i < hand.length() ; i++){
        if(isdigit(hand[i])){
            if(isdigit(hand[i+1])){
                int rank = (hand[i]-'0')*10 + hand[i+1] - '0';
                ranks[rankCounter] = rank;
                rankCounter++;
                i++;
            }
            else{
                ranks[rankCounter] = hand[i]-'0';
                rankCounter++;
            }
        } else {
            suits[suitCounter] = hand[i];
            suitCounter++;
        }
    }
    

   if (isRoyalFlush(suits, ranks)) {
        cout << "Royal Flush" << endl;
    } else if (isStraightFlush(suits, ranks)) {
        cout << "Straight Flush" << endl;
    } else if (isFourOfKind(suits, ranks)) {
        cout << "Four of a Kind" << endl;
    } else if (isFullHouse(suits, ranks)) {
        cout << "Full House" << endl;
    } else if (isFlush(suits, ranks)) {
        cout << "Flush" << endl;
    } else if (isStraight(suits, ranks)) {
        cout << "Straight" << endl;
    } else if (isThreeOfKind(suits, ranks)) {
        cout << "Three of a Kind" << endl;
    } else if (isTwoPair(suits, ranks)) {
        cout << "Two Pair" << endl;
    } else if (isOnePair(suits, ranks)) {
        cout << "One Pair" << endl;
    } else if (isHighCard(suits, ranks)) {
        cout << "High Card" << endl;
    }

    return 0;
}




