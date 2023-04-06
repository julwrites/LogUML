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

template<typename Node, typename InfoSet>
void generateGraphvizForDAG(
    const std::unordered_map<std::string, Node>& dag, 
    const std::string &node, // Starting node ID
    const std::function<std::vector<std::string>>(Node)> &visitor, // Extract the info to print from each Node
    std::ostream& out
    )
{
    out << "digraph {\n";

    // Set of visited ID's
    std::set<std::string> visited = { };

    // Set of next to visit ID's
    std::set<std::string> toVisit = { start };

    while (!toVisit.empty()) {
      // Starting node
      const Node start = dag[node];

      for (const auto & info : visitor(start)) {
        out << start.GetID() << "[label=\"" info << "\"];\n";
      }

      for (const auto & child : start.GetChildren() {
        out << start.GetID() << " -> " << child.GetID() << std::endl;
        toVisit.insert(child.GetID());
      }

      visited.insert(start.GetID());
      toVisit.remove(start.GetID());
    }

    out << "}\n";
}
