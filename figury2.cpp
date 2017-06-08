#include <iostream>

using namespace std;

class figura {
 protected:
int x, y;
   public:
figura(int i=0, int j=0):x(i), y(j) {}
zmien_wsp(int i, int j) {x=i; y=j;}
virtual void rysuj() = 0;
};

class punkt : public figura {
//int x, y;	
    public:
punkt(int i=0, int j=0):figura(i, j) {}
virtual void rysuj() { cout << " rysuje punkt " <<  " w    -----   x = " << /*figura::x*/ x<< "   ,   y = " << y << endl;}
friend ostream & operator << (ostream & ekran, punkt & p)
 { ekran << "x = " << p.x << "   ,   y = " << p.y; 
   return ekran;
 }
};

class kwadrat : public figura {
  protected:	
int bok;
   public:
kwadrat (int i , int j, int k): figura(i,j), bok(k){ }
void rysuj() { cout << " rysuje kwadrat " << endl;}    	
friend ostream & operator << (ostream & ekran, kwadrat & k)
 { ekran << "x = " << k.x << "   ,   y = " << k.y <<  " bok = " << k.bok; 
 return ekran;}
};
////////////
class prostokat : public figura  {
  protected:	
int bok1, bok2;
   public:
prostokat (int i , int j, int k1, int k2): figura(i,j), bok1(k1), bok2(k2) { }
void rysuj() { cout << " rysuje prosotak " << endl;}    	
friend ostream & operator << (ostream & ekran, prostokat & k)
 { ekran << "x = " << k.x << "   ,   y = " << k.y <<  " bok1 = " << k.bok1 
 << " bok2 = " << k.bok2; 
 return ekran;}
};


punkt p1(1,1), p2(4,4);
kwadrat k1(2,2,2);
prostokat pr1(5,5,5,54);

void rysuj_fig (figura &ref) { ref.rysuj();}


figura f;
main()
{
    	cout << sizeof(punkt) << endl;
		
		rysuj_fig(p1);
    	rysuj_fig(k1);
    	rysuj_fig(pr1);
    	rysuj_fig(p2);
	
	
		system("pause");
}
