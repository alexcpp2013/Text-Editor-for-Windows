//---------------------------------------------------------------------------

#ifndef editH
#define editH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ToolWin.hpp>

#include <vcl\ComCtrls.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Dialogs.hpp>
#include <vcl\Menus.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include "trayicon.h"

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TStatusBar *StatusBar1;
        TSaveDialog *SaveDialog1;
        TOpenDialog *OpenDialog1;
        TMemo *Memo1;
        TToolBar *ToolBar1;
        TSpeedButton *SBSave;
        TSpeedButton *SBNew;
        TSpeedButton *SBSaveAs;
        TMainMenu *MainMenu1;
        TSpeedButton *SBExit;
        TSpeedButton *SBHelp;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TMenuItem *N4;
        TMenuItem *NHelp;
        TMenuItem *NAbout;
        TMenuItem *NCreate;
        TMenuItem *NOpen;
        TMenuItem *NSave;
        TMenuItem *NSaveAs;
        TMenuItem *NExit;
        TMenuItem *NCut;
        TMenuItem *NCopy;
        TMenuItem *NPaste;
        TMenuItem *NFont;
        TMenuItem *NDefault;
        TFontDialog *FontDialog1;
        TColorDialog *ColorDialog1;
        TMenuItem *NColor;
        //TTrayIcon *TrayIcon1;
        //TPopupMenu *PopupMenu1;
        //TMenuItem *NVisible;
        //TMenuItem *N_Close;
        //TButton *BHide;
        void __fastcall SBSaveClick(TObject *Sender);
        void __fastcall SBNewClick(TObject *Sender);
        void __fastcall SBSaveAsClick(TObject *Sender);
        void __fastcall SBExitClick(TObject *Sender);
        void __fastcall SBHelpClick(TObject *Sender);
        void __fastcall NExitClick(TObject *Sender);
        void __fastcall NCreateClick(TObject *Sender);
        void __fastcall NOpenClick(TObject *Sender);
        void __fastcall NSaveClick(TObject *Sender);
        void __fastcall NSaveAsClick(TObject *Sender);
        void __fastcall NCutClick(TObject *Sender);
        void __fastcall NCopyClick(TObject *Sender);
        void __fastcall NPasteClick(TObject *Sender);
        void __fastcall NDefaultClick(TObject *Sender);
        void __fastcall NAboutClick(TObject *Sender);
        void __fastcall NFontClick(TObject *Sender);
        void __fastcall NColorClick(TObject *Sender);
        void __fastcall NHelpClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Memo1Change(TObject *Sender);
        //void __fastcall NVisibleClick(TObject *Sender);
        //void __fastcall NHideClick(TObject *Sender);
        //void __fastcall N_CloseClick(TObject *Sender);
        //void __fastcall BHideClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
