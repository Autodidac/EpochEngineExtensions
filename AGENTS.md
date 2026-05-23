# Agent Notes

<!-- SPDX-License-Identifier: MIT -->
<!-- Copyright (c) 2025 Adam Rushford -->

- This repository is the optional package source home for EpochEngine.
- Do not copy package source into EpochEngine mainline unless a reviewed subset
  has a stable engine API boundary, provenance, build evidence, and a promotion
  note in the EpochEngine roadmap.
- Keep package manifests under `packages/<package-id>/package.epoch-package.json`.
- Keep package source inert by default. No package may auto-bind ports, create
  listeners, start hidden services, or expose model-accessible control surfaces.
- Authoritative dedicated server support is optional and human-gated. Client
  listen/nondedicated and future competitive client-predicted networking are
  separate opt-in package tracks.
- Bulky terrain, voxel, ocean, server, and renderer experiments belong here
  first. EpochEngine should consume them through `cache/packages/` and the
  Package Manager/updater gate.
- Forest Factory is a core EpochEngine feature, but heavy forest demos,
  datasets, or external L-system experiments may live here as optional package
  material.
