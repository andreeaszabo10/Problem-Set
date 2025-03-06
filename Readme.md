Copyright Szabo Cristina-Andreea 2022-2023


# Problema 1: Infinite product

Pentru aceasta problema am implementat un algoritm care sa calculeze produsul scalar a 2 vectori, cel de-al doilea maxim pentru fiecare vector (daca exista) si norma 2 a fiecaruia dintre cei 2 vectori.
Rezolvare:
- am citit cu ajutorul unui for() elementele vectorilor, in baza 8;
- am utilizat formulele matematice prezentate in cerinta pentru aflarea produsului scalar si a normelor, acestea din urma fiind implementate cu ajutorul functiilor matematice "sqrt()" si "pow()"
- pentru gasirea celui de-al doilea maxim am luat o variabila test pentru fiecare vector, initializata cu -1, care imi va arata daca exista sau nu al doilea maxim (se face 1 daca apar 2 numere distincte in vector)
- am folosit variabilele a_max1 si b_max1 ca sa retina cel mai mare numar din fiecare vector
- am afisat in baza 10 rezultatele

# Problema 2: Simple Queries

Rezolvare:
1. am inceput aceasta problema cu un while, care se opreste in momentul in care intalnim un caracter invalid, iesind astfel din program
2. am verificat daca a fost introdusa o litera mica, caz in care cresc numarul total de litere(nr_litere), numarul de litere de la declansarea ultimei alarme(a) si numarul de aparitii al literei introdse(vectorul de frecventa v[])
-verific daca au fost introduse macar 2 litere diferite cu o variabila(ok), fapt ce ma va ajuta la declansarea alertei(o alerta este declansata doar daca "a" e mai mare sau egal cu 5, daca exista cel putin 2 litere diferite si numarul de aparitii al unei litere este mai mare sau egal cu jumatatea numarului total de litere)
-in cazul in care se poate declansa o alerta pentru o litera, iau 2 variabile in care retin numarul de aparitii al literei si numarul total de litere(pentru a nu modifica originalele) si le impart pe fiecare la divizorii comuni ai acestora, daca exista, apoi afisez fractia simplificata
3. verific daca a fost introdus un caracter care duce la o operatie("Q", "E" sau "T")
- daca a fost introdus caracterul "Q", se citeste o litera mica, apoi afisez litera si numarul de aparitii al acesteia(cu ajutorul vectorului de frecventa v[])
- daca a fost introdus caracterul "T", se citeste "K"(numarul de litere care trebuie afisate) si folosesc doi vectori, w[](care retine numarul de aparitii al fiecarei litere) si u[](care retine ordinea literelor in functie de numarul de aparitii). Sunt interschimbate atat pozitiile literelor( cu u[]), cat si numarele de aparitii ale acestora(cu w[]) pentru a fi in ordine descrescatoare, iar daca numerele de aparitii sunt egale ale unor litere, acestea se vor ordona in ordine lexicografica. Se afiseaza cele K litere ordonate descrescator in functie de numarul de aparitii.
- daca a fost introdus caracterul "E", se citeste o litera mica si i se elimina aparitiile din vectorul v[], numarul de aparitii se scade din numarul total de litere, iar daca in urma stergerii nu mai exista 2 litere distincte, ok- ul se face 0

# Problema 3: Gigel and the checkboard

In aceasta problema este vorba de o tabla de sah si mutarile pe care le face o piesa care incepe din coltul din stanga sus al tablei, in functie de numerele de pe biletele aflate pe tabla.
Rezolvare:
- problema se termina atunci cand piesa ajunge pe un patrat pe care a mai fost, asa ca am folosit un while in care am verificat acest lucru. Pentru fiecare pozitie noua am crescut valoarea elementului corespunzator tablei din matricea poz[][], initializata cu 0 la inceput. Se iese din while daca valoarea matricei poz corespunzatoare locului in care se afla piesa este 1.
- calculez distanta adunand la distanta parcursa anterior(fiind initializata cu 0 la inceput) numarul care se afla pe biletul pe care se afla piesa daca numarul este pozitiv, sau scazandu-l daca este negativ.
- verific 2 cazuri:patratul e alb sau patratul e negru: alb, daca suma indicilor elementului e divizibila cu 2 si negru, altfel. Daca patratul este alb, piesa se deplaseaza pe linii, iar daca e negru, pe coloane.
- pentru fiecare din cele 2 cazuri, tratez alte 2 cazuri: daca numarul de pe bilet e pozitiv sau negativ. Daca patratul e alb si numarul pozitiv, piesa se deplaseaza spre dreapta, iar daca e negativ, spre stanga. Daca patratul e negru si numarul pozitiv, piesa se deplaseaza in jos, iar daca e negativ, in sus. Daca modulul numarului de pe bilet e mai mare decat numarul de patrate ramase pana la marginea spre care se deplaseaza piesa, folosesc o formule aflate prin inductie pentru a determina pozitia finala a piesei. Daca nu e mai mare, piesa se deplaseaza in directia potrivita cu un numar de patrate egal cu cel de pe bilet. Pentru a calcula modulul numarului de pe bilet, am pus un minus in fata acestuia, in cazul in care era negativ.
- cand se intalneste o pozitie pe care piesa a mai fost, se iese din while si se afiseaza pozitia finala

# Problema 4: Another queries

Rezolvare:
- se citeste numarul N (tabla fiind de N*N) si numarul de operatii(M)
- am utilizat cate o functie pentru fiecare tip de operatie care au fost definite pentru jocul de sudoku. Am pus la toate operatiile Y-1, X-1 si Z-1 pentru ca numerotarea in cod incepe de la 0, nu 1;
- operatia 1: se citeste un X, care reprezinta linia care trebuie verificata, apoi pentru aceasta linie verific care cifre pana la N*N (atatea elemente sunt pe o linie) cu ajutorul variabilei lin[][]. Dupa ce am verificat care cifre au aparut crescand valoarea elementului din matricea lin[][], initializata la inceput cu 0, afisam cu un for de la 1 la N*N: "0", daca cifra nu se poate pe linie(a mai aparut inainte) sau "1", daca se poate pune.
- operatia 2: se citeste un Y, care reprezinta coloana care trebuie verificata, apoi verificam exact ca pentru linii, doar ca am folosit matricea col[][] in loc de lin[][], daca fiecare cifra de la 1 la N*N se poate pune sau nu pe acea coloana si afisam pentru fiecare dintre aceste cifre "0" daca nu se poate pune pe coloana si "1" daca se poate.
- operatia 3: se citeste un Z, care reprezinta careul care trebuie testat si am verificat la fel ca la celelalte 2 operatii cifrele care pot fi adaugate, doar ca am utilizat vectorul c[](pentru careu). Am aflat coordonatele coordonatele elementului din stanga sus al careului Z prin inductie si am testat daca cifrele de la 1 la N*N pot fi puse in careul respectiv. Am afisat pentru fiecare din aceste cifre: "0", daca cifra se poate pune in careu si "1", daca nu.
- operatia 4: se citesc X si Y, coordonatele unei celule. Daca in celula respectiva exista deja o valoare, se afiseaza N*N 0-uri, daca nu, verific frecventa cifrelor atat pe coloane, cat si pe linii si in careul in care se afla celula, apoi afisez "0", daca cifra nu se poate pune in celula si "1", daca se poate. Careul(Z) l-am aflat printr-o formula gasita prin inductie.
- operatia 5: se citesc X si Y, coordonatele unei celule si C o cifra. Vad daca exista o valoare deja in acea celula, iar daca nu exista, introduc cifra C in acel loc.
- operatia 6: verific cu 2 vectori (v[] si u[])daca se repeta vreo valoare in sudoku. Daca se repeta, am ajuns intr-o configuratie invalida, variabila de test ok(initializata cu 1) devine 0 si se afiseaza "1". Daca nu se repeta, configuratia este valida, asa ca verific daca vreun element este 0. Daca exista un element 0, jocul se poate continua, afisez "0", iar daca nu exista niciun element egal cu 0, jocul e castigat, afisez "2".
- in functia main exista un while care face ca programul sa ruleze cat timp M-ul este mai mare decat 0, adica mai exista operatii care trebuie efectuate. Pentru fiecare loop este citit si efectual tipul de operatie, apoi M-ul devine mai mic cu 1, aratand ca s-a efectuat o operatie.
