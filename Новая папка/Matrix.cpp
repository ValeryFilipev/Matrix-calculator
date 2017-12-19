#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include <stdio.h>
using namespace std;
//( matrix input function)
void inputMatrix(int **a,int n2,int m2) {	
	cout << "Input variables of matrix" << endl;
	for (int i = 0; i < n2; i++)
		for (int j = 0; j < m2; j++)
			cin >> a[i][j];
}
//( output function)
void outputMatrix(int **a, int n2, int m2) {
	cout << "Answer " << endl;
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < m2; j++) {
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}	
}
//( checking the dimension before addition-subtraction)
bool checkingDimensionAddSub(int n1, int m1, int n2, int m2) {
	if (n1 == n2 && m1 == m2)return true;
	else false;
}
//( matrix multiplication function)
void multiply(int **a, int **b, int n1, int m1, int n2, int m2) {
	cout << "Answer " << endl;
	int ans = 0;
	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < m1; j++) {
			ans = 0;
			for (int k = 0; k < m1; k++) {
				ans += (a[i][k] * a[k][j]);
			}
			cout << ans << " ";
		}
		cout << endl;
	}
}
//( matrix addition function)
void amount(int**a, int**b, int**c, int n, int m, int n2, int m2){
	
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				c[i][j] = a[i][j] + b[i][j];				 
}
//( matrix subtraction function)
void subtraction(int**a, int**b, int**c, int n1, int m1, int n2, int m2) {	
		for (int i = 0; i < n1; i++)
			for (int j = 0; j < m1; j++)
				c[i][j] = a[i][j] - b[i][j];		
}

int search(int **a, int m, int n, int what,
	bool match, unsigned int &uI, unsigned int &uJ, unsigned int starti, unsigned int startj) {
	//( Search in the matrix a [m] [n] of the element with the specified value of what
	// Its row number and column uI, uJ are returned if an element is found.
	//match - search for an equal element or different from the specified.
	 // Return 0 - not found, not 0 - found)
	if ((!m) || (!n)) return 0;
	if ((starti >= n) || (startj >= m)) return 0;
	for (unsigned int i = starti; i < n; i++)
		for (unsigned int j = startj; j < m; j++) {
			if (match == true) {
				if (a[i][i] == what) {
					uI = i; uJ = j; return 1;
				}
			}
			else if (a[i][j] != what) {
				uI = i; uJ = j; return 1;
			}
		}
	return 0;
}

void swaprows(int **a, int n, int m, unsigned int x1, unsigned int x2) {
	//( Changes in the matrix a [n] [m] rows with numbers x1 and x2 places)
	if ((!n) || (!m)) return;
	if ((x1 >= n) || (x2 >= n) || (x1 == x2)) return;
	double tmp;
	for (unsigned int x = 0; x < m; x++) {
		tmp = a[x1][x];
		a[x1][x] = a[x2][x];
		a[x2][x] = tmp;
	}
	return;
};

void swapcolumns(int **a, int n, int m, unsigned int x1, unsigned int x2) {
	//( Changes in the matrix a [n] [m] the columns with the numbers x1 and x2 in places)
	if ((!n) || (!m)) return;
	if ((x1 >= m) || (x2 >= m) || (x1 == x2)) return;
	double tmp;
	for (unsigned int x = 0; x < n; x++) {
		tmp = a[x][x1];
		a[x][x1] = a[x][x2];
		a[x][x2] = tmp;
	}
	return;
};

double determinant(int **a, int n) {
	//( Calculation of the determinant of the square matrix a [m] [n])
	unsigned int m = n;
	if (m == 0) return 0;
	if (m == 1) return a[0][0];
	if (m == 2) return //(a[0][0] * a[1][1] - a[1][0] * a[0][1]);
	bool sign = false; //( change sign of the determinant. by default - does not change)
	double det = 1;  //( determinant)
	double tmp;
	unsigned int x, y;
	for (unsigned int i = 0; i < n; i++) { //( cycle along the main diagonal)
		if (a[i][i] == 0) { //( If the element on the diagonal is 0, then we are looking for a nonzero element in the matrix)
			if (!search(a, m, n, 0, false, y, x, i, i)) return 0; //( if all elements are zero, then send. = 0)
			if (i != y) { //( change i-th row from y-th)
				swaprows(a, m, n, i, y);
				sign = !sign;
			}
			if (i != x) { (change the i-th column with the x-th)
				swapcolumns(a, m, n, i, x);
				sign = !sign;
			}
			//( thus, in a [i] [i], now a nonzero element)
		}
		//( we take the element a [i] [i] for the determinant)
		det *= a[i][i];
		tmp = a[i][i];
		for (x = i; x < m; x++) {
			a[i][x] = a[i][x] / tmp;
		}
		//( so a [i] [i] is now 1)
		//( we nullify all the elements that stand under the (i, i) th)
		//( by subtraction from the definition. By the coefficient)
		for (y = i + 1; y < n; y++) {
			tmp = a[y][i];
			for (x = i; x < m; x++)
				a[y][x] -= (a[i][x] * tmp);
		}
	}
	if (sign) return det*(-1);
	return det;
};
// matrix multiplication by number
void multipleOnNumber(int **a, int m, int n) {
	int number;
	cout << "Enter the number for the first matrix, which you want to multiply" << endl;
	cin >> number;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << number*a[i][j] << "  ";
		}
		cout << endl;
	}
}

int main() 
{
// command to change colors in the console
	system("color 8E");
	int n1, m1;	
	cout << "Input dimension of first matrix A " << endl;
	cin >> n1 >> m1;	
	int **a = new int*[n1];
	for (int i = 0; i < n1; i++) {
		a[i] = new int[m1];
	}
	inputMatrix(a, n1, m1);
	int n2, m2;
	cout << "Input dimension of second matrix B "<<endl;
	cin >> n2 >> m2;
	int **b = new int*[n2];
	int **c = new int*[n2];
	for (int i = 0; i < n2; i++) {
		b[i] = new int[m2];
		c[i] = new int[m2];
	}
    // various checks for input and output of matrices
	inputMatrix(b, n2, m2);	
	if (checkingDimensionAddSub(n1, m1, n2, m2) == true) {
	    amount(a, b, c, n1, m1, n2, m2);
		outputMatrix(c, n1, m1);
	}
	else cout << "Matrices have different dimension" << endl;
	if (checkingDimensionAddSub(n1, m1, n2, m2) == true) {
		subtraction(a, b, c, n1, m1, n2, m2);
		outputMatrix(c, n1, m1);
	}
	else cout << "Matrices have different dimension" << endl;
	if (m1 != n2)
		cout << "Matrices cannot multiply"<< endl; else {
		multiply(a, b, n1, m1, n2, m2);
	}
	cout << "___________________________________" << endl;
	multipleOnNumber(a, n1, m1);
	cout << determinant(a, n1)<<" = Answer determinant our the first matrix"<< endl;
	
	system("pause");
	return 0;
}

