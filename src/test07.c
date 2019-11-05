#include <cmplx.h>
#include <stdio.h>

int main (){
	cmplx_t input[2], dft[2];

	input[0][0]=1;
	input[0][1]=1;
	input[1][0]=2;
	input[1][1]=2;

	cmplx_dft(input,dft,2);
	printf("\nprvi član: %.2f + j%.2f \n", dft[0][0], dft[0][1]);
	printf("\ndrugi član: %.2f + j%.2f \n", dft[1][0], dft[1][1]);

	return 0;
}
