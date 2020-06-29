
  #include "dos.h"
  void rmode(m)
  int m;
  { union REGS r;
    r.h.ah=0; r.h.al=m; r.x.bx=0;
    int86(16,&r,&r);
    return;
  }

