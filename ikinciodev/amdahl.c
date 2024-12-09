#include <stdio.h>

double amdahl(double p, int n) {
    return 1.0 / ((1 - p) + (p / n));
}

int main() {
    double p;
    int n; 

    
    printf("Paralelize edilebilen kısmın oranını girin (0 ile 1 arasında): ");
    scanf("%lf", &p);
    
    printf("İşlemci sayısını girin: ");
    scanf("%d", &n);

    
    double hızlanma = amdahl(p, n);

    printf("Hızlanma oranı: %.2f\n", hızlanma);

    return 0;
}

