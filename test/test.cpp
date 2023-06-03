#include "../loguml.hpp"
#include <gtest/gtest.h>
#include <iostream>


class TestNode {
  public: 
    TestNode() : m_TestId(std::to_string(s_TestId++)) {
      
    }

    auto GetID() const -> std::string {
      return m_TestId;
    }

    auto GetChildren() const -> std::vector<std::string> {
      return m_Children;
    }

    void AddChild(std::string childId) {
      if ( std::find(m_Children.begin(), m_Children.end(), childId) != m_Children.end() ) {
        m_Children.push_back(childId);
      }
    }

  private:
    static int s_TestId;

    std::string m_TestId;
    std::vector<std::string> m_Children;
};

int TestNode::s_TestId = 0;

auto visitWriteId(const TestNode& node) -> std::vector<std::string> {
  return std::vector<std::string>{node.GetID()};
}

TEST(TestGTest, BasicAsserts) {
  auto node1 = TestNode();
  auto node2 = TestNode();
  auto node3 = TestNode();

  node1.AddChild(node2.GetID());
  node1.AddChild(node3.GetID());

  std::unordered_map<std::string, TestNode> dag = {
    {node1.GetID(), node1},
    {node2.GetID(), node2},
    {node3.GetID(), node3}
  };
  
  generateGraphvizForDAG<TestNode>(
      dag, 
      node1.GetID(), 
      visitWriteId, 
      std::cout);

  ASSERT_EQ(0, 1);
}
