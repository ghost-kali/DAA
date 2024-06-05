#include<iostream.h>
#include<conio.h>
#include<math.h>
class queen
{
	public:
		int n,k,t,x[50];
		void get();
		void nqueens(int,int);
		int place(int,int);
};
void queen::get()
{
	cout<<"\n\t\tNQUEENS PROBLEM.";
	cout<<"\nEnter the no of queens :";
	cin>>n;
	nqueens(1,n);
}
void queen::nqueens(int k,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			x[k]=i;
			if(k==n)
			{
				cout<<"\n\nThe solution is\n";
				for(int j=1;j<=n;j++)
				{
					cout<<"\n";
					cout<<"\n Queen "<<j<<"\t"<<x[j];
				}
			}
		            else
			{
				nqueens(k+1,n);
			}
                 }
	}
}
int queen::place(int k,int i)
{
	for(int j=1;j<k;j++)
	{
		 if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
		{
			return 0;
		}
	}
return 1;
}
void main()
{
	int n;
	clrscr();
	queen q;
	q.get();
	getch();
}
