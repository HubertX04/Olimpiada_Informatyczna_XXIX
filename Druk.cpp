#include <bits/stdc++.h>
using namespace std;
 
long long tablica[1005][1005]={}, znaki[30]={};
long long M=1000000009, n, m, dzielniki[1005]={}, suma;
long long pozx=0, pozy=0,dlszablonu,dlznaleziono,pocz,kon,check,spr,sprr,pomi;
string hashszablonu;

vector < long long > wzory;
vector < long long > odp;

string glowny[1005]={}, tekst;
 
void szukanie(int pozx, int pozy, int dlznaleziono, int dlszablonu)
{
	if(check==0)
	{
		
	if(pozx>=m)
	{
		szukanie(0, pozy+1,dlznaleziono, dlszablonu);
	}
	
	else if(tablica[pozy][pozx]==1)
	{
		szukanie(pozx+1, pozy,dlznaleziono, dlszablonu);	
	}
	
	else if(dlznaleziono>0 && dlznaleziono!=m*n)
	{
		if(pozx+dlszablonu<=m)
		{
			spr=1;
			pocz=pozx;
			kon=pocz+dlszablonu;
			for(int i=pocz; i<kon; i++)
			{
				if(tablica[pozy][i]==1) spr=0;
			}
			
			if(spr==1)
			{
				sprr=1;
				pomi=0;
				for(int i=pocz; i<kon; i++)
				{
					if(hashszablonu[pomi]!=glowny[pozy][i]) sprr=0;
					pomi++;
				}
				
				if(sprr==1)
				{
					for(int i=pozx; i<kon; i++)
					{
						tablica[pozy][i]=1;
					}
					
					szukanie(pozx+dlszablonu, pozy,dlznaleziono+dlszablonu, dlszablonu);
					
					for(int i=pozx; i<kon; i++)
					{
						tablica[pozy][i]=0;
					}
				}
			}
		}
				
		if(pozy+dlszablonu<=n)
		{
			spr=1;
			pocz=pozy;
			kon=pocz+dlszablonu;
			for(int i=pocz; i<kon; i++)
			{
				if(tablica[i][pozx]==1) spr=0;
			}
			if(spr==1)
			{
				sprr=1;
				pomi=0;
				for(int i=pocz; i<kon; i++)
				{
					if(hashszablonu[pomi]!=glowny[i][pozx]) sprr=0;
					pomi++;
				}
				if(sprr==1)
				{
					for(int i=pozy; i<kon; i++)
					{
						tablica[i][pozx]=1;
					}
					
					szukanie(pozx+1, pozy, dlznaleziono+dlszablonu, dlszablonu);
					
					for(int i=pozy; i<kon; i++)
					{
						tablica[i][pozx]=0;
					}
				}
			}
		}
		
	}
	else
	{
		if(dlznaleziono==0)
		{
if(m>=dlszablonu)
{
			for(int i=0; i<dlszablonu; i++)
			{
				hashszablonu.push_back(glowny[0][i]);
				tablica[0][i]=1;
			}
			
			szukanie(pozx+dlszablonu, pozy,dlszablonu, dlszablonu);
			hashszablonu="";
			for(int i=0; i<1005; i++)
			for(int j=0; j<1005;j++) 
tablica[i][j]=0;
}
if(n>=dlszablonu)
{
			for(int i=0; i<dlszablonu; i++)
			{
				hashszablonu.push_back(glowny[i][0]);
				tablica[i][0]=1;
			}
			szukanie(pozx+1, pozy, dlszablonu, dlszablonu);
			for(int i=0; i<1005; i++)
			for(int j=0; j<1005;j++) tablica[i][j]=0;
}
		}
		else if(dlznaleziono==m*n && check==0)
		{
			odp.push_back(dlszablonu);
			check=1;
		}
		
	}
	}
}


int main()
{
ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	cin>>n>>m;
	for (int i=0; i<n; i++)
	{
		cin>>glowny[i];
		for (int j=0; j<glowny[i].size(); j++)
		{
			znaki[glowny[i][j]-97]++;
		}
	}
 
	for (int i=1; i<=n; i++)
		if (n%i==0) dzielniki[i]=1;
	for (int i=1; i<=m; i++)
		if (m%i==0) dzielniki[i]=1;


	for (int i=1; i<1001; i++)
	{
		int x=0;
		if(dzielniki[i]>0)
		{
 
			for(int j=0; j<26; j++)
			{
				if(znaki[j]%((n *m)/i)==0)
				{
					x++;
				}
			}
			if(x==26) wzory.push_back(i);
		}
	}
	for(int i=0; i<wzory.size(); i++)
	{
		pozx=0; pozy=0; dlznaleziono=0; dlszablonu=0, hashszablonu="",check=0;
		for(int j=0; j<1005; j++)
		{
			for(int k=0; k<1005; k++)
			{
				tablica[j][k]=0;
			}
		}
	
		dlszablonu=wzory[i];
		szukanie(pozx, pozy,dlznaleziono, dlszablonu);
	}

if(odp.size()!=0)
{
	cout<<odp.size()<<endl;
	for(int i=0; i<odp.size(); i++) cout<<odp[i]<<" ";
}
else cout<<"0";
	return 0;
}