# Epoch Engine Extensions

Optional package source and package manifests for EpochEngine.

EpochEngine keeps the lean core runtime, editor, package descriptors, security
gates, cache/update plumbing, and stable API contracts. This repository is the
review home for bulky optional packages that should not be copied into every
software project, single-player game, or minimal generated engine clone.

## Package Boundary

- EpochEngine mainline owns stable interfaces and inert package descriptors.
- This repository owns optional package source, provenance records, and package
  integration manifests.
- Runtime downloads and generated package payloads belong under the consuming
  editor/runtime executable folder at `cache/packages/`.
- Packages that can bind a port, host, listen, expose a server, or create a new
  network/control surface require explicit human approval before build or run.
- Authoritative dedicated server support is optional. It is not the default
  networking model for games, and it must not be injected into unrelated
  software or single-player projects.

## Initial Package Tracks

- `engine_network_runtime`: inert shared network/session contracts.
- `engine_authoritative_dedicated_server`: optional headless authoritative
  server package for projects that deliberately choose that model.
- `engine_client_listen_server`: client-hosted listen/nondedicated server path.
- `research_voxel_planetoid_vulkan`: local voxel/Vulkan prototype provenance.
- `research_almond_voxel_authoring`: AlmondVoxel provenance and import plan.
- `research_forest_lsystem_wicked_2ol`: forest/L-system lab provenance.
- `research_planetary_terrain`: planetary and multi-terrain package plan.
- `research_fft_ocean`: FFT ocean package plan.

## Validate

```powershell
.\run_validate_packages.ps1
```

The validator is intentionally small and standard-library only. It checks that
package manifests are present, deterministic JSON, security-gated where needed,
and aligned with EpochEngine package policy.
