// 2024-2025 ikasturtea

/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definizioak.h"
#include "periferikoak.h"
#include "fondoak.h"
#include "spriteak.h"

int EGOERA; // Automata zein egoeratan dagoen adierazteko erabilia
int seg3;   // Hiru segundo pasatzen ote diren ikusten joateko
int seg5;
bool konBarra1;
bool konBarra2;
bool konBarra3;
bool konBarra4;

struct perts
{
	int pos;
	bool barra;

};


struct perts bez1 = {0, false};
struct perts bez2 = {0, false};
struct perts bez3 = {0, false};
struct perts bez4 = {0, false};

struct gara
{
	int pos;
	bool barra;
	bool beteta;

};

struct gara gara1 = {0, false, false};
struct gara gara2 = {0, false, false};
struct gara gara3 = {0, false, false};
struct gara gara4 = {0, false, false};


bool konprobatu1 = false;
bool konprobatu2 = false;
bool konprobatu3 = false;
bool konprobatu4 = false;

int max1 = 146;
int max2 = 162;
int max3 = 178;
int max4 = 194;

int bezabiadura = 3;
int garaabiadura = 10;



void tekEten () {
	IME=0;
	if (EGOERA == BARRA1 || EGOERA == BARRA2 || EGOERA == BARRA3 || EGOERA == BARRA4) {
		if (SakatutakoTekla() == GORA && EGOERA != BARRA1) {
			EGOERA --;
			PantailaAldatu();
		}
		if (SakatutakoTekla() == BEHERA && EGOERA != BARRA4) {
			EGOERA ++;
			PantailaAldatu();
		}
		if (SakatutakoTekla() == A) {
			garaBota(BARRA1, &gara1, max1, &konprobatu1);
        	garaBota(BARRA2, &gara2, max2, &konprobatu2);
        	garaBota(BARRA3, &gara3, max3, &konprobatu3);
        	garaBota(BARRA4, &gara4, max4, &konprobatu4);
		}
		if (SakatutakoTekla() == B) {
			garaBete(BARRA1, &bez1, &gara1, max1, &konprobatu1, 28, 1);
			garaBete(BARRA2, &bez2, &gara2, max2, &konprobatu2, 66, 2);
			garaBete(BARRA3, &bez3, &gara3, max3, &konprobatu3, 104, 3);
			garaBete(BARRA4, &bez4, &gara4, max4, &konprobatu4, 143, 4);
		} else {
			iprintf("\x1b[8;2HEz dago inor Barra honetan");
		}

	}
	IME=1;
}

void tenpEten() {

	IME=0;
	static int tik=0;
	static int seg=0;

	if (EGOERA == BARRA1 || EGOERA == BARRA2 || EGOERA == BARRA3 || EGOERA == BARRA4) {
		tik++; 
		if (tik==30) {
			seg++;
			iprintf("\x1b[22;2H                        ");
			iprintf("\x1b[22;2HPasa diren segunduak=%d", seg);
			tik=0;
			seg5++;
			if (seg5==2) {
				seg5=0;
				//5 segundura bezeroa gehitu
                switch (rand() % 4) {
                    case 0:
                        bezeroaGehitu(&bez1, 70);
                        break;
                    case 1:
                        bezeroaGehitu(&bez2, 54);
                        break;
                    case 2:
                        bezeroaGehitu(&bez3, 38);
                        break;
                    case 3:
                        bezeroaGehitu(&bez4, 22);
                        break;
                }
			}
		}
		if (tik % 5 == 0) {
			//Segunduro bezeroa mugitu
			bezeroaMugitu(&bez1, max1, 5, 28);
			bezeroaMugitu(&bez2, max2, 6, 66);
			bezeroaMugitu(&bez3, max3, 7, 104);
			bezeroaMugitu(&bez4, max4, 8, 143);
			
			//Konprobatu ea bezeroa eta garagardoa posizio beran dauden, ez badaude garagardoa mugitu
			desagertzekoKonprobapena(&bez1, &gara1, &konprobatu1, 1, 28);
    		desagertzekoKonprobapena(&bez2, &gara2, &konprobatu2, 2, 66);
    		desagertzekoKonprobapena(&bez3, &gara3, &konprobatu3, 3, 104);
    		desagertzekoKonprobapena(&bez4, &gara4, &konprobatu4, 4, 143);
			
		}
	}

    if (EGOERA == GAMEOVER) {
        reseteatuJokoa();
		consoleClear();
		iprintf("\x1b[11;2HGame Over");
		iprintf("\x1b[12;2HTekla sakatu L hasierarako edo R bukatzeko");
    }

	IME=1;
}

void garaBota(int barra_egoera, struct gara *gara, int max_pos, bool *konprobatu) {
    if (EGOERA == barra_egoera && gara->beteta) {
        *konprobatu = true;
        gara->pos = max_pos;
        gara->barra = true;
        gara->beteta = false;
        PantailaAldatu();
    }
}

void garaBete(int barra_egoera, struct perts *bez, struct gara *gara, int max_pos, bool *konprobatu, int y_ard, int sprite_zbk) {
    if (EGOERA == barra_egoera && bez->barra && !*konprobatu) {
        gara->beteta = true;
        gara->pos = max_pos;
        ErakutsiErronboa(sprite_zbk, gara->pos, y_ard); //garagardoa erakutsi
        iprintf("\x1b[8;2HBarra%d garagardoa prest", sprite_zbk);
    }
}

void bezeroaGehitu(struct perts *bez, int hasiera_pos) {
    if (!bez->barra) {
        bez->barra = true;
        bez->pos = hasiera_pos;
    }
}

void bezeroaMugitu(struct perts *bez, int max_pos, int sprite_zbk, int y_ard) {
    if (bez->barra) {
        if (bez->pos < max_pos) {
            bez->pos += bezabiadura;
            ErakutsiErronboa(sprite_zbk, bez->pos, y_ard); //bezeroa erakutsi
        } else {
            EGOERA = GAMEOVER;
        }
    }
}

void desagertzekoKonprobapena(struct perts *bez, struct gara *gara, bool *konprobatu, int sprite_zbk, int kokapena) {
    if (*konprobatu) {
        if (bez->pos >= gara->pos) {
            bez->barra = false;
            gara->barra = false;
            EzabatuErronboa(sprite_zbk, gara->pos, kokapena); //garagardoa ezabatu
            EzabatuErronboa(sprite_zbk + 4, bez->pos, kokapena); //bezeroa ezabatu
            *konprobatu = false;
        } else {
            gara->pos -= garaabiadura;
            ErakutsiErronboa(sprite_zbk, gara->pos, kokapena); //garagardoa erakutsi
        }
    }
}

void reseteatuJokoa() {
    if (gara1.barra) EzabatuErronboa(1, gara1.pos, 28); //garagardoa ezabatu
    if (gara2.barra) EzabatuErronboa(2, gara2.pos, 66); //garagardoa ezabatu
    if (gara3.barra) EzabatuErronboa(3, gara3.pos, 104); //garagardoa ezabatu
    if (gara4.barra) EzabatuErronboa(4, gara4.pos, 143); //garagardoa ezabatu

	if (bez1.barra) EzabatuErronboa(5, bez1.pos, 28); //bezeroa ezabatu
    if (bez2.barra) EzabatuErronboa(6, bez2.pos, 66); //bezeroa ezabatu
    if (bez3.barra) EzabatuErronboa(7, bez3.pos, 104); //bezeroa ezabatu
    if (bez4.barra) EzabatuErronboa(8, bez4.pos, 143); //bezeroa ezabatu


    bez1.pos = 0;
    bez1.barra = false;

    bez2.pos = 0;
    bez2.barra = false;

    bez3.pos = 0;
    bez3.barra = false;

    bez4.pos = 0;
    bez4.barra = false;

    gara1.pos = 0;
    gara1.barra = false;
    gara1.beteta = false;

    gara2.pos = 0;
    gara2.barra = false;
    gara2.beteta = false;

    gara3.pos = 0;
    gara3.barra = false;
    gara3.beteta = false;

    gara4.pos = 0;
    gara4.barra = false;
    gara4.beteta = false;

    konprobatu1 = false;
    konprobatu2 = false;
    konprobatu3 = false;
    konprobatu4 = false;
}

void etenZerbErrutEzarri() {	
	irqSet(IRQ_TIMER0, tenpEten);
	irqSet(IRQ_KEYS, tekEten);
}
