**Nume: Gutanu Tiberiu-Mihnea**
**Grupă:311CAa**

## Segregated free lists - Tema 1

### Descriere:

* Scurtă descriere a funcționalității temei

Programul meu creeaza un vector de num_lists liste fiecare de dimensiune
2^3 * 2^i unde i este de la 0 la num_lists - 1. In fiecare nod retin
adresa de inceput a unui bloc. Apoi in cadrul functiei malloc caut daca
exista un bloc de dimensiune egala cu numarul de bytes pe care vreau sa ii
aloc. Daca nu iau blocul cu cea mai mica mai mare dimensiune decat ce vreau
sa aloc. In caz de am gasit in primul caz elimin primul nod. In caz de sunt
in al doilea caz caut sa vad daca exista o lista de dimensiune egala cu cati
bytes au ramas dupa alocare. Daca nu exista o creez cat sa am in vector listele
sortate crescator dupa dimensiunile blocurilor. Pentru ce am alocat pastrez
in a doua structura adresa de start si cati bytes au fost alocati. La free
caut in a doua structura daca exista blocul si il elimin si il pun in lista
corespunzatoare. La read si write caut intai daca exista o zona continua de
un numar de bytes citit alocata cat sa pot aplica aceste operatii. In caz
negativ afisez Segmentation fault(core dumped) dau un dump_memory si opresc
programul. La destroy_heap eliberez toate resursele folosite.
In cea de-a doua structura retin intr-o lista blocurile ce au fost alocate
din heap, iar in vectorul adresses retin ce se scrie la fiecare adresa, adica
in zonele de memorie. Mai precis in cadrul structurii retin ceea ce s-a alocat
si continutul.
### Comentarii asupra temei:

* Crezi că ai fi putut realiza o implementare mai bună?
Consider ca as fi putut realiza o implementare mai buna la functia malloc si
la free de tip 1, sa fac mai eficient. In rest sunt multumit de implementarea
mea si ma bucur ca am realizat acest proiect.
* Ce ai invățat din realizarea acestei teme?
Din realizarea acestei teme am invatat cum sa lucrez cu structuri de date
generice si pe langa acest aspect tema m-a ajutat sa exersez lucrul cu
listele dublu inlantuite. Totodata am invatat cum sa gestionez memoria
mai bine si cum functioneaza pointerii.
