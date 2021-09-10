#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
const int MAXNUM_VERTICES = 1000;
typedef pair<unsigned int, int> PII;
vector<PII> adj[MAXNUM_VERTICES];

bool selected[MAXNUM_VERTICES];
unsigned int prim(int x)
{
	priority_queue<PII, vector<PII>, greater<PII> > Q;
	int y;
	unsigned int minimumCost = 0;
	PII p;
	Q.push(make_pair(0, x));
	while (!Q.empty())
	{

		// soal 3 : pilih edge dengan bobot minimum saat ini, dan masukkan ke p,
		// lalu keluarkan dari priority queue Q
		// gunakan fungsi top() dan pop() pada priority queue
		p = Q.top();
		Q.pop();

		// Ambil vertex tujuan p
		x = p.second;

		 //lewati vertex yang sudah terpilih
		 /* soal 4 : tuliskan konsidi yang benar menggunakan array 'selected' ! */
		if(selected[x] == true)
		 	continue;

		minimumCost += p.first;
		selected[x] = true;
		for (int i = 0; i < adj[x].size(); ++i)
		{
			y = adj[x][i].second;
			if(selected[y] == false)
				//soal 5 : maasukkan edge x --> y ke dalam Q.
				// gunakan fungsi push()!
				Q.push(make_pair(adj[x][i].first, y));
		}
	}
	return minimumCost;
}

unsigned int dijkstra(int s, int f)
{
    bool selected[MAXNUM_VERTICES] = {false};
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    int y, counter = 0;
    unsigned int jarak = 0;
    PII p;
    Q.push(make_pair(0, s));

    while(!Q.empty())
    {
        // soal 3
        counter++;
        p = Q.top();
        Q.pop();

        s = p.second;
        if(selected[s] == true) continue;

        jarak = p.first;
        selected[s] = true;

        cout << counter << " " << s << " " << f << endl;
        if (s == f) break;

        for (int i = 0; i < adj[s].size(); i++)
        {
            y = adj[s][i].second;
            if(selected[y] == false)
                Q.push(make_pair(adj[s][i].first + jarak, y));
        }
        
    }
    return jarak;
}

int main()
{
	int n, k, x, y;
	unsigned int weight, minimumCost;
	// soal 1 : baca niali input n san k 
	cin >> n >> k;
	for (int i = 0; i<k; ++i)
	{
		// soal 1 : baca input x, y, weight
		cin >> x >> y >> weight;
		// Memasukkan edge --> y dengan bobotnya ada adjacency list x
		adj[x].push_back(make_pair(weight, y));
		// soal 2 : Masukkan edge yang sama apda adjacency list y
		//if (undirected)
			adj[y].push_back(make_pair(weight, x));
	}
	
	cout << prim(1)<< endl;
	cout << dijkstra(4, 3) ;

}
