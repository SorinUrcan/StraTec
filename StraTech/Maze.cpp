#include "stdafx.h"
#include <new>
#pragma once

using namespace std;

class Maze {
	public:

		int width, height;
		int * mazeGrid;

		int startX, startY, endX, endY;
		bool * visit;

		Maze::Maze(int mazeWidth, int mazeHeight) {
			width = mazeWidth;
			height = mazeHeight;
			mazeGrid = new int[width * height * sizeof (int) ];
			visit = new bool[width * height * sizeof (bool) ];
		}

		int Maze::getArrayValue(int row, int col) {
			return mazeGrid[row * width + col];
			}

		void Maze::setArrayValue(int row, int col, int value) {
			mazeGrid[row * width + col] = (int) value;
			setVisited(row, col, false);
			}

		int Maze::getLength() {
			return width * height;
		}

		bool Maze::visited(int x, int y) {
			//printf("[%d, %d] ", x, y);
			return visit[x * width + y];
		}

		void Maze::setVisited(int x, int y, bool value) {
			visit[x * width + y] = value;
		}

		void Maze::free() {
			delete[] mazeGrid;
		}

		void unvisitAll() {
			for (int i = 0; i < width * height; i++)
				visit[i] = false;
		}
};