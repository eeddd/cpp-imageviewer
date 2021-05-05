#include "ImagePanel.h"

BEGIN_EVENT_TABLE(wxImagePanel, wxPanel)
EVT_PAINT(wxImagePanel::paintEvent)
END_EVENT_TABLE()


wxImagePanel::wxImagePanel(wxFrame* parent)
	: wxPanel(parent)
{

}

void wxImagePanel::loadFile(const wxString& file, const wxBitmapType& format)
{
	clear();
	image.LoadFile(file, format);
	paintNow();
}

void wxImagePanel::paintEvent(wxPaintEvent& evt)
{
	wxPaintDC dc(this);
	render(dc);
}

void wxImagePanel::paintNow()
{
	wxClientDC dc(this);
	render(dc);
}

void wxImagePanel::render(wxDC& dc)
{
	if (image.IsOk()) {
		dc.DrawBitmap(image, 0, 0, false);
	}
}

void wxImagePanel::clear()
{
	wxClientDC dc(this);
	dc.Clear();
}