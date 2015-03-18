inform-pl
=========
Polska wersja biblioteki **Inform 6** do pisania przygodowych gier tekstowych nazywanych również **interactive fiction**.


Poniżej znajduje się opisana krok po kroku procedura instalacji kompilatora i biblioteki, a także kompilacji przykładowej gry.

W przykładową skompilowaną grę można pograć tutaj: <a href="http://z-ski.pl/if/?story=alice.z5" target="_blank">Na drugą stronę lustra - interaktywny przykład</a>

Instalacja kompilatora i biblioteki
===================================

- Ściągnij kompilator w wersji 6.x ze strony http://www.inform-fiction.org/software/current.html. Są tam dostępne wersje dla różnych systemów operacyjnych, w tym Windows, OSX oraz Linux.

- W wybranym miejscu na dysku załóż katalog *Inform*, który posłuży jako bazowy, a następnie utwórz w nim podkatalogi na źródła oraz bibliotekę, tj. *Games* oraz *Lib*.

- Wypakuj, a następnie skopiuj plik wykonywalny kompilatora do głównego katalogu *Inform*.

- Ściągnij najnowszą wersję biblioteki inform-PL, a następnie umieść pliki biblioteki w katalogu *Lib* oraz źródła gier w katalogu *Games*.

Kompilacja przykładowej gry (wersja Windows)
============================================

- Przykład będzie dotyczyć kompilacji gry, której plik źródłowy znajduje się w katalogu *Games*. Tutaj konkretnie będzie to *alice.inf*.
- Uruchom wiersz polecenia i przejdź do katalogu głównego *Inform*, a następnie wpisz następujące polecenie:

**inform-631.exe -s +include_path=".\Lib\Base,.\Games" ".\Games\alice.inf"**

- Parametr **s** powoduje wyświetlenie podsumowania po zakończeniu kompilacji. **include_path** mówi kompilatorowi gdzie powinien szukać plików biblioteki.

- Po zatwierdzeniu klawiszem ENTER, gra zostanie skompilowana oraz wyświetli się podsumowanie.

Uruchomienie skompilowanej gry
==============================

- Skompilowana według powyższych wskazówek gra znajduje się w katalogu głównym *Inform*. Plik w tym konkretnym przypadku nosi nazwę: *alice.z5* i można go uruchomić za pomocą odpowiedniego tzw. interpretera.
- Niestety nie każdy interpreter jest w stanie poradzić sobie z poleceniami zawierajacymi polskie znaki diakrytyczne. Na MacOS X świetnie sprawdza się i doskonale działa <a target="_blank" href="http://www.logicalshift.co.uk/unix/zoom/">Zoom</a> Najlepszym interpreterem dla Windows jest obecnie <a target="_blank"  href="http://mirror.ifarchive.org/if-archive/infocom/interpreters/frotz/WindowsFrotzInstaller.exe">Frotz</a>.
- Gry napisane i skompilowane z wykorzystaniem polskiej biblioteki inform-pl świetnie działaja także z napisanym w JavaScript interpreterem <a href="https://github.com/curiousdannii/parchment/" target="_blank">Parchment</a>. Przykład działania można zobaczyc <a href="http://z-ski.pl/if/?story=alice.z5" target="_blank">tutaj</a>.
