#include "hands.h"
#include <iostream>

std::istream & operator>>(std::istream &is  , PokerHand &pokerHand){
    for(int i = 0 ; i < 5 ; i++){
        is >> pokerHand.suits[i] >> pokerHand.ranks[i];
    }
    return is;
}

bool isRoyalFlush(const PokerHand * pokerHand){
    if(isFlush(pokerHand) && isStraight(pokerHand)){
        int counter = 0;
        for(int i = 0 ; i < 5 ; i++){
            if(pokerHand->ranks[i] == 1 || pokerHand->ranks[i] == 13){
                counter++;
            }
        }
        return counter == 2 ? true : false;
    }
    return false;
}

bool isStraightFlush(const PokerHand * pokerHand){
    return (isStraight(pokerHand) && isFlush(pokerHand));
}

bool isFourOfKind(const PokerHand * pokerHand){
    return pairChecker(pokerHand , 4);
}

bool isFullHouse(const PokerHand * pokerHand){
    return (isOnePair(pokerHand) && isThreeOfKind(pokerHand));
}

bool isFlush(const PokerHand * pokerHand){
    for(int i = 1; i < 5 ; i++){
        if(pokerHand->suits[0] != pokerHand->suits[i]){
            return false;
        }
    }
    return true;
}

bool isStraight(const PokerHand * pokerHand){
    int forwardCounter = 0;
    int backCounter = 0 ;
    for(int i = 1 ; i < 5 ; i++){
        if(pokerHand->ranks[i] == pokerHand->ranks[0]+forwardCounter+1){
            forwardCounter++;
        } else if(pokerHand->ranks[i] == pokerHand->ranks[0]-backCounter-1){
            backCounter++;
        } else if(pokerHand->ranks[0]+forwardCounter+1 > 13){
            if(pokerHand->ranks[0]+forwardCounter+1-13 == pokerHand->ranks[i]){
                forwardCounter++;
            }
        } else if(pokerHand->ranks[0]-backCounter-1 < 1 ){
            if(pokerHand->ranks[i] == pokerHand->ranks[0]-backCounter-1+13){
                backCounter++;
            }
        }
    }
    return backCounter + forwardCounter == 4 ? true : false;
}

bool isThreeOfKind(const PokerHand * pokerHand){
    return pairChecker(pokerHand , 3);
}

bool isTwoPair(const PokerHand * pokerHand){
    int counter = 0;
    int pairCounter = 0;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = i+1 ; j < 5 ; j++){
            if(pokerHand->ranks[i] == pokerHand->ranks[j]){
                counter++;
            }
        }
        if(counter == 1){
            pairCounter++;
        }
        counter = 0;
    } 
    return pairCounter == 2 ? true : false;
}

bool isOnePair(const PokerHand * pokerHand){
    return pairChecker(pokerHand , 2);
}

bool isHighCard(const PokerHand * pokerHand){
    return true;
}

bool pairChecker(const PokerHand * pokerHand , int numberOfPairs){
    int pairCounter = 0;
    for(int i = 0 ; i < 5 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(pokerHand->ranks[i] == pokerHand->ranks[j]){
                pairCounter++;
            }
        }
        if(pairCounter == numberOfPairs){
            return true;
        }
        pairCounter = 0;
    }
    return false;
}