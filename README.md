#inform-pl

Polska wersja biblioteki **Inform 6** przeznaczonej do tworzenia przygodowych gier tekstowych nazywanych również **interactive fiction**. Jest to rodzaj programów komputerowych, w których użytkownik posługuje się tekstem do komunikacji z programem i do wydawania poleceń fikcyjnej postaci, usytuowanej w wirtualnym świecie gry.

Poniżej znajduje się opisana krok po kroku procedura instalacji kompilatora i biblioteki, a także kompilacji przykładowej gry.

Skompilowane wersje gier demonstracyjnych można przetestować klikając w poniższe linki:
- <a href="http://z-ski.pl/alice" target="_blank">Na drugą stronę lustra</a>
- <a href="http://z-ski.pl/ruins" target="_blank">Ruiny</a>

####Instalacja kompilatora i biblioteki

- Ściągnij kompilator w wersji 6.x ze strony http://www.inform-fiction.org/software/current.html. Są tam dostępne wersje dla różnych systemów operacyjnych, w tym Windows, OSX oraz Linux.

- W wybranym miejscu na dysku załóż katalog *Inform*, który posłuży jako bazowy, a następnie utwórz w nim podkatalogi na źródła oraz bibliotekę, tj. *Games* oraz *Lib*.

- Wypakuj, a następnie skopiuj plik wykonywalny kompilatora do głównego katalogu *Inform*.

- Ściągnij najnowszą wersję biblioteki inform-PL, a następnie umieść pliki biblioteki w katalogu *Lib* oraz źródła gier w katalogu *Games*.

####Kompilacja przykładowej gry (w systemie Windows)

- Przykład będzie dotyczyć kompilacji gry, której plik źródłowy znajduje się w katalogu *Games*. Tutaj konkretnie będzie to *alice.inf*.
- Uruchom wiersz polecenia i przejdź do katalogu głównego *Inform*, a następnie wpisz następujące polecenie:

**inform-631.exe -s +include_path=".\Lib\Base,.\Games" ".\Games\alice.inf"**

- Parametr **s** powoduje wyświetlenie podsumowania po zakończeniu kompilacji. **include_path** mówi kompilatorowi gdzie powinien szukać plików biblioteki.

- Po zatwierdzeniu klawiszem ENTER, gra zostanie skompilowana oraz wyświetli się podsumowanie.

####Uruchomienie skompilowanej gry

Skompilowana według powyższych wskazówek gra znajduje się w katalogu głównym *Inform*. Plik w tym konkretnym przypadku nosi nazwę: *alice.z5* i można go uruchomić za pomocą odpowiedniego tzw. *interpretera z-code*. Istnieje wiele takich programów, niestety nie każdy interpreter jest w stanie poradzić sobie z poleceniami zawierajacymi polskie znaki diakrytyczne. Na MacOS X  sprawdza się i w miarę dobrze działa <a target="_blank" href="http://www.logicalshift.co.uk/unix/zoom/">Zoom</a> Najlepszym i w pełni funkcjonalnym interpreterem dla Windows jest bez wątpienia <a target="_blank"  href="http://mirror.ifarchive.org/if-archive/infocom/interpreters/frotz/WindowsFrotzInstaller.exe">Frotz</a>.

Gry napisane i skompilowane z wykorzystaniem polskiej biblioteki inform-pl świetnie działaja z napisanym w JavaScript interpreterem <a href="https://github.com/curiousdannii/parchment/" target="_blank">Parchment</a>. Przykład działania można zobaczyc <a href="http://z-ski.pl/alice" target="_blank">tutaj</a> lub <a href="http://z-ski.pl/ruiny" target="_blank">tutaj</a>.

Istnieją tez interpretery na urządzenia mobilne, niestety nie odczytują one dobrze polskich znaków (Frotz dla iOS ma ten problem). Dlatego w takich przypadkach lepiej jest uruchamiać wersję w przeglądarce internetowej.
