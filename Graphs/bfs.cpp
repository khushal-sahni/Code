#include <bits/stdc++.h>

using namespace std;

bool *marked;			// pointer to array of marked and unmarked vertices
int *edgeTo;			// pointer to array of edgeTo 
queue < int >q;			// queue to hold vertices
list < int >*adj;		// adjacency lists

void addEdge (int u, int v);


int
main ()
{
  int V = 4;

  adj = new list < int >[V];
  edgeTo = new int[V];
  marked = new bool[V];

  for (int i = 0; i < V; i++)
    {
      edgeTo[i] = i;
    }

  addEdge (0, 1);
  addEdge (0, 2);
  addEdge (2, 1);
  addEdge (0, 2);
  addEdge (3, 1);
  addEdge (3, 3);

  q.push (2);
  marked[2] = true;


  while (!q.empty ())
    {
      int v = q.front ();
      q.pop ();
      cout << v << " ";

      list < int >::iterator i;
      for (i = adj[v].begin (); i != adj[v].end (); i++)
	{
	  if (!marked[*i])
	    {
	      q.push (*i);
	      marked[*i] = true;
	      edgeTo[*i] = v;
	    }
	}
    }

}

void
addEdge (int u, int v)
{
  adj[u].push_back (v);
  adj[v].push_back (u);
}
