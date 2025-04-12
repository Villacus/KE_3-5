// 2024-2025 ikasturtea

/*-------------------------------------
periferikoak.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definizioak.h"


int tekla; // Sakatutako tekla gordetzeko aldagaia; baloratu ea behar den



int TeklaDetektatu() {
	if ((~TEKLAK_DAT & 0x03ff)!=0) return 1;
	else return 0;
}

int SakatutakoTekla() {
	if ((~TEKLAK_DAT & 0x0001)!=0) return A;
	else if ((~TEKLAK_DAT & 0x0002)!=0) return B;
	else if ((~TEKLAK_DAT & 0x0004)!=0) return SELECT;
	else if ((~TEKLAK_DAT & 0x0008)!=0) return START;
	else if ((~TEKLAK_DAT & 0x0010)!=0) return ESKUBI;
	else if ((~TEKLAK_DAT & 0x0020)!=0) return EZKER;
	else if ((~TEKLAK_DAT & 0x0040)!=0) return GORA;
	else if ((~TEKLAK_DAT & 0x0080)!=0) return BEHERA;
	else if ((~TEKLAK_DAT & 0x0100)!=0) return R;
	else if ((~TEKLAK_DAT & 0x0200)!=0) return L;
}

int ukimenUkitua() {
	touchRead(&PANT_DAT);
	return !(PANT_DAT.px==0 && PANT_DAT.py==0);
}

void konfiguratuTeklatua(int TEK_konf){
	TEKLAK_KNT = TEK_konf;
}

void konfiguratuTenporizadorea(int Latch, int TENP_konf) {
	DENB0_KNT = TENP_konf;
	DENB0_DAT = Latch;
}

void TekEtenBaimendu() {
	IME=0;
	IE |= 0x00001000;
	IME=1;
}

void TekEtenGalarazi() {
	IME=0;
	IE &= 0xFFFEFFFF;	
	IME=1;
}  

void DenbEtenBaimendu() {
	IME=0;
	IE |= 0x00000008;	
	IME=1;
}

void DenbEtenGalarazi() {
	IME=0;
	IE &= 0xFFFFFFF7;
	IME=1;
}

void ErlojuaMartxanJarri() {
	DENB0_KNT |= 0x0080;
}

void ErlojuaGelditu() {
	DENB0_KNT &= 0xFF7F;
}
