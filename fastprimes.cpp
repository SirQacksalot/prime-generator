#include <stdio.h>
#include <set>
#include <time.h>

int main(void)
{
    std::set<int> composites;

    int bound, i, count, m;
    printf("Enter a bound: ");
    scanf("%d", &bound);
    
    count = 0;

    double time_spent = 0.0;
    clock_t begin = clock();

    for(i = 2; i <= bound; i++){
        auto search = composites.find(i);
        if (search != composites.end()){
            continue;
        }          
        else{ // when i is prime
            count++;
            for(m = 2; m <= bound/i +1; m++){
                composites.insert(m*i);   
            }

            printf("%d ", i);
        } 
    }

    printf("\nThere are %d primes between 1 and %d\n", count, bound);


    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThe elapsed time is %f seconds", time_spent);
}