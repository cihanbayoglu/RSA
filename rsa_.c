// C dili RSA uygulamasý 
#include<stdio.h>
#include<math.h>
// e degerinin totient degeri ile asal olmasýný saðlayan fonksiyon
int gcd(int a, int h)
{
    int temp;
    while (1)
    {
        temp = a%h;
        if (temp == 0)
          return h;
        a = h;
        h = temp;
    }
}


double sifreleme(double msg, double n , double e)
{
	
	double c=msg;
	int i,sayac =1;

	
	for( i=1 ; i<e ; i++)
	{
		sayac++;
		c= c*msg;
		
		c= fmod(c,n);
		printf("%d . sonuc =%0.lf \t",sayac,c);	 //eger istenilirse aþamalar tek tek ekreana basýlýr.
		
	}
	
	return c;
}
 
double desifreleme(double c , double n , double d)
{
	double msg = c;
	int i,sayac=1;
	
	for(i=1 ; i<d ; i++)
	{
		sayac++;
		msg = msg * c;
		
		msg = fmod ( msg , n );
		printf("%d. desifreleme = %0.lf \t",sayac,msg);  //eger istenilirse aþamalar tek tek ekreana basýlýr.
	}
	
	return msg;
	
}
 
 
 
int main()
{
    // 2 tane aralarýnda asal sayi
    double p , q ;
    printf("Lutfen aralarinda asal 2 sayi giriniz ... \n");
    printf("1. sayi = "); scanf("%lf",&p);
    printf("2. sayi = "); scanf("%lf",&q);
    
    
 	printf("p = %.0lf \nq = %.0lf\n",p,q);
 	
    // Mod tabanýný hesaplama ( n mod )
    double n = p*q;
 	printf("n= %.0lf \n",n);
   
    double e = 2;
    double phi = (p-1)*(q-1); // Totient fonksiyonu
    printf("totient = %.0lf \n",phi);
    while (e < phi)
    {
     
        if (gcd(e, phi)==1)
            break;
        else
            e++;
    }
 	printf("e=  %.0lf \n",e);
  
	// d yi hesaplama 
 	double d=1;
 
 	while(1)
	{
		if (fmod(d*e,phi)==1)
		break;
		
		d++;
	}
 	
 	printf("d = %0.f  \n",d);
    double msg;
 
    printf("Mesajiniz  = ") ; 
    scanf("%lf",&msg);
    
    // 'msg' nin  'n' sayýsýndan büyük olmasý durumunda çalýþýr
    int kat= msg/n;
 
 // sifreleme fonksiyonu çalýþýyor.
 	double c = sifreleme(msg,n,e) ;
    printf("\nSifreli veri = %.0lf\n", c );
 
	// deþifreleme fonskiyonu çalýþýyor.
	msg = desifreleme(c,n,d);
    msg+= (n*kat);  // 'msg' nin 'n' den büyük olma durumu
    printf("\nDesifre edilmis mesaj = %.0lf", msg);
 
    getch();
}
