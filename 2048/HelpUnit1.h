//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// The 2048 Game                                                  HelpUnit1.h
// Donnaware International LLC, no rights reserved, so copy away assholes.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef HelpUnit1H
#define HelpUnit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class THelpForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TLabel *Label2;
    TLabel *Label1;
    TLabel *Label3;
    TImage *Image1;
    TButton *Button1;
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall THelpForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE THelpForm1 *HelpForm1;
//---------------------------------------------------------------------------
#endif
