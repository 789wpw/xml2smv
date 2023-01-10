#ifndef XML_PARSING_H
#define XML_PARSING_H

#include "behaviortree_cpp_v3/bt_parser.h"

namespace BT
{


class XMLParser: public Parser
{
  public:
    XMLParser(const BehaviorTreeFactory& factory);

    ~XMLParser() override;

    XMLParser(const XMLParser& other) = delete;
    XMLParser& operator=(const XMLParser& other) = delete;

    void loadFromFile(const std::string& filename, bool add_includes = true) override;

    void loadFromText(const std::string& xml_text, bool add_includes = true) override;

    std::vector<std::string> registeredBehaviorTrees() const override;

    Tree instantiateTree(const Blackboard::Ptr &root_blackboard,
                         std::string main_tree_to_execute = {}) override;

  private:

    struct Pimpl;
    Pimpl* _p;

};

void VerifyXML(const std::string& xml_text,
               const std::set<std::string> &registered_nodes);

std::string writeTreeNodesModelXML(const BehaviorTreeFactory& factory,
                                   bool include_builtin = false);

}

#endif   // XML_PARSING_BT_H
