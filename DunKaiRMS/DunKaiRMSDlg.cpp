
// DunKaiRMSDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DunKaiRMS.h"
#include "DunKaiRMSDlg.h"
#include "afxdialogex.h"
#include "AddDlg.h"
#include "ModifyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDunKaiRMSDlg �Ի���



CDunKaiRMSDlg::CDunKaiRMSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDunKaiRMSDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDunKaiRMSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDunKaiRMSDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BTN_ADD, &CDunKaiRMSDlg::OnBnClickedBtnAdd)
	ON_BN_CLICKED(IDC_BTN_DEL, &CDunKaiRMSDlg::OnBnClickedBtnDel)
	ON_BN_CLICKED(IDC_BTN_MODIFY, &CDunKaiRMSDlg::OnBnClickedBtnModify)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDunKaiRMSDlg ��Ϣ�������

BOOL CDunKaiRMSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	m_frameDlg.Create(IDD_FRAME_DLG, this);

	//��ȡ�ͻ����Ŀ�͸�
	CRect rect;
	GetClientRect(&rect);
	m_frameDlg.MoveWindow(100, 100, rect.Width()-100-15, rect.Height()-100-15);
	m_frameDlg.ShowWindow(SW_SHOW);


	//ѭ����ȡ�ļ�
	CFile file;
	if (FALSE == file.Open(L"DKRMS.dat", CFile::modeRead))
	{
		MessageBox(L"�ļ���ʧ��");
		return TRUE;
	}

	Staff staff = {0};
	int i = 0;
	while (file.Read(&staff, sizeof(staff)))
	{
		CString str;
		str.Format(L"%d", staff.worknum);
		m_frameDlg.m_list.InsertItem(i, str);
		m_frameDlg.m_list.SetItemText(i, 1, staff.name);

		i++;
	}

	file.Close();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDunKaiRMSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDunKaiRMSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDunKaiRMSDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (m_frameDlg.GetSafeHwnd())
	{
		//��ȡ�ͻ����Ŀ�͸�
		CRect rect;
		GetClientRect(&rect);
		m_frameDlg.MoveWindow(100, 100, rect.Width() - 100 - 15, rect.Height() - 100 - 15);

	}
}

//���Ա��
void CDunKaiRMSDlg::OnBnClickedBtnAdd()
{
	CAddDlg dlg;
	if (IDCANCEL == dlg.DoModal())
	{
		return;
	}

	//��ȡ�б�������
	int nCount = this->m_frameDlg.m_list.GetItemCount();

	//����������ӵ��б���
	CString str;
	str.Format(L"%05d", dlg.m_nWorkNum);	
	this->m_frameDlg.m_list.InsertItem(nCount, str);

	//����
	this->m_frameDlg.m_list.SetItemText(nCount, 1, dlg.m_strName);

	//�Ա�
	str = dlg.m_nSex ? L"Ů" : L"��";
	this->m_frameDlg.m_list.SetItemText(nCount, 2, str);

	//����
	str.Format(L"%d", dlg.m_nAge);
	this->m_frameDlg.m_list.SetItemText(nCount, 3, str);

	//��Ȥ
	str.Empty();
	if (dlg.m_bPaoniu)
		str += L"���;";
	if (dlg.m_bPashan)
		str += L"��ɽ;";
	if (dlg.m_bKsing)
		str += L"K��;";
	if (dlg.m_bGame)
		str += L"����Ϸ;";
	if (dlg.m_bBook)
		str += L"����;";
	this->m_frameDlg.m_list.SetItemText(nCount, 4, str);

	//����	
	this->m_frameDlg.m_list.SetItemText(nCount, 5, dlg.m_strDepartment);

	//ְλ
	this->m_frameDlg.m_list.SetItemText(nCount, 6, dlg.m_strPosition);

	//����н��
	str.Format(L"%.2f", dlg.m_fTempSalary);
	this->m_frameDlg.m_list.SetItemText(nCount, 7, str);

	//ת��н��
	str.Format(L"%.2f", dlg.m_fRegularSalary);
	this->m_frameDlg.m_list.SetItemText(nCount, 8, str);

	//��ְʱ��
	str = dlg.m_joinTime.Format(L"%Y-%m-%d");
	this->m_frameDlg.m_list.SetItemText(nCount, 9, str);

	//ת��ʱ��
	str = dlg.m_officialTime.Format(L"%Y-%m-%d");
	this->m_frameDlg.m_list.SetItemText(nCount, 10, str);

	//��ְʱ��
	str = dlg.m_leaveTime.Format(L"%Y-%m-%d");
	this->m_frameDlg.m_list.SetItemText(nCount, 11, str);

	//��ϵ�绰
	this->m_frameDlg.m_list.SetItemText(nCount, 12, dlg.m_tel);

	//��ͥסַ
	this->m_frameDlg.m_list.SetItemText(nCount, 13, dlg.m_strAddress);
}

//ɾ��Ա��
void CDunKaiRMSDlg::OnBnClickedBtnDel()
{
	POSITION pos =  m_frameDlg.m_list.GetFirstSelectedItemPosition();
	int nSel = m_frameDlg.m_list.GetNextSelectedItem(pos);
	if (nSel < 0)
	{
		MessageBox(L"������ѡ��֮����ɾ��");
		return;
	}

	m_frameDlg.m_list.DeleteItem(nSel);

	//ɾ������
	//m_frameDlg.m_list.DeleteAllItems();
}

//�޸�Ա����Ϣ
void CDunKaiRMSDlg::OnBnClickedBtnModify()
{
	POSITION pos = m_frameDlg.m_list.GetFirstSelectedItemPosition();
	int nSel = m_frameDlg.m_list.GetNextSelectedItem(pos);
	if (nSel < 0)
	{
		MessageBox(L"������ѡ��֮�����޸�");
		return;
	}

	CModifyDlg dlg;
	//����
	dlg.m_nWorkNum = _wtoi(m_frameDlg.m_list.GetItemText(nSel, 0));
	//����
	dlg.m_strName = m_frameDlg.m_list.GetItemText(nSel, 1);
	//�Ա�
	if (m_frameDlg.m_list.GetItemText(nSel, 2) == L"��")
		dlg.m_nSex = 0;
	else
		dlg.m_nSex = 1;
	//����
	dlg.m_nAge = _wtoi(m_frameDlg.m_list.GetItemText(nSel, 3));
	//��Ȥ����
	dlg.m_bPaoniu = FALSE, dlg.m_bPashan = FALSE, dlg.m_bKsing = FALSE, dlg.m_bGame = FALSE, dlg.m_bBook = FALSE;
	CString strInterest = m_frameDlg.m_list.GetItemText(nSel, 4);
	if (strInterest.Find(L"���;") != -1)
	{
		dlg.m_bPaoniu = TRUE;
	}
	if (strInterest.Find(L"��ɽ;") != -1)
	{
		dlg.m_bPashan = TRUE;
	}
	if (strInterest.Find(L"K��;") != -1)
	{
		dlg.m_bKsing = TRUE;
	}
	if (strInterest.Find(L"����Ϸ;") != -1)
	{
		dlg.m_bGame = TRUE;
	}
	if (strInterest.Find(L"����;") != -1)
	{
		dlg.m_bBook = TRUE;
	}
	//����
	dlg.m_strDepartment = m_frameDlg.m_list.GetItemText(nSel, 5);
	//���ò�����ʾ
	//dlg.m_department.SetWindowText(dlg.m_strDepartment);
	//ְλ
	dlg.m_strPosition = m_frameDlg.m_list.GetItemText(nSel, 6);
	//���ò�����ʾ  ��ʱ���ڳ�ʼ�����ڻ�û���������Բ����ÿؼ�
	//dlg.m_position.SetWindowText(dlg.m_strPosition);
	//����н��
	dlg.m_fTempSalary = _wtof(m_frameDlg.m_list.GetItemText(nSel, 7));
	//ת��н��
	dlg.m_fRegularSalary = _wtof(m_frameDlg.m_list.GetItemText(nSel, 8));
	//��ְʱ��
	dlg.m_joinTime.ParseDateTime(m_frameDlg.m_list.GetItemText(nSel, 9));
	//ת��ʱ��
	dlg.m_officialTime.ParseDateTime(m_frameDlg.m_list.GetItemText(nSel, 10));
	//��ְʱ��
	dlg.m_leaveTime.ParseDateTime(m_frameDlg.m_list.GetItemText(nSel, 11));
	//��ϵ�绰
	dlg.m_tel = m_frameDlg.m_list.GetItemText(nSel, 12);
	//��ͥסַ
	dlg.m_strAddress = m_frameDlg.m_list.GetItemText(nSel, 13);

	//����Ҫ��Update����Ϊ����Ի��򻹻��ٳ�ʼ��һ��
	if (IDCANCEL == dlg.DoModal())
	{
		return;
	}
	

	//����������ӵ��б���
	CString str;
	str.Format(L"%05d", dlg.m_nWorkNum);
	this->m_frameDlg.m_list.SetItemText(nSel, 0, str);

	//����
	this->m_frameDlg.m_list.SetItemText(nSel, 1, dlg.m_strName);

	//�Ա�
	str = dlg.m_nSex ? L"Ů" : L"��";
	this->m_frameDlg.m_list.SetItemText(nSel, 2, str);

	//����
	str.Format(L"%d", dlg.m_nAge);
	this->m_frameDlg.m_list.SetItemText(nSel, 3, str);

	//��Ȥ
	str.Empty();
	if (dlg.m_bPaoniu)
		str += L"���;";
	if (dlg.m_bPashan)
		str += L"��ɽ;";
	if (dlg.m_bKsing)
		str += L"K��;";
	if (dlg.m_bGame)
		str += L"����Ϸ;";
	if (dlg.m_bBook)
		str += L"����;";
	this->m_frameDlg.m_list.SetItemText(nSel, 4, str);

	//����	
	this->m_frameDlg.m_list.SetItemText(nSel, 5, dlg.m_strDepartment);

	//ְλ
	this->m_frameDlg.m_list.SetItemText(nSel, 6, dlg.m_strPosition);

	//����н��
	str.Format(L"%.2f", dlg.m_fTempSalary);
	this->m_frameDlg.m_list.SetItemText(nSel, 7, str);

	//ת��н��
	str.Format(L"%.2f", dlg.m_fRegularSalary);
	this->m_frameDlg.m_list.SetItemText(nSel, 8, str);

	//��ְʱ��
	str = dlg.m_joinTime.Format(L"%Y-%m-%d");
	this->m_frameDlg.m_list.SetItemText(nSel, 9, str);

	//ת��ʱ��
	str = dlg.m_officialTime.Format(L"%Y-%m-%d");
	this->m_frameDlg.m_list.SetItemText(nSel, 10, str);

	//��ְʱ��
	str = dlg.m_leaveTime.Format(L"%Y-%m-%d");
	this->m_frameDlg.m_list.SetItemText(nSel, 11, str);

	//��ϵ�绰
	this->m_frameDlg.m_list.SetItemText(nSel, 12, dlg.m_tel);

	//��ͥסַ
	this->m_frameDlg.m_list.SetItemText(nSel, 13, dlg.m_strAddress);

}


void CDunKaiRMSDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	//���ļ�
	CFile file;
	if (FALSE == file.Open(L"DKRMS.dat", CFile::modeCreate | CFile::modeWrite))
	{
		MessageBox(L"���ļ�ʧ��");
		return;
	}

	//��ȡ������
	int nCount = m_frameDlg.m_list.GetItemCount();
	for (int i = 0; i < nCount;i++)
	{
		Staff staff = {0};

		//����
		staff.worknum = _wtoi(m_frameDlg.m_list.GetItemText(i, 0));
		//����
		wcscpy(staff.name ,m_frameDlg.m_list.GetItemText(i, 1));
		//�Ա�
		wcscpy(staff.sex, m_frameDlg.m_list.GetItemText(i, 2));
		//����
		staff.age = _wtoi(m_frameDlg.m_list.GetItemText(i, 3));
		//��Ȥ����
		wcscpy(staff.interest, m_frameDlg.m_list.GetItemText(i, 4));
		//����
		wcscpy(staff.department,  m_frameDlg.m_list.GetItemText(i, 5));
		//���ò�����ʾ
		//dlg.m_department.SetWindowText(dlg.m_strDepartment);
		//ְλ
		wcscpy(staff.position , m_frameDlg.m_list.GetItemText(i, 6));
		//���ò�����ʾ
		//dlg.m_position.SetWindowText(dlg.m_strPosition);
		//����н��
		staff.tempSalary = _wtof(m_frameDlg.m_list.GetItemText(i, 7));
		//ת��н��
		staff.regularSalary = _wtof(m_frameDlg.m_list.GetItemText(i, 8));
		//��ְʱ��
		wcscpy(staff.joinTime,m_frameDlg.m_list.GetItemText(i, 9));
		//ת��ʱ��
		wcscpy(staff.officialTime,m_frameDlg.m_list.GetItemText(i, 10));
		//��ְʱ��
		wcscpy(staff.leaveTime,m_frameDlg.m_list.GetItemText(i, 11));
		//��ϵ�绰
		wcscpy(staff.tel, m_frameDlg.m_list.GetItemText(i, 12));
		//��ͥסַ
		wcscpy(staff.address, m_frameDlg.m_list.GetItemText(i, 13));


		file.Write(&staff, sizeof(staff));
	}

	file.Close();

	// TODO:  �ڴ˴������Ϣ����������
}
