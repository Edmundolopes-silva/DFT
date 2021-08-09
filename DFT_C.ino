void setup()
{
  Serial.begin(9600);
}

void loop()
{
    int n, k;             // indices de dominio em tempo e frequencia
    float x[16];           // Sinal tempo-discreto
    float Xre[16], Xim[16]; // PARTE REAL E IMAGINARIA DA DFT
    float P[16];           // potencia do spectro
     
    for (k=0 ; k<16 ; k++)
    {
        // Real part of X[k]
        Xre[k] = 0;
        for (n=0 ; n<16 ; n++){
        x[n] = sin(2*PI*1000*n/8000) + 0.5*sin(2*PI*2000*n/8000 + (3*PI/4));
        Xre[k] += x[n] * cos(n * k * PI * 2 / 16);
        }
        // Imaginary part of X[k]
        Xim[k] = 0;
        for (n=0 ; n<16 ; n++) {
        x[n] = sin(2*PI*1000*n/8000) + 0.5*sin(2*PI*2000*n/8000 + 3*PI/4);
        Xim[k] += -x[n] * sin(n * k * PI * 2 / 16);
        }
        // Power at kth frequency bin
        P[k] = sqrt(Xre[k]*Xre[k] + Xim[k]*Xim[k]);
    }
    for(int y=0; y<16 ; y++)
    {
      Serial.println(P[y]);
    }
}
