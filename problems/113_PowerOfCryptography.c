#include <stdio.h>
#include <math.h>

int main(int argc, char* argv){
	double p,n;
	while(scanf("%lf\n%lf\n",&n,&p) != EOF){
		printf("%0.lf\n",(pow(p,(1/(double)n))));
	}
	return 0;
}