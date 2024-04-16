
// TriangleView.cpp: CTriangleView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Triangle.h"
#endif

#include "TriangleDoc.h"
#include "TriangleView.h"
#include "CP_Draw.h"
#include "CDialogCoordinates.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTriangleView

IMPLEMENT_DYNCREATE(CTriangleView, CView)

BEGIN_MESSAGE_MAP(CTriangleView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_EDIT_TRIANGLE, &CTriangleView::OnEditTriangle)
	ON_UPDATE_COMMAND_UI(ID_EDIT_TRIANGLE, &CTriangleView::OnUpdateEditTriangle)
	ON_COMMAND(ID_EDIT_ONE, &CTriangleView::OnEditOne)
	ON_UPDATE_COMMAND_UI(ID_EDIT_ONE, &CTriangleView::OnUpdateEditOne)
	ON_COMMAND(ID_EDIT_TWO, &CTriangleView::OnEditTwo)
	ON_UPDATE_COMMAND_UI(ID_EDIT_TWO, &CTriangleView::OnUpdateEditTwo)
	ON_COMMAND(ID_EDIT_THREE, &CTriangleView::OnEditThree)
	ON_UPDATE_COMMAND_UI(ID_EDIT_THREE, &CTriangleView::OnUpdateEditThree)
	ON_COMMAND(ID_EDIT_DIALOG, &CTriangleView::OnEditDialog)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CTriangleView 构造/析构

CTriangleView::CTriangleView(): m_flag(0), m_count(0)
{
	// TODO: 在此处添加构造代码

}

CTriangleView::~CTriangleView()
{
}

BOOL CTriangleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTriangleView 绘图

void CTriangleView::OnDraw(CDC* pDC)
{
	CTriangleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	gb_draw(*pDC, pDoc->m_triangle, PS_SOLID, 0, 0, 0);
}


// CTriangleView 打印

BOOL CTriangleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTriangleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTriangleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CTriangleView 诊断

#ifdef _DEBUG
void CTriangleView::AssertValid() const
{
	CView::AssertValid();
}

void CTriangleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTriangleDoc* CTriangleView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTriangleDoc)));
	return (CTriangleDoc*)m_pDocument;
}
#endif //_DEBUG


// CTriangleView 消息处理程序


void CTriangleView::OnEditTriangle()
{
	// TODO: 在此添加命令处理程序代码
	m_flag = 0;
	m_count = 1;
}


void CTriangleView::OnUpdateEditTriangle(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck((m_flag == 0) ? 1 : 0);
}


void CTriangleView::OnEditOne()
{
	// TODO: 在此添加命令处理程序代码
	m_flag = 1;
}


void CTriangleView::OnUpdateEditOne(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck((m_flag == 1) ? 1 : 0);
}


void CTriangleView::OnEditTwo()
{
	// TODO: 在此添加命令处理程序代码
	m_flag = 2;
}


void CTriangleView::OnUpdateEditTwo(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck((m_flag == 2) ? 1 : 0);
}


void CTriangleView::OnEditThree()
{
	// TODO: 在此添加命令处理程序代码
	m_flag = 3;
}


void CTriangleView::OnUpdateEditThree(CCmdUI* pCmdUI)
{
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->SetCheck((m_flag == 3) ? 1 : 0);
}


void CTriangleView::OnEditDialog()
{
	// TODO: 在此添加命令处理程序代码
	CTriangleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDialogCoordinates d;
	d.m_a_x = pDoc->m_triangle.m_a.m_x;
	d.m_a_y = pDoc->m_triangle.m_a.m_y;
	d.m_b_x = pDoc->m_triangle.m_b.m_x;
	d.m_b_y = pDoc->m_triangle.m_b.m_y;
	d.m_c_x = pDoc->m_triangle.m_c.m_x;
	d.m_c_y = pDoc->m_triangle.m_c.m_y;
	if (IDOK == d.DoModal())
	{
		pDoc->m_triangle.m_a.m_x = d.m_a_x;
		pDoc->m_triangle.m_a.m_y = d.m_a_y;
		pDoc->m_triangle.m_b.m_x = d.m_b_x;
		pDoc->m_triangle.m_b.m_y = d.m_b_y;
		pDoc->m_triangle.m_c.m_x = d.m_c_x;
		pDoc->m_triangle.m_c.m_y = d.m_c_y;
		Invalidate();
	}
	GetParentFrame()->GetMessageBar()
		->SetWindowText(_T("设置三角形端点坐标!"));
}


void CTriangleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CTriangleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if ((m_flag == 0 && m_count == 1) || (m_flag == 1))
	{
		pDoc->m_triangle.m_a.m_x = point.x;
		pDoc->m_triangle.m_a.m_y = point.y;
		m_count++;
		Invalidate();
	}
	else if ((m_flag == 0 && m_count == 2) || (m_flag == 2)) {
		pDoc->m_triangle.m_b.m_x = point.x;
		pDoc->m_triangle.m_b.m_y = point.y;
		m_count++;
		Invalidate();
	}
	else if (((m_flag == 0 && m_count == 3) || m_flag == 3)) {
		pDoc->m_triangle.m_c.m_x = point.x;
		pDoc->m_triangle.m_c.m_y = point.y;
		m_count = 1;
		Invalidate();
	}
	CView::OnLButtonDown(nFlags, point);
}


void CTriangleView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CTriangleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	/*if (m_flag == 0)
	{
		pDoc->m_triangle.m_b.m_x = point.x;
		pDoc->m_triangle.m_b.m_y = point.y;
		pDoc->m_triangle.m_c.m_x = point.x;
		pDoc->m_triangle.m_c.m_y = point.y;
		Invalidate();
	}*/
	CView::OnLButtonUp(nFlags, point);
}
