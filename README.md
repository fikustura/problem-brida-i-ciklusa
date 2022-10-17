Problem glasi: **Za zadani povezani neusmjereni graf i njegov brid _e_ odrediti pripada li _e_ ciklusu ili ne. Složenost, uz standardne oznake, najviše _O(m + n)_.** (_m_ je broj bridova, a _n_ broj vrhova grafa)

_C++_ program koji predstavljaja rješenje problema realiziran je kroz tri detaljno komentirane datoteke: _graph.h_ (sučelje), _graph.cpp_ (implementacija sučelja) i _main.cpp_ (klijentski program).

Dostupna je i _PowerPoint_ prezentacija rješenja.

#### NAPOMENE:
- U prve dvije datoteke (_graph.h_ i _graph.cpp_) definiram i implementiram strukturu koju koristimo, a to je **graf**.
- U trećoj datoteci (_main.cpp_) iz tekstualne datoteke _data.txt_ učitava se graf, odnosno broj njegovih vrhova te bridovi (dvočlani skupovi vrhova).
- Alternativno, graf je moguće, naravno, učitati i manje elegantnim putem, direktno u samom _main_-u. Taj dio sam zakomentirao.
- Program je moguće dobiti zajedničkim _kompajliranjem_ i _linkanjem_ datoteka _main.cpp_ i _graph.cpp_.
- Brid grafa za koji želimo utvrditi pripada li ciklusu ili ne učitavamo putem komandne linije, prilikom pokretanja programa.

#### UPUTE (opis testnih podataka):
- Koristi se tekstualna datoteka _data.txt_.
- U prvom retku datoteke nalazi se **samo** _integer_ _V_ koji predstavlja broj vrhova grafa. Vrhovi grafa indeksirani su brojevima _0, ... , V-1_.
- U svakom idućem retku datoteke nalaze se samo dva _integera_ **strogo manja od _V_**, međusobno odvojena razmakom. Oni predstavljaju brid koji dodajemo grafu.
- Korisnik treba paziti da u tekstualnoj datoteci ne unese neki brid više od jednom (ovome je, naravno, moguće doskočiti u implementaciji, no time se nisam zamarao).
