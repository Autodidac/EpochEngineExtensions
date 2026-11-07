# Agent Notes

<!-- SPDX-License-Identifier: LicenseRef-MIT-NoSell -->
<!-- Copyright (c) 2026 Adam Rushford -->

- Optional package source starts in EpochEngine at
  `Engine/dep/EpochEngineExtensions`. This separate Site project mirrors that
  reviewed source and has its own commits, version and source packages. Do not
  create another permanent `Extensions/` source owner or move it into user Projects.
- Keeping source in the Engine repository does not compile, activate or ship a
  package with every application. Engine interfaces stay engine-owned; optional
  implementations use the existing Package Manager and exact source admission.
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
- Plant Lab and Forest Factory are optional package tracks. Engine retains generic
  authoring, voxel-field and project-persistence contracts. Existing forest
  implementation still compiled into Engine is unfinished extraction work; do
  not claim it has moved here without its real source and independent consumer.
- The pinned Public Engine 0.90.183 CI lane checks the default independent CPU
  targets only. The optional cloud-density exporter/controller requires the new
  0.90.185 artifact contracts and its separate current-source acceptance. Do not
  report the older CI lane as proof of that feature or of native rendering.
- Do not use legacy project naming in package IDs, filenames, manifests, docs,
  or script strings. Extension packages must use Epoch naming and describe code
  capabilities, not unrelated data artifacts.
