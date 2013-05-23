# Installations- und Konfigurationsanleitung
In diesem Abschnitt werden zwei Installations- und Konfigurationsschritte beschrieben.

Zur Realisierung der Belegarbeit wurden zwei verschiedene Computersysteme verwendet. Es handelt sich dabei um die Folgenden:

System 1: HP G62 Notebook, AMD Radeon HD 5430, Ubuntu 12.10 x64, 4GB RAM

System 2: MacBook Pro mid 2009 8GB RAM
Installation des AMD/ATI OpenCL SDK auf Ubuntu 12.10

Für die Einrichtung von Ubuntu+OpenCL sind die folgenden Schritte notwendig :
# Installation von Ubuntu 12.10 64 Bit
Zuerst muss Ubuntu installiert werden. Dazu die aktuelle Version herunterladen und installieren.
Es darf keine virtuelle Maschine verwendet werden, weil die Grafikkarte des Quellsystems nicht durchgereicht wird und somit keine OpenCL per GPU möglich ist.
Verwendet wird die Version 12.10 64Bit.

## Installation vom AMD Catalyst Treiber
Bevor der aktuelle AMD Treiber installiert werden kann, müssen die aktuellen Pakete linux-headers-generic und linux-source installiert werden. Dazu die folgenden Befehle in das Terminal eingeben:
sudo apt-get install linux-source
sudo apt-get install linux-headers-generic

Obwohl Ubuntu einen X.Org AMD/Ati Treiber bereits installiert hat, wird dieser nicht von OpenCL unterstützt. Aktuelle Treiber gibt es unter der folgenden URL: http://support.amd.com/us/gpudownload/Pages/index.aspx

Sofern Ubuntu nicht neu aufgesetzt wurde und bereits ein veralteter AMD/Ati Treiber vorhanden ist, muss der folgende Befehl ausgeführt werden. Bei einem frisch aufgesetzten Ubuntu kann dieser Schritt übersprungen werden.

sudo apt-get purge fglrx*

Verwendet wurde der 64 Bit Treiber amd-catalyst-13.4-linux-x86.x86_64.zip

Notwendige Befehle für das Terminal:
unzip amd-catalyst-13.4-linux-x86.x86_64.zip
sudo sh ./amd-catalyst-13.4-linux-x86.x86_64.run

Nach erfolgreicher Installation auf keinen Fall das System neustarten! Es ist wichtig zuvor Schritt 1.4 durchzuführen.

## Überprüfung der erfolgreichen Installation
Mit dem folgenden Befehl kann die Installation des Treiber geprüft werden:
fglrxinfo

Es sollte die folgende Ausgabe im Terminal erscheinen:
wojtek@Notebook:~$ fglrxinfo
display: :0  screen: 0
OpenGL vendor string: Advanced Micro Devices, Inc.
OpenGL renderer string: ATI Mobility Radeon HD 5000 Series  
OpenGL version string: 4.2.11903 Compatibility Profile Context

## Fehlende Libs installieren
Sobald ein manuell installierter AMD/Ati Treiber verwendet wird, startet der Desktop von Ubuntu 12.10 nach einem Neustart nicht mehr, weil die AMD/Ati Treiber kein X.Org unterstützen. Es ist nur noch der Hintergrund und der Mauszeiger zusehen. Deshalb muss das folgende Paket bei einem 64Bit System neuinstalliert werden:
sudo apt-get install lib32gcc1

## Download und Installation von AMD-APP SDK Version 2.8
OpenCL ist unter der folgenden URL verfügbar: http://developer.amd.com/tools-and-sdks/heterogeneous-computing/amd-accelerated-parallel-processing-app-sdk/downloads/

Verwendet wird AMD-APP-SDK-v2.8-lnx64.tgz

Nach dem Downloadvorgang wird per Terminal die Datei mit dem folgenden Befehl entpackt und installiert:

tar xzvf AMD-APP-SDK-v2.8-lnx64.tgz
sudo ./Install-AMD-APP

## Reboot und Zugriffsberechtigungen ändern
Anschließend muss der Besitzer für das installierte OpenCL SDK gesetzt werden. Dazu den folgenden Befehl in das Terminal eingeben. (user durch den verwendeten Benutzernamen ersetzen.)

sudo chown -R user:user /opt/AMDAPP

Nun kann das System neugestartet werden.

## Kompilierung und Ausführung der Testapplikationen
In das Verzeichnis /opt/AMDAPP wechseln und den Befehl make im Terminal ausführen. Sollte der Kompilierungsvorgang mit der folgenden Fehlermeldung fehlschlagen, fehlt ein weiteres Paket.

Fehlermeldung: “GL/glu.h: No such file or directory.”

GL/glu.h befindet sich im Paket libglu1-mesa-dev und muss installiert werden.

sudo apt-get install libglu1-mesa-dev

Nach der Installation, sollte die Kompilierung erfolgreich abschließen.

# Installation des Intel OpenCL SDK auf Mac OS X


# Probleme und Lösungen
## C Quellcode kompilieren
Die C Beispiele aus dem Repository von Sebastian Bauer verursachen beim Kompilieren mit Hilfe von make einen Fehler. Leider kann das OpenCL Verzeichnis nicht gefunden werden.

wojtek@Notebook:~/Arbeitsfläche/bauers/psys/examples/opencl/hellocl$ make

gcc -ggdb -O3 -Wall -Wmissing-prototypes -ggdb -O3 -Wall  -c -o hellocl.o hellocl.c
hellocl.c:14:19: Schwerwiegender Fehler: CL/cl.h: Datei oder Verzeichnis nicht gefunden
Kompilierung beendet.
make: *** [hellocl.o] Fehler 1

Dem Compiler muss der Speicherort von OpenCL mitgeteilt werden. Wie es mit make funktioniert, muss noch herausgefunden werden.
Eine Lösung für den gcc Compiler sieht so aus:
gcc -L /opt/AMDAPP/lib/x86_64/ -I /opt/AMDAPP/include/ hellocl.c -lOpenCL