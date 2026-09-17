#pragma once

namespace Lz1Z1 {

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
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:

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
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Лінія", L"Прямокутник", L"Зафарбований прямокутник",
					L"Еліпс", L"Зафарбований еліпс", L"Сектор", L"Зірка"
			});
			this->listBox1->Location = System::Drawing::Point(373, 24);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(206, 134);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(591, 276);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graf = CreateGraphics();
		Pen^ pn = gcnew System::Drawing::Pen(Color::Blue, 5);
		Brush^ br = gcnew System::Drawing::SolidBrush(Color::DarkRed);
		graf->Clear(Color::White);
		switch (listBox1->SelectedIndex)
		{
		case 0: graf->DrawLine(Pens::Red, 50, 40, 250, 160); break;
		case 1: graf->DrawRectangle(Pens::Blue, 40, 40, 150, 80); break;
		case 2: graf->FillRectangle(Brushes::Green, 40, 40, 150, 80); break;
		case 3: graf->DrawEllipse(Pens::Purple, 40, 40, 200, 140); break;
		case 4: graf->FillEllipse(Brushes::Orange, 40, 40, 200, 140); break;
		case 5: graf->FillPie(Brushes::Brown, 40, 40, 200, 200, 180, 90); break;
		case 6: {
			cli::array<Point>^ starPoints = gcnew cli::array<Point>{
				Point(120, 30),
					Point(145, 100),
					Point(215, 100),
					Point(155, 150),
					Point(180, 230),
					Point(120, 180),
					Point(60, 230),
					Point(85, 150),
					Point(25, 100),
					Point(95, 100)

			};
			graf->FillPolygon(Brushes::Yellow, starPoints);
			graf->DrawPolygon(Pens::Yellow, starPoints);
		}
			  break;
	}
	}
};
}
