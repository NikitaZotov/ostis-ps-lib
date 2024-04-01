#include "sc-agents-common/utils/AgentUtils.hpp"

#include "test/keynodes/TestKeynodes.hpp"

#include "QuestionFinishedUnsuccessfullyTestAgent.hpp"

using namespace nonAtomicActionInterpreterModuleTest;

SC_AGENT_IMPLEMENTATION(QuestionFinishedUnsuccessfullyTestAgent)
{
  if (!edgeAddr.IsValid())
  {
    return SC_RESULT_ERROR;
  }

  ScAddr actionAddr = m_memoryCtx.GetEdgeTarget(edgeAddr);

  ScIterator3Ptr iterator3Ptr = m_memoryCtx.Iterator3(
      TestKeynodes::unsuccessfully_finished_test_action, ScType::EdgeAccessConstPosPerm, actionAddr);
  if (!iterator3Ptr->Next())
  {
    return SC_RESULT_OK;
  }

  utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionAddr, false);
  return SC_RESULT_OK;
}
