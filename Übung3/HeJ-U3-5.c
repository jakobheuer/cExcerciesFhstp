// Jakob Heigl-Auer, Uebung 3 - Aufgabe 5
// HeJ-U3-5.c

// Includes
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    char a;
    int8_t b;
    unsigned char c;
    uint8_t d;
    short e;
    int16_t f;
    uint16_t g;
    int h;
    unsigned i;
    long j;
    unsigned long k;
    int32_t l;
    uint32_t m;
    long long n;
    int64_t o;
    unsigned long long p;
    uint64_t q;
    float r;
    double s;
    long double t;
    _Bool u;

    printf("Type             |   Bytes\n");
    printf("-----------------------------------------\n");
    printf("Char %*d Bytes\n",15,(int) sizeof(a));
    printf("int8_t %*d Bytes\n",13,(int) sizeof(b));
    printf("unsigned char %*d Bytes\n",6,(int) sizeof(c));
    printf("uint8_t %*d Bytes\n",12,(int) sizeof(d));
    printf("short %*d Bytes\n",14,(int) sizeof(e));
    printf("int16_t %*d Bytes\n",12,(int) sizeof(f));
    printf("uint16t %*d Bytes\n",12,(int) sizeof(g));
    printf("int %*d Bytes\n",16,(int) sizeof(h));
    printf("unsigned %*d Bytes\n",11,(int) sizeof(i));
    printf("long %*d Bytes\n",15,(int) sizeof(j));
    printf("unsigned long %*d Bytes\n",6,(int) sizeof(k));
    printf("int32_t %*d Bytes\n",12,(int) sizeof(l));
    printf("uint32_t %*d Bytes\n",11,(int) sizeof(m));
    printf("long long %*d Bytes\n",10,(int) sizeof(n));
    printf("int64_t %*d Bytes\n",12,(int) sizeof(o));
    printf("unsigned long long %*d Bytes\n",1,(int) sizeof(p));
    printf("uint64_t %*d Bytes\n",11,(int) sizeof(q));
    printf("float %*d Bytes\n",14,(int) sizeof(r));
    printf("double %*d Bytes\n",13,(int) sizeof(s));
    printf("long double %*d Bytes\n",9,(int) sizeof(t));
    printf("_Bool %*d Bytes\n",14,(int) sizeof(u));




    return 0;
}