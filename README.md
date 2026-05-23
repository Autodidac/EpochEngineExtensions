# Epoch Engine Extensions

<!-- SPDX-License-Identifier: LicenseRef-MIT-NoSell -->
<!-- Copyright (c) 2026 Adam Rushford -->

Optional package source and package manifests for EpochEngine.

EpochEngine keeps the lean core runtime, editor, package descriptors, security
gates, cache/update plumbing, and stable API contracts. This repository is the
review home for bulky optional packages that should not be copied into every
software project, single-player game, or minimal generated engine clone.

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

## Initial Code Extension Tracks

- `engine_network_runtime`: inert shared network/session contracts.
- `engine_authoritative_dedicated_server`: optional headless authoritative
  server package for projects that deliberately choose that path.
- `engine_client_listen_server`: client-hosted listen/nondedicated server path.
- `voxel_planetoid_lod`: renderer-neutral voxel planetoid LOD extension.
- `voxel_authoring_tools`: voxel authoring/code extension package.
- `forest_lsystem_extension`: optional Forest Factory reference extension.
- `planetary_terrain`: planetary and multi-terrain extension package.
- `fft_ocean`: FFT ocean simulation extension package.

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
