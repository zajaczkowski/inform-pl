
!% -C2
! ==============================================================================
!   GRAMMAR:  Zawiera informacje o rozpoznawanych przez kompilator czasownikach.
!
!   Przeznaczony do uzywania z kompilatorem Inform 6.
!
!   Wersja 6/11/PL
!   Copyright Bartosz Zajaczkowski 2011-2014
!       z mozliwosci� swobodnego korzystania.
!
!   Original 6/11 Library
!   Copyright Graham Nelson 1993-2004 but freely usable (see manuals)
!

! ==============================================================================



System_file;

! ------------------------------------------------------------------------------
!  The "meta-verbs", commands to the game rather than in the game, come first:
! ------------------------------------------------------------------------------

Verb meta 'brief' 'normalne'
    *                                           -> LMode1;
Verb meta 'verbose' 'pelne'
    *                                           -> LMode2;
Verb meta 'superbrief' 'skrocone'
    *                                           -> LMode3;
Verb meta 'opisy'
    * 'normalne'                                -> LMode1
    * 'pelne'/'dlugie'                          -> LMode2
    * 'skrocone'/'krotkie'                      -> LMode3;


Verb meta 'notify'
    *                                           -> NotifyOn
    * 'on'                                      -> NotifyOn
    * 'off'                                     -> NotifyOff;
Verb meta 'pronouns' 'nouns'
    *                                           -> Pronouns;
Verb meta 'zakoncz' 'skoncz''quit' 'q//' 'die'
    *                                           -> Quit;
Verb meta 'recording'
    *                                           -> CommandsOn
    * 'on'                                      -> CommandsOn
    * 'off'                                     -> CommandsOff;

Verb meta 'replay'
    *                                           -> CommandsRead;

Verb meta 'restart' 'zrestartuj' 'restartuj'
    *                                           -> Restart;

Verb meta 'restore' 'zaladuj' 'wczytaj'
    *                                           -> Restore;
Verb meta 'save' 'zapisz'
    *                                           -> Save;
Verb meta 'score' 'wynik'
    *                                           -> Score;
Verb meta 'fullscore' 'full' 'pe�ny'
    *                                           -> FullScore
    * 'wynik'                                   -> FullScore
    * 'score'                                   -> FullScore;

Verb meta 'script' 'transcript'
    *                                           -> ScriptOn
    * 'on'                                      -> ScriptOn
    * 'off'                                     -> ScriptOff;

Verb meta 'noscript' 'unscript'
    *                                           -> ScriptOff;

Verb meta 'verify' 'zweryfikuj'
    *                                           -> Verify;

Verb meta 'version' 'wersja'
    *                                           -> Version;

#Ifndef NO_PLACES;
Verb meta 'objects' 'przedmioty' 'obiekty'
    *                                           -> Objects;
Verb meta 'places' 'miejsca'
    *                                           -> Places;
#Endif; ! NO_PLACES

! ------------------------------------------------------------------------------
!  Debugging grammar
! ------------------------------------------------------------------------------

#Ifdef DEBUG;
Verb meta 'actions'
    *                                           -> ActionsOn
    * 'on'                                      -> ActionsOn
    * 'off'                                     -> ActionsOff;
Verb meta 'changes'
    *                                           -> ChangesOn
    * 'on'                                      -> ChangesOn
    * 'off'                                     -> ChangesOff;
Verb meta 'gonear'
    * noun                                      -> Gonear;
Verb meta 'goto'
    * number                                    -> Goto;
Verb meta 'random'
    *                                           -> Predictable;
Verb meta 'routines' 'messages'
    *                                           -> RoutinesOn
    * 'on'                                      -> RoutinesOn
    * 'off'                                     -> RoutinesOff;
Verb meta 'scope'
    *                                           -> Scope
    * noun                                      -> Scope;
Verb meta 'showobj'
    *                                           -> Showobj
    * number                                    -> Showobj
    * multi                                     -> Showobj;
Verb meta 'showverb'
    * special                                   -> Showverb;
Verb meta 'timers' 'daemons'
    *                                           -> TimersOn
    * 'on'                                      -> TimersOn
    * 'off'                                     -> TimersOff;
Verb meta 'trace'
    *                                           -> TraceOn
    * number                                    -> TraceLevel
    * 'on'                                      -> TraceOn
    * 'off'                                     -> TraceOff;
Verb meta 'abstract'
    * noun 'to' noun                            -> XAbstract;
Verb meta 'purloin'
    * multi                                     -> XPurloin;
Verb meta 'tree'
    *                                           -> XTree
    * noun                                      -> XTree;

#Ifdef TARGET_GLULX;
Verb meta 'glklist'
    *                                           -> Glklist;
#Endif; ! TARGET_

#Endif; ! DEBUG

! ------------------------------------------------------------------------------
!  Bazowa lista czasownik�w u�ywanych w grze.
! ------------------------------------------------------------------------------

[ ADirection; if (noun in compass) rtrue; rfalse; ];



! ------------------------------------
! Pozosta�o�ci angielskich czasownik�w
! ------------------------------------

Verb 'bother' 'curses' 'darn' 'drat'
    *                                           -> Mild
    * topic                                     -> Mild;

Verb 'set' 'adjust'
    * noun                                      -> Set
    * noun 'to' special                         -> SetTo;


Verb 'swing'
    * noun                                      -> Swing
    * 'on' noun                                 -> Swing;


Verb 'tie' 'attach' 'fasten' 'fix'
    * noun                                      -> Tie
    * noun 'to' noun                            -> Tie;



Verb 'wake' 'awake' 'awaken'
    *                                           -> Wake
    * 'up'                                      -> Wake
    * creature                                  -> WakeOther
    * creature 'up'                             -> WakeOther
    * 'up' creature                             -> WakeOther;




! -------------------
!  Lista czasownik�w
! -------------------


Verb 'dmij' 'zadmij' 'dmuchaj' 'dmuchnij'
    * 'w' biernikheld                           			-> Blow;


Verb 'czekaj' 'poczekaj' 'zaczekaj'
    *                                           			-> Wait;


Verb 'ci�gnij' 'poci�gnij'
    * bierniknoun                               			-> Pull
    * 'za' bierniknoun                          			-> Pull;


Verb 'czytaj' 'przeczytaj'
    * bierniknoun                               			-> Examine
    * 'o' topic 'w' miejscowniknoun             			-> Consult
    * 'w' miejscowniknoun 'o' topic							-> Consult;


Verb 'daj' 'oddaj'
    * biernikheld celownikcreature              			-> Give
    * celownikcreature biernikheld              			-> Give reverse;


Verb 'dotknij'
    * dopelniacznoun                            			-> Touch;


Verb 'id�' 'biegnij' 'pobiegnij' 'p�jd�'
    *                                           			-> VagueGo
    * 'na' noun=ADirection                      			-> Go
    * 'do' noun=ADirection                      			-> GoIn;


Verb 'i//' 'inwentarz'
    *                                           			-> Inv
    * 'lista'                                   			-> InvTall
    * 'opis'                                    			-> InvWide;


Verb 'kop'
    * 														-> Dig
    * 'w' miejscowniknoun                       			-> Dig
    * 'w' miejscowniknoun narzednikheld         			-> Dig
    * narzednikheld 'w' miejscowniknoun         			-> Dig;


Verb 'kup' 'zakup'
    * bierniknoun                               			-> Buy;


Verb 'nape�nij'
    * bierniknoun                               			-> Fill;


Verb 'napij'
    * 'si�' dopelniacznoun                      			-> Drink
    * 'si�' 'z'/'ze' dopelniacznoun             			-> Drink;


Verb 'nie' 'n//'
    *                                           			-> No;


Verb 'obejrzyj' 'ob//' 'zobacz' 'x//'
    * bierniknoun                               			-> Examine;


Verb 'odblokuj'
    * bierniknoun narzednikheld                 			-> Unlock
    * narzednikheld bierniknoun                 			-> Unlock;


Verb 'od��'
    * biernikmultiheld                          			-> Drop
    * biernikheld 'w' miejscowniknoun           			-> Insert
    * biernikmultiexcept 'do' dopelniacznoun    			-> Insert
    * biernikmultiexcept 'na' bierniknoun       			-> PutOn;


Verb 'odpowiedz' ! niedoko�czony - 'say' 'shout' 'speak'
    * topic 'to' creature                       			-> Answer;


Verb 'opr�nij'
    * bierniknoun                               			-> Empty
    * bierniknoun 'na'/'do' dopelniacznoun      			-> EmptyT;


Verb 'otw�rz'
    * bierniknoun                               			-> Open
    * bierniknoun narzednikheld                 			-> Unlock
    * narzednikheld bierniknoun                 			-> Unlock;


Verb 'pchnij' 'popchnij' 'przesu�'
    * bierniknoun                               			-> Push
    * bierniknoun 'na' noun                     			-> PushDir;


Verb 'ply�' 'poply�'
    *                                           			-> Swim;


Verb 'poca�uj' 'ca�uj' 'przytul' 'u�ciskaj'
    * biernikcreature                           			-> Kiss;


Verb 'podpal'
    * bierniknoun                                           -> Burn
    * bierniknoun narzednikheld                             -> Burn;


Verb 'podskocz' 'skocz'
    *                                           			-> Jump;


Verb 'poka�'
    * 'inwentarz'                                           -> Inv
    * celownikcreature biernikheld              			-> Show reverse
    * biernikheld celownikcreature              			-> Show;


Verb 'po��'
    * 'si�' 'na' miejscowniknoun                			-> Enter
    * 'si�' 'w' miejscowniknoun                 			-> Enter
    * biernikmultiheld                          			-> Drop
    * biernikmultiheld 'w' miejscowniknoun           		-> Insert
    * biernikmultiexcept 'do' dopelniacznoun    			-> Insert
    * biernikmultiexcept 'na' miejscowniknoun   			-> PutOn;


Verb 'pomachaj' 'machaj'
    *                                                       -> WaveHands
    * narzedniknoun                                         -> Wave;


Verb 'pom�dl' 'm�dl'
    * 														                    -> Pray
    * 'si�'                                     			-> Pray;


Verb 'pomy�l' 'my�l'
    *                                           			-> Think;


Verb 'popro�' 'pro�'
    * biernikcreature 'o' bierniknoun           			-> AskFor;


Verb 'ustaw' 'postaw'
    * biernikmulti                                          -> Drop
    * biernikmultiexcept 'na' miejscowniknoun               -> PutOn;


Verb 'potrzyj' 'przetrzyj' 'wytrzyj'
    * bierniknoun                               			-> Rub;


Verb 'pow�chaj' 'w�chaj'
    * bierniknoun                               			-> Smell;


Verb 'powiedz'
    * celownikcreature 'o' topic                			-> Tell
    * celownikcreature topic                    			-> AskTo;


Verb 'przekr��' 'dokr��' 'obr��' 'odkr��' 'zakr��'
    * bierniknoun                                           -> Turn;


Verb 'przenie�' 'prze��'
    * bierniknoun 'do' dopelniacznoun           			-> Transfer;


Verb 'przeskocz'
    * 'nad' miejscowniknoun                     			-> JumpOver;


Verb 'przeszukaj'
    * bierniknoun                               			-> Search;


Verb 'przepro�'
    *                                           			-> Sorry;


Verb 'prze�pij' 'zdrzemnij'
    * 'si�'                                     			-> Sleep;


Verb 'przetnij' 'kr�j' 'przekr�j' 'tnij'
    * bierniknoun                               			-> Cut;


Verb 'przyjrzyj'
    * 'si�' celowniknoun                        			-> Examine;

Verb 'rozejrzyj'
    *                                                 -> Look
    * 'si�'                                           -> Look;

Verb 'rzu�'
    * biernikmultiheld										-> Drop
    !* biernikheld 'w' biernikcreature          			-> Attack
    * narzednikheld celownikcreature                        -> Give
    * narzednikheld 'w' bierniknoun             			-> ThrowAt
    !* biernikmultiheld 'w' bierniknoun         			-> Insert
    * biernikmultiheld 'do' dopelniacznoun      			-> Insert
    * biernikmultiexcept 'na'/'w' miejscowniknoun 			-> PutOn;


Verb 'schowaj'
    * bierniknoun 'w' miejscowniknoun           			-> Insert
    * biernikmulti 'do' dopelniacznoun          			-> Insert;


Verb 'si�d�' 'usi�d�'
    * 'na' miejscowniknoun                                  -> Enter
    * 'w' miejscowniknoun                                   -> Enter;


Verb 's�uchaj' 'pos�uchaj'
    *                                           			-> Listen
    * dopelniacznoun                            			-> Listen;


Verb '�pij' 'za�nij'
    *                                                       -> Sleep;


Verb 'sp�jrz' 'sp//' 'popatrz'   ! TU ZMIANA
    *                                           			-> Look
    * 'na' bierniknoun                          			-> Examine
    * 'na' noun=ADirection                      			-> Examine
    * 'pod'/'za' bierniknoun                    			-> LookUnder;


Verb 'sprawd�' 'skonsultuj'
    * topic 'w' miejscowniknoun                             -> Consult
    * bierniknoun                                           -> Examine;


Verb 'spr�buj' 'skosztuj'
    * bierniknoun                                           -> Taste;


Verb 'sta�'
    * 'na' miejscowniknoun                      			-> Enter;


Verb 'szukaj' 'odszukaj' 'poszukaj'
    * dopelniacznoun                            			-> Search
    * topic 'w' miejscowniknoun                   			-> Consult
    * 'pod'/'za'/'na' narzedniknoun             			-> LookUnder;


Verb '�ci�nij' 'zgnie�'
    * bierniknoun                               			-> Squeeze;


Verb 'tak' 't//'
    *                                           			-> Yes;


Verb 'uruchom'
    * 'ponownie'                                			-> Restart
    * bierniknoun                               			-> SwitchOn;


Verb 'wdrap' 'wespnij'
    * 'sie' 'na' bierniknoun                    			-> Climb
    * 'sie' 'po' miejscowniknoun							-> Climb;


Verb 'we�' 'zabierz' 'podnie�'  ! TU ZMIANA
    * biernikmulti                                          -> Take
    * multiinside 'from' noun                               -> Remove;          ! <- tu jest problem, kt�ry wymaga poprawek w parserze... :(


Verb 'wejd�'
    *                                           			-> GoIn
    * 'do' noun=ADirection                      			-> GoIn
    * 'do' dopelniacznoun                       			-> Enter
    * 'na' bierniknoun                          			-> Enter
    * 'w' bierniknoun                           			-> Enter
    * 'po' miejscowniknoun									-> Climb;


Verb 'w��cz' 'zapal'
    * bierniknoun                               			-> SwitchOn;


Verb 'w��'
    * biernikheld                               			-> Wear
    * biernikmultiheld 'w' bierniknoun              	-> Insert
    * biernikmultiheld 'do' dopelniacznoun          	-> Insert;


Verb 'wrzu�'
    * biernikmultiheld 'do'/'w' dopelniacznoun  			-> Insert;


Verb 'wsiad�'
    * 'do' dopelniacznoun                       			-> Enter;


Verb 'wsta�'
    *                                                       -> Exit
    * 'z' dopelniacznoun                                    -> Exit;


Verb 'wyjd�'
    *                                           			-> Exit
    * 'na' 'zewnatrz'                           			-> Exit
    * 'na' noun=ADirection                      			-> Go
    * 'z' dopelniacznoun                        			-> Exit;


Verb 'wyjmij' 'wyciagnij'
!    * multiinside                                          -> Pull            ! <- to jest niejasne
    * multiinside 'z//'/'ze//' dopelniacznoun               -> Remove;


Verb 'wy��cz' 'zga�'
    * bierniknoun                               			-> SwitchOff;


Verb 'wypij'
    * bierniknoun                               			-> Drink;


Verb 'wyrzu�'
    * biernikmultiheld                                      -> Drop;


Verb 'wysiadz'
    *                                           			-> Exit
    * 'z' dopelniacznoun                        			-> Exit;


Verb 'zaatakuj' 'zniszcz'
    * bierniknoun                               			-> Attack
    * biernikcreature                                       -> Attack;


Verb 'zabij'
	* biernikcreature										-> Attack;


Verb 'uderz' 'walnij' 'kopnij'
	* 'w' bierniknoun                           			-> Attack
    * bierniknoun                               			-> Attack;


Verb 'zablokuj'
    * narzednikheld bierniknoun                 			-> Lock
    * bierniknoun narzednikheld                 			-> Lock;


Verb 'zajrzyj'
    * 'do' dopelniacznoun                       			-> Search
    * 'pod'/'za' bierniknoun                    			-> LookUnder;


Verb 'za��' 'ubierz'
    * biernikheld                               			-> Wear;


Verb 'zamknij'
    * bierniknoun                               			-> Close
    * bierniknoun narzednikheld                 			-> Lock
    * narzednikheld bierniknoun                 			-> Lock
    * bierniknoun 'na' biernikheld              			-> Lock;


Verb 'zapytaj' 'pytaj' 'spytaj'
    * biernikcreature 'o' topic                             -> Ask
    * biernikcreature 'o' bierniknoun                       -> AskFor;

    ! * creature 'to' topic                                 -> AskTo
    ! * 'that' creature topic                               -> AskTo;


Verb 'zastan�w'
    * 'sie'                                     			-> Think;


Verb 'za�piewaj' '�piewaj'
    *                                           			-> Sing;


Verb 'zjedz' 'po�knij' 'ugry�'
    * bierniknoun                                           -> Eat;


Verb 'znajd�'
    * topic 'w' miejscowniknoun                   			-> Consult
    * bierniknoun                               			-> Search;


Verb 'zdejmij'
    * bierniknoun                               			-> Disrobe;


Verb 'zejd�'
    *                                           			-> Exit
    * 'z'/'ze' dopelniacznoun	                			-> Exit;

Verb 'zostaw'
    * biernikmultiheld                                      -> Drop
    * biernikmultiexcept 'na' miejscowniknoun               -> PutOn
    * biernikmultiheld 'w' miejscowniknoun                  -> Insert;


Verb 'zsi�d�'
    * 'z'/'ze' dopelniacznoun	                			-> GetOff;





Verb 'shit' 'damn' 'fuck' 'sod' 'kurwa' 'huj' 'chuj' 'g�wno'
    *                                           			-> Strong
    * topic                                     			-> Strong;


! ------------------------------------------------------------------------------
!  This routine is no longer used here, but provided to help existing games
!  which use it as a general parsing routine:

[ ConTopic w;
    consult_from = wn;
    do w = NextWordStopped();
    until (w == -1 || (w == 'to' && action_to_be == ##Answer));
    wn--;
    consult_words = wn - consult_from;
    if (consult_words == 0) return -1;
    if (action_to_be == ##Answer or ##Ask or ##Tell) {
        w = wn; wn = consult_from; parsed_number = NextWord();
        if (parsed_number == 'the' && consult_words > 1) parsed_number = NextWord();
        wn = w;
        return 1;
    }
    return 0;
];

! ------------------------------------------------------------------------------
!  Final task: provide trivial routines if the user hasn't already:
! ------------------------------------------------------------------------------

#Stub AfterLife         0;
#Stub AfterPrompt       0;
#Stub Amusing           0;
#Stub BeforeParsing     0;
#Stub ChooseObjects     2;
#Stub DarkToDark        0;
#Stub DeathMessage      0;
#Stub GamePostRoutine   0;
#Stub GamePreRoutine    0;
#Stub InScope           1;
#Stub LookRoutine       0;
#Stub NewRoom           0;
#Stub ParseNumber       2;
#Stub ParserError       1;
#Stub PrintTaskName     1;
#Stub PrintVerb         1;
#Stub TimePasses        0;
#Stub UnknownVerb       1;

#Ifdef TARGET_GLULX;
#Stub HandleGlkEvent    2;
#Stub IdentifyGlkObject 4;
#Stub InitGlkWindow     1;
#Endif; ! TARGET_GLULX

#Ifndef PrintRank;
! Constant Make__PR;
! #Endif;
! #Ifdef Make__PR;
[ PrintRank; "."; ];
#Endif;

#Ifndef ParseNoun;
! Constant Make__PN;
! #Endif;
! #Ifdef Make__PN;
[ ParseNoun obj; obj = obj; return -1; ];
#Endif;

#Default Story 0;
#Default Headline 0;

#Ifdef INFIX;
#Include "infix";
#Endif;

! ==============================================================================

Constant LIBRARY_GRAMMAR;       ! for dependency checking

! ==============================================================================
