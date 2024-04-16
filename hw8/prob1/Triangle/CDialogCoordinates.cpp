// CDialogCoordinates.cpp: 实现文件
//

#include "pch.h"
#include "Triangle.h"
#include "afxdialogex.h"
#include "CDialogCoordinates.h"


// CDialogCoordinates 对话框

IMPLEMENT_DYNAMIC(CDialogCoordinates, CDialogEx)

CDialogCoordinates::CDialogCoordinates(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_COORDINATES, pParent)
{

}

CDialogCoordinates::~CDialogCoordinates()
{
}

void CDialogCoordinates::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_A_X, m_a_x);
	DDX_Text(pDX, IDC_A_Y, m_a_y);
	DDX_Text(pDX, IDC_B_X, m_b_x);
	DDX_Text(pDX, IDC_B_Y, m_b_y);
	DDX_Text(pDX, IDC_C_X, m_c_x);
	DDX_Text(pDX, IDC_C_Y, m_c_y);
}


BEGIN_MESSAGE_MAP(CDialogCoordinates, CDialogEx)
END_MESSAGE_MAP()


// CDialogCoordinates 消息处理程序
