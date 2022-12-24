//
// Created by pi on 12/24/22.
//

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

// decimal
vector<int> alg1( const vector<int>& u, const vector<int>& v, int b = 10 ){
    vector<int> w(u.size(), 0);
    int k = 0;
    for (size_t j = u.size()-1; j > 0; --j){
        k = (u[j]+v[j]+k)/b;
        w[j] = (u[j] + v[j] + k) % b;
    }
    w[0] = k;
    return w;
}

vector<int> alg2( const vector<int>& u, const vector<int>& v, int b = 10 ){
    vector<int> w(u.size(), 0);
    int k = 0;
    for (size_t j = u.size()-1; j > 0; --j){
        k = (u[j]-v[j]+k)/b;
        w[j] = (u[j] - v[j] + k) % b;
    }
    w[0] = k;
    return w;
}

vector<int> alg3( const vector<int>& u, const vector<int>& v, int b = 10 ){
    vector<int> w(u.size(), 0);
    int k = 0;
    for (size_t j = u.size()-1; j > 0; --j){
        k = (u[j]-v[j]+k)/b;
        w[j] = (u[j] - v[j] + k) % b;
    }
    w[0] = k;
    return w;
}

vector<int> alg4( const vector<int>& u, const vector<int>& v, int b = 10 ){
    vector<int> w(u.size());
    int k = 0;
    for (size_t j = u.size()-1; j > 0; --j){
        k = (u[j]-v[j]+k)/b;
        w[j] = (u[j] - v[j] + k) % b;
    }
    w[0] = k;
    return w;
}

vector<int> alg5( const vector<int>& u, const vector<int>& v, int b = 10 ){
    vector<int> w(u.size());
    int k = 0;
    for (size_t j = u.size()-1; j > 0; --j){
        k = (u[j]-v[j]+k)/b;
        w[j] = (u[j] - v[j] + k) % b;
    }
    w[0] = k;
    return w;
}

void print(const vector<int>& v){
    for (int i : v){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    vector<int> v{1, 2, 3, 4};
    vector<int> u{3, 4, 5, 6};

    auto w = alg1(u, v);
    print(w);

    w = alg2(u, v);
    print(w);


}