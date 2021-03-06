// This program solves Project Euler problem 15: Lattice Paths
// This program and its comments use the notation that the path starts at (0,0), and point (20,20) is located at the top right

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int boxSize = 20; 
	vector<vector<long long int>> pathsAtPoints(boxSize+1, vector<long long int> (boxSize+1));

	//initialize the top and right edges as 1 so we don't have to make special conditions to deal with these points.
	for (int i = 0; i < boxSize; i++)
	{
		pathsAtPoints[i][boxSize] = 1;
		pathsAtPoints[boxSize][i] = 1;
	}

	//this loop works because the edges have already been filled in with 1. It then iterates through each column, calculating the number of points at each point in the column
	for (int i = boxSize - 1; i >= 0; i--)
	{
		for (int j = boxSize - 1; j >= 0; j--)
		{
			pathsAtPoints[i][j] = pathsAtPoints[i + 1][j] + pathsAtPoints[i][j + 1];
		}
	}
	cout << pathsAtPoints[0][0];
}

