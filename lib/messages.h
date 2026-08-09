! Part of PunyInform: A small stdlib and parser for interactive fiction
! suitable for old-school computers such as the Commodore 64.
! Designed to be similar, but not identical, to the Inform 6 library.
!
System_file;

!
! Simple string messages
!

#Ifndef MSG_TAKE_YOURSELF;
Constant MSG_TAKE_YOURSELF "Già ti possiedi.";
#EndIf;
#Ifndef MSG_TAKE_NO_CAPACITY;
Constant MSG_TAKE_NO_CAPACITY "Stai portando già troppe cose.";
#EndIf;
!#Ifndef MSG_TAKE_DEFAULT;
!Constant MSG_TAKE_DEFAULT "Fatto.";
!#EndIf;
#Ifndef MSG_DRINK_NOTHING_SUITABLE;
Constant MSG_DRINK_NOTHING_SUITABLE "Non c'è nulla di bevibile qui.";
#EndIf;
!#Ifndef MSG_DROP_DROPPED;
!Constant MSG_DROP_DROPPED "Fatto.";
!#EndIf;
#Ifndef MSG_THROW_ANIMATE;
Constant MSG_THROW_ANIMATE "Inutile.";
#Endif;
#Ifndef MSG_THROW_DEFAULT;
Constant MSG_THROW_DEFAULT "Ti manca il coraggio proprio nel momento cruciale.";
#Endif;
#Ifndef MSG_SMELL_DEFAULT;
Constant MSG_SMELL_DEFAULT "Non odori nulla di particolare.";
#Endif;
#Ifndef MSG_LISTEN_DEFAULT;
Constant MSG_LISTEN_DEFAULT "Non ascolti nulla di particolare.";
#Endif;
#Ifndef MSG_TELL_PLAYER;
Constant MSG_TELL_PLAYER "Parli da solo per un pò.";
#Endif;
#Ifndef MSG_TELL_DEFAULT;
Constant MSG_TELL_DEFAULT "Non provochi nessuna reazione.";
#Endif;
#Ifndef MSG_ENTER_ALREADY;
Constant MSG_ENTER_ALREADY "Ma ci sei gia dentro!";
#Endif;
#Ifndef MSG_EXIT_ALREADY;
Constant MSG_EXIT_ALREADY "Non devi uscire da nulla al momento!";
#Endif;
#Ifndef MSG_EXIT_NOT_ON;
Constant MSG_EXIT_NOT_ON "Non ci sei sopra.";
#Endif;
#Ifndef MSG_EXIT_NOT_IN;
Constant MSG_EXIT_NOT_IN "Non ci sei dentro.";
#Endif;
#Ifndef MSG_INVENTORY_EMPTY;
Constant MSG_INVENTORY_EMPTY "Sei a mani vuote.";
#Endif;
#Ifndef MSG_GO_CANT_GO;
Constant MSG_GO_CANT_GO "Non puoi andare da quella parte.";
#Endif;
#Ifndef MSG_SAVE_DEFAULT;
Constant MSG_SAVE_DEFAULT "Fatto.";
#Endif;
#Ifndef MSG_INSERT_ITSELF;
Constant MSG_INSERT_ITSELF "Non puoi inserire una cosa dentro sé stessa.";
#Endif;
#Ifndef MSG_PUTON_ITSELF;
Constant MSG_PUTON_ITSELF "No puoi mettere una cosa sopra sè stessa.";
#Endif;
#Ifndef MSG_ATTACK_DEFAULT;
Constant MSG_ATTACK_DEFAULT "La violenza non è la risposta.";
#Endif;
#Ifndef MSG_FILL_NO_WATER;
Constant MSG_FILL_NO_WATER "Ma non c'è acqua da portare.";
#EndIf;
#Ifndef MSG_DIG_NO_USE;
Constant MSG_DIG_NO_USE "Scavare qui non servirebbe a nulla.";
#EndIf;
#Ifndef MSG_WAIT_DEFAULT;
Constant MSG_WAIT_DEFAULT "Non accade nulla.";
#EndIf;
#Ifndef MSG_TOUCH_DEFAULT;
Constant MSG_TOUCH_DEFAULT "Non senti nulla di particolare.";
#EndIf;
#Ifndef MSG_PUSHDIR_DEFAULT;
Constant MSG_PUSHDIR_DEFAULT "È questa l'idea migliore che hai?";
#EndIf;
#Ifndef MSG_JUMP;
Constant MSG_JUMP "Salti sul posto, inutilmente.";
#EndIf;
!#Ifndef MSG_REMOVE_DEFAULT;
!Constant MSG_REMOVE_DEFAULT "Fatto.";
!#EndIf;
#Ifndef MSG_SEARCH_NOTHING_SPECIAL;
Constant MSG_SEARCH_NOTHING_SPECIAL "Non trovi nulla di speciale.";
#EndIf;
#Ifndef MSG_OOPS_DEFAULT;
Constant MSG_OOPS_DEFAULT "Non preoccuparti, capita.";
#EndIf;
#Ifndef MSG_PARSER_ONLY_TO_ANIMATE;
Constant MSG_PARSER_ONLY_TO_ANIMATE "Lo puoi fare solo con qualcosa di animato.";
#EndIf;
#Ifndef MSG_PARSER_NOT_MULTIPLE_VERB;
Constant MSG_PARSER_NOT_MULTIPLE_VERB "Non puoi usare più di una cosa con questo verbo.";
#EndIf;
#Ifndef MSG_PARSER_NOT_MULTIPLE_DIRS;
Constant MSG_PARSER_NOT_MULTIPLE_DIRS "Non puoi usare direzioni multiple.";
#EndIf;
#Ifndef MSG_PARSER_BAD_NUMBER;
Constant MSG_PARSER_BAD_NUMBER "Non capisco questo numero.";
#EndIf;
#Ifndef MSG_PARSER_NO_INPUT;
Constant MSG_PARSER_NO_INPUT "Come scusa?";
#EndIf;
#Ifndef MSG_PARSER_UNKNOWN_SENTENCE;
Constant MSG_PARSER_UNKNOWN_SENTENCE "Non capisco questa frase.";
#EndIf;
#Ifndef MSG_PARSER_UNKNOWN_VERB;
Constant MSG_PARSER_UNKNOWN_VERB "Non riconosco questo verbo.";
#EndIf;
#Ifndef MSG_PARSER_CANT_DISAMBIGUATE;
Constant MSG_PARSER_CANT_DISAMBIGUATE "Ancora non capisco a cosa ti riferisci.";
#EndIf;
#Ifndef MSG_PARSER_UNKNOWN_PERSON;
Constant MSG_PARSER_UNKNOWN_PERSON "Non vedo a chi ti stai riferendo.";
#EndIf;
#Ifndef MSG_PARSER_CANT_OOPS;
Constant MSG_PARSER_CANT_OOPS "Spiacente, ma ormai è fatto.";
#EndIf;
#Ifndef MSG_PARSER_COMPLEX_AGAIN;
Constant MSG_PARSER_COMPLEX_AGAIN "Il comando 'ancora' deve stare su una nuova linea.^";
#EndIf;
#Ifndef MSG_PARSER_NOTHING_TO_AGAIN;
Constant MSG_PARSER_NOTHING_TO_AGAIN "Non credo tu lo possa rifare.";
#EndIf;
#Ifndef MSG_PARSER_BE_MORE_SPECIFIC;
Constant MSG_PARSER_BE_MORE_SPECIFIC "Devi essere più specifico.";
#EndIf;
#Ifndef MSG_PARSER_NO_MULTIPLES_FOR_NPC;
Constant MSG_PARSER_NO_MULTIPLES_FOR_NPC "Puoi riferirti a una sola cosa quando parli con altri.";
#EndIf;
#IfnDef OPTIONAL_NO_DARKNESS;
#IfnDef MSG_NOW_DARK;
Constant MSG_NOW_DARK "^Sei nel buio più totale.";
#EndIf;
#EndIf;

#IfDef OPTIONAL_FULL_SCORE;
#IfDef OPTIONAL_SCORED;
#Ifndef MSG_FULLSCORE_OBJECTS;
Constant MSG_FULLSCORE_OBJECTS "trovando varie cose";
#EndIf;
#Ifndef MSG_FULLSCORE_ROOMS;
Constant MSG_FULLSCORE_ROOMS "visitando vari posti";
#EndIf;
#EndIf;
#Ifndef MSG_FULLSCORE_ACTIONS;
Constant MSG_FULLSCORE_ACTIONS "compiendo azioni notevoli";
#EndIf;
#EndIf;

!
! complex messages (enumerated)
!

! Note, we can only use id 2-999
Default MSG_CLOSE_YOU_CANT = 2;
Default MSG_ENTER_YOU_CANT = 3;
Default MSG_EXAMINE_NOTHING_SPECIAL = 4;
Default MSG_TAKE_ANIMATE = 5;
Default MSG_TAKE_PLAYER_PARENT = 6;
Default MSG_EAT_ANIMATE = 7;
Default MSG_DROP_NOT_HOLDING = 8;
Default MSG_OPEN_DEFAULT = 9;
Default MSG_CLOSE_DEFAULT = 10;
Default MSG_LOOK_BEFORE_ROOMNAME  = 11;
Default MSG_SHOW_NOT_HOLDING = 12;
Default MSG_SHOW_DEFAULT = 13;
Default MSG_GIVE_NOT_HOLDING = 14;
Default MSG_GIVE_DEFAULT = 15;
Default MSG_ASKFOR_DEFAULT = 16;
Default MSG_ASKTO_DEFAULT = 17;
Default MSG_ENTER_DEFAULT = 18;
Default MSG_EXIT_FIRST_LEAVE = 19;
Default MSG_ENTER_NOT_OPEN = 20;
Default MSG_EXIT_NOT_OPEN = 21;
Default MSG_EXIT_DEFAULT = 22;
Default MSG_INVENTORY_DEFAULT = 23;
Default MSG_GO_FIRST_LEAVE = 24;
Default MSG_GIVE_PLAYER 25;
Default MSG_SAVE_FAILED 26;
Default MSG_RESTORE_FAILED 27;
Default MSG_RESTART_FAILED 28;
Default MSG_INSERT_DEFAULT 29;
Default MSG_INSERT_NOT_OPEN 30;
Default MSG_ASK_DEFAULT 31;
Default MSG_ANSWER_DEFAULT 32;
Default MSG_RESTART_RESTORE_OR_QUIT 33;
Default MSG_AREYOUSUREQUIT 34;
Default MSG_WEAR_ALREADY_WORN 35;
Default MSG_WEAR_NOT_CLOTHING 36;
Default MSG_WEAR_NOT_HOLDING 37;
Default MSG_WEAR_DEFAULT 38;
Default MSG_INSERT_ALREADY 39;
Default MSG_INSERT_NO_ROOM 40;
Default MSG_PUTON_ALREADY 41;
Default MSG_PUTON_NO_ROOM 42;
Default MSG_PUTON_DEFAULT 43;
Default MSG_GO_DOOR_CLOSED 44;
Default MSG_SWITCH_ON_NOT_SWITCHABLE 45;
Default MSG_SWITCH_OFF_NOT_SWITCHABLE 46;
Default MSG_SWITCH_ON_ON 47;
Default MSG_SWITCH_OFF_NOT_ON 48;
Default MSG_SWITCH_ON_DEFAULT 49;
Default MSG_SWITCH_OFF_DEFAULT 50;
Default MSG_PUSH_STATIC 51;
Default MSG_PULL_STATIC 52;
Default MSG_TURN_STATIC 53;
Default MSG_PUSH_SCENERY 54;
Default MSG_PULL_SCENERY 55;
Default MSG_TURN_SCENERY 56;
Default MSG_PUSH_ANIMATE 57;
Default MSG_PULL_ANIMATE 58;
Default MSG_TURN_ANIMATE 59;
Default MSG_TURN_DEFAULT 60;
Default MSG_PUSH_DEFAULT 61;
Default MSG_PULL_DEFAULT 62;
Default MSG_YOU_HAVE_WON 63;
Default MSG_YOU_HAVE_DIED 64;
Default MSG_OPEN_YOU_CANT = 65;
Default MSG_PARSER_NOTHING_TO_VERB 66;
Default MSG_TOUCHABLE_FOUND_CLOSED 67;
Default MSG_CONSULT_NOTHING_INTERESTING 68;
Default MSG_CUT_NO_USE 69;
Default MSG_SACK_PUTTING 70;
Default MSG_LOCK_NOT_A_LOCK 71;
Default MSG_LOCK_ALREADY_LOCKED 72;
Default MSG_LOCK_CLOSE_FIRST 73;
Default MSG_LOCK_KEY_DOESNT_FIT 74;
Default MSG_LOCK_DEFAULT 75;
Default MSG_DISROBE_NOT_WEARING 76;
Default MSG_DISROBE_DEFAULT 77;
Default MSG_REMOVE_NOT_HERE 79;
Default MSG_SEARCH_IN_IT_ISARE 80;
Default MSG_SEARCH_ON_IT_ISARE 81;
Default MSG_SEARCH_EMPTY 82;
Default MSG_SEARCH_NOTHING_ON 83;
Default MSG_SEARCH_CANT_SEE_CLOSED 84;
Default MSG_EAT_DEFAULT = 85;
#Ifdef OPTIONAL_FULL_SCORE;
Default MSG_FULLSCORE_START 86;
Default MSG_FULLSCORE_END 87;
#Endif;
Default MSG_SCORE_DEFAULT 88;
Default MSG_UNLOCK_NOT_A_LOCK 89;
Default MSG_UNLOCK_ALREADY_UNLOCKED 90;
Default MSG_UNLOCK_KEY_DOESNT_FIT 91;
Default MSG_UNLOCK_DEFAULT 92;
Default MSG_ENTER_BAD_LOCATION 93;
Default MSG_PROMPT 94;
#Ifndef OPTIONAL_NO_DARKNESS;
Default MSG_EXAMINE_DARK 95;
Default MSG_SEARCH_DARK 96;
#Endif;
Default MSG_EXAMINE_ONOFF 97;
Default MSG_ORDERS_WONT 98;
Default MSG_AUTO_TAKE 99;
Default MSG_AUTO_DISROBE = 100;
Default MSG_PARSER_PARTIAL_MATCH = 101;
Default MSG_TAKE_BELONGS 102;
Default MSG_TAKE_PART_OF 103;
Default MSG_TAKE_NOT_AVAILABLE 104;
Default MSG_PARSER_CONTAINER_ISNT_OPEN 105;
Default MSG_PARSER_NOT_HOLDING 106;
Default MSG_PARSER_CANT_TALK 107;
Default MSG_WAVE_NOTHOLDING 108;
Default MSG_JUMP_OVER 109;
Default MSG_TIE_DEFAULT 110;
Default MSG_CLOSE_NOT_OPEN 111;
Default MSG_RUB_DEFAULT 112;
Default MSG_SQUEEZE_DEFAULT 113;
Default MSG_EXAMINE_CLOSED 114;
Default MSG_EMPTY_IS_CLOSED 115; ! Only used from extended verbset, but same message also used in basic set.
Default MSG_PARSER_NO_NEED_REFER_TO 116;
Default MSG_PARSER_DONT_UNDERSTAND_WORD 117;
Default MSG_INSERT_NOT_CONTAINER 118;
Default MSG_TRANSFER_ALREADY 119;
Default MSG_YES_OR_NO 120;
Default MSG_RESTART_CONFIRM 121;
#Ifndef NO_SCORE;
Default MSG_PARSER_NEW_SCORE 122;
#Endif;
Default MSG_CLIMB_ANIMATE 123;
Default MSG_CLIMB_DEFAULT 124;
Default MSG_PARSER_BAD_PATTERN_PREFIX 125;
Default MSG_PARSER_BAD_PATTERN_SUFFIX 126;
Default MSG_TAKE_ALREADY_HAVE 127;
Default MSG_SHOUT_DEFAULT 128;
Default MSG_SHOUTAT_DEFAULT 129;
Default MSG_INSERT_ANIMATE 130;
Default MSG_PUTON_ANIMATE 131;
Default MSG_LOOKMODE_NORMAL 132;
Default MSG_LOOKMODE_LONG 133;
Default MSG_LOOKMODE_SHORT 134;
Default MSG_AUTO_TAKE_NOT_HELD = 135;
Default MSG_AUTO_DISROBE_WORN = 136;
Default MSG_TAKE_SCENERY = 137;
Default MSG_TAKE_STATIC = 138;
Default MSG_EAT_INEDIBLE = 139;
Default MSG_OPEN_ALREADY = 140;
Default MSG_OPEN_LOCKED = 141;
Default MSG_PUTON_NOT_SUPPORTER = 142;
Default MSG_PARSER_NO_IT = 143;
Default MSG_PARSER_CANT_SEE_IT = 144;
Default MSG_NOTIFY_ON = 145;
Default MSG_NOTIFY_OFF = 146;
Default MSG_ENTER_HELD 147;
Default MSG_PARSER_NOSUCHTHING 148;
Default MSG_SHOUT_NOSUCHTHING 149;

Default MSG_TAKE_DEFAULT 150;
Default MSG_DROP_DROPPED 151;
Default MSG_REMOVE_DEFAULT 152;

#IfDef OPTIONAL_PROVIDE_UNDO_FINAL;
#Ifndef MSG_UNDO_NOTHING_DONE;
Constant MSG_UNDO_NOTHING_DONE "[Non c'è nulla da rimediare!]";
#EndIf;
#Ifndef MSG_UNDO_NOT_PROVIDED;
Constant MSG_UNDO_NOT_PROVIDED "[L'interprete che usi non può rimediare.]";
#EndIf;
#Ifndef MSG_UNDO_FAILED;
Constant MSG_UNDO_FAILED "Non sono riuscito a rimediare.";
#EndIf;
#Ifndef MSG_UNDO_DONE;
Constant MSG_UNDO_DONE "Ho rimediato al tuo ultimo comando.";
#EndIf;
#EndIf;

#Ifndef MSG_COMMENT_TRANSCRIPT;
Constant MSG_COMMENT_TRANSCRIPT "[Comento registrato]^";
#EndIf;
#Ifndef MSG_COMMENT_NO_TRANSCRIPT;
#ifdef OPTIONAL_EXTENDED_METAVERBS;
Constant MSG_COMMENT_NO_TRANSCRIPT "[Commento non registrato. Per farlo devi avviare una trascrizione.]^";
#IfNot;
Constant MSG_COMMENT_NO_TRANSCRIPT "[Commento non registrato. Questo gioco non consente trascrizioni.]^";
#EndIf;
#EndIf;

#IfDef OPTIONAL_EXTENDED_VERBSET;
#Ifndef MSG_BURN_DEFAULT;
Constant MSG_BURN_DEFAULT "Questo atto pericoloso non porterebbe a nulla.";
#EndIf;
#Ifndef MSG_BUY_DEFAULT;
Constant MSG_BUY_DEFAULT "Non c'è nulla in vendita.";
#EndIf;
#Ifndef MSG_EMPTY_WOULDNT_ACHIEVE;
Constant MSG_EMPTY_WOULDNT_ACHIEVE "Non svuoterebbe granchè.";
#EndIf;
#Ifndef MSG_RHETORICAL_QUESTION;
Constant MSG_RHETORICAL_QUESTION "Era una domanda retorica.";
#EndIf;
#Ifndef MSG_PRAY_DEFAULT;
Constant MSG_PRAY_DEFAULT "La tua preghera non ha dato risultati tangibili.";
#EndIf;
#Ifndef MSG_SING_DEFAULT;
Constant MSG_SING_DEFAULT "Il tuo canto è abominevole.";
#EndIf;
#Ifndef MSG_SLEEP_DEFAULT;
Constant MSG_SLEEP_DEFAULT "Non ti senti particolarmente assonnato.";
#EndIf;
#Ifndef MSG_SORRY_DEFAULT;
Constant MSG_SORRY_DEFAULT "Oh, non scusarti.";
#EndIf;
#Ifndef MSG_SQUEEZE_YOURSELF;
Constant MSG_SQUEEZE_YOURSELF "Tieni le mani al loro posto.";
#EndIf;

#Ifndef MSG_SWIM_DEFAULT;
Constant MSG_SWIM_DEFAULT "Non c'è abbastanza acqua per nuotare.";
#EndIf;
#Ifndef MSG_SWING_DEFAULT;
Constant MSG_SWING_DEFAULT "Non c'è nulla di sensato da cui dondolare.";
#EndIf;
#Ifndef MSG_TASTE_DEFAULT;
Constant MSG_TASTE_DEFAULT "Non assaggi nulla di particolare.";
#EndIf;
#Ifndef MSG_THINK_DEFAULT;
Constant MSG_THINK_DEFAULT "Ma che buona idea.";
#EndIf;
#Ifndef MSG_WAVEHANDS_DEFAULT;
Constant MSG_WAVEHANDS_DEFAULT "Saluti, e ti senti folle.";
#EndIf;
#Ifndef MSG_WAKE_DEFAULT;
Constant MSG_WAKE_DEFAULT "La terribile verità è che questo non è un sogno.";
#Endif;
#Ifndef MSG_WAKEOTHER_DEFAULT;
Constant MSG_WAKEOTHER_DEFAULT "Non mi sembra il caso.";
#Endif;
#Ifndef MSG_KISS_PLAYER;
Constant MSG_KISS_PLAYER "Se proprio credi che aiuterà...";
#Endif;
#Ifndef MSG_KISS_DEFAULT;
Constant MSG_KISS_DEFAULT "Rimani concentrato sul gioco.";
#Endif;
#Ifndef MSG_MILD_DEFAULT;
Constant MSG_MILD_DEFAULT "Eh già.";
#EndIf;
#Ifndef MSG_STRONG_DEFAULT;
Constant MSG_STRONG_DEFAULT "I veri avventurieri non usano questo linguaggio.";
#EndIf;

Default MSG_BLOW_DEFAULT 200;
Default MSG_WAVE_DEFAULT 201;
Default MSG_EMPTY_ALREADY_EMPTY 202;
Default MSG_SET_DEFAULT 203;
Default MSG_SET_TO_DEFAULT 204;
Default MSG_EMPTY_NOT_CONTAINER 205;
#EndIf;


#Iffalse MSG_PUSH_DEFAULT < 1000;
#Iffalse MSG_PULL_DEFAULT < 1000;
#Iffalse MSG_TURN_DEFAULT < 1000;
Constant SKIP_MSG_PUSH_DEFAULT;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_PUSH_STATIC < 1000;
#Iffalse MSG_PULL_STATIC < 1000;
#Iffalse MSG_TURN_STATIC < 1000;
#Iffalse MSG_TAKE_STATIC < 1000;
Constant SKIP_MSG_PUSH_STATIC;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_PUSH_SCENERY < 1000;
#Iffalse MSG_PULL_SCENERY < 1000;
#Iffalse MSG_TURN_SCENERY < 1000;
Constant SKIP_MSG_PUSH_SCENERY;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_PUSH_ANIMATE < 1000;
#Iffalse MSG_PULL_ANIMATE < 1000;
#Iffalse MSG_TURN_ANIMATE < 1000;
#Iffalse MSG_CLIMB_ANIMATE < 1000;
Constant SKIP_MSG_PUSH_ANIMATE;
#Endif;
#Endif;
#Endif;
#Endif;


#Iffalse MSG_DROP_NOT_HOLDING < 1000;
#Iffalse MSG_SHOW_NOT_HOLDING < 1000;
#Iffalse MSG_GIVE_NOT_HOLDING < 1000;
#Iffalse MSG_WEAR_NOT_HOLDING < 1000;
Constant SKIP_MSG_DROP_NOT_HOLDING;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_OPEN_YOU_CANT < 1000;
#Iffalse MSG_CLOSE_YOU_CANT < 1000;
#Iffalse MSG_ENTER_YOU_CANT < 1000;
#Iffalse MSG_LOCK_NOT_A_LOCK < 1000;
#Iffalse MSG_UNLOCK_NOT_A_LOCK < 1000;
#Iffalse MSG_WEAR_NOT_CLOTHING < 1000;
Constant SKIP_MSG_OPEN_YOU_CANT;
#Endif;
#Endif;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_TAKE_ANIMATE < 1000;
#Iffalse MSG_EAT_ANIMATE < 1000;
Constant SKIP_MSG_TAKE_ANIMATE;
#Endif;
#Endif;

#Iffalse MSG_TAKE_PLAYER_PARENT < 1000;
#Iffalse MSG_GO_FIRST_LEAVE < 1000;
#Iffalse MSG_EXIT_FIRST_LEAVE < 1000;
Constant SKIP_MSG_TAKE_PLAYER_PARENT;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_CLOSE_DEFAULT < 1000;
#Iffalse MSG_ENTER_DEFAULT < 1000;
#Iffalse MSG_LOCK_DEFAULT < 1000;
#Iffalse MSG_UNLOCK_DEFAULT < 1000;
#Iffalse MSG_EXIT_DEFAULT < 1000;
Constant SKIP_MSG_CLOSE_DEFAULT;
#Endif;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_GIVE_DEFAULT < 1000;
#Iffalse MSG_SHOW_DEFAULT < 1000;
Constant SKIP_MSG_GIVE_DEFAULT;
#Endif;
#Endif;

#Iffalse MSG_ASKFOR_DEFAULT < 1000;
#Iffalse MSG_ASKTO_DEFAULT < 1000;
#Iffalse MSG_ORDERS_WONT < 1000;
Constant SKIP_MSG_ASKFOR_DEFAULT;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_ENTER_NOT_OPEN < 1000;
#Iffalse MSG_EXIT_NOT_OPEN < 1000;
#Iffalse MSG_INSERT_NOT_OPEN < 1000;
#Iffalse MSG_GO_DOOR_CLOSED < 1000;
#Iffalse MSG_EMPTY_IS_CLOSED < 1000;
Constant SKIP_MSG_ENTER_NOT_OPEN;
#Endif;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_GIVE_PLAYER < 1000;
#Iffalse MSG_TAKE_ALREADY_HAVE < 1000;
Constant SKIP_MSG_GIVE_PLAYER;
#Endif;
#Endif;

#Iffalse MSG_SAVE_FAILED < 1000;
#Iffalse MSG_RESTORE_FAILED < 1000;
#Iffalse MSG_RESTART_FAILED < 1000;
Constant SKIP_MSG_SAVE_FAILED;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_INSERT_ALREADY < 1000;
#Iffalse MSG_PUTON_ALREADY < 1000;
#Iffalse MSG_TRANSFER_ALREADY < 1000;
Constant SKIP_MSG_INSERT_ALREADY;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_INSERT_ANIMATE < 1000;
#Iffalse MSG_PUTON_ANIMATE < 1000;
Constant SKIP_MSG_INSERT_ANIMATE;
#Endif;
#Endif;

#Iffalse MSG_INSERT_NO_ROOM < 1000;
#Iffalse MSG_PUTON_NO_ROOM < 1000;
Constant SKIP_MSG_INSERT_NO_ROOM;
#Endif;
#Endif;

#Iffalse MSG_ASK_DEFAULT < 1000;
#Iffalse MSG_ANSWER_DEFAULT < 1000;
#Iffalse MSG_SHOUT_DEFAULT < 1000;
#Iffalse MSG_SHOUTAT_DEFAULT < 1000;
Constant SKIP_MSG_ASK_DEFAULT;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_SWITCH_ON_NOT_SWITCHABLE < 1000;
#Iffalse MSG_SWITCH_OFF_NOT_SWITCHABLE < 1000;
Constant SKIP_MSG_SWITCH_ON_NOT_SWITCHABL;
#Endif;
#Endif;

#Iffalse MSG_SWITCH_ON_ON < 1000;
#Iffalse MSG_SWITCH_OFF_NOT_ON < 1000;
Constant SKIP_MSG_SWITCH_ON_ON;
#Endif;
#Endif;

#Iffalse MSG_SWITCH_ON_DEFAULT < 1000;
#Iffalse MSG_SWITCH_OFF_DEFAULT < 1000;
Constant SKIP_MSG_SWITCH_ON_DEFAULT;
#Endif;
#Endif;

#Iffalse MSG_PARSER_NOT_HOLDING < 1000;
#Iffalse MSG_AUTO_TAKE_NOT_HELD < 1000;
#Iffalse MSG_WAVE_NOTHOLDING < 1000;
Constant SKIP_MSG_PARSER_NOT_HOLDING;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_CLOSE_NOT_OPEN < 1000;
#Iffalse MSG_TOUCHABLE_FOUND_CLOSED < 1000;
#Iffalse MSG_PARSER_CONTAINER_ISNT_OPEN < 1000;
Constant SKIP_MSG_CLOSE_NOT_OPEN;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_CUT_NO_USE < 1000;
#Iffalse MSG_JUMP_OVER < 1000;
#Iffalse MSG_TIE_DEFAULT < 1000;
#Iffalse MSG_CLIMB_DEFAULT < 1000;
Constant SKIP_MSG_CUT_NO_USE;
#Endif;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_LOCK_ALREADY_LOCKED < 1000;
#Iffalse MSG_UNLOCK_ALREADY_UNLOCKED < 1000;
Constant SKIP_MSG_LOCK_ALREADY_LOCKED;
#Endif;
#Endif;

#Iffalse MSG_LOCK_KEY_DOESNT_FIT < 1000;
#Iffalse MSG_UNLOCK_KEY_DOESNT_FIT < 1000;
Constant SKIP_MSG_LOCK_KEY_DOESNT_FIT;
#Endif;
#Endif;

#Iffalse MSG_RUB_DEFAULT < 1000;
#Iffalse MSG_SQUEEZE_DEFAULT < 1000;
Constant SKIP_MSG_RUB_DEFAULT;
#Endif;
#Endif;

#Iffalse MSG_LOOKMODE_NORMAL < 1000;
#Iffalse MSG_LOOKMODE_LONG < 1000;
#Iffalse MSG_LOOKMODE_SHORT < 1000;
Constant SKIP_MSG_LOOKMODE;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_INSERT_NOT_CONTAINER < 1000;
#Ifndef MSG_EMPTY_NOT_CONTAINER;
Constant SKIP_MSG_INSERT_NOT_CONTAINER;
#Ifnot;
#Iffalse MSG_EMPTY_NOT_CONTAINER < 1000;
Constant SKIP_MSG_INSERT_NOT_CONTAINER;
#Endif;
#Endif;
#Endif;

#Ifndef OPTIONAL_NO_SCORE;
#Iffalse MSG_NOTIFY_ON < 1000;
#Iffalse MSG_NOTIFY_OFF < 1000;
Constant SKIP_MSG_NOTIFY_ON;
#Endif;
#Endif;
#Endif;

#Ifndef OPTIONAL_NO_DARKNESS;
#Iffalse MSG_EXAMINE_DARK < 1000;
#Iffalse MSG_SEARCH_DARK < 1000;
Constant SKIP_MSG_EXAMINE_DARK;
#Endif;
#Endif;
#Endif;

#Iffalse MSG_PARSER_NOSUCHTHING < 1000;
#Iffalse MSG_SHOUT_NOSUCHTHING < 1000;
Constant SKIP_MSG_PARSER_NOSUCHTHING;
#Endif;
#Endif;

[ _PrintMsg p_msg p_arg_1 p_arg_2;
	if(IsAString(p_msg))
		print_ret (string) p_msg;

#Ifdef LibraryMessages;
	if(p_msg > 999) {
		return LibraryMessages(p_msg, p_arg_1, p_arg_2);
	}
#Endif;

	! Not a string, there should be code for the message here
	switch(p_msg) {
#IfTrue MSG_PROMPT < 1000;
	MSG_PROMPT:
		print "> ";
		rtrue;
#EndIf;
#Iftrue MSG_LOOK_BEFORE_ROOMNAME < 1000;
	MSG_LOOK_BEFORE_ROOMNAME:
		! what to write at first when describing a room. Can be used to
		! add a newline, but default is to write nothing.
		!@new_line;
#Endif;

#Iftrue MSG_TAKE_DEFAULT < 1000;
	MSG_TAKE_DEFAULT:
		"Pres", (_o) noun, ".";
#Endif;
#Iftrue MSG_DROP_DROPPED < 1000;
	MSG_DROP_DROPPED:
		"Lasciat", (_o) noun, ".";
#Endif;
#Iftrue MSG_REMOVE_DEFAULT < 1000;
	MSG_REMOVE_DEFAULT:
		"Rimoss", (_o) noun, ".";
#Endif;

#Iftrue MSG_TAKE_SCENERY < 1000;
	MSG_TAKE_SCENERY:
		print_ret (CTheyreorThats) noun, " difficilmente trasportabile.";
#EndIf;
#Ifndef SKIP_MSG_PUSH_DEFAULT;
	MSG_PUSH_DEFAULT, MSG_PULL_DEFAULT, MSG_TURN_DEFAULT:
		"Non succede nulla di evidente.";
#Endif;
#Ifndef SKIP_MSG_PUSH_STATIC;
	MSG_PUSH_STATIC, MSG_PULL_STATIC, MSG_TURN_STATIC, MSG_TAKE_STATIC:
		print_ret (CTheyreorThats) noun, " inamovibile.";
#Endif;
#Ifndef SKIP_MSG_PUSH_SCENERY;
	MSG_PUSH_SCENERY, MSG_PULL_SCENERY, MSG_TURN_SCENERY:
		"Che genialata!";
#Endif;
#IfDef SACK_OBJECT;
#IfTrue MSG_SACK_PUTTING < 1000;
	MSG_SACK_PUTTING:
	! p_arg_1 = the object being put into SACK_OBJECT.
		"(mettendo ", (the) p_arg_1, " ", (InPrep) SACK_OBJECT, " per fare spazio)";
#EndIf;
#EndIf;
#IfTrue MSG_INVENTORY_DEFAULT < 1000;
	MSG_INVENTORY_DEFAULT:
		! return true if something listed to run afterroutines
		! or false if MSG_INVENTORY_EMPTY should be displayed
		p_arg_1 = "Stai portando ";
		if(inventory_style == 0) {
			p_arg_1 = "Stai portando:";
			p_arg_2 = NEWLINE_BIT;
		}
		if(PrintContents(p_arg_1, player, p_arg_2)) {
			if(inventory_style) print ".^";
			rtrue;
		}
		rfalse;
#EndIf;
#IfTrue MSG_EXAMINE_NOTHING_SPECIAL < 1000;
	MSG_EXAMINE_NOTHING_SPECIAL:
		"Non c'è nulla di speciale ", (InPrep) noun, ".";
#EndIf;
#Ifndef SKIP_MSG_PUSH_ANIMATE;
	MSG_PUSH_ANIMATE, MSG_PULL_ANIMATE, MSG_TURN_ANIMATE, MSG_CLIMB_ANIMATE:
		"Sarebbe poco cortese.";
#Endif;
#Ifndef SKIP_MSG_DROP_NOT_HOLDING;
	MSG_DROP_NOT_HOLDING, MSG_SHOW_NOT_HOLDING, MSG_GIVE_NOT_HOLDING,
	MSG_WEAR_NOT_HOLDING:
		"Non ", (ThatorThose) noun, " stai tenendo in mano.";
#Endif;
#Ifndef SKIP_MSG_OPEN_YOU_CANT;
	MSG_OPEN_YOU_CANT, MSG_CLOSE_YOU_CANT, MSG_ENTER_YOU_CANT,
	MSG_LOCK_NOT_A_LOCK, MSG_UNLOCK_NOT_A_LOCK, MSG_WEAR_NOT_CLOTHING:
	! p_arg_1 = the base verb for this action ('open', 'close' etc).
		"Non puoi ", (verbname) p_arg_1, (ThatorThose) noun, ".";
#Endif;
#IfTrue MSG_OPEN_ALREADY < 1000;
	MSG_OPEN_ALREADY:
		print_ret (CTheyreorIts) noun, " già apert", (_o) noun, ".";
#EndIf;
#IfTrue MSG_OPEN_LOCKED < 1000;
	MSG_OPEN_LOCKED:
		print_ret (CTheyreorIts) noun, " serrat", (_o) noun, ".";
#EndIf;
#IfTrue MSG_PUTON_NOT_SUPPORTER < 1000;
	MSG_PUTON_NOT_SUPPORTER:
		"Non puoi metter", (ThatorThose) second, " sopra delle cose.";
#EndIf;
#Ifndef SKIP_MSG_TAKE_ANIMATE;
	MSG_TAKE_ANIMATE, MSG_EAT_ANIMATE:
		"Non credo che ", (the) noun, " gradirebbe.";
#Endif;
#Ifndef SKIP_MSG_TAKE_PLAYER_PARENT;
	MSG_TAKE_PLAYER_PARENT, MSG_GO_FIRST_LEAVE, MSG_EXIT_FIRST_LEAVE:
	! p_arg_1 = the object the player has to leave to perform the action.
		"Prima dovresti abbandonare ", (the) p_arg_1, ".";
#Endif;
#Iftrue MSG_OPEN_DEFAULT < 1000;
	MSG_OPEN_DEFAULT:
		print "Hai aperto ", (the) noun;
		if(noun has container && noun hasnt transparent &&
				~~IndirectlyContains(noun, player)) {
			print ", rivelando ";
			if(PrintContents(0, noun)==false) print "nulla";
		}
		".";
#Endif;
#Ifndef SKIP_MSG_CLOSE_DEFAULT;
	!p_arg_1 = the base verb for this action ('open', 'close' etc).
    MSG_CLOSE_DEFAULT:
        "Hai chiuso ", (the) noun, ".";
    MSG_LOCK_DEFAULT:
        "Hai serrato ", (the) noun, ".";
    MSG_UNLOCK_DEFAULT:
        "Hai disserrato ", (the) noun, ".";
    MSG_ENTER_DEFAULT:
        "", (EnterSupp) noun, ".";
    MSG_EXIT_DEFAULT:
        "", (ExitSupp) noun, ".";
#Endif;
#Ifndef SKIP_MSG_GIVE_DEFAULT;
	MSG_GIVE_DEFAULT, MSG_SHOW_DEFAULT:
		print_ret (The) second, " non sembra", (_no) second, " interessat", (_o) second, ".";
#Endif;
#Ifndef SKIP_MSG_ASKFOR_DEFAULT;
	MSG_ASKFOR_DEFAULT, MSG_ASKTO_DEFAULT, MSG_ORDERS_WONT:
	! p_arg_1 = the actor which the player has asked to do something.
		print_ret (The) p_arg_1, " ", (HaveOrHas) p_arg_1, " di meglio da fare.";
#Endif;
#Ifndef SKIP_MSG_ENTER_NOT_OPEN;
	MSG_ENTER_NOT_OPEN, MSG_EXIT_NOT_OPEN, MSG_INSERT_NOT_OPEN,
	MSG_GO_DOOR_CLOSED, MSG_EMPTY_IS_CLOSED:
	! p_arg_1 = the object which is closed, thus blocking the player's action.
		"Non puoi, dato che ", (ObjIs) p_arg_1, " chius", (_o) p_arg_1, ".";
#Endif;
#Ifndef SKIP_MSG_GIVE_PLAYER;
	MSG_GIVE_PLAYER, MSG_TAKE_ALREADY_HAVE:
		"Già ", (ThatorThose) noun, " possiedi.";
#Endif;
#Ifndef SKIP_MSG_SAVE_FAILED;
	MSG_SAVE_FAILED, MSG_RESTORE_FAILED, MSG_RESTART_FAILED:
		"Fallito ", (verbname) verb_word, ".";
#Endif;
#Ifndef SKIP_MSG_INSERT_ALREADY;
	MSG_INSERT_ALREADY, MSG_PUTON_ALREADY, MSG_TRANSFER_ALREADY:
		"Ci ", (IsOrAre) noun, " già.";
#Endif;
#Ifndef SKIP_MSG_INSERT_ANIMATE;
	MSG_INSERT_ANIMATE, MSG_PUTON_ANIMATE:
		"Piuttosto, prova dando a ",(ItorThem) noun, " qualcosa.";
#Endif;
#Ifndef SKIP_MSG_INSERT_NO_ROOM;
	MSG_INSERT_NO_ROOM, MSG_PUTON_NO_ROOM:
		"Non c'è più spazio.";
#Endif;
#IfTrue MSG_INSERT_DEFAULT < 1000;
	MSG_INSERT_DEFAULT:
		"Hai messo ", (the) noun, " ", (InPrep) second, ".";
#EndIf;
#IfTrue MSG_PUTON_DEFAULT < 1000;
	MSG_PUTON_DEFAULT:
		"Hai messo ", (the) noun, " ", (SuPrep) second, ".";
#EndIf;
#Ifndef SKIP_MSG_ASK_DEFAULT;
	MSG_ASK_DEFAULT, MSG_ANSWER_DEFAULT, MSG_SHOUT_DEFAULT, MSG_SHOUTAT_DEFAULT:
		"Non ricevi risposta.";
#Endif;
#IfTrue MSG_WEAR_ALREADY_WORN < 1000;
	MSG_WEAR_ALREADY_WORN:
		"Stai già indossando", (ThatorThose) noun, ".";
#EndIf;
#IfTrue MSG_WEAR_DEFAULT < 1000;
	MSG_WEAR_DEFAULT:
		"Ora stai indossando ", (the) noun, ".";
#EndIf;
#IfTrue MSG_DISROBE_NOT_WEARING < 1000;
	MSG_DISROBE_NOT_WEARING:
		"Non stai indossando ", (the) noun, ".";
#EndIf;
#IfTrue MSG_DISROBE_DEFAULT < 1000;
	MSG_DISROBE_DEFAULT:
		"Ti togli di dosso ", (the) noun, ".";
#EndIf;
#Ifndef SKIP_MSG_SWITCH_ON_NOT_SWITCHABL;
	MSG_SWITCH_ON_NOT_SWITCHABLE, MSG_SWITCH_OFF_NOT_SWITCHABLE:
		print_ret "Non ", (IsOrAre) noun, " un interruttore.";
#Endif;
#Ifndef SKIP_MSG_SWITCH_ON_ON;
	MSG_SWITCH_ON_ON, MSG_SWITCH_OFF_NOT_ON:
		print_ret (CTheyreorThats) noun, " già ", (OnOff) noun, ".";
#Endif;
#Ifndef SKIP_MSG_SWITCH_ON_DEFAULT;
	MSG_SWITCH_ON_DEFAULT:
        "Hai acceso ", (the) noun, ".";
	MSG_SWITCH_OFF_DEFAULT:
        "Hai spento ", (the) noun, ".";
#Endif;
#Iftrue MSG_AUTO_TAKE < 1000;
	MSG_AUTO_TAKE:
	! p_arg_1 = the object the player automatically picks up
		"(prendendo prima ", (the) p_arg_1, ")";
#Endif;
#Iftrue MSG_AUTO_DISROBE < 1000;
	MSG_AUTO_DISROBE:
	! p_arg_1 = the object the player automatically takes off.
		"(togliendoti prima di dosso ", (the) p_arg_1, ")";
#Endif;
#Iftrue MSG_AUTO_DISROBE_WORN < 1000;
	MSG_AUTO_DISROBE_WORN:
	! p_arg_1 = the object the player would need to take off.
		"Prima dovresti toglierti di dosso ", (the) p_arg_1, ".";
#Endif;
#IfTrue MSG_PARSER_NOTHING_TO_VERB < 1000;
	MSG_PARSER_NOTHING_TO_VERB:
	! p_arg_1 = the last word in player input + 1.
		if(action == ##Drop or ##Insert) {
			if(_IsAllWord((parse + 2 + (p_arg_1 - 2) *4) --> 0))
				"Non stai portando nulla.";
			if(TryNumber(verb_wordnum + 1) > 0) "In mano non ne hai.";
		}
		print "Nulla di disponibile combacia con ~";
		_PrintPartialMatch(verb_wordnum, p_arg_1 - 1);
		"~.";
#EndIf;
#Ifndef SKIP_MSG_PARSER_NOT_HOLDING;
	MSG_PARSER_NOT_HOLDING, MSG_AUTO_TAKE_NOT_HELD, MSG_WAVE_NOTHOLDING:
	! p_arg_1 = the object which the player must be holding to perform the
	! action but isn't.
		"Ma non hai in mano ", (the) p_arg_1, ".";
#Endif;
#IfTrue MSG_PARSER_PARTIAL_MATCH < 1000;
	MSG_PARSER_PARTIAL_MATCH:
	! p_arg_1 = the word number of the last word understood + 1.
		print "Ho capito solo fino a ~";
		_PrintPartialMatch(verb_wordnum, p_arg_1);
		"~.";
#EndIf;
#IfTrue MSG_PARSER_CANT_TALK < 1000;
	MSG_PARSER_CANT_TALK:
	! p_arg_1 = the object which can't be talked to.
		"Non puoi parlare con ", (the) p_arg_1, ".";
#EndIf;
#IfTrue MSG_PARSER_NO_NEED_REFER_TO < 1000;
	MSG_PARSER_NO_NEED_REFER_TO:
		print "Non serve riferirsi a ~";
		_PrintUnknownWord();
		"~ in questo gioco.";
#EndIf;
#IfTrue MSG_PARSER_DONT_UNDERSTAND_WORD < 1000;
	MSG_PARSER_DONT_UNDERSTAND_WORD:
		print "Scusa, non capisco ";
		if(oops_unfixed) {
			"nemmeno quella parola.";
		}
		print "cosa significhi ~";
		_PrintUnknownWord();
		"~.";
#EndIf;
#IfTrue MSG_PARSER_BAD_PATTERN_PREFIX < 1000;
	MSG_PARSER_BAD_PATTERN_PREFIX:
		print "Penso che tu volessi dire ~";
		rtrue;
#EndIf;
#IfTrue MSG_PARSER_BAD_PATTERN_SUFFIX < 1000;
	MSG_PARSER_BAD_PATTERN_SUFFIX:
		"~. Per favore, prova ancora.";
#EndIf;
#IfTrue MSG_PARSER_NO_IT < 1000;
	MSG_PARSER_NO_IT:
		"Non saprei a cosa si riferisca ~",(address) p_arg_1, "~.";
#EndIf;
#Ifndef SKIP_MSG_PARSER_NOSUCHTHING;
	MSG_PARSER_NOSUCHTHING, MSG_SHOUT_NOSUCHTHING:
		"Non vedo nulla di tutto ciò.";
#EndIf;
#IfTrue MSG_PARSER_CANT_SEE_IT < 1000;
	MSG_PARSER_CANT_SEE_IT:
		"Non puoi vedere ~",(address) p_arg_1, "~ (", (name) p_arg_2, ") al momento.";
#EndIf;
#Ifndef SKIP_MSG_CLOSE_NOT_OPEN;
	MSG_CLOSE_NOT_OPEN, MSG_TOUCHABLE_FOUND_CLOSED,
	MSG_PARSER_CONTAINER_ISNT_OPEN:
	! p_arg_1 = the object which isn't open.
		print_ret (The) p_arg_1, " non ", (IsOrAre) p_arg_1, " apert", (_o) p_arg_1, ".";
#Endif;
#IfTrue MSG_CONSULT_NOTHING_INTERESTING < 1000;
	MSG_CONSULT_NOTHING_INTERESTING:
		"Non scopri nulla di interessante ", (InPrep) noun, ".";
#EndIf;
#Ifndef SKIP_MSG_CUT_NO_USE;
	MSG_CUT_NO_USE, MSG_JUMP_OVER, MSG_TIE_DEFAULT, MSG_CLIMB_DEFAULT:
		"Non otterrai nulla facendo così.";
#Endif;
#Ifndef SKIP_MSG_LOCK_ALREADY_LOCKED;
	MSG_LOCK_ALREADY_LOCKED:
		print_ret (The) noun, " è già serrat", (_o) noun, ".";
	MSG_UNLOCK_ALREADY_UNLOCKED:
		print_ret (The) noun, " è già disserrat", (_o) noun, ".";
#Endif;
#IfTrue MSG_LOCK_CLOSE_FIRST < 1000;
	MSG_LOCK_CLOSE_FIRST:
		"Prima dovresti chiudere ", (the) noun, ".";
#EndIf;
#Ifndef SKIP_MSG_LOCK_KEY_DOESNT_FIT;
	MSG_LOCK_KEY_DOESNT_FIT, MSG_UNLOCK_KEY_DOESNT_FIT:
		print_ret (The) second, " non combacia", (_no) second, " con questo lucchetto.";
#Endif;
#IfTrue MSG_EXAMINE_CLOSED < 1000;
	MSG_EXAMINE_CLOSED:
	! p_arg_1 = the examines object (which is closed).
		print_ret (CObjIs) p_arg_1, " chius", (_o) p_arg_1, ".";
#Endif;
#IfTrue MSG_REMOVE_NOT_HERE < 1000;
	MSG_REMOVE_NOT_HERE:
		"Ma ", (the) noun, " non ", (IsOrAre) noun, " qui ora.";
#EndIf;
#IfTrue MSG_SEARCH_IN_IT_ISARE < 1000;
	MSG_SEARCH_IN_IT_ISARE:
		print (The) noun;
		if (noun has pluralname) print " contengono ";
		else print " contiene ";
		PrintContents(0, noun);
		".";
#EndIf;
#IfTrue MSG_SEARCH_ON_IT_ISARE < 1000;
	MSG_SEARCH_ON_IT_ISARE:
		print "Sopra ", (the) noun;
		PrintContents(" ", noun, ISARE_BIT);
		".";
#EndIf;
#IfTrue MSG_SEARCH_EMPTY < 1000;
	MSG_SEARCH_EMPTY:
		print_ret (CObjIs) noun, " vuot", (_o) noun, ".";
#EndIf;
#IfTrue MSG_SEARCH_NOTHING_ON < 1000;
	MSG_SEARCH_NOTHING_ON:
		"Non c'è nulla ", (SuPrep) noun, ".";
#EndIf;
#IfTrue MSG_SEARCH_CANT_SEE_CLOSED < 1000;
	MSG_SEARCH_CANT_SEE_CLOSED:
		"Non puoi vedere dentro perchè ", (ObjIs) noun, " chius", (_o) noun, ".";
#EndIf;
#IfTrue MSG_EXAMINE_ONOFF < 1000;
	MSG_EXAMINE_ONOFF:
		print_ret (CObjIs) noun, " risulta ", (onoff) noun, ".";
#EndIf;
#IfTrue MSG_EAT_DEFAULT < 1000;
	MSG_EAT_DEFAULT:
		"Hai mangiato ", (the) noun, ". Niente male.";
#EndIf;
#Ifndef SKIP_MSG_RUB_DEFAULT;
MSG_RUB_DEFAULT, MSG_SQUEEZE_DEFAULT:
	"Non hai ottenuto nulla facendolo.";
#Endif;
#IfTrue MSG_TAKE_NOT_AVAILABLE < 1000;
	MSG_TAKE_NOT_AVAILABLE:
		print_ret (The) noun, " non ", (IsOrAre) noun, " disponibil", (_e) noun, ".";
#EndIf;
#IfTrue MSG_TAKE_BELONGS < 1000;
	MSG_TAKE_BELONGS:
		! p_arg_1 = the object that is held by p_arg_2
		print_ret (The) p_arg_1, " sembra", (_no) p_arg_1, " appartenere ", (APrep) p_arg_2, ".";
#EndIf;
#IfTrue MSG_TAKE_PART_OF < 1000;
	MSG_TAKE_PART_OF:
		! p_arg_1 = the object that is part of p_arg_2
		print_ret (The) p_arg_1, " sembra", (_no) p_arg_1, " essere parte ", (DiPrep) p_arg_2, ".";
#EndIf;
#IfTrue MSG_EAT_INEDIBLE < 1000;
	MSG_EAT_INEDIBLE:
		print_ret (CTheyreorThats) noun, " chiaramente immangiabil", (_e) noun, ".";
#EndIf;
#Ifndef OPTIONAL_NO_DARKNESS;
#Ifndef SKIP_MSG_EXAMINE_DARK;
	MSG_EXAMINE_DARK, MSG_SEARCH_DARK:
		"Ma è buio.";
#Endif;
#Endif;
#IfTrue MSG_ENTER_BAD_LOCATION < 1000;
	MSG_ENTER_BAD_LOCATION:
		print "Prima devi ";
		if(player notin location && ~~IndirectlyContains(parent(player), noun))
			print "uscire ", (DaPrep) parent(player);
		else
			print "entrare ", (InPrep) parent(noun);
		".";
#EndIf;
#IfTrue MSG_ENTER_HELD < 1000;
	MSG_ENTER_HELD:
		"Non puoi entrare ", (InPrep) noun, " se ", (ThatorThose) noun, " tieni in mano.";
#EndIf;
#Ifndef SKIP_MSG_INSERT_NOT_CONTAINER;
#ifdef MSG_EMPTY_NOT_CONTAINER;
	MSG_INSERT_NOT_CONTAINER, MSG_EMPTY_NOT_CONTAINER:
#Ifnot;
	MSG_INSERT_NOT_CONTAINER:
#Endif;
		! p_arg_1 = the object that can't contain things
		print_ret (The) p_arg_1, " non è un contenitore.";
#Endif;

#IfDef OPTIONAL_EXTENDED_VERBSET;
#IfTrue MSG_BLOW_DEFAULT < 1000;
	MSG_BLOW_DEFAULT:
		"Non è utile soffiare ", (SuPrep) noun, ".";
#EndIf;
#IfTrue MSG_EMPTY_ALREADY_EMPTY < 1000;
	MSG_EMPTY_ALREADY_EMPTY:
		! p_arg_1 = the object that is already empty
		print_ret (CObjIs) p_arg_1, " già vuot", (_o) p_arg_1, ".";
#EndIf;
#IfTrue MSG_SET_DEFAULT < 1000;
	MSG_SET_DEFAULT:
		"No, non puoi impostar", (thatorthose) noun, ".";
#EndIf;
#IfTrue MSG_SET_TO_DEFAULT < 1000;
	MSG_SET_TO_DEFAULT:
		"No, non puoi impostar", (thatorthose) noun, " su nulla.";
#EndIf;
#IfTrue MSG_WAVE_DEFAULT < 1000;
	MSG_WAVE_DEFAULT:
		"Ti senti in imbarazzo mentre saluti ", (the) noun, ".";
#EndIf;
#EndIf; ! Extended verbset

#Ifndef NO_SCORE;
#Iftrue MSG_PARSER_NEW_SCORE < 1000;
	MSG_PARSER_NEW_SCORE:
		! p_arg_1 = the old score
		print "^[Il punteggio è appena ";
		if(p_arg_1 < score) {
			p_arg_2 = score - p_arg_1;
			print "salito ";
		} else {
			p_arg_2 = p_arg_1 - score;
			print "sceso ";
		}
		print "di ", p_arg_2, " punt";
		if(p_arg_2 > 1) print "i"; else print "o";
		".]";
#Endif;
#Endif;
#Iftrue MSG_SCORE_DEFAULT < 1000;
	MSG_SCORE_DEFAULT:
#Ifdef NO_SCORE;
		"Non c'è punteggio in questo gioco.";
#Ifnot;
		if (deadflag) print "In questo gioco"; else print "Per ora";
		print " hai ottenuto ", score, " punt";
		if(score ~= 1) print "i"; else print "o";
		print " su un totale di ", MAX_SCORE, ", in ", turns, " mosse";
		if(turns ~= 1) print "s";
		rtrue;
#Endif;
#Endif;
#IfDef OPTIONAL_FULL_SCORE;
#IfTrue MSG_FULLSCORE_START < 1000;
	MSG_FULLSCORE_START:
		print "Il punteggio ";
		if(deadflag) print "era"; else print "è";
		" così composto:";
#EndIf;
#IfTrue MSG_FULLSCORE_END < 1000;
	MSG_FULLSCORE_END:
		"in totale (su ", MAX_SCORE, ")";
#EndIf;
#EndIf;

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
! Infrequently used messages
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#Ifndef SKIP_MSG_LOOKMODE;
	MSG_LOOKMODE_NORMAL, MSG_LOOKMODE_LONG, MSG_LOOKMODE_SHORT:
		print "Questo gioco è ora in modalità ";
		if(lookmode==1) print "normale ~";
		if(lookmode==2) print "~verboso";
		else {
			if(lookmode==3) print "~super";
			print "breve";
		}
		print "~, che dà";
		if(lookmode ~= 1) print "sempre ";
		print "descrizioni ";
		if(lookmode == 3) print "corte";
		else print "lunghe";
		print " dei luoghi ";
		if(lookmode == 1)
			"mai visitati prima e descrizioni lunghe altrimenti.";
		print "(anche se ";
		if(lookmode ~= 2) print "non ";
		"ci sei mai stato prima).";
#Endif;
#IfTrue MSG_RESTART_RESTORE_OR_QUIT < 1000;
	MSG_RESTART_RESTORE_OR_QUIT:
		print "^Ora RICOMINCIA il gioco, CARICA una partita";
#Ifdef OPTIONAL_PROVIDE_UNDO_FINAL;
	#Ifdef DEATH_MENTION_UNDO;
			if(((HDR_GAMEFLAGS->1) & 16) ~= 0)
				print ", RIMEDIA all'ultima mossa"
	#Ifnot;
			if(((HDR_GAMEFLAGS->1) & 16) ~= 0 && deadflag ~= GS_WIN)
				print ", RIMEDIA all'ultima mossa";
	#Endif;
#Endif;
#IfDef OPTIONAL_FULL_SCORE;
		print ", guarda il punteggio TOTALE";
#EndIf;
#Ifdef Amusing;
		if(AMUSING_PROVIDED == 0 && deadflag == GS_WIN) 
			print ", leggi i RETROSCENA";
#Endif;
		print " o TERMINA il gioco.";
		rtrue;
#EndIf;
#IfTrue MSG_AREYOUSUREQUIT < 1000;
	MSG_AREYOUSUREQUIT: ! print and rtrue to avoid newline
		print "Sei sicuro di voler terminare il gioco? ";
		rtrue;
#EndIf;
#IfTrue MSG_YOU_HAVE_WON < 1000;
	MSG_YOU_HAVE_WON: ! print and rtrue to avoid newline
 		print "Hai vinto";
 		rtrue;
#EndIf;
#IfTrue MSG_YOU_HAVE_DIED < 1000;
	MSG_YOU_HAVE_DIED: ! print and rtrue to avoid newline
		print "Sei morto";
		rtrue;
#EndIf;
#IfTrue MSG_YES_OR_NO < 1000;
	MSG_YES_OR_NO:
		print "Per favore, rispondi si o no: ";
		rtrue;
#EndIf;
#IfTrue MSG_RESTART_CONFIRM < 1000;
	MSG_RESTART_CONFIRM:
		print "Sei sicuro di voler ricominciare il gioco? ";
		rtrue;
#Endif;

#Ifndef NO_SCORE;
#Ifndef SKIP_MSG_NOTIFY_ON;
	MSG_NOTIFY_ON, MSG_NOTIFY_OFF:
		print "Le notifiche del punteggio sono state ";
		if(p_msg == MSG_NOTIFY_ON) "attivate.";
		"disattivate.";
#Endif;
#Endif;


default:
		! No code found. Print an error message.
		_RunTimeError(ERR_UNKNOWN_MSGNO);
	}
];

[ ThatorThose p_obj;
	if (p_obj == player)		{ print "ti"; rtrue; }
	if (p_obj has pluralname) {
		if (p_obj has female)	{ print "le"; rtrue; }
		{ print "li"; rtrue; }
	}
	if (p_obj has female)	{ print "la"; rtrue; }
	{ print "lo"; rtrue; }
];

[ ItorThem p_obj;
	if (p_obj == player)		{ print "te"; rtrue; }
	if (p_obj has pluralname)	{ print "loro"; rtrue; }
	if (p_obj has animate) {
		if (p_obj has female)	{ print "ella"; rtrue; }
		{ print "egli"; rtrue; }
	}
	if (p_obj has female)	{ print "essa"; rtrue; }
	{ print "esso"; rtrue; }
];

[ CObjIs p_obj;
	print (The) p_obj, " ", (isorare) p_obj;
];

[ ObjIs p_obj;
	print (the) p_obj, " ", (isorare) p_obj;
];

[ DoOrDoes p_obj;
	print "do";
	if (p_obj hasnt pluralname) print "es";
];

[ HaveOrHas p_obj;
	if (p_obj has pluralname) print "have"; else print "has";
];

[ IsorAre p_obj;
	if (p_obj has pluralname) print "sono";
	else if (p_obj == player) print "sei";
	else print "è";
];

[ CTheyreorThats p_obj;
	if (p_obj has pluralname) print "Sono";
	else if (p_obj == player) print "Sei";
	else print "È";
];

[ CTheyreorIts p_obj;
	CTheyreorThats(p_obj);
];

[OnOff p_obj;
	if(p_obj has on) print "acces", (_o) p_obj;
	else print "spent", (_o) p_obj;
	return;
];

[ SingularS p_obj;
	if(p_obj hasnt pluralname && p_obj ~= player) print "s";
];

! 
! Costrutti italiani
!
[_o p_obj;
	if (p_obj has pluralname) {
		if (p_obj has female) print "e";
		else print "i";
	} else {
		if (p_obj has female) print "a";
		else print "o";
	}
	return;
];

[_e p_obj;
	if (p_obj has pluralname) print "i";
	else print "e";
	return;
];

[_no p_obj;
	if (p_obj has pluralname) print "no";
	return;
];

[DiPrep p_obj;
	if (p_obj has pluralname) {
		if (p_obj has female) print "delle ";
		else {
			if (p_obj has logli) print "degli ";
			else print "dei ";
		}
	} else {
		if (p_obj has female) {
			if (p_obj has apostrofo) print "dell'";
			else print "della ";
		} 
		else {
			if (p_obj has logli) { 
				if (p_obj has apostrofo) print "dell'"; 
				else print "dello ";
			}
			else print "del ";
		}
	}
	print (name) p_obj;
	return;
];

[APrep p_obj;
	if (p_obj has pluralname) {
		if (p_obj has female) print "alle ";
		else {
			if (p_obj has logli) print "agli ";
			else print "ai ";
		}
	} else {
		if (p_obj has female) {
			if (p_obj has apostrofo) print "all'";
			else print "alla ";
		} 
		else {
			if (p_obj has logli) { 
				if (p_obj has apostrofo) print "all'"; 
				else print "allo ";
			}
			else print "al ";
		}
	}
	print (name) p_obj;
	return;
];

[DaPrep p_obj;
	if (p_obj has pluralname) {
		if (p_obj has female) print "dalle ";
		else {
			if (p_obj has logli) print "dagli ";
			else print "dai ";
		}
	} else {
		if (p_obj has female) {
			if (p_obj has apostrofo) print "dall'";
			else print "dalla ";
		} 
		else {
			if (p_obj has logli) { 
				if (p_obj has apostrofo) print "dall'"; 
				else print "dallo ";
			}
			else print "dal ";
		}
	}
	print (name) p_obj;
	return;
];

[InPrep p_obj;
	if (p_obj has pluralname) {
		if (p_obj has female) print "nelle ";
		else {
			if (p_obj has logli) print "negli ";
			else print "nei ";
		}
	} else {
		if (p_obj has female) {
			if (p_obj has apostrofo) print "nell'";
			else print "nella ";
		} 
		else {
			if (p_obj has logli) { 
				if (p_obj has apostrofo) print "nell'"; 
				else print "nello ";
			}
			else print "nel ";
		}
	}
	print (name) p_obj;
	return;
];

[SuPrep p_obj;
	if (p_obj has pluralname) {
		if (p_obj has female) print "sulle ";
		else {
			if (p_obj has logli) print "sugli ";
			else print "sui ";
		}
	} else {
		if (p_obj has female) {
			if (p_obj has apostrofo) print "sull'";
			else print "sulla ";
		} 
		else {
			if (p_obj has logli) { 
				if (p_obj has apostrofo) print "sull'"; 
				else print "sullo ";
			}
			else print "sul ";
		}
	}
	print (name) p_obj;
	return;
];

[EnterSupp p_obj;
	if (p_obj has supporter) print "Sei ", (SuPrep) p_obj;
	else print "Sei ", (InPrep) p_obj;
	return;
];

[ExitSupp p_obj;
	if (p_obj has supporter) print "Hai disceso ", (the) p_obj;
	else print "Sei fuori ", (DaPrep) p_obj;
	return;
];

!
! Error messages
!
Constant ERR_TOO_MANY_TIMERS_DAEMONS 1;
Constant ERR_OBJECT_HASNT_PROPERTY 2;
Constant ERR_SCOPE_FULL 3;
Constant ERR_UNKNOWN_MSGNO 4;
Constant ERR_INVALID_DIR_PROP 5;
Constant ERR_TOO_MANY_FLOATING 6;
Constant ERR_NOT_DIR_PROP 7;
Constant ERR_NOT_FAKE_OBJ 8;
Constant ERR_ILLEGAL_CHOOSEOBJNO 9;
Constant ERR_BUFFER_OVERRUN 10;
Constant ERR_UNSAFE_GRAMMAR_PROP 11;

[_RunTimeError p_err p_obj _parent;
	print "^[PunyInform error: ";
	if(p_err ofclass string)
		print (string) p_err;
	else {
		print p_err;
#IfTrue RUNTIME_ERRORS == RTE_VERBOSE;
		print " - ";
		switch(p_err) {
		ERR_TOO_MANY_TIMERS_DAEMONS:
			print "Too many timers/daemons";
		ERR_OBJECT_HASNT_PROPERTY:
			print "Object lacks required property";
		ERR_SCOPE_FULL:
			print "Scope full";
		ERR_UNKNOWN_MSGNO:
			print "Unknown message#";
		ERR_INVALID_DIR_PROP:
			print "GoSub called with invalid direction property";
		ERR_TOO_MANY_FLOATING:
			print "Too many floating objects";
		ERR_NOT_DIR_PROP:
			print "DirPropToFakeObj called with non-dirprop";
		ERR_NOT_FAKE_OBJ:
			print "FakeObjToDirProp called with non-fakeobj";
		ERR_ILLEGAL_CHOOSEOBJNO:
			print "ChooseObjectsFinal_(Pick or Discard) called with nonexistent array index";
#Ifdef DEBUG;
		ERR_BUFFER_OVERRUN:
			print "Buffer overrun: Printing too many characters to a buffer";
		ERR_UNSAFE_GRAMMAR_PROP:
			print "Unsafe usage of grammar property";
#Endif;
		default:
			print "Unknown error";
		}
#EndIf;
	}
	print "]^";
#IfTrue RUNTIME_ERRORS == RTE_VERBOSE;
	if(p_obj ofclass object) {
		_parent = parent(p_obj);
		print "Offending object: ", (the) p_obj, " (", p_obj, ") in ", (name) _parent, " (", _parent, ")^";
	}
#Ifnot;
	_parent = p_obj; ! Avoid compiler warning
#EndIf;
	rtrue;
];
