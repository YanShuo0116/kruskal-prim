//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TSplitter *Splitter1;
	TPageControl *PageControl1;
	TLabel *Label1;
	TButton *Button1;
	TGroupBox *GroupBox1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TButton *Button2;
	TTabSheet *TabSheet2;
	TTabSheet *TabSheet3;
	TStringGrid *StringGrid1;
	TButton *Button3;
	TButton *Button4;
	TCheckBox *CheckBox2;
	TGroupBox *GroupBox2;
	TTabSheet *TabSheet4;
	TStringGrid *StringGrid2;
	TMemo *Memo2;
	TLabel *Label7;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations

public:		// User declarations
	__fastcall TForm2(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
