#include "unorderedMap.h"


#include <iostream>
#include <string>
#include "unorderedMap.h"

int main() {
    // Create an empty unordered_map
    MySTL::unorderedMap<std::string, int>umap;

    // Insert some key-value pairs
    umap.insert({"apple", 1});
    umap.insert({"banana", 2});
    umap.insert({"cherry", 3});

    // Print the size of the unordered_map
    std::cout << "Size of umap: " << umap.size() << std::endl;

    return 0;
}
