#include <iostream>

using namespace std;
 
class punkt {
 protected:
int x, y;
   public:
punkt(int i=0, int j=0):x(i), y(j) {}
zmien_wsp(int i, int j) {x=i; y=j;}
virtual void rysuj() { cout << " rysuje punkt " <<  " w    -----   x = " << x << "   ,   y = " << y << endl;}
friend ostream & operator << (ostream & ekran, punkt & p)
 { ekran << "x = " << p.x << "   ,   y = " << p.y; 
   return ekran;
 }
};

class kwadrat : public punkt {
  protected:	
int bok1;
   public:
kwadrat (int i , int j, int k): punkt(i,j), bok1(k){ }
virtual void rysuj() { cout << " rysuje kwadrat " << endl;}    	
friend ostream & operator << (ostream & ekran, kwadrat & k)
 { ekran << "x = " << k.x << "   ,   y = " << k.y <<  " bok = " << k.bok1; 
 return ekran;}
};
////////////
class prostokat : public kwadrat  {
  protected:	
int bok2;
   public:
prostokat (int i , int j, int k1, int k2): kwadrat(i,j,k1 ), bok2(k2) { }
virtual void rysuj() { cout << " rysuje prostokat " << endl;}    	
friend ostream & operator << (ostream & ekran, prostokat & k)
 { ekran << "x = " << k.x << "   ,   y = " << k.y <<  " bok1 = " << k.bok1 
 << " bok2 = " << k.bok2; 
 return ekran;}
};

punkt p1(1,1), p2(4,4);
kwadrat k1(2,2,2);
prostokat pr1(5,5,5,54);
 
void rysuj(punkt * wsk) 
{
   wsk->rysuj(); 
}

main()
{
    cout << "roz punkt  " <<sizeof (punkt) << endl;	 
    cout << "roz kwadrat  " <<sizeof (kwadrat ) << endl;
     rysuj(&p1);	    
     rysuj(&p2);
     rysuj(&k1);
     rysuj(&pr1);
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
