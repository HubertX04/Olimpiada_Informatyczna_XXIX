#include <bits/stdc++.h>
using namespace std;
 
	long long n,tab[100005]={},pewne[100005]={}, iloscw[100005]={},uzyteliczby[100005]={},sprawdzone[100005]={};
	long long dowolne=0,silniadowolne=1,wynik=1,pozycjadowolnych,zliczaniedowolnych,pozycjai;
	long long wystapienie=0,iloscczapek=0;
	long long poz1=-1,poz2=-1;
 
struct graf{
	vector <long long> pol;
}*w;
 
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
 
	cin>>n;
	w = new graf[n+1];
	
	for(int i=0; i<n; i++)
	{
		cin>>tab[i];
		iloscw[tab[i]]++;
		pewne[i]=0;
		sprawdzone[i]=0;
		if(iloscw[tab[i]]>=3)
		{
			wystapienie=1;
		}
	}
 
	for(int i=0; i<n; i++) pewne[i]=0;

	if(wystapienie==0)
	{
		for(int i=0; i<=n-2; i++)
		{
			if(iloscw[tab[i]]==2)
			{
				if(tab[i]==tab[i+2])
				{
					if(sprawdzone[tab[i]]==0)
					{
					sprawdzone[tab[i]]=1;
					dowolne++;
					}
				}
				else if(tab[i]!=tab[i+2] && sprawdzone[tab[i]]==0)
				{
					iloscczapek=1;
					break;
				}
			}
 
		}

		if(iloscczapek==1) cout<<"0";
 
 
		else
		{

			pewne[1]=tab[0];
			uzyteliczby[tab[0]]=1;
			pewne[n-2]=tab[n-1];
			uzyteliczby[tab[n-1]]=1;
 
			for(int i=0; i<n-2; i++)
			{
				if(tab[i]==tab[i+2])
				{
					pewne[i+1]=tab[i];
					uzyteliczby[tab[i]]=1;
				}
			}
 
			for(int i=0; i<n-2; i++)
			{
				if(uzyteliczby[tab[i+1]]==0 && pewne[i]!=0 && pewne[i+2]==0)
				{
					pewne[i+2]=tab[i+1];
					uzyteliczby[tab[i+1]]=1;
				}
				if(uzyteliczby[tab[i+1]]==0 && pewne[i]==0 && pewne[i+2]!=0)
				{
					pewne[i]=tab[i+1];
					uzyteliczby[tab[i+1]]=1;
				}
			}
 
			for(int i=n-3; i>=0; i--)
			{
				if(uzyteliczby[tab[i+1]]==0 && pewne[i]!=0 && pewne[i+2]==0)
				{
					pewne[i+2]=tab[i+1];
					uzyteliczby[tab[i+1]]=1;
				}
				if(uzyteliczby[tab[i+1]]==0 && pewne[i]==0 && pewne[i+2]!=0)
				{
					pewne[i]=tab[i+1];
					uzyteliczby[tab[i+1]]=1;
				}
			}
 
			int sprzecznyprzypadek=0;
			for(int i=1; i<n-1; i++)
			{
				if(uzyteliczby[tab[i]]==0)
				{
					if(pewne[i-1]>0 && pewne[i+1]>0)
					{
						sprzecznyprzypadek=1;
						break;
					}
				}
			}
			if(sprzecznyprzypadek==0)
			{

			for(int i=1; i<=dowolne;i++)
			{
				silniadowolne=(silniadowolne*i)%1000000007;
			}

			if(uzyteliczby[tab[1]]==0) w[0].pol.push_back(tab[1]);
			if(uzyteliczby[tab[n-2]]==0) w[n-1].pol.push_back(tab[n-2]);
 
			for(int i=1; i<=n-2; i++)
			{
				if(pewne[i]==0)
				{
					if(uzyteliczby[tab[i-1]]==0)
					{
						w[i].pol.push_back(tab[i-1]);
					}
					if(uzyteliczby[tab[i+1]]==0)
					{
						w[i].pol.push_back(tab[i+1]);
					}
				}
			}

			pozycjadowolnych=0;
			pozycjai=0;
			zliczaniedowolnych=1;
			for(int i=0; i<n; i++)
			{
				if(pewne[i]==0)
				{
						if(w[i].pol.size()==1)
						{
 
							if(pozycjadowolnych==w[i].pol[0])
							{
								while(!w[i].pol.empty()) w[i].pol.pop_back();
								if(zliczaniedowolnych!=0) wynik=(wynik*zliczaniedowolnych)%1000000007;
 
								zliczaniedowolnych=1;
								i=pozycjai;
								pozycjadowolnych=0;
							}
							else if(pozycjadowolnych==0)
							{
								zliczaniedowolnych++;
								pozycjadowolnych=w[i].pol[0];
								pozycjai=i;
								while(!w[i].pol.empty()) w[i].pol.pop_back();
							}
 
						}
 
						if(w[i].pol.size()==2)
						{
							if(w[i].pol[0]==pozycjadowolnych)
							{
								zliczaniedowolnych++;
								pozycjadowolnych=w[i].pol[1];
								while(!w[i].pol.empty()) w[i].pol.pop_back();
							}
							else if(w[i].pol[1]==pozycjadowolnych)
							{
								zliczaniedowolnych++;
								pozycjadowolnych=w[i].pol[0];
								while(!w[i].pol.empty()) w[i].pol.pop_back();
							}
						}
 
				}
			}
 
			cout<<(wynik*silniadowolne)%1000000007;
		}
		else cout<<"0";
 
		}
 
	}
 
	else if(wystapienie==1)
	{
		cout<<"0";
	}
 
	return 0;
}