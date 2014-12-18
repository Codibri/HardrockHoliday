/*
Jona:
Für den Betrieb der Falcon bitte die beiden install dateien
- setup.Falcon.v4.0.28.0_100707.exe
und
- HDAL_SDK_2.1.3_setup.exe
(beide im FalconResources Ordner) in genau dieser Reihenfolge installieren.
Die wichtigen Files liegen in folgenden Ordnern: 
C:\Program Files x86\Novint\HDAL_SDK_2.1.3\lib
und
C:\Program Files x86\Novint\HDAL_SDK_2.1.3\include

Der relative Pfad für die Umgebungsvariabeln zum "NOVINT_DEVICE_SUPPORT" wird mit dem Tool NDSSetter gesetzt.
Der NDSSetter im "HDAL_SDK" Ordner unter "utilities" muss als Admin ausgeführt werden und auf den Ordner
auf den HDAL_SDK-Ordner gesetzt werden.
Wenn ich alle Pfade korrekt gesetzt habe sollte es dann funktionieren.
Infos zum korrekten setzen der Variablen und Directories gibts auch im "HDAL_ProgrammersGuide.pdf" im FalconResources-Ordner
Wenn alles geklappt hat sollten die Headerfiles hdl.h und hdlu.h gefunden werden!
Have Fun!
*/
// Mareike 

#include "Input/Falcon.h"
//#include <hdl/hdl.h>
//#include <hdlu/hdlu.h>

Falcon::Falcon() {
}

Falcon::~Falcon() {
}