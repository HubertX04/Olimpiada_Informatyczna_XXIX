#include <bits/stdc++.h>
using namespace std;

vector <long long> wektor;
long long m,fib[90]={},x,odp=0,wynik=INT_MAX,check=0,pom=0,pomx;

void odpowiedz()
{
	for(int i=0; i<wektor.size();i++)
		{
			odp+=wektor[i]+1;
		}
		if(odp-1<wynik) wynik=odp-1;
		check=1;
}

void licz( long long m, long long x)
{
if(x>1)
{
	if(m%fib[x]==0)
	{
		wektor.push_back(x);
		if(m/fib[x]==1) odpowiedz();
		licz(m/fib[x],x);
		if(!wektor.empty()) wektor.pop_back();
	}
	licz(m, x-1);
}
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	fib[0]=1;fib[1]=1; fib[2]=2;
	for(int i=3; i<90; i++) fib[i]=fib[i-1]+fib[i-2];
	
	cin>>m;
		odp=0; check=0; wynik=INT_MAX;
	pom=m;
	x=89;
	if(m==1) cout<<"1";
	
	else
	{
	licz(m,x);
	if(check==0) cout<<"NIE";
	else cout<<wynik;
	}
	
	cout<<endl;
	return 0;
}