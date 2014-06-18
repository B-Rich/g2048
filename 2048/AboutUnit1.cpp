//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "AboutUnit1.h"
#include "g2048Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAboutForm1 *AboutForm1;
//---------------------------------------------------------------------------
__fastcall TAboutForm1::TAboutForm1(TComponent* Owner) : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAboutForm1::FormShow(TObject *Sender)
{
    Top  = Form1->Panel1->ClientOrigin.y;
    Left = Form1->Panel1->ClientOrigin.x;

}
//---------------------------------------------------------------------------
