#include "hands.h"
#include <iostream>

bool isRoyalFlush(char* suits , int* ranks){
    if(isFlush(suits , ranks) && isStraight(suits , ranks)){
        int counter = 0;
        for(int i = 0 ; i < 5 ; i++){
            if(ranks[i] == 1 || ranks[i] == 13){
                counter++;
            }
        }
        return counter == 2 ? true : false;
    }
    return false;
}
bool isStraightFlush(char* suits , int* ranks){
    return (isStraight(suits , ranks) && isFlush(suits , ranks));
}
bool isFourOfKind(char* suits , int* ranks){
    int counter = 0;
    for(int i = 0 ; i < 2 ; i++){
        for(int j = i+1 ; j < 5 ; j++){
            if(ranks[i] == ranks[j]){
                counter++;
            }
        }
        if(counter == 3){
            return true;
        }
        counter = 0;
    } 
    return false;
}

bool isFullHouse(char* suits , int* ranks){
    return (isOnePair(suits , ranks) && isThreeOfKind(suits , ranks));
}
bool isFlush(char* suits , int* ranks){
    for(int i = 1; i < 5 ; i++){
        if(suits[0] != suits[i]){
            return false;
        }
    }
    return true;
}
bool isStraight(char* suits , int* ranks){
    int forwardCounter = 0;
    int backCounter = 0 ;
    for(int i = 1 ; i < 5 ; i++){
        if(ranks[i] == ranks[0]+forwardCounter+1){
            forwardCounter++;
        } else if(ranks[i] == ranks[0]-backCounter-1){
            backCounter++;
        } else if(ranks[0]+forwardCounter+1 > 13){
            if(ranks[0]+forwardCounter+1-13 == ranks[i]){
                forwardCounter++;
            }
        } else if(ranks[0]-backCounter-1 < 1 ){
            if(ranks[i] == ranks[0]-backCounter-1+13){
                backCounter++;
            }
        }
    }
    return backCounter + forwardCounter == 4 ? true : false;
}
bool isThreeOfKind(char* suits , int* ranks){
    int counter = 0;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = i+1 ; j < 5 ; j++){
            if(ranks[i] == ranks[j]){
                counter++;
            }
        }
        if(counter == 2){
            return true;
        }
        counter = 0;
    } 
    return false;
}
bool isTwoPair(char* suits , int* ranks){
    int counter = 0;
    int pairCounter = 0;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = i+1 ; j < 5 ; j++){
            if(ranks[i] == ranks[j]){
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
bool isOnePair(char* suits , int* ranks){
    int counter = 0;
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 5 ; j++){
            if(ranks[i] == ranks[j]){
                counter++;
            }
        }
        if(counter == 2){
            return true;
        }
        counter = 0;
    } 
    return false;
}
bool isHighCard(char* suits , int* ranks){
    return true;
}