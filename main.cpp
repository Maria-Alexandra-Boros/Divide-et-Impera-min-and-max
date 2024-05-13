/*Scrieti o functie minmax care sa determine elementul minim si elementul maxim dintr-un tablou cu elemente intregi folosind metoda divide et impera.*/
///scrieti o functie care se cheama min max care determina nr min si nr max dintr un tablou folosind d&i
#include <fstream>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int A[1001],n,i;
int mini,maxi;
void citire()
{
	f>>n;
	for(int i=1;i<=n;i++)
		f>>A[i];
}
 void minmaxi(int &mini, int &maxi, int s, int d)
{
	if(s==d)
        mini=maxi=A[s];
	else
	{
		int ms,Ms,md,Md;
		minmaxi(ms,Ms,s,(s+d)/2);
		minmaxi(md,Md,(s+d)/2+1,d);
        if(ms<md)
			mini=ms;
		else
			mini=md;
		if(Ms>Md)
			maxi=Ms;
		else
			maxi=Md;
	}
}

int main()
{
	citire();
	minmaxi(mini,maxi,1,n);
	g<<mini<<" "<<maxi;
	f.close();
	g.close();
    return 0;
}
