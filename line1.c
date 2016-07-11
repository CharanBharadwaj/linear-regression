#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{

	char * commands[]={"set title \"TITLEEEE\"","plot 'data.temp' "};
	FILE *temp=fopen("data.temp","w");
	FILE *gnuplotPipe=popen ("gnuplot -persistent", "w");

	int n,x[100],y[100],i,j;
	float xmean=0,ymean=0,slope,yinter,a,b,numer=0,den=0,e=0,yline;
	printf("Enter the no of points\n");
	scanf("%d",&n);
	printf("Enter the points\n");
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	printf("Points are\n");
	printf("Point number\tX-ordinate\tY-ordinate\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\n",i,x[i],y[i]);
	}
	
	for(i=0;i<n;i++)
	{
		fprintf(temp, "%d %d \n",x[i],y[i]);
	}

	for(i=0;i<n;i++)
	{
		xmean=xmean+x[i];
		ymean=ymean+y[i];
	}

	xmean=xmean/n;
	ymean=ymean/n;

	for(i=0;i<n;i++)
	{
		a=x[i]-xmean;
		b=y[i]-ymean;
		numer=numer+(a*b);
		den=den+(a*a);
	}

	slope=numer/den;

	yinter=ymean-(slope*xmean);

	printf("Slope=%.3f\nY-Intercept=%.3f\n",slope,yinter);

	for(i=0;i<n;i++)
	{
		yline=(slope*x[i])+yinter;
		e=e+((y[i]-yline)*(y[i]-yline));
	}
	e=e/n;
	printf("Squared error=%.3f\n\n",e);
	
	printf("Equation of the line is: Y=%.3fx+%.3f+%.3f\n",slope,yinter,e);

	for(i=0;i<2;i++)
	{
		fprintf(gnuplotPipe, "%s \n", commands[i]);
	}
	
        return 0;
}

