#pragma once
#include <cliext/vector>
#include <vector>
#include <time.h>
#include "SudokuBoard.cpp"
#include <string>
#include <msclr/marshal_cppstd.h>


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
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->innerMainPanel = (gcnew System::Windows::Forms::Panel());
			this->settingsPanel = (gcnew System::Windows::Forms::Panel());
			this->numberOfTips = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timeLabel = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1->SuspendLayout();
			this->settingsPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(616, 24);
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
			this->newGameToolStripMenuItem->Name = L"newGameToolStripMenuItem";
			this->newGameToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->newGameToolStripMenuItem->Text = L"New game";
			this->newGameToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::newGameToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(137, 22);
			this->exitToolStripMenuItem->Text = L"Result Table";
			// 
			// innerMainPanel
			// 
			this->innerMainPanel->Location = System::Drawing::Point(22, 54);
			this->innerMainPanel->Name = L"innerMainPanel";
			this->innerMainPanel->Size = System::Drawing::Size(375, 347);
			this->innerMainPanel->TabIndex = 2;
			// 
			// settingsPanel
			// 
			this->settingsPanel->Controls->Add(this->numberOfTips);
			this->settingsPanel->Controls->Add(this->label1);
			this->settingsPanel->Controls->Add(this->button2);
			this->settingsPanel->Controls->Add(this->button1);
			this->settingsPanel->Controls->Add(this->timeLabel);
			this->settingsPanel->Location = System::Drawing::Point(428, 54);
			this->settingsPanel->Name = L"settingsPanel";
			this->settingsPanel->Size = System::Drawing::Size(150, 347);
			this->settingsPanel->TabIndex = 3;
			// 
			// numberOfTips
			// 
			this->numberOfTips->AutoSize = true;
			this->numberOfTips->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numberOfTips->Location = System::Drawing::Point(101, 265);
			this->numberOfTips->Name = L"numberOfTips";
			this->numberOfTips->Size = System::Drawing::Size(20, 24);
			this->numberOfTips->TabIndex = 4;
			this->numberOfTips->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(80, 247);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Tips to use:";
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(0, 247);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(74, 47);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Tip";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(0, 300);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 47);
			this->button1->TabIndex = 1;
			this->button1->Text = L"End game";
			this->button1->UseVisualStyleBackColor = true;
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
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(616, 447);
			this->Controls->Add(this->settingsPanel);
			this->Controls->Add(this->innerMainPanel);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->settingsPanel->ResumeLayout(false);
			this->settingsPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

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
		void sampleData() {
			array< int >^ solution = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
			array< int >^ baord = { 1,1,1,1,-1,1,1,1,1,1,1,1,1,1,1,1,-1,1,1,1,1,1,1,1,1,1,-1,1,1,1,1,1,1,1,1,-1,1,1,1,1,1,1,1,1,1,1,1,-1,1,1,1,1,-1,1,1,1,1,-1,1,1,1,1,1,1,-1,1,-1,1,1,1,1,-1,1,-1,1,1,1,-1,1,1,1 };
			//przykładowa tablica sudoku


			gameBoard->setSolution(solution);
			gameBoard->setBoard(baord);

			//setNumberInFields();
			setNumberInFields(gameBoard->getBoard());
			//randomFields(30);
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
		TableLayoutPanel^ createSmallBoard() {

			TableLayoutPanel^ smallBoard = gcnew System::Windows::Forms::TableLayoutPanel();
			int const SIZE = 3;
			smallBoard->ColumnCount = SIZE;
			smallBoard->RowCount = SIZE;
			
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					TextBox^ field = gcnew System::Windows::Forms::TextBox();
					field->Width = 20;
					field->Height = 30;
					smallBoard->Controls->Add(field, j, i);
					//add field to vector
					fields.push_back(field);
					smallBoard->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
					smallBoard->RowStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));

				}
			}
			smallBoard->AutoSize = true;

			return smallBoard;

		}
		void setNumberInFields(array< int >^ board) {
			for (int i = 0; i < 81; i++) {

				TextBox^ field = fields[i];
				int value = board[i];
				if (value < 0) field->Enabled = true;
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


	private: System::Void newGameToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		min = 0;
		sec = 0;
		tips = 10;
		numberOfTips->Text = Convert::ToString(tips);
		button1->Enabled = true;
		button2->Enabled = true;
		
		inicializeBoard();
		//clearFields();
		sampleData();
		timer1->Enabled = true;
		

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

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	
	
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
	//int intPart = 10;
	if (equal) {
		message = "YOU WON!";
		timer1->Enabled = false;

	}
	//std::cout << message << std::endl;
	String^ msg = String::Concat(msclr::interop::marshal_as<System::String^>(message));
	MessageBox::Show(msg);
}
	   int sec = 0;
	   int min = 0;
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

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
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	
	TextBox^ field;
	
	for (int i = 0; i < 81; i++) {
		field = fields[i];
		if (field->Enabled == true & field->Text =="") {
			int tip = gameBoard->getSolution()[i];
			field->Text = Convert::ToString(tip);
			break;
		}
	}
	

	tips--;
	numberOfTips->Text = Convert::ToString(tips);
	if (tips == 0) button2->Enabled = false;
}
};
}
