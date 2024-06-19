#include <bits/stdc++.h>
using namespace std;

	vector < pair < pair < long long , long long > , long long > > montaz;
	vector < pair < pair < long long , long long > , long long > > odpowiedzi;
	vector <long long> czasy;
	
	multiset < pair < pair < long long , long long > , long long > > glowny;
	multiset < pair < pair < long long , long long > , long long > > ::iterator it;
	
	pair < pair < long long , long long > , long long >  pom;
	
	long long n,a,b;
	long long dlciagu=0,pomdlugosc=0,pomciag=0,ipom,czas=1;

void odp()
{
	for(it=glowny.begin(); it!=glowny.end(); it++)
	{
		pom=*it;
		odpowiedzi.push_back(make_pair(make_pair(pom.second, pom.first.first),pom.first.second));
	}	
	sort(odpowiedzi.begin(), odpowiedzi.end());
}


void szukanie()
{
	if(glowny.size()>0)
	{
		dlciagu-=pom.first.first;
		glowny.erase(it);
	}
						
	glowny.insert(make_pair(make_pair(montaz[ipom].first.second,montaz[ipom].second),montaz[ipom].first.first));
	dlciagu+=montaz[ipom].first.second;
}

void dodawanie()
{
	glowny.insert(make_pair(make_pair(montaz[ipom].first.second,montaz[ipom].second),montaz[ipom].first.first));
	dlciagu+=montaz[ipom].first.second;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>a>>b;
		if(a<=b) montaz.push_back(make_pair(make_pair(b,a),i+1));
	}
 
	sort(montaz.begin(), montaz.end());
 
	for(int i=0; i<montaz.size(); i++)
	{
			if(montaz[i].first.first>=montaz[i].first.second+dlciagu)
			{
				ipom=i;
				dodawanie();
			}
 
			else
			{
				if(montaz[i].first.first<=montaz[i].first.second+dlciagu)
				{		
					it=glowny.end();
					it--;
					pom=*it;
					ipom=i;
					if(montaz[i].first.second<pom.first.first) szukanie();
				}
			}
	}
	
	cout<<glowny.size()<<endl;
	odp();
	for(int i=0; i<glowny.size(); i++)
	{
		cout<<odpowiedzi[i].second<<" "<<czas<<endl;
		czas+=odpowiedzi[i].first.second;
	}
	return 0;
}