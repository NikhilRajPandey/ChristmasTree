#include <stdio.h>
#include <stdlib.h> 
#include<time.h>

char random_decorative(){ // Give random from *.+O surch that * have greater possibility
    int random_digit = rand()%10;
    switch (random_digit){
        case 7:return 'o';
        case 8:return '+';
        case 9:return 'O';
        default:return '*';
    }
}
void print_wooden_area(int start_,int end_){ // Start-end_ will be the width and (width)/2=height
    for (int i = 0; i < (end_-start_)/2; i++){
        for (int j = 0; j < end_; j++){
            if(j<start_){printf(" ");}
            else{printf("#");}
        }
        printf("\n");
    }

}
void print_christmas_leaf(){
    int interval_ = 4;
    int next_interval = 4;
    int no_of_interval = 5;
    int leaf_start = 20;
    int leaf_end = leaf_start+1;

    while (no_of_interval > 0){
        while (interval_ > 0){
            for (int i = 0; i < leaf_end; i++){
                if (i < leaf_start){printf(" ");}
                else{printf("%c ",random_decorative());}
            }
            printf("\n");
            leaf_start--;
            interval_--;
        }
        interval_ = next_interval;
        next_interval++;
        leaf_start +=3;
        no_of_interval--;
    }
    leaf_start -=3;
    leaf_end = leaf_start+(leaf_end-leaf_start)*2-2;
    // Doing this so that leaf at the end of trapezium base because i have printed whitespace characters also(Comment For myself)
    print_wooden_area((leaf_start+leaf_end)/3+1,2*(leaf_start+leaf_end)/3);
    // Just using trial and error method i am able to get the wooden area width and height
}
int main(){
    srand(time(0));
    print_christmas_leaf();
    return 0;
}
/*
    Note for me
    I founded in my rough copy that for any trapezium(or triangle) form by leafs base can be calculated by this function:-> interval_+Σ(no_of_itervals)
*/
