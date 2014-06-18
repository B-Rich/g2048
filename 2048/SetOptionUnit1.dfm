object SetOptionForm1: TSetOptionForm1
  Left = 360
  Top = 475
  BorderStyle = bsNone
  Caption = ' Set Options'
  ClientHeight = 290
  ClientWidth = 250
  Color = 10530235
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDefault
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 250
    Height = 290
    Align = alClient
    Alignment = taRightJustify
    Color = 15726842
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 6716047
    Font.Height = -15
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    object Label1: TLabel
      Left = 1
      Top = 37
      Width = 136
      Height = 16
      Alignment = taCenter
      AutoSize = False
      Caption = 'Winning Number:'
      WordWrap = True
    end
    object Label2: TLabel
      Left = 1
      Top = 1
      Width = 248
      Height = 19
      Align = alTop
      Alignment = taCenter
      AutoSize = False
      Caption = 'Set Options'
      Color = 6716047
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 15922937
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 137
      Top = 35
      Width = 46
      Height = 23
      AutoSize = False
      ReadOnly = True
      TabOrder = 0
      Text = '2048'
    end
    object UpDown1: TUpDown
      Left = 183
      Top = 35
      Width = 17
      Height = 23
      Min = 3
      Max = 12
      Position = 11
      TabOrder = 1
      Thousands = False
      Wrap = False
      OnChanging = UpDown1Changing
    end
    object CheckBox1: TCheckBox
      Left = 20
      Top = 69
      Width = 130
      Height = 14
      Alignment = taLeftJustify
      Caption = ' Sound Effects:'
      TabOrder = 2
    end
    object Button1: TButton
      Left = 94
      Top = 255
      Width = 61
      Height = 20
      Caption = 'OK'
      Default = True
      ModalResult = 1
      TabOrder = 3
    end
    object CheckBox2: TCheckBox
      Left = 40
      Top = 101
      Width = 110
      Height = 14
      Alignment = taLeftJustify
      Caption = ' Key Clicks:'
      TabOrder = 4
    end
  end
end
