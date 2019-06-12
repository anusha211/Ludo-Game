#include<dos.h>
#include<math.h>
#include<string.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void lines(int,int,int,int,int);
void circles(int,int,int,int);
void player1(int,int,int h[4][4],int k[4][4]);
void player2(int,int,int h[4][4],int k[4][4]);
void player3(int,int,int h[4][4],int k[4][4]);
void player4(int,int,int h[4][4],int k[4][4]);
void board();
void mainmenu();
void arotation(float a[3][9],int j);
void drawcube(float a[3][9]);

int main(void)
{
    int i,j,m,t,n,z;
    float a[3][9];
    char ch;
    static int h[4][4],k[4][4];
   int gdriver = DETECT, gmode, errorcode;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "c://turboc3//bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

  mainmenu();

 board();

 h[0][0]=420; h[1][0]=465;      h[2][0]=230;       h[3][0]=180;
 h[0][1]=460; h[1][1]= 515;     h[2][1]=270;       h[3][1]=230;
 h[0][2]=420; h[1][2]=465;      h[2][2]=230;       h[3][2]=180;
 h[0][3]=460; h[1][3]=515;      h[2][3]=270;       h[3][3]=230;
 k[0][0]=50;  k[1][0]= 290;     k[2][0]=330;       k[3][0]=110;
 k[0][1]=50;  k[1][1]= 290;     k[2][1]=330;       k[3][1]=110;
 k[0][2]=90;  k[1][2]= 340;     k[2][2]=380;       k[3][2]=150;
 k[0][3]=90;  k[1][3]= 340;     k[2][3]=380;       k[3][3]=150;
 for(i=0;i<4;i++)
 { circles(h[0][i],k[0][i],10,4);
   circles(h[1][i],k[1][i],10,14);
   circles(h[2][i],k[2][i],10,2);
   circles(h[3][i],k[3][i],10,1);
 }

     a[0][0]=10;
     a[0][1]= 10;
     a[0][2]= 50;
     a[0][3]= 50;
     a[0][4]= 10;
     a[0][5]= 10;
     a[0][6]= 50;
     a[0][7]= 50;
     a[0][8]= 10;
     a[1][0]= 40;
     a[1][1]= 80;
     a[1][2]= 80;
     a[1][3]= 40;
     a[1][4]= 40;
     a[1][5]= 40;
     a[1][6]= 40;
     a[1][7]= 80;
     a[1][8]= 80;
      a[2][0]= 0;
     a[2][1]= 0;
     a[2][2]= 0;
     a[2][3]= 0;
     a[2][4]= 0;
     a[2][5]= 20;
     a[2][6]= 20;
     a[2][7]= 20;
     a[2][8]= 20;

    drawcube(a);
   gotoxy(1,1);
   printf("red's turn:");
 for(z=1;z>0;z++)
 {
 for(m=1;m<5;m++)
 {
   while(!kbhit())
   { ch=getch();
     if(ch=='d')
      break;
      else if(ch=='e')
      goto end;
   }
   {
    for(j=1;j<360;j++)
    {
    arotation(a,j);
    delay(10);
    cleardevice();
    }
   }
    drawcube(a);
    board();
  for(i=0;i<4;i++)
 { circles(h[0][i],k[0][i],10,4);
   circles(h[1][i],k[1][i],10,14);
   circles(h[2][i],k[2][i],10,2);
   circles(h[3][i],k[3][i],10,1);
  }
 gotoxy(6,5);
 n=random(6)+1;
 printf("%d",n);

  scanf("%d",&t);
 if(m==1)
 {
   player1(t,n,h,k);
   cleardevice();
   gotoxy(1,1);
   printf("yellow's turn:");
 }

  if(m==2)
 {
   player2(t,n,h,k);
   cleardevice();
   gotoxy(1,1);
   printf("green's turn:");
 }

  if(m==3)
 {
   player3(t,n,h,k);
   cleardevice();
   gotoxy(1,1);
   printf("blue's turn:");
 }

  if(m==4)
 {
   player4(t,n,h,k);
   cleardevice();
   gotoxy(1,1);
   printf("red's turn:");
 }

   board();
    for(i=0;i<4;i++)
 { circles(h[0][i],k[0][i],10,4);
  circles(h[1][i],k[1][i],10,14);
  circles(h[2][i],k[2][i],10,2);
  circles(h[3][i],k[3][i],10,1);
 }
 drawcube(a);
 gotoxy(6,5);
 printf("%d",n);

}
}
end: return 0;
}


void player1(int t,int n,int h[4][4], int k[4][4])
{

 if(n==1&&(h[0][t-1]==420||460)&&(k[0][t-1]==50||90))
 {
  h[0][t-1]=375;
  k[0][t-1]=65;
 }

 else if(k[0][t-1]==65)
 {
  if(n<4)
  {
  k[0][t-1]= k[0][t-1]+ n*30;
  }
  else if(n>=4)
  {
   k[0][t-1]= k[0][t-1] + 4*30;
   h[0][t-1]= h[0][t-1]+(n-3)*30;
  }
 }

  else if(k[0][t-1]==95)
 {
  if(n<3)
  {
  k[0][t-1]= k[0][t-1]+ n*30;
  }
  else if(n>=3)
  {
   k[0][t-1]= k[0][t-1] + 3*30;
   h[0][t-1]= h[0][t-1]+(n-2)*30;
  }
 }
  else if(k[0][t-1]==125)
 {
  if(n<2)
  {
  k[0][t-1]= k[0][t-1]+ n*30;
  }
  else if(n>=2)
  {
   k[0][t-1]= k[0][t-1] + 2*30;
   h[0][t-1]= h[0][t-1]+(n-3)*30;
  }
 }
  else if(k[0][t-1]==155)
 {
  k[0][t-1]= k[0][t-1]+30;
  h[0][t-1]=h[0][t-1]+30*n;
 }

}


void player2(int t,int n,int h[4][4], int k[4][4])
{
 if(n==1&&(h[1][t-1]==465||515)&&(k[1][t-1]==290||340))
 {
  h[1][t-1]=495;
  k[1][t-1]=245;
 }
else if( h[1][t-1]==495)
 {
  if(n<4)
  {
    h[1][t-1]=h[1][t-1]-n*30;
  }
  else
  { h[1][t-1]=h[1][t-1]-4*30;
    k[1][t-1]=k[1][t-1]+(n-3)*30;
  }
  }
 else if( h[1][t-1]==465)
 {
  if(n<3)
  {
    h[1][t-1]=h[1][t-1]-n*30;
  }
  else
  { h[1][t-1]=h[1][t-1]-3*30;
    k[1][t-1]=k[1][t-1]+(n-2)*30;
  }
  }
else if( h[1][t-1]==435)
 {
  if(n<2)
  {
    h[1][t-1]=h[1][t-1]-n*30;
  }
  else
  { h[1][t-1]=h[1][t-1]-2*30;
    k[1][t-1]=k[1][t-1]+(n-1)*30;
  }
  }
 else if( h[1][t-1]==405)
 {
  h[1][t-1]=h[1][t-1]-30;
  k[1][t-1]=k[1][t-1]+n*30;
  }
}

void player3(int t,int n,int h[4][4], int k[4][4])
{
 if(n==1&&(h[2][t-1]==230||270)&&(k[2][t-1]==330||380))
 {
  h[2][t-1]=315;
  k[2][t-1]=395;
 }
}

void player4(int t,int n,int h[4][4], int k[4][4])
{
 if(n==1&&(h[3][t-1]==180||230)&&(k[3][t-1]==110||150))
 {
  h[3][t-1]=195;
  k[3][t-1]=185;
 }
}

void board()
{ int i,j;

 for(j=50;j<170;j++)
 {
 for(i=330;i<360;i++)
 {
  putpixel(i,j,RED);
 }
 }

  for(j=200;j<230;j++)
 {
 for(i=390;i<510;i++)
 {
  putpixel(i,j,YELLOW);
 }
 }
   for(j=260;j<380;j++)
 {
 for(i=330;i<360;i++)
 {
  putpixel(i,j,GREEN);
 }
 }
  for(j=200;j<230;j++)
 {
 for(i=180;i<300;i++)
 {
  putpixel(i,j,BLUE);
 }
 }
  lines(300,20,390,170,1);
   lines(300,260,390,410,1);
    lines(150,170,300,260,2);
     lines(390,170,540,260,2);
     rectangle(390,20,490,120);
     rectangle(200,300,300,410);
     rectangle(440,260,540,370);
     rectangle(150,80,260,170);
}

void circles(int h,int k, int r,int c)
{
   setfillstyle(1,c);
  fillellipse(h,k,r,r);

}


void lines(int x1,int y1,int x2,int y2,int t)
{ int i,j;
  if( t==1)
  {
  for(i=0;i<6;i++)
  { line(x1,y1+30*i,x2,y1+30*i);
  }
  for(j=0;j<4;j++)
  {
  line(x1+30*j,y1,x1+30*j,y2);
  }
 }
 else
 {
   for(i=0;i<4;i++)
  { line(x1,y1+30*i,x2,y1+30*i);
  }
  for(j=0;j<6;j++)
  {
 line(x1+30*j,y1,x1+30*j,y2);
  }
 }
}


void drawcube(float a[3][9])
{
 int i; float c[3][9];
 for(i=0;i<9;i++)
 { c[0][i]=a[0][i];
   c[1][i]=a[1][i];
   c[2][i]=a[2][i];
 }
  for(i=0;i<9;i++)
 { c[0][i]=c[0][i]+c[2][i];
   c[1][i]=c[1][i]+c[2][i];
   }

  for(i=0;i<8;i++)
 {
    line(c[0][i],c[1][i],c[0][i+1],c[1][i+1]);
 }
 line(c[0][8],c[1][8],c[0][5], c[1][5]);
 line(c[0][1],c[1][1],c[0][8], c[1][8]);
 line(c[0][2],c[1][2],c[0][7], c[1][7]);
 line(c[0][3],c[1][3],c[0][6], c[1][6]);
 }


 void arotation(float a[3][9],int j)
 {
  int i;  float b[3][9],c[3][9];
    for(i=0;i<9;i++)
     { c[0][i]=a[0][i];
       c[1][i]=a[1][i];
       c[2][i]=a[2][i];
     }

  for(i=0;i<9;i++)
  { c[0][i]=c[0][i]-30;
    c[1][i]=c[1][i]-60;
    c[2][i]=c[2][i]-10;
  }
   for(i=0;i<9;i++)
  {
    b[0][i]=(c[0][i]*cos(j*3.1415/180))-(c[1][i]*sin(j*3.1415/180));
    b[1][i]=(c[0][i]*sin(j*3.1415/180))+(c[1][i]*cos(j*3.1415/180));
    b[2][i]=c[2][i];
  }

  for(i=0;i<9;i++)
  { b[0][i]=b[0][i]+30;
    b[1][i]=b[1][i]+60;
    b[2][i]=b[2][i]+10;
  }
  drawcube(b);
}

void mainmenu()
{ char ch;
  int i,j;
/*for(i=1;i<getmaxx()/2;i++)
{
  for(j=1;j<getmaxy()/2;j++)
  {
   putpixel(i,j,BLUE);
  }
}
for(i=1;i<getmaxx()/2;i++)
{
  for(j=getmaxy()/2;j<getmaxy();j++)
  {
   putpixel(i,j,GREEN);
  }
}
for(i=getmaxx()/2;i<getmaxx();i++)
{
  for(j=1;j<getmaxy()/2;j++)
  {
   putpixel(i,j,RED);
  }
}
for(i=getmaxx()/2;i<getmaxx();i++)
{
  for(j=getmaxy()/2;j<getmaxy();j++)
  {
   putpixel(i,j,YELLOW);
  }
}*/
gotoxy(35,8);
printf("LUDO GAME\n");
gotoxy(30,11);
printf("*************");
gotoxy(10,20);
printf("INSTRUCTIONS:\n\n");
printf("1. press 'p' to play the game.\n");
printf("2. press 'd' to roll the dice.\n");
printf("3. each time select the circle that u want to move.\n");
printf("4. press 'e' to end the game.");
 while(!kbhit())
   { ch=getch();
     if(ch=='p')
      break;
   }
 cleardevice();
 }