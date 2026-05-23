# FFT Ocean Extension

<!-- SPDX-License-Identifier: LicenseRef-MIT-NoSell -->
<!-- Copyright (c) 2026 Adam Rushford -->

`fft_ocean` is a renderer-neutral C++23 Epoch code extension. The package owns
a CPU spectral ocean tile that can be staged into `cache/packages/fft_ocean/`,
compiled by the Package Manager, and previewed by any active renderer through a
height/displacement/normal sample buffer.

This package is intentionally not part of the minimal EpochEngine clone. It is
for projects that opt into ocean simulation and accept the package build cost.

## Source

- `include/epoch/extensions/fft_ocean/fft_ocean.hpp`
- `src/fft_ocean.cpp`
- `tests/fft_ocean_self_test.cpp`

The implementation builds a deterministic Phillips-style initial spectrum,
evolves it over time, performs a 2D inverse FFT, and derives displacement,
normals, and foam hints for preview/render integration.
