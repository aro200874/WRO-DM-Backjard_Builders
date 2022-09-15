# WRO-DM-Backjard_Builders

stand 08.08.2022
---
Einleitung:
Für die deutsche Meisterschaft haben wir und dafür entschieden ein neues besseres Fahrzeug zu bauen. Das neue Fahrzeug wird statt mit einen Fischertechnik TXT Controller jetzt mit einem Arduino Uno gesteuert. Es besteht aber trotzdem noch aus Fischertechnik Bausteinen. Als Antriebsmotor benutzen wier einen schwartzen encodermotor von Fischertechnik. Dieser wird von der H-Brücke l298n angesteuert. Die H-Brücke versorgt auserdem mit Hilfe des intrekrirtrm Spanungswandlers das gesamte fahrzeug mit 5v Spanung. Zur Lenkung benutzen wir einen Handelsüblichen Servomotor. Links und Rechts besitzt das Fahrzeug je einen HC-SR04 Ultraschallsensor. Als kamere benutzen wir eine pixy v2.1 und als Akku einen Fischertechnik NiMH Akku mit 8,4 V und 1800mAh. 



verbaut sind:
Arduino uno zur steuerung des Fahrzeugs

stand 12.08.2022
---
Der Parkur ohne objekte wurde in beide Richtungen Gelöst...

Erstes Umfahren Funktionirt...

stand 18.08.2022

Unfahren mit Ultraschall Uhrzeigersinn...




Programme:
Wir haben zwei Programme geschrieben um die zwei Aufgaben so gut wie möglich zu bewältigen. 

Das erste Programm ist dazu da um das Spielfeld zu umfahren ohne Hindernisse und so schnell wie möglich. Es ist so aufgebaut: 
Zu begin des Programmes werden vorgefertigte Bibilotheken für Kompass und Servo hinzugefügt und Variablen erstellt, für z.B. die Entfernungsmessung mit einem Ultraschallsensor, oder auslesen von Werten des Kompass Sensors.  Danach werden einmal alle Aus- und Eingänge definiert. 
Im loop Teil des Programmes wird zuerst der Motor zum vorwärtz fahren gestartet und die Räder, mithilfe des Servos, auf gerade aus gestellt. Es wird nun Abgefragt welcher Ultraschall Sensor, der Linke oder der Rechte, als erstes eine größeren Abstand als ein Meter anzeigt. So weiß das Programm ob der Roboter gegen den Uhrzeigesinn fährt oder nicht und benutz den Ultraschall weiterhin. Im Programm wird jetzt durchgehen der Ultraschall abgefragt um die Kurven zu erkennen und nicht zu nahe an die innere Wand zu fahren. Fährt der Roboter näher als 20 cm an die Wand lenkt der Servo nach aussen ist der Roboter 20cm entfernt lenkt er gerade aus und ist der Roboter weiter weg als 20 cm lenkt der Servo nach innen. Der Kompass Sensor zählt die 90 grad Kurven und gibt bescheid wenn 12 Kurven gemacht sind also der Roboter 3 Runden gefahren ist. Sind 3 Runden erreicht stopt das Programm.

Das zweite Programm ist mit der Hinderniserkennung von den Grünen und Roten Klötzen.
Zu beginn ist das Programm ähnlich. Es werden nun wieder vorgefertigte Bibilotheken für Kompass und Servo hinzugefügt plus eine zusätzliche für die Kamera. Weiter werden jetzt die Variablen erstellt, für z.B. die Entfernungsmessung mit einem Ultraschallsensor, auslesen von Werten des Kompass Sensors oder auslesen und verarbeiten von Werte der Kamera.  Danach werden einmal alle Aus- und Eingänge definiert und der Servo auf geradeaus gestellt.
Im loop Teil des Programmes werden zuerst vereinfachte Variabeln zum erhalten und verarbeiden der Kamerawerte erstellt. Als nächstes nehmen wir ein ähnlichen Teil vom voherigen Programm und zwar die fahrt mit dem Ultraschall. Mit einem wichtigen Unterschied wir positionieren uns jetzt nicht mit 20cm von der inneren Wand sonder genau mittig im Spielfeld. Somit sind die Hindernisse immer vor der Kamera und werden nicht so schnell übersehen. Die Hindernisse müssen jetzt auch noch erkannt werden. Deswegen wird als nächstes im Programm abgefragt ob der Roboter ein Hindernis sieht und falls ja auch welche Farbe. Erkennt die Kamera ein grünes Hindernis, lenkt der Servo nach links und umfahrt es. Genau das selbe wenn er ein Rotes Hindernis wahr nimmt nur das der Servo nach rechts lenkt. Erkennt er kein Objekt springt er wieder zurück und orientiert sich wieder mit Hilfe von den Ultraschallsensoren. 
Da wir beim Testen öfters Probleme hatten nach den Kurve den Roboter wieder gerade zu positionieren, benutzen wir in Kurven den äußeren Ultraschallsensor.
Der loop Teil wird jetzt kopiert und nochmal eingefügt nur werden die Ultraschalsensoren und die ein oder anderen Werte vertauscht, damit wir auch gegen den Uhrzeigersinn fahren können. Ob Uhrzeigersinn oder gegen Uhrzeigersinn kann zu begin des Programmes über zwei Taster ausgewählt werden.
