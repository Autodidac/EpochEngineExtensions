# Epoch Engine Extensions

<!-- SPDX-License-Identifier: LicenseRef-MIT-NoSell -->
<!-- Copyright (c) 2026 Adam Rushford -->

Optional package source and package manifests for EpochEngine.

EpochEngine keeps the lean core runtime, editor, package descriptors, security
gates, cache/update plumbing, and stable API contracts. This repository is the
review home for bulky optional packages that should not be copied into every
software project, single-player game, or minimal generated engine clone.

## Core Compatibility

- Published EpochEngine runtime baseline: `v0.87.69`.
- Current EpochEngine source contract: `v0.87.72`.
- Renderer contexts, sampled render-to-texture, EpochGui, updater behavior, and
  release packaging remain engine-owned contracts. Extensions consume those
  contracts and do not replace or fork them.

## Package Boundary

- EpochEngine mainline owns stable interfaces and inert package descriptors.
- This repository owns optional package source, provenance records, and package
  integration manifests.
- JSON manifests are package discovery and policy metadata, not the live
  implementation path for visual/source packages.
- Visual/source packages use C++23 `.ascript.cpp` package runners. Those
  runners describe the human-gated fetch, cache, build, and live-preview path
  that Epoch's Package Manager can compile and invoke.
- Runtime downloads and generated package payloads belong under the consuming
  editor/runtime executable folder at `cache/packages/`.
- Packages that can bind a port, host, listen, expose a server, or create a new
  network/control surface require explicit human approval before build or run.
- Authoritative dedicated server support is optional. It is not the default
  networking model for games, and it must not be injected into unrelated
  software or single-player projects.

## Source-Staged Code Extension Tracks

- `engine_network_runtime`: inert shared network/session contracts and packet
  frame/policy self-tests.
- `engine_authoritative_dedicated_server`: optional headless authoritative
  server planning package for projects that deliberately choose that path.
- `engine_client_listen_server`: client-hosted listen/nondedicated server
  planning path.
- `voxel_planetoid_lod`: renderer-neutral voxel planetoid field and chunk LOD
  package.
- `voxel_authoring_tools`: sparse voxel authoring and brush replay package.
- `forest_temporal_graph`: optional Forest Factory temporal graph package.
- `planetary_terrain`: planetary biome/tile composition package.
- `fft_ocean`: FFT ocean simulation package.

Each source-staged package has a package-local `CMakeLists.txt`, public C++23
header, source file, and self-test target. Package code is intentionally
renderer-neutral unless the package name says otherwise.

## Validate

```powershell
.\run_validate_packages.ps1
```

The validator is intentionally small and standard-library only. It checks that
package manifests are present, deterministic JSON, security-gated where needed,
aligned with EpochEngine package policy, and that source/visual packages point
at a real C++23 package runner script.

## License

Repository files are licensed under the same `LicenseRef-MIT-NoSell` license as
EpochEngine unless another license is explicitly stated. Package manifests
describe package source provenance separately; a manifest license does not
relicense upstream source.
