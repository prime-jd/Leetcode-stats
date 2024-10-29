#include<iostream>
using namespace std;

class sol {
    //by default private
    int var;
    public:
       void getVar(int x){
        this->var = x;
        cout<<var<<endl;
       }


};

int main(){
     sol* obj= new sol();
     obj->getVar(4);   // creates object on heap


     sol obj1;
     obj->getVar(6);  // creates obj on stack
}