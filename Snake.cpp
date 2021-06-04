#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<fstream.h>
	int p,h,c[50],a,b,x1[50], n=5, x=320, y=200, y1[50],j=1, q,m,sc=-5,hs=0;
	char *hr,*sr,st='p';
void hsc()
	{
ifstream fin("High.txt");
fin.seekg(0);
fin>>hs;
fin.close();
settextstyle(1,0,1);
setcolor(3);
itoa(hs,hr,10);
outtextxy(600,300,hr);
if(sc>hs)
{hs=sc;
ofstream fout ("High.txt");
fout<<hs;
fout.close();
setcolor(0);
outtextxy(600,300,hr);
itoa(hs,hr,10);
setcolor(3);
outtextxy(600,300,hr);
}
}
void cd()
{setcolor(0);
setfillstyle(SOLID_FILL,0);
if(c[n-1])
fillellipse(x1[n-1], y1[n-1],10,5);
else
fillellipse(x1[n-1],y1[n-1],5,10);
}
void er()
{setcolor(0);
setfillstyle(SOLID_FILL,0);
fillellipse(p,h,5,5);
}
void ins()
{line(500,0,500,400);
line(0,400,640,400);
line(500,100,640,100);
setcolor(3);
settextstyle(7,0,1);
outtextxy(10,410,"Credits to Adithya");
outtextxy(135,440,"RA181100010183, SECTION C, CSE");
settextstyle(7,0,4);
outtextxy(510,5,"SNAKE");
outtextxy(510,50,"XENZIA");
settextstyle(11,0,2);
outtextxy(524,110,"Controls");
outtextxy(522,135,"P-Pause");
outtextxy(522,155,"G-Resume");
outtextxy(522,175,"E-EXIT :(");
outtextxy(513,195,"Arrows");
outtextxy(512,205,"-Movement");
outtextxy(524,250,"SCORE-");
outtextxy(524,300,"HIGHSCORE-");
}
void score()
{
itoa(sc,sr,10);
settextstyle(1,0,1);
setcolor(0);
outtextxy(600,240,sr);
sc+=5;
itoa(sc,sr,10);
setcolor(3);
outtextxy(600,240,sr);
}
void crd()
{
p=(rand()%485)+10;
h=(rand()%385)+10;
score();
hsc();
}
void gnr()
{setcolor(3);
setfillstyle(SOLID_FILL,rand()%15+1);
fillellipse(p,h,5,5);
}
int move()
{setcolor(3);
int m=1,z;
x1[0]=x;
y1[0]=y;
while(1)
{cd();
gnr();
ins();
if(m==0)
{c[0]=1;
x1[0]=x1[0]-20;
y=y1[0];
if(x1[0]<0)
x1[0]=490;
}
else if(m==1)
{
c[0]=1;
x1[0]=x1[0]+20;
if(x1[0]>500)
x1[0]=10;
}
else if(m==2)
{
y1[0]=y1[0]+20;
//x=x1[0];
c[0]=0;
if(y1[0]>400)
y1[0]=10;
}
else
{y1[0]=y1[0]-20;
c[0]=0;
if(y1[0]<0)
y1[0]=390;
}
for(int i=n-1;i>0;i--){
x1[i]=x1[i-1];
c[i]=c[i-1];
y1[i]=y1[i-1];
setfillstyle(CLOSE_DOT_FILL, rand()%15+1);
if(c[i])
{
ellipse(x1[i],y1[i],0,360,10,5);
fillellipse(x1[i],y1[i],10,5);
}
else
{
ellipse(x1[i],y1[i],0,360,5,10);
fillellipse(x1[i],y1[i],5,10);
}
}
if(c[0])
ellipse(x1[0], y1[0], 0, 360, 10, 5);
else
ellipse(x1[0], y1[0], 0, 360, 5, 10);
delay(100);
int check();
check();
if((p<=x1[0]+10 && p>=x1[0]-10) && (h<=y1[0]+10 && h>=y1[0]-10))
{
er();
crd();
if(n<50)
++n;
}
if(kbhit())
{z=getch();
switch(z)
{case(72): m=3; j=1;
break;
case(77):m=1; j=1;
break;
case(80):m=2;j=1;
break;
case(75):m=0; j=1;
break;
case('p'):if(!kbhit())
getch();
break;
case('e'):exit(0);
default:break;
}
}
}
}
int check()
{
for(int i=3; i<n; ++i)
if(x1[0]==x1[i] && y1[0]==y1[i])
{while(!kbhit())
{setcolor(4);
settextstyle(EUROPEAN_FONT, HORIZ_DIR,2);
outtextxy(250,200,"GAME OVER");

delay(100);

setcolor(7);
outtextxy(250,200,"GAME OVER!");
delay(100);
}
getch();
exit(0);
} return 0;}
void main(){
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
setbkcolor(0); setcolor(3);
crd();
gnr();
move();
getch();
closegraph();
}