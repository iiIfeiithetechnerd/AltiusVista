#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <vulkan/vulkan.hpp>
#include "shader.hpp"

std::vector<char> readFile(const std::string& filename) {

    std::ifstream file(filename, std::ios::ate | std::ios::binary); 
    std::vector<char> buffer(file.tellg());
    file.seekg(0);
    file.read(buffer.data(), buffer.size());        
    return buffer;
}
