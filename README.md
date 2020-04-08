# lab5-6-template-stl-Teona09
lab5-6-template-stl-Teona09 created by GitHub Classroom
Tanasă Teona-Gabriela

Lab 6 314/1- Aplicatie de management al parcarii

Sistemul de bariera de la parcarea facultatii are nevoie de un sistem de management pentru numere de inmatriculare.
Pentru asta are nevoie de un repository care stocheaza Masina(numePosesor, nrInmatriculare, status).
Numarul de inmatriculare este unic, status in [ocupat, liber].
Folositi conceptele de programare stratificata repo, service, UI.

live:
– clasa entitate & teste, (2p)
– clasa Repo (stl, folosind list!!!!, (optional repo cu template)), popularea repo-ului cu obiecte și ”vizualizarea” lor (add,
getAll) & teste (3p)

tema:
Finalizare repo, servici, UI cu CRUD complet + teste (5p).

8.04.2020 – 314/1 Lab 7

Parcarea are un numar predefinit de locuri X.
Administratorul poate adauga sau sterge oricate masini din gestiune cu conditia sa aiba numere de inmatriculare diferite.
Nu se poate sterge din sistem o masina cu statusul “ocupat”, pana ce aceasta iese din parcare.
Senzorul optic citeste numerele la intrare si iesire schimband statusurle.
La intrare, sistemul va citi numarul de inmatriculare si va marca masina ca “ocupat” daca capacitatea parcarii permite, altfel va printa un mesaj de eroare.
De asemena va printa un mesaj de eroare daca o masina marcata “liber” incearca sa iasa sau una marcata “ocupat” incearca sa intre.
Administratorul are nevoie si de numarul cu care se depaseste capacitatea, egal cu maximul de masini care incearca sa intre si nu au loc, intre o intrare si o iesire de succes.

live:
– functionalitatea de intrare cu cazurile exceptionale (capacitate plina,  masina vrea sa intre de 2 ori)  + teste 3p
– RepoFile (mostenit din Repo), cu functia de loadDataFromFile- 2p

tema:
– finalizare RepoFile si finalizare cerinte si teste
– repository cu template stl (5p)
