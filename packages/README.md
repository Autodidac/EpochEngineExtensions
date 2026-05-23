# Packages

<!-- SPDX-License-Identifier: MIT -->
<!-- Copyright (c) 2025 Adam Rushford -->

Each package folder contains a manifest and, later, reviewed source or adapter
code. A manifest is allowed to exist before source import when it records
provenance, security constraints, and the intended EpochEngine API boundary.

Required first-pass rules:

- Every package has `package.epoch-package.json`.
- Network/server-capable packages set `requiresExplicitNetworkApproval` to
  `true`.
- Package source is not copied into generated Epoch projects by default.
- Build/run commands are human-gated and must produce visible evidence.
- Unreviewed prototypes remain `status: "provenance-only"` or
  `status: "planned"`.
