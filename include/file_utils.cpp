#include "file_utils.hpp"
#include "common.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

std::vector<body> bodies;
int n;
float dt;

void read_input_file(std::string path)
{
    std::ifstream file(path.c_str());
    std::string line;

    while (file.good())
    {
        body tmp;
        getline(file, line, ' ');  tmp.m = atof(line.c_str());
        getline(file, line, ' ');  tmp.x = atof(line.c_str());
        getline(file, line, ' ');  tmp.y = atof(line.c_str());
        getline(file, line, ' ');  tmp.z = atof(line.c_str());
        getline(file, line, ' ');  tmp.v_x = atof(line.c_str());
        getline(file, line, ' ');  tmp.v_y = atof(line.c_str());
        getline(file, line, '\n'); tmp.v_z = atof(line.c_str());
        bodies.push_back(tmp);
    }
    file.close();
    bodies.pop_back();
    n = (int)bodies.size();
    std::cout << n << std::endl;
    dt = 0.01;
}

void write_output_file(std::string path)
{
    std::ofstream file(path.c_str());
    for (int i = 0; i < n; i++) {
        file << bodies[i].x   << " ";
        file << bodies[i].y   << " ";
        file << bodies[i].z   << " ";
        file << bodies[i].v_x << " ";
        file << bodies[i].v_y << " ";
        file << bodies[i].v_z << " ";
        file << bodies[i].a_x << " ";
        file << bodies[i].a_y << " ";
        file << bodies[i].a_z << "\n";
    }
    file.close();
}
