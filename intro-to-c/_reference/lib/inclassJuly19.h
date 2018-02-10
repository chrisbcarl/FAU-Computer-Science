
#include<iostream>
using namespace std;

void test(int **C, int n, int m)
{
	int i, j;
	cout << "Test is called" << endl;
	for (i = 0; i<n; i++) {
		for (j = 0; j<m; j++) {
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void test2(int **A, int n1, int m1, int **B, int *n2, int *m2)
{
	int i, j;
	*n2 = n1;
	*m2 = m1;


	for (i = 0; i<n1; i++)
		for (j = 0; j<m1; j++)
			B[i][j] = A[i][j] + 1;




}

int main()
{
	int n = 4, m = 5;
	int A[4][5] = { { 1,2,3 },{ 4,5,6 },{ 7,8 },{ 9,10,11,12,13 } };
	int i, j;
	for (i = 0; i<n; i++) {
		for (j = 0; j<m; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int **B;
	B = new int *[n];

	for (i = 0; i< n; i++)
		B[i] = new int[m];



	for (i = 0; i<n; i++)
		for (j = 0; j<m; j++)
			B[i][j] = A[i][j];

	int **C;
	int n2, m2;



	test(B, n, m);

	C = new int *[n];
	for (i = 0; i<n; i++) {
		C[i] = new int[m];
	}

	test2(B, n, m, C, &n2, &m2);


	test(C, n2, m2);



	return 0;
}