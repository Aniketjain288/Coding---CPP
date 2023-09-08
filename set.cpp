#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;
    s.insert(5);
    s.insert(3);
    s.insert(1);
    s.insert(2);
    s.insert(2);
    for( auto i : s){
        cout<<i<<" ";
    }
    cout<<endl;
    s.erase(1);
    cout<<*s.lower_bound(3)<<endl;
    cout<<*s.lower_bound(4)<<endl;
    cout<<*s.upper_bound(2)<<endl;
    for( auto i : s){
        cout<<i<<" ";
    }
    cout<<endl;
    multiset<int> t;
    t.insert(5);
    t.insert(3);
    t.insert(1);
    t.insert(2);
    t.insert(2);
    for( auto i : t){
        cout<<i<<" ";
    }
    cout<<endl;
    t.erase(t.find(2));
    for( auto i : t){
        cout<<i<<" ";
    }
    cout<<endl;
    unordered_set<int> a;
    a.insert(5);
    a.insert(3);
    a.insert(1);
    a.insert(2);
    a.insert(2);
    for( auto i : a){
        cout<<i<<" ";
    }
    cout<<endl;
    a.erase(1);
    a.erase(a.begin());
    for( auto i : a){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}