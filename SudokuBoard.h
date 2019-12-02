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
		return this->board;
	}

	void setBoard(array< int >^ board) {
		this->board = board;
	}

};

