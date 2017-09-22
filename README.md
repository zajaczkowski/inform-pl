# inform-pl

Polska wersja biblioteki **Inform 6** przeznaczonej do tworzenia przygodowych gier tekstowych nazywanych również **interactive fiction**. Jest to rodzaj programów komputerowych, w których użytkownik posługuje się tekstem do komunikacji z programem i do wydawania poleceń fikcyjnej postaci, usytuowanej w wirtualnym świecie gry.

Poniżej znajduje się opisana krok po kroku procedura instalacji kompilatora i biblioteki, a także kompilacji przykładowej gry.

#### Instalacja kompilatora i biblioteki

- Ściągnij kompilator w wersji 6.x ze strony http://ifarchive.giga.or.at/indexes/if-archiveXinfocomXcompilersXinform6Xexecutables.html. Są tam dostępne wersje dla różnych systemów operacyjnych, w tym Windows, OSX oraz Linux.

- W wybranym miejscu na dysku załóż katalog *Inform*, który posłuży jako bazowy, a następnie utwórz w nim podkatalogi na źródła oraz bibliotekę, tj. *Games* oraz *Lib*.

- Wypakuj, a następnie skopiuj plik wykonywalny kompilatora do głównego katalogu *Inform*.

- Ściągnij najnowszą wersję biblioteki inform-PL, a następnie umieść pliki biblioteki w katalogu *Lib* oraz źródła gier w katalogu *Games*.

#### Kompilacja przykładowej gry

- Przykład będzie dotyczyć kompilacji gry, której plik źródłowy znajduje się w katalogu *Games*. Tutaj konkretnie będzie to *alice.inf*.
- Uruchom wiersz polecenia i przejdź do katalogu głównego *Inform*, a następnie wpisz następujące polecenie:

Windows: **inform-633.exe -s +include_path=".\Lib,.\Games" ".\Games\alice.inf"**

macOS: **./inform633_macosx -s +include_path="./Lib" "./Games/alice.inf"**

- Należy pamiętać, że numer wersji kompilatora może być inny. Parametr **s** powoduje wyświetlenie podsumowania po zakończeniu kompilacji. **include_path** mówi kompilatorowi gdzie powinien szukać plików biblioteki.

- Po zatwierdzeniu klawiszem ENTER, gra zostanie skompilowana oraz wyświetli się podsumowanie.

#### Uruchomienie skompilowanej gry

Skompilowana według powyższych wskazówek gra znajduje się w katalogu głównym *Inform*. Plik w tym konkretnym przypadku nosi nazwę: *alice.z5* i można go uruchomić za pomocą odpowiedniego tzw. *interpretera z-code*. 

Istnieje wiele takich programów, niestety nie każdy interpreter jest w stanie poradzić sobie z poleceniami zawierajacymi polskie znaki diakrytyczne. Problem nie występuje w systemie Windows, gdzie najlepszym i w pełni funkcjonalnym interpreterem jest <a target="_blank"  href="http://mirror.ifarchive.org/if-archive/infocom/interpreters/frotz/WindowsFrotzInstaller.exe">Frotz</a>.

Niestety gry napisane i skompilowane z wykorzystaniem polskiej biblioteki inform-pl NIE DZIAŁAJĄ z napisanym w JavaScript interpreterem <a href="https://github.com/curiousdannii/parchment/" target="_blank">Parchment</a>. Pomimo całości opartej na Unicode, Parchment nie potrafi zrozumieć polskich znaków w linii poleceń. Przyczyna błędu wciąż nie jest znana.

Niestety ten sam problem dotyczy interpreterów dla systemu macOS na iOS. Z przyczyn nieznanych nie odczytują one dobrze polskich znaków. Najpopularniejszy Frotz dla iOS również ma ten problem.
