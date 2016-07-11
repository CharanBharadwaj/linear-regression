#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void linreg(int n)
{
	int i,x[100],y[100];
	float Xmean=0,Ymean=0,Yinter,e=0,yline,Yplot[100],a=0,b=0;
	float Numsum=0,Densum=0,slope=0;

	FILE *file;
	FILE *pipe = popen("gnuplot -persist", "w");
	file=fopen("points","w");


	printf("Enter the points:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter Point %d's X and Y co-ordinates:\n",i+1);
		scanf("%d%d",&x[i],&y[i]);
	}
	for (i=0; i < n; i++)
	{
		fprintf(file,"%d %d \n",x[i],y[i]);
	}
	fclose(file);

	for(i=0;i<n;i++)
	{
		Xmean=Xmean+x[i];
		Ymean=Ymean+y[i];
	}
	Xmean=Xmean/n;
	Ymean=Ymean/n;

	for(i=0;i<n;i++)
	{
		a=x[i]-Xmean;
		b=y[i]-Ymean;
		Numsum=Numsum+(a*b);
		Densum=Densum+(a*a);
		//printf("%f\n",Densum);
	}
	if((int)Densum ==0)
	{
		printf("Slope is infinite\n");
	}
	else
	{
		slope=Numsum/Densum;
		Yinter=Ymean-(slope*Xmean);

		printf("Slope is:\t%.2f\nY-intercept:\t%.2f\n",slope,Yinter);

		for(i=0;i<n;i++)
		{
			yline=(slope*x[i])+Yinter;
			e=e+((y[i]-yline)*(y[i]-yline));
		}	
		e=e/n;
		printf("Squared error=%.2f\n\n",e);


		printf("Equation of the line is: Y=%.2fx+%.2f+%.2f\n",slope,Yinter,e);

		for(i=0;i<n;i++)
		{
			Yplot[i]=(slope*x[i])+Yinter;
		}

		file=fopen("data","w");

		for (i=0; i < n; i++)
		{
			fprintf(file,"%d\t%.2f \n",x[i],Yplot[i]);
		}
		fclose(file);
		fprintf(pipe,"set title \"LINEAR REGRESSION\"\n");
		fprintf(pipe,"set style data lines\n");
		fprintf(pipe,"plot 'data' with lines, 'points' with points\n");
	}
}
int main()
{
	int n;
	printf("Enter the Number of points to be input\n");
	scanf("%d",&n);
	linreg(n);
	return 0;
}
