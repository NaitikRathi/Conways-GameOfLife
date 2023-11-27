//
// Created by rathi on 11/26/2023.
//

#ifndef LIFEDATA_H
#define LIFEDATA_H

#pragma once

extern const inline int BoardSize_Y = 160;
extern const inline int BoardSize_X = 120;

extern bool LifeBoard[BoardSize_X][BoardSize_Y];

void SetBoard();
void NewBoard();

#endif //LIFEDATA_H
