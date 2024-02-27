/*************************************************/
/*
		Author   : Mohamed
		Date     : 12/2/24

*/

#ifndef TFT_INTRFACE_H
#define TFT_INTRFACE_H

void HTFT_voidInit(void);
void HTFTvoidDisplayImage(const u16* Copy_Image);
void HTFTvoidFillColor( u16 Copy_u16Color);
void HTFTvoidDrawRect( u8 x1 ,u8 x2 , u8 y1 ,u8 y2, u16 Copy_u16Color);
#endif
