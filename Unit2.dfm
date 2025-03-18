object Form2: TForm2
  Left = 0
  Top = 0
  Caption = ' Kruskal'#39's and Prim'#39's by Y.S Chen'
  ClientHeight = 534
  ClientWidth = 901
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Courier New'
  Font.Style = []
  TextHeight = 18
  object Splitter1: TSplitter
    Left = 241
    Top = 0
    Height = 534
    ExplicitLeft = 264
    ExplicitTop = 312
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 241
    Height = 534
    Align = alLeft
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 12
      Width = 70
      Height = 18
      Caption = 'G=(V,E)'
    end
    object Button1: TButton
      Left = 120
      Top = 7
      Width = 97
      Height = 25
      Caption = 'Read G'
      TabOrder = 0
      OnClick = Button1Click
    end
    object GroupBox1: TGroupBox
      Left = 0
      Top = 64
      Width = 242
      Height = 225
      Caption = 'Randomly Generated'
      TabOrder = 1
      object Label2: TLabel
        Left = 10
        Top = 32
        Width = 40
        Height = 18
        Caption = '|V|='
      end
      object Label3: TLabel
        Left = 10
        Top = 64
        Width = 120
        Height = 18
        Caption = 'range(w(e))='
      end
      object Label4: TLabel
        Left = 10
        Top = 96
        Width = 80
        Height = 18
        Caption = 'if w(e)>'
      end
      object Label5: TLabel
        Left = 10
        Top = 128
        Width = 120
        Height = 18
        Caption = 'w(e)=MaxInt('
      end
      object Label6: TLabel
        Left = 204
        Top = 128
        Width = 10
        Height = 18
        Caption = ')'
      end
      object Edit1: TEdit
        Left = 136
        Top = 24
        Width = 62
        Height = 26
        TabOrder = 0
        Text = '12'
      end
      object Edit2: TEdit
        Left = 136
        Top = 56
        Width = 62
        Height = 26
        TabOrder = 1
        Text = '1000'
      end
      object Edit3: TEdit
        Left = 136
        Top = 88
        Width = 62
        Height = 26
        TabOrder = 2
        Text = '500'
      end
      object Edit4: TEdit
        Left = 136
        Top = 120
        Width = 62
        Height = 26
        TabOrder = 3
        Text = '99999'
      end
      object Button2: TButton
        Left = 29
        Top = 165
        Width = 169
        Height = 25
        Caption = 'Genarate'
        TabOrder = 4
        OnClick = Button2Click
      end
    end
    object CheckBox2: TCheckBox
      Left = 37
      Top = 260
      Width = 161
      Height = 17
      Caption = 'Echo print G'
      Checked = True
      State = cbChecked
      TabOrder = 2
    end
    object GroupBox2: TGroupBox
      Left = 0
      Top = 309
      Width = 242
      Height = 264
      Caption = 'MST Solver'
      TabOrder = 3
      object Label7: TLabel
        Left = 29
        Top = 16
        Width = 180
        Height = 18
        Caption = 'Cycle decection by'
      end
      object Button3: TButton
        Left = 3
        Top = 96
        Width = 235
        Height = 25
        Caption = 'Kruskal'#39's algorithm'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Courier New'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
        OnClick = Button3Click
      end
      object Button4: TButton
        Left = 4
        Top = 167
        Width = 235
        Height = 25
        Caption = 'Prim'#39's algorithm'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Courier New'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        OnClick = Button4Click
      end
      object RadioButton1: TRadioButton
        Left = 10
        Top = 40
        Width = 113
        Height = 17
        Caption = 'Loop'
        TabOrder = 2
      end
      object RadioButton2: TRadioButton
        Left = 122
        Top = 40
        Width = 113
        Height = 17
        Caption = 'UnionFind'
        Checked = True
        TabOrder = 3
        TabStop = True
      end
    end
  end
  object PageControl1: TPageControl
    Left = 244
    Top = 0
    Width = 657
    Height = 534
    ActivePage = TabSheet2
    Align = alClient
    TabOrder = 1
    object TabSheet2: TTabSheet
      Caption = 'Matrix'
      ImageIndex = 1
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 649
        Height = 501
        Align = alClient
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'MST found'
      ImageIndex = 2
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 653
        Height = 502
        Align = alClient
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Courier New'
        Font.Style = []
        Lines.Strings = (
          'Memo2')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Edges matrix'
      ImageIndex = 3
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 657
        Height = 503
        Align = alClient
        TabOrder = 0
      end
    end
  end
end
