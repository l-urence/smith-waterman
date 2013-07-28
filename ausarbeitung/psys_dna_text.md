# Einleitung
Seit einigen Jahren steigt die Taktfrequenz von Prozessoren (CPU) nicht weiter an, dies ist durch die hohe Wärmeabgabe bei hohen Taktfrequenzen des Prozessors bedingt. Die Entwicklung vom Mehrkernprozessoren erlaubt es durch Parallelisierung dies teilweise zu kompensieren. Mittlerweile ist nicht nur die Parallelisierung auf herkömmlichen CPUs von Bedeutung. Die rasante Entwicklung von Grafikarten-Prozessoren (GPU) macht diese für parallele Ausführung von Programmen immer interessanter. Verantwortlich ist die wesentlich höhere Anzahl an Prozessorkernen einer GPU im vergleich zu einer herkömmlichen CPU. Auch die die schneller ansteigende Leistung im Bezug auf CPUs lassen der Grafikkarte für Parallelisierung mehr Bedeutung zukommen.

Diese Arbeit befasst sich mit der Parallelisierung eines Algorithmus für Sequenz Aligments in Zeichenketten. Verwendung finden Algorithmen zur Bestimmung von Aligments zum Großenteil in der Bioinformatik, um besipelsweise DNA-Sequenzen zu analysieren. Diese Arbeit betrachtet den Smith-Waterman Algorithmus, welcher das optimale alignment zweier Zeichenketten A und B ermittelt. Das verwendete Framework für die Parallelisierung auf der GPU ist OpenCL. Die Open Computing Language (OpenCL) ist ein plattformübergreifender Standart zum Ausführen von parallelen Anwendungen auf Mehrkern CPUs und GPUs. Ziel dieser Arbeite ist es die Nebenläufigkeit des Smith-Waterman Algorithmus zu identifizieren und diesen mittels OpenCL auf der GPU zu parallelisieren. Vergleiche zwischen der seriellen und parallelen Version des Algorithmus geben Aufschluss darüber, ob eine effektive Parallelisierung des finden von optimalen Aligments in Zeichenketten  möglich ist.

# Smith Waterman

## Serieller - Ansatzt

## Paralleler - Ansatz mittels OpenCL

# DNA - Alignment

## DNA

## Aligments in der DNA

# Ergebnisse

# Zusammenfassung

# Ausblick