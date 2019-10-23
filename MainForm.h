#pragma once

#include <array>

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
		System::ComponentModel::Container ^components;
		


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
			this->ClientSize = System::Drawing::Size(479, 294);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			main();
		}
		void main() {
			//std::array<TextBox^, 81> data;

			createBoard();
		}
		void createBoard() {

			int const SIZE = 3;

			TableLayoutPanel^ mainTablePanel = gcnew System::Windows::Forms::TableLayoutPanel();
			
			for (int i = 0; i < SIZE; i++) {
				TableLayoutPanel^ table = gcnew System::Windows::Forms::TableLayoutPanel();
				
				table->ColumnCount = SIZE;
				table->RowCount = SIZE;
				
				
				for (int j = 0; j < SIZE; j++){
					table->Controls->Add(createSmallBoard(), j, i);
					table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
					table->RowStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));

				}
				table->AutoSize = true;
				mainTablePanel->Controls->Add(table);
			}
			mainTablePanel->AutoSize = true;
			mainTablePanel->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::InsetDouble;
			this->Controls->Add(mainTablePanel);
			
		}
		TableLayoutPanel^ createSmallBoard() {
			int const SIZE = 3;
			TableLayoutPanel^ table = gcnew System::Windows::Forms::TableLayoutPanel();
			
			table->ColumnCount = SIZE;
			table->RowCount = SIZE;
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++) {
					TextBox^ textBox = gcnew System::Windows::Forms::TextBox();
					textBox->Width = 20;
					textBox->Height = 30;
					table->Controls->Add(textBox, j, i);
					table->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
					table->RowStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));

				}
			}
			table->AutoSize = true;
			
			return table;

		}

	
	};
}
