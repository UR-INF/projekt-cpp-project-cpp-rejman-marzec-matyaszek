#pragma once
#include <cliext/vector>
#include <vector>
#include <time.h>
#include "SudokuBoard.cpp"
#include <string>

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

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		cliext::vector<TextBox^> fields;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 379);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);

			inicializeBoard();
			
			sampleData();
			
			
		}
		//	WARNING!!!
		//after editing MainForm in design view
		//all stuff in InitializeComponent() are overwritten
		//so this function must be always credited in InitializeComponent()
		void inicializeBoard() {

			this->Controls->Add(createBoard());
		}
		void sampleData() {
			array< int >^ solution = { 1,0,7,0,3,6,2,7,3,4,2,3,4,5,2,3,0,1,2,3,4,5,6,5,6,7,6,7,8,7,6,5,4,5,6,5,6,6,7,0,1,2,3,2,3,4,3,4,5,4,6,5,7,6,7,6,5,4,5,6,5,6,5,5,4,3,4,5,6,5,4,5,4,3,4,3,4,5,4,5,4 };
			array< int >^ baord = { -1,0,7,0,3,6,2,7,3,4,-2,3,4,5,2,3,-0,1,2,3,4,5,6,5,-6,7,6,-7,8,7,6,5,-4,-5,-6,5,6,6,-7,0,1,2,3,2,3,4,3,4,5,4,6,5,7,6,7,6,5,4,5,6,5,6,5,5,4,3,4,5,6,5,4,5,4,3,4,3,4,5,4,5,4 };
			//przykładowa tablica sudoku
			SudokuBoard^ easyLevelTest = gcnew SudokuBoard();

			easyLevelTest->setSolution(solution);
			easyLevelTest->setBoard(baord);

			//setNumberInFields();
			setNumberInFields(easyLevelTest->getBoard());
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

		

	


	};
}
