/*
 * Name: Alexander Van Maren
 * WSUID: J527E389
 * HW 01
 * Description: Finds the max number of primes for if abs(a) and abs(b) < 1000 for n^2 + an + b
 */

#include <iostream>
#include <cmath>
#include <vector>

using std::cout;
using std::endl;

// Gives true if a number is prime
bool isPrime(int n);
// Counts the number of primes for n^2 + na + b, up until for n:[0,limit]
// When print is true, all primes and combinations will be printed
int countPrimes(int a, int b, int limit, bool print);
// Finds and prints all primes from 0 to the limit for the formula: n^2 + na + b
//void printQuadraticPrimes(int a, int b, int limit);

int main()
{
	int temp = countPrimes(1, 41, 40, true);
	cout << temp << " primes" << endl << endl;
	temp = countPrimes(-79, 1601, 79, true);
	cout << temp << " primes" << endl << endl;

	int n = 0;
	int currentPrimes = 0;
	int maxPrimes = 0;
	int bestA = 0;
	int bestB = 0;

	// Finds a and b [-1000, 1000] such that n^2 + na + b produces the most primes
	for (int a = -999; a <= 999; a++)
	{
		//cout << a;
		for (int b = -1000; b <= 1000; b++)
		{
			if (isPrime(b))
			{
				n = 0;
				currentPrimes = 0;
				//cout << b;
	
				while (isPrime((n*n) + (n*a) + b))
				{
					n++;
					currentPrimes++;
				}
	
				// No more primes found, so see if found most
				if (currentPrimes > maxPrimes)
				{
					//cout << "New pair";
					maxPrimes = currentPrimes;
					bestA = a;
					bestB = b;
				}
			}
		}
	}

	cout << "Most primes found for a = " << bestA << " b = " << bestB << ": " << maxPrimes << " primes found." << endl;

	cout << "The primes for these 2 numbers are: " << endl;
	countPrimes(bestA, bestB, 72, true);


	//temp = countPrimes(bestA, bestB, 1019, true);
	//int arr[15];

	//for (int i = 0; i < 15; i++)
	//{
	//	arr[i] = i;
	//}
//
//	for (int i = 0; i < 15; i++)
//	{
//		cout << arr[i] << ": " << isPrime(arr[i]) << endl;
//	}

	return 0;
}

bool isPrime(int n)
{
	if (n < 1)
	{
		return false;
	}

	for (int i = 2; i < (sqrt(n) + 1); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int countPrimes(int a, int b, int limit, bool print = false)
{
	int count = 0;
	
	if (print)
	{
		cout << "For a = " << a << " and b = " << b << endl
			<< "count\tn\tprime" << endl;
	}

	for (int n = 0; n <= limit; n++)
	{
		int result = ((n*n) + (a*n) + b);
		if (isPrime(result))
		{
			count++;
			if (print)
			{
				cout << count << '\t'  <<  n << '\t' << result << endl;
			}
		}
	}
	
	return count;
}
