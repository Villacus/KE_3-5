// 2024-2025 ikasturtea

extern u16* gfx;
extern u16* gfx2;
extern u16* gfx3;
extern u16* gfxSub;

extern void memoriaErreserbatu();

extern void PaletaNagusiaEzarri();
/* Pixel bakoitzak har ditzakeen 256 balioetako bakoitzari kolore bat esleitu pantaila nagusian. 0 balioa gardena da 
   eta definitu gabeko balioak beltzak. */

extern void BigarrenPaletaEzarri();
/* Pixel bakoitzak har ditzakeen 256 balioetako bakoitzari kolore bat esleitu bigarren pantailan. 0 balioa 
   gardena da eta definitu gabeko balioak beltzak. */

extern void SpriteakMemorianGorde();
/* Irudikatutako Spriteak memorian kargatzen ditu.*/


extern void ErakutsiErronboa(int indizea, int x, int y);
/* Funtzio honek erronbo bat irudikatzen du pantailako x, y posizioan. Pantailan ateratzea nahi den erronbo 
   bakoitzari indize desberdin bat esleitu behar zaio, 0 eta 126 balioen arteko indizea izan daiteke. */

extern void EzabatuErronboa(int indizea, int x, int y);
/* Funtzio honek erronbo baten indizea pasata pantailatik ezabatzen du */

extern void ErakutsiErronboHandia(int indizea, int x, int y);
/* Funtzio honek erronbo handi bat irudikatzen du pantailako x, y posizioan. Pantailan ateratzea nahi den erronbo 
   bakoitzari indize desberdin bat esleitu behar zaio, 0 eta 126 balioen arteko indizea izan daiteke. */

extern void EzabatuErronboHandia(int indizea, int x, int y);
/* Funtzio honek erronbo handi baten indizea pasata pantailatik ezabatzen du */


/***********************2024-2025*******************************/

