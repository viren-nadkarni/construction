#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DELAY 60

int i=0,j=0,k=0;

int groundpoly[]={	0,515,
					0,672,
					1024,672,
					1024,509,
					902,509,
					780,504,		//top right
					720,502,		//bottom right
					542,500,		//middle
					400,506,		//bottom left
					319,514,		//top left
					256,514,
					0,515};

void redraw();
void drawtrees();
void drawwindow(int, int);

void drawwindow(int x, int y)
{
	//450,283
	setcolor(LIGHTGRAY);
	rectangle(450-450+x, 283-283+y, 468-450+x, 304-283+y);
	line(459-450+x, 283-283+y, 459-450+x, 304-283+y);
	line(450-450+x, 290-283+y, 468-450+x, 290-283+y);
}

void redraw()
{
	cleardevice();
	
	//draw ground
	drawpoly(11,groundpoly);		
	setfillstyle(SOLID_FILL,BROWN);
	fillpoly(11,groundpoly);

	//draw tree
	drawtrees();
}

void drawtrees()
{
	setcolor(DARKGRAY);
	
	//trunk
	line(273,513,273,466);
	line(274,513,274,466);
	line(275,513,275,466);
	
	//branches
	line(275,483,285,467);
	line(272,480,264,469);
	
	//leaves
	int treeleaves[]={251,379,
					260,380,
					264,391,
					272,369,
					286,368,
					298,387,
					307,390,
					304,412,
					310,417,
					311,434,
					308,459,
					288,477,
					271,472,
					254,465,
					243,468,
					239,435,
					252,415,
					242,397,
					254,396,
					251,379};
	//setcolor(GREEN);				
	setfillstyle(SOLID_FILL,GREEN);
	fillpoly(20,treeleaves);
	
	setcolor(BLACK);
}

int main(int argc, char *argv[])
{
	initwindow(1024,672,"Construction");
	
	//housekeeping	
	floodfill(1,1,WHITE);
	setbkcolor(WHITE);
	setcolor(BLACK);
	
	redraw();
	
	//start digging foundation
	while(groundpoly[15]<580)
	{
		groundpoly[15]++;

		if(i%2 == 0)
		{
			groundpoly[12]--;
			groundpoly[13]++;
			groundpoly[16]++;
			groundpoly[17]++;
		}
	
		redraw();

		drawtrees();
		
		delay(DELAY/2);
		++i;
	}
	
	while(groundpoly[12]!=780 || groundpoly[13]!=580 || groundpoly[16]!=319 || groundpoly[17]!=580)
	{
		if(groundpoly[12]<780)
			groundpoly[12]++;
			
		if(groundpoly[13]<580)
			groundpoly[13]++;
		
		if(groundpoly[16]>319)
			groundpoly[16]--;
			
		if(groundpoly[17]<580)
			groundpoly[17]++;
		
		redraw();
		delay(DELAY/2);		
	}
	
	
	//fortify foundations
	for(i=0;i<8;++i)
	{
		line(319,580-i,780,580-i);
		delay(DELAY);
	}
	for(i=0;i<6;++i)
	{
		line(319+i,514,319+i,580);
		line(780-i,504,780-i,580);
		delay(DELAY);
	}
	
	//build basement pillars	
	for(i=0;i<25;++i)
	{
		if(i<12)
			line(323+i,549,323+i,580);
		
		putpixel(352,572-i,DARKGRAY);
		putpixel(380,572-i,DARKGRAY);
		putpixel(386,572-i,DARKGRAY);
		
		putpixel(415,572-i,DARKGRAY);
		putpixel(419,572-i,DARKGRAY);
		putpixel(421,572-i,DARKGRAY);
		putpixel(423,572-i,DARKGRAY);
		putpixel(425,572-i,DARKGRAY);
		
		putpixel(441,572-i,DARKGRAY);
		putpixel(442,572-i,DARKGRAY);
		putpixel(443,572-i,DARKGRAY);
		putpixel(444,572-i,DARKGRAY);
		
		delay(DELAY);
	}
	
	//build basement
	for(i=0;i<85;++i)
	{
		if(i<6)
			line(325,549-i,441,549-i);				//basement ceil
			
		if(i<5)
			line(441,549-i,536,575-i);				//staircase
		
		line(613,574-i,624,574-i);					//main pillar
		
		if(i<=36 && i>=30)
			line(624,541-i+30,762,541-i+30);		//right room roof
		
		if(i<13)
			line(755,573-i,762,573-i);				//right door
		
		delay(DELAY/2);
	}


	//theater walls
	for(i=0;i<13;++i)
	{
		if(i<5)
			line(427+i,492,427+i,545);				//theater back wall
			
		if(i<13)									//staircase
		{
			if(i%3==0)
				j+=5;
			line(389+j,543-i,427,543-i);
		}
		
		delay(DELAY);
	}

	//roof of basement
	for(i=0;i<8;++i)
	{
		if(i<6)
		{
			line(418,491-i,761,491-i);			//main floor
			line(325,520-i,378,520-i);			//entrance floor
		}
		
		if(i<8)									//restroom ceiling
		{
			line(655,540+i,684,540+i);
			line(746,540+i,756,540+i);
		}
		
		if(i<8)									//restroom top basement window
			line(755+i,538,755+i,522);
					
		delay(DELAY);	
	}
	
	//darken theatre
	int theatrepoly[]={	429,491,
						429,544,
						450,544,
						554,575,
						615,575,
						615,491,
						429,491};
	setfillstyle(CLOSE_DOT_FILL,BLUE);
	fillpoly(7,theatrepoly);
	
	j=0;
	//staircases
	for(i=0;i<35;++i)
	{
		//main
		if(i%3==0)
			j+=5;
		if(i<30)
			line(365+j,515-i,378+j,515-i);
		
		//back
		if(i<18)
			line(783-j+2,504-i,790-j+2,504-i);	

		delay(DELAY);			
	}
	
	//basement interiors
	for(i=0;i<10;++i)
	{
		//if(i<7)
		//	line(329-i,525,334-i,525);			//under main entrance
		
		//theater ceil
		if(i<7)
		{
			line(479+i,498,479+i,491);
			line(501+i,498,501+i,491);
			line(526+i,498,526+i,491);			
			line(571+i,498,571+i,491);		
			line(594+i,498,594+i,491);			
		}
		delay(DELAY);
	}
	
	//restroom interiors
	setcolor(DARKGRAY);
	for(i=0;i<30;++i)
	{
		putpixel(655,572-i,DARKGRAY);
		putpixel(657,572-i,DARKGRAY);
		putpixel(659,572-i,DARKGRAY);
		
		putpixel(668,572-i,DARKGRAY);
		putpixel(698,572-i,DARKGRAY);
		putpixel(700,572-i,DARKGRAY);

		putpixel(746,572-i,DARKGRAY);
		putpixel(748,572-i,DARKGRAY);
		putpixel(750,572-i,DARKGRAY);
		
		//lower floor
		setcolor(DARKGRAY);
		if(i==28)
		{
			line(700,555,746,555);
			line(700,561,746,561);
			line(700,566,746,566);
			
			line(684,547,745,547);
		}
		
		//upper floor
		if(i==29)
		{
			line(654,493,654,535);
			line(669,493,669,535);

			line(675,506,675,535);
			line(687,506,687,535);
			line(699,506,699,535);
			line(711,506,711,535);
			line(714,506,714,535);
			line(726,506,726,535);
			line(738,506,738,535);

			line(675,506,726,506);
			
			line(700,506,726,535);
			line(726,506,700,535);
		}
		
		delay(DELAY/2);
	}
	
	//restroom ceil repeat
	setcolor(BLACK);
	for(i=0;i<8;++i)
	{
		line(655,540+i,684,540+i);
		line(746,540+i,756,540+i);
	}
	
	//first floor
	//interior pillars
	for(i=0;i<45;++i)
	{
		putpixel(503,484-i,DARKGRAY);
		putpixel(507,484-i,DARKGRAY);
		
		putpixel(527,484-i,DARKGRAY);
		putpixel(531,484-i,DARKGRAY);
		
		putpixel(572,484-i,DARKGRAY);
		putpixel(576,484-i,DARKGRAY);

		putpixel(596,484-i,DARKGRAY);
		putpixel(600,484-i,DARKGRAY);
		
		putpixel(664,484-i,DARKGRAY);
		putpixel(668,484-i,DARKGRAY);
		
		delay(DELAY);
	}
	
	for(i=0;i<13;++i)
	{
		if(i<8)								//PILLAR SUPPORTS
		{
			line(501,437-i,509,437-i);
			line(525,437-i,533,437-i);
			line(570,437-i,578,437-i);		
			line(594,437-i,602,437-i);
			line(662,437-i,670,437-i);
		}
		else								//1st floor ceil
			line(424,430-i+8,761,430-i+8);
				
		delay(DELAY);
	}
	
/*	
	//paint theatre screen
	setcolor(WHITE);
	line(614,755,620,725);
	setcolor(BLACK);
*/	

	//front large step
	setcolor(DARKGRAY);
	line(344,488,416,488);
	line(344,488,344,514);
	
	//pilar
	line(351,488,351,429);
	line(358,488,358,429);
	
	//staircase sidebars
	//front
	line(413,475,374,500);
	line(413,475,413,487);
	line(374,510,374,500);
	line(392,490,392,502);
	//back
	line(760,474,778,488);
	line(760,474,760,484);
	line(778,488,778,498);	
	setcolor(BLACK);
	
	//FRONT ARCH
	int frontarchpoly[]={	363,413,
							356,413,
							356,410,
							351,410,
							351,418,
							319,419,
							319,453,
							325,453,
							325,430,
							363,429,
							363,413};	
	setfillstyle(SOLID_FILL,BLACK);
	setcolor(BLACK);
	fillpoly(11,frontarchpoly);
	int frontarchsupport[]={325,430,
							343,430,
							343,475,
							325,475,
							325,430};
	setfillstyle(SOLID_FILL,WHITE);
	setcolor(LIGHTGRAY);
	fillpoly(5,frontarchsupport);
	setcolor(BLACK);
	
	//first floor
	for(i=0;i<50;++i)
	{
		line(501,425-i,506,425-i);			//pillar left
		line(595,425-i,600,425-i);			//pillar right
		
		if(i<13)
			line(752,425-i,759,425-i);		//right wall -first floor
		
		delay(DELAY);
	}
	
	for(i=0;i<137;++i)
	{
		//fancy pillar
		putpixel(321,417-i,DARKGRAY);
		putpixel(335,417-i,DARKGRAY);
		putpixel(323,417-i,LIGHTGRAY);
		putpixel(326,417-i,LIGHTGRAY);
		putpixel(330,417-i,LIGHTGRAY);
		putpixel(333,417-i,LIGHTGRAY);

		if(i>=43 && i<=47)
			line(352,417-i,759,417-i);			//floor of second floor

		if(i>=95 && i<=99)
			line(352,417-i,696,417-i);			//floor of third floor
			
		delay(DELAY/2);	
	}
	
	for(i=0;i<8;++i)
	{
		line(351+i,358,351+i,376);				//second fl. left wall
		line(351+i,324,351+i,306);				//third fl. left wall

		if(i<4)
		{
			line(754+i,358,754+i,376);			//sec fl. right wall
			line(692+i,307,692+i,327);			//third fl. staircase wall left
		}
		
		line(748+i,322,748+i,306);	

		delay(DELAY);
	}
	
	//third floor support pillars
	for(i=316;i>=280;--i)
	{
		putpixel(430,i,DARKGRAY);		//pillar 1
		putpixel(437,i,DARKGRAY);
		
		putpixel(476,i,DARKGRAY);		//pillar 2
		putpixel(483,i,DARKGRAY);
		
		putpixel(525,i,DARKGRAY);		//pillar 3
		putpixel(532,i,DARKGRAY);
		
		putpixel(569,i,DARKGRAY);		//pillar 4
		putpixel(576,i,DARKGRAY);
		
		putpixel(616,i,DARKGRAY);		//pillar 5
		putpixel(623,i,DARKGRAY);
	
		putpixel(663,i,DARKGRAY);		//pillar 6
		putpixel(670,i,DARKGRAY);
	
		delay(DELAY);
	}
	
	//third floor ceil
	setcolor(BLACK);
	for(i=279;i>=268;--i)
	{
		if(i>274)
		{
			line(429,i,439,i);
			line(475,i,485,i);
			line(524,i,534,i);
			line(568,i,578,i);
			line(615,i,625,i);
			line(662,i,672,i);
		}
		else
		{
			line(351,i,759,i);
		}
		delay(DELAY);
	}
	
	//staircase linking second and third floor
	j=0;
	for(i=369;i>=331;--i)
	{
		if(i%2==0)
			j+=4;
		
		line(642+j,i,654+j,i);
		
		delay(DELAY);
	}
	
	for(i=0;i<7;++i)
		line(718,330+i,752,330+i);
	setcolor(LIGHTGRAY);
	for(i=330;i>=317;--i)
		if(i%2 == 0)
			line(718,i,747,i);
	line(718,330,718,317);
	line(747,330,747,317);
		
	//front fancy pillar top
	int fpillartop[]={	316,230,
						316,237,
						321,237,
						321,253,
						317,253,
						317,259,
						321,259,
						321,281,
						351,281,
						351,285,
						357,285,
						357,271,
						381,271,
						381,256,
						370,256,
						370,261,
						346,261,
						346,230,
						316,230};
	setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	fillpoly(19,fpillartop);
	
	//backrailing
	for(i=728;i<=739;++i)
		line(i,267,i,256);
	for(i=740;i<754;++i)
		line(i,263,i,270);
	for(i=754;i<759;i++)
		line(i,251,i,280);
	
	
	//pent house - whew!!!
	setcolor(BLACK);
	for(i=267;i>=216;--i)
	{
		line(461,i,464,i);			//leftmost
		line(487,i,490,i);			//left
		line(650,i,653,i);			//right
		line(672,i,675,i);			//rightmost
	
		if(i>255 || i<235)
		{
			line(510,i,513,i);		//centre left
			line(597,i,600,i);		//centre right
		}
		
		if(i<223)
		{
			line(371,i,513,i);		//ceil left
			line(597,i,740,i);		//ceil right
		}
				
		delay(DELAY);
	}
	
	//the attic and roof!
	for(i=261;i>=167;--i)
	{
		if(i>203 && i<218)
		{
			line(370,i,383,i);		//left wall
			line(736,i,741,i);		//right wall	
		}
		
		if(i<188 && i >177)
		{
			line(370,i,513,i);		//left roof
			line(597,i,741,i);		//right roof
		}
		
		if(i <178)
		{
			line(440,i,461,i);		//left chimney
			line(650,i,671,i);		//right chimney
		}
		delay(DELAY/2);
	}
	line(370,263,370,185);		//left wall lining
	line(739,267,739,185);		//right wall lining
	line(513,179,513,263);		//left inner wall lining
	line(596,179,596,263);		//right inner wall lining

	line(439,166,462,166);		//left chimney top
	line(439,165,462,165);
	
	line(649,166,672,166);		//right chimney top
	line(649,165,672,165);

		
	//glass
	//horizontal
	line(514,179,596,179);
	setcolor(LIGHTGRAY);
	line(514,204,596,204);
	line(514,234,596,234);
	line(514,256,596,256);
	//vertical
	line(524,267,524,179);	
	line(539,267,539,179);
	line(555,267,555,179);
	line(571,267,571,179);
	line(587,267,587,179);
	
	
	//interior dec
	//sec floor windows 
	drawwindow(449,337);
	delay(DELAY);

	drawwindow(495,337);
	delay(DELAY);

	drawwindow(543,337);
	delay(DELAY);

	drawwindow(589,337);
	delay(DELAY);

	drawwindow(636,337); 
	delay(DELAY);

	//third floor window
	drawwindow(710,283);		//near staircase landing
	delay(DELAY);


	
	while( !kbhit() )
		delay(DELAY);
	
	//system("PAUSE");
		
	return EXIT_SUCCESS;
}
