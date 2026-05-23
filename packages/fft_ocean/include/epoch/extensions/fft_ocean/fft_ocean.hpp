// SPDX-License-Identifier: LicenseRef-MIT-NoSell
// Copyright (c) 2026 Adam Rushford

#pragma once

#include <complex>
#include <cstdint>
#include <span>
#include <vector>

namespace epoch::extensions::fft_ocean
{
    struct OceanSettings
    {
        std::uint32_t resolution = 64;
        float tileLengthMeters = 128.0f;
        float windSpeedMetersPerSecond = 18.0f;
        float windDirectionRadians = 0.65f;
        float amplitude = 0.00035f;
        float choppiness = 1.25f;
        float normalStrength = 1.0f;
        float foamSlopeThreshold = 0.72f;
        float gravity = 9.80665f;
        std::uint32_t seed = 0xE903'F00Du;
    };

    struct OceanSample
    {
        float xMeters = 0.0f;
        float zMeters = 0.0f;
        float heightMeters = 0.0f;
        float displacementXMeters = 0.0f;
        float displacementZMeters = 0.0f;
        float normalX = 0.0f;
        float normalY = 1.0f;
        float normalZ = 0.0f;
        float foam = 0.0f;
    };

    class OceanTile
    {
    public:
        explicit OceanTile(OceanSettings settings = {});

        void reset(OceanSettings settings);
        void evaluate(float timeSeconds);

        [[nodiscard]] const OceanSettings& settings() const noexcept;
        [[nodiscard]] std::uint32_t resolution() const noexcept;
        [[nodiscard]] float tileLengthMeters() const noexcept;
        [[nodiscard]] std::span<const OceanSample> samples() const noexcept;
        [[nodiscard]] OceanSample sample(float xMeters, float zMeters) const noexcept;

    private:
        OceanSettings settings_{};
        std::vector<OceanSample> samples_{};
        std::vector<std::complex<float>> spectrum0_{};
        std::vector<std::complex<float>> frequencyDomain_{};

        void rebuildSpectrum();
        [[nodiscard]] std::uint32_t wrappedIndex(std::int32_t x, std::int32_t z) const noexcept;
    };
}
