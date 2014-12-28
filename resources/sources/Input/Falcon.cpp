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
#include "Input/Constants.h"


Falcon::Falcon() {
	falconManager.init();
}

Falcon::~Falcon() {
}

void Falcon::makeReady() {
	move_To_Origin();
}

float Falcon::getNewPosition(int direction) {
	return falconManager.getNewPosition(direction);
}

bool Falcon::isKeyPressed(Game_Inputs key) {
	return falconManager.isKeyPressed(key);
}

void Falcon::rumble(bool on, float strength) {
	rumbleOn = on;
	rumbleStrength = strength;
}

void Falcon::block(bool on, Direction direction) {

}

void Falcon::move_To_Origin() {
	std::cout << "Moved to Origin" << std::endl;
	double pos[3] = { 0.0, 0.04, 0.0 };
	falconManager.moveToPosition(pos, 0.2);
}

void Falcon::fallDown() {

}

void Falcon::updateBlockAndRumble() {
	falconManager.updateBlocking();
	if (rumbleOn) {
		std::cout << "Rumble" << std::endl;
		//falconManager.rumbleSwitch(rumbleStrength);
	}
	else {
		std::cout << "Rumble nicht" << std::endl;
	}
}