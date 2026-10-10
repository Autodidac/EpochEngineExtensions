# Extensions Source Reconciliation

<!-- SPDX-License-Identifier: LicenseRef-MIT-NoSell -->
<!-- Copyright (c) 2026 Adam Rushford -->

October 10, 2026, source version v0.2.1 joins two previously unrelated histories:

- GitHub `eccef139f982a9e6b64295cd9c8b976905ef0990`: ten optional package
  source trees, their manifests/scripts/contracts, validation tools and policy.
- Site `16007d4b492855ca770ac172b0e7a2e24400d8aa`: v0.2.0 tiered-terrain
  module, contract, package license/README, stable catalog and root build.

Both parents remain ancestors of the reconciliation commit. No force push,
historical tag movement, package deletion or historical archive replacement is
part of this source integration. All pre-existing GitHub files remain, with
only the root README updated for the combined source. The Site terrain module,
contract and package notices are imported byte-for-byte; the root build and
catalog revision are updated for this new source version.

The root `LICENSE` retains the GitHub bytes. The Site root license expresses the
same terms with different whitespace and remains available in its original
history. The tiered-terrain package retains its own original complete license.
Manifest provenance does not relicense upstream third-party software.

The root CMake build consumes an explicitly selected authoritative EpochEngine
module directory, builds tiered terrain and the ten preserved source packages,
and registers their CPU-only contracts plus catalog/manifest checks. It does
not launch a renderer, model, listener, service or generated Editor. Package
builds remain available individually; `EPOCH_BUILD_SOURCE_PACKAGES=OFF` selects
the terrain-only library lane. This is source/build evidence, not native package
activation or renderer acceptance.

The Engine's embedded Extensions directory remains an engine-owned descriptor
fixture, not a complete mirror of this optional-source repository. Source sync
must not dump these package trees into Engine mainline or automatically admit
their execution. Catalog stable identities and inactive descriptor admission
states remain unchanged.

## Validation

The combined root build passes with CMake 4.4.2, MSVC 19.44.35227.0, Windows SDK
10.0.19041.0 and the current EpochEngine v0.90.35 authoritative modules. All
13 CPU contracts pass in both Debug and Release: ten package self-tests,
tiered terrain, stable catalog and ten-manifest policy validation. No original
package source or terrain module/contract bytes were modified to obtain this
result. The selected Engine modules remain external inputs to this archive.

Build logs use a short task-owned output directory and single-node MSBuild.
An earlier restricted multi-node launch stalled before compilation; a subsequent
deeply nested build exceeded Windows compiler-generated path limits. Both
transcripts are retained as build-host evidence. They are not package compiler
defects or proof of a model/renderer problem.

Linux/macOS builds and native Package Manager admission are not newly qualified
by this Windows CPU validation. Historical v0.2.0 packages and their evidence
are preserved; this new full-repository source export does not replace them.
