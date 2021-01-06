#include <cstdio>
#include <set>
#include <stack>
using namespace std;

const int N = 10001;

set< int > adj[N];
stack< int > st;

void insert_edge(int v, int w)
{
	adj[v].insert(w);
	adj[w].insert(v);
}

void remove_edge(int v, int w)
{
	adj[v].erase(w);
	adj[w].erase(v);
}

int traverse(int v)
{
	for (set< int >::iterator it; (it = adj[v].begin()) != adj[v].end(); v = *it)
	{
		st.push(v);
		remove_edge(v, *it);
	}
	return v;
}

void print_euler(int v)
{
	st.push(v = traverse(v));
	while (!st.empty())
	{
		printf("%d ", v = st.top()); st.pop();
		traverse(v);
	}
}

int find_odd_degree()
{
	for (int v = 0; v < N; ++v)
		if (adj[v].size() & 0x01)
			return v;
	return -1;
}

int main()
{
	for (int v, w; 1 < scanf("%d%d", &v, &w); insert_edge(v, w));
	print_euler(find_odd_degree());

	return 0;
}