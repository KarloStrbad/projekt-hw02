#include <cmplx.h>
#include <stdio.h>

int main (){
	cmplx_t input[2], idft[2];

	input[0][0]=3;
	input[0][1]=3;
	input[1][0]=-1;
	input[1][1]=-1;

	cmplx_idft(input,idft,2);
	printf("\nprvi član: %.2f + j%.2f \n", idft[0][0], idft[0][1]);
	printf("\ndrugi član: %.2f + j%.2f \n", idft[1][0], idft[1][1]);

	return 0;
}
