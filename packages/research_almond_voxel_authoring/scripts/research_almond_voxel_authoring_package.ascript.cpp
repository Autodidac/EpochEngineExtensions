// SPDX-License-Identifier: LicenseRef-MIT-NoSell
// Copyright (c) 2026 Adam Rushford

#include "../../_api/epoch_package_script_api.hpp"

namespace
{
    using epoch::packages::script::Operation;
    using epoch::packages::script::OperationKind;
    using epoch::packages::script::PackageScriptPlan;

    constexpr Operation kOperations[] = {
        { OperationKind::HumanApprovalGate, "Confirm AlmondVoxel import", "Fetch only after the operator approves the package import and source license notice.", true },
        { OperationKind::FetchGitSource, "Fetch source", "Clone Autodidac/AlmondVoxel at the recorded commit into cache/packages/research_almond_voxel_authoring/source/.", true },
        { OperationKind::StageCachePackage, "Stage authoring adapter", "Stage a minimal Epoch voxel-authoring adapter; do not copy the whole tree into core.", true },
        { OperationKind::ConfigureBuild, "Configure authoring preview", "Configure against Epoch voxel.field and voxel.trace boundaries.", true },
        { OperationKind::CompileAdapter, "Compile authoring preview", "Build the package adapter for editor-side voxel authoring proof.", true },
        { OperationKind::RegisterLivePreview, "Register voxel authoring preview", "Expose the authoring preview only after build evidence is captured.", true }
    };

    constexpr PackageScriptPlan kPlan{
        "research_almond_voxel_authoring",
        "1",
        "cache/packages/research_almond_voxel_authoring",
        "https://github.com/Autodidac/AlmondVoxel.git",
        "fc84eb43eebed07cb95791920e9f2f6ba3734b81",
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
