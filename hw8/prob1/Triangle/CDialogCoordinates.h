#pragma once
#include "afxdialogex.h"


// CDialogCoordinates 对话框

class CDialogCoordinates : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogCoordinates)

public:
	CDialogCoordinates(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogCoordinates();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_COORDINATES };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_a_x, m_a_y;
	double m_b_x, m_b_y;
	double m_c_x, m_c_y;
};
