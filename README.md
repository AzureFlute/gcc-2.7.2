# GCC 2.7.2 #

## Building the source ##

### In order to build, you must install a few dependencies first: ###

```
sudo apt-get update
sudo apt-get install build-essential flex libelf-dev libc6-dev libc6-dev-i386 binutils-dev libdwarf-dev gperf binutils-mips-linux-gnu
```

### Next, you must configure this repository, in order to do this, run these commands in the root directory of the repo: ###

```
./configure --target=mips --prefix=$OUTPUT_DIR --host=i386-pc-linux --build=i386-pc-linux
sed -i -E 's/LANGUAGES = c .+$/LANGUAGES = c/g' Makefile
```

This configures the repo and fixes a few flags in the generated Makefile.

### You can now build with the following command: ###

```
sudo make install || true
```
