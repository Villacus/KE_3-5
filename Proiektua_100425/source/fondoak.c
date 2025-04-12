// 2024-2025 ikasturtea

/*---------------------------------------------------------------------------------
Kode hau garatu da dovotoren "Simple sprite demo" adibidean eta Jaeden Ameronen beste
adibide batean oinarrituta.
---------------------------------------------------------------------------------*/

#include <nds.h> 		// NDS-rako garatuta dagoen liburutegia
#include <stdio.h>		// C-ko liburutegi estandarra sarrera eta irteerako funtzioak definitzen dituena
#include <stdlib.h>		// C-ko liburutegi estandarra memoria erreserbak eta zenbaki bihurketak egiteko
#include <unistd.h>		// Sistema eragileen arteko bateragarritasuna ziurtatzeko liburutegia

/* Fondo desberdinak erakutsi nahi izango baditugu, hemen fondo bakoitzaren burukoa (.h fitxategia) gehitu behar da. Buruko horiek
automatikoki sortzen dira, konpilatzerako garaian, baina horretarako gogoratu behar da */

#include "fondoak.h"
#include "grafikoak.h"
#include "Atea.h"
#include "AteaIrekita.h"
#include "Barra1.h"
#include "Barra2.h"
#include "Barra3.h"
#include "Barra4.h"
#include "gameover.h"
#include "hasierapantaila.h"
#include "pausapantaila.h"

/* Irudiak memorian kopiatzeko DMA kanala aukeratu (3.a) */
static const int DMA_CHANNEL = 3;

/* Pantailaratu nahi den grafiko bakoitzerako horrelako prozedura bat idatzi behar da */


void erakutsiBarra1() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Barra1Bitmap, // Automatikoki sortzen den aldagaia
                     (uint16 *)BG_BMP_RAM(0), // Fondo nagusiaren helbidea
                     Barra1BitmapLen); // Luzera (bytetan); automatikoki sortzen den aldagaia
}
void erakutsiBarra2() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Barra2Bitmap, // Automatikoki sortzen den aldagaia
                     (uint16 *)BG_BMP_RAM(0), // Fondo nagusiaren helbidea
                     Barra2BitmapLen); // Luzera (bytetan); automatikoki sortzen den aldagaia
}
void erakutsiBarra3() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Barra3Bitmap, // Automatikoki sortzen den aldagaia
                     (uint16 *)BG_BMP_RAM(0), // Fondo nagusiaren helbidea
                     Barra3BitmapLen); // Luzera (bytetan); automatikoki sortzen den aldagaia
}
void erakutsiBarra4() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     Barra4Bitmap, // Automatikoki sortzen den aldagaia
                     (uint16 *)BG_BMP_RAM(0), // Fondo nagusiaren helbidea
                     Barra4BitmapLen); // Luzera (bytetan); automatikoki sortzen den aldagaia
}
void erakutsihasierapantaila() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     hasierapantailaBitmap, // Automatikoki sortzen den aldagaia
                     (uint16 *)BG_BMP_RAM(0), // Fondo nagusiaren helbidea
                     hasierapantailaBitmapLen); // Luzera (bytetan); automatikoki sortzen den aldagaia
}
void erakutsipausapantaila() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     pausapantailaBitmap, // Automatikoki sortzen den aldagaia
                     (uint16 *)BG_BMP_RAM(0), // Fondo nagusiaren helbidea
                     pausapantailaBitmapLen); // Luzera (bytetan); automatikoki sortzen den aldagaia
}

void erakutsigameover() {
    dmaCopyHalfWords(DMA_CHANNEL,
                     gameoverBitmap, // Automatikoki sortzen den aldagaia
                     (uint16 *)BG_BMP_RAM(0), // Fondo nagusiaren helbidea
                     gameoverBitmapLen); // Luzera (bytetan); automatikoki sortzen den aldagaia
}



/***********************2024-2025*******************************/

