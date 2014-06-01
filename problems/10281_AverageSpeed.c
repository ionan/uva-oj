#include <stdio.h>

double getDistance(int hh1, int mm1, int ss1, int hh2, int mm2, int ss2, int speed);

int main(int argc, char const *argv[]){
	int speed = 0, lastSpeed, hh, mm, ss, lastHh, lastMm, lastSs, trash, iters = 0; 
	double distance = 0;
	char c;
	while (scanf("%d:%d:%d", &hh, &mm, &ss) != EOF){
		if (iters > 0) 
			distance += getDistance(hh,mm,ss,lastHh,lastMm,lastSs,lastSpeed);
		iters++;
		if ((c = getchar()) == '\n' || c == EOF){
			printf("%02d:%02d:%02d %.2lf km\n",hh,mm,ss,distance);
		} else {
			trash = scanf("%d\n",&speed);
			lastSpeed = speed;
		}
		lastHh = hh;
		lastMm = mm;
		lastSs = ss;		
	}
	return 0;
}

double getDistance(int hh1, int mm1, int ss1, int hh2, int mm2, int ss2, int speed){
	int hh = 0;
	if (hh1 < hh2){
		hh = 24 + hh1 - hh2;
	} else {
		hh = hh1 - hh2;
	}

	int mm = 0;
	if (mm1 < mm2){
		mm = 60 + mm1 - mm2;
		hh--;
	} else {
		mm = mm1 - mm2;
	}

	int ss = 0;
	if (ss1 < ss2){
		ss = 60 + ss1 - ss2;
	} else {
		ss = ss1 - ss2;
	}

	double timeEllapsed = hh;

	if (mm != 0 && 60 % mm == 0){
		timeEllapsed += 1.0/(60.0/mm);
	} else {
		timeEllapsed += (mm / 60.0);
	}

	if (ss > 0) timeEllapsed += (ss / 3600.0);

	return speed * timeEllapsed;
}