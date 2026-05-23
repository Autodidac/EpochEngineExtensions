# SPDX-License-Identifier: MIT
# Copyright (c) 2025 Adam Rushford

from __future__ import annotations

import json
import pathlib
import sys


ROOT = pathlib.Path(__file__).resolve().parents[1]
PACKAGES = ROOT / "packages"
REQUIRED = {
    "id",
    "displayName",
    "manifestLicense",
    "manifestCopyright",
    "status",
    "kind",
    "activation",
    "summary",
    "security",
    "source",
    "engineBoundary",
}
SECURITY_REQUIRED = {
    "serverOrListenerAllowed",
    "requiresExplicitNetworkApproval",
    "autoRunAllowed",
    "includeByDefault",
}


def load_json(path: pathlib.Path) -> dict:
    with path.open("r", encoding="utf-8") as handle:
        return json.load(handle)


def validate_manifest(path: pathlib.Path) -> list[str]:
    errors: list[str] = []
    try:
        manifest = load_json(path)
    except json.JSONDecodeError as exc:
        return [f"{path}: invalid JSON: {exc}"]

    missing = sorted(REQUIRED - set(manifest))
    if missing:
        errors.append(f"{path}: missing required fields: {', '.join(missing)}")

    security = manifest.get("security")
    if not isinstance(security, dict):
        errors.append(f"{path}: security must be an object")
        return errors

    missing_security = sorted(SECURITY_REQUIRED - set(security))
    if missing_security:
        errors.append(f"{path}: missing security fields: {', '.join(missing_security)}")

    if security.get("autoRunAllowed") is True:
        errors.append(f"{path}: autoRunAllowed must stay false for package imports")

    if security.get("includeByDefault") is True:
        errors.append(f"{path}: includeByDefault must stay false for optional packages")

    if security.get("serverOrListenerAllowed") is True and security.get("requiresExplicitNetworkApproval") is not True:
        errors.append(f"{path}: server/listener package must require explicit network approval")

    package_id = manifest.get("id")
    if package_id and path.parent.name != package_id:
        errors.append(f"{path}: folder name must match id '{package_id}'")

    if manifest.get("manifestLicense") != "MIT":
        errors.append(f"{path}: manifestLicense must be MIT")

    if "Adam Rushford" not in str(manifest.get("manifestCopyright", "")):
        errors.append(f"{path}: manifestCopyright must name Adam Rushford")

    boundary = manifest.get("engineBoundary")
    if isinstance(boundary, dict):
        cache_root = boundary.get("expectedCacheRoot", "")
        if package_id and cache_root != f"cache/packages/{package_id}":
            errors.append(f"{path}: expectedCacheRoot should be cache/packages/{package_id}")

    return errors


def main() -> int:
    manifests = sorted(PACKAGES.glob("*/package.epoch-package.json"))
    if not manifests:
        print("No package manifests found.", file=sys.stderr)
        return 1

    errors: list[str] = []
    for manifest in manifests:
        errors.extend(validate_manifest(manifest))

    if errors:
        for error in errors:
            print(error, file=sys.stderr)
        return 1

    print(f"Validated {len(manifests)} package manifest(s).")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
