#include<iostream>
using namespace std;

class A {
    int a;
    public:
    void display(int x){
        this->a = x;
        cout<<"display my value"<<endl;
    }
};

class B : A{
    public:
    void display(int y){
       A::display(y);   // works same as super keyword in java
    }
};

int main(){
    B* obj = new B();
    obj->display(6);
    return 0;
}