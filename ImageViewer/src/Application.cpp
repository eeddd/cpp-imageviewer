#include<wx/wx.h>
#include "ImagePanel.h"

class MainFrame : public wxFrame
{
	wxTextCtrl* txtInput;
	wxImagePanel* imgPanel;

public:
	MainFrame(const wxString& title)
		: wxFrame(NULL, -1, title, wxDefaultPosition, wxSize(800, 600))
	{
		wxInitAllImageHandlers();

		txtInput = new wxTextCtrl(this, -1);
		imgPanel = new wxImagePanel(this);

		wxButton* btn = new wxButton(this, 10001, "Browse");
		btn->Bind(wxEVT_BUTTON, &MainFrame::OnClickOpen, this);

		wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
		hbox->Add(txtInput, 1, wxALL | wxEXPAND, 0);
		hbox->Add(btn, 0, wxALL | wxEXPAND, 1);

		wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
		vbox->Add(hbox, 0, wxALL | wxEXPAND, 1);
		vbox->Add(imgPanel, 1, wxALL | wxEXPAND, 1);
		SetSizer(vbox);
	}

	void OnClickOpen(wxCommandEvent& event)
	{
		wxFileDialog dlg(this, _("Open Image"), "", "", "PNG (*.png)|*.png|JPEG (*.jpg)|*.jpg", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

		if (dlg.ShowModal() == wxID_CANCEL)
			return;

		imgPanel->loadFile(dlg.GetPath(), wxBITMAP_TYPE_ANY);
		txtInput->SetLabelText(dlg.GetPath());
	}
};


class App : public wxApp
{
public:
	virtual bool OnInit()
	{
		MainFrame* frm = new MainFrame("ImageView");
		frm->Show();
		return true;
	}
};

IMPLEMENT_APP(App);