# Packages

<!-- SPDX-License-Identifier: LicenseRef-MIT-NoSell -->
<!-- Copyright (c) 2026 Adam Rushford -->

Each package folder contains a manifest and, later, reviewed source or adapter
code. A manifest is allowed to exist before source import when it records
provenance, security constraints, and the intended EpochEngine API boundary.

Required first-pass rules:

- Every package has `package.epoch-package.json`.
- Visual/source packages declare a C++23 `.ascript.cpp` runner under the package
  folder. The manifest points at that runner, but the runner owns the staged
  source-fetch/build/live-preview plan.
- JSON and Python stay in the metadata/validation lane. They do not replace
  Epoch's compiled C++23 package/scripting path.
- Network/server-capable packages set `requiresExplicitNetworkApproval` to
  `true`.
- Package source is not copied into generated Epoch projects by default.
- Build/run commands are human-gated and must produce visible evidence.
- Unreviewed source extensions remain `status: "planned"` until the package has
  reviewed source, a compiling adapter, and visible Package Manager evidence.
- `fft_ocean` is the first source-staged package: it includes real C++23 ocean
  simulation source and a self-test target instead of only a manifest.
