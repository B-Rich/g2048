//---------------------------------------------------------------------------
#ifndef AboutUnit1H
#define AboutUnit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TAboutForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TLabel *Label2;
    TLabel *Label3;
    TImage *Image1;
    TButton *Button1;
    TLabel *Label4;
    void __fastcall FormShow(TObject *Sender);

private:	// User declarations

public:		// User declarations

    __fastcall TAboutForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAboutForm1 *AboutForm1;
//---------------------------------------------------------------------------
#endif
