#include <list>

using namespace std;

// Struktura za nepovezani graf
struct Graph
{
    // Broj vrhova
    int V;

    // Polje u koje biljezimo boje vrhova (potrebno za BFS)
    int* color;

    // Pokazivac na polje koje sadrzi liste susjeda
    list<int>* adj; // Vrhove BSO reprezentiramo pomocu integera

    // Konstruktor
    Graph( int V );

    // Funkcija kojom dodajemo brid grafu
    void addEdge( int v, int w );

    // Pomocna funkcija kojom izbacujemo brid iz grafa
    void removeEdge( int v, int w );

    // Pomocna funkcija kojom ispitujemo pripada li brid grafu (osigurava da input bude korektan)
    bool belongsToGraph( int v, int w );
    
    // Funkcija koja vraca true ako dani brid pripada ciklusu, inace false
    bool belongsToCyle( int v, int w );
};