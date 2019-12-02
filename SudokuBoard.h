#pragma once
#include <iostream>

ref class SudokuBoard
{
private:

	array< int >^ solution; 
	array< int >^ board;

public:

	SudokuBoard()
	{

		solution = gcnew array<int>(81);
		board = gcnew array<int>(81);
	}

	array< int >^ getSolution() {
		return this->solution;
	}

	void setSolution(array< int >^ solution) {
		this->solution = solution;
	}

	array< int >^ getBoard() {
		return board;
	}

	void setBoard(array< int >^ board) {
		this->board = board;
	}

	SudokuBoard^ getSample() {
		SudokuBoard^ sample = gcnew SudokuBoard();
		
		array< int >^ solution = gcnew array<int>(81);
		for (int i = 0; i < solution->Length; i++) {
			
			solution[i] = i-3;
			

		}

		sample->setSolution(solution);

		return sample;

	}
	array< int >^ getSampleTable() {
		array< int >^ solution = gcnew array<int>(81);
		for (int i = 0; i < solution->Length; i++) {

			solution[i] = i-4;


		}
		return solution;
	}

};

