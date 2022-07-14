#include<bits/stdc++.h>
using namespace std;

class Cell {
private:
	int row, col;
	bool isBomb;
	int number;
	bool isExposed = false;
	bool isGuess = false;

public:
	Cell(){ }
	/* Getters and Setters */

	bool flip() {
		isExposed = true; 
		return lisBomb;
	}
	bool toggleGuess(){
		if(!isExposed){
			isGuess = lisGuess;
		}
		return isGuess;
	}
};

// PLACING BOMBS ON BOARD
// 1. Rejection Sample
// 2. Put K and Shuffle


int main(){
}