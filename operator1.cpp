#include <iostream>
using namespace std;

class l_zes {
	int re, im;
public:
	l_zes (int i, int j): re(i), im(j) {}
	void wypisz();
    l_zes operator+ (const l_zes& a);
    l_zes operator+ (int a);  // 
    //friend l_zes operator+ (const l_zes&, int);
    //friend l_zes operator+ (const l_zes&, const l_zes&);
    friend l_zes operator+ (int , const l_zes&);
    void wstaw(int i, int j)
    {  re=i; im=j;}	
};

l_zes z1(0,0);
l_zes z2(0,0);
l_zes z3(0,0);

main()
{
	z1.wstaw(3,3);
	z2.wstaw(2,2);
	z3 = z1.operator+(z2);  // 
	//z3 = operator+(z2,z1);
	z3 = z1 + z2;
	z3 = z1 + 2;
	z3 = 232 + z2;
	z3.wypisz();
    system("pause");
}
/////////////////////////////////////
void l_zes::wypisz()
{
	cout << " re  " << re << " ,  im   " << this->im<<endl;
}
///////////////////////////////////
inline l_zes l_zes::operator+ (const l_zes & a)
{
	return l_zes(a.re + re, 	a.im + im);
} 
l_zes  l_zes::operator+ (int a)
{
	return l_zes(a + re, im);
} 
////////////////////////
l_zes operator+ (int a, const l_zes& b)
{return l_zes(a + b.re, b.im);}

//l_zes operator+ (const l_zes& a, const l_zes& b)
//{return l_zes(a.re + b.re, a.im + b.im);}
