
// DunKaiRMS.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDunKaiRMSApp: 
// �йش����ʵ�֣������ DunKaiRMS.cpp
//

class CDunKaiRMSApp : public CWinApp
{
public:
	CDunKaiRMSApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDunKaiRMSApp theApp;