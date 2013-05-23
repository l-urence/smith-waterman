# Einleitung
In der Bioinformatik stellt die Ermittlung von Ähnlichkeitsmaßen eine wichtige Rolle ...

Ziel dieser Arbeit ist ...

# Grundlagen
## Alignment
Ein Alignment ist ein Paar aus zwei gegebenen Sequenzen.

## OpenMP
Mit Hilfe von OpenMP können parallelisierte Anwendungen bequem ohne externe Bibliotheken realisiert werden. OpenMP ist Bestandteil von gcc.

## OpenCL
OpenCL (Abk. Open Computing Language) ist eine von Apple im Jahr 2008 entwickelte frei verfügbare Bibliothek zur Entwicklung von parallelisierten Anwendungen. Ein OpenCL System besteht aus einem Host und mehreren Geräten. 

.... SIEHE WIKI und NVIDIA FOLIEN...

Die Rechenoperationen können parallel von der CPU oder der weitaus performanten GPU erfolgen. Die Bibliothek stellt alle notwendigen Schnittstellen zur Verfügung.
 
## DNA
Text

## Smith-Waterman
Der Smith-Waterman Algorithmus dient zur Ermittlung von lokalen Alignments zweier Sequenzen. Das Ziel ist es, die Teilsequenzen mit der größten Übereinstimmung zwischen zwei gegebenen Sequenzen zu finden. Dazu wird aus beiden Sequenzen eine Bewertungsmatrix gebildet, mit deren Hilfe es möglich ist Übereinstimmungen und Unterschiede in den Sequenzen festzustellen.
Bei Übereinstimmung (match) einzelner Sequenzelemente wird die Position in der Matrix mit +2 bewertet. Unterschiede (mismatches) und Lücken (gaps) werden mit -1 bewertet. Der niedrigste Wert einer Bewertung beträgt 0. Nach dem Bewerten aller Sequenzelemente in der Matrix wird rückwärts von unten rechts vom höchsten Bewertungswert diagonal zum nächst tieferen Wert hochgegangen bis zum Wert 1. Sind mehere gleichhohe Bewertungswerte vorhanden, so muss dieser Vorgang bei diesen auch wiederholt werden und es gibt mehr als eine gemeinsame Teilsequenz. \cite{sw:algorithmus}

## Initialisierung
Zu Beginn wird die erste gegebene Sequenz .... \cite{sw:berechnung}

# Implementierung

## Single

## Parallelisiert (opencl)

# Auswertung

# Fazit

# Ausblick