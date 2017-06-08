#include <iostream>
#include <cstring>
using namespace std;
class string1 {
  int roz;
  char * wsk;
 public:
 	string1 (int r=8):roz(((r-1)/8)+1), wsk (new char[(roz*8)+1]){ } 
	string1 (const char t[]):roz( ( ( (strlen(t))-1 )/8)+1), wsk (new char[(roz*8)+1])
	     {strcpy(wsk, t);} 
	string1 (const string1 &s):roz(s.roz), wsk (new char[(roz*8)+1])
	     {strcpy(wsk, s.wsk);} 
	string1 & operator= (const string1 &s)
	{
	    if (roz!=s.roz) {
		          delete [] wsk; 
		          roz = s.roz;
		          wsk  = new char[(roz*8)+1];
		          }
	    strcpy(wsk,s.wsk);
	    return *this;
	} 
	
	string1 operator +=(const string1 &s)
	{  string1 temp = *this; // apamietuje s1
	   if (wsk!=s.wsk) { delete [] wsk; 
	                     roz=temp.roz+s.roz;
	                     wsk  = new char[(roz*8)+1];  
	                   }
	   strcpy(wsk, temp.wsk); 
	   strcat(wsk, s.wsk);
	   return *this;
	}
    friend string1 operator +(const string1 &a,  const string1 &b)
	{  string1 temp (a.roz+b.roz);
	   strcpy(temp.wsk, a.wsk);
	   strcat(temp.wsk, b.wsk);
	   return temp;
	}
	
		     
	~string1() {delete [] wsk;}
	operator char * () {return wsk;	}
	//operator int () {return roz;}
};

void fun(int  roz) { cout << "przetwarzam string o  roz = " << roz << endl;}


string1 s1("ala");
string1 s2(" oraz tola");
string1 s3(40);
char t[] = "ala";
main(){   
    //   s3 = s1+s2;
    //fun(s1);
    s3 = "Ala ma kota geografa i psa burka";
    //fun(s3);
    //cout << (char *)s1 << endl;
    //s3= t;
	//s3 = 34;
	s3 = t + s1;
	
	//s3 = (s1+=s2);
    //cout << (int )s3 << endl;
	system("pause");
}


