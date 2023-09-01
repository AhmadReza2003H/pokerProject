#ifndef _HANDS_H
#define _HANDS_H

bool isRoyalFlush(char* suits , int* ranks);
bool isStraightFlush(char* suits , int* ranks);
bool isFourOfKind(char* suits , int* ranks);
bool isFullHouse(char* suits , int* ranks);
bool isFlush(char* suits , int* ranks);
bool isStraight(char* suits , int* ranks);
bool isThreeOfKind(char* suits , int* ranks);
bool isTwoPair(char* suits , int* ranks);
bool isOnePair(char* suits , int* ranks);
bool isHighCard(char* suits , int* ranks);

#endif