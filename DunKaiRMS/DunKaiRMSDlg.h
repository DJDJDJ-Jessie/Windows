
// DunKaiRMSDlg.h : 头文件
//

#pragma once
#include "FrameDlg.h"

// CDunKaiRMSDlg 对话框
class CDunKaiRMSDlg : public CDialogEx
{
// 构造
public:
	CDunKaiRMSDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DUNKAIRMS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;
	CFrameDlg m_frameDlg;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnDel();
	afx_msg void OnBnClickedBtnModify();
	afx_msg void OnDestroy();
};
