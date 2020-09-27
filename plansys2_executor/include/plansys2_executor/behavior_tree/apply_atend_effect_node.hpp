// Copyright 2020 Intelligent Robotics Lab
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef PLANSYS2_EXECUTOR__BEHAVIOR_TREE__APPLY_ATEND_EFFECT_NODE_HPP_
#define PLANSYS2_EXECUTOR__BEHAVIOR_TREE__APPLY_ATEND_EFFECT_NODE_HPP_

#include <map>
#include <string>

#include "behaviortree_cpp_v3/action_node.h"

#include "plansys2_problem_expert/ProblemExpertClient.hpp"
#include "plansys2_executor/ActionExecutor.hpp"
#include "plansys2_executor/Utils.hpp"

#include "plansys2_executor/behavior_tree/execute_action_node.hpp"

namespace plansys2
{

class ApplyAtEndEffect : public BT::ActionNodeBase
{
public:
  ApplyAtEndEffect(
    const std::string & xml_tag_name,
    const BT::NodeConfiguration & conf);

  void halt() {}
  BT::NodeStatus tick() override;

  static BT::PortsList providedPorts()
  {
    return BT::PortsList({
      BT::InputPort<std::string>("action", "Action whose at end reqs maust stop"),
    });
  }

private:
  std::shared_ptr<std::map<std::string, ActionExecutor::Ptr>> action_map_;
  std::shared_ptr<std::map<std::string, DurativeAction>> durative_actions_map_;
  std::shared_ptr<plansys2::ProblemExpertClient> problem_client_;
};
}

#endif  // PLANSYS2_EXECUTOR__BEHAVIOR_TREE__APPLY_ATESTART_EFFECT_NODE_HPP_