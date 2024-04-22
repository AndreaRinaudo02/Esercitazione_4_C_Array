#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

double ottieni_investimento(ifstream& dati)
{
    string linea;
    getline(dati, linea);     // legge la prima riga del file

    istringstream str(linea);
    char ch;
    double S;

    str >> ch;        // si ignorano il carattere "S" e il carattere ";" per poter poi leggere il valore di S
    str >> ch;
    str >> S;
    return S;
}

int ottieni_dimensione(ifstream& dati)
{
    string linea;
    getline(dati, linea);     // legge la seconda riga del file

    istringstream str(linea);
    int n;
    char ch;

    str >> ch;        // si ignorano il carattere "n" e il carattere ";" per poter poi leggere il valore di n
    str >> ch;
    str >> n;

    return n;
}

double** ottieni_w_r( double** Dati, int dimensione, ifstream& dati)
{
    string linea;
    char ch;

    for (int i = 0; i < dimensione; i++)    // scorre i valori riportati nel file e li memorizza negli array definiti in precedenza
    {

        getline(dati, linea);
        istringstream str3(linea);
        str3 >> Dati[0][i] >> ch >> Dati[1][i];
    }

    return Dati;

}

double rendimento(double** Dati, int dimensione)
{
    double ritorno = 0;
    for (int i = 0; i < dimensione; i++)
    {
        ritorno += Dati[0][i] * Dati[1][i];      // calcola il rendimento complessivo
    }
    return ritorno;
}

int stampa_output(double S, int n, double** Dati, double ritorno,double V)
{
    // stampa output a schermo

    cout << "S = " << fixed << setprecision(2) << S << ", n = " << setprecision(0) << n << endl;
    cout.unsetf(ios_base::fixed);
    cout << "w = [ ";
    for (int i=0 ; i < n; i++)
    {
        cout << Dati[0][i]<< " ";
    }
    cout << "]" << endl;

    cout << "r = [ ";
    for (int i=0 ; i < n; i++)
    {
        cout << Dati[1][i]<< " ";
    }
    cout << "]" << endl;

    cout << "Rate of return of the portfoglio: " << fixed << setprecision(4) << ritorno << endl;
    cout << "V: " << fixed << setprecision(2) << V << endl;


    // stampa output sul file result.txt

    string file_output = "result.txt";
    ofstream result(file_output);

    if (!result.is_open())                 // gestisce eventuali errori nell'apertura del file
    {
        cerr << "Errore: impossibile aprire il file " << file_output << endl;
        return 2;
    }

    result << "S = " << fixed << setprecision(2) << S << ", n = " << setprecision(0) << n << endl;
    result.unsetf(ios_base::fixed);
    result << "w = [ ";
    for (int i=0 ; i < n; i++)
    {
        result << Dati[0][i]<< " ";
    }
    result << "]" << endl;

    result << "r = [ ";
    for (int i=0 ; i < n; i++)
    {
        result << Dati[1][i]<< " ";
    }
    result << "]" << endl;

    result << "Rate of return of the portfoglio: " << fixed << setprecision(4) << ritorno << endl;
    result << "V: " << fixed << setprecision(2) << V << endl;

    result.close();
    return 0;
}
