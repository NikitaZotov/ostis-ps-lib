#include "sc-agents-common/keynodes/coreKeynodes.hpp"
#include "sc-agents-common/utils/AgentUtils.hpp"

#include "test/keynodes/TestKeynodes.hpp"

#include "CheckDynamicArgumentTestAgent.hpp"

using namespace nonAtomicActionInterpreterModuleTest;

SC_AGENT_IMPLEMENTATION(CheckDynamicArgumentTestAgent)
{
  if (!edgeAddr.IsValid())
  {
    return SC_RESULT_ERROR;
  }

  ScAddr actionAddr = m_memoryCtx.GetEdgeTarget(edgeAddr);

  ScIterator3Ptr iterator3Ptr = m_memoryCtx.Iterator3(
      TestKeynodes::check_dynamic_argument_test_action, ScType::EdgeAccessConstPosPerm, actionAddr);
  if (!iterator3Ptr->Next())
  {
    return SC_RESULT_OK;
  }

  ScTemplate scTemplate;
  scTemplate.Quintuple(
      actionAddr,
      ScType::EdgeAccessVarPosPerm,
      ScType::NodeVar >> "_dynamic_argument",
      ScType::EdgeAccessVarPosPerm,
      scAgentsCommon::CoreKeynodes::rrel_1);
  scTemplate.Triple("_dynamic_argument", ScType::EdgeAccessVarPosTemp, TestKeynodes::test_node);
  ScTemplateSearchResult results;
  m_memoryCtx.HelperSearchTemplate(scTemplate, results);
  if (results.Size() == 1)
  {
    utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionAddr, true);
  }
  else
  {
    utils::AgentUtils::finishAgentWork(&m_memoryCtx, actionAddr, false);
  }

  return SC_RESULT_OK;
}
