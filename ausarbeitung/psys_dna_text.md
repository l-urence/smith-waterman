# Einleitung
Seit einigen Jahren steigt die Taktfrequenz von Prozessoren (CPU) nicht weiter an, dies ist durch die hohe Wärmeabgabe bei hohen Taktfrequenzen des Prozessors bedingt. Die Entwicklung vom Mehrkernprozessoren erlaubt es durch Parallelisierung dies teilweise zu kompensieren. Mittlerweile ist nicht nur die Parallelisierung auf herkömmlichen CPUs von Bedeutung. Die rasante Entwicklung von Grafikarten-Prozessoren (GPU) macht diese für parallele Ausführung von Programmen immer interessanter. Verantwortlich ist die wesentlich höhere Anzahl an Prozessorkernen einer GPU im vergleich zu einer herkömmlichen CPU. Auch die die schneller ansteigende Leistung der GPUs im Bezug zu CPUs lassen der Grafikkarte für Parallelisierung mehr Bedeutung zukommen. \cite{cpu:limit}

Diese Arbeit befasst sich mit der Parallelisierung eines Algorithmus für Sequenz Aligments in zwei Zeichenketten. Anwendung finden Algorithmen zur Bestimmung von Aligments zum Großteil in der Bioinformatik, um beispielsweise DNA-Sequenzen zu analysieren. Diese Arbeit betrachtet den Smith-Waterman Algorithmus, welcher das optimale lokale Alignment zweier Zeichenketten A und B ermittelt. Das verwendete Framework für die Parallelisierung auf der GPU ist OpenCL. Die Open Computing Language (OpenCL) definiert einen plattformübergreifenden Standart zum Ausführen von parallelen Anwendungen auf Mehrkern CPUs und GPUs \cite{cl:apple}. Ziel dieser Arbeite ist es die Nebenläufigkeit des Smith-Waterman Algorithmus zu identifizieren und diesen mittels OpenCL auf der GPU zu parallelisieren. Vergleiche zwischen der seriellen und parallelen Version des Algorithmus geben Aufschluss darüber, ob eine effektive Parallelisierung des Algorithmus auf der GPU, unter Berücksichtigung der Implementierung, möglich ist.

# Smith-Waterman Algorithmus
Der Smith-Waterman Algorithmus ist konstruiert um das optimale Alignment zweier Zeichenketten oder Sequenzen zu bestimmen. T.F.  Smith und M.S. Waterman veröffentlichten den Algorithmus 1981 in dem Paper: *Identification of common molecular subsequences*. Wie der zuvor entworfene Algorithmus von Needleman & Wunsch (1970) wird mit Hilfe einer Matrix das Alignment berechnet. Es gibt eine viel Zahl von heuristischen Algorithmen, welche vor der Entwicklung des Smith-Waterman Algorithmus verfasst worden, jedoch sind diese für biologische Untersuchungen nicht hinreichend genug oder nicht interpretierbar. 1982 verbesserte Gotoh den Algorithmus vom Smith & Waterman. Der Ursprüngliche Algorithmus benötigte $M^2N$ Schritte um das lokale Alignment zu erhalten, Gotoh reduzierte die benötigten Schritte auf $MN$, wobei $M$ und $N$ ($M\ge N$) die Längen der zu vergleichenden Zeichenketten bzw. Sequenzen sind. \cite{sw:paper, sw:gotoh}

Bevor jedoch der Algorithmus vom Smith & Waterman beschrieben wird, soll der Unterschied zwischen lokalen und globalen Aligments geklärt werden. Lokale bzw. globale Alignments betrachten die zu untersuchenden Sequenzen unterschiedlich und ermitteln somit verschiedene Ergebnisse. Ein globales Alignment betrachtet das Alignment auf der gesamten Länge der Sequenzen (vgl. Listing \ref{alignment}). Hingen betrachtet das lokale Alignment nur ähnliche Abschnitte in einer Sequenz (vgl. Listing \ref{alignment}). Nun ist es möglich, dass mehrere lokale Alignments in einer Sequenz vorkommen, um das optimale lokale Alignment zu bestimmen, wählt ein Algorithmus das Alignment mir der höchsten Wertigkeit aus. Der Needleman & Wunsch Algorithmus ermittelt ein globales Alignment, indessen der Smith-Waterman Algorithmus ein optimales lokales Alignment bestimmt. \cite{sw:alignment}

\lstinputlisting[label=alignment, caption={Beispiel für globales und lokales Alignment}]{./src_examples/alignemt.txt}

## Algorithmus
Der Smith-Waterman Algorithmus basiert auf dem Paradigma der dynamischen Programmierung. Hierbei ist "Programmierung" nicht im Sinne von schreiben von Code zu verstehen, dynamische Programmierung löst das Probleme durch das Ausfüllen einer Tabelle (Matrix). Wie auch bei bei der Methode von "teile und herrsche" zerlegt dynamische Programmierung ein Probleme in viele leichter zu lösende Teilprobleme, deren Ergebnisse in einer Tabelle hinterlegt werden. Jedoch sind die Teilprobleme untereinander von einander Abhängig, da ihre Berechnungen bzw. Lösungen auf denen der Vorgänger beruhen. Generell lässt sich dynamische Programmierung auf Optimierungsprobleme anwenden. Solche Probleme bestehen aus einer Vielzahl von korrekten Lösungen, wohingegen nur eine optimale Lösung des Problems (Minima, Maxima) von Interesse ist. \cite{sw:dynamic_prog}
Gegeben sind zwei Zeichenketten bzw. Sequenzen ${A=a_1a_2\dots a_n \text{ und } B=b_1b_2\dots b_n}$. 

\input{./img/sw_eq}



## Serieller Ansatz

## Paralleler Ansatz mittels OpenCL

# DNA
Die DNA (Desoxyribonukleinsäure) ist ein Biomolekül und ist Bestandteil jedes Lebewesen und Viren. Es besteht aus vielen Bestandteilen, den sogenannten Nukleotiden. Jedes Nukleotid besteht aus Phosphorsäure bzw. Phosphat und Zucker (Desoxyribose) sowie einer einer Base. Bei der Base kann es sich um Adenin (A), Thymin (T), Cytosin (C) oder Guanin (G) handeln. Die Phosphorsäure und der Zucker sind immer gleich und bilden den Strang des DNA Moleküls. Dabei bilden immer zwei Nukleotide anhand ihrer Basen ein Basenpaar. Es können jedoch nur Basenpaare aus Adenin und Thymin oder Cytosin und Guanin gebildet werden (siehe Abbildung \ref{fig:dna1}). Anhand der Komplexität der DNA Sequenz, die beim Menschen aus 3.101.788.170 Basenpaaren besteht, erfolgt die DNA Sequenzierung abschnittsweise. \cite{dna:dna}

![Strukturmodell eines DNA-Moleküls \cite{dna:dna1} \label{fig:dna1}](./img/dna1)

## Aligments in der DNA
Der Vergleich (Alignment) von DNA Sequenzen spielt eine wichtige Rolle in der Forschung, Medizin, Forensik und Bioinformatik. Es ist mit Hilfe von Algorithmen, wie dem Smith-Waterman Algorithmus möglich zwei DNA Sequenzen miteinander zu vergleichen. Stellt man eine biologische Sequenz als einen eindimensionalen Zeichenkette dar, so kann der Vergleich der beiden Sequenzen als zeichenweiser Vergleich von diesen Zeichenketten verstanden werden. Dazu werden als Zeichen die Abkürzungen der Basenpaare (AT, TA, CG, GC) verwendet. Ein sehr kurzes Beispiel einer Sequenz könnte, wie folgt sein: "CGCGATCGATCGTACGGCATCGCG". Ziel ist es den Grad  Ähnlichkeit bzw. Unähnlichkeit zu bestimmen.

In der Forensik können DNA Sequenzen mit einer vorgegebenen Sequenz verglichen werden, um Täter zu identifizieren. In der Forschung können z.B. Spezies mit anderen Spezies oder defekte DNA Sequenzen mit korrekten DNA Sequenzen verglichen werden. \cite{dna:dna}

# Ergebnisse

# Zusammenfassung

# Ausblick