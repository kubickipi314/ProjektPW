# Świszcz

**Świszcz** (*Marmota monax*) nie jada drewna. Inaczej nie powierzonoby mu pieczy nad największym w okolicy tartakiem, obsługiwanym przez sympatyczną rodzinę niedźwiedzi.

Już w pierwszym dniu pracy Świszcz dostrzegł, że niedźwiedzie nieefektywnie posługują się skomplikowanym zestawem pił do cięcia gotowych desek. Każdą deskę trzeba poprzecinać w n uprzednio zaznaczonych miejscach. Aby wykonać cięcie należy położyć deskę na pile, a długimi deskami dość ciężko się manipuluje. Koszt pojedynczej operacji – ustawienia deski – można skutecznie przybliżyć przez odległość miejsca cięcia do dalszego końca deski.

Dla zadanej deski oraz listy cięć wyznacz kolejność ich wykonywania minimalizującą sumaryczny koszt zlecenia.

---

### Wejście
W pierwszej linii wejścia podano liczbę zestawów danych Z (1≤Z≤25). W pierwszej linii każdego zestawu podano dwie liczby całkowite: długość deski d oraz liczbę cięć n (1 ≤ d ≤ 10^9; 1 ≤ n ≤ 400). W drugie linii zestawu podano n parami różnych liczb całkowitych a1,…,an∈(0,d), będacych odległościami miejsc cięcia od lewego końca deski.

---

### Wyjście
Dla każdego zestawu danych wypisz dwie linie. Pierwsza powinna zawierać minimalny sumaryczny koszt wykonania zlecenia, zaś druga kolejność wykonywania cięć. Jeśli istnieje wiele rozwiązań, możesz wypisać dowolne z nich.

---

Przykład
Dla danych wejściowych:

> `2` <br>
  `6 2` <br>
  `1 3` <br>
  `10 3` <br>
  `8 4 6`
  
Możliwą poprawną odpowiedzią jest:

> `5` <br>
  `3 1` <br>
  `12` <br>
  `4 8 6`