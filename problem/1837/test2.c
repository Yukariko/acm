#include <stdio.h>
#include <pthread.h>

char P[101];

void *isPrime(void *arg)
{
	int n = (int)arg;
	for(int i=2;i*i<=n;i++)
		if(n % i == 0)
			return (void *)0;
	return (void *)1;
}

void *isDiv(void *arg)
{
	int n = (int)arg;
	int mod = 0;
	for(int i=0;P[i];i++)
	{
		mod *= 10;
		mod += P[i] - '0';
		mod %= n;
	}
	return (void *)!mod;
}

int min(int p,int q){return p>q?q:p;}

int main()
{
	int K;
	scanf("%s%d",P,&K);
	
	pthread_t thread[32][2];
	for(int i=2, batch=32;i<=K;i+=batch)
	{
		batch = min(32, K-i+1);
		for(int j=0; j < batch; j++)
		{
			pthread_create(&thread[j][0], 0, isPrime, (void *)(i+j));
			pthread_create(&thread[j][1], 0, isDiv, (void *)(i+j));
		}
		
		for(int j=0; j < batch; j++)
		{
			void *res1,*res2;
			pthread_join(thread[j][0],(void **)&res1);
			pthread_join(thread[j][1],(void **)&res2);
			if(res1 && res2)
			{
				printf("BAD %d",i+j);
				return 0;
			}
		}
	}
	puts("GOOD");
	return 0;
}
