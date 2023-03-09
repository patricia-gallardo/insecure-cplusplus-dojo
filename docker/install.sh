#!/bin/bash -Eeu

apt-get install --yes curl
mkdir /usr/include/catch2
cd /usr/include/catch2
curl \
   --remote-header-name  `# -J Use the header-provided filename` \
   --location            `# -L Follow redirects` \
   --remote-name         `# -O Write output to a file named as the remote file` \
     https://github.com/catchorg/Catch2/releases/download/v2.11.3/catch.hpp \

apt-get remove --yes curl
cd /usr/src
clang++ -fPIC -Wall -c catch_main.cpp
mv /usr/src/catch_main.o /usr/lib
