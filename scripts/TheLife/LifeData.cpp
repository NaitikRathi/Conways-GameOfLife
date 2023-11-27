//
// Created by rathi on 11/26/2023.
//
#include<cstdlib>
#include<ctime>
#include<iostream>

#include <SDL.h>

#include "LifeData.h"

using namespace std;

bool LifeBoard[BoardSize_X][BoardSize_Y];

void SetBoard() {
    for(size_t i = 0;i<BoardSize_X;i++) {
        for(size_t j= 0;j<BoardSize_Y;j++) {
            LifeBoard[i][j] = false;
        }
    }
}

void NewBoard() {
    srand(time(NULL));
    for(size_t i = 0;i<BoardSize_X;i++) {
        for(size_t j= 0;j<BoardSize_Y;j++) {
            int random_chance = rand()%1000;
            if(random_chance>=875){LifeBoard[i][j] = true;}
        }
    }
}
