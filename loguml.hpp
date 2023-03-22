#include <unordered_map>
#include <string>
#include <iostream>

// Print Graphviz code for a DAG represented as an unordered_map
void printGraphvizCode(const std::unordered_map<std::string, std::unordered_map<std::string, std::string>>& dag) {
    std::cout << "digraph {\n";

    // Iterate over all nodes in the DAG
    for (const auto& node : dag) {
        // Print the node ID
        std::cout << "    " << node.first << " [label=\"" << node.first << "\"];\n";

        // Iterate over all edges from the node
        for (const auto& edge : node.second) {
            // Print the edge
            std::cout << "    " << node.first << " -> " << edge.first << " [label=\"" << edge.second << "\"];\n";
        }
    }

    std::cout << "}\n";
}
