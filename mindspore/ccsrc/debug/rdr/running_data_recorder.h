/**
 * Copyright 2021 Huawei Technologies Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef RUNNING_DATA_RECORDER_H_
#define RUNNING_DATA_RECORDER_H_

#include <vector>
#include <string>
#include <memory>

#include "backend/optimizer/somas/somas.h"
#include "mindspore/core/utils/log_adapter.h"
namespace mindspore {
class FuncGraph;
class CNode;
using FuncGraphPtr = std::shared_ptr<FuncGraph>;
using CNodePtr = std::shared_ptr<CNode>;
using SomasPtr = std::shared_ptr<somas::Somas>;
namespace RDR {
bool RecordAnfGraph(const SubModuleId module, const std::string &tag, const FuncGraphPtr &graph,
                    const std::string &file_type = ".ir;.pb;.dat", int graph_id = 0);
bool RecordGraphExecOrder(const SubModuleId module, const std::string &tag,
                          const std::vector<CNodePtr> &&final_exec_order);
bool RecordSomasInfo(const SubModuleId module, const std::string &tag, const SomasPtr &somas_ptr, int graph_id);
void TriggerAll();
}  // namespace RDR
}  // namespace mindspore
#endif  // RUNNING_DATA_RECORDER_H_
