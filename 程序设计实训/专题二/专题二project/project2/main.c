#include <stdio.h>
#include <stdlib.h>
typedef  struct Polynomial *PtrToNode;
struct Polynomial
{
    int coefficient;
    int exponent;
    PtrToNode next;
};
PtrToNode CreateLinkedList(int);
PtrToNode AddPolynomial(PtrToNode, PtrToNode);
PtrToNode SubtractionPolynomial(PtrToNode, PtrToNode);
PtrToNode MultiplicationPolynomial(PtrToNode, PtrToNode);
int Delete(PtrToNode);
void type(PtrToNode);

int main() {
    int Poly_1,Poly_2;
    PtrToNode Fhead,Shead,Addhead,Subt,Mult;
    do{
        printf("请输入第一个多项式的项数:");
        scanf("%d", &Poly_1);
        printf("请输入第二个多项式的项数:");
        scanf("%d", &Poly_2);
    }
    while(Poly_1<=0||Poly_2<=0);
    printf("第一个多项式:\n");
    Fhead = CreateLinkedList(Poly_1);
    printf("第二个多项式:\n");
    Shead = CreateLinkedList(Poly_2);
    printf("多项式相加:\n");
    type(Fhead);
    printf(" + \n");
    type(Shead);
    printf(" = \n");
    Addhead = AddPolynomial(Fhead, Shead);
    type(Addhead);
    Delete(Addhead);
    printf("多项式相减:\n");
    type(Fhead);
    printf(" - \n");
    type(Shead);
    printf(" = \n");
    Subt = SubtractionPolynomial(Fhead, Shead);
    type(Subt);
    Delete(Subt);
    printf("多项式乘法:");
    type(Fhead);
    printf(" * \n");
    type(Shead);
    printf(" = \n");
    Mult = MultiplicationPolynomial(Fhead, Shead);
    type(Mult);
    Delete(Mult);
    Delete(Fhead);
    Delete(Shead);
}

PtrToNode CreateLinkedList(int LinkedListQuantity){
    int i;
    PtrToNode head,p,s;
    p = (PtrToNode)malloc(sizeof(struct Polynomial));
    head = p;
    printf("请输入第1项的系数:");
    scanf("%d", &p->coefficient);
    printf("请输入第1项的次数:");
    scanf("%d", &p->exponent);
    p->next = NULL;
    for(i=1; i<LinkedListQuantity; i++){
        s = (PtrToNode)malloc(sizeof(struct Polynomial));
        printf("请输入第%d项的系数:", i+1);
        scanf("%d", &s->coefficient);
        printf("请输入第%d项的次数:", i+1);
        scanf("%d", &s->exponent);
        p->next = s;
        p = s;
    }
    p->next = NULL;
    return head;
}

PtrToNode AddPolynomial(PtrToNode Fhead, PtrToNode Shead){
    PtrToNode head,f,s,t,p;
    f = Fhead;
    s = Shead;
    if(s==NULL)
        return f;
    if(f==NULL)
        return s;
    t = (PtrToNode)malloc(sizeof(struct Polynomial));
    head = t;
    if(f->exponent>s->exponent){
        t->coefficient = f->coefficient;
        t->exponent = f->exponent;
        f = f->next;
    }
    else if(f->exponent==s->exponent){
        t->coefficient = f->coefficient+s->coefficient;
        t->exponent = f->exponent;
        f = f->next;
        s = s->next;
    }
    else{
        t->coefficient = s->coefficient;
        t->exponent = s->exponent;
        s = s->next;
    }
    t->next = NULL;
    while(f!=NULL&&s!=NULL){
        p = (PtrToNode)malloc(sizeof(struct Polynomial));
        t->next = p;
        if(f->exponent>s->exponent){
            p->coefficient = f->coefficient;
            p->exponent = f->exponent;
            f = f->next;
        }
        else if(f->exponent==s->exponent){
            p->coefficient = f->coefficient+s->coefficient;
            p->exponent = f->exponent;
            f = f->next;
            s = s->next;
        }
        else{
            p->coefficient = s->coefficient;
            p->exponent = s->exponent;
            s = s->next;
        }
        t = p;
    }
    if(f==NULL&&s==NULL)
        t->next = NULL;
    else{
        if(s==NULL)
            s = f;
        while(s!=NULL){
            p = (PtrToNode)malloc(sizeof(struct Polynomial));
            t->next = p;
            p->coefficient = s->coefficient;
            p->exponent = s->exponent;
            s = s->next;
            t = p;
        }
        t->next = NULL;
    }
    return head;
}

PtrToNode SubtractionPolynomial(PtrToNode Fhead, PtrToNode Shead){
    PtrToNode head,p,f,s,t;
    f = Fhead;
    s = Shead;
    p = (PtrToNode)malloc(sizeof(struct Polynomial));
    head = p;
    p->next = NULL;
    if(s->exponent>f->exponent){
        p->coefficient = -s->coefficient;
        p->exponent = s->exponent;
        s = s->next;
    }
    else if(s->exponent==f->exponent){
        p->coefficient = f->coefficient-s->coefficient;
        p->exponent = f->exponent;
        f = f->next;
        s = s->next;
    }
    else{
        p->coefficient = f->coefficient;
        p->exponent = f->exponent;
        f = f->next;
    }
    while(f!=NULL&&s!=NULL){
        t = (PtrToNode)malloc(sizeof(struct Polynomial));
        if(s->exponent>f->exponent){
            t->coefficient = -s->coefficient;
            t->exponent = s->exponent;
            s = s->next;
        }
        else if(s->exponent==f->exponent){
            t->coefficient = f->coefficient-s->coefficient;
            t->exponent = f->exponent;
            f = f->next;
            s = s->next;
        }
        else{
            t->coefficient = f->coefficient;
            t->exponent = f->exponent;
            f = f->next;
        }
        p->next = t;
        p = t;
    }
    if(f==NULL){
        while(s!=NULL){
            t = (PtrToNode)malloc(sizeof(struct Polynomial));
            t->coefficient = -s->coefficient;
            t->exponent = s->exponent;
            s = s->next;
            p->next = t;
            p = t;
        }
    }
    else{
        while(f!=NULL){
            t = (PtrToNode)malloc(sizeof(struct Polynomial));
            t->coefficient = f->coefficient;
            t->exponent = f->exponent;
            f = f->next;
            p->next = t;
            p = t;
        }
    }
    p->next = NULL;
    return head;
}

PtrToNode MultiplicationPolynomial(PtrToNode Fhead, PtrToNode Shead){
    PtrToNode head,f,s,p,t,q,o;
    f = Fhead;
    s = Shead;
    head = NULL;
    while(f!=NULL){
        p = (PtrToNode)malloc(sizeof(struct Polynomial));
        q = p;
        p->coefficient = (f->coefficient)*(s->coefficient);
        p->exponent = f->exponent+s->exponent;
        p->next = NULL;
        s = s->next;
        while(s!=NULL){
            t = (PtrToNode)malloc(sizeof(struct Polynomial));
            t->coefficient = (f->coefficient)*(s->coefficient);
            t->exponent = f->exponent+s->exponent;
            p->next = t;
            p = t;
            s = s->next;
        }
        p->next = NULL;
        o = head;
        head = AddPolynomial(head, q);
        if(head!=q)
        {
            Delete(o);
            Delete(q);
        }
        f = f->next;
        s = Shead;
    }
    return head;
}

void type(PtrToNode head){
    PtrToNode p;
    p = head;
    while(p->next!=NULL){
        printf("%dx^%d + ", p->coefficient, p->exponent);
        p = p->next;
    }
    printf("%dx^%d\n", p->coefficient, p->exponent);
}

int Delete(PtrToNode head){
    PtrToNode p,s;
    p = head;
    if(p==NULL)
        return 0;
    while(p!=NULL){
        s = p->next;
        free(p);
        p = s;
    }
    return 0;
}

