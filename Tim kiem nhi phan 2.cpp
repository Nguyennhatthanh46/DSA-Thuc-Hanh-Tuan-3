#include <bits/stdc++.h>
using namespace std;

int BS1(const vector<pair<int, int>> &b, int n, int x)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (b[m].first == x)
		{
			if (m == 0 || b[m - 1].first < x)
				return b[m].second;
			else
				r = m - 1;
		}
		else if (x < b[m].first)
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}

int BS2(const vector<pair<int, int>> &b, int n, int x)
{
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (b[m].first == x)
		{
			if (m == n - 1 || b[m + 1].first > x)
				return b[m].second;
			else
				l = m + 1;
		}
		else if (x < b[m].first)
			r = m - 1;
		else
			l = m + 1;
	}
	return -1;
}

void Merge(vector<pair<int, int>>& v, int l, int m, int r)
{
	vector<pair<int, int>> a(v.begin() + l, v.begin() + m + 1);
	vector<pair<int, int>> b(v.begin() + m + 1, v.begin() + r + 1);
	int i = 0, j = 0;
	while (i < a.size() && j < b.size())
	{
		if (a[i].first <= b[j].first)
		{
			v[l].first = a[i].first;
			v[l].second = a[i].second;
			++i;
			++l;
		}
		else
		{
			v[l].first = b[j].first;
			v[l].second = b[j].second;
			++j;
			++l;
		}
	}

	while (i < a.size())
	{
		v[l].first = a[i].first;
		v[l].second = a[i].second;
		++i;
		++l;
	}
	while (j < b.size())
	{
		v[l].first = b[j].first;
		v[l].second = b[j].second;
		++j;
		++l;
	}
}

void MergeSort(vector<pair<int, int>>& v, int l, int r)
{
	if (l >= r)
		return;
	int m = (l + r) / 2;
	MergeSort(v, l, m);
	MergeSort(v, m + 1, r);
	Merge(v, l, m, r);
}


int main() {
    int n,q;
    vector<pair<int,int>> b;
    cin >> n;
    cin>>q;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b.push_back({a[i],i+1});
    }
MergeSort(b,0,n-1);
cin.ignore();
while (q--)
	{
		string tmp;
        getline(cin, tmp);
        stringstream ss(tmp);
        string cmd;
        int type, value;
        ss >> cmd >> type >> value;

        if (type == 1)
            cout << BS1(b, n, value) << '\n';
        else if (type == 2)
            cout << BS2(b, n, value) << '\n';
    }
}
