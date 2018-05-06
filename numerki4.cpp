#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int N = 3;
double f(double x)
{
	return x*x - 8 ;
}
double fu(double x) // trzeba dobrac odpowiednio !
{
	return (3 + x);
}

double simpson (double xp, double xk, double eps)
{
	int powtorz = 0;
	double s,st,dx,x,ss, wynik;
	s = 0; 
	st = 0;
	dx = (xk - xp) / N;
	for(int i = 1; i <= N; i++)
	{
		x = xp + i * dx;
		st += f(x - dx / 2.0);
		if(i < N) s += f(x);
	}
	s = dx / 6.0 * (f(xp) + f(xk) + 2.0 * s + 4.0 * st);
	N ++;
	do {
		ss = 0; 
		st = 0;
		dx = (xk - xp) / N;
		for(int i = 1; i <= N; i++)
		{
			x = xp + i * dx;
			st += f(x - dx / 2.0);
			if(i < N) ss += f(x);
		}
		ss = dx / 6.0 * (f(xp) + f(xk) + 2.0 * ss + 4.0 * st);
		if (fabs(ss-s) < eps) {
			wynik = ss;
			powtorz = 1;
		}
		else {
			ss = s ;
		}
	} while (powtorz == 0);
	return wynik;

}
void gauss (void)
{
	double C;
	for (int i = 2 ; i <=5 ; i++)
	{
		C=0;
		for (int j = 0 ; j <= i ; j ++)
		{
			C += fu(cos(((2.0*j+1.0)/(2.0*i+2.0))*M_PI));
		}
		
		cout << endl << "Gauss dla " << i << " wezlow : " << (M_PI/(i+1))*C << endl;
	}
}

int main() 
{ 
		double xp, xk, eps;
		cout << setprecision(6) << fixed;
		cout << "Obliczanie całki przy pomocy kwadratury Netona-Cotesa (wzor Simpsona) dla f(x)=x^2 - 8\n";
		cout << "Podaj poczatek przedzialu calkowania :\n";
		cin >> xp;
		cout << "\nPodaj koniec przedzialu calkowania\n";
		cin >> xk;
		cout << "\nPodaj dokladnosc calkowania\n";
		cin >> eps;
		cout << endl;
		cout << "Wartosc calki wynosi : " << setw(8) << simpson(xp, xk, eps);
		cout << "\nObliczanie całki przy pomocy kwadratury Gaussa (wielomian Czybyszewa) dla w(x)=(1)/sqrt(1-x^2) i f(x)=3 + x\n";
		gauss();


return 0;	
}

