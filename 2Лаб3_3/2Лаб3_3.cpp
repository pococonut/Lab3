#include <iostream>
#include <fstream>
#include <math.h>
#include <complex>
using namespace std;

//Решение СЛАУ с комплексными коэффициентами
int SLAU(complex <float>** matrica_a, int n,
	complex <float>* massiv_b, complex <float>* x)
{
	int i, j, k, r;
	complex <float> c, M, s;
	float max;
	complex <float>** a, * b;
	a = new complex <float> *[n];
	for (i = 0; i < n; i++)
		a[i] = new complex <float>[n];
	b = new complex <float>[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = matrica_a[i][j];
	for (i = 0; i < n; i++)
		b[i] = massiv_b[i];
	for (k = 0; k < n; k++)
	{
		max = abs(a[k][k]);
		r = k;
		for (i = k + 1; i < n; i++)
			if (abs(a[i][k]) > max)
			{
				max = abs(a[i][k]);
				r = i;
			}
		for (j = 0; j < n; j++)
		{
			c = a[k][j];
			a[k][j] = a[r][j];
			a[r][j] = c;
		}
		c = b[k];
		b[k] = b[r];
		b[r] = c;
		for (i = k + 1; i < n; i++)
		{
			for (M = a[i][k] / a[k][k], j = k; j < n; j++)
				a[i][j] -= M * a[k][j];
			b[i] -= M * b[k];
		}
	}
	if (abs(a[n - 1][n - 1]) == 0)
		if (abs(b[n - 1]) == 0)
			return -1;
		else return -2;
	else
	{
		for (i = n - 1; i >= 0; i--)
		{
			for (s = 0, j = i + 1; j < n; j++)
				s += a[i][j] * x[j];
			x[i] = (b[i] - s) / a[i][i];
		}
		return 0;
	}
	for (i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
	delete[] b;
}

//Вычисление обратной матрицы
//с комплексными коэффициентами
int INVERSE(complex <float>** a, int n,
	complex <float>** y)
{
	int i, j, res;
	complex <float>* b, * x;
	b = new complex <float>[n];
	x = new complex <float>[n];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			if (j == i)
				b[j] = 1;
			else b[j] = 0;
		res = SLAU(a, n, b, x);
		if (res != 0)
			break;
		else
			for (j = 0; j < n; j++)
				y[j][i] = x[j];
	}
	delete[] x;
	delete[] b;
	if (res != 0)
		return -1;
	else
		return 0;
}
//Вычисление определителя матрицы
//с комплексными коэффициентами
complex <float> determinant(complex <float>** matrica_a,
	int n)
{
	int i, j, k, r;
	complex <float> c, M, s, det = 1;
	complex <float>** a;
	float max;
	a = new complex <float> *[n];
	for (i = 0; i < n; i++)
		a[i] = new complex <float>[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = matrica_a[i][j];
	for (k = 0; k < n; k++)
	{
		max = abs(a[k][k]);
		r = k;
		for (i = k + 1; i < n; i++)
			if (abs(a[i][k]) > max)
			{
				max = abs(a[i][k]);
				r = i;
			}
		if (r != k) det = -det;
		for (j = 0; j < n; j++)
		{
			c = a[k][j];
			a[k][j] = a[r][j];
			a[r][j] = c;
		}
		for (i = k + 1; i < n; i++)
			for (M = a[i][k] / a[k][k], j = k; j < n; j++)
				a[i][j] -= M * a[k][j];
	}
	for (i = 0; i < n; i++)
		det *= a[i][i];
	return det;
	for (i = 0; i < n; i++)
		delete[] a[i];
	delete[] a;
}


int main()
{
	setlocale(LC_ALL, "RU");
	int i, j, p, N;
	complex <float>** A, ** B, ** C, ** At, **A2, **X;
	ifstream f;
	ofstream g;
	f.open("comp_matrix.txt");
	f >> N;
	cout << "N=" << N << endl;

	A = new complex <float> *[N];
	for (i = 0; i < N; A[i] = new complex <float>[N], i++);

    At = new complex <float> *[N];
    for (i = 0; i < N; At[i] = new complex <float>[N], i++);

    A2 = new complex <float> *[N];
    for (i = 0; i < N; A2[i] = new complex <float>[N], i++);

	C = new complex <float> *[N];
	for (i = 0; i < N; C[i] = new complex <float>[N], i++);

	X = new complex <float> *[N];
	for (i = 0; i < N; i++)
		X[i] = new complex <float>[N];

	for (i = 0; i < N; i++)
		for (j = 0; j < N; f >> A[i][j], j++);

	cout << endl << "Матрица A\n";
	for (i = 0; i < N; cout << endl, i++)
		for (j = 0; j < N; cout << A[i][j] << "     ", j++);

	complex <float> x(3.2, 1.8);

    cout << endl << "Матрица A^T\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            At[i][j] = A[j][i];
        }
    }
    for (i = 0; i < N; cout << endl, i++)
        for (j = 0; j < N; cout << At[i][j] << "     ", j++);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; At[i][j] = At[i][j] * x, j++);

	cout << endl << "Матрица A^T*x\n";
	for (i = 0; i < N; cout << endl, i++)
		for (j = 0; j < N; cout << At[i][j] << "     ", j++);

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (C[i][j] = p = 0; p < N; p++)
                A2[i][j] += A[i][p] * A[p][j];

    cout << endl << "Матрица A*A\n";
    for (i = 0; i < N; cout << endl, i++)
        for (j = 0; j < N; cout << A2[i][j] << "     ", j++);

    cout << endl << "Матрица C\n";
    for (i = 0; i < N; i++)
        for (j = 0; j < N; C[i][j] = At[i][j] - A2[i][j], j++);

    for (i = 0; i < N; cout << endl, i++)
        for (j = 0; j < N; cout << C[i][j] << "     ", j++);


	if (!INVERSE(C, N, X))
	{
		cout << endl << "Обратная матрица C\n";
		for (i = 0; i < N; cout << endl, i++)
			for (j = 0; j < N; j++)
				cout << X[i][j] << "     ";
	}
	else cout << "Не существует обратной матрицы\n";
	cout << endl << "Определитель=" << determinant(A, N) << endl;

	f.close();
}