#include "Header.h"

void dalykai(vector<Studentas>& pabiruciai, vector<Studentas>& protinguciai, vector<Studentas>& eilinis, int kiekis)
{
    eilinis.reserve(kiekis + 1);
    eilinis.resize(kiekis + 1);
    pabiruciai.reserve(kiekis + 1);
    protinguciai.reserve(kiekis + 1);
    pabiruciai.resize(kiekis + 1);
    protinguciai.resize(kiekis + 1); // rezervuota viena vieta daugiau, kad butu paprasciau skaiciuoti irasus nuo 1

    chrono::time_point<chrono::system_clock> start, end;
    chrono::time_point<chrono::system_clock> startEvent, endEvent;
    chrono::duration<double> elapsed_seconds;

    int protKiekis, pabirKiekis;
    string failas;

    start = chrono::system_clock::now();
    startEvent = chrono::system_clock::now();
    failas = generuoti(eilinis, kiekis); // process
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su "<< kiekis<<" duomenu sugeneravimas uztruko: " << elapsed_seconds.count() << "s\n";

    start = chrono::system_clock::now();
    nuskaityti(eilinis, kiekis, failas);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su " << kiekis << " duomenu nuskaitymas uztruko: " << elapsed_seconds.count() << "s\n";

    start = chrono::system_clock::now();
    rusiuoti(eilinis, kiekis);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su " << kiekis << " duomenu rusiavimas uztruko: " << elapsed_seconds.count() << "s\n";

    start = chrono::system_clock::now();
    pabirKiekis = 0;
    protKiekis = 0;
    skirstyti(eilinis, kiekis, pabirKiekis, protKiekis, pabiruciai, protinguciai);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su " << kiekis << " duomenu skirstymas i protingus ir pabirucius uztruko: " << elapsed_seconds.count() << "s\n";

    string pavadinimasPabir = "pabiruciai" + to_string(kiekis) + ".txt";
    string pavadinimasProt = "protinguciai" + to_string(kiekis) + ".txt";

    start = chrono::system_clock::now();
    isvedimas(pabiruciai, pabirKiekis, pavadinimasPabir);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su " << pabirKiekis << " duomenu irasymas i pabirucius uztruko: " << elapsed_seconds.count() << "s\n";

    start = chrono::system_clock::now();
    isvedimas(protinguciai, protKiekis, pavadinimasProt);
    end = std::chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Failo su " << protKiekis << " duomenu irasymas i protingucius uztruko: " << elapsed_seconds.count() << "s\n";

    endEvent = std::chrono::system_clock::now();
    elapsed_seconds = endEvent - startEvent;
    cout << "Failo su " << kiekis << " duomenu procesai uztruko: " << elapsed_seconds.count() << "s\n\n";
}
void skirstyti(vector<Studentas>& eilinis, int kiekis, int& pabirKiekis, int& protKiekis, vector<Studentas> &pabiruciai, vector<Studentas> &protinguciai)
{
    for (int i = 1; i <= kiekis; i++) {
        if (eilinis[i].egz < 5.00) {
            pabiruciai[pabirKiekis].vardas = eilinis[i].vardas;
            pabiruciai[pabirKiekis].pavarde = eilinis[i].pavarde;
            pabiruciai[pabirKiekis].egz = eilinis[i].egz;
            pabirKiekis++;
        }
        else {
            protinguciai[protKiekis].vardas = eilinis[i].vardas;
            protinguciai[protKiekis].pavarde = eilinis[i].pavarde;
            protinguciai[protKiekis].egz = eilinis[i].egz;
            protKiekis++;
        }
    }
}
void rusiuoti(vector<Studentas>& eilinis, int kiekis)
{
    sort(eilinis.begin(), eilinis.end(), maziau);
}
void nuskaityti(vector<Studentas>& eilinis, int kiekis, string failas)
{
    ifstream autoIn(failas);
    eilinis = {}; // nunullinam struktura
    eilinis.reserve(kiekis + 1);
    eilinis.resize(kiekis + 1);

    for (int i = 1; i <= kiekis; i++) {
        autoIn >> eilinis[i].pavarde >> eilinis[i].vardas >> eilinis[i].egz;
    }
}
string generuoti(vector<Studentas>& eilinis, int kiekis)
{
    eilinis = {}; // nunullinam struktura
    eilinis.reserve(kiekis+1);
    eilinis.resize(kiekis+1);
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> balai(1.0, 10.0);
    double egzas;
    string outFileName = "autoOut" + to_string(kiekis)+".txt";
    ofstream autoOut(outFileName);
    for (int i = 1; i <= kiekis; i++) {
        eilinis[i].vardas = "Vardas" + to_string(i);
        eilinis[i].pavarde = "Pavarde" + to_string(i);
        egzas = balai(mt);
        eilinis[i].egz = egzas;
        autoOut << left << setw(20) << eilinis[i].pavarde << setw(20) << eilinis[i].vardas << setw(20) << setprecision(3) << eilinis[i].egz << endl;
    }
    return outFileName;
}
bool compareByLength(const Studentas& a, const Studentas& b)
{
    return a.vardas < b.pavarde;
}
bool maziau(const Studentas& a, const Studentas& b)
{
    return a.egz < b.egz;
}
void isvedimas(vector<Studentas> vektorius, int kiekis, string failoPav= "rezultatai.txt") // isvedimas auto sugeneruotiems
{
    ofstream offile(failoPav);
    offile << "Pavarde             Vardas              Galutinis (egz.)\n";
    offile << "--------------------------------------------------------\n";
    for (int i = 0; i < kiekis; i++) {
        offile << left << setw(20) << vektorius[i].pavarde << setw(20) << vektorius[i].vardas << setw(20) << setprecision(3) << vektorius[i].egz << endl;
    }

}
void isvedimas(vector<Studentas>& eilinis)
{
        ofstream offile("rezultatai.txt");
        offile << "Pavarde             Vardas              Galutinis (vid.)    Galutinis (med.)    \n";
        offile << "--------------------------------------------------------------------------------\n";
        for (int i = 0; i < eilinis.size(); i++) {
            offile << left << setw(20) << eilinis[i].pavarde << setw(20) << eilinis[i].vardas << setw(20) << setprecision(3) << eilinis[i].galVid << setw(20) << setprecision(2) << eilinis[i].galMed << endl;
        }
        
        //cout << left << setw(20) << pavarde << setw(20) << vardas << setw(20) << setprecision(3) << vid << setw(20) << setprecision(2) << med << endl; 
}
double vidurkis(vector<double>& nd, double egz)
{
    double vidurkis = 0;
    int dydis = nd.size();
    for (int i = 0; i < dydis; i++) {
        vidurkis += nd[i];
    }

    return vidurkis = 0.4 * (vidurkis / dydis) + 0.6 * egz;
}
double mediana(vector<double>& nd)
{
    int dydis = nd.size();
    // susortina masyva
    sort(nd.begin(), nd.end());
    // suranda mediana
    if (dydis % 2 == 0)
    {
        return (nd[dydis / 2 - 1] + nd[dydis / 2]) / 2;
    }
    else
    {
        return nd[dydis / 2];
    }
}
void digitCheck(string& stringas, bool check)
{
    while (!check) {
        if (std::any_of(stringas.begin(), stringas.end(), isdigit)
        {
            cout << "\nVardas ir pavarde negali tureti skaiciu! Prasome ivesti is naujo: ";
            cin >> stringas;
        }
        else {
            check = true;
        }
    }
}
void symbolCheck(double& skaicius, bool ok, bool balas)
{
    ok = false;
    cin >> skaicius;
    while (cin.fail()) { // tikrina ar tikrai ivestas double tipo skaicius
        cout << "\nIvesta reiksme gali buti tik skaicius. Iveskite skaiciu is naujo: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> skaicius;
    }

    while (!ok) {
        if (cin.fail()) symbolCheck(skaicius, ok, balas);
        if (balas) {
            if (skaicius >= 0.0 && skaicius <= 10.0)
            {
                ok = true;
            }
            else {
                cout << "\nBalas turi buti desimtbaleje sistemoje. Iveskite skaiciu is naujo: ";
                cin >> skaicius;
            }
        }
        else {
            if (skaicius < 0.0) {
                cout << "\nNamu darbu kiekis turi buti neneigiamas skaicius. Iveskite skaiciu is naujo: ";
                cin >> skaicius;
            }
            else ok = true;
        }
    }
}
void symbolCheck(int& skaicius, bool ok, bool balas)
{
    ok = false;
    cin >> skaicius;
    while (cin.fail()) { // tikrina ar tikrai ivestas double tipo skaicius
        cout << "\nIvesta reiksme gali buti tik skaicius. Iveskite skaiciu is naujo: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> skaicius;
    }

    while (!ok) {
        if (cin.fail()) symbolCheck(skaicius, ok, balas);
        if (balas) {
            if (skaicius >= 0.0 && skaicius <= 10.0)
            {
                ok = true;
            }
            else {
                cout << "\nBalas turi buti desimtbaleje sistemoje. Iveskite skaiciu is naujo: ";
                cin >> skaicius;
            }
        }
        else {
            if (skaicius < 0.0) {
                cout << "\nNamu darbu kiekis turi buti neneigiamas skaicius. Iveskite skaiciu is naujo: ";
                cin >> skaicius;
            }
            else ok = true;
        }
    }
}
double vectorSymbolCheck() // PAKEISTI KAD TIKTU VEKTORIUI
{
    double skaicius;
    bool ok = false;
    cin >> skaicius;
    while (cin.fail()) { // tikrina ar tikrai ivestas double tipo skaicius
        cout << "\nIvesta reiksme gali buti tik skaicius. Iveskite skaiciu is naujo: ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> skaicius;
    }

    while (!ok) {
        if (cin.fail()) vectorSymbolCheck();
        if (skaicius >= 0.0 && skaicius <= 10.0)
        {
            ok = true;
        }
        else {
            cout << "\nBalas turi buti desimtbaleje sistemoje. Iveskite skaiciu is naujo: ";
            cin >> skaicius;
        }
    }

    return skaicius;
}
void boolCheck(bool& check)
{
    int ivestis;
    bool ok = false;
    while (!ok) {
        cin >> ivestis;
        if (cin.fail()) {
            cout << "\nIveskite 0 arba 1: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        else {
            if (ivestis == 0) {
                check = false;
                ok = true;
            }
            else if (ivestis == 1) {
                check = true;
                ok = true;
            }
            else cout << "\nIveskite 0 arba 1: ";
        }

    }
}