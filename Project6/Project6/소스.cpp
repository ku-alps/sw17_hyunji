#include<iostream>
#include<math.h>
using namespace std;


int max(int n1, int n2, int n3) {
	if (n1 > n2) {
		return (n1 > n3) ? n1 : n3;
	}
	else
		return (n2 > n3) ? n2 : n3;
}





void answer(int* array, int num);



int main() {



	int num;

	cin >> num;

	int* wine = new int[num];



	for (int i = 0; i < num; i++) {

		cin >> wine[i];

	}





	answer(wine, num);



	delete[] wine;

}



void answer(int* array, int num) {



	int* dp = new int[num];

	dp[0] = array[0];

	dp[1] = array[0] + array[1];

	for (int i = 2; i < num; i++) {

		dp[i] = max(array[i] + dp[i - 2], array[i] + array[i - 1] + dp[i - 3],dp[i - 1]);
		

	}



	cout << dp[num - 1] << endl;



	delete[] dp;

}
