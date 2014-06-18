//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// The 2048 Game                                                HelpUnit1.cpp
// Donnaware International LLC, no rights reserved, so copy away assholes.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "HelpUnit1.h"
#include "g2048Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
THelpForm1 *HelpForm1;
//---------------------------------------------------------------------------
__fastcall THelpForm1::THelpForm1(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THelpForm1::FormShow(TObject *Sender)
{
    Top  = Form1->Panel1->ClientOrigin.y;
    Left = Form1->Panel1->ClientOrigin.x;
}
//---------------------------------------------------------------------------

