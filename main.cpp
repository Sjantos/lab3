// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "Slav.h"

#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)

using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);
void menorwomen(Slav *, int n);

int main(int argc, char const *argv[])
{
	int n = 2 * atoi(argv[1]);
	Slav *slavs = new Slav[n];
	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
		cout << slavs[i].description() << endl;

	containers(slavs, n);
	adapters(slavs, n);
	menorwomen(slavs, n);

	delete [] slavs;
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs, tmpvector;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;
	
	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");

	// Umieść Słowian w losowej kolejności w wektorze.
	for(int i=0; i<n; i++)
	{
		tmpvector.push_back(&slavs[i]);
	}
	for(int i=0; i<n; i++)
	{
		int r=rand()%(tmpvector.size());
		vectorOfSlavs.push_back(tmpvector[r]);
		tmpvector.erase(tmpvector.begin()+r);
	}
	// Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze
	for(vector<Slav *>::iterator it=vectorOfSlavs.begin(); it!=vectorOfSlavs.end(); it++)
	{
		cout<<(*it)->description();
	}
	cout<<endl;

	REPORT_CONTAINERS;
	printf("## set\n");

	// Przenieś wszystkich Słowian z wektoru do zbioru.
	for(int i=0; i<n; i++)
	{
		setOfSlavs.insert(vectorOfSlavs[i]);
	}
	vectorOfSlavs.clear();
	for(set<Slav *>::iterator it=setOfSlavs.begin(); it!=setOfSlavs.end(); it++)
	{
		cout<<(*it)->description()<<"  ";
	}
	cout<<endl;

	REPORT_CONTAINERS;
	printf("## map\n");

	// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór
	for(set<Slav *>::iterator it=setOfSlavs.begin(); it!=setOfSlavs.end(); it++)
	{
		mapOfSlavs[*it]=*(++it);
	}
	setOfSlavs.clear();
	// Wykorzystując iterator, wyświetl wszystkie pary Słowian
	for(map<Slav *, Slav *>::iterator it=mapOfSlavs.begin(); it!=mapOfSlavs.end(); it++)
	{
		cout<<it->first->description()<<"  =>  "<<it->second->description()<<endl;
	}
	cout<<endl;
	
	REPORT_CONTAINERS;
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

	// Umieść Słowian w kolejce.
	for(int i=0; i<n; i++)
	{
		queueOfSlavs.push(&slavs[i]);
	}
	
	REPORT_ADAPTERS;

	printf("## stack\n");
	// Przenieś Słowian z kolejki do stosu.
	for(int i=0; i<n; i++)
	{
		stackOfSlavs.push(queueOfSlavs.front());
		queueOfSlavs.pop();
	}

	REPORT_ADAPTERS;

	// Wyświetl Słowian zdejmowanych ze stosu.
	for(int i=0; i<n; i++)
	{
		cout<<stackOfSlavs.top()->description();
		stackOfSlavs.pop();
	}
	cout<<endl;

	REPORT_ADAPTERS;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %lu, set_size = %lu, map_size = %lu, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %lu, stack_size = %lu, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}
void menorwomen(Slav * slavs, int n)
{
		map <int, vector <Slav *> > mymap;
		vector <Slav *> womenvector, menvector;
		mymap[0]=womenvector;
		mymap[1]=menvector;
		for(int i=0; i<n; i++)
		{
			if(slavs[i].menwomen()) menvector.push_back(&slavs[i]);
			else womenvector.push_back(&slavs[i]);
		}
		cout<<"Men pointers: "<<endl;
		for(vector<Slav *>::iterator it=menvector.begin(); it<menvector.end(); it++)
		{
			cout<<*it<<"  ";
		}
		cout<<endl<<"Women pointers: "<<endl;
		for(vector<Slav *>::iterator it=womenvector.begin(); it<womenvector.end(); it++)
		{
			cout<<*it<<"  ";
		}
}