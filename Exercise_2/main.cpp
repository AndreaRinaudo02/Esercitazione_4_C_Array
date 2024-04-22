// NB: questo codice si adatta unicamente a file di input del tipo specificato nel file README.pdf in allegato al codice stesso

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

int main()
{

    const string file_input = "data.csv";
    ifstream dati(file_input);                // apre il file di input

    if (!dati.is_open())                      // gestisce eventuali errori nell'apertura del file
    {
        cerr << "Errore: impossibile aprire il file " << file_input << endl;
        return 1;
    }


    double S = ottieni_investimento(dati);       // memorizza la cifra investita

    int n = ottieni_dimensione(dati);            // memorizza il numero di asset


    string linea;                    // scarta una riga inutile nel file di input
    getline(dati, linea);


    double* w = new double[n];       // crea due array dove memorizzare la percentuale di capitale investito e il rendimento
    double* r = new double[n];

    double* Dati[2] = {w,r};         // crea un array da due elementi, ognuno dei quali è uno degli array precedentemente creati


    ottieni_w_r(Dati,n,dati);        // memorizza la percentuale di capitale investito e il rendimento


    dati.close();         // chiude il file di input


    double rendimento_r = rendimento(Dati,n);     // calcola il rendimento complessivo

    double V;
    V = (1 + rendimento_r)*S;       // calcola il valore finale del portafoglio


    stampa_output(S,n,Dati,rendimento_r,V);       // stampa l'output nel formato desiderato


    delete [] Dati[0];      // dealloca la memoria
    delete [] Dati[1];

    return 0;

}
