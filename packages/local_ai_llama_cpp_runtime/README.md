# Local AI llama.cpp Runtime

This optional package connects Epoch to a local `llama-cli` process without an
HTTP server. Package discovery is inert. Fetching and compiling source requires
a visible Package Manager approval, and model weights remain operator supplied.

The runtime layout is executable-local:

```text
cache/
├── packages/local_ai_llama_cpp_runtime/
│   ├── source/
│   ├── build/
│   └── bin/llama-cli[.exe]
└── models/**/*.gguf
```

Epoch can also use `EPOCH_LLAMA_CPP_EXECUTABLE` and `EPOCH_AI_MODEL_PATH` for
explicit paths. It starts `llama-cli` as a captured child process with an
argument vector, timeout, bounded output, and offline flags. It never builds or
starts `llama-server`.

The upstream runtime is [ggml-org/llama.cpp](https://github.com/ggml-org/llama.cpp)
and carries the MIT license. Every GGUF model has its own license and usage
terms; installing this package does not grant rights to any model weights.