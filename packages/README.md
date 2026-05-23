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
- Unreviewed prototypes remain `status: "provenance-only"` or
  `status: "planned"`.
