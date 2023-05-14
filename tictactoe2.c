#include<stdio.h>
#include<conio.h>
#include<string.h>
int mark(int,char);
void view(int);
void scrchk(char, char);
int chkrslt(int, int);
void adder(char);
int n,scr1,scr2,pi,pl,agn,rst;
char s,s1,s2,a[3][3];

int main()
{
	int plyr,ch;
	
	gameplay:
		pi=1;
		memset(a, '\0', sizeof(a));
		scr1=0,scr2=0;
		playerchoice:
			printf("\n Enter starter player# \n( enter '1' or '2' ) :  ");
			scanf("%d",&plyr);
		pl=plyr;
		if(plyr!=1 && plyr!=2)
		{
			printf("\n Player-no. choice is invalid !! please try again...\n\n New Game...\n\n");
			goto playerchoice;
		}
		else
		{
			signchoice:
				printf("\n Enter sign-choice for player %d ,\n( enter '1-> X' or '2-> O' or'3-> x' or'4-> o' ) :  ",plyr);
				scanf("%d",&ch);
			if(ch!=1 && ch!=2 && ch!=3 && ch!=4)
			{
				printf("\n Sign-choice is invalid !! please try again...\n\n New Game...\n\n");
				goto signchoice;
			}
			else
			{
				if(ch==1 && plyr==1 || ch==2 && plyr==2)
					s1='X',s2='O';
				else if(ch==2 && plyr==1 || ch==1 && plyr==2)
					s1='O',s2='X';
				else if(ch==3 && plyr==1 || ch==4 && plyr==2)
					s1='x',s2='o';
				else if(ch==4 && plyr==1 || ch==3 && plyr==2)
					s1='o',s2='x';
					
				printf("\n Game Starts....");
				do
				{
					printf("\n  1  |  2  |  3  \n  4  |  5  |  6  \n  7  |  8  |  9  \n");
					printf("\n player# %d enter position choice to make move-no. %d: ",pl,pi);
					scanf("%d",&n);
					if(pl==1)
						s=s1;
					else
						s=s2;
					mark(n,s);
					view(pi);
					
					pi++;
					if(pl%2==1)
						pl=2;
					else
						pl=1;
				}while(pi<10);
				scrchk(s1,s2);
				chkrslt(scr1,scr2);
				
				printf("\n\n Do you wanna play another game ? Press 0 to play...");
				scanf("%d",&agn);
				if(agn==0)
				{
					printf("\n\n~~~~~~~~~~~~~~~~~~~~~~~<New Game>~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
					goto gameplay;
					
				}
				else
				{
					printf("\n\n Thanks for playing...");
					getch();
				}
			}
		}
}

int mark(int n, char s)
{
	int i,j,k;
	if(n<0 || n>10)
	{
		printf("\n Invalid position no. enetered.. Input Again !!!\n");
		pi--;
		if(pl%2==0)
			pl=1;
		else
			pl=2;
		return;
	}
	else
	{
		if(n>0 && n<4)
			i=0,k=1;
		else if(n>3 && n<7)
			i=1,k=3;
		else if(n>6 && n<10)
			i=2,k=5;

	for(j=0;j<3;j++)
	{
		if(n==(i+j+k))
			if(a[i][j]!='\0')
			{
				printf("\n Position %d is already marked with %c.. Don't Cheat !!",n,a[i][j]);
				pi--;
				if(pl%2==0)
					pl=1;
				else
					pl=2;
				break;
			}
			else
				a[i][j]=s;
	}
	}
}

void view(int pi)
{
	int l,m;
	printf("\n ~~~ CheckBoard is looking like after move no. %d ~~~\n\n",pi);
	for(l=0;l<3;l++)
	{
		for(m=0;m<3;m++)
		{
			if(a[l][m]!='\0')
				printf(" %c ",a[l][m]);
			else
				printf(" ! ");
			
			if(m!=2)
				printf(" | ");
		}
		printf("\n");
	}
}

void scrchk(char s1, char s2)
{
	int x,y;
	char sgn;
	for(x=0;x<3;x++)
		for(y=0;y<3;y++)
		{
			sgn=a[x][y];
			if(sgn!='\0')
			{
				if(x==0 && y==0)
				{
				if(sgn==a[1][1] && sgn==a[2][2])//1
					adder(sgn);
				else if(sgn==a[0][1] && sgn==a[0][2])//2
					adder(sgn);
				else if(sgn==a[1][0] && sgn==a[2][0])//3					
					adder(sgn);
				}
				
				if(x==0 && y==1)
					if(sgn==a[1][1] && sgn==a[2][1])//4					
						adder(sgn);
				
				if(x==0 && y==2)
				{
					if(sgn==a[1][1] && sgn==a[2][0])//5
						adder(sgn);
					else if(sgn==a[1][2] &&sgn==a[2][2])//6				
						adder(sgn);
				}
				
				if(x==1 && y==0)
					if(sgn==a[1][1] && sgn==a[1][2])//7
						adder(sgn);
				
				if(x==2 && y==0)
					if(sgn==a[2][1] && sgn==a[2][2])//8
						adder(sgn);
			}
		}	
	printf("\n\t <->-<->-<->-<->-<->-<->-<->-<->\n\t  Present Scores of the Game are...... ");
	printf("\n\t  Score of player#1 is : %d pts\n\t Score of player#2 is : %d pts ",scr1,scr2);
}

void adder(char sgn)
{
	if(s1==sgn)
		scr1++;
	else
		scr2++;
}

int chkrslt(int scr1, int scr2)
{	
	printf("\n\t <->-<->-<->-<->-<->-<->-<->-<->\n\t  Final Results of the Game are:");
	if(scr1>scr2)
		printf("\n\t  Winner is Player-#1 with points %d",scr1);
	else if(scr2>scr1)
		printf("\n\t  Winner is Player-#2 with points %d",scr2);
	else
		printf("\n\t  This Game is a TIE between player-#1 & #2");
	printf("\n\n\t <->-<->-<->-<->-<->-<->-<->-<->\n\n");
}
