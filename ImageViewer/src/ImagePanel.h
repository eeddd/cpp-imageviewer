#pragma once
#include<wx/wx.h>

class wxImagePanel : public wxPanel
{
	wxBitmap image;
public:
	wxImagePanel(wxFrame* parent);

	void loadFile(const wxString& file, const wxBitmapType& format);

	void paintEvent(wxPaintEvent& evt);
	void paintNow();
	void render(wxDC& dc);
	void clear();

	DECLARE_EVENT_TABLE()
};

