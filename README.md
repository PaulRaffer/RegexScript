# RegexScript

## Table of Contents

- [Installation](#installation)
- [Run](#run)
- [License](#license)


## Installation

### Prerequisites

The following tools need to be installed on your computer:
- [Git](https://git-scm.com/downloads)
- [CMake](https://cmake.org/download/)
- [MinGW](https://osdn.net/projects/mingw/releases/) (only on Windows)
- [raffer_cpplib](https://github.com/PaulRaffer/raffer_cpplib#installation)


### Clone

Navigate to the directory where you want to install RegexScript
clone this repository to your local machine:
```
cd <RegexScript-path>
git clone https://github.com/PaulRaffer/RegexScript.git

```


#### Submodules

```
cd RegexScript
git submodule init
git submodule update
```


### Config
#### Linux
```
./config-debug-unix.sh
```
#### Windows
```
./config-debug-mingw.bat
```


### Build
```
./build-static.sh.bat
```


### Make RegexScript executable from anywhere

#### Linux
Add a link to RegexScript to the directory ```/usr/local/bin/```:

```
sudo cp -s <RegexScript-path>/RegexScript/build/regs /usr/local/bin/regs
```

#### Windows

TODO

## Run

```
regs std/core.regs
```

## License

Distributed under the [Boost Software License, Version 1.0](https://www.boost.org/LICENSE_1_0.txt).
