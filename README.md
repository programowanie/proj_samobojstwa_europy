Program został już oceniony i zaliczony dnia 27.05.2016 r. na konsultacjach, nie udało mi się dołączyć do niego doxygena, wrzucam jego wyczyszczoną, ujednoliconą i poprawioną wersję.

# Samobójstwo Europy
Symulacja choroby rozprzestrzeniającej się po Europie. 

Choroba ma trzy podstawowe cechy:
- zaraźliwość (decyduje o tym, jak szybko wirus się rozprzestrzeniał)
- odporność (jaka jest odporność wirusa/pasożyta/bakterii na leczenie)
- szybkość postępowania choroby (jak szybko stan osoby zarażonej będzie się pogarszał, co doprowadzi do jej szybszego zgonu)
Podstawowe cechy wirusa są rozdysponowane za pomocą punktów, analogicznie z wyborem obywatelstwa pacjenta zero.

Każdy kraj także posiada swoje podstawowe cechy takie jak:
- transport/turystyka (im chętniej kraj jest uczęszczany, tym większa szansa, że choroba pojawi się w nim szybciej niż w pozostałych)
- postęp medycyny (jeśli w kraju medycyna będzie dobrze rozwinięta, to rozwój wirusa w danym państwie będzie wolniejszy)
- z kim graniczy (pomiędzy krajami, które graniczą ze sobą, zagrożenie rozwoju epidemii jest dużo większe)
Statystyki kraju odzwierciedlają z grubsza stan faktyczny. Dane są wczytywane z pliku zawierającym aktualne informacje pochodzące z internetu.

Szybkość rozwoju choroby zależy w bardzo dużym stopniu od jego cech, dużą rolę odgrywa także położenie, tzn. w krajach bardziej rozwiniętych wirus rozwija się wolniej. Jeśli wirus ma zbyt duży współczynnik szybkości postępowania choroby może bardzo szybko doprowadzić siebie do samozniszczenia - żywi nosiciele nie zdążą zarazić innych osób przed swoją śmiercią: dojdzie do sytuacji, gdy liczba zarażonych osiągnie 0.

Symulacja opiera się na użyciu prostych wzorów biorących pod uwagę szereg zależności. Przebieg symulacji został zbalansowany poprzez nadanie odpowiednich współczynników (factor).
Symulacja kończy się wraz ze śmiercią wszystkich zarażonych ludzi.