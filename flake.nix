{
  inputs = {
    nixpkgs.url = "github:paveloom/nixpkgs/system";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    nixpkgs,
    flake-utils,
    ...
  }:
    flake-utils.lib.eachDefaultSystem (system: let
      pkgs = import nixpkgs {inherit system;};

      llvm = pkgs.llvmPackages_16;
      llvmStdenv = llvm.libcxxStdenv.override (old: {
        cc = old.cc.override {
          inherit (llvm) bintools;
        };
      });
      ccacheStdenv = pkgs.ccacheStdenv.override {
        stdenv = pkgs.stdenvAdapters.useMoldLinker llvmStdenv;
      };
    in {
      devShells.default = ccacheStdenv.mkDerivation {
        name = "dsa-env";

        nativeBuildInputs = with pkgs; [
          alejandra
          bashInteractive
          nil

          ccache
          clang-analyzer
          clang-tools_16
          cppcheck
          cpplint
          swift-mesonlsp
          valgrind

          meson
          ninja
          pkg-config
        ];

        env = {
          NIX_HARDENING_ENABLE = "";
        };
      };
    });
}
