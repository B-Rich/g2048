//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// The 2048 Game                                             SetOptionUnit1.h
// Donnaware International LLC, no rights reserved, so copy away assholes.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef SetOptionUnit1H
#define SetOptionUnit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TSetOptionForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TLabel *Label1;
    TLabel *Label2;
    TEdit *Edit1;
    TUpDown *UpDown1;
    TCheckBox *CheckBox1;
    TButton *Button1;
    TCheckBox *CheckBox2;
    void __fastcall UpDown1Changing(TObject *Sender, bool &AllowChange);
    void __fastcall FormShow(TObject *Sender);

private:	// User declarations

public:		// User declarations

    short winum;

    __fastcall TSetOptionForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSetOptionForm1 *SetOptionForm1;
//---------------------------------------------------------------------------
#endif
