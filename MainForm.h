#pragma once
#include <cliext/vector>
#include <vector>
#include <time.h>
#include "SudokuBoard.h"

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
			SudokuBoard^ board = gcnew SudokuBoard();
			int rc = Win32::AllocConsole();
			freopen("CONOUT$", "w", stdout);
			std::cout << "This works" << std::endl;
			SudokuBoard^ test = board->getSample();

			std::cout << "test";
			
			//setNumberInFields2(test->getSolution);
			//randomFields(30);
			
		}
		//	WARNING!!!
		//after editing MainForm in design view
		//all stuff in InitializeComponent() are overwritten
		//so this function must be always credited in InitializeComponent()
		void inicializeBoard() {

			this->Controls->Add(createBoard());
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
		void setNumberInFields2(array< int^ >^ board) {
			for (int i = 0; i < 81; i++) {
				TextBox^ field = fields[i];
				field->Text = ""+board[i];
				field->Enabled = true;
			}
		}
		void setNumberInFields() {
			for (int i = 0; i < 81; i++) {
				TextBox^ field = fields[i];
				field->Text = "" + i;
				field->Enabled = true;
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
		void randomFields(int number) {
			//this line ensure uniqueness of random numbers
			//every time when the program starts
			srand(time(NULL));

			cliext::vector<int> indexs;
			cliext::vector<int>::iterator it;
			for (int i = 0; i < number; i++) {
				int randomInt;
				while (true) {
					randomInt = rand() % 81;
					it = std::find(indexs.begin(), indexs.end(), randomInt);
					//false if random number is inside indexs
					if (it == indexs.end()) break;
				}
				indexs.push_back(randomInt);
			}
			disableFields(indexs);
			
		}

		

	


	};
}
