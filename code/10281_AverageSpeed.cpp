#include <iostream>
#include <cstdio>

int main(){
    char buf[1000];
    int n, t = 0, curr_t;
    int hh, mm, ss, curr_speed = 0, new_speed;
    double distance = 0;
    while (std::cin.getline(buf, sizeof(buf))){
        n = sscanf(buf, "%d:%d:%d %d", &hh, &mm, &ss, &new_speed);
        curr_t = hh * 3600 + mm * 60 + ss;
        distance += (curr_t - t) * curr_speed;
        t = curr_t;
        if (n == 3)
            printf("%02d:%02d:%02d %.2lf km\n", hh, mm, ss, distance/3600);
        else if (n == 4)
            curr_speed = new_speed;
    }
    return 0;
}