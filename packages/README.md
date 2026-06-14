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
- Current source-staged packages include real C++23 code and self-test targets
  instead of only manifests: `fft_ocean`, `voxel_authoring_tools`,
  `voxel_planetoid_lod`, `planetary_terrain`, `forest_temporal_graph`,
  `engine_network_runtime`, `engine_client_listen_server`, and
  `engine_authoritative_dedicated_server`.
- Network/server packages are contract/planning packages only. They must not
  bind ports, create listeners, auto-run services, or expose a model-accessible
  control surface from package install.
