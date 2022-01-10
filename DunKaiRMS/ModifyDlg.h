#pragma once


// CModifyDlg 对话框

class CModifyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CModifyDlg)

public:
	CModifyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CModifyDlg();

// 对话框数据
	enum { IDD = IDD_MODIFY_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	int m_nWorkNum;
	CString m_strName;
	int m_nSex;
	int m_nAge;
	BOOL m_bPaoniu;
	BOOL m_bPashan;
	BOOL m_bKsing;
	BOOL m_bGame;
	BOOL m_bBook;
	CComboBox m_department;
	CString m_strDepartment;
	CComboBox m_position;
	CString m_strPosition;
	float m_fTempSalary;
	float m_fRegularSalary;
	COleDateTime m_joinTime;
	COleDateTime m_officialTime;
	COleDateTime m_leaveTime;
	CString m_tel;
	CString m_strAddress;
	afx_msg void OnBnClickedBtnModify();
	virtual BOOL OnInitDialog();
};
