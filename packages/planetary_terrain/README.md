# Planetary Terrain

<!-- SPDX-License-Identifier: LicenseRef-MIT-NoSell -->
<!-- Copyright (c) 2026 Adam Rushford -->

Optional planetary terrain composition package for Epoch.

This package stages deterministic terrain tiles, biome selection, and classic
terrain-output metadata above the core voxel field and trace contracts. It is
kept out of minimal engine clones so software projects and small games do not
inherit planetary generation weight unless they explicitly opt in.
