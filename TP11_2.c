#include <stdio.h>
#define N 32
union ieee{
	float num;
	unsigned int n;
	struct {
		unsigned int mant:23;
		unsigned int exp:8;
		unsigned int sign:1;
	}bits;
	
};
void print_ieee(float);
void print_sign(float);
void print_exp(float);
void print_mant(float);
unsigned int get_ieee_sign (float n);
unsigned int get_ieee_exp (float n);
unsigned int get_ieee_mantissa (float n);


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
	printf ("Numero expresado en binario:  ");
	for (int i = 0; i < N; i++) {
		printf("%d", mask & u.n ? 1 : 0);
		mask=mask>>1;
	}
}


void print_sign(float num)
{
	union ieee s={num};
	printf("\nBit de signo: ");
	printf("%d",s.bits.sign);
	printf("(%d)",get_ieee_sign(num));
}

unsigned int get_ieee_sign (float n)
{
	union ieee s={n};
	return s.bits.sign;
}

void print_exp(float num)
{
	union ieee e={num};
	unsigned int mask=1<<(7);
	printf("\nBits de exponente: ");
	for (int i = 0; i < 8; i++) {
		printf("%d", mask & e.bits.exp ? 1 : 0);
		mask>>=1;
	}
	printf("(%d)",get_ieee_exp (num));
}

unsigned int get_ieee_exp (float n)
{
	union ieee e={n};
	return e.bits.exp;
}

void print_mant(float num)
{
	union ieee m={num};
	unsigned int mask=1<<(22);
	printf("\nBits de mantissa: ");
	for (int i = 0; i < 23; i++) {
		printf("%d", mask & m.bits.mant ? 1 : 0);
		mask>>=1;
	}
	printf("(%d)",get_ieee_mantissa (num));
}

unsigned int get_ieee_mantissa (float n)
{
	union ieee m={n};
	return m.bits.mant;
}




