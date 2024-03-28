#pragma once

#include "sc-memory/kpm/sc_agent.hpp"
#include "sc-agents-common/keynodes/coreKeynodes.hpp"

#include "QuestionFinishedUnsuccessfullyTestAgent.generated.hpp"

namespace nonAtomicActionInterpreterModuleTest
{
class QuestionFinishedUnsuccessfullyTestAgent : public ScAgent
{
  SC_CLASS(Agent, Event(scAgentsCommon::CoreKeynodes::question_initiated, ScEvent::Type::AddOutputEdge))
  SC_GENERATED_BODY()
};

}  // namespace commonTest
