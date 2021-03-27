#include <iostream>
#include <vector>
#include <unordered_map>

//big O(n^2)
//f(n) = f(n-1) + f(n-2)
int fibonnaci_recursive(const int &n)
{
    //base case: f(0) = 0; f(1) = 1;
    if(n <= 1)
    {
        return n;
    }
    return fibonnaci_recursive(n-1) + fibonnaci_recursive(n-2);
}

//big O(n)
int fibonnaci_linear(const int &n)
{
    if(n <= 1)
    {
        return n;
    }
    int t1 = 0;
    int t2 = 1;
    int nextTerm{};

    //f(2) = f(1) + f(0)
    //f(3) = f(2) + f(1)
    for(int i=2; i<=n; i++)
    {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return nextTerm;
}

//big O(n) or O(1) if already saved
int fibonnaci_memoization(const int &n, std::unordered_map<int,int> &fib_map)
{
    auto x = fib_map.find(n);
    if(x != fib_map.end())
    {
        std::cout << "using memoization!" << std::endl;
        return x->second;
    }
    int t1 = 0;
    int t2 = 1;
    int nextTerm{};

    for(int i=2; i<=n; i++)
    {
        nextTerm = t1 + t2;
        fib_map.insert(std::make_pair(i,nextTerm));
        t1 = t2;
        t2 = nextTerm;
    }
    return nextTerm;
}


int main(int argc, char *argv[])
{
    int argv1 = atoi(argv[1]);

    //option 1: use recursion
    std::cout << "fibonnaci_recursive() = " << fibonnaci_recursive(argv1) << std::endl;
    
    //option 2: use linear method
    std::cout << "fibonnaci_linear() = " << fibonnaci_linear(argv1) << std::endl;
    
    //option 3: use memoization
    std::unordered_map<int,int> fib_map{};
    fib_map[0] = 0;
    fib_map[1] = 1;
    std::cout << "fibonnaci_memoization() = " << fibonnaci_memoization(2,fib_map) << std::endl;
    std::cout << "fibonnaci_memoization() = " << fibonnaci_memoization(3,fib_map) << std::endl;
    std::cout << "fibonnaci_memoization() = " << fibonnaci_memoization(3,fib_map) << std::endl;
    std::cout << "fibonnaci_memoization() = " << fibonnaci_memoization(2,fib_map) << std::endl;
    std::cout << "fibonnaci_memoization() = " << fibonnaci_memoization(9,fib_map) << std::endl;
    std::cout << "fibonnaci_memoization() = " << fibonnaci_memoization(9,fib_map) << std::endl;
    return EXIT_SUCCESS;
}