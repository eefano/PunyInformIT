! ######################### Grammar + Actions

[ SelfGpr;
	if (NextWord() == '-mi' or 'me' or '-ti' or 'te') return GPR_PREPOSITION;
	return GPR_FAIL;
];

! ---------------------
! Base verbs
! ---------------------

Verb 'rispondi' 'dì' 'dici'
	* creature topic						-> Answer reverse
	* 'a//'/'a*' creature topic				-> Answer reverse
	* topic 'a//'/'a*' creature -> Answer;
!!
Verb 'chiedi' 'domanda'
		* creature noun 									-> AskFor
		* 'a//'/'a*' creature noun							-> AskFor
		* noun 'a//'/'a*' creature							-> AskFor reverse
    * creature 'su'/'su*'/'sopra'/'di'/'di*' topic 					-> Ask
    * 'a//'/'a*' creature 'su'/'su*'/'sopra'/'di'/'di*' topic 		-> Ask
    * creature topic 									-> Ask
    * 'a//'/'a*' creature topic 						-> Ask
    * 'su'/'su*'/'sopra'/'di'/'di*' topic 'a//'/'a*' creature -> Ask reverse
    * topic 'a//'/'a*' creature -> Ask reverse;
Verb 'ordina' 'comanda' 'impartisci' 
    * creature topic      					-> AskTo
    * 'a//'/'a*' creature topic 					-> AskTo
    * topic 'a//'/'a*' creature -> AskTo reverse;
Verb 'estorci' 
    * creature noun        					-> AskFor
    * 'a//'/'a*' creature noun        		-> AskFor
    * noun 'a//'/'a*' creature        		-> AskFor reverse;
Verb 'richiedi' 'esigi'
    * creature noun        					-> AskFor
    * 'da'/'da*' creature noun        		-> AskFor
    * noun 'da'/'da*' creature        		-> AskFor reverse;
!!
Verb 'attacca' 'rompi' 'crepa' 'distruggi'
		'affronta' 'colpisci' 'uccidi' 'ammazza' 'assassina'
		'scazzotta' 'sfonda' 'calcia' 'tortura' 'demolisci'
	* noun                                      -> Attack
	* 'con' held noun			-> Attack
	* noun 'con' held                          -> Attack;
!!
Verb 'sali' 'scala' 'arrampica'
  *                                 -> GoUp
	* 'su'/'su*'/'sopra' noun            					-> Climb
	*  noun                           -> Climb
	* 'in'/'in*'/'dentro' noun                    	-> Enter
	* 'fuori' 'da'/'da*' noun							-> Exit;
!!
Verb 'chiudi'
    * noun                            -> Close
    * 'a//'/'a*' 'chiave' noun      				-> Lock
    * noun 'con' held                 -> Lock;
Verb 'copri' 'richiudi'
	* noun						-> Close;
!!
Verb 'taglia' 'affetta' 'pota' 'sminuzza' 'trita'
    * noun                               		-> Cut
    * noun 'con' held                    		-> Attack;
!!
Verb 'scava'
    * noun                				-> Dig
    * noun 'con' held                   		-> Dig;
!!
Verb 'bevi' 'sorseggia' 'tracanna'
    * noun                               		-> Drink;
!!
Verb 'scarta' 'lancia' 'scaglia'
    * multiheld                     -> Drop
    * multiexcept 'in'/'in*'/'dentro' noun        -> Insert
    * held 'contro'/'a//'/'a*' noun     					-> ThrowAt
    * multiexcept 'su'/'su*'/'sopra' noun        -> PutOn;
Verb 'abbandona' 'lascia'
    * multiheld                     -> Drop
    * multiexcept 'in'/'in*'/'dentro' noun        -> Insert
    * held 'contro'/'a//'/'a*' noun     					-> ThrowAt
    * multiexcept 'su'/'su*'/'sopra' noun        -> PutOn
		*                               -> Exit
		* noun                          -> Exit;
!!
Verb 'mangia' 'ingoia'
    * held                -> Eat;
!!
#IfDef OPTIONAL_EXTENDED_VERBSET;
Verb 'entra'
	*                                           -> GoIn
	* noun                                      -> Enter
	* 'in'/'in*'/'dentro' noun                  -> Enter;
#IfNot;
Verb 'entra'
	* noun                                      -> Enter
	* 'in'/'in*'/'dentro' noun                  -> Enter;
#Endif;
!!
Verb 'esamina' 'x//'
	* noun -> Examine;
!!
Verb 'esci' 'scappa'
	*                                   -> Exit
	* noun                              -> Exit;
!!
Verb 'riempi'
	* noun                              -> Fill;
!!
Verb 'scendi'
	*																		-> GetOff
	* noun															-> Exit
	* 'da'/'da*' noun										-> Exit;
Verb 'prendi'
	* multi                             -> Take
	* multiinside 'da'/'da*' noun				-> Remove;
Verb 'alza' 'solleva'
	* SelfGpr                           -> Exit
	* multi                             -> Take
	* multiinside 'da'/'da*' noun						-> Remove;
!!
! Attenzione il verbo 'dai' diventa 'da*' per effetto collaterale
! della dearticolizzazione delle preposizioni
Verb 'dà' 'dai' 'da*' 'offri' 'dona'
	* held creature									-> Give
  * held 'a//'/'a*' creature        		-> Give
  * 'a//'/'a*' creature held        		-> Give reverse
  * creature held            			-> Give reverse;
Verb 'sfama' 'paga'
    * 'con' held creature        		-> Give
    * creature 'con' held        		-> Give reverse;

[ ADirection;
	if (noun == Directions) rtrue;
	rfalse;
];
!!
Verb 'vai' 
    * noun=ADirection                   -> Go
    * 'a//'/'a*' noun=ADirection        -> Go
    * noun                              -> Enter
    * 'a//'/'a*' noun                   -> Enter
    * 'in'/'in*'/'dentro' noun          -> Enter;
!!
Verb 'inserisci'
	* multiexcept 'in'/'in*'/'dentro' noun -> Insert;
!!
#Ifdef OPTIONAL_FLEXIBLE_INVENTORY;
Verb 'inventario' 'i//' 
    *                                     		-> Inv
    * 'alto'/'largo'                     		-> Inv;
#Ifnot;
Verb 'inventario' 'i//' 
	* 											-> Inv;
#Endif;
!!
Verb 'salta'
    *                                    		-> Jump
    * noun                               		-> JumpOver
    * 'in'/'in*'/'dentro' noun              -> Enter
    * 'su'/'su*'/'sopra' noun              	-> JumpOver
    * 'oltre' noun              						-> JumpOver;
Verb 'scavalca'
    * noun						-> JumpOver;
!!
Verb 'ascolta'
    *                                    		-> Listen
    * noun                               		-> Listen;
!!
Verb 'serra' 'blocca'
	* noun 'con' held				-> Lock;
!!
Verb 'guarda' 'vedi' 'osserva' 'v//'
    *                                    		-> Look
    * noun                               		-> Examine
    * 'in'/'in*'/'dentro' noun         			-> Search
    * 'su'/'su*'/'sopra' noun         			-> Search;
!!
Verb 'apri' 'schiudi'
	* noun                                      -> Open
	* noun 'con' held                           -> Unlock;
!!
!Verb 'pick'
!unused 
!!
Verb 'tira' 'trascina'
	* noun                                      -> Pull;
!!
Verb 'spingi' 'sgombra' 'muovi' 'premi' 'sposta'
    * noun                               	-> Push
    * noun 'verso' noun=ADirection        -> PushDir
    * noun noun=ADirection                -> PushDir
    * noun 'a//'/'a*' noun         				-> Transfer
    * noun 'su'/'su*'/'sopra' noun        -> Transfer
    * noun 'in'/'in*'/'dentro' noun       -> Transfer
    * noun 'verso' noun                   -> Transfer;
!!
Verb 'piazza' 'posiziona' 'colloca'
	* multiexcept 'in'/'in*'/'dentro' noun	-> Insert
	* multiexcept 'su'/'su*'/'sopra' noun		-> PutOn;
Verb 'metti'
	* multiexcept 'in'/'in*'/'dentro' noun	-> Insert
	* multiexcept 'su'/'su*'/'sopra' noun		-> PutOn
	* 'su' held                             -> Wear
	*  held                                 -> Wear;
!!
Verb 'leggi'
    * noun                               	-> Examine
    * 'in'/'in*'/'dentro' noun 'su'/'su*'/'sopra'/'di'/'di*' topic            -> Consult
    * 'in'/'in*'/'dentro' noun topic            				-> Consult
    * 'su'/'su*'/'sopra'/'di'/'di*' topic 'in'/'in*'/'dentro' noun -> Consult reverse
    * topic 'in'/'in*'/'dentro' noun -> Consult reverse;
!!
Verb 'togli' 'rimuovi'
  * 'di' 'dosso' noun           -> Disrobe
  * SelfGpr noun								-> Disrobe
	* multi                       -> TakeDisrobe
	* multiinside 'da'/'da*' noun			-> Remove;
!!
Verb 'sfrega' 'pulisci' 'spolvera' 'lucida' 'strofina' 'smacchia' 'spazza'
	* noun                                  -> Rub;
!!
Verb 'cerca'
    * noun                          		-> Search
    * 'in'/'in*'/'dentro' noun 'su'/'su*'/'sopra'/'di'/'di*' topic          -> Consult
    * 'in'/'in*'/'dentro' noun topic            			-> Consult
    * 'su'/'su*'/'sopra'/'di'/'di*' topic 'in'/'in*'/'dentro' noun -> Consult reverse
    * topic 'in'/'in*'/'dentro' noun -> Consult reverse;
!!
Verb 'svesti' 'spoglia'
	* 'di'/'di*' held                           -> Disrobe
	* SelfGpr 'di'/'di*' held                   -> Disrobe;
!!
Verb 'grida' 'urla' 'sbraita'
	* 'a//'/'a*' noun                         	-> ShoutAt
	* topic 'a//'/'a*' creature -> Answer
	* topic                               -> Shout
	*                                     -> Shout;
!!
Verb 'mostra' 'presenta' 'sfoggia'
    * held creature                     -> Show
    * 'a//'/'a*' creature held        				-> Show reverse
    * held 'a//'/'a*' creature        				-> Show;
!!
Verb 'siedi' 'sdraia' 'accomoda'
    * SelfGpr 'su'/'su*'/'sopra' noun      -> Enter
    * SelfGpr 'in'/'in*'/'dentro' noun      -> Enter
    * 'su'/'su*'/'sopra' noun             	-> Enter
    * 'in'/'in*'/'dentro' noun             	-> Enter;
!!
Verb 'annusa' 'odora'
    *                                    		-> Smell
    * noun                               		-> Smell;
!!
!!
#Ifndef OPTIONAL_EXTENDED_VERBSET;
Verb 'imposta'
    * 'su'/'a//' 'on' noun                      -> SwitchOn
    * 'su'/'a//' 'off' noun                     -> SwitchOff
    * noun 'su'/'a//' 'on'                      -> SwitchOn
    * noun 'su'/'a//' 'off'                     -> SwitchOff;
#Endif;
Verb 'attiva' 'accendi'
	* noun -> SwitchOn;
Verb 'disattiva' 'spegni'
	* noun -> SwitchOff;
!!
!Verb 'take' 'carry' 'hold'   TODO ?!?!
!	* multi                                     -> Take
!	* 'off' noun                                -> Disrobe
!	* multiinside 'from'/'off' noun             -> Remove
!	* 'inventory'                               -> Inv;
!!
#Ifndef EXT_TALK_MENU;
Verb 'informa' 'narra' 'spiega' 'rivela' 'parla' 'comunica' 'conversa'
    * creature topic                      -> Tell
    * 'con'/'a//'/'a*' creature topic     -> Tell
    * topic 'con'/'a//'/'a*' creature -> Tell reverse;
#Endif;
#Ifdef EXT_TALK_MENU;
Verb 'informa' 'narra' 'spiega' 'rivela'
    * creature topic                      -> Tell
    * 'a//'/'a*' creature topic        		      -> Tell
    * topic 'a//'/'a*' creature -> Tell reverse;
#Endif;
!!
Verb 'lega' 'appiccica' 'avvita' 'ripara' 'incolla' 'salda' 'unisci' 'collega'
    * noun                               		-> Tie
    * noun 'a//'/'a*' noun                     		-> Tie;
!!
Verb 'tocca' 'tasta' 'palpa' 'saggia'
    * noun                               		-> Touch;
!!
Verb 'gira' 'ruota'
    * noun                -> Turn
    * 'su' 'on'	noun		 	-> SwitchOn
    * 'su' 'off' noun     -> SwitchOff
    * noun 'su' 'on'			-> SwitchOn
    * noun 'su' 'off'     -> SwitchOff;
!!
#Ifdef OPTIONAL_EXTENDED_VERBSET;
Verb 'disserra' 'sblocca'
	* noun 'con' held                          -> Unlock;
#Ifnot;
Verb 'disserra' 'sblocca' 'scassina'
	* noun 'con' held                          -> Unlock;
#Endif;
!!
Verb 'aspetta' 'attendi' 'z//'
	*                                           -> Wait;
!!
Verb 'indossa'
	* held                                      -> Wear;

[ AnswerSub;
	if (second > 1 && RunLife(second,##Answer) ~= 0) rfalse;
	return MSG_ANSWER_DEFAULT;
];

[ AskSub;
	if (RunLife(noun,##Ask) ~= 0) rfalse;
	return MSG_ASK_DEFAULT;
];

[ AskToSub;
	PrintMsg(MSG_ASKTO_DEFAULT, noun);
];

[ AskForSub;
	if (noun == player) <<Inv>>;
	PrintMsg(MSG_ASKFOR_DEFAULT, noun);
];

[ AttackSub;
	if(ImplicitGrabIfNotHeld(second)) rtrue;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has animate && RunLife(noun, ##Attack) ~= 0) rfalse;
	return MSG_ATTACK_DEFAULT;
];

[ ClimbSub;
	if(noun has animate) return MSG_CLIMB_ANIMATE;
	return MSG_CLIMB_DEFAULT;
];

[ CloseSub;
	if(ObjectIsUntouchable(noun)) return;
	if(noun hasnt openable) { PrintMsg(MSG_CLOSE_YOU_CANT, 'chiudere'); rtrue; }
	if(noun hasnt open) { PrintMsg(MSG_CLOSE_NOT_OPEN, noun); rtrue; }
	give noun ~open;
	scope_modified = true;
	run_after_routines_msg = MSG_CLOSE_DEFAULT;
	run_after_routines_arg_1 = 'chiudere';
];

[ ConsultSub;
	return MSG_CONSULT_NOTHING_INTERESTING;
];

[ CutSub;
	return MSG_CUT_NO_USE;
];

[ DigSub;
	if(ImplicitGrabIfNotHeld(second)) rtrue;
	return MSG_DIG_NO_USE;
];

[ DisrobeSub;
	if (noun notin player || noun hasnt worn) return MSG_DISROBE_NOT_WEARING;
	give noun ~worn;
	run_after_routines_msg = MSG_DISROBE_DEFAULT;
];

[ DrinkSub;
	return MSG_DRINK_NOTHING_SUITABLE;
];

[ DropSub;
	if(noun notin player) return MSG_DROP_NOT_HOLDING;
	if(ImplicitDisrobeIfWorn(noun)) rtrue;
	move noun to parent(player);
	give noun moved;
#Ifndef OPTIONAL_NO_DARKNESS;
	if(location == thedark)
		scope_modified = true;
#Endif;
	run_after_routines_msg = MSG_DROP_DROPPED;
	!PrintMsg(MSG_DROP_DROPPED, noun); rtrue;
];

[ EatSub;
	if(noun has animate) return MSG_EAT_ANIMATE;
	if(ImplicitGrabIfNotHeld(noun)) rtrue;
	if(noun hasnt edible) return MSG_EAT_INEDIBLE;
	remove noun;
	scope_modified = true;
	run_after_routines_msg = MSG_EAT_DEFAULT;
];

#IfTrue RUNTIME_ERRORS > RTE_MINIMUM;
[ _CheckDoorDirTo p_door;
#Ifdef OPTIONAL_SIMPLE_DOORS;
	if(p_door.&door_dir == 0 || (p_door.&door_to == 0 && (p_door.&found_in == 0 || p_door.#found_in ~= 4))) {
		_RunTimeError(ERR_OBJECT_HASNT_PROPERTY, p_door);
		rtrue;
	}
#Ifnot;
	if(p_door.&door_to == 0 || p_door.&door_dir == 0) {
		_RunTimeError(ERR_OBJECT_HASNT_PROPERTY, p_door);
		rtrue;
	}
#EndIf;
];
#EndIf;


[ DoorDir p_door _door_dir;
#IfTrue RUNTIME_ERRORS > RTE_MINIMUM;
	_CheckDoorDirTo(p_door);
#EndIf;
#IfDef OPTIONAL_SIMPLE_DOORS;
	if(p_door.#door_dir > 2) {
		! This is a Simple Door, where door_dir is an array
		if(real_location == p_door.&found_in-->1)
			_door_dir = 1;
		return p_door.&door_dir-->_door_dir;
	} else {
#EndIf;
		! Normal Inform door
		_door_dir = p_door.door_dir;
		if(UnsignedCompare(_door_dir, top_object) > 0)
			return p_door.door_dir();
		return _door_dir;
#IfDef OPTIONAL_SIMPLE_DOORS;
	}
#EndIf;
];

[ EnterSub _door_dir;
	if(noun has door) {
		_door_dir = DoorDir(noun);
		! Convert to fake object
		_door_dir = DirPropToFakeObj(_door_dir);
		<<Go _door_dir>>;
	}
	if(noun hasnt enterable) { PrintMsg(MSG_ENTER_YOU_CANT, 'entrare'); rtrue; }
	if(player in noun) return MSG_ENTER_ALREADY;
	if(IndirectlyContains(player, noun)) return MSG_ENTER_HELD;
	if(noun has container && noun hasnt open) { PrintMsg(MSG_ENTER_NOT_OPEN, noun); rtrue; }
	if(parent(noun) ~= parent(player)) return MSG_ENTER_BAD_LOCATION;
	PlayerTo(noun, true);
	run_after_routines_msg = MSG_ENTER_DEFAULT;
	run_after_routines_arg_1 = 'entrare';
];

[ ExamineSub x;
#Ifndef OPTIONAL_NO_DARKNESS;
	if(location == thedark) return MSG_EXAMINE_DARK;
#Endif;
	if (noun.description == 0) {
		if (noun has container) {
			if (noun has open or transparent) <<Search noun>>;
			else { PrintMsg(MSG_EXAMINE_CLOSED, noun); rtrue;	}
		}
		if (noun has switchable) return MSG_EXAMINE_ONOFF;
		return MSG_EXAMINE_NOTHING_SPECIAL;
	}
	x = PrintOrRun(noun, description);
	run_after_routines_msg = 1; ! Run after routines, don't print a msg
	if (x == 0 && noun has switchable) return MSG_EXAMINE_ONOFF;
];

[ ExitSub _p;
	_p = parent(player);
	if(parent(_p) == 0) {
		! player not inside, standing in the room
		if(_p.out_to && noun == 0) <<Go FAKE_OUT_OBJ>>;
		return MSG_EXIT_ALREADY;
	}
	if(noun == 0) <<Exit _p>>;
	if(player notin noun) {
		if(IndirectlyContains(noun, player)) { PrintMsg(MSG_EXIT_FIRST_LEAVE, parent(player)); rtrue; }
		if(noun has supporter) return MSG_EXIT_NOT_ON;
		return MSG_EXIT_NOT_IN;
	}
	if(noun has container && noun hasnt open) { PrintMsg(MSG_EXIT_NOT_OPEN, noun); rtrue; }
	PlayerTo(parent(noun), true);
	run_after_routines_msg = MSG_EXIT_DEFAULT;
	run_after_routines_arg_1 = 'uscire';
];

[ FillSub;
	return MSG_FILL_NO_WATER;
];

[ GetOffSub _p;
	_p = parent(player);
	if(parent(_p) == 0) {
		! player not inside, standing in the room
		if(_p.out_to && noun == 0) <<Go FAKE_D_OBJ>>;
		return MSG_EXIT_ALREADY;
	}
  ExitSub();
];

[ GiveSub;
	if(ObjectIsUntouchable(second)) return;
	if (noun notin player) return MSG_GIVE_NOT_HOLDING;
	if (second == player)  return MSG_GIVE_PLAYER;
	if (RunLife(second, ##Give) ~= 0) rfalse;
	return MSG_GIVE_DEFAULT;
];

[ GoSub _prop;
	! when called Directions have been set properly
	_prop = selected_direction;
#IfTrue RUNTIME_ERRORS > RTE_MINIMUM;
	if(_prop == 0) { _RunTimeError(ERR_INVALID_DIR_PROP); rtrue; }
#EndIf;

	return GoDir(_prop);
];

! Generic routine to move object. Can be used for Insert, PutOn, Take, Drop, Transfer, Empty (and Enter/Exit?)
! p_messages:
! 0: Noun is already in second
! 1: Can't put noun in/on itself
! 2: Second isn't open
! 3: Try to grab if not held (1 to try, no message#)
! 4: Try to disrobe noun if worn (1 to try, no message#)
! 5: Second is animate
! 6: Second isn't container
! 7: Second isn't supporter
! 8: Check if second is full
! 9: Default (success) message
[ _MoveNounToSecond p_messages _msg _ancestor _action;
	if(ObjectIsUntouchable(second)) return;
	_ancestor = CommonAncestor(noun, second);

	_msg = p_messages-->0;
	if(_msg && parent(noun) == second) 
		return _msg;
	_msg = p_messages-->1;
	if(_msg && _ancestor == noun) 
		return _msg;
	_msg = p_messages-->2;
	if(_msg && second ~= _ancestor && second has container && second hasnt open) {
		PrintMsg(_msg, second);
		rtrue;
	}
	_msg = p_messages-->3;
	if(_msg && noun ~=player && second ~= Directions &&  ImplicitGrabIfNotHeld(noun)) rtrue;

	_msg = p_messages-->4;
	if(_msg && ImplicitDisrobeIfWorn(noun)) rtrue;

	! run before on receiver
#IfDef DEBUG;
	if(debug_flag & 1) print "(", (name) second, ").before()^";
#EndIf;
	receive_action = action;
	_action = action; action = ##Receive;
	if(RunRoutines(second, before) ~= 0) { action = _action; rtrue; }
	action = _action;

	_msg = p_messages-->5;
	if(_msg && second has animate)
		return _msg;
	_msg = p_messages-->6;
	if(_msg && second hasnt container) {
		PrintMsg(_msg, second);
		rtrue;
	}
	_msg = p_messages-->7;
	if(_msg && second hasnt supporter) {
		PrintMsg(_msg, second);
		rtrue;
	}
	_msg = p_messages-->8;
	if(_msg && _AtFullCapacity(second))
		return _msg;

	move noun to second;

	! run after on object
	if(AfterRoutines()) rtrue;

	! run after on receiver
#IfDef DEBUG;
	if(debug_flag & 1) print "(", (name) second, ").after()^";
#EndIf;
	_action = action; action = ##Receive;
	if(RunRoutines(second, after) ~= 0) { action = _action; rtrue; }
	action = _action;

	if (keep_silent) return;
	_msg = p_messages-->9;
	return _msg; ! Can be 0 or a message#
];


! 0: Noun is already in second
! 1: Can't put noun in/on itself
! 2: Second isn't open
! 3: Try to grab if not held (1 to try, no message#)
! 4: Try to disrobe noun if worn (1 to try, no message#)
! 5: Second is animate
! 6: Second isn't container
! 7: Second isn't supporter
! 8: Check if second is full
! 9: Default (success) message
Array _InsertMessages static -->
	MSG_INSERT_ALREADY
	MSG_INSERT_ITSELF
	MSG_INSERT_NOT_OPEN
	1
	1
	MSG_INSERT_ANIMATE
	MSG_INSERT_NOT_CONTAINER
	0
	MSG_INSERT_NO_ROOM
	MSG_INSERT_DEFAULT;

[ InsertSub;
	if(noun == player) <<Enter second>>;
	return _MoveNounToSecond(_InsertMessages);
];

#Ifdef OPTIONAL_FLEXIBLE_INVENTORY;
[ InvSub _mode;
	_mode = WordValue(num_words);
	if(_mode == 'alto') inventory_style = 0;
	if(_mode == 'largo') inventory_style = 1;
#Ifnot;
[ InvSub;
#Endif;
	run_after_routines_msg = 1; ! Run after routines, don't print a msg
	if(PrintMsg(MSG_INVENTORY_DEFAULT) == false)
		return MSG_INVENTORY_EMPTY;
];

[ JumpSub;
	return MSG_JUMP;
];

[ JumpOverSub;
	return MSG_JUMP_OVER;
];

[ ListenSub;
	return MSG_LISTEN_DEFAULT;
];

[ LockSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun hasnt lockable) { PrintMsg(MSG_LOCK_NOT_A_LOCK, 'serrare'); rtrue; }
	if (noun has locked)  { PrintMsg(MSG_LOCK_ALREADY_LOCKED, 'serrare'); rtrue; }
	if (noun has open) return MSG_LOCK_CLOSE_FIRST;
	if(ImplicitGrabIfNotHeld(second)) rtrue;
	if (RunRoutines(noun, with_key) ~= second) return MSG_LOCK_KEY_DOESNT_FIT;
	give noun locked;
	run_after_routines_msg = MSG_LOCK_DEFAULT;
	run_after_routines_arg_1 = 'serrare';
];

[ LookSub _old_lookmode;
	_old_lookmode = lookmode;
	lookmode = 2; ! force long description
	Look();
	lookmode = _old_lookmode;
];

[ OpenSub;
	if(ObjectIsUntouchable(noun)) return;
	if(noun hasnt openable) { PrintMsg(MSG_OPEN_YOU_CANT, 'aprire'); rtrue; }
	if(noun has locked) return MSG_OPEN_LOCKED;
	if(noun has open) return MSG_OPEN_ALREADY;
	give noun open;
	scope_modified = true;
	run_after_routines_msg = MSG_OPEN_DEFAULT;
];

[ PullSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has static)   return MSG_PULL_STATIC;
	if (noun has scenery)  return MSG_PULL_SCENERY;
	if (noun has animate)  return MSG_PULL_ANIMATE;
	return MSG_PULL_DEFAULT; !Nothing obvious happens
];

[ PushSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has static)   return MSG_PUSH_STATIC;
	if (noun has scenery)  return MSG_PUSH_SCENERY;
	if (noun has animate)  return MSG_PUSH_ANIMATE;
	return MSG_PUSH_DEFAULT;
];

[ PushDirSub;
	return MSG_PUSHDIR_DEFAULT;
];

! 0: Noun is already in second
! 1: Can't put noun in/on itself
! 2: Second isn't open
! 3: Try to grab if not held (1 to try, no message#)
! 4: Try to disrobe noun if worn (1 to try, no message#)
! 5: Second is animate
! 6: Second isn't container
! 7: Second isn't supporter
! 8: Check if second is full
! 9: Default (success) message
Array _PutOnMessages static -->
	MSG_PUTON_ALREADY
	MSG_PUTON_ITSELF
	0
	1
	1
	MSG_PUTON_ANIMATE
	0
	MSG_PUTON_NOT_SUPPORTER
	MSG_PUTON_NO_ROOM
	MSG_PUTON_DEFAULT;

[ PutOnSub;
	if(noun == player) <<Enter second>>;
	return _MoveNounToSecond(_PutOnMessages);
];

[ RemoveSub _i;
	if(noun == player)
		<<Exit second>>;
	_i = parent(noun);
	if (_i ~= second) return MSG_REMOVE_NOT_HERE;
	if(TryToTakeNoun() ~= false) rtrue;
	action = ##Remove; if (AfterRoutines()) rtrue;
	action = ##Take;
	run_after_routines_msg = MSG_REMOVE_DEFAULT;
	!PrintMsg(MSG_REMOVE_DEFAULT, noun); rtrue;
];

[ RubSub;
	return MSG_RUB_DEFAULT;
];

[ SearchSub _i _plural;
#Ifndef OPTIONAL_NO_DARKNESS;
	if(location == thedark) return MSG_SEARCH_DARK;
#Endif;
	if (ObjectIsUntouchable(noun)) return;
	_plural = PrintContents(1, noun);

	if(noun has supporter) {
		if(_plural == 0)
			return MSG_SEARCH_NOTHING_ON;
		else
			return MSG_SEARCH_ON_IT_ISARE;
	}
	if(noun hasnt container) return MSG_SEARCH_NOTHING_SPECIAL;
	if(noun hasnt transparent && noun hasnt open)
		return MSG_SEARCH_CANT_SEE_CLOSED;
	if(AfterRoutines()) rtrue;
	_i = MSG_SEARCH_EMPTY;
	if(_plural)
		_i = MSG_SEARCH_IN_IT_ISARE;
	return _i;
];

[ ShoutSub;
	if(consult_words > 1 && WordValue(consult_from) == 'a')
		return MSG_PARSER_NOSUCHTHING;
	return MSG_SHOUT_DEFAULT;
];

[ ShoutAtSub;
	return MSG_SHOUTAT_DEFAULT;
];

[ ShowSub;
	if (parent(noun) ~= player) return MSG_SHOW_NOT_HOLDING;
	if (second == player) <<Examine noun>>;
	if (RunLife(second, ##Show) ~= 0) rfalse;
	return MSG_SHOW_DEFAULT;
];

[ SmellSub;
	if(ObjectIsUntouchable(noun)) return;
	return MSG_SMELL_DEFAULT;
];

[ SwitchOffSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun hasnt switchable) return MSG_SWITCH_OFF_NOT_SWITCHABLE;
	if (noun hasnt on)         return MSG_SWITCH_OFF_NOT_ON;
	give noun ~on;
	run_after_routines_msg = MSG_SWITCH_OFF_DEFAULT;
];

[ SwitchOnSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun hasnt switchable) return MSG_SWITCH_ON_NOT_SWITCHABLE;
	if (noun has on)           return MSG_SWITCH_ON_ON;
	give noun on;
	run_after_routines_msg = MSG_SWITCH_ON_DEFAULT;
];

[ TakeSub;
	if(TryToTakeNoun(true) ~= false) rtrue;
	run_after_routines_msg = MSG_TAKE_DEFAULT;
	!PrintMsg(MSG_TAKE_DEFAULT); rtrue;
];

[ TakeDisrobeSub;
	if(noun has worn) <<Disrobe noun>>;
	<<Take noun>>;
];

[ TieSub;
	return MSG_TIE_DEFAULT;
];

[ TellSub;
	if (noun == player) return MSG_TELL_PLAYER;
	if (RunLife(noun, ##Tell) ~= 0) rfalse;
	return MSG_TELL_DEFAULT;
];

[ ThrowAtSub;
	if(ImplicitGrabIfNotHeld(noun)) rtrue;
	if(ObjectIsUntouchable(second)) return;
	if(ImplicitDisrobeIfWorn(noun)) rtrue;
	if(second > 1) {
#IfDef DEBUG;
		if(debug_flag & 1) print "(", (name) second, ").before()^";
#EndIf;
		action = ##ThrownAt;
		if (RunRoutines(second, before) ~= 0) { action = ##ThrowAt; rtrue; }
		action = ##ThrowAt;
	}
	if(second hasnt animate) return MSG_THROW_ANIMATE;
	if(RunLife(second,##ThrowAt) ~= 0) rfalse;
	return MSG_THROW_DEFAULT;
];

[ TouchSub;
	if(ObjectIsUntouchable(noun)) return;
	return MSG_TOUCH_DEFAULT;
];

[ TransferSub _work_to_do;
	if(noun notin second) _work_to_do = true;
	if(second == player) { <Take noun>; run_after_routines_msg = _work_to_do; rtrue; }
	if(_work_to_do == false || (noun in parent(player) && second == Directions && selected_direction == d_to))
		return MSG_TRANSFER_ALREADY;
	if(noun notin player && TryToTakeNoun() == true) rtrue;
	if (second == Directions && selected_direction == d_to) {
		<Drop noun>;
		if(noun in location) run_after_routines_msg = 1;
	}
	else {
		if (second has supporter) 
			<PutOn noun second>;
		else 
			<Insert noun second>;
		if(noun in second)
			run_after_routines_msg = 1;
	}
];

[ TurnSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has static)   return MSG_TURN_STATIC;
	if (noun has scenery)  return MSG_TURN_SCENERY;
	if (noun has animate)  return MSG_TURN_ANIMATE;
	return MSG_TURN_DEFAULT;
];

[ UnlockSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun hasnt lockable) { PrintMsg(MSG_UNLOCK_NOT_A_LOCK, 'sbloccare'); rtrue; }
	if (noun hasnt locked)  { PrintMsg(MSG_UNLOCK_ALREADY_UNLOCKED, 'sbloccare'); rtrue; }
	if(ImplicitGrabIfNotHeld(second)) rtrue;
	if (RunRoutines(noun, with_key) ~= second) return MSG_UNLOCK_KEY_DOESNT_FIT;
	give noun ~locked;
	run_after_routines_msg = MSG_UNLOCK_DEFAULT;
	run_after_routines_arg_1 = 'sbloccare';
];

[ WaitSub;
	if(AfterRoutines()) rtrue;
	return MSG_WAIT_DEFAULT;
];

[ WearSub;
	if (parent(noun) ~= player) return MSG_WEAR_NOT_HOLDING;
	if (noun has worn) return MSG_WEAR_ALREADY_WORN;
	if (noun hasnt clothing) { PrintMsg(MSG_WEAR_NOT_CLOTHING, 'indossare'); rtrue; }
	give noun worn;
	run_after_routines_msg = MSG_WEAR_DEFAULT;
];

[ GoUpSub;
	! shortcut to <<Go up>>
	<Go FAKE_U_OBJ>;
];

! ---------------------
! Extended verbs
! ---------------------

#IfDef OPTIONAL_EXTENDED_VERBSET;
!!
Verb 'soffia'
    * noun                               		-> Blow;
!!
Verb 'maledizione' 'dannazione' 'uffa'
    *                                    		-> Mild
    * topic                            			-> Mild;
!!
Verb 'brucia' 'divampa' 'infiamma' 'innesca'
    * noun                               		-> Burn
    * noun 'con' held                    		-> Burn;
!!
Verb 'compra' 'acquista'
    * noun                               		-> Buy;
!!
Verb 'consulta'
    * noun 'su'/'su*'/'sopra'/'di'/'di*' topic            				-> Consult
    * noun topic            								-> Consult;
!!
Verb 'svuota' 'vuota' 'versa' 'riversa'
    * noun              							-> Empty
    * noun 'su'/'su*'/'sopra' noun 								-> EmptyT
    * noun 'in'/'in*'/'dentro' noun 								-> EmptyT;
!!
Verb 'penetra' 'dentro'
	*                                           -> GoIn;
!!
Verb 'bacia' 'abbraccia'
    * creature                           	-> Kiss;
!!
Verb 'no'
	*                                           -> No;
!!
Verb 'sbuccia' 'scortica' 'spella' 'strappa'
	* noun                                      -> Take
	* 'via' noun                                -> Take;
!!
Verb 'prega'
	*                                           -> Pray;
!!
Verb 'scassina' 'forza' 'divella' 'sradica'
	* noun 'con' held                          -> Unlock;
!!
Verb 'imposta' 'regola'
    * noun                               	-> Set
    * 'su'/'a//' 'on' noun                      -> SwitchOn
    * 'su'/'a//' 'off' noun                     -> SwitchOff
    * noun 'su'/'a//' 'on'                      -> SwitchOn
    * noun 'su'/'a//' 'off'                     -> SwitchOff
    * 'su'/'a//' special noun                   -> SetTo
    * noun 'su'/'a//' special                   -> SetTo;
!!
Verb 'merda' 'cazzo' 'figa' 'porco' 'porca' 'puttana' 'bastardo' 'stronzo' 'mannaggia' 'porcaccia'
    *                                   		-> Strong
    * topic                            			-> Strong;
!!
Verb 'canta'
    *                  -> Sing;
!!
Verb 'dormi' 'pisola' 'russa' 'svieni' 'addormenta'
    *                    				-> Sleep
    * SelfGpr										-> Sleep;
!!
Verb 'scusa' 'perdona'
    *                                   		-> Sorry
    * SelfGpr                            		-> Sorry;
!!
Verb 'schiaccia' 'spremi' 'comprimi' 'pressa'
    * noun                               		-> Squeeze;
!!
Verb 'nuota'
    *                                    		-> Swim;
Verb 'tuffa'
    *                                    		-> Swim
    * SelfGpr                            		-> Swim;
!!
Verb 'dondola' 'bilancia' 'aggrappa'
    * noun     			                  			-> Swing
    * 'con'/'su'/'su*'/'sopra' noun         -> Swing
    * SelfGpr 'con'/'su'/'su*'/'sopra' noun -> Swing;
!!
Verb 'assaggia' 'degusta' 'assapora' 'lecca'
    * noun                               		-> Taste;
!!
Verb 'pensa' 'rifletti' 'rimugina'
    *                                    		-> Think;
!!
Verb 'trasferisci' 'trasporta' 'travasa'
   * noun 'a//'/'a*' noun           							-> Transfer
   * noun 'su'/'su*'/'sopra' noun 							          -> Transfer
   * noun 'in'/'in*'/'dentro' noun           							-> Transfer
   * noun 'verso' noun           						-> Transfer;
!!
Verb 'sveglia' 'rinvieni'
    *                                   		-> Wake
    * SelfGpr                           		-> Wake
    * creature                           		-> WakeOther;
!!
Verb 'saluta'
	*                               -> WaveHands
	* 'con' 'la' 'mano'            	-> WaveHands
	* noun                          -> Wave
	* noun 'con' 'la' 'mano'        -> Wave;
!!
Verb 'si'
	*                                           -> Yes;

[ BlowSub;
	if(ImplicitGrabIfNotHeld(noun)) rtrue;
	return MSG_BLOW_DEFAULT;
];

[ BurnSub;
	if(ImplicitGrabIfNotHeld(second)) rtrue;
	return MSG_BURN_DEFAULT;
];

[ BuySub;
	return MSG_BUY_DEFAULT;
];

[ EmptySub;
	<EmptyT noun FAKE_D_OBJ>;
];

[ EmptyTSub _i _n _obj _recipient;
	if(noun == second) return MSG_EMPTY_WOULDNT_ACHIEVE;
	if(noun hasnt container) { PrintMsg(MSG_EMPTY_NOT_CONTAINER, noun); rtrue; }
	if(noun hasnt open) {
		PrintMsg(MSG_EMPTY_IS_CLOSED, noun);
		rtrue;
	}
	if(second == Directions && selected_direction ~= 0)
		_recipient = DirPropToFakeObj(selected_direction);
	else
		_recipient = second;
	_obj = child(noun);
	if(_obj == 0) { PrintMsg(MSG_EMPTY_ALREADY_EMPTY, noun); rtrue; }
	while(_obj ~= 0 && _n<MAX_SCOPE) {
		empty_arr-->_n = _obj;
		_n++;
		_obj = sibling(_obj);
	}
	for(_i=0: _i<_n: _i++) {
		_obj = empty_arr-->_i;
		if(_obj in noun) {
			if(keep_silent == 0) print (name) _obj, ": ";
			<Transfer _obj _recipient>;
		}
	}
	run_after_routines_msg = 1;
];

[ GoInSub;
	! shortcut to <<Go in>>
	<Go FAKE_IN_OBJ>;
];

[ KissSub;
	if (ObjectIsUntouchable(noun)) return;
	if (RunLife(noun, ##Kiss) ~= 0) rfalse;
	if (noun == player) return MSG_KISS_PLAYER;
	return MSG_KISS_DEFAULT;
];

[ MildSub;
	return MSG_MILD_DEFAULT;
];

[ NoSub;
	return MSG_RHETORICAL_QUESTION;
];

[ PraySub;
	return MSG_PRAY_DEFAULT;
];

[ SetSub;
	return MSG_SET_DEFAULT;
];

[ SetToSub;
	return MSG_SET_TO_DEFAULT;
];

[ SingSub;
	return MSG_SING_DEFAULT;
];

[ SleepSub;
	return MSG_SLEEP_DEFAULT;
];

[ SorrySub;
	return MSG_SORRY_DEFAULT;
];

[ StrongSub;
	return MSG_STRONG_DEFAULT;
];

[ SqueezeSub;
	if (ObjectIsUntouchable(noun)) return;
	if (noun has animate) return MSG_SQUEEZE_YOURSELF;
	return MSG_SQUEEZE_DEFAULT;
];

[ SwimSub;
	return MSG_SWIM_DEFAULT;
];

[ SwingSub;
	return MSG_SWING_DEFAULT;
];

[ TasteSub;
	if (ObjectIsUntouchable(noun)) return;
	return MSG_TASTE_DEFAULT;
];

[ ThinkSub;
	return MSG_THINK_DEFAULT;
];

[ WakeSub;
	return MSG_WAKE_DEFAULT;
];

[ WakeOtherSub;
	if (ObjectIsUntouchable(noun)) return;
	if (RunLife(noun, ##WakeOther) ~= 0) rfalse;
	return MSG_WAKEOTHER_DEFAULT;
];

[ WaveSub;
	if(parent(noun) ~= player) { PrintMsg(MSG_WAVE_NOTHOLDING, noun); rtrue; }
	return MSG_WAVE_DEFAULT;
];

[ WaveHandsSub;
	return MSG_WAVEHANDS_DEFAULT;
];

[ YesSub;
	return MSG_RHETORICAL_QUESTION;
];

#EndIf;

! ---------------------
! Base meta verbs
! ---------------------

Verb meta 'ripeti' 'rifai' 'ancora' 'r//'
	*                                           -> Again;

Verb meta 'breve' 'normal'
	*                                           -> LookModeNormal;

#Ifdef OPTIONAL_FULL_SCORE;
Verb meta 'totali' 'totale' 'tot'
    *                                           -> FullScore;
Verb meta 'punti' 'punteggio'
    *                                           -> Score
    * 'totali'/'totale'/'tot'                   -> FullScore;
#Endif;

#Ifndef NO_SCORE;
Verb meta 'notifiche'
	*                                           -> NotifyOn
	* 'on'/'attive'                             -> NotifyOn
	* 'off'/'disattive'                         -> NotifyOff;
#Endif;

Verb meta 'oops' 'ops'
	*                                           -> Oops
	* special                                   -> OopsCorrection;

Verb meta 'ricomincia'
	*                                           -> Restart;

Verb meta 'carica'
	*                                           -> Restore;

Verb meta 'salva'
	*                                           -> Save;

#Ifndef OPTIONAL_FULL_SCORE;
Verb meta 'punti' 'punteggio'
	*                                           -> Score;
#Endif;

Verb meta 'superbrief' 'corto'
	*                                           -> LookModeShort;

Verb meta 'verbose' 'lungo'
	*                                           -> LookModeLong;

Verb meta 'versione'
	*                                           -> Version;

Verb meta 'termina' 'q//'
	*                                           -> Quit;

[ AgainSub;
	! nothing here - this is taken care of in the main game loop instead
];

#IfDef OPTIONAL_FULL_SCORE;
#IfDef TASKS_PROVIDED;
[ FullScoreSub _i _score_sum _sc;
#IfNot;
[ FullScoreSub _i _score_sum;
#EndIf;
	new_line;
	PrintMsg(MSG_FULLSCORE_START);
#IfDef TASKS_PROVIDED;
	for(_i=0 : _i<NUMBER_TASKS : _i++)
		if (task_done->_i == 1) {
			_sc = task_scores->(_i);
			PANum(_sc);
			_score_sum = _score_sum + _sc;
#Ifdef PrintTaskName;
			PrintTaskName(_i);
#Endif;
		}
#IfNot;
	_i = 0; ! Avoid warning
#EndIf;
#IfDef OPTIONAL_SCORED;
	if(things_score ~= 0) {
		PANum(things_score);
		PrintMsg(MSG_FULLSCORE_OBJECTS);
	}
	if(places_score ~= 0) {
		PANum(places_score);
		PrintMsg(MSG_FULLSCORE_ROOMS);
	}
	_score_sum = score - _score_sum - things_score - places_score;
#IfNot;
	_score_sum = score - _score_sum;
#EndIf;
	if(_score_sum ~= 0) {
		PANum(_score_sum);
		PrintMsg(MSG_FULLSCORE_ACTIONS);
	}
	new_line;
	PANum(score);
	return MSG_FULLSCORE_END;
];
#EndIf;

[ LookModeNormalSub;
	lookmode=1;
	return MSG_LOOKMODE_NORMAL;
];

[ LookModeLongSub;
	lookmode=2;
	return MSG_LOOKMODE_LONG;
];

[ LookModeShortSub;
	lookmode=3;
	return MSG_LOOKMODE_SHORT;
];

#Ifndef NO_SCORE;
[ NotifyOnSub;
	notify_mode = 1;
	return MSG_NOTIFY_ON;
];

[ NotifyOffSub;
	notify_mode = 0;
	return MSG_NOTIFY_OFF;
];
#Endif;

[ OopsSub;
	return MSG_OOPS_DEFAULT;
];

[ OopsCorrectionSub;
	! nothing here - this is taken care of in the main game loop instead
];

[ QuitSub;
	PrintMsg(MSG_AREYOUSUREQUIT);
	if(YesOrNo()) {
		deadflag = GS_QUIT;
	}
];

[ RestartSub;
	PrintMsg(MSG_RESTART_CONFIRM);
	if(YesOrNo()) {
		@restart;
		return MSG_RESTART_FAILED;
	}
];

#Iftrue #version_number < 4;
[ RestoreSub;
	@restore ?_restore_was_successful; ! can't use @restore because of compiler test
	verb_word = 'carica';
	return MSG_RESTORE_FAILED;
._restore_was_successful; ! This is never reached, since a successful restore continues after save opcode.
#Ifnot;
[ RestoreSub _flag;
	@restore -> _flag;
	! must have failed here so no need to check the flag
	return MSG_RESTORE_FAILED;
#Endif;
];

#Iftrue #version_number < 4;
[ SaveSub;
	@save ?_save_was_successful;
	return MSG_SAVE_FAILED;
._save_was_successful;
	return MSG_SAVE_DEFAULT;
#Ifnot;
[ SaveSub _result;
	@save -> _result;
	if(_result == 0) return MSG_SAVE_FAILED;
	return MSG_SAVE_DEFAULT; ! _result = 1: save ok, 2: Restore ok
#Endif;
];

#Ifdef NO_SCORE;
[ ScoreSub;
	return MSG_SCORE_DEFAULT;
];
#Ifnot;
[ ScoreSub;
	PrintMsg(MSG_SCORE_DEFAULT);
	PrintRank();
];
#Endif;

[ Banner _i;
	new_line;
#Ifdef Story;
	#Iftrue #version_number > 3;
		style bold;
	#Endif;
		print (string) Story;
	#Iftrue #version_number > 3;
		style roman;
	#Endif;
	#Ifdef Headline;
		print (string) Headline;
	#Ifnot;
		new_line;
	#Endif;
#Endif;
	print "Versione ", (0-->1) & $03ff, " / Numero di serie ";
	for (_i = 18:_i < 24: _i++) print (char) 0->_i;
	print " / Inform v";
	inversion;
	print " PunyInformIT v", PUNYINFORM_MAJOR_VERSION, (char) '.', PUNYINFORM_MINOR_VERSION;
	if(PUNYINFORM_PATCH_VERSION)
		print (char) '.', PUNYINFORM_PATCH_VERSION;
#Ifdef PUNYINFORM_VERSION_SUFFIX;
	print (string) PUNYINFORM_VERSION_SUFFIX;
#EndIf;
	print (char) ' ';
#IfDef STRICT_MODE;
	#Iftrue #version_number > 4;
	print (char) 'S';
	#Endif;
#EndIf;
#IfDef DEBUG;
	print (char) 'D';
#EndIf;
#IfTrue RUNTIME_ERRORS > 0;
	print (char) 'R';
#EndIf;
	new_line;
];

[ VersionSub;
	Banner();
];

! ---------------------
! Extended meta verbs
! ---------------------

#IfDef OPTIONAL_EXTENDED_METAVERBS;
Global transcript_mode = false;        ! true when game scripting is on
Global xcommsdir = false;              ! true if command recording is on

Verb meta 'noscript' 'unscript'
	*                                           -> ScriptOff;

#Ifndef NO_PLACES;
Verb meta 'objects' 'oggetti'
	*                                           -> Objects;
Verb meta 'places' 'luoghi'
	*                                           -> Places;
#Endif; ! NO_PLACES

Verb meta 'recording' 'registrazione'
	*                                           -> CommandsOn
	* 'on'/'attiva'                             -> CommandsOn
	* 'off'/'disattiva'                         -> CommandsOff;

Verb meta 'replay' 'riproduzione'
	*                                           -> CommandsRead;

Verb meta 'script' 'transcript' 'trascrizione'
	*                                           -> ScriptOn
	* 'on'/'attiva'                             -> ScriptOn
	* 'off'/'disattiva'                         -> ScriptOff;

Verb meta 'verify' 'verifica'
	*                                           -> Verify;

[ CommandsOnSub;
	@output_stream 4;
	xcommsdir = 1;
	"[Registrazione comandi attiva.]";
];

[ CommandsOffSub;
	if (xcommsdir == 1) @output_stream -4;
	xcommsdir = 0;
	"[Registrazione comandi disattiva.]";
];

[ CommandsReadSub;
	@input_stream 1;
	xcommsdir = 2;
	"[Riproduzione dei comandi.]";
];

#Ifndef NO_PLACES;
[ PlacesSub _i;
	print "Hai visitato: ";
	objectloop(_i has visited) {
		if(parent(_i) == 0 && _RoomLike(_i)) {
#Ifndef OPTIONAL_NO_DARKNESS;
			if(_i == thedark) continue;
#Endif;
			print "- ", (name) _i; new_line;
		}
	}
];

[ ObjectsSub _i _j _f;
	print "Oggetti che hai posseduto: ";
		objectloop (_i has moved && _ObjectLike(_i)) {
		_j = parent(_i);
		if(_f == 0) new_line;
		_f++;
		print "- ", (the) _i, "   ";
		if (_j == player) {
			if (_i has worn) {
				print "(indossato)";
			} else {
				print "(impugnato)";
			}
		} else if(_j == 0) print "(perso)";
		else if(_j has animate) print "(dato via)";
		else if(_j has visited && parent(_j)==0) print "(nel ", (name) _j, ")";
		else if(_j has container) print "(dentro ", (the) _j, ")";
		else if(_j has supporter) print "(sopra ", (the) _j, ")";
		else if(_j has enterable) print "(dentro ", (the) _j, ")";
		else print "(perso)";
		new_line;
	}
	if(_f == 0) "nulla.";
];
#Endif; ! NO_PLACES

[ ScriptOnSub;
	transcript_mode = (HDR_GAMEFLAGS-->0) & 1;
	if (transcript_mode) "La trascrizione è già attiva.";
	@output_stream 2;
	if (((HDR_GAMEFLAGS-->0) & 1) == 0) "Non riesco ad avviare la trascrizione.";
	print "Inizio la trascrizione di^";
	Banner();
	transcript_mode = true;
];

[ ScriptOffSub;
	transcript_mode = ((HDR_GAMEFLAGS-->0) & 1);
	if (transcript_mode == false) "La trascrizione è già inattiva.";
	print "^Fine della trascrizione.^";
	@output_stream -2;
	if ((HDR_GAMEFLAGS-->0) & 1) "Non riesco a concludere la trascrizione.";
	transcript_mode = false;
];

[ VerifySub;
	@verify ?_verify_was_maybe_ok;
	"Il file del gioco non mi risulta integro e potrebbe essere corrotto.";
._verify_was_maybe_ok;
	"Il file del gioco mi risulta integro.";
];


#EndIf;

! ---------------------
! Debug verbs
! ---------------------

#IfDef DEBUG;
Verb meta 'pronoun'
	*                                           -> Pronouns;
#Iftrue #version_number > 3;
Verb meta 'pronouns'
	*                                           -> Pronouns;
#Endif;

Verb meta 'random'
	*                                           -> RandomSeed
	* special                                   -> RandomSeed
	* 'seed' number                             -> RandomSeed;

Verb meta 'scope'
	*                                           -> Scope
	* noun                                      -> Scope;

Verb meta 'purloin'
	* noun                                      -> Purloin;

Verb meta 'tree'
	*                                           -> Tree
	* number                                    -> Tree
	* noun                                      -> Tree;

Verb meta 'forest'
	*                                           -> Forest;

Verb meta 'rooms'
	*                                           -> Rooms
	* topic                                     -> Rooms;

Verb meta 'gonear'
	* noun                                      -> GoNear;

Verb meta 'goto'
	* topic                                     -> Goto;

Verb meta 'debug'
	*                                           -> Debug
	* 'reactive'                                -> Debug;

Verb meta 'routines' 'messages'
	*                                           -> RoutinesOn
	* 'on'                                      -> RoutinesOn
	* 'off'                                     -> RoutinesOff;

Verb meta 'actions'
	*                                           -> ActionsOn
	* 'on'                                      -> ActionsOn
	* 'off'                                     -> ActionsOff;

Verb meta 'timers' 'daemons'
	*                                           -> TimersOn
	* 'on'                                      -> TimersOn
	* 'off'                                     -> TimersOff;

Global scope_cnt;

[ GoNearSub _obj;
	_obj = noun;
	while(parent(_obj) ~= 0) _obj = parent(_obj);
	if(_obj == noun) print_ret (The) noun, " is not in anything!";
	PlayerTo(_obj);
];

#Ifndef GOTOSUB_BUFFER_SIZE;
Constant GOTOSUB_BUFFER_SIZE 80;
#Endif;

Array _GotoSubBuffer --> (1 + (GOTOSUB_BUFFER_SIZE + 1)/2); ! Add an extra word of constant has odd value

[ GotoSub _obj;
	if(consult_words == 1) {
		_obj = TryNumber(consult_from);
		if(_obj > 0) {
			if(_RoomLike(_obj))
				jump _gotoObj;
			jump _not_a_room;
		}
	}
	_obj = _GotoRoomsHelper(true);
	if(_obj == 0)
		jump _not_a_room;
._gotoObj;
	PlayerTo(_obj);
	rtrue;
._not_a_room;
	"That doesn't seem to be a room.";
];

[ PronounsSub;
	print "lo: ", (name) lo_obj, "^la: ", (name) la_obj, "^li: ", (name) li_obj, "^le: ", (name) le_obj, "^";
];

[ PurloinSub;
	if(noun == player) return MSG_TAKE_YOURSELF;
	if(IndirectlyContains(noun, player)) { PrintMsg(MSG_TAKE_PLAYER_PARENT, noun); rtrue; }

	move noun to player;
	scope_modified = true;
	update_moved = true;
	"Purloined.";
];

[ RandomSeedSub _i;
	! sets the random seed, making randomness predictable
	! also a test of special and number, thus the fancy grammar
	!print special_word, " ", special_number," ",parsed_number,"^";
	if(special_word ~=0) "You can't send randomness to an object!";
	_i = parsed_number;
	if(_i == 0) _i = 100; ! either 'xxxx' (unknown special) or '0'
	random(-_i);
	"The random seed is set to ", _i, ".";
];

[ _ScopeSubHelper p_obj;
	print scope_cnt++,": ", (a) p_obj, " (", p_obj, ")";
	if(ObjectIsUntouchable(p_obj, true)) print " [untouchable]";
	new_line;
];

[ ScopeSub;
	scope_cnt = 1;
	LoopOverScope(_ScopeSubHelper, noun);
	if(scope_cnt < 2) "Nothing in scope.^";
];

[ _TreeSubHelper p_parent p_indent _x _i;
	objectloop(_x in p_parent) {
		for(_i = 0 : _i < p_indent : _i++) print "  ";
		print (a) _x, " (", _x, ")^";
		if(child(_x)) _TreeSubHelper(_x, p_indent + 1);
	}
];

Constant _REAL_LOCATION_TEXT " *** real_location ***";

[ TreeSub p_real_location _p;
	if(parsed_number > 0 && noun == parsed_number) {
		if(parsed_number < Directions || parsed_number > top_object)
			"That doesn't seem to be an object.";
	}

	if(noun==0) noun = real_location;
	if(noun in nothing)
		print (name) noun;
	else
		print (a) noun;
	print " (", noun, ")";
	_p = parent(noun);
	if(_p) {
		if(_p has supporter)
			print " on";
		else
			print " in";
		print " ~", (name) _p, "~ (", _p, ")";
	}
	if(noun == p_real_location) {
#Iftrue #version_number > 3;
		style bold;
#Endif;
		print (string) _REAL_LOCATION_TEXT;
#Iftrue #version_number > 3;
		style roman;
#Endif;
	}
	new_line;
	_TreeSubHelper(noun, 1);
];

[ ForestSub;
	for(noun=Directions : noun<= top_object: noun++)
		if(noun in nothing)
			TreeSub(real_location);
];

[ _GotoRoomsHelper p_return_first _obj _first _i _j _k _m _n _t _count 
		_first_typed_char _first_typed_char_upcase _last_start_pos;
	! p_return_first = true: return the first matching room
	! p_return_first = false: print all matching rooms
	_t = _GotoSubBuffer + 2;
	if(consult_from) {
		_first = WordAddress(consult_from);
		if(_first->0 == '*') _first++; ! Ignore '*' at start of search string
		_i = consult_from + consult_words - 1;
		_count = WordAddress(_i) + WordLength(_i) - _first;
		if(_first->(_count-1) == '*') _count--;  ! Ignore '*' at end of search string
		_first_typed_char = _first->0;
		_first_typed_char_upcase = _first_typed_char;
		if(_first_typed_char_upcase < 123 && _first_typed_char_upcase > 96) {
			_first_typed_char_upcase = _first_typed_char_upcase - 32;
		}
		
	}
	_obj=Directions + 1;
!	for(_obj=Directions + 1 : _obj<= top_object: _obj++)
._check_next_obj;
		if(_RoomLike(_obj)) {

			if(_count > 0) {
				@output_stream 3 _GotoSubBuffer;
				print (name) _obj;
				@output_stream -3;
				_k = _GotoSubBuffer-->0;
#IfTrue RUNTIME_ERRORS > RTE_MINIMUM;
				if(_k > GOTOSUB_BUFFER_SIZE) {
					_RunTimeError(ERR_BUFFER_OVERRUN, _obj);
					rtrue;
				}
#Endif;
				_last_start_pos = _k - _count;

				! Check if search string is part of room name
				_j = 0;
				!for(_j=0:_j<=_last_start_pos:_j++) {
._match_loop;
					if(_t->_j == _first_typed_char or _first_typed_char_upcase) {
						! Found a match for first character
						if(_count == 1) jump _found_match;
						_m = _count - 1;
						_i = 1;
						_n = _j + 1;
!							for(_i=1,_n=_j+1:_i<_count:_i++,_n++) {
._match_next_char;
							_k = _t->_n;
							if(_k < 91 && _k > 64)
								_k = _k + 32;
							if(_k ~= _first->_i) {
								jump _leave_inner_match_loop;
							}
							_n++;
							@inc_chk _i _m ?~_match_next_char;
!							}
						jump _found_match;
._leave_inner_match_loop;
					}
					@inc_chk _j _last_start_pos ?~_match_loop;
!				}
				jump _end_of_obj_loop;
			} 
._found_match;		
			if(p_return_first)
				return _obj;
			print (name) _obj, " (", _obj, ")";
			if(_obj == real_location) {
#Iftrue #version_number > 3;
				style bold;
#Endif;
				print (string) _REAL_LOCATION_TEXT;
#Iftrue #version_number > 3;
				style roman;
#Endif;
			}
			new_line;
		}
._end_of_obj_loop;
		@inc_chk _obj top_object ?~_check_next_obj;
	return false;
];

[ RoomsSub;
	_GotoRoomsHelper();
];

#Ifdef OPTIONAL_MANUAL_REACTIVE;
[ MayBeRoutine p_obj p_prop _val;
	_val = p_obj.&p_prop;
	if(_val == 0) rfalse;
	_val = _val-->0;
	if(_val == 0 or NULL || metaclass(_val) == Routine) rtrue;
	rfalse;
];
#Endif;

[DebugSub _w _o;
	wn = num_words;
	_w = NextWord();
	switch(_w) {
		'reactive':
#Ifndef OPTIONAL_MANUAL_REACTIVE;
			_o = 1;
			"Define OPTIONAL_MANUAL_REACTIVE and recompile.";
#Ifnot;
			print "Probably give reactive to these objects (see notes about ~reactive~ in manual) :^";
			objectloop(_o) {
#Ifdef OPTIONAL_REACTIVE_PARSE_NAME;
				if(_o hasnt reactive && (
						MayBeRoutine(_o, react_before) ||
						MayBeRoutine(_o, react_after) ||
						MayBeRoutine(_o, parse_name) ||
						_o.&add_to_scope ~= 0 ||
						_o.&each_turn ~= 0))
					print "(",_o,") ", (name) _o, "^";
#Ifnot;
				if(_o hasnt reactive && (
						MayBeRoutine(_o, react_before) ||
						MayBeRoutine(_o, react_after) ||
						_o.&add_to_scope ~= 0 ||
						_o.&each_turn ~= 0))
					print "(",_o,") ", (name) _o, "^";
#Endif;
			}
			print "^Remove reactive from these objects:^";
			objectloop(_o) {
#Ifdef OPTIONAL_REACTIVE_PARSE_NAME;
				if(_o has reactive && (
						MayBeRoutine(_o, react_before) == false &&
						MayBeRoutine(_o, react_after) == false &&
						MayBeRoutine(_o, parse_name) == false &&
						_o.&add_to_scope == 0 &&
						_o.&each_turn == 0))
					print "(",_o,") ", (name) _o, "^";
#Ifnot;
				if(_o has reactive && (
						MayBeRoutine(_o, react_before) == false &&
						MayBeRoutine(_o, react_after) == false &&
						_o.&add_to_scope == 0 &&
						_o.&each_turn == 0))
					print "(",_o,") ", (name) _o, "^";
#Endif;
			}
#Endif;
		default:
			"Type one of the following:^
			DEBUG REACTIVE";
	}
];

[ RoutinesOnSub;  debug_flag = debug_flag | 1;  "[Message listing on.]"; ];

[ RoutinesOffSub; debug_flag = debug_flag & 14; "[Message listing off.]"; ];

[ ActionsOnSub;   debug_flag = debug_flag | 2;  "[Action listing on.]"; ];

[ ActionsOffSub;  debug_flag = debug_flag & 13; "[Action listing off.]"; ];

[ TimersOnSub;    debug_flag = debug_flag | 4;  "[Timers listing on.]"; ];

[ TimersOffSub;   debug_flag = debug_flag & 11; "[Timers listing off.]"; ];


#EndIf;

! ---------------------
! HELP ROUTINES
! ---------------------

[ _ListObjsMsg p_parent;
	p_parent = 0; ! Avoid warning
	print "^Puoi vedere ";
	if(also_flag) print "anche ";
];

[ _ListObjsInOnMsg p_parent;
	print "^";
	if(p_parent has supporter) print "Sopra "; else print "Dentro ";
	print (the) p_parent, " puoi vedere ";
	if(also_flag) print "anche ";
];

[ Look _obj _top_ceil _ceil _describe_room _you_can_see_1 _you_can_see_2 
		_desc_prop _action _result;
	if(input_action == ##Look) PrintMsg(MSG_LOOK_BEFORE_ROOMNAME);
	if((lookmode == 1 && location hasnt visited) || lookmode == 2) _describe_room = true;
#Iftrue #version_number > 3;
	style bold;
#Endif;

	! Print the room name
#Ifdef OPTIONAL_NO_DARKNESS;
	_ceil = ScopeCeiling(player);
#Ifnot;
	if(location == thedark)
		_ceil = location;
	else
		_ceil = ScopeCeiling(player);
#Endif;

	_top_ceil = _ceil;

	if(_ceil == location) {
#IfDef OPTIONAL_SCORED;
		if(location has scored && location hasnt visited) {
			score = score + ROOM_SCORE;
#IfDef OPTIONAL_FULL_SCORE;
			places_score = places_score + ROOM_SCORE;
#EndIf;
		}
#EndIf;
		_PrintObjName(location);
	} else
		print (The) _ceil;
#Iftrue #version_number > 3;
	style roman;
#Endif;
#Ifndef OPTIONAL_NO_DARKNESS;
	if(location == thedark) {
		new_line;
		PrintOrRun(location, description);
		jump _EndOfLookRoutine;
	}
#Endif;
	_obj = parent(player);
	while(_obj ~= _ceil or 0) {
		if(_obj has supporter)
			print " (sopra ";
		else
			print " (dentro ";
		print (the) _obj, ")";
		_obj = parent(_obj);
	}
	new_line;
	while(_ceil ~= player or 0) {
		if(_describe_room) {
			if(_ceil == location) {
				PrintOrRun(_ceil, description);
			} else if(_ceil.inside_description ~= 0 or NULL) {
				if(_ceil ~= _top_ceil) new_line;
				PrintOrRun(_ceil, inside_description);
			}
		}

		also_flag = false;
		! write intial and describe messages in a new paragraph
		objectloop(_obj in _ceil)
			if(_obj hasnt scenery or concealed && _obj ~= player) {
				give _obj workflag;
				if(_obj.&describe) {
					_result = PrintOrRun(_obj, describe, 0);
					if(_result) {
						give _obj ~workflag;
						if(_result ~= 2) also_flag = true;
						continue;
					}
				}
				if(_obj has container or door) {
					_desc_prop = when_closed;
					if(_obj has open)
						_desc_prop = when_open;
				} else if(_obj has switchable) {
					_desc_prop = when_off;
					if(_obj has on)
						_desc_prop = when_on;
				} else
					_desc_prop = initial;
				if(_obj.&_desc_prop && (_obj hasnt moved || _desc_prop == when_off)) { ! Note: when_closed in an alias of when_off
					give _obj ~workflag;
					new_line;
					PrintOrRun(_obj, _desc_prop);
					also_flag = true;
				}
			}

		! write any remaining objects in a new paragraph
		if(parent(_ceil) == 0) {
			_you_can_see_1 = _ListObjsMsg;
			_you_can_see_2 = " qui.^";
		} else {
			_you_can_see_1 = _ListObjsInOnMsg;
			_you_can_see_2 = ".^";
		}
		if(PrintContents(_you_can_see_1, _ceil, WORKFLAG_BIT)) 
			print (string) _you_can_see_2;


#IfDef OPTIONAL_PRINT_SCENERY_CONTENTS;
		objectloop(_obj in _ceil)
			if(_obj has scenery &&
					(_obj has supporter ||
						(_obj has container && _obj has transparent or open)) &&
						child(_obj) ~= 0 &&
						IndirectlyContains(_obj, player) == false) {
				if(PrintContents(_ListObjsInOnMsg, _obj))
					print ".^";
			}
#EndIf;

		! Descend one level
		_ceil = ScopeCeiling(player, _ceil);
	} ! while
._EndOfLookRoutine;
#Ifdef LookRoutine;
	! finally, call the optional library entry routine
	RunEntryPointRoutine(LookRoutine);
#Endif;
	_action = action; action = ##Look;
	AfterRoutines();
	action = _action;

	if(_top_ceil == location)
		give location visited;
];

#Ifndef NO_SCORE;
#Ifndef PrintRank;
[ PrintRank; "."; ];
#Endif;
#Endif;

#IfDef OPTIONAL_FULL_SCORE;
#IfDef TASKS_PROVIDED;
[ Achieved num;
	if (task_done->num == 0) {
		task_done->num = 1;
		score = score + task_scores->num;
	}
];
#EndIf;
[ PANum p_m _n;
	print "  ";
	_n = p_m;
	if(_n < 0)    _n = -10 * p_m;
	if(_n < 10)   print " ";
	if(_n < 100)  print " ";
	if(_n < 1000) print " ";
._Panuml;
	print p_m, " ";
];
#EndIf;

[ TryToTakeNoun p_suppress_before_after _i _k _r _ancestor _after_recipient;
	! Try to transfer the given item to the player. Return values:
	! 	0: Success, no message has been printed
	!   1: Failed, a message has been printed
	!   2: Success, a message has been printed

	_k = action;
	if(p_suppress_before_after == false) {
		action = ##Take;
		_r = BeforeRoutines();
		action = _k;
		if (_r) rtrue;
	}

	! People cannot ordinarily be taken.
	if(noun == player) { PrintMsg(MSG_TAKE_YOURSELF); rtrue; };
#Ifdef DisallowTakeAnimate;
	if(noun has animate && DisallowTakeAnimate(noun)) { PrintMsg(MSG_TAKE_ANIMATE); rtrue; }
#Ifnot;
	if(noun has animate) { PrintMsg(MSG_TAKE_ANIMATE); rtrue; }
#Endif;
	_ancestor = CommonAncestor(player, noun);

#Ifndef OPTIONAL_NO_ADD_TO_SCOPE;
	if (_ancestor == 0) {
		_i = _ObjectScopedBySomething(noun);
		if (_i) _ancestor = CommonAncestor(player, _i);
	}
#Endif;

	if(noun in player) { PrintMsg(MSG_TAKE_ALREADY_HAVE); rtrue; }
	if(ObjectIsUntouchable(noun, false, true)) rtrue;
	if(IndirectlyContains(noun, player)) { PrintMsg(MSG_TAKE_PLAYER_PARENT, noun); rtrue; }

	! The item is now known to be accessible.

	! Consult the immediate possessor of the item, if it's in a container
	! which the actor is not in.

	_i = parent(noun);
	if (_i && _i ~= _ancestor && (_i has container or supporter)) {
		_after_recipient = _i;
#IfDef DEBUG;
		if(debug_flag & 1) print "(", (name) _i, ").before()^";
#EndIf;
		action = ##LetGo;
		_r = RunRoutines(_i, before);
		action = _k;
		if (_r) rtrue;
	}
	

	if(noun has scenery) { PrintMsg(MSG_TAKE_SCENERY); rtrue; }
	if(noun has static) { PrintMsg(MSG_TAKE_STATIC); rtrue; }
	if(_AtFullCapacity(player)) { PrintMsg(MSG_TAKE_NO_CAPACITY); rtrue; }

	move noun to player;
	give noun ~concealed;
	update_moved = true;

	! Send "after" message to the object letting go of the item, if any.

	if (_after_recipient) {
#IfDef DEBUG;
		if(debug_flag & 1) print "(", (name) _after_recipient, ").after()^";
#EndIf;
		action = ##LetGo;
		_i = RunRoutines(_after_recipient, after);
		action = _k;
		if(_i) return 2;
	}

	if(p_suppress_before_after == false) {
		action = ##Take;
		_r = AfterRoutines();
		action = _k;
		if (_r) return 2;
	}

	rfalse;
];

[ DoorTo p_door _door_to;
	! Returns the location the door leads to (handling Simple Doors, as needed). 
	! Value true means the exit is blocked and a message has been printed
#IfTrue RUNTIME_ERRORS > RTE_MINIMUM;
	_CheckDoorDirTo(p_door);
#EndIf;
	_door_to = p_door.door_to;
#IfDef OPTIONAL_SIMPLE_DOORS;
	if(_door_to == 0) {
		! This is a Simple Door, where door_to has been left out
		if(real_location == p_door.&found_in-->0)
			_door_to = 1;
		return p_door.&found_in-->_door_to;
	} else {
#EndIf;
		! Normal Inform door
		if(UnsignedCompare(_door_to, top_object) > 0)
			return p_door.door_to();
		return _door_to;
#IfDef OPTIONAL_SIMPLE_DOORS;
	}
#EndIf;
];

[ GoDir p_property _new_location _old_location _vehicle _vehicle_mode _saved_location;
	if(parent(player) ~= real_location) {
		! special rule when in enterable (veichles)
		! before routine for the object is called with Go dir, and returns
		! 0   to disallow the movement, printing a refusal;
		! 1   to allow the movement, moving vehicle and player;
		! 2   to disallow but print and do nothing; or
		! 3   to allow but print and do nothing.
		_vehicle = parent(player);
#IfDef DEBUG;
		if(debug_flag & 1) print "(", (name) _vehicle, ").before()^";
#EndIf;
		_saved_location = location;
#Ifndef OPTIONAL_NO_DARKNESS;
		if(location == thedark) location = real_location;
#Endif;
		_vehicle_mode = RunRoutines(_vehicle, before);
		if(_vehicle_mode ~= 3) location = _saved_location;
		if(_vehicle_mode == 0) { PrintMsg(MSG_GO_FIRST_LEAVE, parent(player)); rtrue; }
		if(_vehicle_mode == 2 or 3) rtrue;
	}
	if(real_location provides p_property) {
		@get_prop real_location p_property -> _new_location; ! works in z3 and z5
	}
	if(IsAString(_new_location))
		print_ret (string) _new_location;
	if(UnsignedCompare(_new_location, top_object) > 0) {
		_new_location = real_location.p_property();
		if(_new_location == 1)
			rtrue;
	}

	! Check for a door
	if(_new_location ~= 0 && _new_location has door) {
		! The destination is in fact a door
		if(_new_location has concealed)
			_new_location = 0;
		else {
			if(_new_location hasnt open) { PrintMsg(MSG_GO_DOOR_CLOSED, _new_location); rtrue; }
			_new_location = DoorTo(_new_location);
			if(_new_location == 1)
				rtrue;
		}
	}

	! If _new_location is 0, we tell the player they can't go there and exit
	if(_new_location == 0) {
		if(real_location provides cant_go) {
#IfDef DEBUG;
!#Iftrue #version_number < 5;
			if(debug_flag & 1) print "[ ~", (name) real_location, "~.cant_go() ]^";
!#Endif;
#EndIf;
			PrintOrRun(real_location, cant_go);
			rtrue;
		}
		return MSG_GO_CANT_GO;
	}

#IfDef DEBUG;
!#Iftrue #version_number < 5;
	if(debug_flag & 1) print "[ ~", (name) _new_location, "~.before() ]^";
!#Endif;
#EndIf;
	action = ##Going;
	if(RunRoutines(_new_location, before)) { action = ##Go; rtrue; }
	action = ##Go;

	if(_vehicle_mode == 1) {
		move _vehicle to _new_location;
		_new_location = _vehicle;
	}

	_old_location = location;

	PlayerTo(_new_location, true);
	if(deadflag ~= GS_PLAYING) rtrue;

	action = ##Going;
	if(RunRoutines(_old_location, after)) { action = ##Go; rtrue; }
	action = ##Go;


	if(AfterRoutines()) rtrue;
	if(keep_silent) rtrue;
	
	PrintMsg(MSG_LOOK_BEFORE_ROOMNAME);
	Look();
];


[ VerbName p_v ;
#Ifdef PrintVerb;
	! first give entry routine a chance to override
	if(PrintVerb(p_v)) return;
#Endif;

#Iftrue #version_number < 4;
	switch(p_v) {
		'r//': print "ripeti"; return;
		'i//', 'inv': print "inventario"; return;
		'l//': print "guarda"; return;
		'q//': print "termina"; return;
		'x//': print "esamina"; return;
		'z//': print "aspetta"; return;
	}

	print (address) p_v;

	! For words longer than 6 characters, print the extra characters
	switch(p_v) {
		'destroy', 'display': print (char) 'y'; return;
		'discard': print (char) 'd'; return;
		'disrobe', 'restore', 'torture', 'verbose': print (char) 'e'; return;
#Ifndef NO_PLACES;
		'objects': print (char) 's'; return;
#Endif;
		'present', 'restart': print (char) 't'; return;
		'superbrief': print "rief"; return;
		'swallow', 'unscrew': print (char) 'w'; return;
		'uncover': print (char) 'r'; return;
		'version': print (char) 'n'; return;
#IfDef OPTIONAL_EXTENDED_VERBSET;
		'consult': print (char) 't'; return;
		'embrace', 'squeeze': print (char) 'e'; return;
		'purchase': print "se"; return;
		'transfer': print "er"; return;
#EndIf;
#IfDef OPTIONAL_EXTENDED_METAVERBS;
		'noscript', 'unscript': print "pt"; return;
		'transcript': print "ript"; return;
#EndIf;
	}
#Ifnot; ! This is z4+
	switch(p_v) {
		'superbrief': print "superbrief"; return;
		'r//': print "ripeti"; return;
		'i//': print (address) 'inventario'; return;
		'l//': print "guarda"; return;
		'q//': print "termina"; return;
		'x//': print (address) "esamina"; return;
		'z//': print "aspetta"; return;
#IfDef OPTIONAL_EXTENDED_METAVERBS;
		'transcript': print "transcript"; return;
#EndIf;
	}
	print (address) p_v;
#Endif;

];

