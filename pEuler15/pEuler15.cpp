// This program solves Project Euler problem 15: Lattice Paths
// This program and its comments use the notation that the path starts at (0,0), and point (20,20) is located at the bottom right

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int boxSize = 20; 
	vector<vector<int>> pathsAtPoints(20, vector<int> (20));

	pathsAtPoints[20][20] = 1; //Need to initialize the final point as 1 in order for getPaths to work for points adjacent to 20,20

	int numDiags = boxSize * 2; //numDiags is the number of diagonal lines needed to intersect every point, (exclusing boxSize,boxSize)

}

//This function calculates the number of paths at the point n-i,n-j. vector<vector<int>> p must already be solved for the two adjacent points (down and right) to n-i,n-j.
//n is total number of points
vector<vector<int>> getPaths(vector<vector<int>> p, int i, int j, int n)
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

}