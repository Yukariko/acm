#include <stdio.h>

#define MAX(p,q) (p>q?p:q)
#define MIN(p,q) (p>q?q:p)

int main()
{
	double A,B,C;
	double I,J,K;
	scanf("%lf%lf%lf",&A,&B,&C);
	scanf("%lf%lf%lf",&I,&J,&K);
	
	double sel = MAX(I,MAX(J,K));
	
	I /= sel;
	J /= sel;
	K /= sel;
	
	double sel2 = MIN(A/I,MIN(B/J,C/K));
	
	printf("%f %f %f",A - I * sel2, B - J * sel2, C - K * sel2);
	return 0;
}
