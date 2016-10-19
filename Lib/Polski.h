! ==============================================================================
!   POLSKI:  Language Definition File
!
!   Przeznaczony do uzywania z kompilatorem Inform 6.
!
!   Wersja 6/11/PL
!   Copyright Bartosz Zaj±czkowski 2011-2014
!       z mozliwosci± swobodnego korzystania.
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
! Kierunki ¶wiata na kompasie
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

CompassDirection -> n_obj "pó³noc",
                    with door_dir n_to, name 'pn//' 'polnoc', has female;

CompassDirection -> s_obj "po³udnie"
                    with door_dir s_to, name 'pd//' 'poludnie', has neuter;

CompassDirection -> e_obj "wschód"
                    with door_dir e_to, name 'w//' 'wschod';

CompassDirection -> w_obj "zachód"
                    with door_dir w_to, name 'z//' 'zachod';

CompassDirection -> ne_obj "pó³nocny-wschód"
                    with door_dir ne_to, name 'pnw';

CompassDirection -> nw_obj "pó³nocny-zachód"
                    with door_dir nw_to, name 'pnz';

CompassDirection -> se_obj "po³udniowy-wschód"
                    with door_dir se_to, name 'pdw';

CompassDirection -> sw_obj "po³udniowy-zachód"
                    with door_dir sw_to, name 'pdz';

CompassDirection -> u_obj "góra"
                    with door_dir u_to, name 'g//' 'gora' 'gore' 'sufit' 'niebo';

CompassDirection -> d_obj "dó³"
                    with door_dir d_to, name 'd//' 'dol' 'podloga' 'ziemia' 'spod';

#endif; ! WITHOUT_DIRECTIONS

CompassDirection -> in_obj "¶rodek"
                    with door_dir in_to,
                    name 'srodek' 'wnetrze' 'srodka' 'wnetrza';
CompassDirection -> out_obj "zewn±trz"
                    with door_dir out_to, name 'zewnatrz';



! ------------------------------------------------------------------------------
!   Part II.   Vocabulary
! ------------------------------------------------------------------------------

Constant AGAIN1__WD     = 'powtórz';
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
Constant BUT1__WD       = 'oprócz';   ! kogo, czego?
Constant BUT2__WD       = 'wyj±wszy'; ! kogo, co?
Constant BUT3__WD       = 'bez';      ! kogo, czego?
Constant ME1__WD        = 'mi';
Constant ME2__WD        = 'siebie';
Constant ME3__WD        = 'siê';
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
Constant FULLSCORE2__WD = 'pe³ny';
Constant QUIT1__WD      = 'q//';
Constant QUIT2__WD      = 'zakoñcz';
Constant RESTART__WD    = 'zrestartuj';
Constant RESTORE__WD    = 'za³aduj';

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
    'jeden' 1 'dwa' 2 'trzy' 3 'cztery' 4 'piêæ' 5
    'sze¶æ' 6 'siedem' 7 'osiem' 8 'dziewiêæ' 9 'dziesiêæ' 10
    'jedena¶cie' 11 'dwana¶cie' 12 'trzyna¶cie' 13 'czterna¶cie' 14 'piêtna¶cie' 15
    'szesna¶cie' 16 'siedemna¶cie' 17 'osiemna¶cie' 18 'dziewiêtna¶cie' 19 'dwadzie¶cia' 20;










! ------------------------------------------------------------------------------
!   Part III.   T³umaczenie
! ------------------------------------------------------------------------------

[ LanguageToInformese;

  ClearPolishDirections();

  ! GetRidOfPolishLetters();

];



! ------------------------------------------------------------------------------
! ClearPolishDirections();
!
! Procedura ClearPolishDirections() robi porz±dek z nazwami kierunków ¶wiata
! zanim jeszcze parser zacznie analizowaæ polecenie. Jest to niezbêdne, poniewa¿
! kompilator ma problemy z rozró¿nianiem nazw d³u¿szych ni¿ osiem znaków.
! Problem jest szczególnie dotktliwy w przypadkach gdy pierwsze osiem
! znaków jest takie same, a tak w³asnie jest w jêzyku polskim. Chodzi o cztery
! przypadki: pó³nocny-wschód, pó³nocny-zachód, po³udniowy-wschód
! i po³udniowy zachód. D³ugie nazwy kierunków zostaj± zast±pione odpowiadaj±cymi
! im skrótami z kompasu, co wyklucza ewentualn± pomy³kê interpretera.
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

    ! po³udniowy-zachód -> PDZ
    if (word == 'po³udniowy-zachód' && buffer->(at+10) =='-' && buffer->(at+11) == 'z')
      {
        for (y=at:y<at+17:y++) {buffer->(y) = ' ';};
        buffer->(at+0) = 'p';
        buffer->(at+1) = 'd';
        buffer->(at+2) = 'z';
        break;
      };

    ! pó³nocny-zachód -> PNZ
    if (word == 'pó³nocny-zachód' && buffer->(at+8) =='-' && buffer->(at+9) == 'z')
      {
      for (y=at:y<at+15:y++) {buffer->(y) = ' ';};
        buffer->(at+0) = 'p';
        buffer->(at+1) = 'n';
        buffer->(at+2) = 'z';
        break;
      };

    ! po³udniowy-wschód -> PDW
    if (word == 'po³udniowy-wschód' && buffer->(at+10) =='-' && buffer->(at+11) == 'w')
      {
      for (y=at:y<at+17:y++) {buffer->(y) = ' ';};
        buffer->(at+0) = 'p';
        buffer->(at+1) = 'd';
        buffer->(at+2) = 'w';
        break;
      };

    ! pó³nocny-wschód -> PNW
    if (word == 'pó³nocny-wschód' && buffer->(at+8) =='-' && buffer->(at+9) == 'w')
      {
      for (y=at:y<at+15:y++) {buffer->(y) = ' ';};
        buffer->(at+0) = 'p';
        buffer->(at+1) = 'n';
        buffer->(at+2) = 'w';
        break;
      };

    }; ! koniec pêtli
]; ! koniec ClearPolishDirections



! ---------------------------------------------------------------------------
! Deklinacja rzeczowników
!
! Ka¿dy obiekt powinien mieæ zdefiniowane dodatkowe w³asno¶ci (property)
! zawieraj±ce informacje o jego nazwie prawid³owo zdefiniowanej w jêzyku
! polskim. W tym celu polska biblioteka korzysta z dziesiêciu dodatkowych
! w³asno¶ci (property), których dzia³ania staje siê jasne po zapoznaniu siê
! z poni¿szym przyk³adem obiektu.
! U¿yty w grze "¿elazny miecz" powinien zostaæ zdefiniowany nastêpuj±co:
!
! Object -> miecz "¿elazny miecz",
!   name '¿elazny' 'miecz',
!   name_dop '¿elaznego' 'miecza',       ! tu s± nazwy interpretowane i tutaj
!   name_cel '¿elaznemu' 'mieczowi',     ! powinny zostaæ wymienione wszelkie
!   name_bie '¿elazny' 'miecz',          ! synonimy.
!   name_nar '¿elaznym' 'mieczem',
!   name_mie '¿elaznym' 'mieczu',
!   desc_dop "¿elaznego miecza",         ! tu s± nazwy wy¶wietlane, wystarczy
!   desc_cel "¿elaznemu mieczowi",       ! odmieniæ nazwê w³asn± obiektu
!   desc_bie "¿elazny miecz",
!   desc_nar "¿elaznym mieczem",
!   desc_mie "¿elaznym mieczu";

! Je¶li interpreter nie znajdzie w definicji obiektu nazwy w odpowiedniej
! formie (desc_dop, desc_cel, itp.), zostanie wy¶wietlona nazwa w formie
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
      n_to:    print "pó³noc";
      s_to:    print "po³udnie";
      e_to:    print "wschód";
      w_to:    print "zachód";
      ne_to:   print "pó³nocny-wschód";
      nw_to:   print "pó³nocny-zachód";
      se_to:   print "po³udniowy-wschód";
      sw_to:   print "po³udniowy-zachód";
      u_to:    print "góra";
      d_to:    print "dó³";
      in_to:   print "do ¶rodka";
      out_to:  print "na zewn±trz";
      default: return RunTimeError(9,d);
    }
];

! ------------------------------------------------------------------------------

[ LanguageNumber n f;
    if (n == 0)    { print "zero"; rfalse; }
    if (n < 0)     { print "minus "; n = -n; }
    if (n >= 1000) {
    if (n < 2000) { print "tysi±c"; }
    else  {
      LanguageNumber(n/1000);
      if (n<5000) print " tysi±ce"; else print " tysiêcy";
      }
    n = n%1000; f = 1;
    }
    if (n >= 100)  {
        if (f == 1) print " ";

  switch (n/100) {
    1:  print "sto";
    2:  print "dwie¶cie";
        3:  print "trzysta";
        4:  print "czterysta";
        5:  print "piêæset";
        6:  print "sze¶æset";
        7:  print "siedemset";
        8:  print "osiemset";
        9:  print "dziewiêæset";
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
      5:    print "piêæ";
      6:    print "sze¶æ";
      7:    print "siedem";
      8:    print "osiem";
      9:    print "dziewiêæ";
      10:   print "dziesiêæ";
      11:   print "jedena¶cie";
      12:   print "dwana¶cie";
      13:   print "trzyna¶cie";
      14:   print "czterna¶cie";
      15:   print "piêtna¶cie";
      16:   print "szesna¶cie";
      17:   print "siedemna¶cie";
      18:   print "osiemna¶cie";
      19:   print "dziewiêtna¶cie";
      20 to 99: switch (n/10) {
        2:  print "dwadzie¶cia";
        3:  print "trzydzie¶ci";
        4:  print "czterdzie¶ci";
        5:  print "piêædziesi±t";
        6:  print "sze¶ædziesi±t";
        7:  print "siedemdziesi±t";
        8:  print "osiemdziesi±t";
        9:  print "dziewiêædziesi±t";
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
    if ((hours/12) > 0) print " po po³udniu"; else print " rano";
];

! ------------------------------------------------------------------------------

[ LanguagePreposition i;
  switch (i)
    {

    ! Ask:
      'pytaj', 'spytaj', 'zapytaj': return 1;
    ! Drink:
      'napij': return 1;
      'po³ó¿': return 2;
      'wstañ','powstañ': return 1;
      'prze¶pij','zdrzemnij': return 1;
      'kop': return 2;
    } rfalse;
];




! ------------------------------------------------------------------------------
! QuestionVerb();
!
! Je¶li interpreter nie bêdzie potrzebowaæ dodatkowych informacji, zada graczowi
! pytanie o podanie dodatkowych informacji. W jêzyku polskim sposób zadania tego
! pytania bêdzie zale¿eæ od u¿ywanego czasownika. Procedura QuestionVerb() ma za
! zadanie rozwi±zaæ ten problem.
!
! Dla porz±dku polskie czasowniki zosta³y u³o¿one wg angielskich odpowiedników.
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
      'idz', 'biegnij', 'pobiegnij', 'pojdz':             print "Dok±d";
      'kop':                                              print "Gdzie";
      'kup', 'zakup':                                     print "Co";
      'napelnij':                                         print "Co";
      'napij':                                            print "Czego";
      'obejrzyj','zobacz':                                print "Co";
      'potrzyj':                                          print "Co";
      'odblokuj':                                         print "Co";
      'odloz':                                            print "Co";
      'odpowiedz':                                        print "Co"; ! ewentualnie mog³o by byæ 'Komu'
      'oproznij':                                         print "Co";
      'otworz':                                           print "Co";
      'pchnij', 'popchnij', 'przesun':                    print "Co";
      'plyn', 'poplyn':                                   print "Dok±d";
      'pocaluj', 'caluj', 'przytul', 'usciskaj':          print "Kogo";
      'podpal':                                           print "Co";
      'pokaz':                                            print "Co";
      'poloz':                                            print "Co"; ! ewentualnie mog³o by byæ 'Gdzie' 'Na czym' itp.
      'pomachaj', 'machaj':                               print "Czym";
      'popros','pros':                                    print "Kogo"; ! ewentualnie mog³o by byæ 'O co'
      'postaw', 'ustaw':                                  print "Co";
      'potrzyj', 'przetrzyj', 'wytrzyj':                  print "Co";
      'powachaj','w±chaj':                                print "Co";
      'powiedz':                                          print "Co";
      'przekrec', 'dokrec', 'obroc', 'odkrec', 'zakrec':  print "Co";
      'przenies', 'przeloz':                              print "Co";
      'przeskocz':                                        print "Nad czym";
      'przeszukaj':                                       print "Co";
      'przetnij', 'tnij', 'przekroj', 'kroj':             print "Co";
      'przyjrzyj':                                        print "Czemu"; ! ewentualnie mog³o by byæ 'Komu'
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
      'wyjdz':                                            print "Dok±d";
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
      'zejdz':                                            print "Sk±d";
      'zostaw':                                           print "Co";
      'zsiadz':                                           print "Z czego";

    default: print "Co";
  };

  print " chcesz ";

];

! ------------------------------------------------------------------------------
! Formy bezokolicznika stosowanych czasowników
! ------------------------------------------------------------------------------

[ LanguageVerb i;
  switch (i)
    {
    'i//','spis':               print "obejrzeæ spis posiadanych przez ciebie przedmiotów";
    ! 'z//':                    print "wait";


    'dmij', 'zadmij':                         print "zad±æ";
    'dmuchnij', 'dmuchaj':                    print "dmuchn±æ";
    'czekaj','poczekaj','zaczekaj':           print "poczekaæ";
    'ciagnij', 'pociagnij':                   print "poci±gn±æ";
    'czytaj', 'przeczytaj':                   print "przeczytaæ";
    'daj', 'oddaj':                           print "daæ";
    'dotknij':                                print "dotkn±æ";
    'idz':                                    print "pój¶æ";
      'biegnij':                              print "biec";
      'pobiegnij':                            print "pobiec";
      'pojdz':                                print "pój¶æ";
    'kop':                                    print "kopaæ";
    'kup','zakup':                            print "kupiæ";
    'napelnij':                               print "nape³niæ";
    'napij':                                  print "siê napiæ"; ! szyk przestawny!
    'obejrzyj','zobacz':                      print "obejrzeæ";
    'odblokuj':                               print "odblokowaæ"; ! w znaczeniu 'Unlock'
    'odloz':                                  print "od³o¿yæ";
    'odpowiedz':                              print "odpowiedzieæ";
    'oproznij':                               print "opró¿niæ";
    'otworz':                                 print "otworzyæ"; ! w znaczeniu 'Open' oraz 'Unlock'
    'pchnij':                                 print "pchn±æ";
      'popchnij':                             print "popchn±æ";
      'przesun':                              print "przesun±æ";
    'plyn':                                   print "p³yn±æ";
      'poplyn':                               print "pop³yn±æ";
    'caluj', 'pocaluj':                       print "poca³owaæ";
      'przytul':                              print "przytuliæ";
      'usciskaj':                             print "u¶ciskaæ";
    'podpal':                                 print "podpaliæ";
    'pokaz':                                  print "pokazaæ";
    'poloz':                                  print "po³o¿yæ";
    'pomachaj', 'machaj':                     print "pomachaæ";
    'pomodl','modl':                          print "pomodliæ";
    'pomysl','mysl':                          print "pomy¶leæ";
    'popros','pros':                          print "poprosiæ";
    'postaw':                                 print "postawiæ";
      'ustaw':                                print "ustawiæ";
    'potrzyj':                                print "potrzeæ";
      'przetrzyj':                            print "przetrzeæ";
      'wytrzyj':                              print "wytrzeæ";
    'powachaj','w±chaj':                      print "pow±chaæ";
    'powiedz':                                print "powiedzieæ";
    'przekrec':                               print "przekrêciæ";
      'dokrec':                               print "dokrêciæ";
      'obroc':                                print "obróciæ";
      'odkrec':                               print "odkrêciæ";
      'zakrec':                               print "zakrêciæ";
    'przenies':                               print "przenie¶æ";
      'przeloz':                              print "prze³o¿yæ";
    'przeskocz':                              print "przeskoczyæ";
    'przeszukaj':                             print "przeszukaæ";
    'przepros':                               print "przeprosiæ";
    'przespij':                               print "przespaæ";
      'zdrzemnij':                            print "zdrzemn±æ";
    'przetnij', 'tnij':                       print "przeci±æ";
    'przekroj', 'kroj':                       print "przekroiæ";
    'przyjrzyj':                              print "siê przyjrzeæ"; ! szyk przestawny!
    'rzuc':                                   print "rzuciæ";
    'schowaj':                                print "schowaæ";
    'siadz', 'usiadz':                        print "usi±¶æ";
    'sluchaj', 'posluchaj':                   print "pos³uchaæ";
    'spojrz':                                 print "spojrzeæ";
      'popatrz':                              print "popatrzeæ";
    'sprawdz':                                print "sprawdziæ";
      'skonsultuj':                           print "skonsultowaæ";
    'sprobuj':                                print "spróbowaæ";
      'skosztuj':                             print "skosztowaæ";
    'szukaj', 'odszukaj', 'poszukaj':         print "poszukaæ";
    'scisnij':                                print "¶cisn±æ";
      'zgniec':                               print "zgnie¶æ";
    'uruchom':                                print "uruchomiæ";
    'wdrap':                                  print "siê wdrapaæ"; ! szyk przestawny!
      'wespnij':                              print "siê wspi±æ"; ! szyk przestawny!
    'wez':                                    print "wzi±æ";
      'zabierz':                              print "zabraæ";
      'podnie¶':                              print "podnie¶æ";
    'wejdz':                                  print "wejd¼";
    'wlacz':                                  print "w³±czyæ";
      'zapal':                                print "zapaliæ";
    'wloz':                                   print "w³o¿yæ";
    'wrzuc':                                  print "wrzuciæ";
    'wsiadz':                                 print "wsi±¶æ";
    'wstan':                                  print "wstaæ";
    'wyjsc':                                  print "wyj¶æ";
    'wyjmij':                                 print "wyj±æ";
      'wyciagnij':                            print "wyci±gn±æ";
    'wylacz':                                 print "wy³±czyæ";
      'zgas':                                 print "zgasiæ";
    'wypij':                                  print "wypiæ";
    'wyrzuc':                                 print "wyrzuciæ";
    'wysiadz':                                print "wysi±¶æ";
    'zaatakuj':                               print "zaatakowaæ";
      'zniszcz':                              print "zniszczyæ";
    'zabij':                                  print "zabiæ";
    'uderz':                                  print "uderzyæ";
      'walnij':                               print "waln±æ";
      'kopnij':                               print "kopn±æ";
    'zablokuj':                               print "zablokowaæ";
    'zajrzyj':                                print "zajrzyj";
    'zaloz':                                  print "za³o¿yæ";
      'ubierz':                               print "ubraæ";
    'zamknij':                                print "zamkn±æ";
    'zapytaj', 'pytaj', 'spytaj':             print "zapytaæ";
    'zastanow':                               print "siê zastanowiæ"; ! szyk przestawny!
    'zaspiewaj', 'spiewaj':                   print "za¶piewaæ";
    'zjedz':                                  print "zje¶æ";
      'polknij':                              print "po³kn±æ";
      'ugryz':                                print "ugry¼æ";
    'znajdz':                                 print "znale¼æ";
    'zdejmij':                                print "zdj±æ";
    'zejdz':                                  print "zej¶æ";
    'zostaw':                                 print "zostawiæ";
    'zsiadz':                                 print "zsi±¶æ";

    !   Czasowniki dodatkowe, które nie z± zdefiniowane w podstawowym zestawie
    'policz': print "policzyæ";   ! pochodzi z advent.inf
    'sfotografuj': print "sfotografowaæ"; ! pochodzi z ruins.inf

    default: rfalse;



  !
  ! Pominiête czasowniki...
  !    - zastanów siê
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

  ! nie ma zastosowania w jêzyku polskim - zostawione na wszelki wypadek

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

  ! nie ma zastosowania w jêzyku polskim - zostawione na wszelki wypadek

    if (w == 'long' or 'short' or 'normal'
                    or 'brief' or 'full' or 'verbose')
        rtrue;
    rfalse;
];


Constant NKEY__TX       = "N = nastêpny temat";
Constant PKEY__TX       = "P = poprzedni temat";
Constant QKEY1__TX      = "Q = powrót do gry";
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
Constant CANTGO__TX     = "Nie mo¿esz i¶æ w tym kierunku.";
Constant FORMER__TX     = "your former self";
Constant YOURSELF__TX   = "Ty";
Constant YOU__TX        = "You";
Constant DARKNESS__TX   = "Ciemno¶æ";

Constant THOSET__TX     = "jakie¶ rzeczy";
Constant THAT__TX       = "tamto";
Constant OR__TX         = " lub ";
Constant OR2__TX        = " czy ";     ! dodanie tej opcji wymaga³o zmiany parsera

Constant NOTHING__TX    = "nic";
Constant IS__TX         = " jest";
Constant ARE__TX        = " s±";
Constant IS2__TX        = "jest ";
Constant ARE2__TX       = "s± ";
Constant AND__TX        = " oraz ";
Constant WHOM__TX       = "whom ";
Constant WHICH__TX      = "which ";
Constant COMMA__TX      = ", ";




! ------------------------------------------------------------------------------
! Procedura wy¶wietlaj±ca pierwsz± literê nazwy obiektu z du¿ej litery.
! W jêzyku polskim nie ma rodzajników okre¶lonych i nieokre¶lonych, dlatego
! bez tej procedury zdania zaczynaj±ce siê od nazwy obiektu zaczyna³y by
! siê z ma³ej litery (nieelegancko) lub trzeba by³o by konstruowaæ niepotrzebne
! konstrukcje s³owne.
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

              ! Przy konwersji ma³ej litery na du¿± trzeba pamiêtaæ o polskich znakach.
              ! Dla polskich znaków w standardzie ISO-8859-2 przesuniêcie wynosi 40 i 41...
              ! Kody znaków s± dostêpne na: http://www.firthworks.com/roger/informfaq/aa20.html

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
! Procedury do wy¶wietlania odpowiedniej formy czasowników "byæ" i "mieæ".
! ------------------------------------------------------------------------------

[ JestLubSa obj;
    if (obj has pluralname || obj == player) print "s±"; else print "jest";
];

[ StoiLubStoja obj;
    if (obj has pluralname || obj == player) print "stoj±"; else print "stoi";
];

[ MaLubMaja obj;
    if (obj has pluralname) { print "maj±"; return; }
    print "ma";
];




! ------------------------------------------------------------------------------
! Procedury do wy¶wietlania odpowiedniej formy "który".
! ------------------------------------------------------------------------------


[ KtoryKtoraKtore obj;
    if (obj has pluralname) {print "które"; return; };
            if (obj has female)       { print "która"; return; }
        else
            if (obj hasnt neuter) { print "który"; return; } else { print "które";return;};
];
[ KtorymKtorejKtorych obj;
    if (obj has pluralname) {print "których"; return; };
            if (obj has female)       { print "której"; return; }
        else
            if (obj hasnt neuter) { print "którym"; return; } else { print "którym";return;};
];




! ------------------------------------------------------------------------------
! Procedury wy¶wietlaj±ce odpowiednia formê najczê¶ciej u¿ywanych przydawek.
! ------------------------------------------------------------------------------

[ JestOddany obj;
    if (obj has pluralname)       { print "oddane"; return; }
        if (obj has female)       { print "oddana"; return; }
        else
            if (obj hasnt neuter) { print "oddany"; return; }
    print "wy³±czone";
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
    print "Nie jeste¶ w stanie ich przesun±æ."; return;} else
        print "Nie jeste¶ w stanie";
            if (obj has female)       { print " przesun±æ ", (dop) obj,"."; return; }
        else
            if (obj hasnt neuter) { print " przesun±æ", (dop) obj,"."; return; } else { print " przesun±æ ", (dop) obj,".";return;};
];

[ JestPusty obj;
    if (obj has pluralname)       { print "puste"; return; }
        if (obj has female)       { print "pusta"; return; }
        else
            if (obj hasnt neuter) { print "pusty"; return; }
    print "puste";
];

[ JestSmaczny obj;
    if (obj has pluralname)       { print "S± ca³kiem smaczne."; return; }
        if (obj has female)       { print "Jest ca³kiem smaczna."; return; }
        else
            if (obj hasnt neuter) { print "Jest ca³kiem smaczny."; return; }
    print "Jest ca³kiem smaczne.";
];

[ JestUbrany obj;
    if (obj has pluralname)       { print "ubrane"; return; }
        if (obj has female)       { print "ubrana"; return; }
        else
            if (obj hasnt neuter) { print "ubrany"; return; }
    print "ubrane";
];

[ JestWlaczony obj;
    if (obj has pluralname)       { print "w³±czone"; return; }
        if (obj has female)       { print "w³±czona"; return; }
        else
            if (obj hasnt neuter) { print "w³±czony"; return; }
    print "w³±czone";
];

[ JestWylaczony obj;
    if (obj has pluralname)       { print "wy³±czone"; return; }
        if (obj has female)       { print "wy³±czona"; return; }
        else
            if (obj hasnt neuter) { print "wy³±czony"; return; }
    print "wy³±czone";
];

[ JestZagubiony obj;
    if (obj has pluralname)       { print "zagubione"; return; }
        if (obj has female)       { print "zagubiona"; return; }
        else
            if (obj hasnt neuter) { print "zagubiony"; return; }
    print "wy³±czone";
];

[ JestZamkniety obj;
    if (obj has pluralname)       { print "zamkniête"; return; }
        if (obj has female)       { print "zamkniêta"; return; }
        else
            if (obj hasnt neuter) { print "zamkniêty"; return; }
    print "zamkniête";
];




! ------------------------------------------------------------------------------
! Kilka funkcji wy¶wietlaj±cych informacje o liczebnikach prawid³owo
! zgodnie z zasadami jêzyka polskiego. Potrzebne przy wy¶wietlaniu wyniku.
! ------------------------------------------------------------------------------

[ LiczPunkty num;

  if (num == 0) { print " punktów";return;};
  if (num == 1) { print " punkt";return;};
  if (num > 5 && num <21) { print " punktów";return;};

  if (num > 1000) num = num%1000;
  if (num > 100) num = num%100;
  if (num > 10) num = num %10;

  if (num > 1 && num < 5) { print_ret " punkty";} else {print " punktów";return;};


];

[ LiczTury num;

  if (num == 0) { print num, " tur";return;};
  if (num == 1) { print num, " tury";return;};
  if (num > 1) { print num, " tur";return;};

];




! -----------------------------------------------------------------------------
! Funkcje opisuj±ce stan obiektu w zale¿no¶ci od liczby (pojedyncza lub mnoga).
! Wykorzystywane s± g³ównie w opisach -> patrz LanguageLM
! -----------------------------------------------------------------------------

[ DawacSie obj;
  if (obj has pluralname)   print "daj± ";
        else
     print "daje ";
];

[ Lezec obj;
  if (obj has pluralname)   print "le¿±";
        else
     print "le¿y";
];

[ NadawacSie obj;
  if (obj has pluralname)   print "nadaj±";
        else
     print "nadaje";
];

[ Stac obj;
  if (obj has pluralname)   print "stoj±";
        else
     print "stoi";
];



! ------------------------------------------------------------------------------
! Zaimki wskazuj±ce... te zaczynaj±ce siê z du¿ej litery s± bardzo rzadko
! u¿ywane. Zosta³y na wszelki wypadek.
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
    if (obj has pluralname)       { print " czym¶"; } else {print " co¶";};
    return;
];

[ ItorThem obj;
    if (obj == player)            { print "siê"; return; }
    if (obj has pluralname)       { print "je"; return; }
    if (obj has female)       { print "j±"; return; }
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


! Standardowo jest "z", np. "z krzes³a", ale czasami trzeba zdefiniowaæ inaczej
! np. "ze sto³u".
[ pl_z obj;
  if (obj has z_article) print "ze "; else print "z ";
];

! Standardowo jest "w", np. "w ksi±¿ce", ale czasami trzeba zdefiniowaæ inaczej
! np. "we wraku".
[ pl_w obj;
  if (obj has w_article) "we "; else print "w ";
];




! ------------------------------------------------------------------------------
! Odpowiedzi parsera
! ------------------------------------------------------------------------------


[ LanguageLM n x1;
  Answer, Ask: "Nie dostajesz odpowiedzi.";
  Attack:   "Przemoc nie jest rozwi±zaniem.";
  Blow:     "Niespecjalnie wiesz jak mo¿na zad±æ w ", (bie) x1, ".";
  Burn:     "Niebezpieczny pomys³. Niczego w ten sposób nie osi±gniesz.";
  Buy:      "Nie ", (JestLubSa) x1, " na sprzeda¿.";
  Climb:    "Niewiele w ten sposób osi±gniesz.";
  Close: switch (n) {
        1:  print_ret (Cname) x1, " nie ",(JestLubSa) x1, " czym¶ co mo¿na zamkn±æ.";
        2:  print (Cname) x1, " "; if (x1 has pluralname)       { print "s± ju¿ zamkniête.^"; return; }
            if (x1 has female)       { print "jest ju¿ zamkniêta.^"; return; }
            else if (x1 hasnt neuter) { print "jest ju¿ zamkniête.^"; return; }
    print "jest ju¿ zamkniête.^";
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
  Consult:  "Nie znajdujesz w ", (mie) x1, " niczego interesuj±cego.";
  Cut:      "Przeciêcie ", (dop) x1, " do niczego nie doprowadzi.";
  Dig:      "Kopaniem nic tu nie osi±gniesz.";
  Disrobe: switch (n) {
        1:  "Nie masz na sobie ", (dop) x1, ".";
        2:  "Zdejmujesz ", (bie) x1, ".";
    }
  Drink:    print (Cname) x1 ," nie ", (NadawacSie) x1, " siê do picia.";
  Drop: switch (n) {
        1:  if (x1 has pluralname) print (The) x1, " are "; else print (The) x1, " is ";
            "already here.";
        2:  "You haven't got ", (ToLubTe) x1, ".";
        3:  "(zdejmujesz ", (bie) x1, ")";
        4:  print "Zostawiasz ", (bie) x1, ".^";
    }
  Eat: switch (n) {
        1:  if (x1 == player) "Cokolwiek my¶lisz, autokanibalizm nie jest rozwi±zaniem.";
          print_ret (Cname) x1, " nie nadaje siê do jedzenia.";
        2:  "Zjadasz ", (bie) x1, ".", (JestSmaczny) x1;
    }
  EmptyT: switch (n) {
        1:  print_ret (Cname) x1, " nie s³u¿y do przechowywania.";
        2:  print_ret (Cname) x1, " ", (JestLubSa) x1, " ", (JestZamkniety) x1, ".";
        3:  print_ret (Cname) x1, " ", (JestLubSa) x1, " ju¿ ", (JestPusty) x1,".";
        4:  "That would scarcely empty anything.";
    }
  Enter: switch (n) {
        1:  print "Przecie¿ jeste¶ ju¿ ";
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
        1:  "Ciemno¶æ, rzeczownik. Oznacza brak ¶wiat³a...";
        2:  "Nie widzisz w ", (mie) x1, " nic specjalnego.";
        3:  print "Obecnie ", (name) x1, " ", (JestLubSa) x1, " ";
            if (x1 has on) print (JestWlaczony) x1,"."; else print (JestWylaczony) x1, ".^";
    }
  Exit: switch (n) {
        1:  "Nie znajdujesz siê w tej chwili we wnêtrzu niczego konkretnego.";
        2:  "Nie mo¿esz wyj¶æ z ", (dop) x1, " poniewa¿ ", (JestLubSa) x1, " ", (JestZamkniety) x1, "." ;
        3:  if (x1 has supporter) print "Schodzisz z "; else print "Wychodzisz z ";
            print_ret (dop) x1, ".";
        4:  print "Przecie¿ nie jeste¶ ";
            if (x1 has supporter) print "na "; else print "w ";
            print_ret (mie) x1, ".";
    }
  Fill:     "Ale tu nie ma wody do nape³nienia.";
  FullScore: switch (n) {
        1:  if (deadflag) print "Na wynik z³o¿y³y siê "; else print "Na wynik sk³adaj± siê ";
            "nastêpuj±ce osi±gniêcia:^";
        2:  "finding sundry items";
        3:  "visiting various places";
        4:  print "     ³±cznie: ";
        5:  print " (z maksymalnie ", MAX_SCORE, (LiczPunkty) MAX_SCORE, ").";
    }
  GetOff:   "Nie jeste¶ w tym/na ", (mie) x1, ".";
  Give: switch (n) {
        1:  "Nie posiadasz ", (dop) x1, ".";
        2:  "You juggle ", (the) x1, " for a while, but don't achieve much.";
        3:  print (Cname) x1;
            if (x1 has pluralname) print " don't"; else print " doesn't";
            " seem interested.";
    }
  Go: switch (n) {
        1:  print "Najpierw musisz ";
            if (x1 has supporter) print "zej¶æ ", (pl_z) x1; else print "wyj¶æ ", (pl_z) x1;
            print_ret (dop) x1, ".";
        2:  print_ret (string) CANTGO__TX;   ! "Nie mo¿esz udaæ siê w tym kierunku."
        3:  "You are unable to climb ", (the) x1, ".";
        4:  "You are unable to descend by ", (the) x1, ".";
        5:  "Nie mo¿esz udaæ siê w tym kierunku, poniewa¿ na twojej drodze ", (StoiLubStoja) x1, " ", (name) x1,".";
        6:  print "You can't, since ", (the) x1;
            if (x1 has pluralname) " lead nowhere."; else " leads nowhere.";
    }
  Insert: switch (n) {
        1:  "Musisz najpierw trzymaæ ", (bie) x1, " zanim bêdziesz móg³ ", (itorthem) x1,
            " w³o¿yæ do czego¶ innego.";
        2:  print_ret "Niestety, ", (name) x1 ," nie s³u¿y do przechowywania innych rzeczy.";
        3:  print_ret (Cname) x1, " ", (JestLubSa) x1, " ",(JestZamkniety) x1, ".";
        4:  "Musisz najpierw ", (itorthem) x1, " zdj±æ.";
        5:  "Nie mo¿esz w³o¿yæ czego¶ do ¶rodka siebie samego.";
        6:  "(najpierw zdejmujesz ", (bie) x1, ")^";
        7:  "W ", (mie) x1, " nie ma ju¿ miejsca.";
        8:  "Zrobione.";
        9:  print "Wk³adasz ", (bie) x1, " do ", (dop) second, ".^";
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
  Kiss:     "Lepiej skup siê na grze.";
  Listen:   "Nie s³yszysz niczego konkretnego.";
  ListMiscellany: switch (n) {
        1:  print " (¶wieci)";
        2:  print " (", (ktoryktoraktore) x1, " ", (JestLubSa) x1, " ", (JestZamkniety) x1,")";
        3:  print " (", (ktoryktoraktore) x1, " ", (JestLubSa) x1, " ", (JestZamkniety) x1," i ¶wieci)";
        4:  print " (", (ktoryktoraktore) x1, " ", (JestLubSa) x1, " ", (JestPusty) x1,")";
        5:  print " (", (ktoryktoraktore) x1, " ", (JestLubSa) x1, " ", (JestPusty) x1," i ¶wieci)";
        6:  print " (", (ktoryktoraktore) x1, " ", (JestLubSa) x1, " ", (JestZamkniety) x1," i ", (JestPusty) x1,")";
        7:  print " (", (JestOtwarty) x1,", ", (JestPusty) x1, " i ¶wieci)";
        8:  print " (¶wieci i ", (JestUbrany) x1;
        9:  print " (¶wieci";
        10: print " (", (JestUbrany) x1;
        11: print " (...", (ktoryktoraktore) x1, " ";!, (JestLubSa) x1, " ";
        12: print (JestLubSa) x1, " ", (JestOtwarty) x1;
        13: print (JestLubSa) x1, " ", (JestOtwarty) x1," i ", (JestPusty) x1;
        14: print (JestLubSa) x1, " ", (JestZamkniety) x1;
        15: print (JestLubSa) x1, " ", (JestZamkniety) x1, " na klucz";
        16: print " oraz ", (JestPusty) x1;
        17: print " (", (ktoryktoraktore) x1, " ", (JestLubSa) x1, " ", (JestPusty) x1;
        18: print " containing ";
        19: print " (na "; ! na którym jest to i tamto
        20: print ", on top of ";
        21: print " (w ";
        22: print ", wewn±trz ";
    }
  LMode1:   "Zosta³ uruchomiony tryb ~normalnego~ wy¶wietlania opisów lokacji, tzn. po pierwszym wej¶ciu do danej lokacji
                poka¿e siê jej pe³ny opis, natomiast przy ka¿dym nastêpnym - skrócony.";
  LMode2:   "Zosta³ uruchomiony tryb ~pe³nego~ wy¶wietlania opisów lokacji, tzn. po wej¶ciu do danej lokacji zawsze
                poka¿e siê jej pe³ny opis, nawet je¶li zosta³a ona ju¿ wcze¶niej odwiedzona.";
  LMode3:   "Zosta³ uruchomiony tryb ~skróconego~ wy¶wietlania opisów lokacji, tzn. po wej¶ciu do danej lokacji
                poka¿e siê jej skrócony opis, nawet je¶li nie by³a ona wcze¶niej odwiedzana.";
  Lock: switch (n) {
        1:  "W ", (cel) x1, " nie ma zamka.";
        2:  print (Cname) x1, " "; if (x1 has pluralname)       { print "s± ju¿ zamkniête na klucz.^"; return; }
            if (x1 has female)       { print "jest ju¿ zamkniêta na klucz.^"; return; }
            else if (x1 hasnt neuter) { print "jest ju¿ zamkniêty na klucz.^"; return; }
            print "jest ju¿ zamkniête na klucz.^";
        3:  "(zamykajac ", (bie) x1, ")";
        4:  print (Cname) x1, " nie "; if (x1 has pluralname) print "pasuj± "; else print "pasuje ";
            "do zamka.";
        5:  "Zamykasz zamek w ", (mie) x1, " za pomoc± ", (dop) second, ".";
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
            if (n == 5) print "tak¿e ";
            ! print "see ";
            WriteListFrom(child(x1),
              ENGLISH_BIT+RECURSE_BIT+PARTINV_BIT+TERSE_BIT+CONCEAL_BIT+BIERNIK_BIT+WORKFLAG_BIT);
            !if (x1 == location) "."; else " here.";
            print ".^";
        7:  "Nie dostrzegasz w tym kierunku niczego szczególnie interesuj±cego.";
    }
  LookUnder: switch (n) {
        1:  "Przecie¿ jest ciemno.";
        2:  "Nie znajdujesz nic ciekawego.";
    }
  Mild:     "Quite.";
  Miscellany: switch (n) {
        1:  "(considering the first sixteen objects only)^";
        2:  "Nothing to do!";
        3:  print " Zgin±³e¶ ";
        4:  print " Zwyciê¿y³e¶ ";
        5:  print "^Czy chcesz ZRESTARTOWAÆ, ZA£ADOWAÆ  zapisany stan gry";
            #Ifdef DEATH_MENTION_UNDO;
            print ", COFN¡Æ  swój ostatni ruch";
            #Endif;
            if (TASKS_PROVIDED == 0) print ", zobaczyæ PE£NY WYNIK";
            if (deadflag == 2 && AMUSING_PROVIDED == 0)
                print ", see some suggestions for AMUSING things to do";
            " czy ZAKOÑCZYÆ€ ?";
        6:  "[Niestety! U¿ywany przez ciebie interpreter nie pozwala wykonaæ ~cofania~.]";
            #Ifdef TARGET_ZCODE;
        7:  "~Undo~ failed.  [Not all interpreters provide it.]";
            #Ifnot; ! TARGET_GLULX
        7:  "[You cannot ~undo~ any further.]";
            #Endif; ! TARGET_
        8:  "Udziel proszê jednej ze wskazanych powy¿ej odpowiedzi.";
        9:  "^Nagle wokó³ zapad³y nieprzeniknione ciemno¶ci!";
        10: "S³ucham?";
        11: "[Nie mo¿esz ~cofn±æ~ czego¶ co nie zosta³o zrobione!]";
        12: "[Can't ~undo~ twice in succession. Sorry!]";
        13: "[Poprzedni ruch zosta³ cofniêty.]";
        14: "Sorry, that can't be corrected.";
        15: "Think nothing of it.";
        16: "~Oops~ can only correct a single word.";
        17: "It is pitch dark, and you can't see a thing.";
        18: print "yourself";
        19: "Jak zwykle wygl±dasz ¶wietnie.";
        20: "Aby powtórzyæ polecenie, przyk³adowo ~¿aba, podskocz~, wystarczy powiedziæ ~powtórz~, a nie ~¿aba, powtórz~.";
        21: "You can hardly repeat that.";
        22: "Nie mo¿esz zaczynaæ zdania od przecinka.";
        23: "Wygl±da na to, ¿e próbujesz z kim¶ porozmawiaæ, ale nie bardzo widzê z kim.";
        24: "You can't talk to ", (the) x1, ".";
        25: "To talk to someone, try ~someone, hello~ or some such.";
        26: "(bierzesz ", (bie) not_holding, ")";
        27: "Nie zrozumia³em tego zdania.";
        28: print "Zrozumia³em tylko tyle, ¿e usi³ujesz ";
        29: "I didn't understand that number.";
        30: "Nie widzisz nic takiego.";
        31: "You seem to have said too little!";
        32: "You aren't holding that!";
        33: "Ten czasownik mo¿na zastosowaæ tylko do pojedynczego obiektu.";
        34: "You can only use multiple objects once on a line.";
        35: "I'm not sure what ~", (address) pronoun_word, "~ refers to.";
        36: "You excepted something not included anyway!";
        37: "To jedno z tych poleceñ, które nie dzia³a na przedmioty martwe.";
        38: "Nie znam takiego czasownika.";
        39: "To nie jest co¶ do czego musisz siê odnosiæ podczas tej gry.";
        40: "You can't see ~", (address) pronoun_word, "~ (", (the) pronoun_obj,
            ") at the moment.";
        41: "I didn't understand the way that finished.";
        42: if (x1 == 0) print "None"; else print "Only ", (number) x1;
            print " of those ";
            if (x1 == 1) print "is"; else print "are";
            " available.";
        43: "Nothing to do!";
        44: "There are none at all available!";
        45: print "Sprecyzuj kogo dok³adnie masz na my¶li, ";
        46: print "Sprecyzuj co dok³adnie masz na my¶li, ";
        47: "Sorry, you can only have one item here. Which exactly?";
        48: QuestionVerb();
            if (actor ~= player) print " ", (the) actor;
            ! print "to ";
            PrintCommand(); print "?^";
        49: QuestionVerb();
            if (actor ~= player) print " kazaæ ", (cel) actor;
            PrintCommand(0); print "?^";
        50: print "Twój wynik w³a¶nie ";
            if (x1 > 0) print "wzrós³"; else { x1 = -x1; print "zmniejszy³ siê"; }
            print " o ", (number) x1, (LiczPunkty) x1;
        51: "(Since something dramatic has happened, your list of commands has been cut short.)";
        52: "^Type a number from 1 to ", x1, ", 0 to redisplay or press ENTER.";
        53: "^[Naci¶nij SPACJÊ.]";
        54: "[Comment recorded.]";
        55: "[Comment NOT recorded.]";
        56: print ".^";
        57: print "?^";
    }
  No,Yes:   "To by³o pytanie retoryczne.";
  NotifyOff:
            "Score notification off.";
  NotifyOn: "Score notification on.";
  Objects: switch (n) {
        1:  "Rzeczy, które jak dot±d by³y lub obecnie znajduj± siê w Twoim posiadaniu:^";
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
        1:  print_ret (Cname) x1, " nie ", (JestLubSa) x1, " czym¶ co dawa³oby siê otworzyæ.";
        2:  print (Cname) x1, " ", (JestLubSa) x1, " ", (JestZamkniety) x1, " na klucz.^";
        3:  print_ret (Cname) x1, " ", (JestLubSa) x1," ju¿ ", (JestOtwarty) x1,".";
        4:  print "Otwierasz ", (bie) x1, ", znajduj±c ";
            if (WriteListFrom(child(x1), ENGLISH_BIT+TERSE_BIT+CONCEAL_BIT+BIERNIK_BIT) == 0) "puste wnêtrze.";
            ".";
        5:  "Otwierasz ", (bie) x1, ".";
    }
  Order:    print (The) x1;
            if (x1 has pluralname) print " have"; else print " has";
            " better things to do.";
  Places: switch (n) {
        1:  print "Lista odwiedzonych pomieszczeñ: ";
        2:  print ".^";
    }
  Pray:     "Twoja modlitwa nie da³a ¿adnego widocznego rezultatu.";
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
        2:  "Nie jeste¶ w stanie tego zrobiæ.";
        3:  "Nic specjalnego siê nie sta³o.";
        4:  "To by³oby bardzo niekulturalne.";
    }
! Push: see Pull
  PushDir: switch (n) {
        1:  "Nic lepszego nie uda³o ci siê wymy¶liæ?";
        2:  "To nie jest prawid³owo wskazany kierunek.";
        3:  "W tym kierunku niestety siê nie da.";
    }
  PutOn: switch (n) {
        1:  "Musisz trzymaæ ", (bie) x1, " ¿eby móc ", (itorthem) x1, " po³o¿yæ na czym¶ innym.";
        2:  "You can't put something on top of itself.";
        3:  "Putting things on ", (the) x1, " would achieve nothing.";
        4:  "You lack the dexterity.";
        5:  "(najpierw zdejmujesz ", (bie) x1, ")^";
        6:  "There is no more room on ", (the) x1, ".";
        7:  "Zrobione.";
        8:  "Odk³adasz ", (bie) x1, " na ", (mie) second, ".";
    }
  Quit: switch (n) {
        1:  print "Odpowiedz ~tak~ lub ~nie~.";
        2:  print "Czy na pewno chcesz zakoñczyæ grê? ";
    }
  Remove: switch (n) {
        1:  print "Niestety", (JestLubSa) x1, " ", (JestZamkniety) x1,".";
        2:  if (x1 has pluralname) print "But they aren't"; else print "But it isn't";
            " there now.";
        3:  if (player has female) print "Wyjê³a¶.^"; else print "Wyj±³e¶.^";
    }
  Restart: switch (n) {
        1:  print "Czy na pewno chcesz uruchomiæ grê ponownie? ";
        2:  "Nie uda³o siê.";
    }
  Restore: switch (n) {
        1:  "Nie uda³o siê za³adowaæ zapisanej gry.";
        2:  "Ok.";
    }
  Rub:      "Nie uda³o Ci siê w ten sposób osi±gn±æ niczego konkretnego.";
  Save: switch (n) {
        1:  "Nie uda³o siê zapisaæ stanu gry.";
        2:  "Ok.";
    }
  Score: switch (n) {
        1:  if (turns>0) print "W czasie ", (LiczTury) turns; else print "Jak dot±d";
            print " uda³o Ci siê zdobyæ ";
            print score, " z mo¿liwych do zdobycia ", MAX_SCORE, (LiczPunkty) MAX_SCORE;
            return;
        2:  "W tej opowie¶ci nie s± liczone punkty.";
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
        1:  "Przecie¿ jest ciemno.";
        2:  "Na ", (mie) x1, " nic nie ma.";
        3:  print "Na ", (mie) x1;
            WriteListFrom(child(x1), ENGLISH_BIT+TERSE_BIT+CONCEAL_BIT+ISARE_BIT);
            ".";
        4:  "You find nothing of interest.";
        5:  "Nie mo¿esz zobaczyæ co jest w ¶rodku, poniewa¿ ", (name) x1, " ", (JestLubSa) x1, " ", (JestZamkniety) x1, ".";
        6:  print_ret "Stwierdzasz, ¿e ", (name) x1, " ", (JestPusty) x1, ".";
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
  Sleep:    "Nie czujesz szczególnego zmêczenia.";
  Smell:    "Nie wyczuwasz niczego specjalnego.";
  Sorry:    "Nie musisz przepraszaæ!";
  Squeeze: switch (n) {
        1:  "Trzymaj rêce przy sobie.";
        2:  "Nic w ten sposób nie osi±gniesz.";
    }
  Strong:   "Poszukiwacze przygód nie u¿ywaj± takiego jêzyka.";
  Swim:     "There's not enough water to swim in.";
  Swing:    "There's nothing sensible to swing here.";
  SwitchOff: switch (n) {
        1:  print_ret (Cname) x1, " nie ", (JestLubSa) x1, " czym¶ co dawa³oby siê w³±czyæ lub wy³±czyæ.";
        2:  print_ret (Cname) x1, " jest ju¿ ", (JestWylaczony) x1,".";
        3:  "Wy³±czasz ", (bie) x1, ".";
    }
  SwitchOn: switch (n) {
        1:  print_ret (Cname) x1, " nie ", (JestLubSa) x1, " czym¶ co dawa³oby siê w³±czyæ lub wy³±czyæ.";
        2:  print_ret (Cname) x1, " jest ju¿ ", (JestWlaczony) x1,".";
        3:  "W³±czasz ", (bie) x1, ".";
    }
  Take: switch (n) {
        1:  "Bierzesz ", (bie) x1,".";
        2:  "Próbujesz wi±¶æ siê trochê w gar¶æ.";
        3:  "I don't suppose ", (the) x1, " would care for that.";
        4:  print "You'd have to get ";
            if (x1 has supporter) print "off "; else print "out of ";
            print_ret (the) x1, " first.";
        5:  "Ju¿ masz przy sobie ", (bie) x1, ".";
        6:  print "Nie mo¿esz, poniewa¿ ", (name) x1, " "; if (noun has pluralname) print "nale¿± "; else print "nale¿y ";
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
        12: "Nic z tego. Masz przy sobie za du¿o rzeczy!";
        13: "(wk³adasz ", (bie) x1, " do ", (dop) SACK_OBJECT, " aby zrobiæ miejsce)";
    }
  Taste:    "Nie znajdujesz nic nieoczekiwanego w smaku ", (dop) x1,".";
  Tell: switch (n) {
        1:  "Przez chwilê mamroczesz co¶ do siebie pod nosem.";
        2:  "Jedyn± odpowiedzi± jest brak jakiejkolwiek reakcji.";
    }
  Think:    "¶wietny pomys³.";
  ThrowAt: switch (n) {
        1:  "Futile.";
        2:  "You lack the nerve when it comes to the crucial moment.";
    }
! Tie:  see JumpOver.
  Touch: switch (n) {
        1:  "Trzymaj rêce przy sobie!";
        2:  "Nie czujesz nic nadzwyczajnego.";
        3:  "Je¶li s±dzisz, ¿e to pomo¿e...";
    }
! Turn: see Pull.
  Unlock:  switch (n) {
        1:  print_ret (Cname) x1,
            " nie ", (JestLubSa) x1, " czym¶ co mo¿na otworzyæ za pomoc± ", (dop) second, ".";
        2:  print_ret (ctheyreorthats) x1, " unlocked at the moment.";
        3:  if (x1 has pluralname) print "Nie pasuj± "; else print "Nie pasuje ";
            "do zamka.";
        4:  "Odblokowujesz ", (bie) x1, " za pomoc± ", (dop) second,".";

    }
  VagueGo:  "Musisz sprecyzowaæ kierunek, w którym chcesz siê udaæ.";
  Verify: switch (n) {
        1:  "The game file has verified as intact.";
        2:  "The game file did not verify as intact, and may be corrupt.";
    }
  Wait:     "Up³ywa trochê czasu.";
  Wake:     "The dreadful truth is, this is not a dream.";
  WakeOther:"That seems unnecessary.";
  Wave: switch (n) {
        1:  "But you aren't holding ", (ToLubTe) x1, ".";
        2:  "You look ridiculous waving ", (the) x1, ".";
    }
WaveHands:"Czujesz siê trochê g³upi tak sobie wymachuj±c rêkami.";
  Wear: switch (n) {
        1:  "Nie mozesz za³o¿yæ na siebie ", (dop) x1, "!";
        2:  "Nie trzymasz ", (dop) x1, "!";
        3:  "Masz ju¿ na sobie ", (bie) x1, "!";
        4:  "Zak³adasz ", (bie) x1, ".";
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



  ! - RZECZOWNIK -> -³A

  if (l >= 2 && a->(l-2) == '³' && a->(l-1) == 'a') {

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
