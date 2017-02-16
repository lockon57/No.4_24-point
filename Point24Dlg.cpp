// Point24Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Point24.h"
#include "Point24Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPoint24Dlg dialog

CPoint24Dlg::CPoint24Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPoint24Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPoint24Dlg)
	m_inputs = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//初始化变量
	m_number1=m_number2=m_number3=m_number4=0;
	m_pattern1=m_pattern2=m_pattern3=m_pattern4=129;
	Step=500;
	m_score=0;
	m_factor=5;
	count=0;

//设置列表框列属性
	lvItem.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_STATE;
	lvItem.state = 0;      
	lvItem.stateMask = 0;  
	lvItem.iImage = 0;
}

void CPoint24Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPoint24Dlg)
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_PROGRESS, m_progress);
	DDX_Control(pDX, IDC_COMBO, m_combo);
	DDX_Control(pDX, IDC_EDIT1, m_input);
	DDX_Text(pDX, IDC_EDIT1, m_inputs);
	DDV_MaxChars(pDX, m_inputs, 15);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPoint24Dlg, CDialog)
	//{{AFX_MSG_MAP(CPoint24Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnStart)
	ON_BN_CLICKED(IDC_INPUT, OnInput)
	ON_BN_CLICKED(IDC_CALC, OnCalc)
	ON_CBN_SELCHANGE(IDC_COMBO, OnSelchangeCombo)
	ON_WM_TIMER()
	ON_COMMAND(IDD_ABOUT, OnAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPoint24Dlg message handlers

BOOL CPoint24Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	//设置组合框选项
	m_combo.InsertString(0,"高级");
	m_combo.InsertString(1,"中级");
	m_combo.InsertString(2,"低级");
	m_combo.SetCurSel(2);

	//设置记录条
	m_progress.SetRange(1,100);
	m_progress.SetStep(2);
	m_progress.SetPos(0);

	//初始化分数
	SetDlgItemText(IDC_CUR_SCORE,"0");

	//设置列表框列属性
	LV_COLUMN lvColumn;
	lvColumn.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	lvColumn.fmt = LVCFMT_CENTER;
	lvColumn.cx = 52;

	//设置列表框列标题
	lvColumn.iSubItem = 0;
	lvColumn.pszText = "题数";
	m_list.InsertColumn(0, &lvColumn);
	lvColumn.iSubItem = 1;
	lvColumn.pszText = "对错";
	m_list.InsertColumn(1, &lvColumn);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPoint24Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPoint24Dlg::OnPaint() 
{
	CPaintDC pDC(this); // device context for painting

	if (IsIconic())
	{

		SendMessage(WM_ICONERASEBKGND, (WPARAM) pDC.GetSafeHdc(), 0);

		// 使图标处于客户矩形的中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 画图标
		pDC.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//显示扑克牌
		CRect rect;
		CBitmap card1,card2,card3,card4,*OldBitMap;
		CDC *dc,dcMem;

		dc=GetDC();
		dcMem.CreateCompatibleDC(&pDC);

		card1.LoadBitmap(m_pattern1);
		OldBitMap=dcMem.SelectObject(&card1);
		dc->BitBlt(50,30,BitmapW,BitmapH,
			       &dcMem,0,0,SRCCOPY);
		dcMem.SelectObject(OldBitMap);
		DeleteObject(&card1);

		card2.LoadBitmap(m_pattern2);
		OldBitMap=dcMem.SelectObject(&card2);
		dc->BitBlt(130,30,BitmapW,BitmapH,
			       &dcMem,0,0,SRCCOPY);
		dcMem.SelectObject(OldBitMap);
		DeleteObject(&card2);

		card3.LoadBitmap(m_pattern3);
		OldBitMap=dcMem.SelectObject(&card3);
		dc->BitBlt(210,30,BitmapW,BitmapH,
			       &dcMem,0,0,SRCCOPY);
		dcMem.SelectObject(OldBitMap);
		DeleteObject(&card3);
		
		card4.LoadBitmap(m_pattern4);
		OldBitMap=dcMem.SelectObject(&card4);
		dc->BitBlt(290,30,BitmapW,BitmapH,
			       &dcMem,0,0,SRCCOPY);
		dcMem.SelectObject(OldBitMap);
		DeleteObject(&card4);
		
		dcMem.DeleteDC();
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPoint24Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//发牌
void CPoint24Dlg::OnStart() 
{
	// TODO: Add your control notification handler code here
    m_progress.SetPos(0);
	m_combo.EnableWindow(FALSE);
	m_number1=((double)rand()/(double)RAND_MAX)*9+1;
	m_number2=((double)rand()/(double)RAND_MAX)*9+1;
	m_number3=((double)rand()/(double)RAND_MAX)*9+1;
	m_number4=((double)rand()/(double)RAND_MAX)*9+1;	
	m_pattern1=130+m_number1;
	m_pattern2=143+m_number2;
	m_pattern3=156+m_number3;
	m_pattern4=169+m_number4;
	m_input.SetReadOnly(TRUE);
	if(m_pattern4>172) m_pattern4+=7;
	UpdateData(FALSE);
	Invalidate(FALSE);

    SetTimer(1, Step, NULL);

	CWnd *pWnd=GetDlgItem(IDC_CALC);
	pWnd->EnableWindow(TRUE);
	pWnd=GetDlgItem(IDC_INPUT);
	pWnd->EnableWindow(TRUE);

	GetDlgItem(IDC_START)->SetWindowText("重新发牌");
}

//输入计算式
void CPoint24Dlg::OnInput() 
{
	// TODO: Add your control notification handler code here
	m_input.SetReadOnly(FALSE);	
//	KillTimer(TRUE);
}

//计算
void CPoint24Dlg::OnCalc() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int result  = m_expression.ChangeExpression(m_inputs);
	if (result<0)
	{
		long result = m_expression.Value(m_Result);
		if (result == DIVISION_BY_0)
			AfxMessageBox("除数不能为零！");

	}
	else 
	{
		AfxMessageBox(_T("你失败了！"));
	}

	m_inputs.Empty();
	if(m_Result==24)
	{
		m_inputs="正确！";
		m_score+=m_factor;
		CString str;
		str.Format("%d",m_score);
		SetDlgItemText(IDC_CUR_SCORE,str);
	}
	else
		m_inputs="错误！";


	char s;
	count+=1;
	wsprintf(&s,"%d",count);
	lvItem.iItem = count-1;
	lvItem.iSubItem = 0;
	lvItem.pszText = &s;
    m_list.InsertItem(&lvItem);
	m_list.SetItemText(count-1, 1, m_inputs);

	UpdateData(FALSE);
	m_inputs=_T("");
//	FirstResult=SecondResult=0;
//	flag='a';
	KillTimer(TRUE);
	m_combo.EnableWindow(TRUE);

	CWnd *pWnd=GetDlgItem(IDC_CALC);
	pWnd->EnableWindow(FALSE);
	pWnd=GetDlgItem(IDC_INPUT);
	pWnd->EnableWindow(FALSE);
}

//选择组合框选项
void CPoint24Dlg::OnSelchangeCombo() 
{
	// TODO: Add your control notification handler code here
	int i=m_combo.GetCurSel();
	if(i=0)
	{
		Step=600;
		m_factor=2;
	}
	if(i=1)
	{
		Step=500;
		m_factor=4;
	}
	if(i=2)
	{
		Step=400;
		m_factor=6;
	}
}

//计时器处理函数
void CPoint24Dlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_progress.StepIt();
	if(m_progress.GetPos()>=100)
	{
		KillTimer(1);
		m_inputs=_T("超时！");
		OnCalc();
	}
	else
		CDialog::OnTimer(nIDEvent);
}

void CPoint24Dlg::OnAbout() 
{
	// TODO: Add your command handler code here
	CAboutDlg dlg;
	dlg.DoModal();
}

