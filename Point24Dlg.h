// Point24Dlg.h : header file
//

#if !defined(AFX_POINT24DLG_H__34309438_3377_11D3_860D_8D751F96C64C__INCLUDED_)
#define AFX_POINT24DLG_H__34309438_3377_11D3_860D_8D751F96C64C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPoint24Dlg dialog

#define BitmapW 70//定义扑克牌的宽度
#define BitmapH 95//定义扑克牌的高度
#include "Express.h"

class CPoint24Dlg : public CDialog
{
// Construction
public:
	CPoint24Dlg(CWnd* pParent = NULL);	// standard constructor

	double	m_Result;//储存计算结果
	int m_number1,m_number2,m_number3,m_number4;//扑克牌的点数
	int m_pattern1,m_pattern2,m_pattern3,m_pattern4;//扑克牌的图案
	int Step;//进度条的步进量
	int m_score;//当前得分
	int m_factor;//分数增量
	int count;//题数
	BOOL IsStart;//是否开始
	LV_ITEM lvItem;//定义列表框的列
	CExpression m_expression;//计算表达式对象

//	void OnCancel();//重载该函数使按Escape无法离开程序
// Dialog Data
	//{{AFX_DATA(CPoint24Dlg)
	enum { IDD = IDD_POINT24_DIALOG };
	CListCtrl	m_list;//列表框控件变量
	CProgressCtrl	m_progress;//进度条控件变量
	CComboBox	m_combo;//组合框控件变量
	CEdit	m_input;//计算式输入编辑框控件变量
	CString	m_inputs;//储存输入表达式
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPoint24Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPoint24Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStart();//发牌
	afx_msg void OnInput();//输入计算式
	afx_msg void OnCalc();//计算
	afx_msg void OnSelchangeCombo();//处理组框选择
	afx_msg void OnTimer(UINT nIDEvent);//处理计时器
	afx_msg void OnAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POINT24DLG_H__34309438_3377_11D3_860D_8D751F96C64C__INCLUDED_)
