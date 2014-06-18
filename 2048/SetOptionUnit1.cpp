//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// The 2048 Game                                           SetOptionUnit1.cpp
// Donnaware International LLC, no rights reserved, so copy away assholes.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "SetOptionUnit1.h"
#include "g2048Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSetOptionForm1 *SetOptionForm1;
//---------------------------------------------------------------------------
__fastcall TSetOptionForm1::TSetOptionForm1(TComponent* Owner) : TForm(Owner)
{
    winum = 2048;
}
//---------------------------------------------------------------------------
void __fastcall TSetOptionForm1::FormShow(TObject *Sender)
{
    Top  = Form1->Panel1->ClientOrigin.y;
    Left = Form1->Panel1->ClientOrigin.x;
}
//---------------------------------------------------------------------------
void __fastcall TSetOptionForm1::UpDown1Changing(TObject *Sender, bool &AllowChange)
{
    winum = 1 << UpDown1->Position;
    Edit1->Text = AnsiString(winum);
}
//---------------------------------------------------------------------------

