# DFT
Solving a DFT using C and plotting graphs with MATLAB/OCTAVE

Depois de calculada a parte REAL e IMAGNÁRIA, o algoritmo cria um arquivo ".m" para plotagem dos três gráficos de maneira automática com todos os dados necessários.

We can do it with random discrete-time signal x in range (-1,+1) like:

    srand(time(0));

    for (n=0 ; n<N ; ++n) x[n] = ((2.0 * rand()) / RAND_MAX) - 1.0;
    
    for (k=0 ; k<N ; ++k)
    {
    
        // Real part of X[k]
        Xre[k] = 0;
        for (n=0 ; n<N ; ++n) Xre[k] += x[n] * cos(n * k * PI2 / N);
        
        // Imaginary part of X[k]
        Xim[k] = 0;
        for (n=0 ; n<N ; ++n) Xim[k] -= x[n] * sin(n * k * PI2 / N);
        
        // Power at kth frequency bin
        P[k] = Xre[k]*Xre[k] + Xim[k]*Xim[k];
    }
