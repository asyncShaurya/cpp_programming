#include<iostream>
#include<queue>

using namespace std;

int main(){

    queue<int> s;
    s.push(11);
    s.push(15);
    s.push(20);

    cout << "The size of the queue is " << s.size() << endl;

    cout << "The front of the queue is " << s.front() << endl;

    cout << " The rear of the queue is " << s.back() << endl;
    
    s.pop();
   
     cout << "The size of the queue is " << s.size() << endl;

    if(s.empty()){
        cout << "The queue is empty " << endl;
    }else{
        cout << "The queue is not empty " << endl;
    }

    cout << "The front of the queue is " << s.front() << endl;

    return 0;
}