# Einleitung
Seit einigen Jahren steigt die Taktfrequenz von Prozessoren (CPU) nicht weiter an, dies ist durch die hohe Wärmeabgabe bei hohen Taktfrequenzen des Prozessors bedingt. Die Entwicklung vom Mehrkernprozessoren erlaubt es durch Parallelisierung dies teilweise zu kompensieren. Mittlerweile ist nicht nur die Parallelisierung auf herkömmlichen CPUs von Bedeutung. Die rasante Entwicklung von Grafikarten-Prozessoren (GPU) macht diese für parallele Ausführung von Programmen immer interessanter. Verantwortlich ist die wesentlich höhere Anzahl an Prozessorkernen einer GPU im vergleich zu einer herkömmlichen CPU. Auch die die schneller ansteigende Leistung im Bezug auf CPUs lassen der Grafikkarte für Parallelisierung mehr Bedeutung zukommen.

Diese Arbeit befasst sich mit der Parallelisierung eines Algorithmus für Sequenz Aligments in Zeichenketten. Verwendung finden Algorithmen zur Bestimmung von Aligments zum Großenteil in der Bioinformatik, um besipelsweise DNA-Sequenzen zu analysieren. Diese Arbeit betrachtet den Smith-Waterman Algorithmus, welcher das optimale alignment zweier Zeichenketten A und B ermittelt. Das verwendete Framework für die Parallelisierung auf der GPU ist OpenCL. Die Open Computing Language (OpenCL) ist ein plattformübergreifender Standart zum Ausführen von parallelen Anwendungen auf Mehrkern CPUs und GPUs. Ziel dieser Arbeite ist es die Nebenläufigkeit des Smith-Waterman Algorithmus zu identifizieren und diesen mittels OpenCL auf der GPU zu parallelisieren. Vergleiche zwischen der seriellen und parallelen Version des Algorithmus geben Aufschluss darüber, ob eine effektive Parallelisierung des finden von optimalen Aligments in Zeichenketten  möglich ist.

# Smith Waterman

## Serieller - Ansatzt

## Paralleler - Ansatz mittels OpenCL

# DNA - Alignment

## DNA
Die DNA (Desoxyribonukleinsäure) ist ein Biomolekül und ist Bestandteil jedes Lebewesen und Viren. Es besteht aus vielen Bestandteilen, den sogenannten Nukleotiden. Jedes Nukleotid besteht aus Phosphorsäure bzw. Phosphat und Zucker (Desoxyribose) sowie einer einer Base. Bei der Base kann es sich um Adenin (A), Thymin (T), Cytosin (C) oder Guanin (G) handeln. Die Phoshorsäure und der Zucker sind immer gleich und bilden den Strang des DNA Moleküls. Dabei bilden immer zwei Nukleotide anhand ihrer Basen ein Basenpaar. Es können jedoch nur Basenpaare aus Adenin und Thymin oder Cytosin und Guanin gebildet werden (siehe Abbildung \ref{fig:dna1}). Anhand der Komplexität der DNA Sequenz, die beim Menschen aus 3.101.788.170 Basenpaaren besteht, erfolgt die DNA Sequenzierung abschnittsweise. \cite{dna:dna}

![Strukturmodell eines DNA-Moleküls \cite{dna:dna1} \label{fig:dna1}](./img/dna1)

## Aligments in der DNA
Der Vergleich (Alignment) von DNA Sequenzen spielt eine wichtige Rolle in der Forschung, Medizin, Forensik und Bioinformatik. Es ist mit Hilfe von Algorithmen, wie dem Smith-Waterman Algorithmus möglich zwei DNA Sequenzen miteinander zu vergleichen. Stellt man eine biologische Sequenz als einen eindimensionalen Zeichenkette dar, so kann der Vergleich der beiden Sequenzen als zeichenweiser Vergleich von diesen Zeichenketten verstanden werden. Dazu werden als Zeichen die Abkürzungen der Basenpaare (AT, TA, CG, GC) verwendet. Ein sehr kurzes Beispiel einer Sequenz könnte, wie folgt sein:"CGCGATCGATCGTACGGCATCGCG". Ziel ist es den Grad  Ähnlichkeit bzw. Unähnlichkeit zu bestimmen.

In der Forensik können DNA Sequenzen mit einer vorgegebenen Sequenz verglichen werden, um Täter zu identifizieren. In der Forschung können z.B. Spezies mit anderen Spezies oder defekte DNA Sequenzen mit korrekten DNA Sequenzen verglichen werden. \cite{dna:dna}

# Ergebnisse

# Zusammenfassung

# Ausblick