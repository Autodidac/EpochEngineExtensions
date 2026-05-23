# Package Security And Import Policy

EpochEngineExtensions exists to keep optional package source out of the minimal
EpochEngine clone while still making those packages reviewable and repeatable.

## Server And Network Packages

- Server-capable code must be package-gated.
- A package that can bind a port, host, listen, or expose a network/control
  surface must set `requiresExplicitNetworkApproval` to `true`.
- Package install must not start a server.
- Package build must not start a server.
- Package tests may run local non-network self-tests by default, but any
  listener or port bind requires an explicit human run action.
- Authoritative dedicated server is optional and headless-capable. It is not the
  default multiplayer model.
- Client listen/nondedicated and future competitive client-predicted paths are
  separate packages.

## Source Import Rules

- Record provenance before copying source.
- Keep license status explicit.
- Import the smallest useful source slice.
- Prefer adapter layers over wholesale source-tree dumps.
- Do not promote prototypes into EpochEngine core until the API boundary,
  build/test evidence, and package ownership are documented.

## Cache Layout

Consuming EpochEngine builds should place downloaded or materialized package
payloads under:

```text
cache/packages/<package-id>/
```

Generated atlases and update payloads are separate concerns owned by the engine
runtime cache policy.
