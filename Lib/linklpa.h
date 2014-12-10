! ==============================================================================
!   LINKLPA:  Link declarations of common properties and attributes.
!
!   Przeznaczony do uzywania z kompilatorem Inform 6. 
!   Wersja 6/11/PL - Numer seryjny 110416
!   Copyright Bartosz Zajaczkowski 2011 z mozliwosci swobodnego korzystania.
!   
!   Original 6/11 Library
!   Copyright Graham Nelson 1993-2004 but freely usable (see manuals)
!
!   Ten plik jest automatycznie dolaczany przez "Parser".
! ==============================================================================

System_file;

! ------------------------------------------------------------------------------
!   Some VM-specific constants.
!   (WORDSIZE and TARGET_XXX are defined by the compiler.)
! ------------------------------------------------------------------------------

#Ifdef TARGET_ZCODE;
Constant NULL         = $ffff;
Constant WORD_HIGHBIT = $8000;
#Ifnot; ! TARGET_GLULX
Constant NULL         = $ffffffff;
Constant WORD_HIGHBIT = $80000000;
#Endif; ! TARGET_

! ------------------------------------------------------------------------------
!   The common attributes and properties.
! ------------------------------------------------------------------------------

Attribute animate;
#Ifdef USE_MODULES;
    #Iffalse (animate == 0);
    Message error "Please move your Attribute declarations after the Include ~Parser~ line:
                   otherwise it will be impossible to USE_MODULES";
    #Endif;
#Endif;

Attribute absent;
Attribute clothing;
Attribute concealed;
Attribute container;
Attribute door;
Attribute edible;
Attribute enterable;
Attribute general;
Attribute light;
Attribute lockable;
Attribute locked;
Attribute moved;
Attribute on;
Attribute open;
Attribute openable;
Attribute proper;
Attribute scenery;
Attribute scored;
Attribute static;
Attribute supporter;
Attribute switchable;
Attribute talkable;
Attribute transparent;
Attribute visited;
Attribute workflag;
Attribute worn;

! W jezyku polskim bardzo wazne staje sie aby obiekty mialy zawsze zdefiniowany
! wlasciwy rodzaj. Standardowo jest zawsze zakladany rodzaj meski. Aby go zmienic
! trzeba ustawic odpowiedni artybut.

Attribute male;
Attribute female;
Attribute neuter;
Attribute pluralname;

! Dwa artybuty specyficzne dla jezyka polskiego
! Pomagaja one w rozpoznawaniu która forma jest prawidlowa
! "w" czy "we" lub "z" czy "ze" np. "ze sto³u", "w samochodzie"

Attribute w_article;
Attribute z_article;

! ------------------------------------------------------------------------------

Property additive before NULL;
Property additive after  NULL;
Property additive life   NULL;

Property n_to;
Property s_to;
Property e_to;
Property w_to;
Property ne_to;
Property nw_to;
Property se_to;
Property sw_to;
Property u_to;
Property d_to;
Property in_to;
Property out_to;

#Ifdef USE_MODULES;
    #Iffalse (7 >= n_to);
    Message error "Please move your Property declarations after the Include ~Parser~ line:
                   otherwise it will be impossible to USE_MODULES";
    #Endif;
#Endif;

Property door_to;
Property with_key;
Property door_dir;
Property invent;
Property plural;
Property add_to_scope;
Property list_together;
Property react_before;
Property react_after;
Property grammar;
Property additive orders;

Property initial;
Property when_open;
Property when_closed;
Property when_on;
Property when_off;
Property description;
Property additive describe NULL;
Property article "a";

Property cant_go;

Property found_in;          ! For fiddly reasons this can't alias

Property time_left;
Property number;
Property additive time_out NULL;
Property daemon;
Property additive each_turn NULL;

Property capacity 100;

Property short_name 0;
Property short_name_indef 0;
Property parse_name 0;

Property articles;
Property inside_description;

! Parametry niezbedne do prawidlowej odmiany w jezyku polskim.

Property name_dop;
Property name_cel;
Property name_bie;
Property name_nar;
Property name_mie;

Property plural_cel;

!Property desc_mia;
Property desc_dop;
Property desc_cel;
Property desc_bie;
Property desc_nar;
Property desc_mie;


Property plural_dopelniacz;
!Property plural_celownik;
Property plural_biernik;
!Property plural_narzednik;
!Property plural_miejscownik;

! ==============================================================================
