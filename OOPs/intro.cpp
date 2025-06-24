#include<iostream>
using namespace std;

class Hero{
    //properties
    private:
     int health;
    public:
     char level;
     //default constructor
     Hero(){
        cout << "Constructor Called" << endl;
     }

     //Paramerterised constructor
     Hero (int health){
        cout << "this ->" << this << endl;
        this-> health = health;
     }
     //copy constructor
     Hero(Hero& temp){
      cout << "Copy constructor called" << endl;
      this->health = temp.health;
      this->level = temp.level;
     }

     int getHealth(){
        return health;
     }
     char getLevel(){
        return level;
     }

     void setHealth(int h){
        health = h;
     }

     void setLevel(char ch){
        level = ch;
     }
};

int main(){
    //object created statically
    Hero ramesh(10);
    cout << "Address of ramesh " << &ramesh << endl;
    ramesh.getHealth();

    //dynamically
    Hero *h = new Hero();
    

    // //static memory allocation
    // Hero a;
    // a.setHealth(90);
    // a.setLevel('B');
    // cout << "level is: " << a.level << endl;
    // cout << "health is: " << a.getHealth() << endl;

    // // dynamic memory allocation
    // Hero *h = new Hero;
    // h->setHealth(70);
    // h->setLevel('A');
    // cout << "level is "<< (*h).level << endl;
    // cout << "health is "<< (*h).getHealth() << endl;

    // cout << "level is "<< h->level << endl;
    // cout << "health is "<< h->getHealth()<<endl;


    //create Hero object
    // Hero luffy;
    // cout << "Size of luffy is: " << sizeof(luffy) << endl;
    // //Access the properties
    // luffy.health = 70;
    // luffy.level = 'A';

    // cout << "health is: " << luffy.health << endl;
    // cout << "level is: " << luffy.level << endl;

    Hero S(70, 'C');
    S.print();

    //copy constructor
    Hero R(S);
    R.print(); 

    return 0;
}