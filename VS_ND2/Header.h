#pragma once
#include <iostream>
#include <algorithm>    // std::any_of
#include <iomanip>      // std::setprecision
#include <vector>
#include <random>
#include <fstream>
#include <string>
#include <iterator>
#include <chrono>

using namespace std;

struct Studentas {

    string vardas = "", pavarde = "";
      int n = 0;
    vector<double> ND;
    double egz = 0, galVid = 0, galMed = 0;
};

void digitCheck(string& stringas, bool check);
void symbolCheck(double& skaicius, bool check, bool balas);
void symbolCheck(int& skaicius, bool check, bool balas);
void boolCheck(bool& arMediana);
double vectorSymbolCheck();
double mediana(vector<double>& nd);
double vidurkis(vector<double>& nd, double egz);
//void isvedimas(string &vardas, string &pavarde, double &vid, double &med);
void isvedimas(vector<Studentas>& eilinis);
void isvedimas(vector<Studentas>& eilinis, int kiekis);
//void failoNuskaitymas(vector<Studentas>& eilinis, string &ndCheck, int& ndCount, int& stKiekis);
bool compareByLength(const Studentas& a, const Studentas& b);
string generuoti(vector<Studentas>& eilinis, int kiekis);
void nuskaityti(vector<Studentas>& eilinis, int kiekis, string failas);
void rusiuoti(vector<Studentas>& eilinis, int kiekis);
bool maziau(const Studentas& a, const Studentas& b);
void skirstyti(vector<Studentas>& eilinis, int kiekis, int& pabirKiekis, int& protKiekis, vector<Studentas> &pabiruciai, vector<Studentas> &protinguciai);
void isvedimas(vector<Studentas> vektorius, int kiekis, string failoPav);
void dalykai(vector<Studentas>& pabiruciai, vector<Studentas>& protinguciai, vector<Studentas>& eilinis, int kiekis);
