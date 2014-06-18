//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// The 2048 Game                                                 game2048.cpp
// This is the famous 2048 game that everyone seems to think is
// so neeto, so i guess I had to write one.
//
// Donnaware International LLC, no rights reserved, so copy away assholes.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <mem.h>                // Memory set, copy and so on
#include <stdlib.h>             // Ye ole C standard library
#include <list>                 // C++ Linked list standard library
#pragma hdrstop                 // Stop caching headers now
#include "game2048.h"
//---------------------------------------------------------------------------
typedef struct {                // A nice structure to remember the game state
    short     field[4][4];
    long long score;
    bool      previous_turn;
} gamestate;
using namespace std;            // whatever
list<gamestate> undostack;      // Create the undo stack
//---------------------------------------------------------------------------
// Class instantiator
//---------------------------------------------------------------------------
g2048::g2048(void)
{
    score = 0;                  // start with a score of 0
    FINISH_TILE = 2048;         // the finish tile can be anything
}
//---------------------------------------------------------------------------
// Get game result based on current state
//---------------------------------------------------------------------------
game_result g2048::get_game_result(void)
{
	bool continue_flag = false;
	for(int i = 0; i < NUMSQUARES; i++) {
		for(int j = 0; j < NUMSQUARES; j++) {
            short t = field[i][j];
			if(t == FINISH_TILE) {
				return(WIN);
			}
			if(field[i][j] == 0) {
				continue_flag = true;
				continue;
			}
			static const int D = 4;
			static const int DI[D] = { -1,  0,  0, +1 };
			static const int DJ[D] = {  0, -1, +1,  0 };
			for(int d = 0; d < D; d++) {
				if(check_coord(i + DI[d], j + DJ[d] ) && field[i][j] == field[i + DI[d]][j + DJ[d]]) {
					continue_flag = true;
				}
			}
		}
	}
	return(continue_flag ? CONTINUE : LOOSE);
}
//---------------------------------------------------------------------------
// Move game pieces around based on the user input
//---------------------------------------------------------------------------
void g2048::shift_pieces(const int mult_i, const int mult_j, const int d_i, const int d_j)
{
    undo_push();

	static bool merged[NUMSQUARES][NUMSQUARES];
	memset(merged, false, sizeof(bool) * NUMSQUARES * NUMSQUARES);
	for(int di = 1; di <= NUMSQUARES; di++) {
		for(int dj = 1; dj <= NUMSQUARES; dj++) {
			int i = (NUMSQUARES + di * mult_i) % NUMSQUARES;
			int j = (NUMSQUARES + dj * mult_j) % NUMSQUARES;
			if(field[i][j] == 0) continue;
			int new_i = i;
			int new_j = j;
			do {
				new_i += d_i;
				new_j += d_j;
			} while(check_coord ( new_i, new_j ) && field[new_i][new_j] == 0);

			if(check_coord(new_i, new_j) && field[i][j] == field[new_i][new_j] && !merged[new_i][new_j]) {
				previous_turn = true;
				field[new_i][new_j] += field[i][j];
				score += field[new_i][new_j];
				field[i][j] = 0;
				merged[new_i][new_j] = true;
				continue;
			}
			new_i -= d_i;
			new_j -= d_j;

			if((i != new_i) || (j != new_j)) {
				previous_turn = true;
				field[new_i][new_j] = field[i][j];
				field[i][j] = 0;
			}
		}
	}
}
//---------------------------------------------------------------------------
// User made a move
//---------------------------------------------------------------------------
void g2048::shift(game_move move)
{
    switch(move) {
        case GAME_LEFT:  shift_pieces( +1, +1,  0, -1 );  break;
        case GAME_RIGHT: shift_pieces( +1, -1,  0, +1 );  break;
        case GAME_UP:    shift_pieces( +1, +1, -1,  0 );  break;
        case GAME_DOWN:  shift_pieces( -1, +1, +1,  0 );  break;
	}
    if(previous_turn) {
		put_random();
		previous_turn = false;
	}
}
//---------------------------------------------------------------------------
// The user made a move, do everything needed for that
//---------------------------------------------------------------------------
void g2048::move(game_move move)
{
    shift(move);                            // Shift peices around
    result = get_game_result();             // check if we won yet
    if(result == WIN)   wins++;             // we won, yeah !
    if(result == LOOSE) losses++;           // loser
    settopscores(score, (result == WIN));   // Update all the scores
}
//---------------------------------------------------------------------------
// Put a new random square up
//---------------------------------------------------------------------------
void g2048::put_random(void)
{
	static int empty_cells[NUMSQUARES*NUMSQUARES][2];
	int empty_cells_size = 0;

	for(int i = 0; i < NUMSQUARES; i++) {
		for(int j = 0; j < NUMSQUARES; j++) {
			if(field[i][j] == 0) {
				empty_cells[empty_cells_size][0] = i;
				empty_cells[empty_cells_size][1] = j;
				++empty_cells_size;
			}
		}
	}
	if(empty_cells_size ) {
		int idx = rand() % empty_cells_size;
		field[empty_cells[idx][0]][empty_cells[idx][1]] = 1 << ( rand() % 2 + 1 );
	}
}
//---------------------------------------------------------------------------
// Start a new game
//---------------------------------------------------------------------------
void g2048::newgame(void)
{
    score = 0;
    clearsquares();
    put_random();
    put_random();
    undostack.clear();
}
//---------------------------------------------------------------------------
// Set the top score into the top scores table
//---------------------------------------------------------------------------
void g2048::settopscores(long long lastscore, bool won)
{
    for(int i = 0; i < 10; i++) {
        if(lastscore == topscores[i]) {
            winners[i] = won;
            break;
        }
        if(lastscore > topscores[i]) {
            if(i < 9) {
                for(int j = 9; j > i; j--) {
                    topscores[j] = topscores[j-1];
                    winners[j]   = winners[j-1];
                }
            }
            topscores[i] = lastscore;
            winners[i]   = won;
            break;
        }
    }
}
//---------------------------------------------------------------------------
// Cheating, set up a game that is like 3 moves from winning, WINNING ! hehe
//---------------------------------------------------------------------------
void g2048::cheating(void)
{
    clearsquares();

    field[0][0] = 1024;
    field[0][1] =  512;
    field[0][2] =  256;
    field[0][3] =  256;
    put_random();
    put_random();
    previous_turn = false;
    score = 18000;
}
//---------------------------------------------------------------------------
// Undo Push Game state up onto stack
//---------------------------------------------------------------------------
void g2048::undo_push(void)
{
    gamestate g;
    memcpy(g.field, field, sizeof(short) * NUMSQUARES * NUMSQUARES);
    g.score = score;
    g.previous_turn = previous_turn;
    undostack.push_front(g);
}
//---------------------------------------------------------------------------
// Undo Pop Game state off of stack
//---------------------------------------------------------------------------
void g2048::undo_pop(void)
{
    if(undostack.empty()) return;

    gamestate g;
    g = undostack.front();
    undostack.pop_front();

    memcpy(field, g.field, sizeof(short) * NUMSQUARES * NUMSQUARES);
    previous_turn = g.previous_turn;
    score = g.score;
}
//---------------------------------------------------------------------------
// Undo
//---------------------------------------------------------------------------
void g2048::undo(void)
{
    undo_pop();
}
//---------------------------------------------------------------------------
