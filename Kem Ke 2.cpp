#include <bits/stdc++.h>
using namespace std;

bool Compare(const string &a, const string &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

void Merge(vector<string> &a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<string> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int i = 0; i < n2; i++) R[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (Compare(L[i], R[j])) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void MergeSort(vector<string> &a, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    Merge(a, left, mid, right);
}

bool ComparePair(const pair<string, int> &a, const pair<string, int> &b) {
    if (a.second != b.second) return a.second > b.second;
    return Compare(a.first, b.first);
}

void Merge(vector<pair<string, int>> &a, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<pair<string, int>> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int i = 0; i < n2; i++) R[i] = a[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (ComparePair(L[i], R[j])) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void MergeSort(vector<pair<string, int>> &a, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    Merge(a, left, mid, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    MergeSort(a, 0, n - 1);
    vector<pair<string, int>> v;
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            v.push_back({a[i - 1], count});
            count = 1;
        } else {
            count++;
        }
    }
    v.push_back({a[n - 1], count});
    MergeSort(v, 0, v.size() - 1);
    for (const auto &p : v) {
        cout << p.first << ' ' << p.second << '\n';
    }
}
