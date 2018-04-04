// tourist.cpp : Defines the entry point for the console application.
// ba`i toa´n nguo`i du li?ch

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>
#define S 10
using namespace std;

void readFile(const char *filePath, int nVertex, int **cost) {
	fstream f;
	f.open(filePath, ios::in);
	for (int i = 0; i < nVertex; i++)
	{
		for (int j = 0; j < nVertex; j++) {
			f >> cost[i][j];
			cout << cost[i][j] << "  ";
		}
		cout << endl;
	}
	f.close();
}

void printWay(int way[S], int nVertex) {
	for (int i = 0; i < nVertex; i++) cout << way[i] << " -> ";
	cout << way[nVertex];
}

void update(int way[S], int *min_way, int nVertex) {
	for (int i = 0; i <= nVertex; i++)
		min_way[i] = way[i];
}

bool check(int way[S], int key, int pos) {
	bool b = false;
	for(int i = 0; i < pos; i++) 
		if (key == way[i]) {
			b = true;
			break;
		}
	return b;
}

void find_Min_Cost_Way(int **cost, int way[S], int *min_way, int nVertex, int verStart, int pos, int &min_cost, int cur_cost) {
	for (int i = 0; i < nVertex; i++) {
		if (pos == nVertex) {
			min_cost = cur_cost;
			update(way, min_way, nVertex);
		}
		else {
			if (check(way, i, pos)) continue;
			way[pos] = i;
			int temp = cur_cost;
			cur_cost += cost[way[pos-1]][way[pos]];
			if (min_cost == 0) {
				find_Min_Cost_Way(cost, way, min_way, nVertex, verStart, pos + 1, min_cost, cur_cost);
			}
			else {
				if (cur_cost > min_cost) break;
				else {
					find_Min_Cost_Way(cost, way, min_way, nVertex, verStart, pos + 1, min_cost, cur_cost);

				}
			}
			cur_cost = temp;
		}
	}
}

int main()
{
	//input the number of vertex
	cout << "nhap vao so dinh and data will load from file cost.txt: ";
	int nVertex ;
	cin >> nVertex;

	//initializing Cost array
	int **cost;
	cost = new int*[nVertex];
	for (int i = 0; i < nVertex; i++) cost[i] = new int[nVertex];
	readFile("cost.txt", nVertex, cost);

	//the starting vertex
	cout << "nhap dinh bat dau : ";
	int verStart ;
	cin >> verStart;

	//initializing Way and Min_way array
	int * way = new int[nVertex + 1];
	way[0] = way[nVertex] = verStart;

	int * min_way = new int[nVertex + 1];
	int min_cost = 0;
	find_Min_Cost_Way(cost, way, min_way, nVertex, verStart, 1, min_cost,0);
	cout << endl;
	cout << "The way costs lest : ";
	printWay(min_way, nVertex);
	cout << endl;
	cout << "And the the price is : " << min_cost + cost[min_way[nVertex - 1]][min_way[nVertex]] << endl;
    return 0;
}


