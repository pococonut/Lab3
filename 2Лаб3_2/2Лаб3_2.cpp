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