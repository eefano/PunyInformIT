# PunyInformIT

This is a translation of the PunyInform library to Italian.

### [Click Here for the original english version of PunyInform](https://github.com/johanberntsson/PunyInform)

The rest of this document is written in Italian language.

## Presentazione

Questa è la traduzione in italiano della libreria PunyInform.

PunyInform è una libreria scritta in Inform 6 che consente agli autori di creare giochi di avventura testuale / narrativa interattiva utilizzando la macchina virtuale Z-machine, giocabili sia su computer a 8 bit che su piattaforme più recenti. Fornisce un parser, implementazioni dei verbi più comuni e un framework per la scrittura di avventure testuali.

I giochi che utilizzano PunyInform possono essere compilati nei formati z3, z4, z5, z6, z7 e z8. Ciò significa che rispetto ad Inform 6 standard non è supportato Glulx, ma sono supportati i formati z3 e z4 (che viceversa non sono supportati dalla Inform 6 standard). C'è anche un'estensione disponibile per supportare lo schermo grafico z6.

L'obiettivo principale di PunyInform è quello di consentire la realizzazione di giochi veloci e con un ingombro di memoria ridotto. Ciò dovrebbe garantire un buon funzionamento dei giochi su architetture meno recenti, come i computer a 8 bit degli anni '80. Il nostro obiettivo principale è renderlo adatto ai giochi per Commodore 64 utilizzando [Ozmoo](https://github.com/johanberntsson/ozmoo/).


### ATTENZIONE: IL PROGETTO È ANCORA IN FASE DI COMPLETAMENTO

Anche se allo stato attuale sono state effettuate tutte le traduzioni e implementate le grammatiche, non sono ancora stati completati abbastanza test
per poter dichiarare il software completo e senza errori. 

Il progetto è allineato alle modifiche presenti nella release v6.8 di PunyInform.

## Istruzioni

ATTENZIONE: queste istruzioni sono specifiche per questa versione italiana e riflettono la situazione attuale del progetto, che potrebbe cambiare in futuro finchè non sarà rilasciata una prima versione stabile.

### Per i giocatori 

I verbi sono riconosciuti solo nella forma imperativa (```SPINGI```, ```PRENDI```, etc)

Le preposizioni articolate vengono riconosciute, ma non viene fatto un controllo sulla correttezza della forma maschile/femminile singolare/plurale. ```IN```, ```NELLA```, ```NEGLI``` sono intercambiabili e interpretate come ```IN QUALCOSA```.

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

L'apostrofo nei formati ```.z3``` e ```.z4``` non può essere attaccato alla parola successiva (scrivere invece ```L' APOSTROFO``` con lo spazio). I formati ```.z5``` e superiori lo separano in automatico.

### Per gli autori

L'italiano non ha una forma neutra, quindi ricordarsi di utilizzare l'attributo ```female``` anche per oggetti inanimati, dove necessario.

L'attributo ```neuter``` è stato rimosso in favore di due nuovi attributi: ```apostrofo``` e ```logli```. Di conseguenza l'autore avrà a disposizione un attributo libero in meno rispetto a quelli indicati nella documentazione ufficiale.

* ```apostrofo``` serve ad indicare quando il nome prevede un articolo o una preposizione articolata con l'apostrofo. Quando presente, nelle stampe trasforma ```LA ARANCIA``` in ```L'ARANCIA``` oppure ```SULLA INSEGNA``` in ```SULL'INSEGNA```.

* ```logli``` serve ad indicare quando il nome maschile prevede l'articolo ```LO / GLI``` al posto di ```IL / I```. Se presente, nelle stampe trasforma ```IL STRACCIO``` in ```LO STRACCIO``` oppure ```NEL SPORCO``` in ```NELLO SPORCO```

* La combinazione ```apostrofo``` più ```logli``` va usata per i nomi maschili che iniziano con vocale o acca, ad esempio per ottenere correttamente sia ```L'ALBERO / SULL'ALBERO``` che ```GLI ALBERI / SUGLI ALBERI```.

Quando scrivete le vostre regole grammaticali, per le preposizioni utilizzate ```DiGpr``` al posto di ```'di'```, ```AGpr``` al posto di ```'a//'``` e così via anche per ```DaGpr```, ```InGpr```, ```SuGpr```, ```SuDiGpr```. 

Esempio: ```CHIEDI A QUALCUNO SU/DI QUALCOSA```
```
Verb 'chiedi'
    * AGpr creature SuDiGpr topic -> Ask;
```

Esistono routine per stampare la preposizione articolata corretta nelle vostre stringhe: ```(DiPrep)``` ```(APrep)``` ```(DaPrep)``` ```(InPrep)``` ```(SuPrep)```. 

Esempio: ```HAI MESSO LA PALLA NELLA SCATOLA / HAI MESSO LA PALLA NEI CESTI```
```
print "Hai messo ", (the) noun, " ", (InPrep) second, ".";
```

La routine di stampa ```(_o)``` serve per aggiungere i suffissi che declinano gli aggettivi nelle forme combinate maschile/femminile e singolare/plurale. 

Esempio: ```IL NEGOZIO È CHIUSO / LE SERRANDE SONO CHIUSE / LA PORTA È CHIUSA / I PORTONI SONO CHIUSI```
```
print (ObjIs) oggetto, " chius", (_o) oggetto;
``` 

La routine di stampa ```(_e)``` serve se l'aggettivo ha solo la declinazione singolare/plurale.

Esempio: ```L'ACQUA È POTABILE / LE ACQUE SONO POTABILI```
```
print (ObjIs) oggetto, " potabil", (_e) oggetto;
```

La routine di stampa ```(_no)``` serve per aggiungere il suffisso ai verbi riferiti a soggetti plurali.

Esempio: ```IL CANE NON PARLA / I CANI NON PARLANO```
```
print (the) oggetto, " non parla", (_no) oggetto;
```


## Crediti

PunyInform è stato concepito, progettato e programmato da Johan Berntsson e Fredrik Ramsberg, con la collaborazione di Pablo Martinez e Tomas Öberg. 

PunyInform include codice dalla Inform 6 standard library, di Graham Nelson. 

PunyInformIT mantiene la quasi totalità del codice originale di PunyInform, fatto salvo per i messaggi in lingua e le regole grammaticali, ed è a cura di eefano.

