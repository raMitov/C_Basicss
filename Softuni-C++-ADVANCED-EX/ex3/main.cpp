#include <iostream>
#include <vector>
#include <map>
#include <cmath>
int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> interceptions(n, std::vector<int>(n,0));
    
    for(auto &row : interceptions)
    {
        for(auto &cell : row)
        {
            std::cin >> cell;
        }
    }
    std::cout << "  ";
    for(int i = 0; i < n; i++)
    {
        std::cout << char('A' + i)<< " ";
    }
    std::cout << std::endl;
    int count = 0;
    for(auto &row : interceptions)
    {
        std::cout << char('A' + count) << " ";
        for(auto &cell : row)
        {


            std::cout << cell << " ";

        }
        std::cout << std::endl;
        count++;
    }
    int totalOps = 0;
    int bigOpt = 0;
    std::map<std::string, std::string> myMap;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(interceptions[i][j] < interceptions[j][i]){
                std::cout << char('A' + i) << char('A' + j) <<"(" << interceptions[i][j] << ")" << " - " << char('A' + j) << char('A' + i) << "(" << interceptions[j][i] << ")" <<std::endl;
                totalOps += abs(interceptions[i][j] - interceptions[j][i]);
                if(bigOpt < abs(interceptions[i][j] - interceptions[j][i])){
                        bigOpt = abs(interceptions[i][j] - interceptions[j][i]);
                  }


            }
        }

    }
    std::cout << "Total oportunities: " << totalOps << std::endl;
    if(bigOpt == 0)
    {
        std::cout << "Max optimisation: None" << std::endl;
        return 0;
    }
    std::cout << "Max optimisation: " << bigOpt << ": ";
    
    return 0;

}
