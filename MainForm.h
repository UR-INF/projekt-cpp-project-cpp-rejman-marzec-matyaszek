#pragma once
#include <cliext/vector>
#include <vector>
#include <time.h>
#include "SudokuBoard.cpp"
#include <string>
#include <msclr/marshal_cppstd.h>
#include <fstream>
#include "Result.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;

namespace Win32 {
	[DllImport("kernel32.dll", CallingConvention = CallingConvention::StdCall)]
	int AllocConsole();
	[DllImport("kernel32.dll", CallingConvention = CallingConvention::StdCall)]
	int FreeConsole();
}
namespace Sudoku {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ newGameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::Panel^ innerMainPanel;
	private: System::Windows::Forms::Panel^ settingsPanel;

	private: System::Windows::Forms::Label^ timeLabel;
	private: System::Windows::Forms::Button^ button1;

	TableLayoutPanel^ board;
	cliext::vector<TextBox^> fields;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ numberOfTips;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::ToolStripMenuItem^ easyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ mediumToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ hardToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ timeLimit;

	private: System::Windows::Forms::ToolStripMenuItem^ min1;
	private: System::Windows::Forms::ToolStripMenuItem^ min3;
	private: System::Windows::Forms::ToolStripMenuItem^ min5;
	private: System::Windows::Forms::ToolStripMenuItem^ min10;
	private: System::Windows::Forms::Panel^ savePanel;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ saveButton;
	private: System::Windows::Forms::TextBox^ nameTextBox;
	private: System::Windows::Forms::RichTextBox^ textArea;




		   SudokuBoard^ gameBoard;

	
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newGameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->easyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mediumToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->timeLimit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->min1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->min3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->min5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->min10 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->innerMainPanel = (gcnew System::Windows::Forms::Panel());
			this->savePanel = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->nameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->settingsPanel = (gcnew System::Windows::Forms::Panel());
			this->numberOfTips = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timeLabel = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textArea = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1->SuspendLayout();
			this->innerMainPanel->SuspendLayout();
			this->savePanel->SuspendLayout();
			this->settingsPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->optionsToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(548, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->newGameToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// newGameToolStripMenuItem
			// 
			this->newGameToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->easyToolStripMenuItem,
					this->mediumToolStripMenuItem, this->hardToolStripMenuItem
			});
			this->newGameToolStripMenuItem->Name = L"newGameToolStripMenuItem";
			this->newGameToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->newGameToolStripMenuItem->Text = L"New game";
			// 
			// easyToolStripMenuItem
			// 
			this->easyToolStripMenuItem->Name = L"easyToolStripMenuItem";
			this->easyToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->easyToolStripMenuItem->Text = L"Easy";
			this->easyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::easyToolStripMenuItem_Click);
			// 
			// mediumToolStripMenuItem
			// 
			this->mediumToolStripMenuItem->Name = L"mediumToolStripMenuItem";
			this->mediumToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->mediumToolStripMenuItem->Text = L"Medium";
			this->mediumToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::mediumToolStripMenuItem_Click);
			// 
			// hardToolStripMenuItem
			// 
			this->hardToolStripMenuItem->Name = L"hardToolStripMenuItem";
			this->hardToolStripMenuItem->Size = System::Drawing::Size(119, 22);
			this->hardToolStripMenuItem->Text = L"Hard";
			this->hardToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::hardToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->exitToolStripMenuItem->Text = L"Result Table";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->timeLimit });
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->optionsToolStripMenuItem->Text = L"Options";
			// 
			// timeLimit
			// 
			this->timeLimit->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->min1, this->min3,
					this->min5, this->min10
			});
			this->timeLimit->Name = L"timeLimit";
			this->timeLimit->Size = System::Drawing::Size(125, 22);
			this->timeLimit->Text = L"time limit";
			// 
			// min1
			// 
			this->min1->Name = L"min1";
			this->min1->Size = System::Drawing::Size(110, 22);
			this->min1->Text = L"1 min";
			this->min1->Click += gcnew System::EventHandler(this, &MainForm::min1_Click);
			// 
			// min3
			// 
			this->min3->Name = L"min3";
			this->min3->Size = System::Drawing::Size(110, 22);
			this->min3->Text = L"3 min";
			this->min3->Click += gcnew System::EventHandler(this, &MainForm::min3_Click);
			// 
			// min5
			// 
			this->min5->Name = L"min5";
			this->min5->Size = System::Drawing::Size(110, 22);
			this->min5->Text = L"5 min";
			this->min5->Click += gcnew System::EventHandler(this, &MainForm::min5_Click);
			// 
			// min10
			// 
			this->min10->Checked = true;
			this->min10->CheckState = System::Windows::Forms::CheckState::Checked;
			this->min10->Name = L"min10";
			this->min10->Size = System::Drawing::Size(110, 22);
			this->min10->Text = L"10 min";
			this->min10->Click += gcnew System::EventHandler(this, &MainForm::min10_Click);
			// 
			// innerMainPanel
			// 
			this->innerMainPanel->BackColor = System::Drawing::Color::WhiteSmoke;
			this->innerMainPanel->Controls->Add(this->textArea);
			this->innerMainPanel->Location = System::Drawing::Point(25, 57);
			this->innerMainPanel->Name = L"innerMainPanel";
			this->innerMainPanel->Size = System::Drawing::Size(352, 363);
			this->innerMainPanel->TabIndex = 2;
			// 
			// savePanel
			// 
			this->savePanel->Controls->Add(this->label2);
			this->savePanel->Controls->Add(this->saveButton);
			this->savePanel->Controls->Add(this->nameTextBox);
			this->savePanel->Location = System::Drawing::Point(25, 27);
			this->savePanel->Name = L"savePanel";
			this->savePanel->Size = System::Drawing::Size(346, 31);
			this->savePanel->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 6);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Name";
			// 
			// saveButton
			// 
			this->saveButton->Location = System::Drawing::Point(288, 1);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(52, 23);
			this->saveButton->TabIndex = 1;
			this->saveButton->Text = L"Save";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &MainForm::saveButton_Click);
			// 
			// nameTextBox
			// 
			this->nameTextBox->Location = System::Drawing::Point(44, 3);
			this->nameTextBox->Name = L"nameTextBox";
			this->nameTextBox->Size = System::Drawing::Size(238, 20);
			this->nameTextBox->TabIndex = 0;
			// 
			// settingsPanel
			// 
			this->settingsPanel->Controls->Add(this->numberOfTips);
			this->settingsPanel->Controls->Add(this->label1);
			this->settingsPanel->Controls->Add(this->button2);
			this->settingsPanel->Controls->Add(this->button1);
			this->settingsPanel->Controls->Add(this->timeLabel);
			this->settingsPanel->Location = System::Drawing::Point(390, 54);
			this->settingsPanel->Name = L"settingsPanel";
			this->settingsPanel->Size = System::Drawing::Size(150, 363);
			this->settingsPanel->TabIndex = 3;
			// 
			// numberOfTips
			// 
			this->numberOfTips->AutoSize = true;
			this->numberOfTips->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numberOfTips->Location = System::Drawing::Point(104, 283);
			this->numberOfTips->Name = L"numberOfTips";
			this->numberOfTips->Size = System::Drawing::Size(20, 24);
			this->numberOfTips->TabIndex = 4;
			this->numberOfTips->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(80, 260);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Tips to use:";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(0, 260);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(74, 47);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Tip";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->button1->Enabled = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button1->Location = System::Drawing::Point(0, 313);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 47);
			this->button1->TabIndex = 1;
			this->button1->Text = L"End game";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// timeLabel
			// 
			this->timeLabel->AutoSize = true;
			this->timeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timeLabel->Location = System::Drawing::Point(2, 0);
			this->timeLabel->Name = L"timeLabel";
			this->timeLabel->Size = System::Drawing::Size(145, 55);
			this->timeLabel->TabIndex = 0;
			this->timeLabel->Text = L"00:00";
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// textArea
			// 
			this->textArea->Location = System::Drawing::Point(6, 7);
			this->textArea->Name = L"textArea";
			this->textArea->Size = System::Drawing::Size(340, 350);
			this->textArea->TabIndex = 0;
			this->textArea->Text = L"";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::WhiteSmoke;
			this->ClientSize = System::Drawing::Size(548, 437);
			this->Controls->Add(this->savePanel);
			this->Controls->Add(this->settingsPanel);
			this->Controls->Add(this->innerMainPanel);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->innerMainPanel->ResumeLayout(false);
			this->savePanel->ResumeLayout(false);
			this->savePanel->PerformLayout();
			this->settingsPanel->ResumeLayout(false);
			this->settingsPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
			showList();
		}
		//	WARNING!!!
		//after editing MainForm in design view
		//all stuff in InitializeComponent() are overwritten
		//so this function must be always credited in InitializeComponent()
		void inicializeBoard() {
			innerMainPanel->Controls->Clear();
			board = createBoard();
			clearFields();
			//this->innerMainPanel->Controls->Remove(board);
			this->innerMainPanel->Controls->Add(board);

			SudokuBoard^ easyLevelTest = gcnew SudokuBoard();
			gameBoard = gcnew SudokuBoard();
		}
		void setEasyLevel() {
			
			
			array< int >^ ez_sol_1 = { 5, 8, 2, 4, 6, 1, 9, 3, 7, 9, 6, 3, 2, 7, 5, 4, 8, 1, 1, 4, 7, 9, 3, 8, 2, 5, 6, 8, 9, 4, 7, 1, 6, 2, 5, 3, 6, 1, 2, 3, 5, 8, 7, 4, 9, 3, 7, 5, 4, 9, 2, 8, 6, 1, 3, 7, 9, 1, 4, 5, 6, 2, 8, 1, 2, 6, 8, 3, 7, 5, 9, 4, 5, 8, 4, 6, 2, 9, 7, 1, 3 };
			array< int >^ ez_brd_1 = { 5, -1, -1, 4, -1, 1, -1, -1, -1, -1, -1, -1, 2, 7, -1, 4, -1, 1, -1, 4, 7, 9, -1, -1, -1, -1, 6, -1, -1, -1, 7, -1, -1, -1, -1, 3, 6, -1, -1, -1, 5, -1, -1, -1, 9, 3, -1, -1, -1, -1, 2, -1, -1, -1, 3, -1, -1, -1, -1, 5, 6, 2, -1, 1, -1, 6, -1, 3, 7, -1, -1, -1, -1, -1, -1, 6, -1, 9, -1, -1, 3 };

			array< int >^ ez_sol_2 = { 8, 3, 9, 2, 5, 4, 6, 7, 1, 7, 5, 1, 6, 3, 8, 4, 2, 9, 2, 4, 6, 1, 9, 7, 3, 5, 8, 5, 6, 8, 4, 2, 3, 9, 1, 7, 9, 1, 3, 8, 6, 7, 2, 4, 5, 4, 7, 2, 9, 1, 5, 8, 6, 3, 3, 8, 5, 7, 4, 6, 1, 9, 2, 1, 7, 4, 3, 9, 2, 5, 8, 6, 6, 2, 9, 5, 8, 1, 7, 3, 4 };
			array< int >^ ez_brd_2 = { -1, -1, -1, 2, -1, -1, -1, -1, 1, 7, 5, -1, -1, -1, -1, -1, -1, 9, -1, 4, -1, -1, -1, 7, 3, 5, 8, -1, -1, 8, 4, 2, -1, 9, -1, -1, -1, 1, -1, -1, -1, -1, -1, 4, -1, -1, -1, 2, -1, 1, 5, 8, -1, -1, 3, 8, 5, 7, -1, -1, -1, 9, -1, 1, -1, -1, -1, -1, -1, -1, 8, 6, 6, -1, -1, -1, -1, 1, -1, -1, -1 };

			array< int >^ ez_sol_3 = { 6, 2, 3, 5, 7, 4, 1, 9, 8, 4, 7, 5, 8, 9, 1, 3, 2, 6, 1, 8, 9, 2, 3, 6, 7, 4, 5, 8, 5, 2, 7, 3, 6, 9, 4, 1, 9, 4, 3, 1, 5, 2, 6, 8, 7, 6, 7, 1, 8, 9, 4, 5, 2, 3, 3, 6, 9, 2, 1, 7, 4, 8, 5, 7, 1, 8, 5, 3, 4, 2, 6, 9, 4, 5, 2, 9, 6, 8, 3, 1, 7 };
			array< int >^ ez_brd_3 = { 6, -1, 3, 5, -1, -1, 1, 9, -1, 4, -1, -1, 8, 9, -1, -1, 2, -1, 1, -1, -1, 2, 3, -1, -1, 4, -1, -1, -1, -1, -1, -1, 6, 9, 4, -1, 9, -1, 3, -1, 5, -1, 6, -1, 7, -1, 7, 1, 8, -1, -1, -1, -1, -1, -1, 6, -1, -1, 1, 7, -1, -1, 5, -1, 1, -1, -1, 3, 4, -1, -1, 9, -1, 5, 2, -1, -1, 8, 3, -1, 7 };

			array<array<int>^>^ sol = { ez_sol_1, ez_sol_2, ez_sol_3 };
			array<array<int>^>^ brd = { ez_brd_1, ez_brd_2, ez_brd_3 };
			int randomInt = rand() % 3;
			gameBoard->setSolution(sol[randomInt]);
			gameBoard->setBoard(brd[randomInt]);
			tips = 4;
			
		}
		void setMediumLevel() {

			array< int >^ md_sol_1 = { 3, 5, 7, 1, 6, 8, 2, 4, 9, 9, 2, 8, 3, 4, 5, 1, 6, 7, 1, 6, 4, 7, 2, 9, 8, 5, 3, 8, 7, 2, 4, 3, 1, 6, 9, 5, 5, 3, 1, 2, 9, 6, 7, 8, 4, 4, 9, 6, 5, 8, 7, 3, 1, 2, 5, 1, 6, 9, 2, 4, 7, 8, 3, 4, 7, 9, 8, 1, 3, 6, 5, 2, 2, 3, 8, 6, 7, 5, 9, 4, 1, };
			array< int >^ md_brd_1 = { -1, -1, 7, 1, 6, 8, -1, -1, -1, 9, -1, 8, -1, -1, -1, 1, -1, 7, 1, 6, -1, -1, -1, -1, -1, 5, 3, -1, 7, -1, -1, 3, -1, -1, -1, 5, -1, -1, 1, -1, -1, -1, -1, 8, 4, 4, -1, 6, -1, -1, 7, -1, -1, -1, 5, -1, 6, 9, -1, 4, -1, 8, 3, -1, -1, -1, 8, 1, -1, 6, 5, -1, 2, 3, -1, -1, 7, -1, -1, -1, 1, };

			array< int >^ md_sol_2 = { 5, 7, 3, 4, 2, 8, 1, 9, 6, 8, 9, 6, 3, 5, 1, 2, 7, 4, 4, 1, 2, 6, 7, 9, 5, 3, 8, 7, 5, 9, 8, 3, 2, 6, 4, 1, 1, 4, 8, 7, 6, 9, 5, 3, 2, 3, 2, 6, 1, 5, 4, 8, 9, 7, 3, 8, 5, 9, 1, 7, 2, 6, 4, 4, 2, 7, 6, 8, 5, 9, 1, 3, 9, 6, 1, 2, 4, 3, 7, 8, 5 };
			array< int >^ md_brd_2 = { -1, 7, -1, -1, 2, -1, -1, -1, 6, -1, -1, 6, 3, 5, 1, 2, 7, 4, 4, 1, -1, -1, 7, -1, -1, 3, -1, 7, -1, -1, 8, 3, 2, -1, -1, -1, -1, -1, -1, 7, -1, 9, 5, 3, 2, 3, -1, 6, -1, -1, -1, -1, -1, -1, 3, 8, -1, -1, 1, 7, -1, -1, -1, -1, -1, -1, 6, 8, 5, 9, -1, -1, 9, -1, -1, 2, -1, -1, 7, -1, 5 };

			array< int >^ md_sol_3 = { 4, 8, 5, 9, 1, 3, 6, 2, 7, 2, 9, 7, 5, 6, 8, 1, 4, 3, 6, 3, 1, 2, 4, 7, 9, 8, 5, 8, 6, 2, 5, 9, 4, 3, 7, 1, 3, 7, 4, 8, 1, 6, 9, 5, 2, 5, 1, 9, 7, 2, 3, 4, 6, 8, 7, 5, 8, 2, 3, 9, 1, 4, 6, 6, 2, 1, 4, 8, 5, 7, 3, 9, 3, 9, 4, 1, 7, 6, 8, 5, 2 };
			array< int >^ md_brd_3 = { 4, -1, 5, 9, -1, -1, 6, -1, 7, 2, -1, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2, 4, 7, 9, 8, -1, -1, -1, 2, -1, -1, -1, -1, -1, 1, -1, -1, 4, 8, -1, 6, -1, -1, -1, -1, -1, 9, -1, -1, 3, -1, 6, 8, 7, 5, 8, -1, 3, 9, -1, -1, -1, -1, 2, 1, -1, 8, 5, 7, 3, 9, -1, 9, -1, -1, 7, 6, -1, 5, -1 };

			array<array<int>^>^ sol = { md_sol_1, md_sol_2, md_sol_3 };
			array<array<int>^>^ brd = { md_brd_1, md_brd_2, md_brd_3 };
			int randomInt = rand() % 3;
			gameBoard->setSolution(sol[randomInt]);
			gameBoard->setBoard(brd[randomInt]);
			tips = 4;

		}
		void setHardLevel() {


			array< int >^ hd_sol_1 = { 2, 9, 3, 8, 1, 5, 6, 7, 4, 8, 6, 1, 2, 7, 4, 3, 9, 5, 7, 4, 5, 6, 9, 3, 8, 1, 2, 1, 3, 2, 7, 4, 8, 9, 5, 6, 5, 4, 6, 9, 3, 2, 1, 8, 7, 9, 8, 7, 5, 6, 1, 2, 3, 4, 5, 2, 9, 3, 8, 7, 4, 6, 1, 6, 1, 3, 4, 5, 9, 7, 2, 8, 4, 7, 8, 1, 2, 6, 3, 5, 9 };
			array< int >^ hd_brd_1 = { 2, 9, -1, -1, -1, -1, 6, -1, -1, -1, 6, -1, -1, 7, -1, -1, 9, 5, -1, -1, 5, 6, -1, 3, -1, -1, 2, 1, -1, -1, 7, 4, 8, -1, 5, -1, 5, -1, 6, -1, -1, -1, 1, -1, -1, 9, 8, 7, -1, -1, -1, -1, -1, -1, -1, -1, 9, -1, -1, 7, -1, -1, 1, -1, -1, 3, -1, -1, 9, -1, -1, 8, -1, 7, -1, 1, 2, 6, -1, 5, -1 };

			array< int >^ hd_sol_2 = { 9, 7, 8, 5, 2, 4, 1, 6, 3, 4, 2, 3, 8, 6, 1, 7, 5, 9, 1, 5, 6, 9, 3, 7, 4, 8, 2, 2, 3, 6, 4, 9, 1, 7, 8, 5, 1, 8, 7, 5, 3, 2, 6, 9, 4, 5, 4, 9, 6, 7, 8, 2, 1, 3, 3, 1, 2, 8, 4, 7, 6, 5, 9, 9, 7, 5, 2, 1, 6, 3, 4, 8, 8, 6, 4, 3, 9, 5, 7, 2, 1 };
			array< int >^ hd_brd_2 = { 9, -1, 8, 5, -1, 4, -1, 6, -1, -1, -1, 3, -1, -1, 1, 7, -1, 9, -1, 5, -1, -1, 3, 7, -1, 8, -1, 2, 3, -1, -1, -1, -1, -1, -1, -1, -1, 8, -1, 5, -1, -1, 6, -1, -1, 5, -1, -1, 6, 7, 8, 2, -1, -1, 3, 1, 2, 8, 4, -1, -1, 5, -1, -1, 7, -1, -1, 1, -1, -1, 4, -1, -1, -1, -1, -1, -1, 5, -1, 2, 1 };

			array< int >^ hd_sol_3 = { 1, 3, 6, 2, 7, 5, 8, 4, 9, 4, 2, 7, 8, 3, 9, 1, 6, 5, 5, 8, 9, 1, 6, 4, 3, 2, 7, 3, 2, 1, 9, 5, 8, 4, 6, 7, 6, 4, 8, 7, 1, 3, 9, 5, 2, 7, 9, 5, 6, 4, 2, 8, 1, 3, 5, 8, 3, 7, 9, 4, 6, 1, 2, 2, 9, 6, 3, 8, 1, 5, 7, 4, 4, 7, 1, 2, 5, 6, 9, 3, 8 };
			array< int >^ hd_brd_3 = { -1, -1, 6, -1, -1, -1, 8, -1, 9, -1, 2, 7, -1, -1, -1, -1, 6, -1, -1, -1, -1, 1, -1, 4, -1, -1, -1, -1, 2, 1, -1, 5, -1, -1, 6, -1, -1, -1, -1, -1, -1, 3, 9, 5, 2, -1, 9, 5, 6, -1, -1, -1, -1, -1, -1, -1, -1, 7, 9, -1, 6, -1, -1, 2, -1, -1, 3, -1, 1, 5, -1, -1, 4, -1, 1, -1, 5, -1, 9, -1, 8 };

			array<array<int>^>^ sol = { hd_sol_1, hd_sol_2, hd_sol_3 };
			array<array<int>^>^ brd = { hd_brd_1, hd_brd_2, hd_brd_3 };
			int randomInt = rand() % 3;
			gameBoard->setSolution(sol[randomInt]);
			gameBoard->setBoard(brd[randomInt]);
			tips = 3;
			


		}
		void setData(int level) {
			

			switch (level)
			{
			case 0:
				setEasyLevel();
				break;
			case 1:
				setMediumLevel();
				break;
			case 2:
				setHardLevel();
				break;
			default:
				array< int >^ solution = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
				array< int >^ baord = { 1,1,1,1,-1,1,1,1,1,1,1,1,1,1,1,1,-1,1,1,1,1,1,1,1,1,1,-1,1,1,1,1,1,1,1,1,-1,1,1,1,1,1,1,1,1,1,1,1,-1,1,1,1,1,-1,1,1,1,1,-1,1,1,1,1,1,1,-1,1,-1,1,1,1,1,-1,1,-1,1,1,1,-1,1,1,1 };
				
				gameBoard->setSolution(solution);
				gameBoard->setBoard(baord);
				break;
			}

			setNumberInFields(gameBoard->getBoard());
			numberOfTips->Text = Convert::ToString(tips);

		}
		void setConsole() {
			//KONSOLA to jest potrzebne tylko do testów by wyświetlić konsole
			int rc = Win32::AllocConsole();
			freopen("CONOUT$", "w", stdout);
			std::cout << "Console for tests:" << std::endl;
		}
		TableLayoutPanel^ createBoard() {
			//clear all fields
			fields.clear();
			//clearFields();
			int const SIZE = 3;

			TableLayoutPanel^ baord = gcnew System::Windows::Forms::TableLayoutPanel();

			for (int i = 0; i < SIZE; i++) {
				TableLayoutPanel^ table = gcnew System::Windows::Forms::TableLayoutPanel();

				table->ColumnCount = SIZE;
				table->RowCount = SIZE;

				for (int j = 0; j < SIZE; j++) {
					table->Controls->Add(createSmallBoard(), j, i);
					table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
					table->RowStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));

				}
				table->AutoSize = true;
				baord->Controls->Add(table);
			}
			baord->AutoSize = true;
			baord->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::InsetDouble; 
			
			return baord;

		}

		public: System::Void validate(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs e) {
			TextBox^ field = (TextBox^)sender;
			field->Text = "test";
			//String^ text = field->Text;
			//int len = text->Length;
			//if (len > 1) field->Text = "";
		}
		private: System::Void validate_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
			TextBox^ field = (TextBox^) sender;
			if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
				e->Handled = true;
			}
		}
		TableLayoutPanel^ createSmallBoard() {

			TableLayoutPanel^ smallBoard = gcnew System::Windows::Forms::TableLayoutPanel();
			int const SIZE = 3;
			smallBoard->ColumnCount = SIZE;
			smallBoard->RowCount = SIZE;
			
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					TextBox^ field = gcnew System::Windows::Forms::TextBox();
					field->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
						static_cast<System::Byte>(0));
					field->Width = 30;
					//field->Height = 30;
					field->BackColor = System::Drawing::Color::White;
					field->ForeColor = System::Drawing::Color::Black;
					field->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
					field->MaxLength = 1;
					smallBoard->Controls->Add(field, j, i);
					//add field to vector
					fields.push_back(field);
					smallBoard->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
					smallBoard->RowStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
					//field->Click += gcnew System::EventHandler(this, &MainForm::validate);
					//field->ModifiedChanged += gcnew System::EventHandler(this, &MainForm::validate);
					field->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::validate_KeyPress);


				}
			}
			smallBoard->AutoSize = true;

			return smallBoard;

		}
		void setNumberInFields(array< int >^ board) {
			for (int i = 0; i < 81; i++) {

				TextBox^ field = fields[i];
				int value = board[i];
				if (value < 0) {
					field->Enabled = true;
					field->BackColor = System::Drawing::Color::White;
				}
				else{
					field->Text = value + "";
					field->Enabled = false;
					
				}
				
			}
		}
		void clearFields() {
			for (int i = 0; i < 81; i++) {
				TextBox^ field = fields[i];
				field->Text = "";
				field->Enabled = true;
			}
		}
		void disableFields(cliext::vector<int> indexs) {
			for (int i = 0; i < indexs.size(); i++) {
				int id = indexs[i];
				TextBox^ field = fields[id];
				field->Enabled = false;
				field->Text = "R";
			}
		}
		//Easy level	-	38 fields is filled
		//Medium level	-	30 fields is filled
		//void randomFields(int number) {
		//	//this line ensure uniqueness of random numbers
		//	//every time when the program starts
		//	srand(time(NULL));

		//	cliext::vector<int> indexs;
		//	cliext::vector<int>::iterator it;
		//	for (int i = 0; i < number; i++) {
		//		int randomInt;
		//		while (true) {
		//			randomInt = rand() % 81;
		//			it = std::find(indexs.begin(), indexs.end(), randomInt);
		//			//false if random number is inside indexs
		//			if (it == indexs.end()) break;
		//		}
		//		indexs.push_back(randomInt);
		//	}
		//	disableFields(indexs);
		//	
		//}


	private: void newGame() {
		savePanel->Visible = false;
		innerMainPanel->BackColor = System::Drawing::Color::SkyBlue;
		settingsPanel->Visible = true;
		min = 0;
		sec = 0;
		button1->Enabled = true;
		button2->Enabled = true;
		
		inicializeBoard();
		//clearFields();
		timer1->Enabled = true;
		timeLimit->Enabled = false;
		

	}
	private: array< int >^ fieldsToArray() {
		//int rc = Win32::AllocConsole();
		//freopen("CONOUT$", "w", stdout);
		//std::cout << "Console for tests:" << std::endl;
		array< int >^ table = gcnew array< int >(81);
		for (int i = 0; i < 81; i++) {
			TextBox^ field = fields[i];
			String^ text = field->Text;
			std::string unmanaged = msclr::interop::marshal_as<std::string>(text);
			std::string test = "5";
			
			if (unmanaged == "") unmanaged = "99";
			table[i] = std::stoi(unmanaged);
		}
		return table;
	}

		   void judge() {
			   //int rc = Win32::AllocConsole();
	//freopen("CONOUT$", "w", stdout);
	//std::cout << "Console for tests:" << std::endl;
			   array< int >^ solution = this->gameBoard->getSolution();
			   array< int >^ actualBoard = fieldsToArray();
			   std::cout << solution->Length << std::endl;

			   bool equal = true;
			   for (int i = 0; i < 81; i++) {
				   //std::cout <<actualBoard[i]<< "=" <<solution[i]<< std::endl;
				   if (actualBoard[i] == solution[i]) equal = true;
				   else {
					   equal = false;
					   break;
				   }
			   }
			   

			   std::string message = "It's not correct answer";
			   if (min == max_time) {

				   timer1->Enabled = false;
				   timeLimit->Enabled = true;
				   message = "time is over";
				   
			   }
			   //int intPart = 10;
			   if (equal) {
				   message = "YOU WON!";
				   timer1->Enabled = false;
				   timeLimit->Enabled = true;
				   savePanel->Visible = true;

			   }
			   //std::cout << message << std::endl;
			   String^ msg = String::Concat(msclr::interop::marshal_as<System::String^>(message));
			   MessageBox::Show(msg);

		   }
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	judge();
	
	
}
	   int sec = 0;
	   int min = 0;
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

	if (min == max_time) {
		judge();

		return;
	}

	String^ seconds = "";
	String^ minuts = "";
	sec++;
	if (sec == 60) {
		sec = 0;
		min++;
	}
	if (min <= 9) minuts = "0";
	minuts += Convert::ToString(min);

	if (sec <= 9) seconds = "0";
	seconds += Convert::ToString(sec);
	

	timeLabel->Text = minuts +":"+ seconds;
}

	   int tips = 10;
	   int max_time = 10;
	   //tip button

	  
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	
	TextBox^ field;
	
	for (int i = 0; i < 81; i++) {
		field = fields[i];
		if (field->Enabled == true & field->Text =="") {
			int tip = gameBoard->getSolution()[i];
			field->Text = Convert::ToString(tip);
			field->BackColor = System::Drawing::Color::LightGreen;
			field->Enabled = false;
			break;
		}
	}
	

	tips--;
	numberOfTips->Text = Convert::ToString(tips);
	if (tips == 0) button2->Enabled = false;
}
	   void showList() {
		   savePanel->Visible = false;
		   timer1->Enabled = false;
		   timeLimit->Enabled = true;
		   settingsPanel->Visible = false;
		   innerMainPanel->Controls->Clear();
		   innerMainPanel->BackColor = System::Drawing::Color::WhiteSmoke;

		   loadResults();

		   innerMainPanel->Controls->Add(textArea);
		   textArea->Clear();
		   for each (Result ^ elem in rows)
		   {
			   textArea->Text += elem->name;
			   textArea->Text += "\t\t\t\t";
			   textArea->Text += elem->min;
			   textArea->Text += ":";
			   textArea->Text += elem->sec;
			   textArea->Text += "\n";
		   }
	   }
private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	showList();
}

private: System::Void easyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	newGame();
	setData(44);
}
private: System::Void mediumToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	newGame();
	setData(1);
}
private: System::Void hardToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	newGame();
	setData(2);
}
private: System::Void min1_Click(System::Object^ sender, System::EventArgs^ e) {
	min1->Checked = true;
	min3->Checked = false;
	min5->Checked = false;
	min10->Checked = false;
	max_time = 1;
}
private: System::Void min3_Click(System::Object^ sender, System::EventArgs^ e) {
	min1->Checked = false;
	min3->Checked = true;
	min5->Checked = false;
	min10->Checked = false;
	max_time = 3;
}
private: System::Void min5_Click(System::Object^ sender, System::EventArgs^ e) {
	min1->Checked = false;
	min3->Checked = false;
	min5->Checked = true;
	min10->Checked = false;
	max_time = 5;
}
private: System::Void min10_Click(System::Object^ sender, System::EventArgs^ e) {
	min1->Checked = false;
	min3->Checked = false;
	min5->Checked = false;
	min10->Checked = true;
	max_time = 10;
}

	cliext::vector<Result^> rows;

private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e) {
	loadResults();

	String^ name = nameTextBox->Text;

	Result^ newResult = gcnew Result(name, Convert::ToString(min), Convert::ToString(sec));

	rows.push_back(newResult);


	//std::ofstream file("test", std::ios_base::app);
	std::ofstream file("rows.txt");
	for each (Result^ var in rows)
	{
		String^ name = var -> name;
		String^ min = var->min;
		String^ sec = var->sec;
		std::string stringName = msclr::interop::marshal_as<std::string>(name);
		std::string stringMin = msclr::interop::marshal_as<std::string>(min);
		std::string stringSec = msclr::interop::marshal_as<std::string>(sec);
		file << stringName <<"-"<< stringMin << ":" << stringSec << std::endl;
	}


	file.close();
	savePanel->Visible = false;

}
	   void loadResults() {

		   //int rc = Win32::AllocConsole();
		   //freopen("CONOUT$", "w", stdout);
		   //std::cout << "Console for tests:" << std::endl;
		   rows.clear();
		   std::ifstream file("rows.txt");
		   if (file.is_open())
		   {
			   std::string row;//maksymalnie 9999 znaków w wierszu
			   while (getline(file,row) )//dopóki jest co czytać
			   {
				   
				   int id = row.find('-');
				   std::string name = row.substr(0, id);
				   std::string min = row.substr(id+1, 2);
				   std::string sec = row.substr(id + 4, 2);
				   //String^ min = text->Substring(id, 2);
				   //String^ sec = text->Substring(id + 3, id + 5);
				   String^ nameS = "";
				   

				   Result^ newResult = gcnew Result(String::Concat(msclr::interop::marshal_as<System::String^>(name)) , String::Concat(msclr::interop::marshal_as<System::String^>(min)) , String::Concat(msclr::interop::marshal_as<System::String^>(sec)));
				   rows.push_back(newResult);

				   //std::cout << name <<"\n"<<min<<"\n"<<sec<< std::endl; //wypisz to co wczytałes z pliku
				   //lub wykonaj inną operację
			   }
		   }

		   file.close();
	   }
};
}