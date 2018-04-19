#include<fstream>
#include<iostream>
using namespace std;

int G[100][3]; // graful colectie de muchii (i,j,k) unde k = costul
int n;             // numarul nodurilor
int L[100];     // setul arborilor disjuncti unde L[i]=j inseamna ca
                     // nodul i se gaseste in Arbore A_j
int m;            // numarul muchiilo

int read_data()
{fstream f;
f.open("input.dat",ios::in);
f>>n;
m=0;

while (!f.eof()) {
                         m++;
                        f>>G[m][1];
                        f>>G[m][2];
                        f>>G[m][3];
                        }m--;}

int swapper(int a, int b){
    int A[100][3];

    A[1][1]=G[a][1];
    A[1][2]=G[a][2];
    A[1][3]=G[a][3];

    G[a][1]=G[b][1];
    G[a][2]=G[b][2];
    G[a][3]=G[b][3];

    G[b][1]=A[1][1];
    G[b][2]=A[1][2];
    G[b][3]=A[1][3];
}

int sort_data()
{
    int i, j, min_idx;
    for (i = 1; i <= m-1; i++)
    {
        min_idx = i;
        for (j = i+1; j <= m; j++)
          if (G[j][3] < G[min_idx][3])
            min_idx = j;
        swapper(min_idx,i);
    }
}

int init_data()
{for(int i=1;i<=n;i++)  L[i]=i;}

int compute_APM()
{
sort_data();  // sortam crescator dupa costuri
cout<<" Nodes : "<<n<<" Edges  : "<<m;   //  verificari
for(int i=1;i<=m;i++) cout<<endl<<G[i][1]<<"-"<<G[i][2]<<"="<<G[i][3];
init_data();  // initializam setul arborilor disjuncti
int unify=0;  // numarul de unificari care trebuie efectuate
cout<<endl<<"APM";  // Kruskal , execut prima unificare
unify++;                       // data de extremitatile muchiei de cost minim
int name;
int left=G[1][1];
int right=G[1][2];
L[right]=L[left] ; // unificarea
name=left;
cout<<endl<<left<<"  "<<right;

while (unify<(n-1))
   {    int first=1;  // prima muchie
        int last=m;  // ultima muchie , dupa costuri
        while (first<=last)   // parcurg  muchiile
        {  left=G[first][1];   // extrag exemitatile muchiei curente
            right=G[first][2];
if ((L[left]!=L[right])&&((left==name)||(right==name)))
                                    // daca trebuie facuta unificare
                    {  unify++;
                       cout<<endl<<left<<"  "<<right;
                       L[right]=name;}
            first++; }
    }
}

int main()
{read_data();
compute_APM();
}
