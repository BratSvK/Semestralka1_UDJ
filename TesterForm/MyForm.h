#pragma once
#include <iostream>
#include "StructureTester.h";
#include <functional>
#include <thread>

namespace TesterForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace std;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{

			/* initialize random seed: */
			srand(time(NULL));

			InitializeComponent();
			this->tester = new StructureTester();
			// zavoalt do listenara tester->testList();
			

			
			
			
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
				delete tester;
			}
		}

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^ TestBtn;






	private: System::Windows::Forms::ComboBox^ Scenar;
	private: System::Windows::Forms::CheckBox^ arrayList_check;
	private: System::Windows::Forms::CheckBox^ linkedList_check;


	private: System::Windows::Forms::RadioButton^ Zoznam;


		   // tester pre celu instanciu 
		StructureTester* tester;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->TestBtn = (gcnew System::Windows::Forms::Button());
			this->Scenar = (gcnew System::Windows::Forms::ComboBox());
			this->arrayList_check = (gcnew System::Windows::Forms::CheckBox());
			this->linkedList_check = (gcnew System::Windows::Forms::CheckBox());
			this->Zoznam = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// TestBtn
			// 
			this->TestBtn->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->TestBtn->Location = System::Drawing::Point(484, 510);
			this->TestBtn->Name = L"TestBtn";
			this->TestBtn->Size = System::Drawing::Size(187, 67);
			this->TestBtn->TabIndex = 5;
			this->TestBtn->Text = L"Test";
			this->TestBtn->UseVisualStyleBackColor = true;
			this->TestBtn->Click += gcnew System::EventHandler(this, &MyForm::test_click);
			// 
			// Scenar
			// 
			this->Scenar->Enabled = false;
			this->Scenar->FormattingEnabled = true;
			this->Scenar->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Scenar->IntegralHeight = false;
			this->Scenar->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"A(20,20,50,10)", L"B(35,35,20,10)", L"C(45,45,5,5)",
					L"None"
			});
			this->Scenar->Location = System::Drawing::Point(121, 154);
			this->Scenar->Name = L"Scenar";
			this->Scenar->Size = System::Drawing::Size(136, 24);
			this->Scenar->Sorted = true;
			this->Scenar->TabIndex = 7;
			this->Scenar->Text = L"Scenar";
			// 
			// arrayList_check
			// 
			this->arrayList_check->AutoSize = true;
			this->arrayList_check->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->arrayList_check->Enabled = false;
			this->arrayList_check->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->arrayList_check->Location = System::Drawing::Point(37, 99);
			this->arrayList_check->Name = L"arrayList_check";
			this->arrayList_check->Size = System::Drawing::Size(137, 32);
			this->arrayList_check->TabIndex = 8;
			this->arrayList_check->Text = L"ArrayList";
			this->arrayList_check->UseVisualStyleBackColor = false;
			this->arrayList_check->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// linkedList_check
			// 
			this->linkedList_check->AutoSize = true;
			this->linkedList_check->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->linkedList_check->Enabled = false;
			this->linkedList_check->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
			this->linkedList_check->Location = System::Drawing::Point(198, 99);
			this->linkedList_check->Name = L"linkedList_check";
			this->linkedList_check->Size = System::Drawing::Size(155, 32);
			this->linkedList_check->TabIndex = 9;
			this->linkedList_check->Text = L"LinkedList";
			this->linkedList_check->UseVisualStyleBackColor = false;
			this->linkedList_check->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox2_CheckedChanged);
			// 
			// Zoznam
			// 
			this->Zoznam->AutoSize = true;
			this->Zoznam->Font = (gcnew System::Drawing::Font(L"Showcard Gothic", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Zoznam->Location = System::Drawing::Point(82, 25);
			this->Zoznam->Name = L"Zoznam";
			this->Zoznam->Size = System::Drawing::Size(204, 54);
			this->Zoznam->TabIndex = 10;
			this->Zoznam->TabStop = true;
			this->Zoznam->Text = L"Zoznam";
			this->Zoznam->UseVisualStyleBackColor = true;
			this->Zoznam->CheckedChanged += gcnew System::EventHandler(this, &MyForm::Zoznam_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::CornflowerBlue;
			this->ClientSize = System::Drawing::Size(681, 583);
			this->Controls->Add(this->Zoznam);
			this->Controls->Add(this->linkedList_check);
			this->Controls->Add(this->arrayList_check);
			this->Controls->Add(this->Scenar);
			this->Controls->Add(this->TestBtn);
			this->Name = L"MyForm";
			this->Text = L"StructerTester(GUI)";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void enableScenarList()
	{
		if (this->Zoznam->Checked && (this->arrayList_check->Checked || this->linkedList_check->Checked)) {
			this->Scenar->Enabled = true;
		}
		else {
			this->Scenar->Enabled = false;
			this->Scenar->Text = "Scenar";
		}
	}
	private: System::Void enableZoznamSelection()
	 {
		if (this->Zoznam->Checked) {
			this->arrayList_check->Enabled = true;
			this->linkedList_check->Enabled = true;
		}
		else {
			this->arrayList_check->Enabled = false;
			this->linkedList_check->Enabled = false;
		}
	}

private: System::Boolean CheckZoznamSelectionToTest()
{
	return (this->Zoznam->Checked && (this->arrayList_check->Checked || this->linkedList_check->Checked) && (!(this->arrayList_check->Checked && this->linkedList_check->Checked))
		&& ((this->Scenar->Text != "None" && this->Scenar->Text != "Scenar" ) && this->Scenar->Enabled));
}

private: System::Byte GetADT()
{
	if (CheckZoznamSelectionToTest())
	{
		return 1;
	}
	return 0;
}
	
private: System::Boolean GetADS()
{
	return this->arrayList_check->Checked ? true : false;
}

private: System::Char GetScenarList()
{
	if (CheckZoznamSelectionToTest())
	{
		if (this->Scenar->Text->Contains("A")) {
			return 'A';
		}
		else if (this->Scenar->Text->Contains("B")) {
			return 'B';
		}
		else {
			return 'C';
		}
	}
	return 'x';
}


private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	enableScenarList();
	enableZoznamSelection();
}
private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	enableScenarList();
}
private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	enableScenarList();
}
private: System::Void Zoznam_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	enableZoznamSelection();
}
private: System::Void test_click(System::Object^ sender, System::EventArgs^ e) {

	if (!CheckZoznamSelectionToTest())
	{
		MessageBox::Show("Your selection isn't complete!!!");
		return;
	}

	switch (GetADT())
	{
	case 1:
		tester->testList(GetADS(), GetScenarList());
	default:
		break;
	}
	MessageBox::Show("Your test is completed!!!");
}
};
}
