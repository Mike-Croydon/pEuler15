// This program solves Project Euler problem 15: Lattice Paths
// This program and its comments use the notation that the path starts at (0,0), and point (20,20) is located at the bottom right

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

//This function calculates the number of paths at the point n-i,n-j. vector<vector<int>> p must already be solved for the two adjacent points (down and right) to n-i,n-j.
//n is total number of points
void getPaths(vector<vector<int>> & p, int i, int j, int n)
{
	int numPaths;
	if (i == 0)
	{
		numPaths = p[n - j + 1][n - i];
	}
	else if (j == 0)
	{
		numPaths = p[n - j][n - i + 1];
	}
	else
	{
		numPaths = p[n - j + 1][n - i] + p[n - j][n - i + 1];
	}

	p[n - j][n - i] = numPaths;
}

int main()
{
	int boxSize = 20; 
	vector<vector<int>> pathsAtPoints(boxSize+1, vector<int> (boxSize+1));

	pathsAtPoints[boxSize][boxSize] = 1; //Need to initialize the final point as 1 in order for getPaths to work for points adjacent to 20,20

	int numDiags = boxSize * 2; //numDiags is the number of diagonal lines needed to intersect every point, (exclusing boxSize,boxSize)

	for (int diag = 0; diag < numDiags; diag++)
	{
		int j = 1;
		int i = 0;
		for (int numPoints = 2; numPoints < boxSize + 1; numPoints++)
		{
			getPaths(pathsAtPoints, i, j, boxSize);
			i++;
			j--;
		}
	}

}

