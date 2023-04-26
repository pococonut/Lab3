## Лабораторная работа № 3.

Золотухина П. В.
Группа 23/3
Вариант 4

### Задача 1
4.	Подсчитать количество пробелов в тексте.

#### Программа
```
#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");

    string s;

    cout << "Введите строку:" << endl;
    getline(cin, s, '\n');

    int l = s.length();
    int spaces = 0;

    for (int i = 0; i < l; i++)
    {
        if (s[i] == ' ') spaces++;
    }

    cout << "Количество пробелов: "<< spaces;
}

```

#### Вывод
![image](https://user-images.githubusercontent.com/114181600/234595592-cd8ad22d-b5e5-4b03-97ad-f67d6c792d47.png)

### Задача 2. 

Разработать программу на языке С++ для решения следующей задачи. Даны комплексные числа. Найти комплесное число  по формуле представленной в табл

![image](https://user-images.githubusercontent.com/114181600/234596274-62f661e9-0608-4e2e-9271-a0743244bad7.png)

#### Программа

```
#include <iostream>
#include <math.h>
# define M_PI = 3.14
using namespace std;
struct complex1
{
	float Re;
	float Im;
};
struct complex2
{
	float Modul;
	float Argum;
};
complex1 vvod1()
{
	complex1 temp;
	cout << "Введите действительную часть числа\n";
	cin >> temp.Re;
	cout << "Введите мнимую часть комплексного числа\n";
	cin >> temp.Im;
	return temp;
}
void vivod(complex1 chislo)
{
	cout << chislo.Re;
	if (chislo.Im >= 0)
		cout << " +" << chislo.Im << " i" << endl;
	else
		cout << " " << chislo.Im << " i" << endl;
}

complex1 perevod(complex2 chislo, bool pr = false)
{
	complex1 temp;
	temp.Re = chislo.Modul * cos(chislo.Argum);
	temp.Im = chislo.Modul * sin(chislo.Argum);
	if (pr) vivod(temp);
	return temp;
}

complex2 perevod(complex1 chislo, bool pr = false)
{
	complex2 temp;
	temp.Modul = sqrt(chislo.Re * chislo.Re +
		chislo.Im * chislo.Im);
	temp.Argum = atan(chislo.Im / chislo.Re);
	return temp;
}


complex1 plus1(complex1 chislo1, complex1 chislo2,
	bool pr = true)
{
	complex1 temp;
	temp.Re = chislo1.Re + chislo2.Re;
	temp.Im = chislo1.Im + chislo2.Im;
	if (pr) vivod(temp);
	return temp;
}

complex1 minus1(complex1 chislo1, complex1 chislo2,
	bool pr = true)
{
	complex1 temp;
	temp.Re = chislo1.Re - chislo2.Re;
	temp.Im = chislo1.Im - chislo2.Im;
	if (pr) vivod(temp);
	return temp;
}

complex1 mult1(complex1 chislo1, complex1 chislo2,
	bool pr = true)
{
	complex1 temp;
	temp.Re = chislo1.Re * chislo2.Re - chislo1.Im * chislo2.Im;
	temp.Im = chislo1.Im * chislo2.Re + chislo1.Re * chislo2.Im;
	if (pr) vivod(temp);
	return temp;
}

complex1 divide1(complex1 chislo1, complex1 chislo2,
	bool pr = true)
{
	complex1 temp;
	temp.Re = (chislo1.Re * chislo2.Re + chislo1.Im * chislo2.Im) /
		(chislo2.Re * chislo2.Re + chislo2.Im * chislo2.Im);
	temp.Im = (chislo1.Im * chislo2.Re - chislo1.Re * chislo2.Im) /
		(chislo2.Re * chislo2.Re + chislo2.Im * chislo2.Im);
	if (pr) vivod(temp);
	return temp;
}

complex1 pow1(complex1 chislo1, int n, bool pr = true)
{
	complex1 temp;
	complex2 temp2;
	float p = 1;
	int i = 1;
	temp2 = perevod(chislo1, true);	
	for (; i <= n; p *= temp2.Modul, i++);
	temp.Re = p * cos(n * temp2.Argum);
	temp.Im = p * sin(n * temp2.Argum);
	if (pr) vivod(temp);
	return temp;
}

int main()
{
	setlocale(LC_ALL, "RU");
	complex1 a, b, c, d1, d2, d; 		

	a = vvod1(); 			
	b = vvod1();
	c = vvod1();
	cout << endl;
	vivod(a);			
	vivod(b);
	vivod(c);
	
	d1 = plus1(a, b, false);
	cout << endl << "Действие №1: ";
	vivod(d1);

	d1 = divide1(d1, a, false);
	cout << endl << "Действие №2: ";
	vivod(d1);

	d2 = minus1(a, c, false);
	cout << endl << "Действие №3: ";
	vivod(d2);

	d2 = pow1(d2, 2, false);
	cout << endl << "Действие №4: ";
	vivod(d2);

	d = mult1(d1, d2, false);
	
	cout << endl << "Результат: " ;
	vivod(d);
	cout << endl;
	return 0;
}

```

#### Вывод

![image](https://user-images.githubusercontent.com/114181600/234596988-fefab782-cd8b-4fab-8dc1-0b2e3021ade9.png)

### Задача №3. 

![image](https://user-images.githubusercontent.com/114181600/234597451-d276b0ac-2f29-45c4-a25b-9d962e7b4d73.png)

```
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
```

#### Вывод

![image](https://user-images.githubusercontent.com/114181600/234598026-fa078819-2ab1-496b-b38c-78ae196e53fb.png)
