//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "edit.h"
#include "MAPI.hpp"
#include <shfolder.h>
#include "Unit2.h"

#define sUntitled   1
#define sOverwrite  2
#define sSendError  3

#include "ShellApi.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TForm1 *Form1;

int flag = 0;

//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

//------------------------���������---------------------------------------------------

void __fastcall TForm1::SBSaveClick(TObject *Sender)
{
        if (StatusBar1->Panels->Items[0]->Text == "��� �����")
	SBSaveAsClick(Sender);
	else
        {
                Memo1->Lines->SaveToFile(StatusBar1->Panels->Items[0]->Text);
                flag = 0;
        }
}

//------------------------�����---------------------------------------------------

void __fastcall TForm1::SBNewClick(TObject *Sender)
{
        if ((Memo1->Lines->Count > 0) && (flag == 1))
	{
	        if (MessageBox(0,"��������� ���������� ���� ��������������? ",
	                        "����������� ����������",MB_YESNO) == IDYES)
	        {
	                SBSaveAsClick(Sender);
	        }
        };
	Memo1->Clear();
        NDefaultClick(Sender);
	StatusBar1->Panels->Items[0]->Text = "��� �����";
}

//------------------------------��������� ���...---------------------------------------------

void __fastcall TForm1::SBSaveAsClick(TObject *Sender)
{
        if (SaveDialog1->Execute())
        {
                Memo1->Lines->SaveToFile(SaveDialog1->FileName + AnsiString(".txt"));
                StatusBar1->Panels->Items[0]->Text = SaveDialog1->FileName;
                flag = 0;
        }
}

//-------------------------�����--------------------------------------------------

void __fastcall TForm1::SBExitClick(TObject *Sender)
{
	Close();
}

//--------------------------�������-------------------------------------------------

void __fastcall TForm1::SBHelpClick(TObject *Sender)
{
        WinExec("hh.exe help.chm", 1);
}

//----------------------------�����-----------------------------------------------

void __fastcall TForm1::NExitClick(TObject *Sender)
{
	Close();
}

//--------------------------�������-------------------------------------------------

void __fastcall TForm1::NCreateClick(TObject *Sender)
{
        if (Memo1->Lines->Count>0)
	{
	        if (MessageBox(0,"��������� ���������� ���� ��������������? ",
	        "����������� ����������",MB_YESNO)==IDYES)
	        {
	                SBSaveClick(Sender);
	        }
	};
	Memo1->Clear();
	StatusBar1->Panels->Items[0]->Text = "��� �����";
}

//-----------------------------�������----------------------------------------------

void __fastcall TForm1::NOpenClick(TObject *Sender)
{
        if ((Memo1->Lines->Count > 0) && (flag == 1))
	{
	        if (MessageBox(0,"��������� ���������� ���� ��������������? ",
	                        "����������� ����������",MB_YESNO) == IDYES)
	        {
	                SBSaveAsClick(Sender);
	        }
        };
        if (OpenDialog1->Execute()) Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
	StatusBar1->Panels->Items[0]->Text = OpenDialog1->FileName;
        flag = 0;
}

//----------------------------���������-----------------------------------------------

void __fastcall TForm1::NSaveClick(TObject *Sender)
{
        if (StatusBar1->Panels->Items[0]->Text == "��� �����")
	SBSaveAsClick(Sender);
	else Memo1->Lines->SaveToFile(StatusBar1->Panels->Items[0]->Text);
}

//----------------------------��������� ���...-----------------------------------------------

void __fastcall TForm1::NSaveAsClick(TObject *Sender)
{
       SBSaveAsClick(Sender);
}

//--------------------------��������-------------------------------------------------

void __fastcall TForm1::NCutClick(TObject *Sender)
{
        Memo1->CutToClipboard();
}

//----------------------�����������-----------------------------------------------------

void __fastcall TForm1::NCopyClick(TObject *Sender)
{
        Memo1->CopyToClipboard();
}

//--------------------------��������-------------------------------------------------

void __fastcall TForm1::NPasteClick(TObject *Sender)
{
        Memo1->PasteFromClipboard();
}

//------------------------������� ���������---------------------------------------------------

void __fastcall TForm1::NDefaultClick(TObject *Sender)
{
        Memo1->Font->Size = 12;
        Memo1->Font->Color = clWindowFrame;
        Memo1->Color = clWindow;
        Memo1->Font->Name = "Times New Roman";
        Memo1->Font->Charset = DEFAULT_CHARSET;
        Memo1->Font->Pitch = fpDefault;
        Memo1->Font->Style = TFontStyles();
}

//-------------------------� ���������--------------------------------------------------

void __fastcall TForm1::NAboutClick(TObject *Sender)
{
        //ShowMessage(AnsiString("������� ��������� ��������. �������� ������ �������� ������ �� - 82. �������� �. �."));
        AboutBox->ShowModal();
}

//----------------------------�����-----------------------------------------------

void __fastcall TForm1::NFontClick(TObject *Sender)
{
        if(FontDialog1->Execute())
                Memo1->Font->Assign(FontDialog1->Font);
}

//-------------------------���--------------------------------------------------

void __fastcall TForm1::NColorClick(TObject *Sender)
{
        if(ColorDialog1->Execute())
                Memo1->Color = ColorDialog1->Color;
}

//-----------------------������----------------------------------------------------

void __fastcall TForm1::NHelpClick(TObject *Sender)
{
        SBHelpClick(Sender);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        if ((Memo1->Lines->Count > 0) && (flag == 1))
	{
	        if (MessageBox(0,"��������� ���������� ���� ��������������? ",
	                        "����������� ����������",MB_YESNO) == IDYES)
	        {
                        if (StatusBar1->Panels->Items[0]->Text == "��� �����") SBSaveAsClick(Sender);
	                else Memo1->Lines->SaveToFile(StatusBar1->Panels->Items[0]->Text);
                }
        }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Memo1Change(TObject *Sender)
{
        flag = 1;        
}

//---------------------------------------------------------------------------


