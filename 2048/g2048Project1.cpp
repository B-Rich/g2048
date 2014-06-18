//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
// The 2048 Game                                            g2048Project1.cpp
// Donnaware International LLC, no rights reserved, so copy away assholes.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("g2048Unit1.cpp", Form1);
USEFORM("GameOverUnit1.cpp", GameOverForm1);
USEFORM("SetOptionUnit1.cpp", SetOptionForm1);
USEFORM("TopScoresUnit1.cpp", TopScoresForm1);
USEFORM("HelpUnit1.cpp", HelpForm1);
USEFORM("AboutUnit1.cpp", AboutForm1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->Title = "The 2048 Game";
         Application->CreateForm(__classid(TForm1), &Form1);
         Application->CreateForm(__classid(TGameOverForm1), &GameOverForm1);
         Application->CreateForm(__classid(TSetOptionForm1), &SetOptionForm1);
         Application->CreateForm(__classid(TTopScoresForm1), &TopScoresForm1);
         Application->CreateForm(__classid(THelpForm1), &HelpForm1);
         Application->CreateForm(__classid(TAboutForm1), &AboutForm1);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    catch (...)
    {
         try
         {
             throw Exception("");
         }
         catch (Exception &exception)
         {
             Application->ShowException(&exception);
         }
    }
    return 0;
}
//---------------------------------------------------------------------------
