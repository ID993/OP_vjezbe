/* Zadatak_2.cpp :

Definirati strukturu koja opisuje matricu. Napisati program za osnovne
operacije s matricama čiji su elementi decimalni brojevi(float).Program
treba imati sljedeće funkcije :
• funkciju za unos matrice mxn,
• funkciju za generiranje matrice mxn s elementima u rasponu[a, b],
• funkcije za zbarajanje, oduzimanje, množenje matrica,
• funkciju za trasponiranje matrice,
• funkciju za ispisivanje matrice.Elementi matrice se ispisuju na četiri
decimale, poravnati udesno.

#include "pch.h"
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;


struct matrix
{
	int rows, cols;
	//float num[20][20];
	float** num;


	matrix matrix_input()
	{
		matrix A{};
		cout << "Enter number of rows and columns of matrix A: " << endl;
		cin >> A.rows;
		cin >> A.cols;

		
		A.num = new float* [A.rows];
		for (int i = 0; i < A.rows; i++)
			A.num[i] = new float[A.cols];

		cout << "Enter elements of matrix A: " << endl;

		for (int i = 0; i < A.rows; i++)
			for (int j = 0; j < A.cols; j++)
				cin >> A.num[i][j];

		return A;
	}


	matrix generate_matrix()
	{
		matrix B{};
		int a, b;
		cout << "Enter intervals: " << endl;
		cin >> a;
		cin >> b;
		cout << "Enter number of rows and columns of matrix B: " << endl;
		cin >> B.rows;
		cin >> B.cols;

		B.num = new float* [B.rows];
		for (int i = 0; i < B.rows; i++)
			B.num[i] = new float[B.cols];

		for (int i = 0; i < B.rows; i++)
		{
			for (int j = 0; j < B.cols; j++)
				B.num[i][j] = a + rand() % (b - a + 1); // a + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (b - a))); //a + rand() % (b - a + 1);
		}
		return B;
	}

	matrix sum_matrices(matrix a, matrix b)
	{
		matrix C{};

		if (a.rows == b.rows && a.cols == b.cols)
		{
			C.rows = a.rows;
			C.cols = a.cols;
			C.num = new float* [C.rows];
			for (int i = 0; i < C.rows; i++)
				C.num[i] = new float[C.cols];

			for (int i = 0; i < C.rows; i++)
				for (int j = 0; j < C.cols; j++)
					C.num[i][j] = a.num[i][j] + b.num[i][j];
			return C;
		}
		
	}

	matrix subtract_matrices(matrix a, matrix b)
	{
		matrix D{};

		if (a.rows == b.rows && a.cols == b.cols)
		{
			D.rows = a.rows;
			D.cols = a.cols;
			D.num = new float* [D.rows];
			for (int i = 0; i < D.rows; i++)
				D.num[i] = new float[D.cols];
			for (int i = 0; i < D.rows; i++)
				for (int j = 0; j < D.cols; j++)
					D.num[i][j] = a.num[i][j] - b.num[i][j];
			return D;
		}
		
	}

	matrix multiply_matrices(matrix a, matrix b)
	{
		matrix E{};
		int k, l;
		if (a.cols == b.rows)
		{
			E.rows = a.rows;
			E.cols = b.cols;
			E.num = new float* [a.rows];
			for (int i = 0; i < a.rows; i++)
				E.num[i] = new float[b.cols];

			for (int i = 0; i < E.rows; i++)
				for (int j = 0; j < E.cols; j++)
					E.num[i][j] = 0;

			for (int i = 0; i < E.rows; i++)
			{
				for (int j = 0; j < E.cols; j++)
				{
					k = 0;
					l = 0;
					while (k < a.cols && l < b.rows)
					{
						E.num[i][j] += a.num[i][k++] * b.num[l++][j];
					}
				}
			}
			return E;
		}
		
	}

	matrix transposed_matrix(matrix a)
	{
		matrix F{};

		F.rows = a.cols;
		F.cols = a.rows;
		F.num = new float* [F.rows];
		for (int i = 0; i < F.rows; i++)
			F.num[i] = new float[F.cols];

		for (int i = 0; i < F.rows; i++)
		{
			for (int j = 0; j < F.cols; j++)
				F.num[i][j] = a.num[j][i];
		}
		return F;
	}

	void print_matrix(matrix a)
	{
		for (int i = 0; i < a.rows; i++)
		{
			for (int j = 0; j < a.cols; j++)
			{
				cout << setw(16) << right << setprecision(4) << fixed << a.num[i][j]; // << '\t';
			}
			cout << endl;
		}
	}

};


int main()
{
	matrix matrixA = matrixA.matrix_input();
	matrix matrixB = matrixB.generate_matrix();
	matrix matrixC = matrixC.sum_matrices(matrixA, matrixB);
	matrix matrixD = matrixD.subtract_matrices(matrixA, matrixB);
	matrix matrixE = matrixE.multiply_matrices(matrixA, matrixB);
	matrix matrixF = matrixF.transposed_matrix(matrixA);
	cout << "Matrix A: " << endl;
	matrixA.print_matrix(matrixA);
	cout << "Matrix B: " << endl;
	matrixB.print_matrix(matrixB);
	cout << "Sum of A and B: " << endl;
	matrixC.sum_matrices(matrixA,matrixB);
	cout << "Subtraction of A and B: " << endl;
	matrixD.print_matrix(matrixD);
	cout << "Multiplication of A and B: " << endl;
	matrixE.print_matrix(matrixE);
	cout << "Transposed Matrix A: " << endl;
	matrixF.print_matrix(matrixF);


}

