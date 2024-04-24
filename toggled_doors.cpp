#include <iostream> 
#include <math.h>
int main(){
    int doors;
    std::cin >> doors;

    /**
     * pattern of toggle
     * 1 2 3 4 5
     * 2 4 6 8 
     * 3 6 9 12 ...
     * 
     * we can see each number is toggled = number of factors it has
     * 
     * so we need to count all those numbers which are toggled odd number of time
     * 
     * all numbers except perfect squares have odd divisors
     * */

    std::cout << sqrtl(doors);
    return 0;
}