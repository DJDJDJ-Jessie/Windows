#pragma once
#include "afxcmn.h"


// CFrameDlg �Ի���

class CFrameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFrameDlg)

public:
	CFrameDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFrameDlg();

// �Ի�������
	enum { IDD = IDD_FRAME_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CListCtrl m_list;
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
