#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
int AX;
scanf("%d",&AX);
int BX;
scanf("%d",&BX);
int B;
B=AX;
int A;
A=BX;
int CX;
CX=AX+BX;
scanf("%d",&AX);
int DX;
DX=AX-BX;
printf("%d",DX);
printf("%d",CX);
if(CX==DX){int C;
C=DX;
printf("%d",CX);
}
else{int D;
D=DX;
printf("%d",DX);
}
}