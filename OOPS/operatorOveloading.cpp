// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Base1 { 
  public:
  Base1(){
      cout<<"I am a base class"<<endl;
  }  
  virtual void func(){
      cout<<"I am a free func"<<endl;
  }
  void func2(){
      cout<<"I am mother of Derived"<<endl;
  }
};
class Base2{
    public: 
    Base2(){
        cout<<"I am also a base class"<<endl;
    }
    void func2(){
        cout<<"I am father of Derived"<<endl;
    }
    
};

class CompilePol{
   private :
    int real;
    int imag;
   public:
   CompilePol(int r, int i){
       this->real = r;
       this->imag = i;
   }
   CompilePol operator+(CompilePol const&obj){
       CompilePol res(0,0);
       res.real = real + obj.real;
       res.imag = imag +  obj.imag;
       return res;
   }
   void print(){
       cout<<real<<"+i"<<imag;
   }
};

class Derived : public Base1, public Base2{
    public:
    Derived(){
        cout<<"I am a derived class"<<endl;
    }
    void func(){
        cout<<"Now i am not free"<<endl;
    }
};
int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";
    Derived d;
    d.Base2::func2();
    
    CompilePol a1(2,4), b1(4,6),a3(0,0);
    a3 = a1+b1;
    a3.print();
    return 0;
}