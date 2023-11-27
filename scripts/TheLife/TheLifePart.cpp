//
// Created by rathi on 11/26/2023.
//

#include "TheLifePart.h"
#include "LifeData.h"

#include <vector>

using namespace std;

vector<pair<int,int>> neighbour_cells = {{0,1},{1,0},{1,1},{-1,-1},{-1,0},{-1,1},{1,-1},{0,-1}};
bool temp[BoardSize_X][BoardSize_Y];

bool IsValid(const int cx, const int cy) {//Check if coordinate exists or not
    return cx < BoardSize_X && cy < BoardSize_Y && cx >= 0 && cy >=0;//c->current value
}

int countNeighbour(const int cx, const int cy) {//This functions counts the live neighbour of each cell
    int cnt = 0;//cnt of live neighbour of each cell

    for(const auto &[x,y] : neighbour_cells) {
        const int nx = x+cx; //n -> new value //x -> to be added // c->current value
        const int ny = y+cy;
        if(IsValid(nx,ny)) {//check if it's in bound
            if(temp[nx][ny])cnt++;//check if it's alive
        }
    }

    return cnt;
}

void NextBoard() {
    for(int cx = 0;cx<BoardSize_X;cx++) {//cx -> current_x value
        for(int cy = 0;cy<BoardSize_Y;cy++) {//cy -> current_y value
            temp[cx][cy] = LifeBoard[cx][cy];
        }
    }
    for(int cx = 0;cx<BoardSize_X;cx++) {//cx -> current_x value
        for(int cy = 0;cy<BoardSize_Y;cy++) {//cy -> current_y value
            const int cnt = countNeighbour(cx,cy);// Get the neighbour of the current cell
            if(cnt<2 || cnt>3){LifeBoard[cx][cy] = false;}
            else if(cnt == 3 && !LifeBoard[cx][cy]) {LifeBoard[cx][cy] = true;}
            else if(cnt == 2 && LifeBoard[cx][cy]) {LifeBoard[cx][cy] = true;}
        }
    }
}