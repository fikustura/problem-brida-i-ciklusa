#include "graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>

using namespace std;

// Funkcija za citanje dvaju integera iz stringa
void extractIntegerWords(string str, int* a, int* b)
{
    stringstream ss;

    ss << str;

    string temp;
    
    ss >> temp;
    if(stringstream(temp) >> *a) {}

    temp = "";

    ss >> temp;
    if(stringstream(temp) >> *b) {}
}

// Funkcija za citanje jednog integera iz stringa
void extractIntegerWord(string str, int* V)
{
    stringstream ss;

    ss << str;

    string temp;
    
    ss >> temp;
    if(stringstream(temp) >> *V) {}

    temp = "";
}

int main( int argc, char** argv )
{
    if( argc != 3 ){
        cout << "Upotreba: " << argv[0] << " vrh1 vrh2 (brid je reprezentiran dvoclanim skupom {vrh1, vrh2})" << endl;
        exit(0);
    }

    /*  Ovaj zakomentirani graf ucitat cemo iz datoteke
    Graph g( 8 );
    g.addEdge( 0, 2 );
    g.addEdge( 0, 1 );
    g.addEdge( 1, 3 );
	g.addEdge( 3, 4 );
	g.addEdge( 4, 6 );
    g.addEdge( 6, 7 );
    g.addEdge( 7, 5 );
    g.addEdge( 5, 4 );
    g.addEdge( 5, 6 );
    g.addEdge( 5, 3 );
    */

    // Ucitavanje grafa iz datoteke
    ifstream inFile;
    inFile.open( "data.txt" );
    if( !inFile ) {
        cout << "Neuspjesno otvaranje datoteke data.txt" << endl;
        exit(3);
    }
    string s;
    getline( inFile, s );   // U prvoj liniji zapisan je broj vrhova
    int V;
    extractIntegerWord( s, &V );
    Graph g( V );   // Poziv konstruktora strukture Graph
    int a, b;
    while( !inFile.eof() ) {
        getline( inFile, s );   // Datoteku citamo liniju po liniju
        extractIntegerWords( s, &a, &b );   // Iz svake linije procitamo dva integera
        if(a < 0 || a >= V || b < 0 || b >= V )
        {
            cout << "Neispravan unos u tekstualnoj datoteci!" << endl;
            exit(4);
        }
        g.addEdge( a, b );  // Dodajemo odgovarajuci brid u graf
    }
    inFile.close();

    int v = atoi( argv[1] );
    if( v < 0 || v >= g.V ){    // Provjera postoji li vrh v u grafu (je li input korektan)
        cout << "Vrh " << v << " ne postoji u grafu!" << endl;
        exit(1);
    }
    int w = atoi( argv[2] );
    if( w < 0 || w >= g.V ){    // Provjera postoji li vrh w u grafu (je li input korektan)
        cout << "Vrh " << w << " ne postoji u grafu!" << endl;
        exit(2);
    }
    
    g.belongsToCyle( v, w )?    // Provjera pripada li dani brid ciklusu ili ne
    cout << "Dani brid pripada ciklusu." << endl:
    cout << "Dani brid ne pripada ciklusu." << endl;
    
    return 0;
}