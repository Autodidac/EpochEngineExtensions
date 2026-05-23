// SPDX-License-Identifier: LicenseRef-MIT-NoSell
// Copyright (c) 2026 Adam Rushford

#include "../../_api/epoch_package_script_api.hpp"

namespace
{
    using epoch::packages::script::Operation;
    using epoch::packages::script::OperationKind;
    using epoch::packages::script::PackageScriptPlan;

    constexpr Operation kOperations[] = {
        { OperationKind::HumanApprovalGate, "Confirm local archive import", "Use the reviewed vk_cp_cursor_nodoublefree.zip provenance before materializing source.", true },
        { OperationKind::VerifyLocalArchive, "Verify source archive", "Match the recorded SHA-256 before extracting into cache/packages/research_voxel_planetoid_vulkan/.", true },
        { OperationKind::ExtractLocalArchive, "Extract package source", "Extract into the package cache, never into EpochEngine mainline or a generated project by default.", true },
        { OperationKind::ConfigureBuild, "Configure voxel preview adapter", "Configure only the smallest Vulkan voxel preview adapter needed for editor proof.", true },
        { OperationKind::CompileAdapter, "Compile voxel preview", "Build the adapter as a package preview target through the engine Package Manager gate.", true },
        { OperationKind::RegisterLivePreview, "Register live voxel preview", "Expose the preview through the editor package surface after build evidence exists.", true }
    };

    constexpr PackageScriptPlan kPlan{
        "research_voxel_planetoid_vulkan",
        "1",
        "cache/packages/research_voxel_planetoid_vulkan",
        "local:C:/Users/iammi/source/cursorAIsource/vk_cp_cursor_nodoublefree.zip",
        "sha256:BCACE57C2ED881C0AE0D5B4B48F8757E80BE08135031CA29EAA3DE2CFE9B69F1",
        false,
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
