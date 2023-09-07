#ifndef _HANDS_H
#define _HANDS_H
#include <iostream>
struct PokerHand{
    int ranks[5];
    char suits[5];
};
std::istream & operator>>(std::istream & is , PokerHand &pokerHand);
bool isRoyalFlush(const PokerHand * pokerHand);
bool isStraightFlush(const PokerHand * pokerHand);
bool isFourOfKind(const PokerHand * pokerHand);
bool isFullHouse(const PokerHand * pokerHand);
bool isFlush(const PokerHand * pokerHand);
bool isStraight(const PokerHand * pokerHand);
bool isThreeOfKind(const PokerHand * pokerHand);
bool isTwoPair(const PokerHand * pokerHand);
bool isOnePair(const PokerHand * pokerHand);
bool isHighCard(const PokerHand * pokerHand);
bool pairChecker(const PokerHand * pokerHand , int numberOfPairs);

#endif