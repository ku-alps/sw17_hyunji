#include<iostream>
using namespace std;

bool compare(int** array, int x, int y, int size);
void QuadTree(int **array, int x, int y, int size);

int main() {
	int n;
	cin >> n;

	int** array;  //2차원 배열 동적할당
	array = new int*[n];
	for (int i = 0; i < n; i++)
		array[i] = new int[n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> array[i][j];
		}
	}


	QuadTree(array, 0, 0, n); //함수 호출
	cout << "\n";

	return 0;

}



bool compare(int** array, int x, int y, int size) {
	for (int i = 0; i < size; i++) 
		for (int j = 0; j < size; j++) 
			if (array[x][y] != array[x+i][y+j])
				return false;
	return true;

}  //같은지 비교하는 함수


void QuadTree(int** array, int x, int y, int size) {

	
		if (compare(array, x, y, size) == true)
			cout << array[x][y];
		else
		{
			cout << "(";
			QuadTree(array, x, y, size / 2);
			QuadTree(array, x, y + size / 2, size / 2);
			QuadTree(array, x + size / 2, y, size / 2);
			QuadTree(array, x + size / 2, y + size / 2, size / 2);
			cout << ")";



		} //이 함수를 재귀호출한다

}