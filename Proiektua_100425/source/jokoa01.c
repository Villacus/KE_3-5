// 2024-2025 ikasturtea

/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		// NDS-rako garatuta dagoen liburutegia
#include <stdio.h>		// C-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		// C-ko liburutegi estandarra memoria erreserbak eta zenbaki bihurketak egiteko
#include <unistd.h>		// Sistema eragileen arteko bateragarritasuna ziurtatzeko liburutegia
// Guk garatutako fitxategiak
	
#include "definizioak.h"
#include "periferikoak.h"
#include "zerbitzuErrutinak.h"
#include "fondoak.h"

int denb; // denbora neurtzen joateko; baloratu ea beharrezkoa den

void jokoa01() {	
	int tekla;
	int temp;
	EGOERA=HASIERA;

	hasieraPantaila();

	TekEtenBaimendu();
	konfiguratuTeklatua(0x40C3);
	DenbEtenBaimendu();
	konfiguratuTenporizadorea(61166, 0x0042);
	ErlojuaMartxanJarri();
	EtenakBaimendu();
	etenZerbErrutEzarri();


	while (1) {
		if (TeklaDetektatu()) {
			tekla = SakatutakoTekla();
			/*
			iprintf("\x1b[16;2HTekla sakatu da. Balioa=%d", tekla);
			iprintf("\x1b[15;2HEgoera=%d", EGOERA);
			*/
			if (EGOERA == GAMEOVER) {
				if (tekla == L) {
					EGOERA = HASIERA;
					hasieraPantaila();
				} else if (tekla == R) {
					EGOERA = BUKAERA;
				}
			}
		}
		if (EGOERA != GAMEOVER && ukimenUkitua()) {
			if (EGOERA == HASIERA) {
				erakutsiBarra1();
				jokoaPantaila();
				EGOERA = BARRA1;
			}
		}
		if (EGOERA == BUKAERA) {
			break;
		}
			
	}
	DenbEtenGalarazi();
	TekEtenGalarazi();
}


void PantailaAldatu() {
	if (EGOERA == BARRA1) {
		erakutsiBarra1();
		// barra1 pantaila erakutsi
	} else if (EGOERA == BARRA2) {
		erakutsiBarra2();
		// barra2 pantaila erakutsi
	} else if (EGOERA == BARRA3) {
		erakutsiBarra3();
		// barra3 pantaila erakutsi
	} else if (EGOERA == BARRA4) {
		erakutsiBarra4();
		// barra4 pantaila erakutsi
	}
}

void hasieraPantaila() {
	consoleClear();
	erakutsihasierapantaila();
	iprintf("\x1b[3;7HROOT BEER TAPPER II");
	iprintf("\x1b[10;2HPantaila ikutu jokoa hasteko");
}
void jokoaPantaila() {
	consoleClear();
	erakutsiBarra1();
	iprintf("\x1b[3;5HROOT BEER TAPPER II");
	iprintf("\x1b[5;2HKONTROLAK:");
	iprintf("\x1b[6;5HGora tekla");
	iprintf("\x1b[7;5HBehera tekla");
	iprintf("\x1b[8;5HA");
	iprintf("\x1b[9;5HB");

}


/***********************2024-2025*******************************/

