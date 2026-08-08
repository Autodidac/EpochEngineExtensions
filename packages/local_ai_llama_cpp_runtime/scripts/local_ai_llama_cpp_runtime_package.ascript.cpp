// SPDX-License-Identifier: LicenseRef-MIT-NoSell
// Copyright (c) 2026 Adam Rushford

#include "../../_api/epoch_package_script_api.hpp"

namespace
{
    using epoch::packages::script::Operation;
    using epoch::packages::script::OperationKind;
    using epoch::packages::script::PackageScriptPlan;

    constexpr Operation kOperations[] = {
        { OperationKind::HumanApprovalGate, "Confirm local AI runtime setup", "Fetching or compiling llama.cpp requires a visible Package Manager approval.", true },
        { OperationKind::FetchGitSource, "Fetch pinned llama.cpp source", "Stage reviewed ggml-org/llama.cpp source under executable-local cache/packages; record the immutable revision before build.", true },
        { OperationKind::ConfigureBuild, "Configure offline llama-cli", "Configure C++23 Release with server, network download, and test targets disabled.", true },
        { OperationKind::CompileAdapter, "Build llama-cli", "Build only the direct llama-cli executable and retain visible build evidence.", true },
        { OperationKind::RegisterLivePreview, "Register runtime status", "Expose executable and GGUF readiness in Epoch AI without starting a listener or hidden service.", true }
    };

    constexpr PackageScriptPlan kPlan{
        "local_ai_llama_cpp_runtime",
        "1",
        "cache/packages/local_ai_llama_cpp_runtime",
        "https://github.com/Autodidac/EpochEngineExtensions",
        "packages/local_ai_llama_cpp_runtime",
        true,
        true,
        true,
        false,
        kOperations,
        sizeof(kOperations) / sizeof(kOperations[0])
    };
}

EPOCH_PACKAGE_SCRIPT_EXPORT const epoch::packages::script::PackageScriptPlan* epoch_package_script_plan() noexcept
{
    return &kPlan;
}