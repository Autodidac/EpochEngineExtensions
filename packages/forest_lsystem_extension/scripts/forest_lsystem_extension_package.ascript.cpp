// SPDX-License-Identifier: LicenseRef-MIT-NoSell
// Copyright (c) 2026 Adam Rushford

#include "../../_api/epoch_package_script_api.hpp"

namespace
{
    using epoch::packages::script::Operation;
    using epoch::packages::script::OperationKind;
    using epoch::packages::script::PackageScriptPlan;

    constexpr Operation kOperations[] = {
        { OperationKind::HumanApprovalGate, "Confirm Forest Factory extension", "Forest Factory is a core Epoch direction; this package stages optional L-system source and must stay opt-in.", true },
        { OperationKind::FetchGitSource, "Fetch package source", "Fetch the reviewed extension source into cache/packages/forest_lsystem_extension/source/.", true },
        { OperationKind::StageCachePackage, "Stage forest adapter", "Stage deterministic grammar and branch segment code for renderer-neutral preview evidence.", true },
        { OperationKind::ConfigureBuild, "Configure forest preview", "Configure the C++23 Forest Factory extension self-test target.", true },
        { OperationKind::CompileAdapter, "Compile forest preview", "Build the staged forest extension before any editor preview is exposed.", true },
        { OperationKind::RegisterLivePreview, "Register forest preview", "Expose the forest preview only after build evidence exists.", true }
    };

    constexpr PackageScriptPlan kPlan{
        "forest_lsystem_extension",
        "1",
        "cache/packages/forest_lsystem_extension",
        "https://github.com/Autodidac/EpochEngineExtensions",
        "packages/forest_lsystem_extension",
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
