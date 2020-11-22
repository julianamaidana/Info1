#include <stdio.h>
#include <math.h>
#define N 32


union ieee{
	float num;
	unsigned int bits;
};
void print_ieee(float);
void print_sign(float);
unsigned int get_ieee_sign (float);
void print_exp(float);
unsigned int get_ieee_exp (float);
void print_mant(float);
unsigned int get_ieee_mantissa (float);

void imp_mant(float);

int main(void) 
{
	float num;
		
	printf("Ingrese un número real: ");
	scanf("%f",&num);

	print_ieee(num);
	print_sign(num);
	print_exp(num);
	print_mant(num);
	
	return 0;
}

void print_ieee(float num)
{
	union ieee u={num};
	unsigned int mask=1<<(N - 1);
	printf("Numero expresado en binario\n");
	for (int i = 0; i < N; i++) {
		printf("%d", mask & u.bits ? 1 : 0);
		mask=mask>>1;
	}
}

void print_sign(float num)
{
	union ieee s={num};
	unsigned int mask=1<<(N - 1);
	printf("\nBit de signo: ");
	printf("%d", mask & s.bits ? 1 : 0);
	printf("(%d)",get_ieee_sign (num));
}

unsigned int get_ieee_sign (float num)
{
	union ieee s={num};
	unsigned int mask=1<<(N-1);
	return (mask & s.bits ? 1 : 0);
}
void print_exp(float num)
{
	union ieee e={num};
	unsigned int mask=1<<(N-2);
	printf("\nBits de exponente: ");
	for (int i = 0; i < 8; i++) {
		printf("%d", mask & e.bits ? 1 : 0);
		mask=mask>>1;
	}
	printf("(%d)",get_ieee_exp (num));
}

unsigned int get_ieee_exp (float num)
{
	union ieee e={num};
	unsigned int exp=0x7f800000;
	e.bits&=exp;
	e.bits>>=(N-9);
	return e.bits;
}

void print_mant(float num)
{
	union ieee m={num};
	unsigned int mask=1<<(N-10);
	printf("\nBits de mantissa: ");
	for (int i = 0; i < 23; i++) {
		printf("%d", mask & m.bits ? 1 : 0);
		mask=mask>>1;
	}
	printf("(%d)",get_ieee_mantissa (num));
}
unsigned int get_ieee_mantissa (float num)
{
	union ieee m={num};
	unsigned int mant=0x007fffff;
	m.bits &= mant;
	return m.bits;
}	
	
	

