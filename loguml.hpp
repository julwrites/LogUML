#include <unordered_map>
#include <set>
#include <string>
#include <iostream>

// The conceptual type: Node
// e.g. 
// class Node {
//  public: 
//    auto GetID() -> std::string;
//    auto GetChildren() -> std::vector<std::string>
// };
// We assume the DAG is made up of Node objects, which internally hold all their relations

template<typename Node>
void generateGraphvizForDAG(
    const std::unordered_map<std::string, Node>& dag, 
    const std::string &nodeId, // Starting node ID
    const std::function<std::vector<std::string>(const Node&)> &visitor, // Extract the info to print from each Node
    std::ostream& oss
    )
{
    oss << "digraph {\n";

    // Set of visited ID's
    std::set<std::string> visited = { };

    // Set of next to visit ID's
    std::set<std::string> toVisit = { nodeId };

    while (!toVisit.empty()) {
      // Starting node
      const Node currNode = dag.at(nodeId);

      // Print the labels associated with this node into the node
      for (const auto & info : visitor(currNode)) {
        oss << currNode.GetID() << "[label=\"" << info << "\"];\n";
      }

      // Generate the links to the next node
      for (const auto & childId : currNode.GetChildren()) {
        oss << currNode.GetID() << " -> " << childId << std::endl;
        toVisit.insert(childId);
      }

      visited.insert(currNode.GetID());
      toVisit.erase(currNode.GetID());
    }

    oss << "}\n";
}
