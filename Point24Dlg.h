// Point24Dlg.h : header file
//

#if !defined(AFX_POINT24DLG_H__34309438_3377_11D3_860D_8D751F96C64C__INCLUDED_)
#define AFX_POINT24DLG_H__34309438_3377_11D3_860D_8D751F96C64C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPoint24Dlg dialog

#define BitmapW 70//�����˿��ƵĿ��
#define BitmapH 95//�����˿��Ƶĸ߶�
#include "Express.h"

class CPoint24Dlg : public CDialog
{
// Construction
public:
	CPoint24Dlg(CWnd* pParent = NULL);	// standard constructor

	double	m_Result;//���������
	int m_number1,m_number2,m_number3,m_number4;//�˿��Ƶĵ���
	int m_pattern1,m_pattern2,m_pattern3,m_pattern4;//�˿��Ƶ�ͼ��
	int Step;//�������Ĳ�����
	int m_score;//��ǰ�÷�
	int m_factor;//��������
	int count;//����
	BOOL IsStart;//�Ƿ�ʼ
	LV_ITEM lvItem;//�����б�����
	CExpression m_expression;//������ʽ����

//	void OnCancel();//���ظú���ʹ��Escape�޷��뿪����
// Dialog Data
	//{{AFX_DATA(CPoint24Dlg)
	enum { IDD = IDD_POINT24_DIALOG };
	CListCtrl	m_list;//�б��ؼ�����
	CProgressCtrl	m_progress;//�������ؼ�����
	CComboBox	m_combo;//��Ͽ�ؼ�����
	CEdit	m_input;//����ʽ����༭��ؼ�����
	CString	m_inputs;//����������ʽ
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
	afx_msg void OnStart();//����
	afx_msg void OnInput();//�������ʽ
	afx_msg void OnCalc();//����
	afx_msg void OnSelchangeCombo();//�������ѡ��
	afx_msg void OnTimer(UINT nIDEvent);//�����ʱ��
	afx_msg void OnAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POINT24DLG_H__34309438_3377_11D3_860D_8D751F96C64C__INCLUDED_)
