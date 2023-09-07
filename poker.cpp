#include <iostream>
#include <string.h>
#include "hands.h"

int main(){

    PokerHand pokerHand;
    std::cin >> pokerHand;

    if (isRoyalFlush(&pokerHand)) {
        std::cout << "Royal Flush" << std::endl;
    } else if (isStraightFlush(&pokerHand)) {
        std::cout << "Straight Flush" << std::endl;
    } else if (isFourOfKind(&pokerHand)) {
        std::cout << "Four of a Kind" << std::endl;
    } else if (isFullHouse(&pokerHand)) {
        std::cout << "Full House" << std::endl;
    } else if (isFlush(&pokerHand)) {
        std::cout << "Flush" << std::endl;
    } else if (isStraight(&pokerHand)) {
        std::cout << "Straight" << std::endl;
    } else if (isThreeOfKind(&pokerHand)) {
        std::cout << "Three of a Kind" << std::endl;
    } else if (isTwoPair(&pokerHand)) {
        std::cout << "Two Pair" << std::endl;
    } else if (isOnePair(&pokerHand)) {
        std::cout << "One Pair" << std::endl;
    } else if (isHighCard(&pokerHand)) {
        std::cout << "High Card" << std::endl;
    }

    return 0;
}




