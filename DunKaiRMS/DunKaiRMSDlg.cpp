
// DunKaiRMSDlg.cpp : 实现文件
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


// CDunKaiRMSDlg 对话框



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


// CDunKaiRMSDlg 消息处理程序

BOOL CDunKaiRMSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	m_frameDlg.Create(IDD_FRAME_DLG, this);

	//获取客户区的宽和高
	CRect rect;
	GetClientRect(&rect);
	m_frameDlg.MoveWindow(100, 100, rect.Width()-100-15, rect.Height()-100-15);
	m_frameDlg.ShowWindow(SW_SHOW);


	//循环读取文件
	CFile file;
	if (FALSE == file.Open(L"DKRMS.dat", CFile::modeRead))
	{
		MessageBox(L"文件打开失败");
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDunKaiRMSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDunKaiRMSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDunKaiRMSDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (m_frameDlg.GetSafeHwnd())
	{
		//获取客户区的宽和高
		CRect rect;
		GetClientRect(&rect);
		m_frameDlg.MoveWindow(100, 100, rect.Width() - 100 - 15, rect.Height() - 100 - 15);

	}
}

//添加员工
void CDunKaiRMSDlg::OnBnClickedBtnAdd()
{
	CAddDlg dlg;
	if (IDCANCEL == dlg.DoModal())
	{
		return;
	}

	//获取列表总行数
	int nCount = this->m_frameDlg.m_list.GetItemCount();

	//工号数据添加到列表中
	CString str;
	str.Format(L"%05d", dlg.m_nWorkNum);	
	this->m_frameDlg.m_list.InsertItem(nCount, str);

	//姓名
	this->m_frameDlg.m_list.SetItemText(nCount, 1, dlg.m_strName);

	//性别
	str = dlg.m_nSex ? L"女" : L"男";
	this->m_frameDlg.m_list.SetItemText(nCount, 2, str);

	//年龄
	str.Format(L"%d", dlg.m_nAge);
	this->m_frameDlg.m_list.SetItemText(nCount, 3, str);

	//兴趣
	str.Empty();
	if (dlg.m_bPaoniu)
		str += L"泡妞;";
	if (dlg.m_bPashan)
		str += L"爬山;";
	if (dlg.m_bKsing)
		str += L"K歌;";
	if (dlg.m_bGame)
		str += L"玩游戏;";
	if (dlg.m_bBook)
		str += L"看书;";
	this->m_frameDlg.m_list.SetItemText(nCount, 4, str);

	//部门	
	this->m_frameDlg.m_list.SetItemText(nCount, 5, dlg.m_strDepartment);

	//职位
	this->m_frameDlg.m_list.SetItemText(nCount, 6, dlg.m_strPosition);

	//试用薪资
	str.Format(L"%.2f", dlg.m_fTempSalary);
	this->m_frameDlg.m_list.SetItemText(nCount, 7, str);

	//转正薪资
	str.Format(L"%.2f", dlg.m_fRegularSalary);
	this->m_frameDlg.m_list.SetItemText(nCount, 8, str);

	//入职时间
	str = dlg.m_joinTime.Format(L"%Y-%m-%d");
	this->m_frameDlg.m_list.SetItemText(nCount, 9, str);

	//转正时间
	str = dlg.m_officialTime.Format(L"%Y-%m-%d");
	this->m_frameDlg.m_list.SetItemText(nCount, 10, str);

	//离职时间
	str = dlg.m_leaveTime.Format(L"%Y-%m-%d");
	this->m_frameDlg.m_list.SetItemText(nCount, 11, str);

	//联系电话
	this->m_frameDlg.m_list.SetItemText(nCount, 12, dlg.m_tel);

	//家庭住址
	this->m_frameDlg.m_list.SetItemText(nCount, 13, dlg.m_strAddress);
}

//删除员工
void CDunKaiRMSDlg::OnBnClickedBtnDel()
{
	POSITION pos =  m_frameDlg.m_list.GetFirstSelectedItemPosition();
	int nSel = m_frameDlg.m_list.GetNextSelectedItem(pos);
	if (nSel < 0)
	{
		MessageBox(L"请您先选中之后再删除");
		return;
	}

	m_frameDlg.m_list.DeleteItem(nSel);

	//删除所有
	//m_frameDlg.m_list.DeleteAllItems();
}

//修改员工信息
void CDunKaiRMSDlg::OnBnClickedBtnModify()
{
	POSITION pos = m_frameDlg.m_list.GetFirstSelectedItemPosition();
	int nSel = m_frameDlg.m_list.GetNextSelectedItem(pos);
	if (nSel < 0)
	{
		MessageBox(L"请您先选中之后再修改");
		return;
	}

	CModifyDlg dlg;
	//工号
	dlg.m_nWorkNum = _wtoi(m_frameDlg.m_list.GetItemText(nSel, 0));
	//姓名
	dlg.m_strName = m_frameDlg.m_list.GetItemText(nSel, 1);
	//性别
	if (m_frameDlg.m_list.GetItemText(nSel, 2) == L"男")
		dlg.m_nSex = 0;
	else
		dlg.m_nSex = 1;
	//年龄
	dlg.m_nAge = _wtoi(m_frameDlg.m_list.GetItemText(nSel, 3));
	//兴趣爱好
	dlg.m_bPaoniu = FALSE, dlg.m_bPashan = FALSE, dlg.m_bKsing = FALSE, dlg.m_bGame = FALSE, dlg.m_bBook = FALSE;
	CString strInterest = m_frameDlg.m_list.GetItemText(nSel, 4);
	if (strInterest.Find(L"泡妞;") != -1)
	{
		dlg.m_bPaoniu = TRUE;
	}
	if (strInterest.Find(L"爬山;") != -1)
	{
		dlg.m_bPashan = TRUE;
	}
	if (strInterest.Find(L"K歌;") != -1)
	{
		dlg.m_bKsing = TRUE;
	}
	if (strInterest.Find(L"玩游戏;") != -1)
	{
		dlg.m_bGame = TRUE;
	}
	if (strInterest.Find(L"看书;") != -1)
	{
		dlg.m_bBook = TRUE;
	}
	//部门
	dlg.m_strDepartment = m_frameDlg.m_list.GetItemText(nSel, 5);
	//设置部门显示
	//dlg.m_department.SetWindowText(dlg.m_strDepartment);
	//职位
	dlg.m_strPosition = m_frameDlg.m_list.GetItemText(nSel, 6);
	//设置部门显示  此时还在初始化窗口还没出来，所以不能用控件
	//dlg.m_position.SetWindowText(dlg.m_strPosition);
	//试用薪资
	dlg.m_fTempSalary = _wtof(m_frameDlg.m_list.GetItemText(nSel, 7));
	//转正薪资
	dlg.m_fRegularSalary = _wtof(m_frameDlg.m_list.GetItemText(nSel, 8));
	//入职时间
	dlg.m_joinTime.ParseDateTime(m_frameDlg.m_list.GetItemText(nSel, 9));
	//转正时间
	dlg.m_officialTime.ParseDateTime(m_frameDlg.m_list.GetItemText(nSel, 10));
	//离职时间
	dlg.m_leaveTime.ParseDateTime(m_frameDlg.m_list.GetItemText(nSel, 11));
	//联系电话
	dlg.m_tel = m_frameDlg.m_list.GetItemText(nSel, 12);
	//家庭住址
	dlg.m_strAddress = m_frameDlg.m_list.GetItemText(nSel, 13);

	//不需要再Update，因为这个对话框还会再初始化一下
	if (IDCANCEL == dlg.DoModal())
	{
		return;
	}
	

	//工号数据添加到列表中
	CString str;
	str.Format(L"%05d", dlg.m_nWorkNum);
	this->m_frameDlg.m_list.SetItemText(nSel, 0, str);

	//姓名
	this->m_frameDlg.m_list.SetItemText(nSel, 1, dlg.m_strName);

	//性别
	str = dlg.m_nSex ? L"女" : L"男";
	this->m_frameDlg.m_list.SetItemText(nSel, 2, str);

	//年龄
	str.Format(L"%d", dlg.m_nAge);
	this->m_frameDlg.m_list.SetItemText(nSel, 3, str);

	//兴趣
	str.Empty();
	if (dlg.m_bPaoniu)
		str += L"泡妞;";
	if (dlg.m_bPashan)
		str += L"爬山;";
	if (dlg.m_bKsing)
		str += L"K歌;";
	if (dlg.m_bGame)
		str += L"玩游戏;";
	if (dlg.m_bBook)
		str += L"看书;";
	this->m_frameDlg.m_list.SetItemText(nSel, 4, str);

	//部门	
	this->m_frameDlg.m_list.SetItemText(nSel, 5, dlg.m_strDepartment);

	//职位
	this->m_frameDlg.m_list.SetItemText(nSel, 6, dlg.m_strPosition);

	//试用薪资
	str.Format(L"%.2f", dlg.m_fTempSalary);
	this->m_frameDlg.m_list.SetItemText(nSel, 7, str);

	//转正薪资
	str.Format(L"%.2f", dlg.m_fRegularSalary);
	this->m_frameDlg.m_list.SetItemText(nSel, 8, str);

	//入职时间
	str = dlg.m_joinTime.Format(L"%Y-%m-%d");
	this->m_frameDlg.m_list.SetItemText(nSel, 9, str);

	//转正时间
	str = dlg.m_officialTime.Format(L"%Y-%m-%d");
	this->m_frameDlg.m_list.SetItemText(nSel, 10, str);

	//离职时间
	str = dlg.m_leaveTime.Format(L"%Y-%m-%d");
	this->m_frameDlg.m_list.SetItemText(nSel, 11, str);

	//联系电话
	this->m_frameDlg.m_list.SetItemText(nSel, 12, dlg.m_tel);

	//家庭住址
	this->m_frameDlg.m_list.SetItemText(nSel, 13, dlg.m_strAddress);

}


void CDunKaiRMSDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	//打开文件
	CFile file;
	if (FALSE == file.Open(L"DKRMS.dat", CFile::modeCreate | CFile::modeWrite))
	{
		MessageBox(L"打开文件失败");
		return;
	}

	//获取总行数
	int nCount = m_frameDlg.m_list.GetItemCount();
	for (int i = 0; i < nCount;i++)
	{
		Staff staff = {0};

		//工号
		staff.worknum = _wtoi(m_frameDlg.m_list.GetItemText(i, 0));
		//姓名
		wcscpy(staff.name ,m_frameDlg.m_list.GetItemText(i, 1));
		//性别
		wcscpy(staff.sex, m_frameDlg.m_list.GetItemText(i, 2));
		//年龄
		staff.age = _wtoi(m_frameDlg.m_list.GetItemText(i, 3));
		//兴趣爱好
		wcscpy(staff.interest, m_frameDlg.m_list.GetItemText(i, 4));
		//部门
		wcscpy(staff.department,  m_frameDlg.m_list.GetItemText(i, 5));
		//设置部门显示
		//dlg.m_department.SetWindowText(dlg.m_strDepartment);
		//职位
		wcscpy(staff.position , m_frameDlg.m_list.GetItemText(i, 6));
		//设置部门显示
		//dlg.m_position.SetWindowText(dlg.m_strPosition);
		//试用薪资
		staff.tempSalary = _wtof(m_frameDlg.m_list.GetItemText(i, 7));
		//转正薪资
		staff.regularSalary = _wtof(m_frameDlg.m_list.GetItemText(i, 8));
		//入职时间
		wcscpy(staff.joinTime,m_frameDlg.m_list.GetItemText(i, 9));
		//转正时间
		wcscpy(staff.officialTime,m_frameDlg.m_list.GetItemText(i, 10));
		//离职时间
		wcscpy(staff.leaveTime,m_frameDlg.m_list.GetItemText(i, 11));
		//联系电话
		wcscpy(staff.tel, m_frameDlg.m_list.GetItemText(i, 12));
		//家庭住址
		wcscpy(staff.address, m_frameDlg.m_list.GetItemText(i, 13));


		file.Write(&staff, sizeof(staff));
	}

	file.Close();

	// TODO:  在此处添加消息处理程序代码
}
