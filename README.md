Train_O_Matic
--------------
--------------

System rezerwacji biletów kolejowych
------------------------------------

ZAŁÓŻCIE KAŻDY SWOJEGO BRANChA A POTEM RÓBCIE MERGA. 

Projekt z PO. Wykonałem szkielet aplikacji wraz z GUI, bazą danych oraz część funkcjonalości związanej z logiką biznesową. Pokazywałem diagramy klas dr. Myszorowi. Powiedział, że należy rozbić klasę Pasażer na mniejsze, wyspecjalizowane klasy. Zacząłem od klasy Ticket odpowiedzialnego za obsługę biletów wraz z wydrukiem i zapisem do bazy danych. W większości działa. Pozostało w niej do zrobienia:
1. Zapis do bazy wraz z usunięciem biletu z pamięci. 
2. wydruk z QStringa (QPrinterDialog i QPrinter) - 3-4 linie kodu. 
3. Uzupełnienie pól związanych ze stacjami wyjazdu i docelowej oraz godzinami i datami przyjazdu i odjazdu. Wg. wybór stacji będzie odbywał się ALBO na stronie SCHEDULE albo na stronie ROUTE gdzie zaznaczone dane będą dopisywane automatycznie do biletu. 


Zrobiłem też widok wraz widokiem z tabeli Connections w bazie. Należałoby zrobić obsługę grab-n-scroll i przebudować tabele. 
Na podstawie tych rozkładów należałoby robić:

strone HOME na której proponuje umieścić informację o trzech najbliższych połączeniach na danej stacji, updatowane co określony interwał czasu z QTimer .  

Stronę ROUTE gdzie można zaplanować trasę z konkretnymi stacjami tranzytowymi przez które użytkownik będzie chciał jechać. Powinno się umożliwic użytkownikowi zestawianie stacji ręcznie pamiętając o odpowiednim interfejsie, ponieważ: 

		### APLIKACJA BĘDZIE WSPOŁPRACOWAŁA Z PANELEM DOTYKOWYM ###

zostało Was 4 i jest akturat tyle roboty:
1. sekcja HOME, 
2. sekcja SCHEDULE, 
3. sekcja ROUTE,
4. sekcja TICKET (dokończyć) + API bazy danych dla księgowości. 

I appka gotowa. Mi to coś zajęło dwa popołudnia, choć wcześniej zmarnowałem 3 przez cholernego .NETa który (jak się okazało) nie posiada odpowiedniego wsparcia dla C++. 


[Qt Creator 4.5.0]
[Based on Qt 5.10.0 (MSVC 2015, 32 bit)]

[SQlite3]
do obsługi polecam SQLiteStudio
<https://sqlitestudio.pl/index.rvt>


Powodzenia
