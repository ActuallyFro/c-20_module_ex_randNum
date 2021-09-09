//https://stackoverflow.com/questions/14009637/c11-random-numbers
#include <random>
#include <iostream>

struct MT19937 {
private:
    static std::mt19937_64 rng;
public:
    // This is equivalent to srand().
    static void seed(uint64_t new_seed = std::mt19937_64::default_seed) {
        rng.seed(new_seed);
    }

    // This is equivalent to rand().
    static uint64_t get() {
        return rng();
    }
};

std::mt19937_64 MT19937::rng;


int main() {
    //MT19937::seed(/*put your seed here*/);
    MT19937::seed((uint64_t)(788574));

    for (int i = 0; i < 10; ++ i)
        std::cout << MT19937::get() << std::endl;
}
