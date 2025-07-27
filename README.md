# 🚗 Controllo Motori DC con Telecomando IR – Ponte H

## 🔧 Descrizione del progetto
Questo progetto ha lo scopo di controllare la direzione e la velocità di due motori DC tramite un telecomando a infrarossi. Il sistema è basato su una scheda **Arduino Uno** e utilizza il driver **L293D** per gestire il ponte H. I comandi IR permettono di muovere il modellino in avanti, indietro, girare a destra/sinistra, e regolare la velocità. LED colorati indicano lo stato corrente del sistema.

## 🧠 Principio di funzionamento
- Il sensore IR riceve i comandi dal telecomando.
- Arduino decodifica il segnale e attiva i motori e LED corrispondenti.
- Il driver L293D gestisce la direzione dei motori.
- La velocità è controllata tramite segnale PWM generato da Arduino.
- I LED indicano lo stato: rosso (STOP), verde (AVANTI), giallo (INDIETRO).

## ⚙️ Componenti utilizzati
- Arduino Uno  
- Sensore infrarossi IR  
- Driver L293D  
- Motori DC x2  
- LED: rosso, verde, giallo  
- Breadboard  
- Resistori da 220Ω x3  
- Telecomando IR  
- Cavi jumper

## 🖥️ Software utilizzato
- **Arduino IDE**: per la scrittura e caricamento del codice  
- **Autodesk Tinkercad**: per lo schema elettrico  
- **Microsoft Visio**: per il diagramma di flusso  
- **Adobe Illustrator / Photoshop**: per la grafica e layout

## 🧩 Schema elettrico e diagrammi
Sono inclusi nella documentazione originale (`Relazione.pdf`) e comprendono:
- Schema elettrico del circuito
- Diagramma di flusso del programma
- Schema di principio del modellino
- Piedinatura del driver L293D
- Layout dei tasti del telecomando

## 🔄 Possibili estensioni
Una futura evoluzione del progetto potrebbe includere:
- Sensori di prossimità per evitare ostacoli
- Feedback tramite encoder per controllo preciso della velocità
- Controllo via Bluetooth o Wi-Fi

## 👨‍💻 Autore

Nicolò Emilii

---
