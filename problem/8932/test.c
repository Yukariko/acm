#include <stdio.h>
#include <math.h>

const double A[7] = {9.23076,1.84523,56.0211,4.99087,0.188807,15.9803,0.11193};
const double B[7] = {26.7,75,1.5,42.5,210,3.8,254};
const double C[7] = {1.835,1.348,1.05,1.81,1.41,1.04,1.88};
const int TYPE[7] = {0,1,1,0,1,1,0};

int main()
{
	int T;
	scanf("%d",&T);
	for(;T--;)
	{
		int sum = 0;
		for(int i=0;i<7;i++)
		{
			int P;
			scanf("%d",&P);
			if(TYPE[i] == 0)
				sum += A[i] * pow(B[i] - P, C[i]);
			else
				sum += A[i] * pow(P - B[i], C[i]);
		}
		printf("%d\n",sum);
	}
	return 0;
}