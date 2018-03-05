#include <iostream>
#include <fstream>
#include <sstream>

#include "FactoryIO.hpp"
#include "Simulation.hpp"

/*
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}
 */
int main(int argc, char **argv){
    std::ostringstream oss;
    std::ifstream file("/home/michal/CLionProjects/FactorySimulation/struct-input.txt", std::ifstream::in);
    std::string tmpLine;
    while (std::getline(file, tmpLine)) {
        oss << tmpLine << "\n";
    }
    std::istringstream iss(oss.str());
    Factory factory = loadFactoryStructure(iss);
    simulate(factory,10);

}