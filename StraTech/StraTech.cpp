// StraTech.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <list>
#include "Maze.cpp"
#include "Algorithm.cpp"


using namespace std;

int **mat;

void compute(Maze maze, int sr, int sc, int dr, int dc) {
	maze.startX = sr;
	maze.startY = sc;
	maze.endX = dr;
	maze.endY = dc;

	GreedySearch(maze);

	//print for verifying
	for (int i = 0; i < maze.width; i++) {
		for (int j = 0; j < maze.height; j++) {
			//printf("%d ", maze.getArrayValue(i, j));
		}
		//printf("\n");
	}
}

void readInput() {

	ifstream input;
	input.open("input.txt");

	//read row no, col no
	int n = 0, m = 0;
	input >> n;
	input >> m;

	int i, j;
	/*matrix*/
	mat = (int **)malloc((n + 1) * sizeof(int *));
	for (i = 0; i <= n; i++)
		mat[i] = (int *)malloc((m + 1) * sizeof(int *));

	//maze
	Maze maze(n + 1, m + 1);

	//cout << n << " " << m << endl;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			input >> mat[i][j];
			maze.setArrayValue(i, j, mat[i][j]);
			//printf("%d ", maze.getArrayValue(i, j));
		}
		//printf("\n");
	}

	//read router 
	int routesNo = 0;
	input >> routesNo;
	//cout << routesNo << endl;

	int rNo, sr, sc, dr, dc;
	for (int k = 0; k < routesNo; k++) {
		maze.unvisitAll();
		input >> rNo >> sr >> sc >> dr >> dc;
		//cout << sr << " " << sc << " " << dr << " " << dc << endl;
		cout << rNo << endl;
		compute(maze, sr, sc, dr, dc);
		cout << endl;
	}
	free(mat);
}

int main() 
{
	//read input matrix
	readInput();


	int x = 0;
	cin >> x;
	//getch();
	return 0;
}

