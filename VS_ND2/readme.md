# Programa, skirta skaičiuoti vidurkį bei medianą
Versijų registras:
1. v0.1:
	1. Programa surenka žmogaus įrašytus duomenis: vardą, pavardę, namų darbų kiekį ir jų pažymius, egzamino pažymį. 
	2. Programoje yra apsauga nuo neteisingo formato duomenų įvedimo, tad kai vietoj skaičius bus įvedamas simbolis, programa apie tai praneš ir lieps įvesti dar kartą, o ne 'suluš'. 
2. v0.1.1
	1. Papildomai prie ankstesnių programos galimybių, dabar, vartotojui pasirinkus, studento pažymiai ir jų kiekiai gali būti sugeneruojami atsitiktinai
	2. Vietoje C masyvo naudojamas vektorius.
	3. Studento duomenys saugojami struktūroje.
3. v0.2
	1. Dabar studentų duomenys taip pat gali būti nuskaitomi iš failo.
	2. Išvedamos visų studentų medianos bei vidurkiai.
4. v0.3
	1. Naudojami exceptionai, try ir catch metodai.
	2. Programa suskirstyta į kelis failus: ND2 v0.3.cpp, kuris atlieka pagrindines funkcijas, funkcijų faila func.cpp ir antraščių faila Header.h .
5. v0.4
	1. Pasirinkus parinktį, programa automatiškai:
		1. Sugeneruos 5 studentų failus (1k, 10k, 100k, 1M, 10M failus);
		2. Nuskaitys iš failų duomenis į struktūras;
		3. Surūšiuos studentus pagal pažymius;
		4. Išskirstys studentus į pabiručius (vidurkis < 5) ir protingučius (vidurkis >= 5);
		5. Išves atskirus pabiručių ir protingučių failus.
	2. Norint pasileisti programą: 
		1. Rekomenduojama tiesiog pasileisti "VS_ND2.exe" failą. Nieko daugiau redaguoti nereikia.
		2. Taip pat galima susidėti 3 failus (ND2_v0.4.cpp, func.cpp, Header.h) į bendrą projektą ir jį pasileisti programavimo aplinkoje, pvz. Visual Studio 2019.
		3. Terminale pasigaminti (make) makefile'ą ir jį parunninti
	3. Programos veikimo laiką kūrimo aplinkoje galima rasti nuotraukoje "konsolev0.4.png"