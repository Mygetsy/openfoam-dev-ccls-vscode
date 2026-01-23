# OpenFOAM Dev Container for VS Code (ccls + Bear)

This repository provides a ready-to-use VS Code Dev Container setup for OpenFOAM solvers development with `ccls` indexing and an integrated build workflow. This allows to have syntacsis highlight of source code and your application code.

## Quick start

1. Install:
   - Docker (or compatible container runtime).
   - VS Code + “Dev Containers” support (VS Code Remote Development workflow).
2. Set-up proper version by adjusting image version in ".devcontainer/devcontainer.json".
2. Open the repo in VS Code and run:
   **“Dev Containers: B in Container”**.
3. Build (and generate `compile_commands.json`) using one of:
   - `Ctrl + Shift + B` (default build task).
   - `Run and Debug → Build w/ Bear` (dummy launch config that triggers the same task).

## Build + IntelliSense (ccls)

- The build task runs `bear -- ./Allwmake`, which generates `compile_commands.json` in in the `~/workspace` directory .
- `ccls` is configured to look for the compilation database in `/home/openfoam/workspace/`, so once the build task completes, code navigation and indexing should work without extra steps.
- To speed up indexing of the source code, the container mounts a persistent `ccls` cache volume and (on start) symlinks any prebuilt system cache from `/opt/openfoam/.ccls-cache` into the volume.

## Notes / troubleshooting
- If you add more libraries/apps, extend `Allwmake` and re-run the Bear build task to refresh `compile_commands.json`. `wclean all` is needed sometimes.

### macOS Users (Critical: Case Sensitivity)

By default, the macOS file system (APFS) is **case-insensitive**, which causes name conflicts in OpenFOAM (e.g., it cannot distinguish between `scalar` and `Scalar` files).

To fix this and ensure correct behavior, you **must** create a case-sensitive volume (disk image) and store your OpenFOAM project there.

Run the following commands in your terminal **before** opening the project:

```bash
# 1. Install the specialized macOS file system driver for OpenFOAM
sudo curl -o /usr/local/bin/openfoam-macos-file-system http://dl.openfoam.org/docker/openfoam-macos-file-system
sudo chmod 755 /usr/local/bin/openfoam-macos-file-system

# 2. Create a case-sensitive volume named 'my_openfoam'
sudo openfoam-macos-file-system -v my_openfoam create

# 3. Mount the volume locally
mkdir -p my_openfoam
sudo openfoam-macos-file-system -v my_openfoam mount