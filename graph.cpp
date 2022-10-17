#include "graph.h"
#include <iostream>
#include <list>
#include <queue>

// U obilasku grafa koristenjem reda bojat cemo vrhove
#define WHITE   0   // Vrh jos nije posjecen i nije stavljen u red
#define GRAY    1   // Vrh je stavljen u red
#define BLACK   2   // Vrh je posjecen i svi njegovi susjedi stavljeni u red

using namespace std;

// Konstruktor
Graph::Graph( int V )
{
    this->V = V;
    color = new int[V];
    adj = new list<int>[V];
}

// Funkcija kojom dodajemo brid grafu
void Graph::addEdge( int v, int w )
{
    // Dodajemo w u listu susjeda vrha v
    adj[v].push_back( w );

    // Dodajemo v u listu susjeda vrha w
    adj[w].push_back( v );
}

// Funkcija kojom izbacujemo brid iz grafa
void Graph::removeEdge( int v, int w )
{
    list<int>::iterator li, ltemp;

    // Izbacujemo w iz liste susjeda vrha v
    li = adj[v].begin();
    while( li != adj[v].end() ) {
        if( *li == w ) {
            ltemp = li; ++ltemp;
            adj[v].erase( li );
            li = ltemp;
        }
        else ++li;
    }
    
    // Izbacujemo v iz liste susjeda vrha w
    li = adj[w].begin();
    while( li != adj[w].end() ) {
        if( *li == v ) {
            ltemp = li; ++ltemp;
            adj[w].erase( li );
            li = ltemp;
        }
        else ++li;
    }
}

// Pomocna funkcija kojom ispitujemo pripada li brid grafu (osigurava da input bude korektan)
bool Graph::belongsToGraph( int v, int w )
{
    // Iterator za kretanje po listi susjeda vrha v
    list<int>::iterator li;
    for( li = adj[v].begin(); li != adj[v].end(); ++li ){
        if( *li == w ) return true; // Dani brid pripada grafu
        // Ne moramo provjeravati susjede vrha w jer se te dvije liste u funkciji addEdge pune "simultano"
    }

    // Nismo pronasli vrh w kao susjed vrha v pa brid {v, w} ne pripada grafu
    return false;
}

// Funkcija koja vraca true ako dani brid pripada ciklusu
bool Graph::belongsToCyle( int v, int w )
{
    // Provjera postoji li {v, w} kao brid u danom grafu (osiguravamo da input bude korektan)
    if( !belongsToGraph( v, w ) ){
        cout << "Dani brid ne postoji u grafu!" << endl;
        exit(5);
    }
    
    // Iz grafa izbacujemo dani brid
    this->removeEdge( v, w );

    // Dalje ispitujemo je li sada moguce iz vrha v doci do vrha w
    // Dani brid pripada ciklusu ako i samo ako je to moguce
    
    // Provodimo Breadth-First-Search (BFS)
    
    int i;
    // Bojamo svaki vrh u bijelo (inicijalizacija)
    for( i = 0; i < V; i++ ) this->color[i] = WHITE;

    // Krecemo od vrha v, tj. njega posjecujemo pa ga bojamo u sivo
    // Zasad ga ne bojamo u crno jer jos nismo njegove susjede stavili u red
    color[v] = GRAY;

    // Red koji cemo koristiti za obilazak grafa
    queue<int> Q;
    
    // Ubacujemo polazni vrh v u red
    Q.push( v );

    int u;
    // BFS
    while( !Q.empty() ){
        u = Q.front();
        Q.pop();

        if( u == w ) return true;
        // Nasli smo put od v do w pa dani brid pripada ciklusu

        // Iterator za kretanje po listi susjeda vrha u
        list<int>::iterator li;
        
        for( li = adj[u].begin(); li != adj[u].end(); ++li )
        {
            if( color[*li] == WHITE ){
                // Ovaj susjed vrha u jos nije posjecen i nije stavljen u red
                Q.push( *li );  // Stavimo ga u red
                color[*li] = GRAY;  // Obojamo ga u sivo
            }
        }
        // Prosli smo po svim susjedima vrha u, stoga ga bojamo u crno
        color[u] = BLACK;
    }

    // Prosli smo po citavoj komponenti povezanosti vrha v
    // Nismo pronasli vrh w
    // Dakle, izbacivanjem danog brida iz grafa vise ne postoji put iz vrha v do vrha w
    // Zakljucak: dani brid NE PRIPADA ciklusu
    return false;
}