#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	AUS2___Sem2::MyForm form;
	Application::Run(%form);
}

Property * AUS2___Sem2::MyForm::getCurrLoadProperty()
{
	return currLoadProperty;
}

void AUS2___Sem2::MyForm::setCurrLoadProperty(Property * newCurr)
{
	currLoadProperty = newCurr;
}

void AUS2___Sem2::MyForm::printSequenceData(std::string fileName, std::vector<Block*> *vektor)
{

	for (int i = 0;i < vektor->size();i++) {
		ListViewItem^ item = gcnew ListViewItem();

		std::string block = "Block: " + std::to_string(i+1);
		

		for (int j = 0; j < vektor->at(i)->records->size(); j++) {
			block += " | Rekord: " + vektor->at(i)->records->at(j)->toString();
		}

		for (int j = 0; j < vektor->at(i)->sonsAdreses->size(); j++) {
			block += " | Adresa: " + std::to_string(vektor->at(i)->sonsAdreses->at(j));
		}

		item->Text = gcnew String(block.c_str());
		item->SubItems->Add("");
		listViewSequenceOutput->Items->Add(item);
	}
}

void AUS2___Sem2::MyForm::printSequenceData()
{
	int BLOCK_SIZE = mainS->getPropertySize();

	for (int g = 0; g < mainS->getLastIndex(); g++) {
		char *block = mainS->readDataFromFile(g);

		Property * newProp = new Property();
		newProp->fromByteArray(block);

		ListViewItem^ item = gcnew ListViewItem();

		std::string property = "Nehnutelnost: " + std::to_string(g) + " " + newProp->toString();
		/*item->Text = gcnew String(property.c_str());
		item->SubItems->Add("");
		*/
		
		item->SubItems[0]->Text = gcnew String(property.c_str());
		item->SubItems->Add("");
		listViewSequenceOutput->Items->Add(item);
	}
}
