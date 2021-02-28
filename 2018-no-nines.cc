#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<int> tokenize(const std::string &input)
{
    std::vector<int> vec;
    
    for (size_t i = 0; i < input.length(); ++ i)
    {
        vec.emplace_back(std::stoi(input.substr(i, 1), nullptr, 0));
    }
    
    return vec;
}

int main(int argc, char **argv)
{
    int num_cases;
    std::cin >> num_cases;
    std::vector<int> test_outputs;

    test_outputs.resize(num_cases);

    for (size_t i = 0; i < num_cases; ++i)
    {
        size_t first, second;
        std::cin >> first >> second;

        for (size_t j = first; j <= second; ++j)
        {
            std::stringstream ss;
            ss << j;
            std::vector<int> vec = tokenize(ss.str());
            int sum = 0;

            for (size_t k = 0; k < vec.size(); ++k)
            {
                if (vec[k] == 9)
                {
                    sum = 9;
                    break;
                }
                sum += vec[k];
            }
            if (sum % 9 != 0)
                ++test_outputs[i];
        }
    }
    
    for (size_t i = 0; i < num_cases; ++i)
    {
        std::cout << "Case #" << i + 1 << ": " << test_outputs[i] << std::endl;
    }
    
    return 0;
}