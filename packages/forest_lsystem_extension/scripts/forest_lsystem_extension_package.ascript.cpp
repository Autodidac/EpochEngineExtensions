// SPDX-License-Identifier: LicenseRef-MIT-NoSell
// Copyright (c) 2026 Adam Rushford

#include "../../_api/epoch_package_script_api.hpp"

namespace
{
    using epoch::packages::script::Operation;
    using epoch::packages::script::OperationKind;
    using epoch::packages::script::PackageScriptPlan;

    constexpr Operation kOperations[] = {
        { OperationKind::HumanApprovalGate, "Confirm forest reference import", "Forest Factory is core; this package is reference material only until license/dependency review completes.", true },
        { OperationKind::FetchGitSource, "Fetch reference source", "Fetch the external L-system reference into cache/packages/forest_lsystem_extension/source/ only after approval.", true },
        { OperationKind::RegisterReferenceMaterial, "Register reference material", "Expose the source as reviewed reference material for the native Forest Factory path.", true }
    };

    constexpr PackageScriptPlan kPlan{
        "forest_lsystem_extension",
        "1",
        "cache/packages/forest_lsystem_extension",
        "https://github.com/Autodidac/WickedTwoOLSystem",
        "482b84768447247b076fd4322cba82b285b32698",
        true,
        false,
        false,
        false,
        kOperations,
        sizeof(kOperations) / sizeof(kOperations[0])
    };
}

EPOCH_PACKAGE_SCRIPT_EXPORT const epoch::packages::script::PackageScriptPlan* epoch_package_script_plan() noexcept
{
    return &kPlan;
}
