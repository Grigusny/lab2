#include <iostream>

using namespace std;

class A{
    int *x;
public:
    void setX(int a)
    {
        delete x;
        x=new int;
        *x=a;
    }
    int getX()
    {
        return *x;
    }
    A(int a)
    {
      x=new int;
      *x=a;
    }
    ~A()
    {
        delete x;
        x=NULL;
    }
};

int main()
{
    A obj(2);
    cout << obj.getX();
    obj.setX(3);
}
