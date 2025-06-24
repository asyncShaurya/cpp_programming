//Print the outputs of the following codes
#include<iostream>
using namespace std;
/*
int main(){
    int a, b=1;
    a= 10;
    if(++a){
        cout<<b;
    }
    else{
        cout<< ++b;
    }
}
output: 1;
*/

/*
int main(){
    int a = 1;
    int b = 2;
    if(a-- > 0 && ++b > 2){
        cout<< "Stage1 - Inside If";
    }
    else{
        cout<< "Stage2 - Inside else";
    }
    cout<< a << " " << b << endl;
}
output: Stage1 - Inside If0 3;
*/

/*
int main(){
    int a = 1;
    int b = 4;
    if(a-- > 0 || ++b > 2){
        cout<< "Stage1 - Inside If";
    }else{
        cout<< "Stage2 - Inside else";
    }
    cout << a << " " << b  << endl;
}
output: Stage1 - Inside If0 4;
*/

/*
int main(){
    int number = 3;
    cout<<(25 * (++number));
}
output: 100;
*/
/*
int main(){
    int a = 1;
    int b = a++;
    int c = ++a;
    cout<< b << endl;
    cout<< c << endl;
}
output: 1 3;
*/