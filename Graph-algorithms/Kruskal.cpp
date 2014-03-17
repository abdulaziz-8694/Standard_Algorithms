#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

class Edge{
public:

    int source;
    int target;
    int weight;
    Edge()
    {
        source=0;
        target=0;
        weight=0;
    }
    Edge(int s,int t,int w)
    {
        source=s;
        target=t;
        weight=w;
    }
};

bool sort_by_weight(const Edge &first,const Edge &second)
{
    return (first.weight<second.weight);
}
class DisjointSets{// implementing Disjoint Sets Data Structure with path compression and rank
private:
    int* Parent;//representative of elements
	int* Rank;//rank of elements
//Constructor for DisjointSets whilch will create numElements distinct sets
public:

	DisjointSets(int numElements)
	{
		Parent=new int[numElements];
		Rank=new int[numElements];
		for(int i=0;i<numElements;i++)
		{
			Parent[i]=i;
			Rank[i]=0;
		}
	}
	int Find(int i) {//Finding the representing of the set containing i

    // If i is the parent of itself
    if (Parent[i] == i) {

        // Then i is the representative of his set
        return i;
    }
    else { // Else if i is not the parent of itself

        // Then i is not the representative of his set,
        // so we recursively call Find on it's parent, and save it in our result variable
        int result = Find(Parent[i]);

        // We then cache the result by moving i's node directly under the representative of his set
        Parent[i] = result;

        // And then we return the result
        return result;
    }
}
//to take union of two sets
	void Union(int u,int v)
	{
		int repu=Find(u);
		int repv=Find(v);
		if(repu==repv)//if both are on the same set the no need to unite
			return;
		if(Rank[u]<Rank[v])//if set u is smaller in height than set v
		{
			this->Parent[repu]=repv;
		}
		else if(Rank[u]>Rank[v])//if set v is smaller in height than set u
		{
			this->Parent[repv]=repu;
		}
		else//if both are equal then we take union and increase the height
		{
			this->Parent[repu]=repv;
			Rank[repv]++;
		}
	}



};
