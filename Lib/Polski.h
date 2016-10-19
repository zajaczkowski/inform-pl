! ==============================================================================
!   POLSKI:  Language Definition File
!
!   Przeznaczony do uzywania z kompilatorem Inform 6.
!
!   Wersja 6/11/PL
!   Copyright Bartosz Zaj�czkowski 2011-2014
!       z mozliwosci� swobodnego korzystania.
!
!   Original 6/11 Library
!   Copyright Graham Nelson 1993-2004 but freely usable (see manuals)
!
! ==============================================================================

System_file;




! ------------------------------------------------------------------------------
!   Part I.   Preliminaries
! ------------------------------------------------------------------------------

!Constant EnglishNaturalLanguage;    ! Needed to keep old pronouns mechanism



! ------------------------------------------------------------------------------
! Kierunki �wiata na kompasie
! ------------------------------------------------------------------------------

Class   CompassDirection
  with  number 0,
        description [;
            if (location provides compass_look && location.compass_look(self)) rtrue;
            if (self.compass_look()) rtrue;
            L__M(##Look, 7, self);
        ],
        compass_look false,
  has   scenery;


Object Compass "kompas" has concealed;


#Ifndef WITHOUT_DIRECTIONS;

CompassDirection -> n_obj "p�noc",
                    with door_dir n_to, name 'pn//' 'polnoc', has female;

CompassDirection -> s_obj "po�udnie"
                    with door_dir s_to, name 'pd//' 'poludnie', has neuter;

CompassDirection -> e_obj "wsch�d"
                    with door_dir e_to, name 'w//' 'wschod';

CompassDirection -> w_obj "zach�d"
                    with door_dir w_to, name 'z//' 'zachod';

CompassDirection -> ne_obj "p�nocny-wsch�d"
                    with door_dir ne_to, name 'pnw';

CompassDirection -> nw_obj "p�nocny-zach�d"
                    with door_dir nw_to, name 'pnz';

CompassDirection -> se_obj "po�udniowy-wsch�d"
                    with door_dir se_to, name 'pdw';

CompassDirection -> sw_obj "po�udniowy-zach�d"
                    with door_dir sw_to, name 'pdz';

CompassDirection -> u_obj "g�ra"
                    with door_dir u_to, name 'g//' 'gora' 'gore' 'sufit' 'niebo';

CompassDirection -> d_obj "d�"
                    with door_dir d_to, name 'd//' 'dol' 'podloga' 'ziemia' 'spod';

#endif; ! WITHOUT_DIRECTIONS

CompassDirection -> in_obj "�rodek"
                    with door_dir in_to,
                    name 'srodek' 'wnetrze' 'srodka' 'wnetrza';
CompassDirection -> out_obj "zewn�trz"
                    with door_dir out_to, name 'zewnatrz';



! ------------------------------------------------------------------------------
!   Part II.   Vocabulary
! ------------------------------------------------------------------------------

Constant AGAIN1__WD     = 'powt�rz';
Constant AGAIN2__WD     = 'p//';
Constant AGAIN3__WD     = 'again';
Constant OOPS1__WD      = 'oops';
Constant OOPS2__WD      = 'o//';
Constant OOPS3__WD      = 'oops';
Constant UNDO1__WD      = 'undo';
Constant UNDO2__WD      = 'cofnij';
Constant UNDO3__WD      = 'undo';

Constant ALL1__WD       = 'wszystko';
Constant ALL2__WD       = 'each';
Constant ALL3__WD       = 'every';
Constant ALL4__WD       = 'rzeczy';
Constant ALL5__WD       = 'obie ';
Constant AND1__WD       = 'i//';
Constant AND2__WD       = 'i//';
Constant AND3__WD       = 'oraz';
Constant BUT1__WD       = 'opr�cz';   ! kogo, czego?
Constant BUT2__WD       = 'wyj�wszy'; ! kogo, co?
Constant BUT3__WD       = 'bez';      ! kogo, czego?
Constant ME1__WD        = 'mi';
Constant ME2__WD        = 'siebie';
Constant ME3__WD        = 'si�';
Constant OF1__WD        = 'of';
Constant OF2__WD        = 'of';
Constant OF3__WD        = 'of';
Constant OF4__WD        = 'of';
Constant OTHER1__WD     = 'another';
Constant OTHER2__WD     = 'other';
Constant OTHER3__WD     = 'other';
Constant THEN1__WD      = 'then';
Constant THEN2__WD      = 'then';
Constant THEN3__WD      = 'then';

Constant NO1__WD        = 'n//';
Constant NO2__WD        = 'nie';
Constant NO3__WD        = 'no';
Constant YES1__WD       = 't//';
Constant YES2__WD       = 'tak';
Constant YES3__WD       = 'yes';

Constant AMUSING__WD    = 'amusing';
Constant FULLSCORE1__WD = 'wynik';
Constant FULLSCORE2__WD = 'pe�ny';
Constant QUIT1__WD      = 'q//';
Constant QUIT2__WD      = 'zako�cz';
Constant RESTART__WD    = 'zrestartuj';
Constant RESTORE__WD    = 'za�aduj';

! ------------------------------------------------------------------------------

Array LanguagePronouns table

  ! word        possible GNAs                   connected
  !             to follow:                      to:
  !             a     i
  !             s  p  s  p
  !             mfnmfnmfnmfn

    'tego'   $$001000111000                    NULL
    'jego'   $$100000000000                    NULL
    'jej'    $$010000000000                    NULL
    'ich'    $$000111000111                    NULL;

! ------------------------------------------------------------------------------

Array LanguageDescriptors table

  ! word        possible GNAs   descriptor      connected
  !             to follow:      type:           to:
  !             a     i
  !             s  p  s  p
  !             mfnmfnmfnmfn

    'my'      $$111111111111    POSSESS_PK      0
    'this'    $$111111111111    POSSESS_PK      0
    'these'   $$000111000111    POSSESS_PK      0
    'that'    $$111111111111    POSSESS_PK      1
    'those'   $$000111000111    POSSESS_PK      1
    'his'     $$111111111111    POSSESS_PK      'him'
    'her'     $$111111111111    POSSESS_PK      'her'
    'their'   $$111111111111    POSSESS_PK      'them'
    'its'     $$111111111111    POSSESS_PK      'it'
    'the'     $$111111111111    DEFART_PK       NULL
    'a//'     $$111000111000    INDEFART_PK     NULL
    'an'      $$111000111000    INDEFART_PK     NULL
    'some'    $$000111000111    INDEFART_PK     NULL
    'lit'     $$111111111111    light           NULL
    'lighted' $$111111111111    light           NULL
    'unlit'   $$111111111111    (-light)        NULL;

! ------------------------------------------------------------------------------

Array LanguageNumbers table
    'jeden' 1 'dwa' 2 'trzy' 3 'cztery' 4 'pi��' 5
    'sze��' 6 'siedem' 7 'osiem' 8 'dziewi��' 9 'dziesi��' 10
    'jedena�cie' 11 'dwana�cie' 12 'trzyna�cie' 13 'czterna�cie' 14 'pi�tna�cie' 15
    'szesna�cie' 16 'siedemna�cie' 17 'osiemna�cie' 18 'dziewi�tna�cie' 19 'dwadzie�cia' 20;










! ------------------------------------------------------------------------------
!   Part III.   T�umaczenie
! ------------------------------------------------------------------------------

[ LanguageToInformese;

  ClearPolishDirections();

  ! GetRidOfPolishLetters();

];



! ------------------------------------------------------------------------------
! ClearPolishDirections();
!
! Procedura ClearPolishDirections() robi porz�dek z nazwami kierunk�w �wiata
! zanim jeszcze parser zacznie analizowa� polecenie. Jest to niezb�dne, poniewa�
! kompilator ma problemy z rozr�nianiem nazw d�u�szych ni� osiem znak�w.
! Problem jest szczeg�lnie dotktliwy w przypadkach gdy pierwsze osiem
! znak�w jest takie same, a tak w�asnie jest w j�zyku polskim. Chodzi o cztery
! przypadki: p�nocny-wsch�d, p�nocny-zach�d, po�udniowy-wsch�d
! i po�udniowy zach�d. D�ugie nazwy kierunk�w zostaj� zast�pione odpowiadaj�cymi
! im skr�tami z kompasu, co wyklucza ewentualn� pomy�k� interpretera.
! ------------------------------------------------------------------------------

[ ClearPolishDirections x y at word;

#ifdef TARGET_ZCODE;

  for (x=0:x<parse->1:x++)  ! loop through every word
    {
    word = parse-->(x*2+1);
    at = parse->(x*4+5);

#ifnot; ! TARGET_GLULX;

  for (x=0:x<parse-->0:x++)
    {
    word = parse-->(x*3+1);
    at = parse-->(x*3+3);

#endif; ! TARGET_;

    ! po�udniowy-zach�d -> PDZ
    if (word == 'po�udniowy-zach�d' && buffer->(at+10) =='-' && buffer->(at+11) == 'z')
      {
        for (y=at:y<at+17:y++) {buffer->(y) = ' ';};
        buffer->(at+0) = 'p';
        buffer->(at+1) = 'd';
        buffer->(at+2) = 'z';
        break;
      };

    ! p�nocny-zach�d -> PNZ
    if (word == 'p�nocny-zach�d' && buffer->(at+8) =='-' && buffer->(at+9) == 'z')
      {
      for (y=at:y<at+15:y++) {buffer->(y) = ' ';};
        buffer->(at+0) = 'p';
        buffer->(at+1) = 'n';
        buffer->(at+2) = 'z';
        break;
      };

    ! po�udniowy-wsch�d -> PDW
    if (word == 'po�udniowy-wsch�d' && buffer->(at+10) =='-' && buffer->(at+11) == 'w')
      {
      for (y=at:y<at+17:y++) {buffer->(y) = ' ';};
        buffer->(at+0) = 'p';
        buffer->(at+1) = 'd';
        buffer->(at+2) = 'w';
        break;
      };

    ! p�nocny-wsch�d -> PNW
    if (word == 'p�nocny-wsch�d' && buffer->(at+8) =='-' && buffer->(at+9) == 'w')
      {
      for (y=at:y<at+15:y++) {buffer->(y) = ' ';};
        buffer->(at+0) = 'p';
        buffer->(at+1) = 'n';
        buffer->(at+2) = 'w';
        break;
      };

    }; ! koniec p�tli
]; ! koniec ClearPolishDirections



! ---------------------------------------------------------------------------
! Deklinacja rzeczownik�w
!
! Ka�dy obiekt powinien mie� zdefiniowane dodatkowe w�asno�ci (property)
! zawieraj�ce informacje o jego nazwie prawid�owo zdefiniowanej w j�zyku
! polskim. W tym celu polska biblioteka korzysta z dziesi�ciu dodatkowych
! w�asno�ci (property), kt�rych dzia�ania staje si� jasne po zapoznaniu si�
! z poni�szym przyk�adem obiektu.
! U�yty w grze "�elazny miecz" powinien zosta� zdefiniowany nast�puj�co:
!
! Object -> miecz "�elazny miecz",
!   name '�elazny' 'miecz',
!   name_dop '�elaznego' 'miecza',       ! tu s� nazwy interpretowane i tutaj
!   name_cel '�elaznemu' 'mieczowi',     ! powinny zosta� wymienione wszelkie
!   name_bie '�elazny' 'miecz',          ! synonimy.
!   name_nar '�elaznym' 'mieczem',
!   name_mie '�elaznym' 'mieczu',
!   desc_dop "�elaznego miecza",         ! tu s� nazwy wy�wietlane, wystarczy
!   desc_cel "�elaznemu mieczowi",       ! odmieni� nazw� w�asn� obiektu
!   desc_bie "�elazny miecz",
!   desc_nar "�elaznym mieczem",
!   desc_mie "�elaznym mieczu";

! Je�li interpreter nie znajdzie w definicji obiektu nazwy w odpowiedniej
! formie (desc_dop, desc_cel, itp.), zostanie wy�wietlona nazwa w formie
! mianownika.
! ------------------------------------------------------------------------------



[ dop obj; if (obj.desc_dop) PrintOrRun(obj, desc_dop, 1); else print (name) obj;];
[ cel obj; if (obj.desc_cel) PrintOrRun(obj, desc_cel, 1); else print (name) obj;];
[ bie obj; if (obj.desc_bie) PrintOrRun(obj, desc_bie, 1); else print (name) obj;];
[ nar obj; if (obj.desc_nar) PrintOrRun(obj, desc_nar, 1); else print (name) obj;];
[ mie obj; if (obj.desc_mie) PrintOrRun(obj, desc_mie, 1); else print (name) obj;];



! --------------------------------------------------------------------------------

[ dopelniacznoun; ! KOGO?, CZEGO?
  parser_inflection = name_dop;
  return ParseToken(ELEMENTARY_TT, NOUN_TOKEN);
];

! --------------------------------------------------------------------------------

[ celowniknoun;
  parser_inflection = name_cel;
  return ParseToken(ELEMENTARY_TT, NOUN_TOKEN);
];
[ celownikcreature;
  parser_inflection = name_cel;
  return ParseToken(ELEMENTARY_TT, CREATURE_TOKEN);
];

! --------------------------------------------------------------------------------

[ bierniknoun;
  parser_inflection = name_bie;
  return ParseToken(ELEMENTARY_TT, NOUN_TOKEN);
];
[ biernikheld;
  parser_inflection = name_bie;
  return ParseToken(ELEMENTARY_TT, HELD_TOKEN);
];
[ biernikcreature;
  parser_inflection = name_bie;
  return ParseToken(ELEMENTARY_TT, CREATURE_TOKEN);
];
[ biernikmulti;
  parser_inflection = name_bie;
  return ParseToken(ELEMENTARY_TT, MULTI_TOKEN);
];
[ biernikmultiheld;
  parser_inflection = name_bie;
  return ParseToken(ELEMENTARY_TT, MULTIHELD_TOKEN);
];
[ biernikmultiexcept;
  parser_inflection = name_bie;
  return ParseToken(ELEMENTARY_TT, MULTIEXCEPT_TOKEN);
];
[ biernikmultiinside;
  parser_inflection = name_bie;
  return ParseToken(ELEMENTARY_TT, MULTIINSIDE_TOKEN);
];

! --------------------------------------------------------------------------------

[ narzedniknoun;
  parser_inflection = name_nar;
  return ParseToken(ELEMENTARY_TT, NOUN_TOKEN);
];
[ narzednikheld;
  parser_inflection = name_nar;
  return ParseToken(ELEMENTARY_TT, HELD_TOKEN);
];

! --------------------------------------------------------------------------------

[ miejscowniknoun;
  parser_inflection = name_mie;
  return ParseToken(ELEMENTARY_TT, NOUN_TOKEN);
];










! ------------------------------------------------------------------------------
!   Part IV.   Printing
! ------------------------------------------------------------------------------

Constant LanguageAnimateGender   = male;
Constant LanguageInanimateGender = neuter;

Constant LanguageContractionForms = 2;     ! English has two:
                                           ! 0 = starting with a consonant
                                           ! 1 = starting with a vowel

[ LanguageContraction text;
    if (text->0 == 'a' or 'e' or 'i' or 'o' or 'u'
                or 'A' or 'E' or 'I' or 'O' or 'U') return 1;
    return 0;
];

Array LanguageArticles -->

 !   Contraction form 0:     Contraction form 1:
 !   Cdef   Def    Indef     Cdef   Def    Indef

     "The " "the " "a "      "The " "the " "an "          ! Articles 0
     "The " "the " "some "   "The " "the " "some ";       ! Articles 1

                   !             a           i
                   !             s     p     s     p
                   !             m f n m f n m f n m f n

Array LanguageGNAsToArticles --> 0 0 0 1 1 1 0 0 0 1 1 1;

! ------------------------------------------------------------------------------

[ LanguageDirection d;
    switch (d) {
      n_to:    print "p�noc";
      s_to:    print "po�udnie";
      e_to:    print "wsch�d";
      w_to:    print "zach�d";
      ne_to:   print "p�nocny-wsch�d";
      nw_to:   print "p�nocny-zach�d";
      se_to:   print "po�udniowy-wsch�d";
      sw_to:   print "po�udniowy-zach�d";
      u_to:    print "g�ra";
      d_to:    print "d�";
      in_to:   print "do �rodka";
      out_to:  print "na zewn�trz";
      default: return RunTimeError(9,d);
    }
];

! ------------------------------------------------------------------------------

[ LanguageNumber n f;
    if (n == 0)    { print "zero"; rfalse; }
    if (n < 0)     { print "minus "; n = -n; }
    if (n >= 1000) {
    if (n < 2000) { print "tysi�c"; }
    else  {
      LanguageNumber(n/1000);
      if (n<5000) print " tysi�ce"; else print " tysi�cy";
      }
    n = n%1000; f = 1;
    }
    if (n >= 100)  {
        if (f == 1) print " ";

  switch (n/100) {
    1:  print "sto";
    2:  print "dwie�cie";
        3:  print "trzysta";
        4:  print "czterysta";
        5:  print "pi��set";
        6:  print "sze��set";
        7:  print "siedemset";
        8:  print "osiemset";
        9:  print "dziewi��set";
    }

        n = n%100; f = 1;
    }
    if (n == 0) rfalse;
    if (f == 1) print " ";

    switch (n) {
      1:    print "jeden";
      2:    print "dwa";
      3:    print "trzy";
      4:    print "cztery";
      5:    print "pi��";
      6:    print "sze��";
      7:    print "siedem";
      8:    print "osiem";
      9:    print "dziewi��";
      10:   print "dziesi��";
      11:   print "jedena�cie";
      12:   print "dwana�cie";
      13:   print "trzyna�cie";
      14:   print "czterna�cie";
      15:   print "pi�tna�cie";
      16:   print "szesna�cie";
      17:   print "siedemna�cie";
      18:   print "osiemna�cie";
      19:   print "dziewi�tna�cie";
      20 to 99: switch (n/10) {
        2:  print "dwadzie�cia";
        3:  print "trzydzie�ci";
        4:  print "czterdzie�ci";
        5:  print "pi��dziesi�t";
        6:  print "sze��dziesi�t";
        7:  print "siedemdziesi�t";
        8:  print "osiemdziesi�t";
        9:  print "dziewi��dziesi�t";
        }
       if (n%10 ~= 0) print " ", (LanguageNumber) n%10;
    }
];

! ------------------------------------------------------------------------------

[ LanguageTimeOfDay hours mins i;
    i = hours%12;
    if (i == 0) i = 12;
    if (i < 10) print " ";
    print i, ":", mins/10, mins%10;
    if ((hours/12) > 0) print " po po�udniu"; else print " rano";
];

! ------------------------------------------------------------------------------

[ LanguagePreposition i;
  switch (i)
    {

    ! Ask:
      'pytaj', 'spytaj', 'zapytaj': return 1;
    ! Drink:
      'napij': return 1;
      'po��': return 2;
      'wsta�','powsta�': return 1;
      'prze�pij','zdrzemnij': return 1;
      'kop': return 2;
    } rfalse;
];




! ------------------------------------------------------------------------------
! QuestionVerb();
!
! Je�li interpreter nie b�dzie potrzebowa� dodatkowych informacji, zada graczowi
! pytanie o podanie dodatkowych informacji. W j�zyku polskim spos�b zadania tego
! pytania b�dzie zale�e� od u�ywanego czasownika. Procedura QuestionVerb() ma za
! zadanie rozwi�za� ten problem.
!
! Dla porz�dku polskie czasowniki zosta�y u�o�one wg angielskich odpowiednik�w.
! ------------------------------------------------------------------------------


[ QuestionVerb q;

  q = verb_word;

  switch (q)
    {
      'dmij', 'zadmij', 'dmuchnij', 'dmuchaj':            print "W co";
      'czekaj','poczekaj','zaczekaj':                     print "Na co";
      'ciagnij', 'pociagnij':                             print "Co";
      'czytaj', 'przeczytaj':                             print "Co";
      'daj', 'oddaj':                                     print "Komu";
      'dotknij':                                          print "Co";
      'idz', 'biegnij', 'pobiegnij', 'pojdz':             print "Dok�d";
      'kop':                                              print "Gdzie";
      'kup', 'zakup':                                     print "Co";
      'napelnij':                                         print "Co";
      'napij':                                            print "Czego";
      'obejrzyj','zobacz':                                print "Co";
      'potrzyj':                                          print "Co";
      'odblokuj':                                         print "Co";
      'odloz':                                            print "Co";
      'odpowiedz':                                        print "Co"; ! ewentualnie mog�o by by� 'Komu'
      'oproznij':                                         print "Co";
      'otworz':                                           print "Co";
      'pchnij', 'popchnij', 'przesun':                    print "Co";
      'plyn', 'poplyn':                                   print "Dok�d";
      'pocaluj', 'caluj', 'przytul', 'usciskaj':          print "Kogo";
      'podpal':                                           print "Co";
      'pokaz':                                            print "Co";
      'poloz':                                            print "Co"; ! ewentualnie mog�o by by� 'Gdzie' 'Na czym' itp.
      'pomachaj', 'machaj':                               print "Czym";
      'popros','pros':                                    print "Kogo"; ! ewentualnie mog�o by by� 'O co'
      'postaw', 'ustaw':                                  print "Co";
      'potrzyj', 'przetrzyj', 'wytrzyj':                  print "Co";
      'powachaj','w�chaj':                                print "Co";
      'powiedz':                                          print "Co";
      'przekrec', 'dokrec', 'obroc', 'odkrec', 'zakrec':  print "Co";
      'przenies', 'przeloz':                              print "Co";
      'przeskocz':                                        print "Nad czym";
      'przeszukaj':                                       print "Co";
      'przetnij', 'tnij', 'przekroj', 'kroj':             print "Co";
      'przyjrzyj':                                        print "Czemu"; ! ewentualnie mog�o by by� 'Komu'
      'rzuc':                                             print "Co";
      'schowaj':                                          print "Co";
      'siadz', 'usiadz':                                  print "Gdzie";
      'sluchaj', 'posluchaj':                             print "Czego";
      'spojrz', 'popatrz':                                print "Na co";
      'sprawdz', 'skonsultuj':                            print "Co";
      'sprobuj', 'skosztuj':                              print "Co";
      'szukaj', 'odszukaj', 'poszukaj':                   print "Co";
      'scisnij', 'zgniec':                                print "Co";
      'uruchom':                                          print "Co";
      'wdrap', 'wespnij':                                 print "Na co";
      'wez', 'zabierz', 'podnies':                        print "Co";
      'wejdz':                                            print "Gdzie";
      'wlacz', 'zapal':                                   print "Co";
      'wloz':                                             print "Co";
      'wrzuc':                                            print "Co";
      'wsiadz':                                           print "Do czego";
      'wstan':                                            print "Z czego";
      'wyjdz':                                            print "Dok�d";
      'wyjmij', 'wyciagnij':                              print "Co";
      'wylacz', 'zgas':                                   print "Co";
      'wypij':                                            print "Co";
      'wyrzuc':                                           print "Co";
      'wysiadz':                                          print "Z czego";
      'zaatakuj', 'zniszcz':                              print "Co";
      'zabij':                                            print "Co";
      'uderz', 'walnij', 'kopnij':                        print "Co";
      'zablokuj':                                         print "Co";
      'zajrzyj':                                          print "Gdzie";
      'zaloz', 'ubierz':                                  print "Co";
      'zamknij':                                          print "Co";
      'zapytaj', 'pytaj', 'spytaj':                       print "O co";
      'zastanow':                                         print "Nad czym";
      'zaspiewaj', 'spiewaj':                             print "Co";
      'zjedz', 'polknij', 'ugryz':                        print "Co";
      'znajdz':                                           print "Co";
      'zdejmij':                                          print "Co";
      'zejdz':                                            print "Sk�d";
      'zostaw':                                           print "Co";
      'zsiadz':                                           print "Z czego";

    default: print "Co";
  };

  print " chcesz ";

];

! ------------------------------------------------------------------------------
! Formy bezokolicznika stosowanych czasownik�w
! ------------------------------------------------------------------------------

[ LanguageVerb i;
  switch (i)
    {
    'i//','spis':               print "obejrze� spis posiadanych przez ciebie przedmiot�w";
    ! 'z//':                    print "wait";


    'dmij', 'zadmij':                         print "zad��";
    'dmuchnij', 'dmuchaj':                    print "dmuchn��";
    'czekaj','poczekaj','zaczekaj':           print "poczeka�";
    'ciagnij', 'pociagnij':                   print "poci�gn��";
    'czytaj', 'przeczytaj':                   print "przeczyta�";
    'daj', 'oddaj':                           print "da�";
    'dotknij':                                print "dotkn��";
    'idz':                                    print "p�j��";
      'biegnij':                              print "biec";
      'pobiegnij':                            print "pobiec";
      'pojdz':                                print "p�j��";
    'kop':                                    print "kopa�";
    'kup','zakup':                            print "kupi�";
    'napelnij':                               print "nape�ni�";
    'napij':                                  print "si� napi�"; ! szyk przestawny!
    'obejrzyj','zobacz':                      print "obejrze�";
    'odblokuj':                               print "odblokowa�"; ! w znaczeniu 'Unlock'
    'odloz':                                  print "od�o�y�";
    'odpowiedz':                              print "odpowiedzie�";
    'oproznij':                               print "opr�ni�";
    'otworz':                                 print "otworzy�"; ! w znaczeniu 'Open' oraz 'Unlock'
    'pchnij':                                 print "pchn��";
      'popchnij':                             print "popchn��";
      'przesun':                              print "przesun��";
    'plyn':                                   print "p�yn��";
      'poplyn':                               print "pop�yn��";
    'caluj', 'pocaluj':                       print "poca�owa�";
      'przytul':                              print "przytuli�";
      'usciskaj':                             print "u�ciska�";
    'podpal':                                 print "podpali�";
    'pokaz':                                  print "pokaza�";
    'poloz':                                  print "po�o�y�";
    'pomachaj', 'machaj':                     print "pomacha�";
    'pomodl','modl':                          print "pomodli�";
    'pomysl','mysl':                          print "pomy�le�";
    'popros','pros':                          print "poprosi�";
    'postaw':                                 print "postawi�";
      'ustaw':                                print "ustawi�";
    'potrzyj':                                print "potrze�";
      'przetrzyj':                            print "przetrze�";
      'wytrzyj':                              print "wytrze�";
    'powachaj','w�chaj':                      print "pow�cha�";
    'powiedz':                                print "powiedzie�";
    'przekrec':                               print "przekr�ci�";
      'dokrec':                               print "dokr�ci�";
      'obroc':                                print "obr�ci�";
      'odkrec':                               print "odkr�ci�";
      'zakrec':                               print "zakr�ci�";
    'przenies':                               print "przenie��";
      'przeloz':                              print "prze�o�y�";
    'przeskocz':                              print "przeskoczy�";
    'przeszukaj':                             print "przeszuka�";
    'przepros':                               print "przeprosi�";
    'przespij':                               print "przespa�";
      'zdrzemnij':                            print "zdrzemn��";
    'przetnij', 'tnij':                       print "przeci��";
    'przekroj', 'kroj':                       print "przekroi�";
    'przyjrzyj':                              print "si� przyjrze�"; ! szyk przestawny!
    'rzuc':                                   print "rzuci�";
    'schowaj':                                print "schowa�";
    'siadz', 'usiadz':                        print "usi���";
    'sluchaj', 'posluchaj':                   print "pos�ucha�";
    'spojrz':                                 print "spojrze�";
      'popatrz':                              print "popatrze�";
    'sprawdz':                                print "sprawdzi�";
      'skonsultuj':                           print "skonsultowa�";
    'sprobuj':                                print "spr�bowa�";
      'skosztuj':                             print "skosztowa�";
    'szukaj', 'odszukaj', 'poszukaj':         print "poszuka�";
    'scisnij':                                print "�cisn��";
      'zgniec':                               print "zgnie��";
    'uruchom':                                print "uruchomi�";
    'wdrap':                                  print "si� wdrapa�"; ! szyk przestawny!
      'wespnij':                              print "si� wspi��"; ! szyk przestawny!
    'wez':                                    print "wzi��";
      'zabierz':                              print "zabra�";
      'podnie�':                              print "podnie��";
    'wejdz':                                  print "wejd�";
    'wlacz':                                  print "w��czy�";
      'zapal':                                print "zapali�";
    'wloz':                                   print "w�o�y�";
    'wrzuc':                                  print "wrzuci�";
    'wsiadz':                                 print "wsi���";
    'wstan':                                  print "wsta�";
    'wyjsc':                                  print "wyj��";
    'wyjmij':                                 print "wyj��";
      'wyciagnij':                            print "wyci�gn��";
    'wylacz':                                 print "wy��czy�";
      'zgas':                                 print "zgasi�";
    'wypij':                                  print "wypi�";
    'wyrzuc':                                 print "wyrzuci�";
    'wysiadz':                                print "wysi���";
    'zaatakuj':                               print "zaatakowa�";
      'zniszcz':                              print "zniszczy�";
    'zabij':                                  print "zabi�";
    'uderz':                                  print "uderzy�";
      'walnij':                               print "waln��";
      'kopnij':                               print "kopn��";
    'zablokuj':                               print "zablokowa�";
    'zajrzyj':                                print "zajrzyj";
    'zaloz':                                  print "za�o�y�";
      'ubierz':                               print "ubra�";
    'zamknij':                                print "zamkn��";
    'zapytaj', 'pytaj', 'spytaj':             print "zapyta�";
    'zastanow':                               print "si� zastanowi�"; ! szyk przestawny!
    'zaspiewaj', 'spiewaj':                   print "za�piewa�";
    'zjedz':                                  print "zje��";
      'polknij':                              print "po�kn��";
      'ugryz':                                print "ugry��";
    'znajdz':                                 print "znale��";
    'zdejmij':                                print "zdj��";
    'zejdz':                                  print "zej��";
    'zostaw':                                 print "zostawi�";
    'zsiadz':                                 print "zsi���";

    !   Czasowniki dodatkowe, kt�re nie z� zdefiniowane w podstawowym zestawie
    'policz': print "policzy�";   ! pochodzi z advent.inf
    'sfotografuj': print "sfotografowa�"; ! pochodzi z ruins.inf

    default: rfalse;



  !
  ! Pomini�te czasowniki...
  !    - zastan�w si�
  !

  }
  rtrue;

];





! ----------------------------------------------------------------------------
!  LanguageVerbIsDebugging is called by SearchScope.  It should return true
!  if word w is a debugging verb which needs all objects to be in scope.
! ----------------------------------------------------------------------------

#Ifdef DEBUG;
[ LanguageVerbIsDebugging w;
    if (w == 'purloin' or 'tree' or 'abstract'
                       or 'gonear' or 'scope' or 'showobj')
        rtrue;
    rfalse;
];
#Endif;

! ----------------------------------------------------------------------------
!  LanguageVerbLikesAdverb is called by PrintCommand when printing an UPTO_PE
!  error or an inference message.  Words which are intransitive verbs, i.e.,
!  which require a direction name as an adverb ('walk west'), not a noun
!  ('I only understood you as far as wanting to touch /the/ ground'), should
!  cause the routine to return true.
! ----------------------------------------------------------------------------

[ LanguageVerbLikesAdverb w;

  ! nie ma zastosowania w j�zyku polskim - zostawione na wszelki wypadek

    if (w == 'look' or 'go' or 'push' or 'walk')
        rtrue;
    rfalse;
];

! ----------------------------------------------------------------------------
!  LanguageVerbMayBeName is called by NounDomain when dealing with the
!  players reply to a "Which do you mean, the short stick or the long
!  stick?" prompt from the parser. If the reply is another verb (for example,
!  LOOK) then then previous ambiguous command is discarded /unless/
!  it is one of these words which could be both a verb /and/ an
!  adjective in a 'name' property.
! ----------------------------------------------------------------------------

[ LanguageVerbMayBeName w;

  ! nie ma zastosowania w j�zyku polskim - zostawione na wszelki wypadek

    if (w == 'long' or 'short' or 'normal'
                    or 'brief' or 'full' or 'verbose')
        rtrue;
    rfalse;
];


Constant NKEY__TX       = "N = nast�pny temat";
Constant PKEY__TX       = "P = poprzedni temat";
Constant QKEY1__TX      = "Q = powr�t do gry";
Constant QKEY2__TX      = "Q = poprzednie menu";
Constant RKEY__TX       = "RETURN = przeczytaj";

Constant NKEY1__KY      = 'N';
Constant NKEY2__KY      = 'n';
Constant PKEY1__KY      = 'P';
Constant PKEY2__KY      = 'p';
Constant QKEY1__KY      = 'Q';
Constant QKEY2__KY      = 'q';

Constant SCORE__TX      = "Wynik: ";
Constant MOVES__TX      = "Ruchy: ";
Constant TIME__TX       = "Czas: ";
Constant CANTGO__TX     = "Nie mo�esz i�� w tym kierunku.";
Constant FORMER__TX     = "your former self";
Constant YOURSELF__TX   = "Ty";
Constant YOU__TX        = "You";
Constant DARKNESS__TX   = "Ciemno��";

Constant THOSET__TX     = "jakie� rzeczy";
Constant THAT__TX       = "tamto";
Constant OR__TX         = " lub ";
Constant OR2__TX        = " czy ";     ! dodanie tej opcji wymaga�o zmiany parsera

Constant NOTHING__TX    = "nic";
Constant IS__TX         = " jest";
Constant ARE__TX        = " s�";
Constant IS2__TX        = "jest ";
Constant ARE2__TX       = "s� ";
Constant AND__TX        = " oraz ";
Constant WHOM__TX       = "whom ";
Constant WHICH__TX      = "which ";
Constant COMMA__TX      = ", ";




! ------------------------------------------------------------------------------
! Procedura wy�wietlaj�ca pierwsz� liter� nazwy obiektu z du�ej litery.
! W j�zyku polskim nie ma rodzajnik�w okre�lonych i nieokre�lonych, dlatego
! bez tej procedury zdania zaczynaj�ce si� od nazwy obiektu zaczyna�y by
! si� z ma�ej litery (nieelegancko) lub trzeba by�o by konstruowa� niepotrzebne
! konstrukcje s�owne.
! ------------------------------------------------------------------------------

Array name_buffer->64;
[ Cname obj i st;

  name_buffer-->0 = 0;
  @output_stream 3 name_buffer;
  print (name) obj;
  @output_stream -3;

  for (:i < (name_buffer-->0): i++ )
  {
      if (i == 0)
        {

              ! Przy konwersji ma�ej litery na du�� trzeba pami�ta� o polskich znakach.
              ! Dla polskich znak�w w standardzie ISO-8859-2 przesuni�cie wynosi 40 i 41...
              ! Kody znak�w s� dost�pne na: http://www.firthworks.com/roger/informfaq/aa20.html

              st = 0;

            if (name_buffer->(i+2) >= 97 && name_buffer->(i+2) <= 122) st = 32;
            if (name_buffer->(i+2) >= 195 && name_buffer->(i+2) <= 170) st = 40;
            if (name_buffer->(i+2) >= 171 && name_buffer->(i+2) <= 235) st = 41;

            print (char) name_buffer->(i+2) - st;
      }

        else print (char) name_buffer->(i+2);


  }

];




! ------------------------------------------------------------------------------
! Procedury do wy�wietlania odpowiedniej formy czasownik�w "by�" i "mie�".
! ------------------------------------------------------------------------------

[ JestLubSa obj;
    if (obj has pluralname || obj == player) print "s�"; else print "jest";
];

[ StoiLubStoja obj;
    if (obj has pluralname || obj == player) print "stoj�"; else print "stoi";
];

[ MaLubMaja obj;
    if (obj has pluralname) { print "maj�"; return; }
    print "ma";
];




! ------------------------------------------------------------------------------
! Procedury do wy�wietlania odpowiedniej formy "kt�ry".
! ------------------------------------------------------------------------------


[ KtoryKtoraKtore obj;
    if (obj has pluralname) {print "kt�re"; return; };
            if (obj has female)       { print "kt�ra"; return; }
        else
            if (obj hasnt neuter) { print "kt�ry"; return; } else { print "kt�re";return;};
];
[ KtorymKtorejKtorych obj;
    if (obj has pluralname) {print "kt�rych"; return; };
            if (obj has female)       { print "kt�rej"; return; }
        else
            if (obj hasnt neuter) { print "kt�rym"; return; } else { print "kt�rym";return;};
];




! ------------------------------------------------------------------------------
! Procedury wy�wietlaj�ce odpowiednia form� najcz�ciej u�ywanych przydawek.
! ------------------------------------------------------------------------------

[ JestOddany obj;
    if (obj has pluralname)       { print "oddane"; return; }
        if (obj has female)       { print "oddana"; return; }
        else
            if (obj hasnt neuter) { print "oddany"; return; }
    print "wy��czone";
];

[ JestOtwarty obj;
    if (obj has pluralname)       { print "otwarte"; return; }
        if (obj has female)       { print "otwarta"; return; }
        else
            if (obj hasnt neuter) { print "otwarty"; return; }
    print "otwarte";
];

[ JestPrzytwierdzony obj;
    if (obj has pluralname) {
    print "Nie jeste� w stanie ich przesun��."; return;} else
        print "Nie jeste� w stanie";
            if (obj has female)       { print " przesun�� ", (dop) obj,"."; return; }
        else
            if (obj hasnt neuter) { print " przesun��", (dop) obj,"."; return; } else { print " przesun�� ", (dop) obj,".";return;};
];

[ JestPusty obj;
    if (obj has pluralname)       { print "puste"; return; }
        if (obj has female)       { print "pusta"; return; }
        else
            if (obj hasnt neuter) { print "pusty"; return; }
    print "puste";
];

[ JestSmaczny obj;
    if (obj has pluralname)       { print "S� ca�kiem smaczne."; return; }
        if (obj has female)       { print "Jest ca�kiem smaczna."; return; }
        else
            if (obj hasnt neuter) { print "Jest ca�kiem smaczny."; return; }
    print "Jest ca�kiem smaczne.";
];

[ JestUbrany obj;
    if (obj has pluralname)       { print "ubrane"; return; }
        if (obj has female)       { print "ubrana"; return; }
        else
            if (obj hasnt neuter) { print "ubrany"; return; }
    print "ubrane";
];

[ JestWlaczony obj;
    if (obj has pluralname)       { print "w��czone"; return; }
        if (obj has female)       { print "w��czona"; return; }
        else
            if (obj hasnt neuter) { print "w��czony"; return; }
    print "w��czone";
];

[ JestWylaczony obj;
    if (obj has pluralname)       { print "wy��czone"; return; }
        if (obj has female)       { print "wy��czona"; return; }
        else
            if (obj hasnt neuter) { print "wy��czony"; return; }
    print "wy��czone";
];

[ JestZagubiony obj;
    if (obj has pluralname)       { print "zagubione"; return; }
        if (obj has female)       { print "zagubiona"; return; }
        else
            if (obj hasnt neuter) { print "zagubiony"; return; }
    print "wy��czone";
];

[ JestZamkniety obj;
    if (obj has pluralname)       { print "zamkni�te"; return; }
        if (obj has female)       { print "zamkni�ta"; return; }
        else
            if (obj hasnt neuter) { print "zamkni�ty"; return; }
    print "zamkni�te";
];




! ------------------------------------------------------------------------------
! Kilka funkcji wy�wietlaj�cych informacje o liczebnikach prawid�owo
! zgodnie z zasadami j�zyka polskiego. Potrzebne przy wy�wietlaniu wyniku.
! ------------------------------------------------------------------------------

[ LiczPunkty num;

  if (num == 0) { print " punkt�w";return;};
  if (num == 1) { print " punkt";return;};
  if (num > 5 && num <21) { print " punkt�w";return;};

  if (num > 1000) num = num%1000;
  if (num > 100) num = num%100;
  if (num > 10) num = num %10;

  if (num > 1 && num < 5) { print_ret " punkty";} else {print " punkt�w";return;};


];

[ LiczTury num;

  if (num == 0) { print num, " tur";return;};
  if (num == 1) { print num, " tury";return;};
  if (num > 1) { print num, " tur";return;};

];




! -----------------------------------------------------------------------------
! Funkcje opisuj�ce stan obiektu w zale�no�ci od liczby (pojedyncza lub mnoga).
! Wykorzystywane s� g��wnie w opisach -> patrz LanguageLM
! -----------------------------------------------------------------------------

[ DawacSie obj;
  if (obj has pluralname)   print "daj� ";
        else
     print "daje ";
];

[ Lezec obj;
  if (obj has pluralname)   print "le��";
        else
     print "le�y";
];

[ NadawacSie obj;
  if (obj has pluralname)   print "nadaj�";
        else
     print "nadaje";
];

[ Stac obj;
  if (obj has pluralname)   print "stoj�";
        else
     print "stoi";
];



! ------------------------------------------------------------------------------
! Zaimki wskazuj�ce... te zaczynaj�ce si� z du�ej litery s� bardzo rzadko
! u�ywane. Zosta�y na wszelki wypadek.
! ------------------------------------------------------------------------------

[ ToLubTe obj;      ! Used in the accusative
    if (obj == player)            { print "ty"; return; }
    if (obj has pluralname)       { print "te"; return; }
    if (obj has animate) {
        if (obj has female)       { print "ta"; return; }
        else
            if (obj hasnt neuter) { print "ten"; return; }
    }
    print "to";
];

[ CosLubCzyms obj;
    if (obj has pluralname)       { print " czym�"; } else {print " co�";};
    return;
];

[ ItorThem obj;
    if (obj == player)            { print "si�"; return; }
    if (obj has pluralname)       { print "je"; return; }
    if (obj has female)       { print "j�"; return; }
    else
      if (obj hasnt neuter) { print "go"; return; }
      else print "to";
];


[ CToLubTe obj;     ! Used in the nominative
    if (obj == player)            { print "Ty"; return; }
    if (obj has pluralname)       { print "Te"; return; }
    if (obj has animate) {
        if (obj has female)       { print "Ta"; return; }
        else
            if (obj hasnt neuter) { print "Ten"; return; }
    }
    print "To";
];

[ CTheyreorThats obj;
    if (obj == player)             { print "Ty"; return; }
    if (obj has pluralname)        { print "Te"; return; }
    if (obj has animate) {
        if (obj has female)        { print "Ta"; return; }
        else if (obj hasnt neuter) { print "Ten"; return; }
    }
    print "To";
];




! ------------------------------------------------------------------------------
! Dodaktowe definicje
! ------------------------------------------------------------------------------


! Standardowo jest "z", np. "z krzes�a", ale czasami trzeba zdefiniowa� inaczej
! np. "ze sto�u".
[ pl_z obj;
  if (obj has z_article) print "ze "; else print "z ";
];

! Standardowo jest "w", np. "w ksi��ce", ale czasami trzeba zdefiniowa� inaczej
! np. "we wraku".
[ pl_w obj;
  if (obj has w_article) "we "; else print "w ";
];




! ------------------------------------------------------------------------------
! Odpowiedzi parsera
! ------------------------------------------------------------------------------


[ LanguageLM n x1;
  Answer, Ask: "Nie dostajesz odpowiedzi.";
  Attack:   "Przemoc nie jest rozwi�zaniem.";
  Blow:     "Niespecjalnie wiesz jak mo�na zad�� w ", (bie) x1, ".";
  Burn:     "Niebezpieczny pomys�. Niczego w ten spos�b nie osi�gniesz.";
  Buy:      "Nie ", (JestLubSa) x1, " na sprzeda�.";
  Climb:    "Niewiele w ten spos�b osi�gniesz.";
  Close: switch (n) {
        1:  print_ret (Cname) x1, " nie ",(JestLubSa) x1, " czym� co mo�na zamkn��.";
        2:  print (Cname) x1, " "; if (x1 has pluralname)       { print "s� ju� zamkni�te.^"; return; }
            if (x1 has female)       { print "jest ju� zamkni�ta.^"; return; }
            else if (x1 hasnt neuter) { print "jest ju� zamkni�te.^"; return; }
    print "jest ju� zamkni�te.^";
        3:  "Zamykasz ", (bie) x1, ".";
    }
  CommandsOff: switch (n) {
        1: "[Command recording off.]";
        #Ifdef TARGET_GLULX;
        2: "[Command recording already off.]";
        #Endif; ! TARGET_
    }
  CommandsOn: switch (n) {
        1: "[Command recording on.]";
        #Ifdef TARGET_GLULX;
        2: "[Commands are currently replaying.]";
        3: "[Command recording already on.]";
        4: "[Command recording failed.]";
        #Endif; ! TARGET_
    }
  CommandsRead: switch (n) {
        1: "[Replaying commands.]";
        #Ifdef TARGET_GLULX;
        2: "[Commands are already replaying.]";
        3: "[Command replay failed.  Command recording is on.]";
        4: "[Command replay failed.]";
        5: "[Command replay complete.]";
        #Endif; ! TARGET_
    }
  Consult:  "Nie znajdujesz w ", (mie) x1, " niczego interesuj�cego.";
  Cut:      "Przeci�cie ", (dop) x1, " do niczego nie doprowadzi.";
  Dig:      "Kopaniem nic tu nie osi�gniesz.";
  Disrobe: switch (n) {
        1:  "Nie masz na sobie ", (dop) x1, ".";
        2:  "Zdejmujesz ", (bie) x1, ".";
    }
  Drink:    print (Cname) x1 ," nie ", (NadawacSie) x1, " si� do picia.";
  Drop: switch (n) {
        1:  if (x1 has pluralname) print (The) x1, " are "; else print (The) x1, " is ";
            "already here.";
        2:  "You haven't got ", (ToLubTe) x1, ".";
        3:  "(zdejmujesz ", (bie) x1, ")";
        4:  print "Zostawiasz ", (bie) x1, ".^";
    }
  Eat: switch (n) {
        1:  if (x1 == player) "Cokolwiek my�lisz, autokanibalizm nie jest rozwi�zaniem.";
          print_ret (Cname) x1, " nie nadaje si� do jedzenia.";
        2:  "Zjadasz ", (bie) x1, ".", (JestSmaczny) x1;
    }
  EmptyT: switch (n) {
        1:  print_ret (Cname) x1, " nie s�u�y do przechowywania.";
        2:  print_ret (Cname) x1, " ", (JestLubSa) x1, " ", (JestZamkniety) x1, ".";
        3:  print_ret (Cname) x1, " ", (JestLubSa) x1, " ju� ", (JestPusty) x1,".";
        4:  "That would scarcely empty anything.";
    }
  Enter: switch (n) {
        1:  print "Przecie� jeste� ju� ";
            if (x1 has supporter) print "na "; else print "w ";
            print_ret (mie) x1, ".";
        2:  if (x1 has pluralname) print "They're"; else print "That's";
            print " not something you can ";
            switch (verb_word) {
              'stand':  "stand on.";
              'sit':    "sit down on.";
              'lie':    "lie down on.";
              default:  "enter.";
            }
        3:  "You can't get into the closed ", (name) x1, ".";
        4:  "You can only get into something free-standing.";
        5:  print "Wchodzisz ";
            if (x1 has supporter) print "na ", (bie) x1; else print "do ", (dop) x1 ;
            print_ret ".";
        6:  print "(";
            if (x1 has supporter) print "schodzisz z "; else print "wychodzisz z ";
            print (dop) x1; ")";
        7:  if (x1 has supporter) "(getting onto ", (the) x1, ")^";
            if (x1 has container) "(getting into ", (the) x1, ")^";
            "(entering ", (the) x1, ")^";
    }
  Examine: switch (n) {
        1:  "Ciemno��, rzeczownik. Oznacza brak �wiat�a...";
        2:  "Nie widzisz w ", (mie) x1, " nic specjalnego.";
        3:  print "Obecnie ", (name) x1, " ", (JestLubSa) x1, " ";
            if (x1 has on) print (JestWlaczony) x1,"."; else print (JestWylaczony) x1, ".^";
    }
  Exit: switch (n) {
        1:  "Nie znajdujesz si� w tej chwili we wn�trzu niczego konkretnego.";
        2:  "Nie mo�esz wyj�� z ", (dop) x1, " poniewa� ", (JestLubSa) x1, " ", (JestZamkniety) x1, "." ;
        3:  if (x1 has supporter) print "Schodzisz z "; else print "Wychodzisz z ";
            print_ret (dop) x1, ".";
        4:  print "Przecie� nie jeste� ";
            if (x1 has supporter) print "na "; else print "w ";
            print_ret (mie) x1, ".";
    }
  Fill:     "Ale tu nie ma wody do nape�nienia.";
  FullScore: switch (n) {
        1:  if (deadflag) print "Na wynik z�o�y�y si� "; else print "Na wynik sk�adaj� si� ";
            "nast�puj�ce osi�gni�cia:^";
        2:  "finding sundry items";
        3:  "visiting various places";
        4:  print "     ��cznie: ";
        5:  print " (z maksymalnie ", MAX_SCORE, (LiczPunkty) MAX_SCORE, ").";
    }
  GetOff:   "Nie jeste� w tym/na ", (mie) x1, ".";
  Give: switch (n) {
        1:  "Nie posiadasz ", (dop) x1, ".";
        2:  "You juggle ", (the) x1, " for a while, but don't achieve much.";
        3:  print (Cname) x1;
            if (x1 has pluralname) print " don't"; else print " doesn't";
            " seem interested.";
    }
  Go: switch (n) {
        1:  print "Najpierw musisz ";
            if (x1 has supporter) print "zej�� ", (pl_z) x1; else print "wyj�� ", (pl_z) x1;
            print_ret (dop) x1, ".";
        2:  print_ret (string) CANTGO__TX;   ! "Nie mo�esz uda� si� w tym kierunku."
        3:  "You are unable to climb ", (the) x1, ".";
        4:  "You are unable to descend by ", (the) x1, ".";
        5:  "Nie mo�esz uda� si� w tym kierunku, poniewa� na twojej drodze ", (StoiLubStoja) x1, " ", (name) x1,".";
        6:  print "You can't, since ", (the) x1;
            if (x1 has pluralname) " lead nowhere."; else " leads nowhere.";
    }
  Insert: switch (n) {
        1:  "Musisz najpierw trzyma� ", (bie) x1, " zanim b�dziesz m�g� ", (itorthem) x1,
            " w�o�y� do czego� innego.";
        2:  print_ret "Niestety, ", (name) x1 ," nie s�u�y do przechowywania innych rzeczy.";
        3:  print_ret (Cname) x1, " ", (JestLubSa) x1, " ",(JestZamkniety) x1, ".";
        4:  "Musisz najpierw ", (itorthem) x1, " zdj��.";
        5:  "Nie mo�esz w�o�y� czego� do �rodka siebie samego.";
        6:  "(najpierw zdejmujesz ", (bie) x1, ")^";
        7:  "W ", (mie) x1, " nie ma ju� miejsca.";
        8:  "Zrobione.";
        9:  print "Wk�adasz ", (bie) x1, " do ", (dop) second, ".^";
    }
  Inv: switch (n) {
        1:  "Nic przy sobie nie masz.";
        2:  print "Masz przy sobie";
        3:  print ":^";
        4:  print ".^";
    }
  Jump:     "Podskakujesz w miejscu i nic z tego nie wynika.";
  JumpOver, Tie:
            "You would achieve nothing by this.";
  Kiss:     "Lepiej skup si� na grze.";
  Listen:   "Nie s�yszysz niczego konkretnego.";
  ListMiscellany: switch (n) {
        1:  print " (�wieci)";
        2:  print " (", (ktoryktoraktore) x1, " ", (JestLubSa) x1, " ", (JestZamkniety) x1,")";
        3:  print " (", (ktoryktoraktore) x1, " ", (JestLubSa) x1, " ", (JestZamkniety) x1," i �wieci)";
        4:  print " (", (ktoryktoraktore) x1, " ", (JestLubSa) x1, " ", (JestPusty) x1,")";
        5:  print " (", (ktoryktoraktore) x1, " ", (JestLubSa) x1, " ", (JestPusty) x1," i �wieci)";
        6:  print " (", (ktoryktoraktore) x1, " ", (JestLubSa) x1, " ", (JestZamkniety) x1," i ", (JestPusty) x1,")";
        7:  print " (", (JestOtwarty) x1,", ", (JestPusty) x1, " i �wieci)";
        8:  print " (�wieci i ", (JestUbrany) x1;
        9:  print " (�wieci";
        10: print " (", (JestUbrany) x1;
        11: print " (...", (ktoryktoraktore) x1, " ";!, (JestLubSa) x1, " ";
        12: print (JestLubSa) x1, " ", (JestOtwarty) x1;
        13: print (JestLubSa) x1, " ", (JestOtwarty) x1," i ", (JestPusty) x1;
        14: print (JestLubSa) x1, " ", (JestZamkniety) x1;
        15: print (JestLubSa) x1, " ", (JestZamkniety) x1, " na klucz";
        16: print " oraz ", (JestPusty) x1;
        17: print " (", (ktoryktoraktore) x1, " ", (JestLubSa) x1, " ", (JestPusty) x1;
        18: print " containing ";
        19: print " (na "; ! na kt�rym jest to i tamto
        20: print ", on top of ";
        21: print " (w ";
        22: print ", wewn�trz ";
    }
  LMode1:   "Zosta� uruchomiony tryb ~normalnego~ wy�wietlania opis�w lokacji, tzn. po pierwszym wej�ciu do danej lokacji
                poka�e si� jej pe�ny opis, natomiast przy ka�dym nast�pnym - skr�cony.";
  LMode2:   "Zosta� uruchomiony tryb ~pe�nego~ wy�wietlania opis�w lokacji, tzn. po wej�ciu do danej lokacji zawsze
                poka�e si� jej pe�ny opis, nawet je�li zosta�a ona ju� wcze�niej odwiedzona.";
  LMode3:   "Zosta� uruchomiony tryb ~skr�conego~ wy�wietlania opis�w lokacji, tzn. po wej�ciu do danej lokacji
                poka�e si� jej skr�cony opis, nawet je�li nie by�a ona wcze�niej odwiedzana.";
  Lock: switch (n) {
        1:  "W ", (cel) x1, " nie ma zamka.";
        2:  print (Cname) x1, " "; if (x1 has pluralname)       { print "s� ju� zamkni�te na klucz.^"; return; }
            if (x1 has female)       { print "jest ju� zamkni�ta na klucz.^"; return; }
            else if (x1 hasnt neuter) { print "jest ju� zamkni�ty na klucz.^"; return; }
            print "jest ju� zamkni�te na klucz.^";
        3:  "(zamykajac ", (bie) x1, ")";
        4:  print (Cname) x1, " nie "; if (x1 has pluralname) print "pasuj� "; else print "pasuje ";
            "do zamka.";
        5:  "Zamykasz zamek w ", (mie) x1, " za pomoc� ", (dop) second, ".";
    }
  Look: switch (n) {
        1:  print " (na ", (mie) x1, ")";
        2:  print " (w ", (mie) x1, ")";
        3:  print " (jako ", (object) x1, ")";
        4:  print "^Na ", (mie) x1;
            WriteListFrom(child(x1),
              ENGLISH_BIT+RECURSE_BIT+PARTINV_BIT+TERSE_BIT+CONCEAL_BIT+ISARE_BIT);
            ".";
        5,6:
            if (x1 ~= location) {
                if (x1 has supporter) print "^Na "; else print "^W ";
                print (mie) x1, " widzisz ";
            }
            else print "^Widzisz ";
            if (x1 == location) {print "tutaj ";};
            if (n == 5) print "tak�e ";
            ! print "see ";
            WriteListFrom(child(x1),
              ENGLISH_BIT+RECURSE_BIT+PARTINV_BIT+TERSE_BIT+CONCEAL_BIT+BIERNIK_BIT+WORKFLAG_BIT);
            !if (x1 == location) "."; else " here.";
            print ".^";
        7:  "Nie dostrzegasz w tym kierunku niczego szczeg�lnie interesuj�cego.";
    }
  LookUnder: switch (n) {
        1:  "Przecie� jest ciemno.";
        2:  "Nie znajdujesz nic ciekawego.";
    }
  Mild:     "Quite.";
  Miscellany: switch (n) {
        1:  "(considering the first sixteen objects only)^";
        2:  "Nothing to do!";
        3:  print " Zgin��e� ";
        4:  print " Zwyci�y�e� ";
        5:  print "^Czy chcesz ZRESTARTOWA�, ZA�ADOWAƠ zapisany stan gry";
            #Ifdef DEATH_MENTION_UNDO;
            print ", COFN�Ơ sw�j ostatni ruch";
            #Endif;
            if (TASKS_PROVIDED == 0) print ", zobaczy� PE�NY WYNIK";
            if (deadflag == 2 && AMUSING_PROVIDED == 0)
                print ", see some suggestions for AMUSING things to do";
            " czy ZAKO�CZYƀ�?";
        6:  "[Niestety! U�ywany przez ciebie interpreter nie pozwala wykona� ~cofania~.]";
            #Ifdef TARGET_ZCODE;
        7:  "~Undo~ failed.  [Not all interpreters provide it.]";
            #Ifnot; ! TARGET_GLULX
        7:  "[You cannot ~undo~ any further.]";
            #Endif; ! TARGET_
        8:  "Udziel prosz� jednej ze wskazanych powy�ej odpowiedzi.";
        9:  "^Nagle wok� zapad�y nieprzeniknione ciemno�ci!";
        10: "S�ucham?";
        11: "[Nie mo�esz ~cofn��~ czego� co nie zosta�o zrobione!]";
        12: "[Can't ~undo~ twice in succession. Sorry!]";
        13: "[Poprzedni ruch zosta� cofni�ty.]";
        14: "Sorry, that can't be corrected.";
        15: "Think nothing of it.";
        16: "~Oops~ can only correct a single word.";
        17: "It is pitch dark, and you can't see a thing.";
        18: print "yourself";
        19: "Jak zwykle wygl�dasz �wietnie.";
        20: "Aby powt�rzy� polecenie, przyk�adowo ~�aba, podskocz~, wystarczy powiedzi� ~powt�rz~, a nie ~�aba, powt�rz~.";
        21: "You can hardly repeat that.";
        22: "Nie mo�esz zaczyna� zdania od przecinka.";
        23: "Wygl�da na to, �e pr�bujesz z kim� porozmawia�, ale nie bardzo widz� z kim.";
        24: "You can't talk to ", (the) x1, ".";
        25: "To talk to someone, try ~someone, hello~ or some such.";
        26: "(bierzesz ", (bie) not_holding, ")";
        27: "Nie zrozumia�em tego zdania.";
        28: print "Zrozumia�em tylko tyle, �e usi�ujesz ";
        29: "I didn't understand that number.";
        30: "Nie widzisz nic takiego.";
        31: "You seem to have said too little!";
        32: "You aren't holding that!";
        33: "Ten czasownik mo�na zastosowa� tylko do pojedynczego obiektu.";
        34: "You can only use multiple objects once on a line.";
        35: "I'm not sure what ~", (address) pronoun_word, "~ refers to.";
        36: "You excepted something not included anyway!";
        37: "To jedno z tych polece�, kt�re nie dzia�a na przedmioty martwe.";
        38: "Nie znam takiego czasownika.";
        39: "To nie jest co� do czego musisz si� odnosi� podczas tej gry.";
        40: "You can't see ~", (address) pronoun_word, "~ (", (the) pronoun_obj,
            ") at the moment.";
        41: "I didn't understand the way that finished.";
        42: if (x1 == 0) print "None"; else print "Only ", (number) x1;
            print " of those ";
            if (x1 == 1) print "is"; else print "are";
            " available.";
        43: "Nothing to do!";
        44: "There are none at all available!";
        45: print "Sprecyzuj kogo dok�adnie masz na my�li, ";
        46: print "Sprecyzuj co dok�adnie masz na my�li, ";
        47: "Sorry, you can only have one item here. Which exactly?";
        48: QuestionVerb();
            if (actor ~= player) print " ", (the) actor;
            ! print "to ";
            PrintCommand(); print "?^";
        49: QuestionVerb();
            if (actor ~= player) print " kaza� ", (cel) actor;
            PrintCommand(0); print "?^";
        50: print "Tw�j wynik w�a�nie ";
            if (x1 > 0) print "wzr�s�"; else { x1 = -x1; print "zmniejszy� si�"; }
            print " o ", (number) x1, (LiczPunkty) x1;
        51: "(Since something dramatic has happened, your list of commands has been cut short.)";
        52: "^Type a number from 1 to ", x1, ", 0 to redisplay or press ENTER.";
        53: "^[Naci�nij SPACJ�.]";
        54: "[Comment recorded.]";
        55: "[Comment NOT recorded.]";
        56: print ".^";
        57: print "?^";
    }
  No,Yes:   "To by�o pytanie retoryczne.";
  NotifyOff:
            "Score notification off.";
  NotifyOn: "Score notification on.";
  Objects: switch (n) {
        1:  "Rzeczy, kt�re jak dot�d by�y lub obecnie znajduj� si� w Twoim posiadaniu:^";
        2:  "Brak.";
        3:  print "   (",(JestUbrany) x1,")";
        4:  print "   (masz przy sobie)";
        5:  print "   (",(JestOddany) x1,")";
        6:  print "   (", (name) x1, ")";
        7:  print "   (", (the) x1, ")";
        8:  print "   (w ", (cel) x1, ")";
        9:  print "   (na ", (mie) x1, ")";
        10: print "   (", (JestZagubiony) x1,")";
    }
  Open: switch (n) {
        1:  print_ret (Cname) x1, " nie ", (JestLubSa) x1, " czym� co dawa�oby si� otworzy�.";
        2:  print (Cname) x1, " ", (JestLubSa) x1, " ", (JestZamkniety) x1, " na klucz.^";
        3:  print_ret (Cname) x1, " ", (JestLubSa) x1," ju� ", (JestOtwarty) x1,".";
        4:  print "Otwierasz ", (bie) x1, ", znajduj�c ";
            if (WriteListFrom(child(x1), ENGLISH_BIT+TERSE_BIT+CONCEAL_BIT+BIERNIK_BIT) == 0) "puste wn�trze.";
            ".";
        5:  "Otwierasz ", (bie) x1, ".";
    }
  Order:    print (The) x1;
            if (x1 has pluralname) print " have"; else print " has";
            " better things to do.";
  Places: switch (n) {
        1:  print "Lista odwiedzonych pomieszcze�: ";
        2:  print ".^";
    }
  Pray:     "Twoja modlitwa nie da�a �adnego widocznego rezultatu.";
  Prompt:   print "^>";
  Pronouns: switch (n) {
        1:  print "At the moment, ";
        2:  print "means ";
        3:  print "is unset";
        4:  "no pronouns are known to the game.";
        5:  ".";
    }
  Pull,Push,Turn: switch (n) {
        1: print (JestPrzytwierdzony) x1;
        2:  "Nie jeste� w stanie tego zrobi�.";
        3:  "Nic specjalnego si� nie sta�o.";
        4:  "To by�oby bardzo niekulturalne.";
    }
! Push: see Pull
  PushDir: switch (n) {
        1:  "Nic lepszego nie uda�o ci si� wymy�li�?";
        2:  "To nie jest prawid�owo wskazany kierunek.";
        3:  "W tym kierunku niestety si� nie da.";
    }
  PutOn: switch (n) {
        1:  "Musisz trzyma� ", (bie) x1, " �eby m�c ", (itorthem) x1, " po�o�y� na czym� innym.";
        2:  "You can't put something on top of itself.";
        3:  "Putting things on ", (the) x1, " would achieve nothing.";
        4:  "You lack the dexterity.";
        5:  "(najpierw zdejmujesz ", (bie) x1, ")^";
        6:  "There is no more room on ", (the) x1, ".";
        7:  "Zrobione.";
        8:  "Odk�adasz ", (bie) x1, " na ", (mie) second, ".";
    }
  Quit: switch (n) {
        1:  print "Odpowiedz ~tak~ lub ~nie~.";
        2:  print "Czy na pewno chcesz zako�czy� gr�? ";
    }
  Remove: switch (n) {
        1:  print "Niestety", (JestLubSa) x1, " ", (JestZamkniety) x1,".";
        2:  if (x1 has pluralname) print "But they aren't"; else print "But it isn't";
            " there now.";
        3:  if (player has female) print "Wyj�a�.^"; else print "Wyj��e�.^";
    }
  Restart: switch (n) {
        1:  print "Czy na pewno chcesz uruchomi� gr� ponownie? ";
        2:  "Nie uda�o si�.";
    }
  Restore: switch (n) {
        1:  "Nie uda�o si� za�adowa� zapisanej gry.";
        2:  "Ok.";
    }
  Rub:      "Nie uda�o Ci si� w ten spos�b osi�gn�� niczego konkretnego.";
  Save: switch (n) {
        1:  "Nie uda�o si� zapisa� stanu gry.";
        2:  "Ok.";
    }
  Score: switch (n) {
        1:  if (turns>0) print "W czasie ", (LiczTury) turns; else print "Jak dot�d";
            print " uda�o Ci si� zdoby� ";
            print score, " z mo�liwych do zdobycia ", MAX_SCORE, (LiczPunkty) MAX_SCORE;
            return;
        2:  "W tej opowie�ci nie s� liczone punkty.";
    }
  ScriptOff: switch (n) {
        1:  "Transcripting is already off.";
        2:  "^End of transcript.";
        3:  "Attempt to end transcript failed.";
    }
  ScriptOn: switch (n) {
        1:  "Transcripting is already on.";
        2:  "Start of a transcript of";
        3:  "Attempt to begin transcript failed.";
    }
  Search: switch (n) {
        1:  "Przecie� jest ciemno.";
        2:  "Na ", (mie) x1, " nic nie ma.";
        3:  print "Na ", (mie) x1;
            WriteListFrom(child(x1), ENGLISH_BIT+TERSE_BIT+CONCEAL_BIT+ISARE_BIT);
            ".";
        4:  "You find nothing of interest.";
        5:  "Nie mo�esz zobaczy� co jest w �rodku, poniewa� ", (name) x1, " ", (JestLubSa) x1, " ", (JestZamkniety) x1, ".";
        6:  print_ret "Stwierdzasz, �e ", (name) x1, " ", (JestPusty) x1, ".";
        7:  print "W ", (mie) x1;
            WriteListFrom(child(x1), ENGLISH_BIT+TERSE_BIT+CONCEAL_BIT+ISARE_BIT);
            ".";
    }
  Set:      "No, you can't set ", (ToLubTe) x1, ".";
  SetTo:    "No, you can't set ", (ToLubTe) x1, " to anything.";
  Show: switch (n) {
        1:  "You aren't holding ", (the) x1, ".";
        2:  print_ret (The) x1, " ", (JestLubSa) x1, " unimpressed.";
    }
  Sing:     "Your singing is abominable.";
  Sleep:    "Nie czujesz szczeg�lnego zm�czenia.";
  Smell:    "Nie wyczuwasz niczego specjalnego.";
  Sorry:    "Nie musisz przeprasza�!";
  Squeeze: switch (n) {
        1:  "Trzymaj r�ce przy sobie.";
        2:  "Nic w ten spos�b nie osi�gniesz.";
    }
  Strong:   "Poszukiwacze przyg�d nie u�ywaj� takiego j�zyka.";
  Swim:     "There's not enough water to swim in.";
  Swing:    "There's nothing sensible to swing here.";
  SwitchOff: switch (n) {
        1:  print_ret (Cname) x1, " nie ", (JestLubSa) x1, " czym� co dawa�oby si� w��czy� lub wy��czy�.";
        2:  print_ret (Cname) x1, " jest ju� ", (JestWylaczony) x1,".";
        3:  "Wy��czasz ", (bie) x1, ".";
    }
  SwitchOn: switch (n) {
        1:  print_ret (Cname) x1, " nie ", (JestLubSa) x1, " czym� co dawa�oby si� w��czy� lub wy��czy�.";
        2:  print_ret (Cname) x1, " jest ju� ", (JestWlaczony) x1,".";
        3:  "W��czasz ", (bie) x1, ".";
    }
  Take: switch (n) {
        1:  "Bierzesz ", (bie) x1,".";
        2:  "Pr�bujesz wi��� si� troch� w gar��.";
        3:  "I don't suppose ", (the) x1, " would care for that.";
        4:  print "You'd have to get ";
            if (x1 has supporter) print "off "; else print "out of ";
            print_ret (the) x1, " first.";
        5:  "Ju� masz przy sobie ", (bie) x1, ".";
        6:  print "Nie mo�esz, poniewa� ", (name) x1, " "; if (noun has pluralname) print "nale�� "; else print "nale�y ";
            "do ", (dop) x1, ".";
        7:  if (noun has pluralname) print "Those seem "; else print "That seems ";
            "to be a part of ", (the) x1, ".";
        8:  print_ret (CToLubTe) x1, " ", (JestLubSa) x1,
            "n't available.";
        9:  print_ret (Cname) x1, " ", (JestLubSa) x1, " ", (JestZamkniety) x1, ".";
        10: if (x1 has pluralname) print "They're "; else print "That's ";
            "hardly portable.";
        11: if (x1 has pluralname) print "They're "; else print "That's ";
            "fixed in place.";
        12: "Nic z tego. Masz przy sobie za du�o rzeczy!";
        13: "(wk�adasz ", (bie) x1, " do ", (dop) SACK_OBJECT, " aby zrobi� miejsce)";
    }
  Taste:    "Nie znajdujesz nic nieoczekiwanego w smaku ", (dop) x1,".";
  Tell: switch (n) {
        1:  "Przez chwil� mamroczesz co� do siebie pod nosem.";
        2:  "Jedyn� odpowiedzi� jest brak jakiejkolwiek reakcji.";
    }
  Think:    "�wietny pomys�.";
  ThrowAt: switch (n) {
        1:  "Futile.";
        2:  "You lack the nerve when it comes to the crucial moment.";
    }
! Tie:  see JumpOver.
  Touch: switch (n) {
        1:  "Trzymaj r�ce przy sobie!";
        2:  "Nie czujesz nic nadzwyczajnego.";
        3:  "Je�li s�dzisz, �e to pomo�e...";
    }
! Turn: see Pull.
  Unlock:  switch (n) {
        1:  print_ret (Cname) x1,
            " nie ", (JestLubSa) x1, " czym� co mo�na otworzy� za pomoc� ", (dop) second, ".";
        2:  print_ret (ctheyreorthats) x1, " unlocked at the moment.";
        3:  if (x1 has pluralname) print "Nie pasuj� "; else print "Nie pasuje ";
            "do zamka.";
        4:  "Odblokowujesz ", (bie) x1, " za pomoc� ", (dop) second,".";

    }
  VagueGo:  "Musisz sprecyzowa� kierunek, w kt�rym chcesz si� uda�.";
  Verify: switch (n) {
        1:  "The game file has verified as intact.";
        2:  "The game file did not verify as intact, and may be corrupt.";
    }
  Wait:     "Up�ywa troch� czasu.";
  Wake:     "The dreadful truth is, this is not a dream.";
  WakeOther:"That seems unnecessary.";
  Wave: switch (n) {
        1:  "But you aren't holding ", (ToLubTe) x1, ".";
        2:  "You look ridiculous waving ", (the) x1, ".";
    }
WaveHands:"Czujesz si� troch� g�upi tak sobie wymachuj�c r�kami.";
  Wear: switch (n) {
        1:  "Nie mozesz za�o�y� na siebie ", (dop) x1, "!";
        2:  "Nie trzymasz ", (dop) x1, "!";
        3:  "Masz ju� na sobie ", (bie) x1, "!";
        4:  "Zak�adasz ", (bie) x1, ".";
        }
! Yes:  see No.
];

! ==============================================================================

Constant LIBRARY_ENGLISH;       ! for dependency checking.

! ==============================================================================


[ testnoun;
  if (NextWord() == 'to') return ParseToken(ELEMENTARY_TT, NOUN_TOKEN);
  wn--;
  parser_inflection = xy;
  return ParseToken(ELEMENTARY_TT, NOUN_TOKEN);
];


Verb 'numer'
   * number         -> Liczba;

[ LiczbaSub;
LanguageNumber(noun);
LiczPunkty(noun);
];

Verb 'xy'
  * testnoun        -> Look;


[ XY obj word a l i;

  ! Irregular dative endings
  !if (obj provides name_biernik)
  !    return WordInProperty(word, obj, name_biernik);

  ! Regular dative endings
  a = WordAddress(wn-1);
  l = WordLength(wn-1);

  !while (i < l) {print (char) a->i;i++;};



  ! - RZECZOWNIK -> -�A

  if (l >= 2 && a->(l-2) == '�' && a->(l-1) == 'a') {

    while (i < l) {print (char) a->i;i++;};

    a->(l-1) = 'o';

    word = DictionaryLookup(a, l-1);

    if (WordInProperty(word, obj, name)) rtrue; else rfalse;

    };


  ! - PRZYMIOTNIK -> -EGO

  if (l >= 2 && a->(l-3) == 'e' && a->(l-2) == 'g' && a->(l-1) == 'o') {

          !a->(l-2) = ' ';
          !a->(l-1) = ' ';

          word = DictionaryLookup(a, (l-2));

          if (WordInProperty(word, obj, name)) rtrue; else rfalse;

    };


  rfalse;

];



! ==============================================================================
