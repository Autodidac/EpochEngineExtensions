// SPDX-License-Identifier: LicenseRef-MIT-NoSell
// Copyright (c) 2026 Adam Rushford

#include "epoch/extensions/local_ai_llama_cpp_runtime/local_ai_llama_cpp_runtime.hpp"

#include <stdexcept>

using namespace epoch::extensions::local_ai_llama_cpp_runtime;

int main()
{
    const auto layout = make_runtime_layout("cache");
    const auto blocked = make_build_plan(layout, false);
    if (blocked.valid || blocked.startsServer)
        throw std::runtime_error("local AI package bypassed its approval or server gate");

    const auto approved = make_build_plan(layout, true);
    if (!approved.valid || approved.startsServer || approved.configureArguments.empty())
        throw std::runtime_error("approved local AI build plan is incomplete");
    if (approved.sourceLicense != "MIT")
        throw std::runtime_error("llama.cpp license provenance is missing");
    return 0;
}