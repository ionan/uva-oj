/*
	Long time ago, most of PCs were equipped with video cards that worked only in
	text mode. If the programmer wanted to show a picture on a screen, he had to use
	pseudographics or ASCII art like this on the right:
	
	In this problem you are given a polygon, drawn using ASCII art. Your task is
	to calculate its area.
	
	The picture is formed using characters ‘.’, ‘\’, and ‘/’. Each character represents
	a unit square of the picture. Character ‘.’ represents an empty square, character
	‘/’ — a square with a segment from the lower left corner to the upper right corner,
	and character ‘\’ — a square with a segment from the upper left corner to the lower
	right corner.
	
	INPUT
	
	The input file contains several test cases, each of them as described below.
	The first line of each case contains integer numbers h and w (2 ≤ h, w ≤ 100) — height and width
	of the picture. Next h lines contain w characters each — the picture drawn using ASCII art.
	It is guaranteed that the picture contains exactly one polygon without self-intersections and selftouches.
	
	OUTPUT
	
	For each test case, print to the output file one integer number — the area of the polygon.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int trash, h, w, i, j, area, unitSquaresSoFar, isInside;
	char line[101];
	while (scanf("%d %d", &h, &w) != EOF){
		area = 0;
		for (i = 0; i < h; i++){
			trash = scanf("%s", line);
			unitSquaresSoFar = 0;
			isInside = 0;
			for (j = 0; j < w; j++){
				if (line[j] == '\\' || line[j] == '/'){
					unitSquaresSoFar += isInside;
					isInside = isInside ? 0 : 1;
				} else if (isInside){
					unitSquaresSoFar++;
				}
			}
			area += unitSquaresSoFar;
		}
		printf("%d\n", area);
	}
	return 0;
}