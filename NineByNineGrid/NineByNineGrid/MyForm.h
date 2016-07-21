#pragma once
#include <iostream>
#include<fstream>
namespace NineByNineGrid {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panel1;
	protected:

	private:
		System::Drawing::Graphics^ g;	//Initializes graphics object
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->button1->Font = (gcnew System::Drawing::Font(L"Nirmala UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::Control;
			this->button1->Location = System::Drawing::Point(450, 103);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(138, 79);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Push";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(415, 439);
			this->panel1->TabIndex = 1;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(628, 467);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
		
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		int pic_location[9 * 9][2];	//first element stores first number of paired coordinates. Second element stores second number of paired coordinates.
		get_data(pic_location);
		g = panel1->CreateGraphics();
		Bitmap^ bmp = gcnew Bitmap(L"dwceagles2.bmp");
		for (int i = 0; i < 9 * 9; i++) //loop places image on panel with coordinates
		{
			g->DrawImage(bmp, pic_location[i][0], pic_location[i][1]);

		}

	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		g = panel1->CreateGraphics();
	}

			 void get_data(int piclocation[][2]) {

				 std::ifstream in_stream;
				 in_stream.open("picloc.txt");
				 int count = 0;
				 while (!in_stream.eof()) {					//stream coordinates from file into array
					 in_stream >> piclocation[count][0];
					 in_stream >> piclocation[count][1];
					 count++;
				 }
			 }
	};
}
