//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// The 2048 Game                                            GameOverUnit1.cpp
// Donnaware International LLC, no rights reserved, so copy away assholes.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#include <mmsystem.h>
#pragma hdrstop
#include "GameOverUnit1.h"
#include "SetOptionUnit1.h"
#include "g2048Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGameOverForm1 *GameOverForm1;
//---------------------------------------------------------------------------
__fastcall TGameOverForm1::TGameOverForm1(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGameOverForm1::FormShow(TObject *Sender)
{
    Top  = Form1->Panel1->ClientOrigin.y;
    Left = Form1->Panel1->ClientOrigin.x;
}
//---------------------------------------------------------------------------
void __fastcall TGameOverForm1::ShowMsg(AnsiString Message, long long score, bool win)
{
    Label3->Visible = false;
    Label1->Caption =  Message;

    if(win) Label1->Font->Color = TColor(0x003B5EF6);
    else    Label1->Font->Color = TColor(0x00667A8F);

    Image1->Visible =  win;
    Image2->Visible = !win;

    Show();
    Application->ProcessMessages();

    if(SetOptionForm1->CheckBox1->Checked) {
        if(win) PlaySound("TaDaSound", HInstance, SND_RESOURCE);
        else    PlaySound("Loser", HInstance, SND_RESOURCE);
    }

    Label3->Caption = " You Scored: " + AnsiString(score);
    Label3->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TGameOverForm1::Button1Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

