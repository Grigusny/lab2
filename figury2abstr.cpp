#include <iostream>

using namespace std;
 
class figura  {
 protected:
int x, y;
   public:
figura (int i=0, int j=0):x(i), y(j) {}
void zmien_wsp(int i, int j) {x=i; y=j;}
virtual void rysuj() = 0;
virtual void policzPole()=0;
};

class kwadrat : public figura {
  protected:	
int bok1;
   public:
kwadrat (int i , int j, int k): figura(i,j), bok1(k){ }
virtual void rysuj() { cout << " rysuje kwadrat " << endl;}    	
friend ostream & operator << (ostream & ekran, kwadrat & k)
 { ekran << "x = " << k.x << "   ,   y = " << k.y <<  " bok = " << k.bok1; 
 return ekran;}
virtual void policzPole() { } 
};
////////////
class prostokat : public figura  {
  protected:	
int bok1, bok2;
   public:
prostokat (int i , int j, int k1, int k2): figura(i,j), bok1(k1), bok2(k2) { }
virtual void rysuj() { cout << " rysuje prostokat " << endl;}    	
friend ostream & operator << (ostream & ekran, prostokat & k)
 { ekran << "x = " << k.x << "   ,   y = " << k.y <<  " bok1 = " << k.bok1 
 << " bok2 = " << k.bok2; 
 return ekran;}
virtual void policzPole() { }
};

// figura p3; blad 
figura * p1;
kwadrat k1(2,2,2);
prostokat pr1(5,5,5,54);
 
void rysuj(figura &ref) 
{
   ref.rysuj(); 
}

main()
{
    
	 rysuj(k1);
     rysuj(pr1);
	//wsk_p =  &p1; //p1.rysuj(); 
	  //   wsk_p->rysuj();
    //wsk_p =  &p2; //p1.rysuj(); 
	  //   wsk_p->rysuj();	     
	//wsk_p =  &k1;
//	     wsk_p->rysuj();
//	wsk_p =  &pr1;
//	     wsk_p->rysuj();
	
	
		system("pause");
}
