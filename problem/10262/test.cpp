#include <iostream>
#include <algorithm>

using namespace std;

int nSum(int N)
{
	return N * (N-1) / 2;
}

int main()
{
	int A1,B1,A2,B2;
	cin >> A1 >> B1 >> A2 >> B2;

	double p = (double)(nSum(B1) - nSum(A1-1)) / (B1-A1+1) +
						(double)(nSum(B2) - nSum(A2-1)) / (B2-A2+1);

	cin >> A1 >> B1 >> A2 >> B2;

	double q = (double)(nSum(B1) - nSum(A1-1)) / (B1-A1+1) +
						(double)(nSum(B2) - nSum(A2-1)) / (B2-A2+1);

	if(p > q)
		cout << "Gunnar";
	else if(p < q)
		cout << "Emma";
	else
		cout << "Tie";
	return 0;
}