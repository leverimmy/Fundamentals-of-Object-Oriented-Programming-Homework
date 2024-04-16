
// ShapeMFCView.cpp: CShapeMFCView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ShapeMFC.h"
#endif

#include "ShapeMFCDoc.h"
#include "ShapeMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "CP_Draw.h"

// CShapeMFCView

IMPLEMENT_DYNCREATE(CShapeMFCView, CView)

BEGIN_MESSAGE_MAP(CShapeMFCView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CShapeMFCView 构造/析构

CShapeMFCView::CShapeMFCView()
{
	// TODO: 在此处添加构造代码
}

CShapeMFCView::~CShapeMFCView()
{
}

BOOL CShapeMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CShapeMFCView 绘图

void CShapeMFCView::OnDraw(CDC* pDC)
{
	CShapeMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	gb_draw(*pDC, pDoc->m_circle, PS_DASH, 255, 0, 0);
	gb_draw(*pDC, pDoc->m_square, PS_DOT, 0, 0, 0);
	gb_draw(*pDC, pDoc->m_triangle, PS_SOLID, 0, 0, 255);
}


// CShapeMFCView 打印

BOOL CShapeMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CShapeMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CShapeMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CShapeMFCView 诊断

#ifdef _DEBUG
void CShapeMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CShapeMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShapeMFCDoc* CShapeMFCView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShapeMFCDoc)));
	return (CShapeMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CShapeMFCView 消息处理程序
