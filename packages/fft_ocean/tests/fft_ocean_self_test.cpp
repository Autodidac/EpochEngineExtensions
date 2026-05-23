// SPDX-License-Identifier: LicenseRef-MIT-NoSell
// Copyright (c) 2026 Adam Rushford

#include "epoch/extensions/fft_ocean/fft_ocean.hpp"

#include <cmath>
#include <stdexcept>

int main()
{
    epoch::extensions::fft_ocean::OceanSettings settings{};
    settings.resolution = 32;
    settings.tileLengthMeters = 96.0f;
    settings.seed = 42u;

    epoch::extensions::fft_ocean::OceanTile tile{ settings };
    tile.evaluate(3.25f);

    if (tile.samples().size() != 1024u)
        throw std::runtime_error("fft_ocean self-test failed: sample count mismatch");

    const auto center = tile.sample(0.0f, 0.0f);
    const float normalLength = std::sqrt(center.normalX * center.normalX + center.normalY * center.normalY + center.normalZ * center.normalZ);

    if (!std::isfinite(center.heightMeters) || !std::isfinite(center.displacementXMeters) || !std::isfinite(center.displacementZMeters))
        throw std::runtime_error("fft_ocean self-test failed: non-finite sample");

    if (std::abs(normalLength - 1.0f) > 0.05f)
        throw std::runtime_error("fft_ocean self-test failed: normal is not normalized");

    if (center.foam < 0.0f || center.foam > 1.0f)
        throw std::runtime_error("fft_ocean self-test failed: foam outside [0, 1]");

    return 0;
}
