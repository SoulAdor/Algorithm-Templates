#include <bits/stdc++.h>
using namespace std;

long long d = 26; 			// Alphabet size
long long mod = 1e9 + 7;	// Modulo prime

// Powers stored here for fast computation.
vector <long long> pows_d;

void InitPowers (int size, int d)
{
	pows_d.resize(size);
	pows_d[0] = 1;
	for (int i = 1; i < size; i++) pows_d[i] = pows_d[i - 1] * d % mod;
}

long long ToInt (char c)
{
	return c - 'a' + 1;
}

// We compare two strings by comparing their hash values.
// Each character is numbered from 1 and multiplied by d^i, where i is position
// We take d more than alphabet size and take moduluo prime to keep numbers small
// Updating funciton is O(1), can concatenate two strings with hashes and so on
// We can check if values are the same in O(length) if we want to compare strings