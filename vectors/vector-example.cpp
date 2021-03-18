#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    auto printLambda = [](const auto& elem) { std::cout << elem << " "; };

    //create empty vector then add 3 elements
    std::vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    std::for_each(vec1.begin(),vec1.end(), printLambda);
    std::cout << std::endl;

    //vector with 3 elements
    std::vector<int> vec2{4,5,6};
    std::for_each(vec2.begin(),vec2.end(),printLambda);
    std::cout << std::endl;

    //vector with 3 elements
    std::vector<int> vec3 = {7,8,9};
    std::for_each(vec3.begin(),vec3.end(),printLambda);
    std::cout << std::endl;

    //vector with size n
    int n = 3;
    std::vector<int> vec4(n);
    std::cout << "vec4 size=" <<vec4.size() << std::endl;
    vec4[0]=10;
    vec4[1]=11;
    vec4[2]=12;
    std::for_each(vec4.begin(),vec4.end(),printLambda);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
