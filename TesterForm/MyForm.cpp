#include "MyForm.h"
#include "StructureTester.h";
using namespace System;
using namespace System::Windows::Forms;


[STAThread]

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	TesterForm::MyForm form;
	Application::Run(% form);
}


