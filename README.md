# PunyInformIT

This is a translation of the PunyInform library to Italian.

### [Click Here for the original english version of PunyInform](https://github.com/johanberntsson/PunyInform)

The rest of this document is written in Italian language.

## Presentazione

Questa è la traduzione in italiano della libreria PunyInform.

PunyInform è una libreria scritta in Inform 6 che consente agli autori di creare giochi di avventura testuale / narrativa interattiva utilizzando la macchina virtuale Z-machine, giocabili sia su computer a 8 bit che su piattaforme più recenti. Fornisce un parser, implementazioni dei verbi più comuni e un framework per la scrittura di avventure testuali.

I giochi che utilizzano PunyInform possono essere compilati nei formati z3, z4, z5, z6, z7 e z8. Ciò significa che rispetto a Inform 6 standard non è supportato Glulx, ma sono supportati i formati z3 e z4 (che viceversa non sono supportati dalla Inform 6 standard). C'è anche un'estensione disponibile per supportare lo schermo grafico z6.

L'obiettivo principale di PunyInform è quello di consentire la realizzazione di giochi veloci e con un ingombro di memoria ridotto. Ciò dovrebbe garantire un buon funzionamento dei giochi su architetture meno recenti, come i computer a 8 bit degli anni '80. Il nostro obiettivo principale è renderlo adatto ai giochi per Commodore 64 utilizzando [Ozmoo](https://github.com/johanberntsson/ozmoo/).


### ATTENZIONE: IL PROGETTO È ANCORA IN FASE DI COMPLETAMENTO

Anche se allo stato attuale sono state effettuate tutte le traduzioni e implementate le grammatiche, non sono ancora stati completati abbastanza test
per poter dichiarare il software completo e senza errori. 

Queste istruzioni sono specifiche per questa versione italiana e riflettono la situazione attuale del progetto, che potrebbe cambiare in futuro finchè non sarà rilasciata una prima versione stabile.

Il progetto è allineato alle modifiche presenti nella release v6.8 di PunyInform.


## Istruzioni per i giocatori

### Verbi

I verbi sono riconosciuti solo nella forma imperativa (```SPINGI```, ```PRENDI```, etc)

Per questo motivo, per ordinare agli NPC di eseguire azioni, al posto di scrivere ```ORDINA A GIANNI DI GUARDARE```, bisogna scrivere ```GIANNI, GUARDA ``` oppure ```ORDINA A GIANNI GUARDA```.

Le preposizioni articolate vengono riconosciute, ma non viene fatto un controllo sulla correttezza della forma maschile/femminile singolare/plurale. ```IN```, ```NELLA```, ```NEGLI``` sono intercambiabili e interpretate come ```IN QUALCOSA```.


### Pronomi in suffisso

Nei giochi in formato ```.z3``` o ```.z4``` i pronomi non possono essere combinati con l'imperativo. Per esempio, la frase:
```
PRENDI LA SCATOLA E APRILA
```
occorrerà scriverla in una di queste forme alternative:
```
PRENDI LA SCATOLA E APRI -LA
PRENDI LA SCATOLA E APRI QUELLA
```
I formati ```.z5``` e superiori supportano invece tutte le varianti.

Per coerenza, anche i verbi riflessivi in ```.z3``` o ```.z4``` si scrivono così:
```
ALZA -TI / ALZA TE / SOLLEVA -TI / SOLLEVA TE
PERDONA -MI / PERDONA ME
AGGRAPPA -TI ALLA FUNE / AGGRAPPA LA FUNE 
```
Per brevità, i pronomi riflessivi si possono in genere omettere, tranne per i verbi ```ALZA``` e ```SOLLEVA``` perchè possono essere usati anche con oggetti.


### Apostrofi

L'apostrofo nei formati ```.z3``` e ```.z4``` non può essere attaccato alla parola successiva (scrivere invece ```L' APOSTROFO``` con lo spazio). I formati ```.z5``` e superiori lo separano in automatico.


## Istruzioni per gli autori

### Attributi 

L'italiano non ha una forma neutra, quindi ricordarsi di utilizzare l'attributo ```female``` anche per oggetti inanimati, dove necessario.

L'attributo ```neuter``` è stato rimosso in favore di due nuovi attributi: ```apostrofo``` e ```logli```. Di conseguenza l'autore avrà a disposizione un attributo libero in meno rispetto a quelli indicati nella documentazione ufficiale.

* ```apostrofo``` serve a indicare quando il nome prevede un articolo o una preposizione articolata con l'apostrofo. Quando presente, nelle stampe trasforma ```LA ARANCIA``` in ```L'ARANCIA``` oppure ```SULLA INSEGNA``` in ```SULL'INSEGNA```.

* ```logli``` serve a indicare quando il nome maschile prevede l'articolo ```LO / GLI``` al posto di ```IL / I```. Se presente, nelle stampe trasforma ```IL STRACCIO``` in ```LO STRACCIO``` oppure ```NEL SPORCO``` in ```NELLO SPORCO```

* Per i nomi maschili che iniziano per vocale o acca è sufficiente indicare ```apostrofo``` dato che l'uso di ```LO / GLI``` è implicito. L'articolo indefinito maschile singolare ```UN``` verrà comunque stampato senza apostrofo. 


### Numeri

Quando definite la costante ```OPTIONAL_ALLOW_WRITTEN_NUMBERS``` il numero uno va in confiltto con gli articoli indeterminativi ```uno```,```una```,```un'```, che in genere sono ignorati dal parser, ma in questa modalità sono trattati come quantità numeriche.

In generale il risultato non cambia, tranne in alcuni casi: in particolare quando implementate ```ChooseObjectsFinal```: affinchè tutto funzioni correttamente dovete includere gli articoli indeterminativi tra i ```name``` dell'oggetto, oppure trattati nella routine ```parse_name```.


### Preposizioni articolate

Le preposizioni articolate vengono automaticamente sostituite con ```di*```, ```a*```, ```da*```, ```in*```, ```su*```, prima di eseguire il parser.

Di conseguenza quando create le vostre regole grammaticali includete anche queste preposizioni "asteriscate" per poterle far riconoscere.

Per esempio, questa regola:
```
Verb 'domanda'
    * 'di'/'di*' topic 'a//'/'a*' creature -> Ask;
```
riconosce correttamente entrambe queste frasi:
```
DOMANDA DI VILLAGGIO A ORCHI
DOMANDA DEL VILLAGGIO AGLI ORCHI
``` 

ATTENZIONE, EFFETTI COLLATERALI: 

* Il verbo standard ```'dai'``` diventa ```'da*'```. Ricordatevelo se dovreste ridefinire o estendere questo verbo!

* Se gli oggetti contengono preposizioni articolate nella loro descrizione principale, per esempio ```Object -> Toolbox "scatola degli attrezzi"```, definite la loro lista dei nomi in modo opportuno, per esempio: ```with name 'scatola' 'di*' 'attrezzi'```.


### Verbi riflessivi

Per gestire le regole su azioni riflessive è stato creato ```SelfGpr```. Per esempio ```TUFFATI``` (che in Z3 si scrive ```TUFFA -TI / TUFFA TE```) la regola si costruisce così:
```
Verb 'tuffa'
    * SelfGpr -> Swim;
```

### Routine di stampa

 ```(DiPrep)```, ```(APrep)```, ```(DaPrep)```, ```(InPrep)```, ```(SuPrep)```: stampano il nome dell'oggetto con davanti la preposizione articolata corretta. 

Esempio: ```HAI MESSO LA PALLA NELLA SCATOLA / HAI MESSO LA PALLA NEI CESTI```
```
print "Hai messo ", (the) noun, " ", (InPrep) second, ".";
```

```(ArtCD)``` (Articolo Capitalizzato Determinativo),```(ArtD)``` (Articolo Determinativo), ```(ArtI)``` (articolo Indeterminativo): stampano solo l'articolo di un oggetto, con uno spazio in fondo se non prevede l'uso di un apostrofo.

```(_o)```: serve per aggiungere i suffissi che declinano gli aggettivi nelle forme combinate maschile/femminile e singolare/plurale. 

Esempio: ```IL NEGOZIO È CHIUSO / LE SERRANDE SONO CHIUSE / LA PORTA È CHIUSA / I PORTONI SONO CHIUSI```
```
print (ObjIs) oggetto, " chius", (_o) oggetto;
``` 

```(_e)```: serve se l'aggettivo ha solo la declinazione singolare/plurale.

Esempio: ```L'ACQUA È POTABILE / LE ACQUE SONO POTABILI```
```
print (ObjIs) oggetto, " potabil", (_e) oggetto;
```

```(_no)```: serve per aggiungere il suffisso ai verbi riferiti a soggetti plurali.

Esempio: ```IL CANE NON PARLA / I CANI NON PARLANO```
```
print (the) oggetto, " non parla", (_no) oggetto;
```


## Crediti

PunyInform è stato concepito, progettato e programmato da Johan Berntsson e Fredrik Ramsberg, con la collaborazione di Pablo Martinez e Tomas Öberg. 

PunyInform include codice dalla Inform 6 standard library, di Graham Nelson. 

PunyInformIT mantiene la quasi totalità del codice originale di PunyInform, fatto salvo per i messaggi in lingua e le regole grammaticali, ed è a cura di eefano.

