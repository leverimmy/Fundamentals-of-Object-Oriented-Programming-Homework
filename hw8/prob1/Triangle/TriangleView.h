
// TriangleView.h: CTriangleView 类的接口
//

#pragma once


class CTriangleView : public CView
{
protected: // 仅从序列化创建
	CTriangleView();
	DECLARE_DYNCREATE(CTriangleView)

// 特性
public:
	int m_flag; // 0: 创建三角形；1: 移动第1个端点；2: 移动第2个端点；3: 移动第3个端点。
	int m_count; // 在创建三角形时绘制第几个点。
	
	CTriangleDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CTriangleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEditTriangle();
	afx_msg void OnUpdateEditTriangle(CCmdUI* pCmdUI);
	afx_msg void OnEditOne();
	afx_msg void OnUpdateEditOne(CCmdUI* pCmdUI);
	afx_msg void OnEditTwo();
	afx_msg void OnUpdateEditTwo(CCmdUI* pCmdUI);
	afx_msg void OnEditThree();
	afx_msg void OnUpdateEditThree(CCmdUI* pCmdUI);
	afx_msg void OnEditDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // TriangleView.cpp 中的调试版本
inline CTriangleDoc* CTriangleView::GetDocument() const
   { return reinterpret_cast<CTriangleDoc*>(m_pDocument); }
#endif

