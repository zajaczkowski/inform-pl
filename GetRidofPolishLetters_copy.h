

! ------------------------------------------------------------------------------
! GetRidOfPolishLetters();
!
! Pomimo rozmaitych pr�b, nie uda�o mi si� zmusi� wsp�czesnych interpreter�w do
! prawid�owego rozpoznawania polskich znak�w stosowanych w nazwach obiekt�w oraz
! w czasownikach. Chodzi przede wszystkim o "parchment" oraz o interpretery
! w systemach mobilnych.
!
! Z powy�szego powodu konieczne jest stosowanie poni�szej procedury, kt�ra
! usuwa polskie znaki z polecenia zanim  interpreter zacznie je analizowa�.
! ------------------------------------------------------------------------------


[ GetRidOfPolishLetters x i word at len;


#Ifdef TARGET_ZCODE;

  for (x=0:x<parse->1:x++)
    {
    word = parse-->(x*2 + 1);
    at = parse->(x*4 + 5);
    len = parse->(x*4 + 4);

#Ifnot; ! TARGET_GLULX

  for (x=0:x<parse-->0:x++)
    {
    word = parse-->(x*3 + 1);
    at = parse-->(x*3 + 3);
    len = parse-->(x*3 + 2);

#Endif; ! TARGET_

    for (i=at:i<at+len:i++)
      {

      if     (buffer->i=='�') buffer->i='a';
      else if(buffer->i=='�') buffer->i='c';
      else if(buffer->i=='�') buffer->i='e';
      else if(buffer->i=='�') buffer->i='l';
      else if(buffer->i=='�') buffer->i='n';
      else if(buffer->i=='�') buffer->i='o';
      else if(buffer->i=='�') buffer->i='s';
      else if(buffer->i=='�') buffer->i='z';
      else if(buffer->i=='�') buffer->i='z';

      if     (buffer->i=='�') buffer->i='A';
      else if(buffer->i=='�') buffer->i='C';
      else if(buffer->i=='�') buffer->i='E';
      else if(buffer->i=='�') buffer->i='L';
      else if(buffer->i=='�') buffer->i='N';
      else if(buffer->i=='�') buffer->i='O';
      else if(buffer->i=='�') buffer->i='S';
      else if(buffer->i=='�') buffer->i='Z';
      else if(buffer->i=='�') buffer->i='Z';

      }

    Tokenise__(buffer,parse);

  }

];
