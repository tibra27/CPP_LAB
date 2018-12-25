/*

Write a program that computes the square roots of the integers from 0 to 99 in a separate thread and
returns an array of doubles containing the results. In the meantime the main thread should display a short
message to the user and then display the results of the computation when they are ready.

*/

//	 NOTE : When using math.h library functions we need to compile the code with -lm flag.
// 	because library which contains functions of math.h is not linked by default.

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h> 		//	required for sqrt() function.


/*
	This function computes the square root and returns the result.
*/

void * thread_function(void *param)
{
	int i;
	double *result = malloc(sizeof(double)*100);	// create array to store results.
	
	for(i=0;i<100;i++)
	{
		result[i] = sqrt((double)i);	//	compute the answer using sqrt() library function.
	}
	
	return (void *)result;	//	return the result.

}

int main()
{
	pthread_t 	threadID;
	void 		*exit_status;
	double		*result;
	int 		i;
	
	pthread_create(&threadID,NULL,thread_function,NULL);
	pthread_join(threadID,&exit_status);
	
	printf("\n\nResults are being computed. Please wait.\n\n");
	
	result = (double *) exit_status;
	
	for(i=0;i<100;i++)
	{
		printf("\nsqrt(%d) = %lf",i,result[i]);
	}
	
	free(result);	// free the memory allocated by the thread to avoid memory leakage.
	
	printf("\n\n");
	return 0;
}

/* OUTPUT :

home@home-virtual-machine:~/PTHREAD$ gcc -o prog2_ex1 prog2_ex1.c -lm -pthread
home@home-virtual-machine:~/PTHREAD$ ./prog2_ex1 


Results are being computed. Please wait.


sqrt(0) = 0.000000
sqrt(1) = 1.000000
sqrt(2) = 1.414214
sqrt(3) = 1.732051
sqrt(4) = 2.000000
sqrt(5) = 2.236068
sqrt(6) = 2.449490
sqrt(7) = 2.645751
sqrt(8) = 2.828427
sqrt(9) = 3.000000
sqrt(10) = 3.162278
sqrt(11) = 3.316625
sqrt(12) = 3.464102
sqrt(13) = 3.605551
sqrt(14) = 3.741657
sqrt(15) = 3.872983
sqrt(16) = 4.000000
sqrt(17) = 4.123106
sqrt(18) = 4.242641
sqrt(19) = 4.358899
sqrt(20) = 4.472136
sqrt(21) = 4.582576
sqrt(22) = 4.690416
sqrt(23) = 4.795832
sqrt(24) = 4.898979
sqrt(25) = 5.000000
sqrt(26) = 5.099020
sqrt(27) = 5.196152
sqrt(28) = 5.291503
sqrt(29) = 5.385165
sqrt(30) = 5.477226
sqrt(31) = 5.567764
sqrt(32) = 5.656854
sqrt(33) = 5.744563
sqrt(34) = 5.830952
sqrt(35) = 5.916080
sqrt(36) = 6.000000
sqrt(37) = 6.082763
sqrt(38) = 6.164414
sqrt(39) = 6.244998
sqrt(40) = 6.324555
sqrt(41) = 6.403124
sqrt(42) = 6.480741
sqrt(43) = 6.557439
sqrt(44) = 6.633250
sqrt(45) = 6.708204
sqrt(46) = 6.782330
sqrt(47) = 6.855655
sqrt(48) = 6.928203
sqrt(49) = 7.000000
sqrt(50) = 7.071068
sqrt(51) = 7.141428
sqrt(52) = 7.211103
sqrt(53) = 7.280110
sqrt(54) = 7.348469
sqrt(55) = 7.416198
sqrt(56) = 7.483315
sqrt(57) = 7.549834
sqrt(58) = 7.615773
sqrt(59) = 7.681146
sqrt(60) = 7.745967
sqrt(61) = 7.810250
sqrt(62) = 7.874008
sqrt(63) = 7.937254
sqrt(64) = 8.000000
sqrt(65) = 8.062258
sqrt(66) = 8.124038
sqrt(67) = 8.185353
sqrt(68) = 8.246211
sqrt(69) = 8.306624
sqrt(70) = 8.366600
sqrt(71) = 8.426150
sqrt(72) = 8.485281
sqrt(73) = 8.544004
sqrt(74) = 8.602325
sqrt(75) = 8.660254
sqrt(76) = 8.717798
sqrt(77) = 8.774964
sqrt(78) = 8.831761
sqrt(79) = 8.888194
sqrt(80) = 8.944272
sqrt(81) = 9.000000
sqrt(82) = 9.055385
sqrt(83) = 9.110434
sqrt(84) = 9.165151
sqrt(85) = 9.219544
sqrt(86) = 9.273618
sqrt(87) = 9.327379
sqrt(88) = 9.380832
sqrt(89) = 9.433981
sqrt(90) = 9.486833
sqrt(91) = 9.539392
sqrt(92) = 9.591663
sqrt(93) = 9.643651
sqrt(94) = 9.695360
sqrt(95) = 9.746794
sqrt(96) = 9.797959
sqrt(97) = 9.848858
sqrt(98) = 9.899495
sqrt(99) = 9.949874

*/
