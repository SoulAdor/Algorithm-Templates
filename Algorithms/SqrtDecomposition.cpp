#include <bits/stdc++.h>
using namespace std;
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, q;
vector <long long> arr;
vector <long long> sqrt_decompositon;
int chunk_size;
long long answer;

void In()
{
	cin >> n;
	arr.resize(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> q;
}

int GetSQRTIndex (int i)
{
	return i / chunk_size;
}

void SqrtDecompose (vector <long long>& arr)
{
	chunk_size = ceil(sqrt(n));
	for (int i = 0; i < arr.size(); i += chunk_size)
	{
		long long value = 0;
		for (int j = i; j < arr.size() && j < i + chunk_size; j++)
			value += arr[j];
		sqrt_decompositon.push_back(value);
	}
}

long long GetValue (int L, int R)
{
	long long result = 0;
	for(; L <= R && L % chunk_size != 0; L++) result += arr[L];
	for(; L + chunk_size <= R; L += chunk_size) result += sqrt_decompositon[GetSQRTIndex(L)];
	for(; L <= R; L++) result += arr[L];
	return result;
}

long long GetSum()
{
	int L, R;
	cin >> L >> R;
	L--;R--;
	return GetValue (L, R);
}

void UpdateValue()
{
	long long L, R, V;
	cin >> L >> R >> V;
	L--;R--;
	for (; L <= R; L++) 
	{
		arr[L] += V;
		sqrt_decompositon[GetSQRTIndex(L)] += V;
	}
}

int main()
{__
	In();
	SqrtDecompose(arr);
	int type;
	while (q--)
	{
		cin >> type;
		if (type == 1) cout << GetSum () << endl;
		else UpdateValue();
	}
}