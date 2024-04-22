#pragma once

#include <sstream>
#include <fstream>

using namespace std;

double ottieni_investimento(ifstream& dati);

int ottieni_dimensione(ifstream& dati);

double** ottieni_w_r( double** Dati, int dimensione, ifstream& dati);

double rendimento(double** Dati, int dimensione);

int stampa_output(double S, int n, double** Dati, double ritorno,double V);
