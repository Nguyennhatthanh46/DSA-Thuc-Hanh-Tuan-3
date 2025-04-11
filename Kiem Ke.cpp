#include <bits/stdc++.h>
using namespace std;

void Merge(vector<unsigned long long> &a, int l, int m, int r) {
    vector<unsigned long long> x(a.begin() + l, a.begin() + m + 1);
    vector<unsigned long long> y(a.begin() + m + 1, a.begin() + r + 1);
int i = 0, j = 0;
while(i<x.size()&&j<y.size()){
    if(x[i]<=y[j]){
        a[l] = x[i];
        ++l;
        ++i;
    }else{
    a[l] = y[j];
    ++l;
    ++j;
    }
}
while(i<x.size()){
    a[l] = x[i];
    ++l;
    ++i;
}
while(j<y.size()){
    a[l] = y[j];
    ++l;
    ++j;
}
}

void MergeSort(vector<unsigned long long> &a,int l, int r){
if(l>=r) return;
int m = (l+r)/2;
 MergeSort(a,l,m);
 MergeSort(a,m+1,r);
 Merge(a,l,m,r);
}



unsigned long long H(const string &s) {
    unsigned long long res = 0;
    for (char c : s)
        res = res * 131ULL + (unsigned long long)c;
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<unsigned long long> a;
    string s;

    for (int i = 0; i < n; ++i) {
        cin >> s;
        a.push_back(H(s));
    }

    MergeSort(a,0,a.size()-1);


    int dem = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            dem++;
        }
    }

    cout << dem << '\n';
    return 0;
}
