object Form1: TForm1
  Left = 352
  Top = 129
  AutoScroll = False
  Caption = ' 2048 Game'
  ClientHeight = 301
  ClientWidth = 250
  Color = 15726842
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PopupMenu = PopupMenu1
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 250
    Height = 301
    Align = alClient
    BevelOuter = bvNone
    Color = 15726842
    TabOrder = 0
    object GamePanel1: TPanel
      Left = 8
      Top = 7
      Width = 233
      Height = 233
      Color = 10530235
      TabOrder = 0
      object Panel3: TPanel
        Tag = 2
        Left = 64
        Top = 8
        Width = 49
        Height = 49
        Caption = '4'
        Color = 13164781
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6647415
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
      end
      object Panel4: TPanel
        Tag = 3
        Left = 120
        Top = 8
        Width = 49
        Height = 49
        Caption = '8'
        Color = 7975410
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6647415
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
      end
      object Panel5: TPanel
        Tag = 4
        Left = 176
        Top = 8
        Width = 49
        Height = 49
        Caption = '16'
        Color = 6526453
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6647415
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
      end
      object Panel2: TPanel
        Tag = 1
        Left = 8
        Top = 8
        Width = 49
        Height = 49
        Caption = '2'
        Color = 14345454
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6647415
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 3
      end
      object Panel6: TPanel
        Tag = 5
        Left = 8
        Top = 64
        Width = 49
        Height = 49
        Caption = '64'
        Color = 3890934
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 15922937
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
      end
      object Panel7: TPanel
        Tag = 6
        Left = 64
        Top = 64
        Width = 49
        Height = 49
        Caption = '128'
        Color = 7524333
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 15922937
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
      end
      object Panel8: TPanel
        Tag = 7
        Left = 120
        Top = 64
        Width = 49
        Height = 49
        Caption = '256'
        Color = 6409453
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 15922937
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 6
      end
      object Panel9: TPanel
        Tag = 8
        Left = 176
        Top = 64
        Width = 49
        Height = 49
        Caption = '512'
        Color = 5294317
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 15922937
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 7
      end
      object Panel10: TPanel
        Tag = 9
        Left = 8
        Top = 120
        Width = 49
        Height = 49
        Caption = '1024'
        Color = 4179437
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 15922937
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 8
      end
      object Panel11: TPanel
        Tag = 10
        Left = 64
        Top = 120
        Width = 49
        Height = 49
        Caption = '2048'
        Color = 3064557
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 15922937
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 9
      end
      object Panel12: TPanel
        Tag = 11
        Left = 120
        Top = 120
        Width = 49
        Height = 49
        Color = 12635611
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6647415
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 10
      end
      object Panel13: TPanel
        Tag = 12
        Left = 176
        Top = 120
        Width = 49
        Height = 49
        Color = 12635611
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6647415
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 11
      end
      object Panel14: TPanel
        Tag = 13
        Left = 8
        Top = 176
        Width = 49
        Height = 49
        Color = 12635611
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6647415
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 12
      end
      object Panel15: TPanel
        Tag = 14
        Left = 64
        Top = 176
        Width = 49
        Height = 49
        Color = 12635611
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6647415
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 13
      end
      object Panel16: TPanel
        Tag = 15
        Left = 120
        Top = 176
        Width = 49
        Height = 49
        Color = 12635611
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6647415
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 14
      end
      object Panel17: TPanel
        Tag = 16
        Left = 176
        Top = 176
        Width = 49
        Height = 49
        Color = 12635611
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 6647415
        Font.Height = -16
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 15
      end
    end
    object Panel18: TPanel
      Left = 8
      Top = 246
      Width = 121
      Height = 42
      BevelOuter = bvLowered
      Color = 10530235
      TabOrder = 1
      object ScoreLabel1: TLabel
        Left = 8
        Top = 20
        Width = 105
        Height = 13
        Alignment = taCenter
        AutoSize = False
        Caption = '0'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 14345454
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object StaticText1: TStaticText
        Left = 1
        Top = 1
        Width = 119
        Height = 14
        Align = alTop
        Alignment = taCenter
        AutoSize = False
        BevelInner = bvLowered
        Caption = 'SCORE'
        Color = 10530235
        Font.Charset = DEFAULT_CHARSET
        Font.Color = 14345454
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentColor = False
        ParentFont = False
        TabOrder = 0
      end
    end
    object NewGameButton1: TPanel
      Left = 136
      Top = 245
      Width = 105
      Height = 41
      BevelInner = bvRaised
      BevelOuter = bvNone
      Caption = 'New Game'
      Color = 6716047
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 15922937
      Font.Height = -15
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = NewGameButton1Click
    end
    object LeftPanel1: TPanel
      Left = 0
      Top = 8
      Width = 7
      Height = 280
      Align = alLeft
      BevelOuter = bvNone
      Color = 15266032
      TabOrder = 3
      OnClick = LeftPanel1Click
    end
    object TopPanel1: TPanel
      Left = 0
      Top = 0
      Width = 250
      Height = 8
      Align = alTop
      BevelOuter = bvNone
      Color = 15266032
      TabOrder = 4
      OnClick = TopPanel1Click
    end
    object RightPanel1: TPanel
      Left = 243
      Top = 8
      Width = 7
      Height = 280
      Align = alRight
      BevelOuter = bvNone
      Color = 15266032
      TabOrder = 5
      OnClick = RightPanel1Click
    end
    object BottomPanel1: TPanel
      Left = 0
      Top = 288
      Width = 250
      Height = 13
      Align = alBottom
      BevelOuter = bvNone
      Caption = 'Donnaware International LLC- No Rights Reserved'
      Color = 15266032
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 12635611
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      OnClick = BottomPanel1Click
    end
  end
  object PopupMenu1: TPopupMenu
    MenuAnimation = [maLeftToRight, maTopToBottom]
    object NewGame1: TMenuItem
      AutoHotkeys = maAutomatic
      Caption = '&New Game'
      OnClick = NewGame1Click
    end
    object Options1: TMenuItem
      Caption = '&Options...'
      OnClick = Options1Click
    end
    object Scores1: TMenuItem
      Caption = '&Show High Scores...'
      OnClick = Scores1Click
    end
    object Undo1: TMenuItem
      Caption = '&Undo'
      OnClick = Undo1Click
    end
    object Help1: TMenuItem
      Caption = '&Help...'
      OnClick = Help1Click
    end
    object About1: TMenuItem
      Caption = 'About...'
      OnClick = About1Click
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object Quit1: TMenuItem
      Caption = '&Quit'
      OnClick = Quit1Click
    end
  end
end
