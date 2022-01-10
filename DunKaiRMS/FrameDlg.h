#pragma once
#include "afxcmn.h"


// CFrameDlg 对话框

class CFrameDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFrameDlg)

public:
	CFrameDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFrameDlg();

// 对话框数据
	enum { IDD = IDD_FRAME_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CListCtrl m_list;
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
