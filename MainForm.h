#pragma once

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
		}
		//	WARNING!!!
		//after editing MainForm in design view
		//all stuff in InitializeComponent() are overwritten
		//so this function must be always credited in InitializeComponent()
		void inicializeBoard() {

			this->Controls->Add(createBoard());
		}

		TableLayoutPanel^ createBoard() {

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
					smallBoard->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
					smallBoard->RowStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));

				}
			}
			smallBoard->AutoSize = true;

			return smallBoard;

		}


	};
}
