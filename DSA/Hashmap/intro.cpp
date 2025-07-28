#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;
int main(){
    //create
    unordered_map<string,int> m;

    //insertion
    pair<string,int> p = make_pair("shaurya", 2); //1
    m.insert(p);

    pair<string, int>pair2("singh", 2); //2
    m.insert(pair2);

    m["mera"] = 2; //3
    
    //Search
    cout<< m["mera"] << endl;
    cout << m.at("shaurya") << endl;

    cout << m["unknownKey"] << endl;
    cout << m.at("unknownKey") << endl;

    cout << m.size() << endl;

    cout << m.count("singh") << endl;

    m.erase("singh");
    cout << m.size() << endl;

    //iterator
    unordered_map<string, int> :: iterator it = m.begin();

    while(it != m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return 0;
}