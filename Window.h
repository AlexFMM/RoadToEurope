#pragma once
#include<string>
#include"alg.h"

using namespace std;

namespace RoadToEurope {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Window
	/// </summary>
	public ref class Window : public System::Windows::Forms::Form
	{
	public:
		Window(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Window()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^  OriSel;
	private: System::Windows::Forms::ComboBox^  DestSel;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  Go;
	private: System::Windows::Forms::TextBox^  Solucao;
	private: System::Windows::Forms::ComboBox^  TipSel;
	private: System::Windows::Forms::Label^  label3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->OriSel = (gcnew System::Windows::Forms::ComboBox());
			this->DestSel = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Go = (gcnew System::Windows::Forms::Button());
			this->Solucao = (gcnew System::Windows::Forms::TextBox());
			this->TipSel = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// OriSel
			// 
			this->OriSel->FormattingEnabled = true;
			this->OriSel->Location = System::Drawing::Point(12, 32);
			this->OriSel->Name = L"OriSel";
			this->OriSel->Size = System::Drawing::Size(121, 21);
			this->OriSel->TabIndex = 0;
			// 
			// DestSel
			// 
			this->DestSel->FormattingEnabled = true;
			this->DestSel->Location = System::Drawing::Point(151, 32);
			this->DestSel->Name = L"DestSel";
			this->DestSel->Size = System::Drawing::Size(121, 21);
			this->DestSel->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Origem";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(148, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Destino";
			// 
			// Go
			// 
			this->Go->Location = System::Drawing::Point(101, 116);
			this->Go->Name = L"Go";
			this->Go->Size = System::Drawing::Size(75, 23);
			this->Go->TabIndex = 4;
			this->Go->Text = L"Go";
			this->Go->UseVisualStyleBackColor = true;
			this->Go->Click += gcnew System::EventHandler(this, &Window::Go_Click);
			// 
			// Solucao
			// 
			this->Solucao->Location = System::Drawing::Point(12, 145);
			this->Solucao->Multiline = true;
			this->Solucao->Name = L"Solucao";
			this->Solucao->ReadOnly = true;
			this->Solucao->Size = System::Drawing::Size(260, 143);
			this->Solucao->TabIndex = 5;
			// 
			// TipSel
			// 
			this->TipSel->FormattingEnabled = true;
			this->TipSel->Location = System::Drawing::Point(79, 78);
			this->TipSel->Name = L"TipSel";
			this->TipSel->Size = System::Drawing::Size(121, 21);
			this->TipSel->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(76, 62);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Tipo";
			// 
			// Window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 297);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->TipSel);
			this->Controls->Add(this->Solucao);
			this->Controls->Add(this->Go);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->DestSel);
			this->Controls->Add(this->OriSel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"Window";
			this->Text = L"Road To Europe";
			this->Load += gcnew System::EventHandler(this, &Window::Window_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}


	private: System::Void Window_Load(System::Object^  sender, System::EventArgs^  e) {
		TipSel->Items->Add("Distância");
		TipSel->Items->Add("Preço");
		TipSel->Items->Add("Tempo");
		for (int i = 0; i < 15; i++){
			OriSel->Items->Add(getSystemString(paises[i]));
			DestSel->Items->Add(getSystemString(paises[i]));
		}
	}


	private: System::Void Go_Click(System::Object^  sender, System::EventArgs^  e) {
		Solucao->Clear();
		caminho.clear();
		float tot=0;
		if (OriSel->SelectedIndex == -1 || DestSel->SelectedIndex == -1){
			MessageBox::Show("Selecione a origem e o destino.");
		}
		else if (OriSel->SelectedIndex == DestSel->SelectedIndex){
			MessageBox::Show("A origem e o destino não podem ser iguais.");
		}
		else if (TipSel->SelectedIndex == -1){
			MessageBox::Show("Selecione um tipo.");
		}
		else{
			switch (TipSel->SelectedIndex)
			{
			case 0:
				tot=algoritmo(OriSel->SelectedIndex, DestSel->SelectedIndex, caminho, distancias);
				Solucao->AppendText(getSystemString("A rota que percorre menos distância começando em " + paises[OriSel->SelectedIndex] + " e terminando em " + paises[DestSel->SelectedIndex] + " segue o percurso : "));
				for (int i = 0; i < (int)caminho.size(); i++){
					Solucao->AppendText(getSystemString(paises[caminho[i]]));
					if (i<(int)caminho.size() - 1)
						Solucao->AppendText(getSystemString(", "));
				}
				Solucao->AppendText(getSystemString(" percorrendo um total de "));
				Solucao->AppendText(tot.ToString());
				Solucao->AppendText(getSystemString("Km"));
				break;
			case 1:
				tot=algoritmo(OriSel->SelectedIndex, DestSel->SelectedIndex, caminho, custo);
				Solucao->AppendText(getSystemString("A rota que percorre com menor custo começando em " + paises[OriSel->SelectedIndex] + " e terminando em " + paises[DestSel->SelectedIndex] + " segue o percurso : "));
				for (int i = 0; i < (int)caminho.size(); i++){
					Solucao->AppendText(getSystemString(paises[caminho[i]]));
					if (i<(int)caminho.size() - 1)
						Solucao->AppendText(getSystemString(", "));
				}
				Solucao->AppendText(getSystemString(" gastando um total de "));
				Solucao->AppendText(tot.ToString());
				Solucao->AppendText(getSystemString("€"));
				break;
			case 2:
				tot=algoritmo(OriSel->SelectedIndex, DestSel->SelectedIndex, caminho, tempo);
				Solucao->AppendText(getSystemString("A rota que percorre menos tempo começando em " + paises[OriSel->SelectedIndex] + " e terminando em " + paises[DestSel->SelectedIndex] + " segue o percurso : "));
				for (int i = 0; i < (int)caminho.size(); i++){
					Solucao->AppendText(getSystemString(paises[caminho[i]]));
					if (i<(int)caminho.size() - 1)
						Solucao->AppendText(getSystemString(", "));
				}
				Solucao->AppendText(getSystemString(" levando um total de "));
				Solucao->AppendText(tot.ToString());
				Solucao->AppendText(getSystemString("H"));
				break;
			default:
				break;
			}	
		}
	}
};
}