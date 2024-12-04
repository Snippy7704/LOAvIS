#include <time.h>
#include <iostream>
#include <queue>
using namespace std;

queue <int> Q;

int** createG(int size)
{
	int** G;
	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		G[i] = (int*)malloc(size * sizeof(int));
	}
	for (int i = 0; i < size; i++)
	{
		G[i][i] = 0;
		for (int j = i + 1; j < size; j++)
		{
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
		}
	}
	return G;
};

void printG(int** G, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
};
void bfs(int** G, int size, int s, int* vis)
{
	Q.push(s);
	vis[s] = 1;
	cout << s;
	while (!Q.empty())
	{
		s = Q.front();
		Q.pop();
		for (int i = 0; i < size; i++)
		{
			if (G[s][i] == 1 && vis[i] == 0)
			{
				Q.push(i);
				vis[i] = 1;
				cout << " -> " << i;
			}
		}
	}
};



int main()
{
	srand(time(NULL));
	int** G = NULL;
	int nG = 0, s;
	cout << "Vvedite razmer grafa: ";
	cin >> nG;
	cout << endl;

	G = createG(nG);
	printG(G, nG);

	cout << "\nVvedite startovuy vershinu: ";
	cin >> s;

	int* vis = (int*)malloc(nG * sizeof(int));
	for (int i = 0; i < nG; i++)
	{
		vis[i] = 0;
	}
	bfs(G, nG, s, vis);
	return 0;
}