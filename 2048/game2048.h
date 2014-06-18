//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// The 2048 Game                                                   game2048.h
// This is the famous 2048 game that everyone seems to think is
// so neeto, so i guess I had to write one.
// Donnaware International LLC, no rights reserved, so copy away assholes.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef game2048H
#define game2048H
//---------------------------------------------------------------------------
#define NUMSQUARES  4
//---------------------------------------------------------------------------
enum game_result{CONTINUE, WIN, LOOSE};
enum game_move{GAME_LEFT, GAME_RIGHT, GAME_UP, GAME_DOWN};
//---------------------------------------------------------------------------
// Game class
//---------------------------------------------------------------------------
class g2048
{
private:	    // User declarations

   bool        previous_turn;

    inline bool check_coord(int i, int j) {
        return i >= 0 && i < NUMSQUARES && j >= 0 && j < NUMSQUARES;
    }
    void clearsquares(void) {
   	    for(int i = 0; i < NUMSQUARES; i++) {
		    for(int j = 0; j < NUMSQUARES; j++) {
                field[i][j] = 0;
            }
        }
    }
    void shift_pieces(const int mult_i, const int mult_j, const int d_i, const int d_j);
    void shift(game_move move);
    void settopscores(long long lastscore, bool won);
    void put_random(void);
    void undo_push(void);
    void undo_pop(void);

public:		    // User declarations
    short       FINISH_TILE;
    short       field[NUMSQUARES][NUMSQUARES];
    long long   score;
    long long   topscores[10];
    bool        winners[10];
    int         wins;
    int         losses;
    game_result result;

    void move(game_move move);
    void newgame(void);
    game_result get_game_result(void);
    void cheating(void);
    void undo(void);

    g2048(void);    // Class Constructor
};
//---------------------------------------------------------------------------
#endif

