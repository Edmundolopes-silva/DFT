#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define N 16
#define PI 3.1416
 
int main()
{
    
    int n, k;             // indices de dominio em tempo e frequencia
    float x[N];           // Sinal tempo-discreto
    float Xre[N], Xim[N]; // PARTE REAL E IMAGINARIA DA DFT
    float P[N];           // potencia do spectrum
     
    for (k=0 ; k<N ; ++k)
    {
        // Real part of X[k]
        Xre[k] = 0;
        for (n=0 ; n<N ; ++n){
        x[n] = sin(2*PI*1000*n/8000) + 0.5*sin(2*PI*2000*n/8000 + (3*PI/4));
        Xre[k] += x[n] * cos(n * k * PI * 2 / N);
        }
        // Imaginary part of X[k]
        Xim[k] = 0;
        for (n=0 ; n<N ; ++n) {
        x[n] = sin(2*PI*1000*n/8000) + 0.5*sin(2*PI*2000*n/8000 + 3*PI/4);
        Xim[k] += -x[n] * sin(n * k * PI * 2 / N);
        }
        // Power at kth frequency bin
        P[k] = sqrt(Xre[k]*Xre[k] + Xim[k]*Xim[k]);
    }
     
    // Output results to MATLAB / Octave M-file for plotting
    FILE *f = fopen("dftplots.m", "w");
    fprintf(f, "n = [0:%d];\n", N-1);
    fprintf(f, "x = [ ");
    for (n=0 ; n<N ; ++n) fprintf(f, "%f ", x[n]);
    fprintf(f, "];\n");
    fprintf(f, "Xre = [ ");
    for (k=0 ; k<N ; ++k) fprintf(f, "%f ", Xre[k]);
    fprintf(f, "];\n");
    fprintf(f, "Xim = [ ");
    for (k=0 ; k<N ; ++k) fprintf(f, "%f ", Xim[k]);
    fprintf(f, "];\n");
    fprintf(f, "P = [ ");
    for (k=0 ; k<N ; ++k) fprintf(f, "%f ", P[k]);
    fprintf(f, "];\n");
    fprintf(f, "subplot(3,1,1)\nplot(n,x)\n");
    fprintf(f, "xlim([0 %d])\n", N-1);
    fprintf(f, "subplot(3,1,2)\nplot(n,Xre,n,Xim)\n");
    fprintf(f, "xlim([0 %d])\n", N-1);
    fprintf(f, "subplot(3,1,3)\nstem(n,P)\n");
    fprintf(f, "xlim([0 %d])\n", N-1);
    fclose(f);
     
    // exit normally
    return 0;
}