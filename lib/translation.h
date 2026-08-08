! ==============================================================================
! Translated from a script by Pablo Martínez in 2025
! ==============================================================================
! Questo file modifica il comando del giocatore affinché alcuni
! elementi della lingua possano essere compresi dall'analizzatore sintattico.
! Al momento si limita a elaborare i suffissi -lo, -la, -li, -le, -ti -gli
! (come in “prendi la scatola e aprila”) separandoli con spazio e trattino
! (trasforma «aprila» in «apri -la») in modo che risulti una parola distinta
! che l'analizzatore possa rilevare.
! Al momento, funziona solo per la versione V5 della macchina Inform poichè
! nella V3 non è possibile analizzare il comando del giocatore una seconda
! volta dopo la lettura. Ciò significa che nella V3 NON esistono suffissi.
! ==============================================================================
! Source encoding UTF-8 No Mark
System_file;

! From library 6.12
! To protect against a bug in early versions of the "Zip" interpreter:
[ Tokenise__ b p; b->(2 + b->1) = 0; @tokenise b p; ];

! From library 6.12
[ LTI_Insert i ch  b y;

    ! Protect us from strict mode, as this isn't an array in quite the
    ! sense it expects
    b = buffer;

    ! Insert character ch into buffer at point i.
    ! Being careful not to let the buffer possibly overflow:
    y = b->1;
    if (y > b->0) y = b->0;

    ! Move the subsequent text along one character:
    for (y=y+2 : y>i : y--) b->y = b->(y-1);
    b->i = ch;
    ! And the text is now one character longer:
    if (b->1 < b->0) (b->1)++;
];

[ Translation w x length change cx cx1;
  
	ProcessApostrofi();

	for (w=parse->1:w>=1:w--) {
		length = parse->(4*w);
		if (parse-->(w*2-1) == 0 && length >= 3) {
			x = parse->(4*w + 1) + length - 1; 
			cx = buffer->x; cx1=buffer->(x-1);
			if (cx == 'i' && length >= 4 && cx1 == 'l' && buffer->(x-2) == 'g') { ! suffisso -gli
				change = true;
				Insert_Suffix(x, 2);
			} else if ((cx == 'a' or 'o' or 'e' or 'i') && cx1 == 'l') { ! suffissi -la -lo -le -li
				change = true;
				Insert_Suffix(x, 1);
			} else if (cx == 'i' && cx1 == 't') { ! suffisso -ti
				change = true;
				Insert_Suffix(x, 1);
			}
		}
	}
	if (change) Tokenise__(buffer, parse);
];

[ Insert_Suffix pos len;
	LTI_Insert(pos-len, '-');
	LTI_Insert(pos-len, ' ');
];

[ ProcessApostrofi change i b;
	b = buffer;
	for(i=0 : i < b ->1 : i++) {
		if(b->(i+2) == '@@39') {
			LTI_Insert(i+3, ' ');
			change = true;
		}
	}
	if (change)	Tokenise__(buffer, parse);
];