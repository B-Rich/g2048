//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// The 2048 Game                                           TopScoresUnit1.cpp
// Donnaware International LLC, no rights reserved, so copy away assholes.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "TopScoresUnit1.h"
#include "g2048Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTopScoresForm1 *TopScoresForm1;
//---------------------------------------------------------------------------
__fastcall TTopScoresForm1::TTopScoresForm1(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTopScoresForm1::FormShow(TObject *Sender)
{
    Top  = Form1->Panel1->ClientOrigin.y;
    Left = Form1->Panel1->ClientOrigin.x;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < Panel1->ControlCount; j++) {
            TStaticText *s = (TStaticText *)Panel1->Controls[j];
            if(s->Tag == i+1) {
                s->Caption = AnsiString(game.topscores[i]) + " ";
            }
            if(s->Tag == i+101) {
                if(game.winners[i]) s->Caption = "Winner!";
                else                  s->Caption = "";
            }
        }
   }
   double percetage = (double(game.wins)/double(game.losses))*100;
   AnsiString winloss;

   PercentagesText1->Caption= winloss.FormatFloat("##0.00 %",percetage) ;

}
//---------------------------------------------------------------------------

