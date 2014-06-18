//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// The 2048 Game                                              GameOverUnit1.h
// Donnaware International LLC, no rights reserved, so copy away assholes.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef GameOverUnit1H
#define GameOverUnit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TGameOverForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TLabel *Label1;
    TLabel *Label2;
    TImage *Image1;
    TButton *Button1;
    TLabel *Label3;
    TImage *Image2;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);

private:	// User declarations

public:		// User declarations

    void __fastcall ShowMsg(AnsiString Message, long long score, bool win);


    __fastcall TGameOverForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGameOverForm1 *GameOverForm1;
//---------------------------------------------------------------------------
#endif
