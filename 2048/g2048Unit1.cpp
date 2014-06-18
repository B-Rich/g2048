//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// The 2048 Game                                                    g2048.cpp
// This is the famous 2048 game that everyone seems to think is
// so neeto, so i guess I had to write one.
//
// Donnaware International LLC, no rights reserved, so copy away assholes.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#include <mmsystem.h>
#include <inifiles.hpp>
#pragma hdrstop             // stop caching headers
//---------------------------------------------------------------------------
#include "g2048Unit1.h"
#include "GameOverUnit1.h"
#include "SetOptionUnit1.h"
#include "TopScoresUnit1.h"
#include "HelpUnit1.h"
#include "AboutUnit1.h"
#include "game2048.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;                   // This is the pointer to the main form class
g2048   game;                    // This instantiates the 2048 game class
//---------------------------------------------------------------------------
// This is the class constructor for the main form
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
// Whenever the main form closes, do this junk here. It saves the
// game state, high score, yadda yadaa.
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    TIniFile *pIniFile = new TIniFile(ChangeFileExt(Application->ExeName, ".INI"));
    pIniFile->WriteInteger("Options", "WinningNumber", SetOptionForm1->winum);
    pIniFile->WriteBool("Options", "SoundEffects",     SetOptionForm1->CheckBox1->Checked);
    pIniFile->WriteBool("Options", "KeyClicks",        SetOptionForm1->CheckBox2->Checked);
    for(int i = 0; i < 10; i++) {
        pIniFile->WriteInteger("Scores", "Place" + AnsiString(i),  game.topscores[i]);
        pIniFile->WriteBool("Winners",   "Place" + AnsiString(i),  game.winners[i]);
    }
    pIniFile->WriteInteger("Record", "Wins",   game.wins);
    pIniFile->WriteInteger("Record", "Losses", game.losses);
    delete pIniFile;
}
//---------------------------------------------------------------------------
// When ever the main form is shown, do this junk. This is just reading
// back in the data for options, high scores and all that sort of crap.
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
    TIniFile *pIniFile = new TIniFile(ChangeFileExt(Application->ExeName, ".INI"));
    SetOptionForm1->winum = pIniFile->ReadInteger("Options", "WinningNumber", 2048);
    SetOptionForm1->CheckBox1->Checked = pIniFile->ReadBool("Options", "SoundEffects", false);
    SetOptionForm1->CheckBox2->Checked = pIniFile->ReadBool("Options", "KeyClicks", false);
    for(int i = 0; i < 10; i++) {
        game.topscores[i] = pIniFile->ReadInteger("Scores", "Place" + AnsiString(i), 0);
        game.winners[i]   = pIniFile->ReadBool("Winners",   "Place" + AnsiString(i),  false);
    }
    game.wins    = pIniFile->ReadInteger("Record", "Wins",   0);
    game.losses  = pIniFile->ReadInteger("Record", "Losses", 1);
    delete pIniFile;
    NewGameButton1Click(Sender);
}
//---------------------------------------------------------------------------
// Start a new game
//---------------------------------------------------------------------------
void __fastcall TForm1::NewGame1Click(TObject *Sender)
{
    NewGameButton1Click(Sender);
}
//---------------------------------------------------------------------------
// Quit the game
//---------------------------------------------------------------------------
void __fastcall TForm1::Quit1Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
// Show the top scores form
//---------------------------------------------------------------------------
void __fastcall TForm1::Scores1Click(TObject *Sender)
{
    TopScoresForm1->ShowModal();
}
//---------------------------------------------------------------------------
// Show the help screen
//---------------------------------------------------------------------------
void __fastcall TForm1::Help1Click(TObject *Sender)
{
    HelpForm1->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::About1Click(TObject *Sender)
{
    AboutForm1->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TopPanel1Click(TObject *Sender)
{
    PlayerMove(ARROW_UP);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::LeftPanel1Click(TObject *Sender)
{
    PlayerMove(ARROW_LEFT);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RightPanel1Click(TObject *Sender)
{
    PlayerMove(ARROW_RIGHT);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BottomPanel1Click(TObject *Sender)
{
    PlayerMove(ARROW_DOWN);
}
//---------------------------------------------------------------------------
// Shift the pieces around on the board based on the user input
//---------------------------------------------------------------------------
void __fastcall TForm1::PlayerMove(WORD Key)
{
    if(SetOptionForm1->CheckBox2->Checked) PlaySound("TickSound", HInstance, SND_RESOURCE | SND_NOWAIT);
    switch(Key) {
        case ARROW_LEFT:    game.move(GAME_LEFT);   break;
        case ARROW_RIGHT:   game.move(GAME_RIGHT);  break;
        case ARROW_UP:      game.move(GAME_UP);     break;
        case ARROW_DOWN:    game.move(GAME_DOWN);   break;
	}
    DrawBoard();    // redraw the board
    ScoreLabel1->Caption = AnsiString(game.score);  // update the board
    switch(game.result) {
	    case WIN:      GameOverForm1->ShowMsg("You Win !", game.score, true);             break;
    	case LOOSE:    GameOverForm1->ShowMsg("Keep trying dummy...", game.score, false); break;
        case CONTINUE:                                                                    break;
        default:                                                                          break;
	}
}
//---------------------------------------------------------------------------
// Show the popup menu, this shows the popup menu in a nice place
//---------------------------------------------------------------------------
void __fastcall TForm1::DoPopup(TObject *Sender)
{
    int x = Left +  8;
    int y = Top  + 30;
    PopupMenu1->Popup(x,y);
}
//---------------------------------------------------------------------------
// If someone presses a key when the main form is topped, do this stuff
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
    switch(Key) {
        case ARROW_LEFT:    PlayerMove(Key);    break;
        case ARROW_RIGHT:   PlayerMove(Key);    break;
        case ARROW_UP:      PlayerMove(Key);    break;
        case ARROW_DOWN:    PlayerMove(Key);    break;
        case CHEAT_KEY:     Cheat();            break;
        case MENU_KEY:      DoPopup(Sender);    break;
        case NEW_KEY:       NewGame1->Click();  break;
        case OPTIONS_KEY:   Options1->Click();  break;
        case SCORES_KEY:    Scores1->Click();   break;
        case UNDO_KEY:      Undo1->Click();     break;
        case HELPER_KEY:    Help1->Click();     break;
        case ABOUT_KEY:     About1->Click();    break;
        case QUIT_KEY:      Quit1->Click();     break;
        default:                                break;
	}
}
//---------------------------------------------------------------------------
// Set up a game that wins easily
//---------------------------------------------------------------------------
void __fastcall TForm1::Cheat(void)
{
    if(SetOptionForm1->CheckBox1->Checked) {
        PlaySound("SOLVESOUND", HInstance, SND_RESOURCE);
    }
    game.cheating();
}
//---------------------------------------------------------------------------
// If the user wants to start a new game, this is how to do that
//---------------------------------------------------------------------------
void __fastcall TForm1::NewGameButton1Click(TObject *Sender)
{
    game.newgame();                     // Start a new game
    DrawBoard();                        // Draw the board
    if(SetOptionForm1->CheckBox1->Checked) {
        PlaySound("SHUFFLESOUND", HInstance, SND_RESOURCE);
    }
}
//---------------------------------------------------------------------------
// This is how a tile gets drawn, a bunch of windows crap.
//---------------------------------------------------------------------------
void __fastcall TForm1::SetTile(int tile, short num)
{
	for(int i = 0; i < GamePanel1->ControlCount; i++) {
        TPanel *p = (TPanel *)GamePanel1->Controls[i];
        if(p->Tag == tile) {
            if(num) p->Caption = AnsiString(num);
            else    p->Caption = "";
            switch(num) {
               case    0: { p->Color = TILE_COLOR_BLANK; p->Font->Color = TEXT_COLOR_2;    break; }
               case    2: { p->Color = TILE_COLOR_2;     p->Font->Color = TEXT_COLOR_2;    break; }
               case    4: { p->Color = TILE_COLOR_4;     p->Font->Color = TEXT_COLOR_4;    break; }
               case    8: { p->Color = TILE_COLOR_8;     p->Font->Color = TEXT_COLOR_8;    break; }
               case   16: { p->Color = TILE_COLOR_16;    p->Font->Color = TEXT_COLOR_16;   break; }
               case   32: { p->Color = TILE_COLOR_32;    p->Font->Color = TEXT_COLOR_32;   break; }
               case   64: { p->Color = TILE_COLOR_64;    p->Font->Color = TEXT_COLOR_64;   break; }
               case  128: { p->Color = TILE_COLOR_128;   p->Font->Color = TEXT_COLOR_128;  break; }
               case  256: { p->Color = TILE_COLOR_256;   p->Font->Color = TEXT_COLOR_256;  break; }
               case  512: { p->Color = TILE_COLOR_512;   p->Font->Color = TEXT_COLOR_512;  break; }
               case 1024: { p->Color = TILE_COLOR_1024;  p->Font->Color = TEXT_COLOR_1024; break; }
               case 2048: { p->Color = TILE_COLOR_2048;  p->Font->Color = TEXT_COLOR_2048; break; }
            }
        }
    }
}
//---------------------------------------------------------------------------
// Whenever the user does something, re-draw the board
//---------------------------------------------------------------------------
void __fastcall TForm1::DrawBoard(void)
{
    int n = 1;
	for(int i = 0; i < NUMSQUARES; i++) {
		for(int j = 0; j < NUMSQUARES; j++) {
            SetTile(n++, game.field[i][j]);
		}
	}
    ScoreLabel1->Caption = AnsiString(game.score);
}
//---------------------------------------------------------------------------
// Bring up the options form
//---------------------------------------------------------------------------
void __fastcall TForm1::Options1Click(TObject *Sender)
{
    if(SetOptionForm1->ShowModal() == mrOk) {
        game.FINISH_TILE = SetOptionForm1->winum;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Undo1Click(TObject *Sender)
{
    game.undo();        // Undo the last move
    DrawBoard();        // Redraw the board
}
//---------------------------------------------------------------------------


