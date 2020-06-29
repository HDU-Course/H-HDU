
  #include "stdio.h"
  #include "dos.h"
  void tasci(fn)
  char *fn;
  { FILE *fp;
    union REGS r;
    int i,j,row,col;
    unsigned char c,p[16];
    long int ix,k;
    unsigned char far *ptr=
          (unsigned char far *)0xa0000000;
    if ((fp=fopen(fn,"w+b"))==NULL)
      { printf("cannot open fn !\n");
        exit(0);
      }
    r.h.ah=0; r.h.al=16; int86(16,&r,&r);
    outportb(0x03CE,5); outportb(0x03CF,0);
    row=10; col=0;
    for (i=0; i<=130; i++)
      { c=(unsigned char)i;
        if (i==65) { row=row+2; col=0;}
        if ((i<=32)||(i>=127)) c=(unsigned char)32;
        r.h.ah=2; r.h.dh=row; r.h.dl=col;
        r.h.bh=0; int86(16,&r,&r); col=col+1;
        putchar(c);
      }
    row=139; col=0;
    for (i=0; i<=129; i++)
      { if (i==65) {row=row+28; col=0;}
        for (j=0; j<=15; j++)
          { ix=(long)(row+j)*80L+(long)(col/8);
            outportb(0x03CE,4); outportb(0x03CF,0);
            p[j]=*(ptr+ix);
          }
        col=col+8; k=(long)i*16L;
        fseek(fp,k*sizeof(char),SEEK_SET);
        fwrite(p,sizeof(char),16,fp);
      }
    outportb(0x03CE,5); outportb(0x03CF,0);
    r.h.ah=0; r.h.al=3; int86(16,&r,&r);
    fclose(fp); return;
  }

