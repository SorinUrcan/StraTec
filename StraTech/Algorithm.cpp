#include "stdafx.h"
#include "Maze.cpp"
#include <iostream>
#include <queue>
#include "ArrayListZ.cpp"
#include <stdlib.h>     /* abs */
#include <stdio.h>      /* printf */

using namespace std;

static void printSol(Maze m, Pair * solutions, Pair p, int solIndex) {
	if (p.parentF == m.startX && p.parentS == m.startY) {
		//m.setArrayValue(m.startX, m.startY, 7);
		//printf("Start: ( %d, %d  ) moved to ( %d , %d) Path Cost : %d Depth: %d", p.parentF, p.parentS, p.first, p.second, m.getArrayValue(p.first, p.second), p.ht);
		//cout << endl;
		printf("%c ", p.ch);
		return;
	}
	//haven't finished printing out the solution
	else {
		//printf("Next: ( %d, %d  ) moved to ( %d , %d) Path Cost : %d Depth: %d", p.parentF, p.parentS, p.first, p.second, m.getArrayValue(p.first, p.second), p.ht);
		//cout << endl;
	}

	

	for (int i = 0; i < solIndex; i++) {
		if (solutions[i].first == p.parentF && solutions[i].second == p.parentS) {
			printSol(m, solutions, solutions[i], solIndex);
			printf("%c ", p.ch);
			//printf("Start: ( %d, %d )  \n) ", p.parentF, p.parentS);
			//m.setArrayValue(p.parentF, p.parentS, 7);
			return;
		}
	}
}

static int findMinFrontier(Maze maze, ArrayListZ frontier) {

	Pair minPair = frontier.get(0);
	float distance = sqrt(pow(frontier.get(0).first - maze.endX, 2) + pow(frontier.get(0).second - maze.endY, 2));;
	int index = 0;

	for (int i = 0; i < frontier.getSize(); i++) {
		//printf("F: %d %d ", frontier.get(i).first, frontier.get(i).second);
		Pair temp = frontier.get(i);
		//distance = (float) (abs(temp.first - maze.endX) + abs(temp.second - maze.endY));
		//distance = sqrt(pow(temp.first - maze.endX, 2) + pow(temp.second - maze.endY, 2));


			//float minDist = (float) (abs(minPair.first - maze.endX) + abs(minPair.second - maze.endY));
		float minDist = sqrt(pow(minPair.first - maze.endX, 2) + pow(minPair.second - maze.endY, 2));
			if (minDist > distance) {
				minPair = temp;
				index = i;
				//printf("Poz [%d %d] Dist: %lf, %lf \n", minPair.first, minPair.second, minDist, distance);
			
		}
	}

	//cout << endl;
	return index;
}

static bool canMove(Maze m, Pair p, char s) {

	if (s == 'R') {
		if ((p.first + 1 < m.width) && (0 <= m.getArrayValue(p.first + 1, p.second)) && (m.getArrayValue(p.first + 1, p.second) <= 2)) {
			//no wall to the right of the current position and it is inbounds of the walls
			return true;
		}
		else return false;
	}

	if (s == 'L') {
		if ((p.first > 0) && (0 <= m.getArrayValue(p.first - 1, p.second)) && (m.getArrayValue(p.first - 1, p.second) <= 2)) {
			//no wall to the left of the current position and it is inbounds of the walls
			return true;
		}
		else return false; }

	if (s == 'U') {
		if ((p.second > 0) && (0 <= m.getArrayValue(p.first, p.second - 1)) && (m.getArrayValue(p.first, p.second - 1) <= 2)) {
			//no wall above the current position and it is inbounds of the walls
			return true;
		} else return false;
	}

	if (s == 'D') {
		if ((p.second + 1 < m.height) && (0 <= m.getArrayValue(p.first, p.second + 1)) && (m.getArrayValue(p.first, p.second + 1) <= 2)) {
			//no walldown of the current position and it is inbounds of the walls
			return true;
		} else
			return false;
	}
	return false;
}

	static void GreedySearch(Maze maze) {

		queue <Pair> Gque;
		Pair * solutions = (Pair *)malloc(maze.getLength() * 2 * sizeof(Pair));

		int solIndex = 0;
		int NumberofNodesExpanded = 0;
		int depth = 0;
		int maxfrontier = 0;

		//push the start position on to the stack
		Pair start (maze.startX, maze.startY, maze.startX, maze.startY, depth, 1, 'S');
		Gque.push(start);
		//maze.setVisited(maze.startX, maze.startY, true);

		ArrayListZ frontier;

		while (!Gque.empty()) {
			Pair curr = Gque.front();
			Gque.pop();

			solutions[solIndex] = curr;
			solIndex = solIndex + 1;

			if (curr.first == maze.endX && curr.second == maze.endY) {
				//printf("Found the End!!!");
				//printf("Number of Nodes Expanded: %d", (NumberofNodesExpanded - 3));
				//printf("Max tree depth searched: %d", depth);
				//printf("Max frontier size: %d" , maxfrontier);
				//cout << endl;
				printSol(maze, solutions, curr, solIndex);
				return;
			}

			if (Gque.empty() && !frontier.empty()) {
				int index = findMinFrontier(maze, frontier);
				Pair min2 = frontier.remove(index);
				Gque.push(min2);

				if (frontier.size > maxfrontier)
					maxfrontier = frontier.size;

				if (depth < min2.ht + 1)
					depth = min2.ht + 1;
			}

			//add neighbors
			if (!maze.visited(curr.first, curr.second))
			{
				//update visited
				maze.setVisited(curr.first, curr.second, true);

				//add node
				NumberofNodesExpanded = NumberofNodesExpanded + 1;



				//add left neighbor
				if (canMove(maze, curr, 'L') && !maze.visited(curr.first - 1, curr.second))
				{
					Pair temp (curr.first - 1, curr.second, curr.first, curr.second, curr.ht + 1, 1, 'U');
					frontier.add(temp);
				}

				//add down neighbor
				if (canMove(maze, curr, 'D') && !maze.visited(curr.first, curr.second + 1))
				{
					Pair temp (curr.first, curr.second + 1, curr.first, curr.second, curr.ht + 1, 1, 'R');
					frontier.add(temp);
				}

				//add up neighbor
				if (canMove(maze, curr, 'U') && !maze.visited(curr.first, curr.second - 1))
				{
					Pair temp (curr.first, curr.second - 1, curr.first, curr.second, curr.ht + 1, 1, 'L');
					frontier.add(temp);
				}


				//add right neighbor
				if (canMove(maze, curr, 'R') && !maze.visited(curr.first + 1, curr.second))
				{
					Pair temp (curr.first + 1, curr.second, curr.first, curr.second, curr.ht + 1, 1, 'D');
					frontier.add(temp);
				}

				int index = findMinFrontier(maze, frontier);
				Pair min = frontier.remove(index);

				//printf("\nWent to: %d, %d   \n", min.first, min.second);

				Gque.push(min);


				if (frontier.size > maxfrontier)
					maxfrontier = frontier.size;

				if (depth < min.ht + 1)
					depth = min.ht + 1;
			}

		}

	}