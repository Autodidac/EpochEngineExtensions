# Agent Notes

<!-- SPDX-License-Identifier: LicenseRef-MIT-NoSell -->
<!-- Copyright (c) 2026 Adam Rushford -->

- This repository is the optional package source home for EpochEngine.
- Do not copy package source into EpochEngine mainline unless a reviewed subset
  has a stable engine API boundary, provenance, build evidence, and a promotion
  note in the EpochEngine roadmap.
- Keep package manifests under `packages/<package-id>/package.epoch-package.json`.
- Keep package source inert by default. No package may auto-bind ports, create
  listeners, start hidden services, or expose hidden control surfaces.
- Authoritative dedicated server support is optional and human-gated. Client
  listen/nondedicated and future competitive client-predicted networking are
  separate opt-in package tracks.
- Bulky terrain, voxel, ocean, server, and renderer extensions belong here
  first. EpochEngine should consume them through `cache/packages/` and the
  Package Manager/updater gate.
- Manifests are only discovery/policy metadata. Visual/source packages such as
  voxel terrain, planetary terrain, FFT ocean, and demo previews must expose a
  C++23 `.ascript.cpp` package runner that the engine can stage, compile, and
  preview through a human-approved Package Manager action.
- Server/network packages may remain manifest-driven until their reviewed
  engine API exists; they must not add C++ runners that auto-bind ports or
  launch listeners.
- Forest Factory is a core EpochEngine feature, but heavy forest demos,
  datasets, or external L-system experiments may live here as optional package
  material.
- Do not use legacy project naming in package IDs, filenames, manifests, docs,
  or script strings. Extension packages must use Epoch naming and describe code
  capabilities, not unrelated data artifacts.
