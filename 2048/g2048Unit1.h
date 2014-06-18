//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// The 2048 Game                                                      g2048.h
// Donnaware International LLC, no rights reserved, copy away assholes.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef g2048Unit1H
#define g2048Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include "game2048.h"
//---------------------------------------------------------------------------
// Menu Key Definitions
//---------------------------------------------------------------------------
#define ARROW_LEFT  0x0025
#define ARROW_UP    0x0026
#define ARROW_RIGHT 0x0027
#define ARROW_DOWN  0x0028
#define ABOUT_KEY   0x0041
#define CHEAT_KEY   0x0043
#define HELPER_KEY  0x0048
#define MENU_KEY    0x004D
#define NEW_KEY     0x004E
#define OPTIONS_KEY 0x004F
#define QUIT_KEY    0x0051
#define SCORES_KEY  0x0053
#define UNDO_KEY    0x0055
//---------------------------------------------------------------------------
// Game Color Selections:
//---------------------------------------------------------------------------
#define TILE_COLOR_2        TColor(0x00dae4ee)
#define TILE_COLOR_4        TColor(0x00c8e0ed)
#define TILE_COLOR_8        TColor(0x0079b1f2)
#define TILE_COLOR_16       TColor(0x006395f5)
#define TILE_COLOR_32       TColor(0x005f7cf6)
#define TILE_COLOR_64       TColor(0x003B5ef6)
#define TILE_COLOR_128      TColor(0x0072cfed)
#define TILE_COLOR_256      TColor(0x0061cced)
#define TILE_COLOR_512      TColor(0x0050c8ed)
#define TILE_COLOR_1024     TColor(0x003fc5ed)
#define TILE_COLOR_2048     TColor(0x002ec2ed)
#define TILE_COLOR_SUPER    TColor(0x00323A3C)
#define TILE_COLOR_BLANK    TColor(0x00C0CDDB)
#define TEXT_COLOR_2        TColor(0x00656E77)
#define TEXT_COLOR_4        TColor(0x00656E77)
#define TEXT_COLOR_8        TColor(0x00f2f6f9)
#define TEXT_COLOR_16       TColor(0x00f2f6f9)
#define TEXT_COLOR_32       TColor(0x00f2f6f9)
#define TEXT_COLOR_64       TColor(0x00f2f6f9)
#define TEXT_COLOR_128      TColor(0x00f2f6f9)
#define TEXT_COLOR_256      TColor(0x00f2f6f9)
#define TEXT_COLOR_512      TColor(0x00f2f6f9)
#define TEXT_COLOR_1024     TColor(0x00f2f6f9)
#define TEXT_COLOR_2048     TColor(0x00f2f6f9)
#define TEXT_COLOR_SUPER    TColor(0x00f2f6f9)
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TPanel *GamePanel1;
    TPanel *Panel3;
    TPanel *Panel4;
    TPanel *Panel5;
    TPanel *Panel2;
    TPanel *Panel6;
    TPanel *Panel7;
    TPanel *Panel8;
    TPanel *Panel9;
    TPanel *Panel10;
    TPanel *Panel11;
    TPanel *Panel12;
    TPanel *Panel13;
    TPanel *Panel14;
    TPanel *Panel15;
    TPanel *Panel16;
    TPanel *Panel17;
    TPanel *Panel18;
    TLabel *ScoreLabel1;
    TStaticText *StaticText1;
    TPanel *NewGameButton1;
    TPanel *LeftPanel1;
    TPopupMenu *PopupMenu1;
    TMenuItem *Options1;
    TMenuItem *Scores1;
    TMenuItem *NewGame1;
    TMenuItem *N1;
    TMenuItem *Quit1;
    TMenuItem *Undo1;
    TMenuItem *Help1;
    TPanel *TopPanel1;
    TPanel *RightPanel1;
    TPanel *BottomPanel1;
    TMenuItem *About1;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
    void __fastcall NewGameButton1Click(TObject *Sender);
    void __fastcall Quit1Click(TObject *Sender);
    void __fastcall NewGame1Click(TObject *Sender);
    void __fastcall Options1Click(TObject *Sender);
    void __fastcall Scores1Click(TObject *Sender);
    void __fastcall Help1Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Undo1Click(TObject *Sender);
    void __fastcall TopPanel1Click(TObject *Sender);
    void __fastcall LeftPanel1Click(TObject *Sender);
    void __fastcall RightPanel1Click(TObject *Sender);
    void __fastcall BottomPanel1Click(TObject *Sender);
    void __fastcall About1Click(TObject *Sender);

private:	// User declarations

    void __fastcall DoPopup(TObject *Sender);
    void __fastcall Cheat(void);
    void __fastcall SetTile(int tile, short num);
    void __fastcall DrawBoard(void);
    void __fastcall PlayerMove(WORD Key);

public:		// User declarations

    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
extern g2048           game;
//---------------------------------------------------------------------------
#endif
