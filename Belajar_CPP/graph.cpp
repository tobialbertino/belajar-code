#include <stdio.h>
#include <stdlib.h>
#define MAXNUM_VERTICES 100
/*1
Struktur data untuk mempresentasikan sebuah graf dengan 
menggunakan adjacency_matriks.
Graph akan memiliki sebanyaj n_vertices simpul dan n_edges sisi.
Kita mengasumsikan bahwa graph akan memiliki maksimal hanya MAXIMUM_VERTICES simpul.
*/
typedef struct 
{
	int n_vertices;
	int n_edges;
	int adjacency_matriks[MAXNUM_VERTICES][MAXNUM_VERTICES];	
} Graph ;

/*
Fungsi untuk menginisialisasi adjacency_matriks graph fd cara mengisi
sub-matrix kiri atas dg ukuran n_vertices x n_vertices dati adjacency_matriks
dg nilai 0, sedangkan sisanya (yg tidak relevan untuk tujuan representasi graph
dg jumlah vertex sebanyak n_vertices) akan diisi dg nilai -1
*/
void inisialisasi_graph(Graph *g, int n_v, int n_e){
	int i,j;

	g->n_vertices = n_v;
	g->n_edges = n_e;

	for (i = 0; i < MAXNUM_VERTICES; i++)
	{
		for(j = 0; j < MAXNUM_VERTICES; j++)
		{
			if(i < n_v && j < n_v)
				//soai 1
				g->adjacency_matriks[i][j] = 0;
			else
				//soal 2
				g->adjacency_matriks[i][j] = -1;
		}
	}
}
/*!
Fungsi untuk mencetak adjacency_matriks dari sebuah graph g
*/
void print_adjacency_matriks(Graph *g)
{
	int i, j;
	for(i = 0; i < g->n_vertices; i++)
		printf("\t%d", i);
	printf("\n");

	for(i = 0; i < g->n_vertices; i++)
	{
		printf("%d", i);
		for(j = 0; j < g->n_vertices; j++)
		{
			printf("\t%d", g->adjacency_matriks[i][j] );
		}
		printf("\n");
	}
}
//-----------------------------------------------------------

int comp(const void *a, const void *b)
{
	return(*(int*)b - *(int*)a);
}
// membuat Var global yg menunjukkan keberadaan cycle dgn nilai deafult 0
int cycle = 0;

typedef enum{WHITE, GRAY, BLACK} COLOR;

#define Inf 1000000000		// Menyatakan nilai infinity / tak hingga
int finish_time[MAXNUM_VERTICES];
int time = 0;				// Waktu global
/*
prosedur yang mengimplementasikan DFS_visit.
*/
void DFS_visit(Graph *g, COLOR *vertex_colors, int v)
{
	int i;
	// tampilkan v dijadikan comment agar tdk mencatak alur DFS
	// tampilkan v
	//printf("%d time = %d \n", v, time);

	// tandai v dengan warna GRAY
	vertex_colors[v] = GRAY;
	// Increment nilai waktu SOAL 6 P9 
	time += 1;

	// cari vertex yg adjacent terhadap v, jika masih WHITE, panggil DFS_visit vertex itu
	for(i = 0; i < g->n_vertices; i++)
	{
		//soal 1 P9 : Tuliskan kondisi dimana ada vertex i adjacent terhadap v, & bukan WHITE,
		// apabila ada cycle, variabel cycle diubah menjadi = 1
		if(g->adjacency_matriks[v][i] == 1 && vertex_colors[i] != WHITE) 
		{
			cycle = 1;
			//printf("cycle \n"); break;
		}
		//soal 5: agar DFS_visit mengunjungi V(i) yg adjacent terhadap v dan masih berwarna WHITE
		if (g->adjacency_matriks[v][i] == 1 && vertex_colors[i] == WHITE)
			DFS_visit(g, vertex_colors, i);
	}

	vertex_colors[v] = BLACK;
	// Increment nilai waktu SOAL 6 P9
	// Catat waktu finish untuk vertex v
	time += 1;
	finish_time[v] = time;
}
/*
prosedur yg mengimplementasikan DFS.
*/
void DFS(Graph *g)
{
	COLOR vertex_colors[MAXNUM_VERTICES];
	int i;
	for(i = 0; i < g->n_vertices; i++)
		vertex_colors[i] = WHITE;
	for(i = 0; i < g->n_vertices; i++)
		finish_time[i] = Inf;

	for(i = 0; i < g->n_vertices; i++)
	{
		if(vertex_colors[i] == WHITE)
			DFS_visit(g, vertex_colors, i);
	}

	printf("\n");
}

int main() 
{
	int n_v = 0;
	int n_e = 0;
	int i,j;
	scanf("%d %d", &n_v, &n_e);

	Graph g;
	inisialisasi_graph(&g, n_v, n_e);

	for(i = 0; i < n_e; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		//soal 3
		g.adjacency_matriks[a][b] = 1; //directed graph
		//g.adjacency_matriks[a][b] = g.adjacency_matriks[b][a] = 1;  //undirected Graph
	}
	

	//print_adjacency_matriks(&g);
	DFS(&g);

	//for (i = 0; i < g.n_vertices; i++)
	//	printf("time finish[%d] = %d\n", i, finish_time[i] );

	int finish_time2[g.n_vertices];
	for (i = 0; i < g.n_vertices; i++)
		finish_time2[i] = finish_time[i];
	qsort(finish_time2, g.n_vertices, sizeof(int), comp);
	// digunakan array baru agar setiap indeks dari finish time dapat tersimpan untuk topological sort

	if(cycle == 1)
		printf("cycle \n");
	else
		for (i = 0; i < g.n_vertices; i++)
			printf("time finish[%d] = %d\n", i, finish_time2[i] );
	return 0;
}
