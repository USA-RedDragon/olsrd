{
  description = "The olsr.org Optimized Link-State Routing daemon (olsrd)";

  inputs.nixpkgs.url = "github:nixos/nixpkgs/nixos-23.11";
  inputs.flake-utils.url = github:numtide/flake-utils;

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs {
          inherit system;
        };
      in {
        packages = rec {
          default = pkgs.stdenv.mkDerivation rec {
            name = "olsrd";
            version = "0.9.6.2";
            nativeBuildInputs = with pkgs; [
              bison flex gnumake
            ];
            src = self;

            enableParallelBuilding = true;

            buildPhase = "make prefix=/";
            installPhase = "make DESTDIR=$out prefix=/ install_olsrd arprefresh_install txtinfo_install jsoninfo_install dot_draw_install watchdog_install nameservice_install";

            meta = {
              description = "The olsr.org Optimized Link-State Routing daemon (olsrd)";
              license = pkgs.lib.licenses.bsd3;
              platforms = pkgs.lib.platforms.all;
              longDescription = ''
                olsrd is an implementation of the Optimized Link State Routing protocol for Mobile Ad-Hoc networks(MANET). The protocol is described in RFC3626. It is designed to be run as a standalone server process.

                OLSR operates as a table driven, proactive protocol, i.e., it exchanges topology information with other nodes of the network regularly. It is developed to work independently from other protocols. Likewise, OLSR makes no assumptions about the underlying link-layer. 
              '';
              inherit version;
            };
          };

          olsrd = default;
        };

        devShells = {
          default = pkgs.mkShell {
            nativeBuildInputs = with pkgs; [
              bison flex gnumake
            ];
          };
        };
      }
    );
}
