#include <math.h>
#include <cmplx.h>
#include <stdio.h>

typedef float cmplx_t[2];

void cmplx_div(cmplx_t a, cmplx_t b, cmplx_t c)
{
	cmplx_t pom;

	pom[0] = (a[0]*b[0] + a[1]*b[1]) / (b[0]*b[0] + b[1]*b[1]);
	pom[1] = (a[1]*b[0] - a[0]*b[1]) / (b[0]*b[0] + b[1]*b[1]);

	c[0] = pom[0];
        c[1] = pom[1];
	return;
}

void cmplx_mul(cmplx_t a, cmplx_t b, cmplx_t c)
{
	cmplx_t pom;

        pom[0] = a[0]*b[0] - a[1]*b[1];
        pom[1] = a[1]*b[0] + a[0]*b[1];

        c[0] = pom[0];
        c[1] = pom[1];
	//printf("a0 %f a1 %f\n", a[0], a[1]);
	//printf("b0 %f b1 %f\n", b[0], b[1]);
	//c[0]=(a[0]*b[0]-a[1]*b[1]);
	//printf("a0 %f a1 %f\n", a[0], a[1]);
	//printf("b0 %f b1 %f\n", b[0], b[1]);
	//c[1]=(a[0]*b[1]+a[1]*b[0]);
	//printf("a0 %f a1 %f\n", a[0], a[1]);
	//printf("b0 %f b1 %f\n", b[0], b[1]);
	//printf("a0*b1 %f a1*b0 %f\n", a[0]*b[1], a[1]*b[0]);
}

double cmplx_mag(cmplx_t a)
{
	return sqrt(a[0]*a[0]+a[1]*a[1]);
}

double cmplx_phs(cmplx_t a)
{
	return atan(a[1]/a[0]);
}

double cmplx_real(double mag, double phs)
{
	return mag*(cos(phs));
}

double cmplx_imag(double mag, double phs)
{
	return mag*(sin(phs));
}

void cmplx_dft(cmplx_t *input, cmplx_t *output, int N)
{
	int i, j;
	cmplx_t koef;
	for (i = 0; i < N; i++)
	{
	    output[i][0] = 0;
	    output[i][1] = 0;
            for (j = 0; j < N; j++)
            {
                koef[0] = cos((2 * M_PI * j * i / N));
		//printf("koef0 %f\n", koef[0]);
                koef[1] = -1 * sin((2 * M_PI * j * i / N));
		//printf("koef1 %f\n", koef[1]);
		//printf("inputj %f %f\n", input[j][0], input[j][1]);
                cmplx_mul(koef, input[j], koef);
		//printf("koef0 nakon mul %f\n", koef[0]);
		//printf("koef1 nakon mul %f\n", koef[1]);
                output[i][0] += koef[0];
		//printf("out0 %f\n", output[i][0]);
                output[i][1] += koef[1];
		//printf("out1 %f\n", output[i][1]);
            }
        }
}

void cmplx_idft(cmplx_t *input, cmplx_t *output, int N)
{
	int i, j;
	cmplx_t koef;
	for (i = 0; i < N; i++)
	{
	    output[i][0] = 0;
	    output[i][1] = 0;
    	    for (j = 0; j < N; j++)
	    {
		koef[0] = cos((2 * M_PI * j * i / N)) / N;
		koef[1] = sin((2 * M_PI * j * i / N)) / N;
                cmplx_mul(koef, input[j], koef);
                output[i][0] += koef[0];
                output[i][1] += koef[1];
            }
        }
}
