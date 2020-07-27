#include<bits/stdc++.h>
using namespace std;
#define  inf 2e18
#define ll long long int


bool isPrime[1000000];
void sieve()
{
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = 0;
	isPrime[1] = 0;
	for (int i = 2; i * i <= 1000000; ++i) {
		if (isPrime[i] == 1) {
			for (int j = i * i; j <= 1000000 ; j += i)
				isPrime[j] = 0;
		}
	}
}

int segmented_sieve(long long int  a, long long int b)
{
	sieve();
	bool pp[b - a + 1]; // boolean array of size b-a+1
	memset(pp, 1, sizeof(pp));
	for (long long int i = 2; i * i <= b; i++)
	{
		for (long long int j = a; j <= b; j++)
		{
			if (isPrime[i])  // if i is a prime number then mark all its multiple betwn a to b non prime
			{
				if (j == i)
					continue;
				if (j % i == 0)
					pp[j - a] = 0; // since a is at 0th index b is at b-a index
			}
		}
	}
	int res = 1;
	for (long long  int i = a; i < b; i++)
		res += pp[i - a]; // count the number of primes between a and b
	return res;
}

int main() {
	long long int a, b;
	cin >> a >> b;
	cout << "The no.of Primes Numbers Between a and b :" << segmented_sieve(a, b) << endl;
	return 0;
}