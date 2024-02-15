# {{cookiecutter.projectName}} from {{cookiecutter.author}}

{{cookiecutter.projectVersion}}

{{cookiecutter.projectDescription}}

Libs:
- [pistache](https://github.com/oktal/pistache.git)
- [nlohmann/json](https://github.com/nlohmann/json.git)
- [redis-cpp](https://github.com/tdv/redis-cpp.git)

## build docker-toolchain for CLion
```bash
docker build -f ./{{cookiecutter.projectName}}/Dockerfile.builder -r builder:1
```

## build & run
```bash
mkdir build
cd build
cmake ..
cmake --build .
./{{cookiecutter.projectName}}
```