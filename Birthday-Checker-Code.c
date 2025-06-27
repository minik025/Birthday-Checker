#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	//Dogum gununu kontrol eden ve yas hesaplayan program.
	int gun,ay,yil;
	// Kulllanicidan veri al
	printf("Dogum gununuzu giriniz:\n");
	printf("Gun: ");   
	scanf("%d",&gun);
	printf("Ay: ");
	scanf("%d",&ay);
	printf("Yil: ");
	scanf("%d",&yil);
	//Klavyeden girilen tarihi goster
	printf("Girdiginiz dogum tarihi: %02d/%02d/%d\n",gun,ay,yil);
	time_t t = time(NULL);                   //su an ki zamani al
	struct tm *bugun = localtime(&t);              //Parcala gun,ay,yil
	int bugun_gun = bugun->tm_mday;
	int bugun_ay = bugun->tm_mon + 1;                  //Ocak 0 oldugu icin + 1
	int bugun_yil = bugun->tm_year + 1900;                // Yil 1900 basliyo
	printf("Bugunun tarihi: %02d/%02d/%d\n",bugun_gun,bugun_ay,bugun_yil);
	//Gun ve Ay ikisiide ayniysa 
	if (gun == bugun_gun && ay == bugun_ay){
		printf("\a:)Bugun dogum gunun kutlu olsun nice yaslara.\n");
	} else {
		printf("Bugun dogum gunun degil uzulme.\n");
	}
	int yas = bugun_yil - yil;
	//Dogum  gunu gelmediyse 1 yas kucuk
	if (ay > bugun_ay || (ay == bugun_ay && gun > bugun_gun)){
		yas--;
	}
	printf("Su an ki %d yasindasin (:\n",yas);
	

	return 0;
}
