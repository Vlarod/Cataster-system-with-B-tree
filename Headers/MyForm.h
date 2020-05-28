#pragma once
#include "MainSystem.h"
#include <msclr\marshal_cppstd.h>
namespace AUS2___Sem2 {

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
		Property * getCurrLoadProperty();
		void setCurrLoadProperty(Property* newCurr);
		void printSequenceData(std::string fileName, std::vector<Block*> *vektor);
		void printSequenceData();
		//void searchProperty();
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
	private: System::Windows::Forms::Button^  buttonAddProperty;
	protected:
	private: System::Windows::Forms::GroupBox^  groupBoxAddProperty;
	private: System::Windows::Forms::Button^  buttonAddNewProperty;
	private: System::Windows::Forms::TextBox^  textBoxPropertyId;
	private: System::Windows::Forms::Label^  labelPropertyId;
	private: System::Windows::Forms::TextBox^  textBoxPropertyDescription;
	private: System::Windows::Forms::Label^  labelTitleDescription;
	private: System::Windows::Forms::TextBox^  textBoxNameOfCA;
	private: System::Windows::Forms::Label^  labelTitleNameOfCA;
	private: System::Windows::Forms::TextBox^  textBoxZipNumber;
	private: System::Windows::Forms::Label^  labeltITitleZipNumber;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^  buttonSearchViaId;
	private: System::Windows::Forms::TextBox^  textBoxSeachId;
	private: System::Windows::Forms::GroupBox^  groupBoxPropertyInfo;
	private: System::Windows::Forms::Label^  labelPInfoId;
	private: System::Windows::Forms::Label^  labelPInfoDescr;
	private: System::Windows::Forms::Label^  labelPInfoCaName;
	private: System::Windows::Forms::Label^  labelPInfoZip;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  buttonChangeDesc;
	private: System::Windows::Forms::TextBox^  textBoxSearchCAId;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBoxSearchIdCA;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  button1;
			 MainSystem * mainS;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  textBoxNewDescription;
	private: System::Windows::Forms::GroupBox^  groupBoxGenerate;
	private: System::Windows::Forms::Button^  buttonConfirmgenerate;
	private: System::Windows::Forms::Label^  label11;


	private: System::Windows::Forms::TextBox^  textBoxNumberOfData;


	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::GroupBox^  groupBoxMain;
	private: System::Windows::Forms::GroupBox^  groupBoxChoose;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  buttonConfirmToMain;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBoxTreeZipCaFile;
	private: System::Windows::Forms::TextBox^  textBoxTreeIdFile;
	private: System::Windows::Forms::TextBox^  textBoxTreeZipCadegree;
	private: System::Windows::Forms::TextBox^  textBoxTeeIdDegree;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  textBoxDataFile;
	private: System::Windows::Forms::GroupBox^  groupBoxOldData;
	private: System::Windows::Forms::Button^  buttonConfirmConfFile;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  textBoxConfFile;
	private: System::Windows::Forms::Button^  buttonSaveConf;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  textBoxSaveConfFileName;
	private: System::Windows::Forms::GroupBox^  groupBoxSequenceUouput;
	private: System::Windows::Forms::ListView^  listViewSequenceOutput;
	private: System::Windows::Forms::Button^  buttonSequenceOutput;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::Button^  buttonSeqOutPutZip;
	private: System::Windows::Forms::Button^  buttonSquOutPrintData;
			 Property * currLoadProperty;
#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->buttonAddProperty = (gcnew System::Windows::Forms::Button());
				 this->groupBoxAddProperty = (gcnew System::Windows::Forms::GroupBox());
				 this->buttonAddNewProperty = (gcnew System::Windows::Forms::Button());
				 this->textBoxPropertyId = (gcnew System::Windows::Forms::TextBox());
				 this->labelPropertyId = (gcnew System::Windows::Forms::Label());
				 this->textBoxPropertyDescription = (gcnew System::Windows::Forms::TextBox());
				 this->labelTitleDescription = (gcnew System::Windows::Forms::Label());
				 this->textBoxNameOfCA = (gcnew System::Windows::Forms::TextBox());
				 this->labelTitleNameOfCA = (gcnew System::Windows::Forms::Label());
				 this->textBoxZipNumber = (gcnew System::Windows::Forms::TextBox());
				 this->labeltITitleZipNumber = (gcnew System::Windows::Forms::Label());
				 this->groupBoxPropertyInfo = (gcnew System::Windows::Forms::GroupBox());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->textBoxNewDescription = (gcnew System::Windows::Forms::TextBox());
				 this->buttonChangeDesc = (gcnew System::Windows::Forms::Button());
				 this->labelPInfoId = (gcnew System::Windows::Forms::Label());
				 this->labelPInfoDescr = (gcnew System::Windows::Forms::Label());
				 this->labelPInfoCaName = (gcnew System::Windows::Forms::Label());
				 this->labelPInfoZip = (gcnew System::Windows::Forms::Label());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->buttonSearchViaId = (gcnew System::Windows::Forms::Button());
				 this->textBoxSeachId = (gcnew System::Windows::Forms::TextBox());
				 this->textBoxSearchCAId = (gcnew System::Windows::Forms::TextBox());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->textBoxSearchIdCA = (gcnew System::Windows::Forms::TextBox());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->groupBoxGenerate = (gcnew System::Windows::Forms::GroupBox());
				 this->buttonConfirmgenerate = (gcnew System::Windows::Forms::Button());
				 this->label11 = (gcnew System::Windows::Forms::Label());
				 this->textBoxNumberOfData = (gcnew System::Windows::Forms::TextBox());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->groupBoxMain = (gcnew System::Windows::Forms::GroupBox());
				 this->buttonSquOutPrintData = (gcnew System::Windows::Forms::Button());
				 this->buttonSeqOutPutZip = (gcnew System::Windows::Forms::Button());
				 this->buttonSequenceOutput = (gcnew System::Windows::Forms::Button());
				 this->label16 = (gcnew System::Windows::Forms::Label());
				 this->textBoxSaveConfFileName = (gcnew System::Windows::Forms::TextBox());
				 this->buttonSaveConf = (gcnew System::Windows::Forms::Button());
				 this->groupBoxSequenceUouput = (gcnew System::Windows::Forms::GroupBox());
				 this->listViewSequenceOutput = (gcnew System::Windows::Forms::ListView());
				 this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
				 this->groupBoxChoose = (gcnew System::Windows::Forms::GroupBox());
				 this->groupBoxOldData = (gcnew System::Windows::Forms::GroupBox());
				 this->buttonConfirmConfFile = (gcnew System::Windows::Forms::Button());
				 this->label15 = (gcnew System::Windows::Forms::Label());
				 this->textBoxConfFile = (gcnew System::Windows::Forms::TextBox());
				 this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 this->label14 = (gcnew System::Windows::Forms::Label());
				 this->textBoxDataFile = (gcnew System::Windows::Forms::TextBox());
				 this->buttonConfirmToMain = (gcnew System::Windows::Forms::Button());
				 this->label13 = (gcnew System::Windows::Forms::Label());
				 this->label12 = (gcnew System::Windows::Forms::Label());
				 this->label10 = (gcnew System::Windows::Forms::Label());
				 this->label9 = (gcnew System::Windows::Forms::Label());
				 this->textBoxTreeZipCaFile = (gcnew System::Windows::Forms::TextBox());
				 this->textBoxTreeIdFile = (gcnew System::Windows::Forms::TextBox());
				 this->textBoxTreeZipCadegree = (gcnew System::Windows::Forms::TextBox());
				 this->textBoxTeeIdDegree = (gcnew System::Windows::Forms::TextBox());
				 this->button4 = (gcnew System::Windows::Forms::Button());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->groupBoxAddProperty->SuspendLayout();
				 this->groupBoxPropertyInfo->SuspendLayout();
				 this->groupBoxGenerate->SuspendLayout();
				 this->groupBoxMain->SuspendLayout();
				 this->groupBoxSequenceUouput->SuspendLayout();
				 this->groupBoxChoose->SuspendLayout();
				 this->groupBoxOldData->SuspendLayout();
				 this->groupBox1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // buttonAddProperty
				 // 
				 this->buttonAddProperty->Location = System::Drawing::Point(9, 15);
				 this->buttonAddProperty->Name = L"buttonAddProperty";
				 this->buttonAddProperty->Size = System::Drawing::Size(150, 23);
				 this->buttonAddProperty->TabIndex = 0;
				 this->buttonAddProperty->Text = L"Pridanie nehnutelnosti";
				 this->buttonAddProperty->UseVisualStyleBackColor = true;
				 this->buttonAddProperty->Click += gcnew System::EventHandler(this, &MyForm::buttonAddProperty_Click);
				 // 
				 // groupBoxAddProperty
				 // 
				 this->groupBoxAddProperty->Controls->Add(this->buttonAddNewProperty);
				 this->groupBoxAddProperty->Controls->Add(this->textBoxPropertyId);
				 this->groupBoxAddProperty->Controls->Add(this->labelPropertyId);
				 this->groupBoxAddProperty->Controls->Add(this->textBoxPropertyDescription);
				 this->groupBoxAddProperty->Controls->Add(this->labelTitleDescription);
				 this->groupBoxAddProperty->Controls->Add(this->textBoxNameOfCA);
				 this->groupBoxAddProperty->Controls->Add(this->labelTitleNameOfCA);
				 this->groupBoxAddProperty->Controls->Add(this->textBoxZipNumber);
				 this->groupBoxAddProperty->Controls->Add(this->labeltITitleZipNumber);
				 this->groupBoxAddProperty->Location = System::Drawing::Point(9, 152);
				 this->groupBoxAddProperty->Name = L"groupBoxAddProperty";
				 this->groupBoxAddProperty->Size = System::Drawing::Size(580, 172);
				 this->groupBoxAddProperty->TabIndex = 1;
				 this->groupBoxAddProperty->TabStop = false;
				 // 
				 // buttonAddNewProperty
				 // 
				 this->buttonAddNewProperty->Location = System::Drawing::Point(419, 75);
				 this->buttonAddNewProperty->Name = L"buttonAddNewProperty";
				 this->buttonAddNewProperty->Size = System::Drawing::Size(130, 23);
				 this->buttonAddNewProperty->TabIndex = 8;
				 this->buttonAddNewProperty->Text = L"Pridat nehnutelnost";
				 this->buttonAddNewProperty->UseVisualStyleBackColor = true;
				 this->buttonAddNewProperty->Click += gcnew System::EventHandler(this, &MyForm::buttonAddNewProperty_Click);
				 // 
				 // textBoxPropertyId
				 // 
				 this->textBoxPropertyId->Location = System::Drawing::Point(216, 134);
				 this->textBoxPropertyId->Name = L"textBoxPropertyId";
				 this->textBoxPropertyId->Size = System::Drawing::Size(183, 20);
				 this->textBoxPropertyId->TabIndex = 7;
				 // 
				 // labelPropertyId
				 // 
				 this->labelPropertyId->AutoSize = true;
				 this->labelPropertyId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->labelPropertyId->Location = System::Drawing::Point(7, 138);
				 this->labelPropertyId->Name = L"labelPropertyId";
				 this->labelPropertyId->Size = System::Drawing::Size(137, 16);
				 this->labelPropertyId->TabIndex = 6;
				 this->labelPropertyId->Text = L"Identifikacne cislo:";
				 // 
				 // textBoxPropertyDescription
				 // 
				 this->textBoxPropertyDescription->Location = System::Drawing::Point(216, 95);
				 this->textBoxPropertyDescription->Name = L"textBoxPropertyDescription";
				 this->textBoxPropertyDescription->Size = System::Drawing::Size(183, 20);
				 this->textBoxPropertyDescription->TabIndex = 5;
				 // 
				 // labelTitleDescription
				 // 
				 this->labelTitleDescription->AutoSize = true;
				 this->labelTitleDescription->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
				 this->labelTitleDescription->Location = System::Drawing::Point(7, 99);
				 this->labelTitleDescription->Name = L"labelTitleDescription";
				 this->labelTitleDescription->Size = System::Drawing::Size(147, 16);
				 this->labelTitleDescription->TabIndex = 4;
				 this->labelTitleDescription->Text = L"Popis nehnutelnosti:";
				 // 
				 // textBoxNameOfCA
				 // 
				 this->textBoxNameOfCA->Location = System::Drawing::Point(216, 56);
				 this->textBoxNameOfCA->Name = L"textBoxNameOfCA";
				 this->textBoxNameOfCA->Size = System::Drawing::Size(183, 20);
				 this->textBoxNameOfCA->TabIndex = 3;
				 // 
				 // labelTitleNameOfCA
				 // 
				 this->labelTitleNameOfCA->AutoSize = true;
				 this->labelTitleNameOfCA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->labelTitleNameOfCA->Location = System::Drawing::Point(7, 60);
				 this->labelTitleNameOfCA->Name = L"labelTitleNameOfCA";
				 this->labelTitleNameOfCA->Size = System::Drawing::Size(207, 16);
				 this->labelTitleNameOfCA->TabIndex = 2;
				 this->labelTitleNameOfCA->Text = L"Nazov katastralneho uzemia:";
				 // 
				 // textBoxZipNumber
				 // 
				 this->textBoxZipNumber->Location = System::Drawing::Point(215, 12);
				 this->textBoxZipNumber->Name = L"textBoxZipNumber";
				 this->textBoxZipNumber->Size = System::Drawing::Size(183, 20);
				 this->textBoxZipNumber->TabIndex = 1;
				 // 
				 // labeltITitleZipNumber
				 // 
				 this->labeltITitleZipNumber->AutoSize = true;
				 this->labeltITitleZipNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold,
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
				 this->labeltITitleZipNumber->Location = System::Drawing::Point(6, 16);
				 this->labeltITitleZipNumber->Name = L"labeltITitleZipNumber";
				 this->labeltITitleZipNumber->Size = System::Drawing::Size(105, 16);
				 this->labeltITitleZipNumber->TabIndex = 0;
				 this->labeltITitleZipNumber->Text = L"Supisne cislo:";
				 // 
				 // groupBoxPropertyInfo
				 // 
				 this->groupBoxPropertyInfo->Controls->Add(this->label8);
				 this->groupBoxPropertyInfo->Controls->Add(this->textBoxNewDescription);
				 this->groupBoxPropertyInfo->Controls->Add(this->buttonChangeDesc);
				 this->groupBoxPropertyInfo->Controls->Add(this->labelPInfoId);
				 this->groupBoxPropertyInfo->Controls->Add(this->labelPInfoDescr);
				 this->groupBoxPropertyInfo->Controls->Add(this->labelPInfoCaName);
				 this->groupBoxPropertyInfo->Controls->Add(this->labelPInfoZip);
				 this->groupBoxPropertyInfo->Controls->Add(this->label1);
				 this->groupBoxPropertyInfo->Controls->Add(this->label2);
				 this->groupBoxPropertyInfo->Controls->Add(this->label3);
				 this->groupBoxPropertyInfo->Controls->Add(this->label4);
				 this->groupBoxPropertyInfo->Location = System::Drawing::Point(9, 146);
				 this->groupBoxPropertyInfo->Name = L"groupBoxPropertyInfo";
				 this->groupBoxPropertyInfo->Size = System::Drawing::Size(580, 172);
				 this->groupBoxPropertyInfo->TabIndex = 4;
				 this->groupBoxPropertyInfo->TabStop = false;
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label8->Location = System::Drawing::Point(390, 68);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(74, 13);
				 this->label8->TabIndex = 13;
				 this->label8->Text = L"Novy popis:";
				 // 
				 // textBoxNewDescription
				 // 
				 this->textBoxNewDescription->Location = System::Drawing::Point(393, 88);
				 this->textBoxNewDescription->Name = L"textBoxNewDescription";
				 this->textBoxNewDescription->Size = System::Drawing::Size(181, 20);
				 this->textBoxNewDescription->TabIndex = 12;
				 // 
				 // buttonChangeDesc
				 // 
				 this->buttonChangeDesc->Location = System::Drawing::Point(321, 88);
				 this->buttonChangeDesc->Name = L"buttonChangeDesc";
				 this->buttonChangeDesc->Size = System::Drawing::Size(52, 23);
				 this->buttonChangeDesc->TabIndex = 11;
				 this->buttonChangeDesc->Text = L"Zmen";
				 this->buttonChangeDesc->UseVisualStyleBackColor = true;
				 this->buttonChangeDesc->Click += gcnew System::EventHandler(this, &MyForm::buttonChangeDesc_Click);
				 // 
				 // labelPInfoId
				 // 
				 this->labelPInfoId->AutoSize = true;
				 this->labelPInfoId->Location = System::Drawing::Point(150, 127);
				 this->labelPInfoId->Name = L"labelPInfoId";
				 this->labelPInfoId->Size = System::Drawing::Size(35, 13);
				 this->labelPInfoId->TabIndex = 10;
				 this->labelPInfoId->Text = L"label5";
				 // 
				 // labelPInfoDescr
				 // 
				 this->labelPInfoDescr->AutoSize = true;
				 this->labelPInfoDescr->Location = System::Drawing::Point(160, 88);
				 this->labelPInfoDescr->Name = L"labelPInfoDescr";
				 this->labelPInfoDescr->Size = System::Drawing::Size(35, 13);
				 this->labelPInfoDescr->TabIndex = 9;
				 this->labelPInfoDescr->Text = L"label5";
				 // 
				 // labelPInfoCaName
				 // 
				 this->labelPInfoCaName->AutoSize = true;
				 this->labelPInfoCaName->Location = System::Drawing::Point(220, 50);
				 this->labelPInfoCaName->Name = L"labelPInfoCaName";
				 this->labelPInfoCaName->Size = System::Drawing::Size(35, 13);
				 this->labelPInfoCaName->TabIndex = 8;
				 this->labelPInfoCaName->Text = L"label5";
				 // 
				 // labelPInfoZip
				 // 
				 this->labelPInfoZip->AutoSize = true;
				 this->labelPInfoZip->Location = System::Drawing::Point(118, 3);
				 this->labelPInfoZip->Name = L"labelPInfoZip";
				 this->labelPInfoZip->Size = System::Drawing::Size(35, 13);
				 this->labelPInfoZip->TabIndex = 7;
				 this->labelPInfoZip->Text = L"label5";
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label1->Location = System::Drawing::Point(7, 125);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(137, 16);
				 this->label1->TabIndex = 6;
				 this->label1->Text = L"Identifikacne cislo:";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label2->Location = System::Drawing::Point(7, 86);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(147, 16);
				 this->label2->TabIndex = 4;
				 this->label2->Text = L"Popis nehnutelnosti:";
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label3->Location = System::Drawing::Point(7, 47);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(207, 16);
				 this->label3->TabIndex = 2;
				 this->label3->Text = L"Nazov katastralneho uzemia:";
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label4->Location = System::Drawing::Point(6, 3);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(105, 16);
				 this->label4->TabIndex = 0;
				 this->label4->Text = L"Supisne cislo:";
				 // 
				 // buttonSearchViaId
				 // 
				 this->buttonSearchViaId->Location = System::Drawing::Point(307, 33);
				 this->buttonSearchViaId->Name = L"buttonSearchViaId";
				 this->buttonSearchViaId->Size = System::Drawing::Size(137, 23);
				 this->buttonSearchViaId->TabIndex = 2;
				 this->buttonSearchViaId->Text = L"Hladaj pomocou ID";
				 this->buttonSearchViaId->UseVisualStyleBackColor = true;
				 this->buttonSearchViaId->Click += gcnew System::EventHandler(this, &MyForm::buttonSearchViaId_Click);
				 // 
				 // textBoxSeachId
				 // 
				 this->textBoxSeachId->Location = System::Drawing::Point(460, 35);
				 this->textBoxSeachId->Name = L"textBoxSeachId";
				 this->textBoxSeachId->Size = System::Drawing::Size(42, 20);
				 this->textBoxSeachId->TabIndex = 3;
				 // 
				 // textBoxSearchCAId
				 // 
				 this->textBoxSearchCAId->Location = System::Drawing::Point(460, 79);
				 this->textBoxSearchCAId->Name = L"textBoxSearchCAId";
				 this->textBoxSearchCAId->Size = System::Drawing::Size(42, 20);
				 this->textBoxSearchCAId->TabIndex = 5;
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label5->Location = System::Drawing::Point(460, 16);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(24, 13);
				 this->label5->TabIndex = 6;
				 this->label5->Text = L"ID:";
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label6->Location = System::Drawing::Point(460, 63);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(31, 13);
				 this->label6->TabIndex = 7;
				 this->label6->Text = L"ZIP:";
				 // 
				 // textBoxSearchIdCA
				 // 
				 this->textBoxSearchIdCA->Location = System::Drawing::Point(516, 79);
				 this->textBoxSearchIdCA->Name = L"textBoxSearchIdCA";
				 this->textBoxSearchIdCA->Size = System::Drawing::Size(73, 20);
				 this->textBoxSearchIdCA->TabIndex = 8;
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label7->Location = System::Drawing::Point(513, 63);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(73, 13);
				 this->label7->TabIndex = 9;
				 this->label7->Text = L"Kat. uzemie";
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(307, 76);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(137, 23);
				 this->button1->TabIndex = 10;
				 this->button1->Text = L"Hladaj pomocou ZIP a K.u.";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
				 // 
				 // groupBoxGenerate
				 // 
				 this->groupBoxGenerate->Controls->Add(this->buttonConfirmgenerate);
				 this->groupBoxGenerate->Controls->Add(this->label11);
				 this->groupBoxGenerate->Controls->Add(this->textBoxNumberOfData);
				 this->groupBoxGenerate->Location = System::Drawing::Point(9, 73);
				 this->groupBoxGenerate->Name = L"groupBoxGenerate";
				 this->groupBoxGenerate->Size = System::Drawing::Size(153, 67);
				 this->groupBoxGenerate->TabIndex = 11;
				 this->groupBoxGenerate->TabStop = false;
				 // 
				 // buttonConfirmgenerate
				 // 
				 this->buttonConfirmgenerate->Location = System::Drawing::Point(80, 29);
				 this->buttonConfirmgenerate->Name = L"buttonConfirmgenerate";
				 this->buttonConfirmgenerate->Size = System::Drawing::Size(52, 23);
				 this->buttonConfirmgenerate->TabIndex = 6;
				 this->buttonConfirmgenerate->Text = L"Generuj";
				 this->buttonConfirmgenerate->UseVisualStyleBackColor = true;
				 this->buttonConfirmgenerate->Click += gcnew System::EventHandler(this, &MyForm::buttonConfirmgenerate_Click);
				 // 
				 // label11
				 // 
				 this->label11->AutoSize = true;
				 this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label11->Location = System::Drawing::Point(12, 13);
				 this->label11->Name = L"label11";
				 this->label11->Size = System::Drawing::Size(40, 13);
				 this->label11->TabIndex = 5;
				 this->label11->Text = L"Pocet";
				 // 
				 // textBoxNumberOfData
				 // 
				 this->textBoxNumberOfData->Location = System::Drawing::Point(9, 32);
				 this->textBoxNumberOfData->Name = L"textBoxNumberOfData";
				 this->textBoxNumberOfData->Size = System::Drawing::Size(50, 20);
				 this->textBoxNumberOfData->TabIndex = 2;
				 // 
				 // button2
				 // 
				 this->button2->Location = System::Drawing::Point(9, 44);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(75, 23);
				 this->button2->TabIndex = 12;
				 this->button2->Text = L"Generator";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
				 // 
				 // groupBoxMain
				 // 
				 this->groupBoxMain->Controls->Add(this->buttonSquOutPrintData);
				 this->groupBoxMain->Controls->Add(this->buttonSeqOutPutZip);
				 this->groupBoxMain->Controls->Add(this->buttonSequenceOutput);
				 this->groupBoxMain->Controls->Add(this->label16);
				 this->groupBoxMain->Controls->Add(this->textBoxSaveConfFileName);
				 this->groupBoxMain->Controls->Add(this->buttonSaveConf);
				 this->groupBoxMain->Controls->Add(this->label5);
				 this->groupBoxMain->Controls->Add(this->button2);
				 this->groupBoxMain->Controls->Add(this->groupBoxAddProperty);
				 this->groupBoxMain->Controls->Add(this->groupBoxGenerate);
				 this->groupBoxMain->Controls->Add(this->groupBoxPropertyInfo);
				 this->groupBoxMain->Controls->Add(this->button1);
				 this->groupBoxMain->Controls->Add(this->buttonAddProperty);
				 this->groupBoxMain->Controls->Add(this->label7);
				 this->groupBoxMain->Controls->Add(this->buttonSearchViaId);
				 this->groupBoxMain->Controls->Add(this->textBoxSearchIdCA);
				 this->groupBoxMain->Controls->Add(this->textBoxSeachId);
				 this->groupBoxMain->Controls->Add(this->label6);
				 this->groupBoxMain->Controls->Add(this->textBoxSearchCAId);
				 this->groupBoxMain->Controls->Add(this->groupBoxSequenceUouput);
				 this->groupBoxMain->Location = System::Drawing::Point(12, 12);
				 this->groupBoxMain->Name = L"groupBoxMain";
				 this->groupBoxMain->Size = System::Drawing::Size(599, 360);
				 this->groupBoxMain->TabIndex = 13;
				 this->groupBoxMain->TabStop = false;
				 // 
				 // buttonSquOutPrintData
				 // 
				 this->buttonSquOutPrintData->Location = System::Drawing::Point(152, 131);
				 this->buttonSquOutPrintData->Name = L"buttonSquOutPrintData";
				 this->buttonSquOutPrintData->Size = System::Drawing::Size(121, 23);
				 this->buttonSquOutPrintData->TabIndex = 18;
				 this->buttonSquOutPrintData->Text = L"Sekvencny vypis data";
				 this->buttonSquOutPrintData->UseVisualStyleBackColor = true;
				 this->buttonSquOutPrintData->Click += gcnew System::EventHandler(this, &MyForm::buttonSquOutPrintData_Click);
				 // 
				 // buttonSeqOutPutZip
				 // 
				 this->buttonSeqOutPutZip->Location = System::Drawing::Point(279, 132);
				 this->buttonSeqOutPutZip->Name = L"buttonSeqOutPutZip";
				 this->buttonSeqOutPutZip->Size = System::Drawing::Size(154, 22);
				 this->buttonSeqOutPutZip->TabIndex = 17;
				 this->buttonSeqOutPutZip->Text = L"Sekvencny vypis strom zip";
				 this->buttonSeqOutPutZip->UseVisualStyleBackColor = true;
				 this->buttonSeqOutPutZip->Click += gcnew System::EventHandler(this, &MyForm::buttonSeqOutPutZip_Click);
				 // 
				 // buttonSequenceOutput
				 // 
				 this->buttonSequenceOutput->Location = System::Drawing::Point(439, 132);
				 this->buttonSequenceOutput->Name = L"buttonSequenceOutput";
				 this->buttonSequenceOutput->Size = System::Drawing::Size(154, 22);
				 this->buttonSequenceOutput->TabIndex = 16;
				 this->buttonSequenceOutput->Text = L"Sekvencny vypis strom id";
				 this->buttonSequenceOutput->UseVisualStyleBackColor = true;
				 this->buttonSequenceOutput->Click += gcnew System::EventHandler(this, &MyForm::buttonSequenceOutput_Click);
				 // 
				 // label16
				 // 
				 this->label16->AutoSize = true;
				 this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label16->Location = System::Drawing::Point(274, 335);
				 this->label16->Name = L"label16";
				 this->label16->Size = System::Drawing::Size(122, 13);
				 this->label16->TabIndex = 15;
				 this->label16->Text = L"Nazov conf. suboru:";
				 // 
				 // textBoxSaveConfFileName
				 // 
				 this->textBoxSaveConfFileName->Location = System::Drawing::Point(402, 332);
				 this->textBoxSaveConfFileName->Name = L"textBoxSaveConfFileName";
				 this->textBoxSaveConfFileName->Size = System::Drawing::Size(100, 20);
				 this->textBoxSaveConfFileName->TabIndex = 14;
				 // 
				 // buttonSaveConf
				 // 
				 this->buttonSaveConf->Location = System::Drawing::Point(511, 330);
				 this->buttonSaveConf->Name = L"buttonSaveConf";
				 this->buttonSaveConf->Size = System::Drawing::Size(75, 23);
				 this->buttonSaveConf->TabIndex = 13;
				 this->buttonSaveConf->Text = L"Ulozit";
				 this->buttonSaveConf->UseVisualStyleBackColor = true;
				 this->buttonSaveConf->Click += gcnew System::EventHandler(this, &MyForm::buttonSaveConf_Click);
				 // 
				 // groupBoxSequenceUouput
				 // 
				 this->groupBoxSequenceUouput->Controls->Add(this->listViewSequenceOutput);
				 this->groupBoxSequenceUouput->Location = System::Drawing::Point(9, 150);
				 this->groupBoxSequenceUouput->Name = L"groupBoxSequenceUouput";
				 this->groupBoxSequenceUouput->Size = System::Drawing::Size(584, 174);
				 this->groupBoxSequenceUouput->TabIndex = 9;
				 this->groupBoxSequenceUouput->TabStop = false;
				 // 
				 // listViewSequenceOutput
				 // 
				 this->listViewSequenceOutput->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->columnHeader1 });
				 this->listViewSequenceOutput->GridLines = true;
				 this->listViewSequenceOutput->Location = System::Drawing::Point(6, 10);
				 this->listViewSequenceOutput->Name = L"listViewSequenceOutput";
				 this->listViewSequenceOutput->Size = System::Drawing::Size(568, 158);
				 this->listViewSequenceOutput->TabIndex = 0;
				 this->listViewSequenceOutput->UseCompatibleStateImageBehavior = false;
				 this->listViewSequenceOutput->View = System::Windows::Forms::View::Details;
				 // 
				 // columnHeader1
				 // 
				 this->columnHeader1->Text = L"Data";
				 this->columnHeader1->Width = 2500;
				 // 
				 // groupBoxChoose
				 // 
				 this->groupBoxChoose->Controls->Add(this->groupBoxOldData);
				 this->groupBoxChoose->Controls->Add(this->groupBox1);
				 this->groupBoxChoose->Controls->Add(this->button4);
				 this->groupBoxChoose->Controls->Add(this->button3);
				 this->groupBoxChoose->Location = System::Drawing::Point(-2, 0);
				 this->groupBoxChoose->Name = L"groupBoxChoose";
				 this->groupBoxChoose->Size = System::Drawing::Size(633, 393);
				 this->groupBoxChoose->TabIndex = 14;
				 this->groupBoxChoose->TabStop = false;
				 // 
				 // groupBoxOldData
				 // 
				 this->groupBoxOldData->Controls->Add(this->buttonConfirmConfFile);
				 this->groupBoxOldData->Controls->Add(this->label15);
				 this->groupBoxOldData->Controls->Add(this->textBoxConfFile);
				 this->groupBoxOldData->Location = System::Drawing::Point(136, 52);
				 this->groupBoxOldData->Name = L"groupBoxOldData";
				 this->groupBoxOldData->Size = System::Drawing::Size(345, 59);
				 this->groupBoxOldData->TabIndex = 3;
				 this->groupBoxOldData->TabStop = false;
				 // 
				 // buttonConfirmConfFile
				 // 
				 this->buttonConfirmConfFile->Location = System::Drawing::Point(257, 16);
				 this->buttonConfirmConfFile->Name = L"buttonConfirmConfFile";
				 this->buttonConfirmConfFile->Size = System::Drawing::Size(75, 20);
				 this->buttonConfirmConfFile->TabIndex = 2;
				 this->buttonConfirmConfFile->Text = L"Potvrdit";
				 this->buttonConfirmConfFile->UseVisualStyleBackColor = true;
				 this->buttonConfirmConfFile->Click += gcnew System::EventHandler(this, &MyForm::buttonConfirmConfFile_Click);
				 // 
				 // label15
				 // 
				 this->label15->AutoSize = true;
				 this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label15->Location = System::Drawing::Point(8, 20);
				 this->label15->Name = L"label15";
				 this->label15->Size = System::Drawing::Size(122, 13);
				 this->label15->TabIndex = 1;
				 this->label15->Text = L"Nazov conf. suboru:";
				 // 
				 // textBoxConfFile
				 // 
				 this->textBoxConfFile->Location = System::Drawing::Point(134, 16);
				 this->textBoxConfFile->Name = L"textBoxConfFile";
				 this->textBoxConfFile->Size = System::Drawing::Size(100, 20);
				 this->textBoxConfFile->TabIndex = 0;
				 // 
				 // groupBox1
				 // 
				 this->groupBox1->Controls->Add(this->label14);
				 this->groupBox1->Controls->Add(this->textBoxDataFile);
				 this->groupBox1->Controls->Add(this->buttonConfirmToMain);
				 this->groupBox1->Controls->Add(this->label13);
				 this->groupBox1->Controls->Add(this->label12);
				 this->groupBox1->Controls->Add(this->label10);
				 this->groupBox1->Controls->Add(this->label9);
				 this->groupBox1->Controls->Add(this->textBoxTreeZipCaFile);
				 this->groupBox1->Controls->Add(this->textBoxTreeIdFile);
				 this->groupBox1->Controls->Add(this->textBoxTreeZipCadegree);
				 this->groupBox1->Controls->Add(this->textBoxTeeIdDegree);
				 this->groupBox1->Location = System::Drawing::Point(136, 144);
				 this->groupBox1->Name = L"groupBox1";
				 this->groupBox1->Size = System::Drawing::Size(345, 243);
				 this->groupBox1->TabIndex = 2;
				 this->groupBox1->TabStop = false;
				 // 
				 // label14
				 // 
				 this->label14->AutoSize = true;
				 this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label14->Location = System::Drawing::Point(16, 169);
				 this->label14->Name = L"label14";
				 this->label14->Size = System::Drawing::Size(180, 13);
				 this->label14->TabIndex = 9;
				 this->label14->Text = L"Nazov suboru pre druhy strom:";
				 // 
				 // textBoxDataFile
				 // 
				 this->textBoxDataFile->Location = System::Drawing::Point(262, 166);
				 this->textBoxDataFile->Name = L"textBoxDataFile";
				 this->textBoxDataFile->Size = System::Drawing::Size(77, 20);
				 this->textBoxDataFile->TabIndex = 8;
				 // 
				 // buttonConfirmToMain
				 // 
				 this->buttonConfirmToMain->Location = System::Drawing::Point(134, 205);
				 this->buttonConfirmToMain->Name = L"buttonConfirmToMain";
				 this->buttonConfirmToMain->Size = System::Drawing::Size(75, 23);
				 this->buttonConfirmToMain->TabIndex = 8;
				 this->buttonConfirmToMain->Text = L"Potvrdit";
				 this->buttonConfirmToMain->UseVisualStyleBackColor = true;
				 this->buttonConfirmToMain->Click += gcnew System::EventHandler(this, &MyForm::buttonConfirmToMain_Click);
				 // 
				 // label13
				 // 
				 this->label13->AutoSize = true;
				 this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label13->Location = System::Drawing::Point(16, 132);
				 this->label13->Name = L"label13";
				 this->label13->Size = System::Drawing::Size(180, 13);
				 this->label13->TabIndex = 7;
				 this->label13->Text = L"Nazov suboru pre druhy strom:";
				 // 
				 // label12
				 // 
				 this->label12->AutoSize = true;
				 this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label12->Location = System::Drawing::Point(16, 93);
				 this->label12->Name = L"label12";
				 this->label12->Size = System::Drawing::Size(173, 13);
				 this->label12->TabIndex = 6;
				 this->label12->Text = L"Nazov suboru pre prvy strom:";
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label10->Location = System::Drawing::Point(16, 58);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(227, 13);
				 this->label10->TabIndex = 5;
				 this->label10->Text = L"Rad stromu s klucom Zip a nazov K.u.:";
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label9->Location = System::Drawing::Point(16, 25);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(144, 13);
				 this->label9->TabIndex = 4;
				 this->label9->Text = L"Rad stromu s klucom Id:";
				 // 
				 // textBoxTreeZipCaFile
				 // 
				 this->textBoxTreeZipCaFile->Location = System::Drawing::Point(262, 129);
				 this->textBoxTreeZipCaFile->Name = L"textBoxTreeZipCaFile";
				 this->textBoxTreeZipCaFile->Size = System::Drawing::Size(77, 20);
				 this->textBoxTreeZipCaFile->TabIndex = 3;
				 // 
				 // textBoxTreeIdFile
				 // 
				 this->textBoxTreeIdFile->Location = System::Drawing::Point(262, 90);
				 this->textBoxTreeIdFile->Name = L"textBoxTreeIdFile";
				 this->textBoxTreeIdFile->Size = System::Drawing::Size(77, 20);
				 this->textBoxTreeIdFile->TabIndex = 2;
				 // 
				 // textBoxTreeZipCadegree
				 // 
				 this->textBoxTreeZipCadegree->Location = System::Drawing::Point(262, 53);
				 this->textBoxTreeZipCadegree->Name = L"textBoxTreeZipCadegree";
				 this->textBoxTreeZipCadegree->Size = System::Drawing::Size(77, 20);
				 this->textBoxTreeZipCadegree->TabIndex = 1;
				 // 
				 // textBoxTeeIdDegree
				 // 
				 this->textBoxTeeIdDegree->Location = System::Drawing::Point(262, 18);
				 this->textBoxTeeIdDegree->Name = L"textBoxTeeIdDegree";
				 this->textBoxTeeIdDegree->Size = System::Drawing::Size(77, 20);
				 this->textBoxTeeIdDegree->TabIndex = 0;
				 // 
				 // button4
				 // 
				 this->button4->Location = System::Drawing::Point(136, 23);
				 this->button4->Name = L"button4";
				 this->button4->Size = System::Drawing::Size(345, 23);
				 this->button4->TabIndex = 1;
				 this->button4->Text = L"Pouzit stare data";
				 this->button4->UseVisualStyleBackColor = true;
				 this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
				 // 
				 // button3
				 // 
				 this->button3->Location = System::Drawing::Point(136, 115);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(345, 23);
				 this->button3->TabIndex = 0;
				 this->button3->Text = L"Nove data";
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(643, 405);
				 this->Controls->Add(this->groupBoxMain);
				 this->Controls->Add(this->groupBoxChoose);
				 this->Name = L"MyForm";
				 this->Text = L"MyForm";
				 this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				 this->groupBoxAddProperty->ResumeLayout(false);
				 this->groupBoxAddProperty->PerformLayout();
				 this->groupBoxPropertyInfo->ResumeLayout(false);
				 this->groupBoxPropertyInfo->PerformLayout();
				 this->groupBoxGenerate->ResumeLayout(false);
				 this->groupBoxGenerate->PerformLayout();
				 this->groupBoxMain->ResumeLayout(false);
				 this->groupBoxMain->PerformLayout();
				 this->groupBoxSequenceUouput->ResumeLayout(false);
				 this->groupBoxChoose->ResumeLayout(false);
				 this->groupBoxOldData->ResumeLayout(false);
				 this->groupBoxOldData->PerformLayout();
				 this->groupBox1->ResumeLayout(false);
				 this->groupBox1->PerformLayout();
				 this->ResumeLayout(false);

			 }
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		groupBoxOldData->Hide();
		groupBoxMain->Hide();
		groupBoxGenerate->Hide();
		groupBoxPropertyInfo->Hide();
		groupBox1->Hide();
		groupBoxSequenceUouput->Hide();
		this->groupBoxAddProperty->Hide();
	}
	private: System::Void buttonAddProperty_Click(System::Object^  sender, System::EventArgs^  e) {
		groupBoxPropertyInfo->Hide();
		this->groupBoxAddProperty->Show();
	}
	private: System::Void buttonAddNewProperty_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBoxNameOfCA->Text->Length > 0 && textBoxPropertyDescription->Text->Length > 0 && textBoxPropertyId->Text->Length > 0 && textBoxZipNumber->Text->Length > 0) {

			std::string nameOfCa = msclr::interop::marshal_as<std::string>(textBoxNameOfCA->Text);
			std::string description = msclr::interop::marshal_as<std::string>(textBoxPropertyDescription->Text);
			int idNumner = std::stoi(msclr::interop::marshal_as<std::string>(textBoxPropertyId->Text));
			int zipNumner = std::stoi(msclr::interop::marshal_as<std::string>(textBoxZipNumber->Text));

			if (mainS->addProperty(idNumner, zipNumner, nameOfCa, description) == true) {
				System::Windows::Forms::MessageBox::Show("Pridanie prebehlo uspesne.");
			}
			else {
				System::Windows::Forms::MessageBox::Show("Pridanie sa nezdarilo.");
			}
		}
		else {
			System::Windows::Forms::MessageBox::Show("Musia by vyplnené všetky polia.");
		}
	}
	private: System::Void buttonSearchViaId_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBoxSeachId->Text->Length > 0) {
			int idNumner = std::stoi(msclr::interop::marshal_as<std::string>(textBoxSeachId->Text));
			Property *fProperty = mainS->searchPropertyViaId(idNumner);

			if (fProperty != nullptr) {
				this->setCurrLoadProperty(fProperty);
				groupBoxAddProperty->Hide();
				groupBoxPropertyInfo->Show();

				labelPInfoCaName->Text = gcnew String(fProperty->getCatasterName().c_str());
				labelPInfoDescr->Text = gcnew String(fProperty->getDescription().c_str());
				labelPInfoId->Text = gcnew String(std::to_string(fProperty->getIdNumber()).c_str());
				labelPInfoZip->Text = gcnew String(std::to_string(fProperty->getZIPNumber()).c_str());
			}
			else {
				System::Windows::Forms::MessageBox::Show("Zadana nehnutelnost neexistuje.");
			}
		}
		else {
			System::Windows::Forms::MessageBox::Show("Musite zadat id.");
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBoxSearchCAId->Text->Length > 0 && textBoxSearchIdCA->Text->Length > 0) {
			int idNumner = std::stoi(msclr::interop::marshal_as<std::string>(textBoxSearchCAId->Text));
			std::string nameOfCa = msclr::interop::marshal_as<std::string>(textBoxSearchIdCA->Text);

			Property *fProperty = mainS->searchPropertyViaIdanCA(idNumner, nameOfCa);

			if (fProperty != nullptr) {
				this->setCurrLoadProperty(fProperty);
				groupBoxAddProperty->Hide();
				groupBoxPropertyInfo->Show();

				labelPInfoCaName->Text = gcnew String(fProperty->getCatasterName().c_str());
				labelPInfoDescr->Text = gcnew String(fProperty->getDescription().c_str());
				labelPInfoId->Text = gcnew String(std::to_string(fProperty->getIdNumber()).c_str());
				labelPInfoZip->Text = gcnew String(std::to_string(fProperty->getZIPNumber()).c_str());
			}
			else {
				System::Windows::Forms::MessageBox::Show("Zadana nehnutelnost neexistuje.");
			}
		}
		else {
			System::Windows::Forms::MessageBox::Show("Musia by vyplnené všetky polia.");
		}
	}
	private: System::Void buttonChangeDesc_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBoxNewDescription->Text->Length > 0) {
			std::string newDesc = msclr::interop::marshal_as<std::string>(textBoxNewDescription->Text);
			if (mainS->setDescription(newDesc, this->getCurrLoadProperty()) == true) {
				System::Windows::Forms::MessageBox::Show("Zmena prebehla uspesne.");
			}
		}
		else {
			System::Windows::Forms::MessageBox::Show("Zadajte novy popis.");
		}
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		groupBoxGenerate->Show();
	}
	private: System::Void buttonConfirmgenerate_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBoxNumberOfData->Text->Length > 0) {
			int numberOfData = std::stoi(msclr::interop::marshal_as<std::string>(textBoxNumberOfData->Text));

			mainS->generateData(numberOfData);
			System::Windows::Forms::MessageBox::Show("Generovanie sa podarilo.");
			groupBoxGenerate->Hide();
		}
		else {
			System::Windows::Forms::MessageBox::Show("Generovanie sa nepodarilo.");
		}
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		groupBox1->Show();
	}
	private: System::Void buttonConfirmToMain_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textBoxTeeIdDegree->Text->Length > 0 && textBoxTreeIdFile->Text->Length > 0 && textBoxTreeZipCadegree->Text->Length > 0 && textBoxTreeZipCaFile->Text->Length > 0 && textBoxDataFile->Text->Length > 0) {
			int idTreeDegree = std::stoi(msclr::interop::marshal_as<std::string>(textBoxTeeIdDegree->Text));
			int zipTreeDegree = std::stoi(msclr::interop::marshal_as<std::string>(textBoxTreeZipCadegree->Text));
			std::string idTreeFile = msclr::interop::marshal_as<std::string>(textBoxTreeIdFile->Text);
			std::string zipTreeFile = msclr::interop::marshal_as<std::string>(textBoxTreeZipCaFile->Text);
			std::string dataFile = msclr::interop::marshal_as<std::string>(textBoxDataFile->Text);

			mainS = new MainSystem(idTreeDegree, zipTreeDegree, dataFile, idTreeFile, zipTreeFile);
			
			System::Windows::Forms::MessageBox::Show("Uspesne bol vytvoreny novy system.");
			groupBoxChoose->Hide();
			groupBoxMain->Show();
		}
		else {
			System::Windows::Forms::MessageBox::Show("Musia by vyplnené všetky polia.");
		}
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		groupBoxOldData->Show();
	}
	private: System::Void buttonConfirmConfFile_Click(System::Object^  sender, System::EventArgs^  e) {
		button2->Hide();
		if (textBoxConfFile->Text->Length > 0) {
			std::string confFile = msclr::interop::marshal_as<std::string>(textBoxConfFile->Text);
			mainS = new MainSystem();
			mainS->readConf("conf.txt");
			System::Windows::Forms::MessageBox::Show("Stare data sa uspesne nacitali!");
			groupBoxChoose->Hide();
			groupBoxMain->Show();
		}
		else {
			System::Windows::Forms::MessageBox::Show("Vyplnte nazov conf.suboru!");
		}
	}
private: System::Void buttonSaveConf_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string confFile = msclr::interop::marshal_as<std::string>(textBoxSaveConfFileName->Text);
	mainS->saveConf(confFile);
	System::Windows::Forms::MessageBox::Show("Uspesne ste ulozili conf. subor!");
}
private: System::Void buttonSequenceOutput_Click(System::Object^  sender, System::EventArgs^  e) {
	groupBoxAddProperty->Hide();
	groupBoxPropertyInfo->Hide();
	groupBoxSequenceUouput->Show();

	listViewSequenceOutput->Items->Clear();
	this->printSequenceData(mainS->getPropertiesViaIdFile(),mainS->getPropertiesViaID()->getSequenceBlocks());
}
private: System::Void buttonSeqOutPutZip_Click(System::Object^  sender, System::EventArgs^  e) {
	groupBoxAddProperty->Hide();
	groupBoxPropertyInfo->Hide();
	groupBoxSequenceUouput->Show();

	listViewSequenceOutput->Items->Clear();
	this->printSequenceData(mainS->getPropertiesViaIdAndCAFile(), mainS->getPropertiesViaIDandCA()->getSequenceBlocks());
}
private: System::Void buttonSquOutPrintData_Click(System::Object^  sender, System::EventArgs^  e) {
	groupBoxAddProperty->Hide();
	groupBoxPropertyInfo->Hide();
	groupBoxSequenceUouput->Show();

	listViewSequenceOutput->Items->Clear();
	this->printSequenceData();
}
};
};

